#ifndef MERCHANDISE_H
#define MERCHANDISE_H
#include<QApplication>
#include <iostream>
#include <QSqlQuery>
#include<variant>
class Merchandise
{
public:
    Merchandise();
    ~Merchandise();

    void setMerchandiseID(qint64 merchandiseName);
    qint64 getMerchandiseID();

    void setMerchandiseName(QString merchandiseName);
    QString getMerchandiseName();

    void setMerchandisePrice(double merchandisePrice);
    double getMerchandisePrice();

    void setMerchandiseCounts(qint64 merchandiseCounts);
    qint64 getMerchandiseCounts();

    void setSupplierID(qint64 supplierID);
    qint64 getSupplierID();

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<qint64,QString,double,int> getField(int index);
    static void fillEntry(Merchandise &entry,const QSqlQuery &query);

private:
    qint64 merchandiseID;
    QString merchandiseName;
    double merchandisePrice;
    qint64 merchandiseCounts;
    qint64 supplierID;
};

#endif // MERCHANDISE_H
