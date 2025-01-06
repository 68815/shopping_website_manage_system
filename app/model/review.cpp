#include "review.h"

Review::Review()
{

}

qint64 Review::getReviewID() const
{
    return reviewID;
}

void Review::setReviewID(const qint64 &value)
{
    reviewID = value;
}

QDateTime Review::getReviewDateTime() const
{
    return reviewDateTime;
}

void Review::setReviewDateTime(const QDateTime &value)
{
    reviewDateTime = value;
}

qint64 Review::getUserID() const
{
    return userID;
}

void Review::setUserID(const qint64 &value)
{
    userID = value;
}

QString Review::getTableName()
{
    return "review";
}
QPair<QString,int> Review::getInsertSqlAndFieldsAmounts()
{
    return QPair<QString,int>("insert into review(reviewDateTime,userID) values(?,?)" , 2);
}
std::variant<QString,int,QDateTime,qint64> Review::getField(int index)
{
    if(index == 0)return reviewID;
    if(index == 1)return reviewDateTime;
    if(index == 2)return userID;
    return 0;
}
void Review::fillEntry(Review &entry, const QSqlQuery& query)
{
    entry.setReviewID(query.value("reviewID").toInt());
    entry.setReviewDateTime(QDateTime::fromString(query.value("reviewDateTime").toString(), Qt::ISODate));
    entry.setUserID(query.value("reviewUserID").toInt());
}
