#include "websitecontroller.h"
template <typename T>
WebsiteController<T>* WebsiteController<T>::sWebsiteController;
template<typename T>
WebsiteController<T>::WebsiteController()
{
    websiteDao = new WebsiteDao<T>();
    this->pageNumber = 1;
    this->pageSize = 10;
    this->tableName = "";
    this->foreignKeyName = "";
    this->column = 0;
    this->sqlConditions = nullptr;
}
template<typename T>
WebsiteController<T>::~WebsiteController()
{
    //delete websiteDao;
    //delete sWebsiteController;
}
template<typename T>
WebsiteController<T>* WebsiteController<T>::get()
{
    if(nullptr == sWebsiteController)
    {
        sWebsiteController = new WebsiteController<T>();
    }
    return sWebsiteController;
}
template<typename T>
QSqlRelationalTableModel* WebsiteController<T>::getEntrysWithPagingAndConditions()
{
    return websiteDao->queryWithPageingAndConditions(pageNumber,pageSize,sqlConditions,foreignKeyName,tableName,column);
}
template<typename T>
int WebsiteController<T>::getTotalCountsWithConditions()
{
    return websiteDao->queryTotalWithConditions(sqlConditions);
}
template<typename T>
bool WebsiteController<T>::deleteById(qint64 id)
{
    return websiteDao->eraseById(id);
}
template<typename T>
bool WebsiteController<T>::addbyAll(T entry)
{
    return websiteDao->addByAll(entry);
}
template<typename T>
bool WebsiteController<T>::addByAll(QStringList* sqlInsert,QStringList* sqlFields)
{
    return websiteDao->addByAll(sqlInsert,sqlFields);
}
template <typename T>
void WebsiteController<T>::addByExcel(QStandardItemModel* model)
{
    this->websiteDao->addByExcel(model);
}
template <typename T>
bool WebsiteController<T>::getRoot(QString account,QString password)
{
    return websiteDao->queryRoot(account,password);
}
template <typename T>
void WebsiteController<T>::gotoPreviousPage()
{
    pageNumber = std::max(1,pageNumber - 1);
}
template <typename T>
void WebsiteController<T>::gotoNextPage()
{
    pageNumber++;
}
template <typename T>
void WebsiteController<T>::gotoSpecifiedPage(int pageNumber)
{
    this->pageNumber = pageNumber;
}
template <typename T>
void WebsiteController<T>::updatePageSize(int pageSize)
{
    this->pageSize = pageSize;
}
template <typename T>
void WebsiteController<T>::updateForeignTable(QString foreignKeyName, QString tableName,int column)
{
    this->foreignKeyName = foreignKeyName;
    this->tableName = tableName;
    this->column = column;
}
template <typename T>
void WebsiteController<T>::updateSqlCondition(QStringList* sqlConditions)
{
    this->sqlConditions = sqlConditions;
}
template <typename T>
QStringList* WebsiteController<T>::getSqlConditions()
{
    return sqlConditions;
}
template class WebsiteController<User>;
template class WebsiteController<Merchandise>;
template class WebsiteController<Supplier>;
template class WebsiteController<PurchaseOrder>;
template class WebsiteController<UserComment>;
template class WebsiteController<Review>;
