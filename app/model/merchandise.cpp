#include "merchandise.h"
Merchandise::Merchandise()
    : merchandiseID(0),
      supplierID(0) {
    merchandiseName = "";
    merchandisePrice = 0.0;
    merchandiseCounts = 0;
}
Merchandise::~Merchandise() {
}
void Merchandise::setMerchandiseID(qint64 id) {
    merchandiseID = id;
}
qint64 Merchandise::getMerchandiseID(){
    return merchandiseID;
}
void Merchandise::setMerchandiseName(QString name) {
    merchandiseName = name;
}
QString Merchandise::getMerchandiseName(){
    return merchandiseName;
}
void Merchandise::setMerchandisePrice(double price) {
    merchandisePrice = price;
}
double Merchandise::getMerchandisePrice(){
    return merchandisePrice;
}
void Merchandise::setMerchandiseCounts(qint64 counts) {
    merchandiseCounts = counts;
}
qint64 Merchandise::getMerchandiseCounts(){
    return merchandiseCounts;
}
void Merchandise::setSupplierID(qint64 supplierId) {
    supplierID = supplierId;
}
qint64 Merchandise::getSupplierID(){
    return supplierID;
}
QString Merchandise::getTableName()
{
    return "merchandise";
}
QPair<QString,int> Merchandise::getInsertSqlAndFieldsAmounts()
{
    return QPair<QString,int>("insert into merchandise(merchandiseName, merchandisePrice, merchandiseCounts,supplierID) values(?,?,?,?)",4);
}
std::variant<qint64,QString,double,int> Merchandise::getField(int index)
{
    if(index == 0)return merchandiseID;
    if(index == 1)return merchandiseName;
    if(index == 2)return merchandisePrice;
    if(index == 3)return merchandiseCounts;
    if(index == 4)return supplierID;
    return 0;
}
void Merchandise::fillEntry(Merchandise &entry, const QSqlQuery& query)
{
    entry.setMerchandiseID(query.value("merchandiseID").toLongLong());
    entry.setMerchandiseName(query.value("merchandiseName").toString());
    entry.setMerchandisePrice(query.value("merchandisePrice").toDouble());
    entry.setMerchandiseCounts(query.value("merchandiseCounts").toInt());
    entry.setSupplierID(query.value("supplierID").toLongLong());
}
