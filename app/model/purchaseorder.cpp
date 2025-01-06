#include "purchaseorder.h"

PurchaseOrder::PurchaseOrder()
{

}

PurchaseOrder::~PurchaseOrder()
{

}

qint64 PurchaseOrder::getOrderID() const
{
    return orderID;
}

void PurchaseOrder::setOrderID(const qint64 &value)
{
    orderID = value;
}

QDateTime PurchaseOrder::getOrderDateTime() const
{
    return orderDateTime;
}

void PurchaseOrder::setOrderDateTime(const QDateTime &value)
{
    orderDateTime = value;
}

qint8 PurchaseOrder::getOrderState() const
{
    return orderState;
}

void PurchaseOrder::setOrderState(const qint8 &value)
{
    orderState = value;
}

qint64 PurchaseOrder::getUserID() const
{
    return userID;
}

void PurchaseOrder::setUserID(const qint64 &value)
{
    userID = value;
}

qint64 PurchaseOrder::getMerchandiseID() const
{
    return merchandiseID;
}

void PurchaseOrder::setMerchandiseID(const qint64 &value)
{
    merchandiseID = value;
}

QString PurchaseOrder::getTableName()
{
    return "purchaseorder";
}
QPair<QString,int> PurchaseOrder::getInsertSqlAndFieldsAmounts()
{
    return QPair<QString,int>("insert into purchaseorder(orderDateTime,orderState,userID,merchandiseID) values(?,?,?,?)" , 4);
}
std::variant<int,QDateTime,qint64> PurchaseOrder::getField(int index)
{
    if(index == 0)return orderID;
    if(index == 1)return orderDateTime;
    if(index == 2)return orderState;
    if(index == 3)return userID;
    if(index == 4)return merchandiseID;
    return 0;
}
void PurchaseOrder::fillEntry(PurchaseOrder &entry, const QSqlQuery& query)
{
    entry.setOrderID(query.value("orderID").toInt());
    entry.setOrderDateTime(QDateTime::fromString(query.value("orderDateTime").toString(), Qt::ISODate));
    entry.setOrderState(qint8(query.value("orderState").toInt()));
    entry.setUserID(query.value("userID").toInt());
    entry.setMerchandiseID(query.value("merchandiseID").toInt());
}
