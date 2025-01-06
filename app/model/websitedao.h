#ifndef USERDAO_H
#define USERDAO_H

#include <qsqldatabase.h>
#include "user.h"
#include "merchandise.h"
#include <qsqltablemodel.h>
#include"DBHelper.h"
#include"supplier.h"
#include"purchaseorder.h"
#include"review.h"
#include"usercomment.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include "Qxlsx/header/xlsxdocument.h"
#include <QStandardItemModel>
template<typename T>
class WebsiteDao
{
public:
    WebsiteDao();
    ~WebsiteDao();

    QSqlDatabase db;

    int queryTotalWithConditions(QStringList* sqlConditions);
    bool addByAll(T entry);
    bool addByAll(QStringList* sqlInsert,QStringList* sqlFields);
    void addByExcel(QStandardItemModel* model);
    bool eraseById(qint64 id);
    T queryById(qint64 id);
    QSqlRelationalTableModel* queryWithPageingAndConditions(int currentPage,int pageSize,QStringList* sqlConditions,QString foreignKeyName, QString tableName,int column);

    bool queryRoot(QString account,QString password);

    QSqlDatabase getConnection();
    void closeConnection();
private:

};
#endif // USERDAO_H
