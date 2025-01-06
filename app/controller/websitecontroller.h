#ifndef WEBSITECONTROLLER_H
#define WEBSITECONTROLLER_H
#include "websitedao.h"
#include "Qxlsx/header/xlsxdocument.h"
#include <QStandardItemModel>
template<typename T>
class WebsiteController
{
public:
    ~WebsiteController();
    static WebsiteController* get();

    bool addbyAll(T entry);
    bool addByAll(QStringList* sqlInsert,QStringList* sqlFields);
    void addByExcel(QStandardItemModel* model);

    bool deleteById(qint64 id);

    int getTotalCountsWithConditions();
    QSqlRelationalTableModel* getEntrysWithPagingAndConditions();
    bool getRoot(QString account,QString password);

    void gotoPreviousPage();
    void gotoNextPage();
    void gotoSpecifiedPage(int pageNumber);
    void updatePageSize(int pageSize);
    void updateSqlCondition(QStringList* sqlConditions);
    void updateForeignTable(QString foreignKeyName, QString tableName,int column);
    QStringList* getSqlConditions();
private:
    WebsiteDao<T>* websiteDao;
    static WebsiteController* sWebsiteController;
    WebsiteController();

    int pageNumber;
    int pageSize;
    int column;
    QString foreignKeyName;
    QString tableName;
    QStringList* sqlConditions;

};

#endif // WEBSITECONTROLLER_H
