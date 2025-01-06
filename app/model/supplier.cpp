#include "supplier.h"
#include<variant>
#include<QVariant>
Supplier::Supplier()
{

}
Supplier::~Supplier()
{

}

QString Supplier::getSupplierEmail()
{
    return supplierEmail;
}

void Supplier::setSupplierEmail(QString value)
{
    supplierEmail = value;
}

QString Supplier::getSupplierAddress()
{
    return supplierAddress;
}

void Supplier::setSupplierAddress(QString value)
{
    supplierAddress = value;
}

QString Supplier::getSupplierName()
{
    return supplierName;
}

void Supplier::setSupplierName(QString value)
{
    supplierName = value;
}

qint64 Supplier::getSupplierID()
{
    return supplierID;
}

void Supplier::setSupplierID(qint64 value)
{
    supplierID = value;
}

QString Supplier::getTableName()
{
    return "supplier";
}
QPair<QString,int> Supplier::getInsertSqlAndFieldsAmounts()
{
    return QPair<QString,int>("insert into supplier(supplierName,supplierAddress,userEmail) values(?,?,?)" , 3);
}
std::variant<QString,int,qint64> Supplier::getField(int index)
{
    if(index == 0)return supplierID;
    if(index == 1)return supplierName;
    if(index == 2)return supplierAddress;
    if(index == 3)return supplierEmail;
    return 0;
}
void Supplier::fillEntry(Supplier &entry, const QSqlQuery& query)
{
    entry.setSupplierID(qint64(query.value("supplierID").toInt()));
    entry.setSupplierName(query.value("supplierName").toString());
    entry.setSupplierAddress(query.value("supplierAddress").toString());
    entry.setSupplierEmail(query.value("supplierEmail").toString());
}
