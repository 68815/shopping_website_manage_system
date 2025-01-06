#ifndef PURCHASEORDER_H
#define PURCHASEORDER_H

#include <QApplication>
#include <QDateTime>
#include<QSqlQuery>

class PurchaseOrder
{
public:
    PurchaseOrder();
    ~PurchaseOrder();

    qint64 getOrderID() const;
    void setOrderID(const qint64 &value);

    QDateTime getOrderDateTime() const;
    void setOrderDateTime(const QDateTime &value);

    qint8 getOrderState() const;
    void setOrderState(const qint8 &value);

    qint64 getUserID() const;
    void setUserID(const qint64 &value);

    qint64 getMerchandiseID() const;
    void setMerchandiseID(const qint64 &value);

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<int,QDateTime,qint64> getField(int index);
    static void fillEntry(PurchaseOrder &entry,const QSqlQuery &query);

private:
    qint64 orderID;
    QDateTime orderDateTime;
    qint8 orderState;
    qint64 userID;
    qint64 merchandiseID;
};

#endif // PURCHASEORDER_H
