#include"websitedao.h"
#include <QtDebug>
#include<QSqlError>
#include<QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QTimer>
#include <QMetaType>
template <typename T>
WebsiteDao<T>::WebsiteDao()
{
}
template <typename T>
WebsiteDao<T>::~WebsiteDao()
{
}
template <typename T>
bool WebsiteDao<T>::addByAll(T entry)
{
    db=DBHelper::getConnection();
    QPair<QString,int> tmp = T::getInsertSqlAndFieldsAmounts();
    QString sql = tmp.first;
    QSqlQuery query(db);
    query.prepare(sql);
    int amount = tmp.second;
    for(int i = 1;i <= amount;i++)
    {
        auto field = entry.getField(i);
        std::visit([&query,i](auto&& arg){
            using argType = std::decay_t<decltype(arg)>;
            query.bindValue(i - 1,arg);
        },field);
    }
    if(query.exec())
    {
        return true;
    }
    qDebug() << query.lastError().text();
    return false;
}
template <typename T>
bool WebsiteDao<T>::addByAll(QStringList* sqlInsert,QStringList* sqlFields)
{
    db=DBHelper::getConnection();
    QString sql="insert into " + T::getTableName();
    sql += '(';
    for(int i = 0;i<sqlFields->size();i++)
    {
        sql += sqlFields->at(i);
        sql += ',';
    }
    sql.chop(1);
    sql += ") values(";
    for(int i = 0;i<sqlInsert->size();i++)
    {
        sql += "?,";
    }
    sql.chop(1);
    sql += ')';
    QSqlQuery query(sql,db);
    for(int i = 0;i<sqlInsert->size();i++)
    {
        query.bindValue(i,sqlInsert->at(i));
    }
    if(query.exec())
    {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setStandardButtons(nullptr);msgBox->setWindowModality(Qt::NonModal);msgBox->setWindowFlags(msgBox->windowFlags()|Qt::FramelessWindowHint);
        msgBox->setText("添加成功");msgBox->show();
        QTimer::singleShot(3500,[msgBox](){
            msgBox->close();
            delete msgBox;
        });
        return true;
    }
    QMessageBox::critical(nullptr,"无法添加",query.lastError().text());
    qDebug() << query.lastError().text();
    return false;
}
template <typename T>
void WebsiteDao<T>::addByExcel(QStandardItemModel* model)
{
    db=DBHelper::getConnection();
    db.transaction();
    int rowCount = model->rowCount();
    //int colCount = model->columnCount();
    for (int row = 0; row < rowCount; ++row)
    {
        QPair<QString,int> tmp = T::getInsertSqlAndFieldsAmounts();
        QString sql = tmp.first;
        QSqlQuery query(db);
        query.prepare(sql);
        for (int col = 0; col < tmp.second; ++col)
        {
            QVariant value = model->index(row, col).data();
            if(value.type() == QVariant::Int)
                query.bindValue(col, value.toInt());
            else if(value.type() == QVariant::String)
                query.bindValue(col, value.toString());
            else if(value.type() == QVariant::DateTime)
                query.bindValue(col,value.toDateTime());
        }
        if(!query.exec())
        {
            db.rollback();
            QMessageBox::critical(nullptr,"导入失败",query.lastError().text());
            db.close();
            return;
        }
    }
    if(db.commit())
    {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setStandardButtons(nullptr);msgBox->setWindowModality(Qt::NonModal);msgBox->setWindowFlags(msgBox->windowFlags()|Qt::FramelessWindowHint);
        msgBox->setText("成功导入");msgBox->show();
        QTimer::singleShot(3500,[msgBox](){
            msgBox->close();
            delete msgBox;
        });
    }
    else
    {
        db.rollback();
        QMessageBox::critical(nullptr,"事务提交失败",db.lastError().text());
    }
    db.close();
}
template <typename T>
bool WebsiteDao<T>::eraseById(qint64 id)
{
    db=DBHelper::getConnection();
    QString sql="delete from " + T::getTableName() + " where " + T::getTableName() + "ID = ?";
    QSqlQuery query(sql,db);
    query.bindValue(0,id);
    if(query.exec())
    {
        QMessageBox *msgBox = new QMessageBox();
        msgBox->setStandardButtons(nullptr);msgBox->setWindowModality(Qt::NonModal);msgBox->setWindowFlags(msgBox->windowFlags()|Qt::FramelessWindowHint);
        msgBox->setText("删除成功");msgBox->resize(300,50);msgBox->show();
        QTimer::singleShot(3500,[msgBox](){
            msgBox->close();
            delete msgBox;
        });
        return true;
    }
    QMessageBox::critical(nullptr,"无法删除",query.lastError().text());
    qDebug() << query.lastError().text();
    return false;
}
template<typename T>
T WebsiteDao<T>::queryById(qint64 id)
{
    T entry = T();
    db=DBHelper::getConnection();
    QString sql="select * from ? where id = ?";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(0,T::getTableName());
    query.bindValue(1,id);
    if(query.exec())
    {
        while(query.next())
        {
            T::fillEntry(entry,query);
            return entry;
        }
    }
    qDebug() << query.lastError().text();
    return T();
}
template <typename T>
QSqlRelationalTableModel* WebsiteDao<T>::queryWithPageingAndConditions(int currentPage,int pageSize,QStringList* sqlConditions,QString foreignKeyName, QString foreignTableName,int column)
{
    db = DBHelper::getConnection();
    QSqlRelationalTableModel *tableModel = new QSqlRelationalTableModel(nullptr, db);
    tableModel->setTable(T::getTableName());
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QString filter = "1=1";
    if(nullptr != sqlConditions && !sqlConditions->empty())
    {
        QStringList sqlcon = *sqlConditions;
        filter.append(" AND (");
        for (int i = 0; i < sqlConditions->size(); ++i)
        {
            filter.append(sqlcon[i]);
        }
        filter.append(')');
    }
    filter.append(QString(" LIMIT %1 OFFSET %2").arg(pageSize).arg((currentPage - 1) * pageSize));
    tableModel->setFilter(filter);
    //if("" != tableName)tableModel->setRelation(column,QSqlRelation(foreignTableName,foreignKeyName,foreignTableName+"Name"));
    if(tableModel->select())
    {
        return tableModel;
    }
    qDebug() << "faild to select data from " << T::getTableName() << '\n' << tableModel->lastError().text();
    delete tableModel;
    return nullptr;
}
template <typename T>
int WebsiteDao<T>::queryTotalWithConditions(QStringList* sqlConditions)
{
    db = DBHelper::getConnection();
    QString sql = "select count(*) from " + T::getTableName();
    if(nullptr != sqlConditions && !sqlConditions->empty())
    {
        sql += " where ";
        QStringList sqlcon = *sqlConditions;
        for (int i = 0; i < sqlConditions->size(); ++i)
        {
            sql.append(sqlcon[i]);
        }
    }
    QSqlQuery query(db);
    query.prepare(sql);
    if(query.exec())
    {
        if(query.next()) return query.value(0).toInt();
    }
    qDebug() << query.lastError().text();
    return 0;
}
template <typename T>
bool WebsiteDao<T>::queryRoot(QString account,QString password)
{
     db = DBHelper::getConnection();
     QString sql = "select * from root where rootAccount = ? and rootPassword = ?";
     QSqlQuery query(db);
     query.prepare(sql);
     query.bindValue(0,account);
     query.bindValue(1,password);
     if(query.exec() && query.next())
     {
         return true;
     }
     qDebug() << query.lastError().text();
     return false;
}
template class WebsiteDao<User>;
template class WebsiteDao<Merchandise>;
template class WebsiteDao<Supplier>;
template class WebsiteDao<PurchaseOrder>;
template class WebsiteDao<UserComment>;
template class WebsiteDao<Review>;

