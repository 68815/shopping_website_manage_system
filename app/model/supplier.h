#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <QPair>
#include<variant>
#include<QSqlQuery>
class Supplier
{
public:
    Supplier();
    ~Supplier();

    QString getSupplierEmail() ;
    void setSupplierEmail(QString email);

    QString getSupplierAddress();
    void setSupplierAddress(QString address);

    QString getSupplierName();
    void setSupplierName(QString name);

    qint64 getSupplierID();
    void setSupplierID(qint64 id);

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<QString,int,qint64> getField(int index);
    static void fillEntry(Supplier &entry,const QSqlQuery &query);

private:
    qint64 supplierID;
    QString supplierName;
    QString supplierAddress;
    QString supplierEmail;
};

#endif // SUPPLIER_H
