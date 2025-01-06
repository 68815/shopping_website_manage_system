#include "usercomment.h"

UserComment::UserComment()
{

}

qint64 UserComment::getCommentID() const
{
    return commentID;
}

void UserComment::setCommentID(const qint64 &value)
{
    commentID = value;
}

QDateTime UserComment::getCommentDateTime() const
{
    return commentDateTime;
}

void UserComment::setCommentDateTime(const QDateTime &value)
{
    commentDateTime = value;
}

QString UserComment::getCommentContent() const
{
    return commentContent;
}

void UserComment::setCommentContent(const QString &value)
{
    commentContent = value;
}

qint64 UserComment::getUserID() const
{
    return userID;
}

void UserComment::setUserID(const qint64 &value)
{
    userID = value;
}

QString UserComment::getTableName()
{
    return "user_comment";
}
QPair<QString,int> UserComment::getInsertSqlAndFieldsAmounts()
{
    return QPair<QString,int>("insert into user_comment(userID,commentDateTime,commentContent) values(?,?,?)" , 3);
}
std::variant<QString,int,QDateTime,qint64> UserComment::getField(int index)
{
    if(index == 0)return commentID;
    if(index == 1)return userID;
    if(index == 2)return commentDateTime;
    if(index == 3)return commentContent;
    return 0;
}
void UserComment::fillEntry(UserComment &entry, const QSqlQuery& query)
{
    entry.setCommentID(query.value("commentID").toInt());
    entry.setUserID(query.value("userID").toInt());
    entry.setCommentDateTime(QDateTime::fromString(query.value("commentDateTime").toString(), Qt::ISODate));
    entry.setCommentContent(query.value("commentContent").toString());
}
