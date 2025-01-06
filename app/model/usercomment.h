#ifndef USERCOMMENT_H
#define USERCOMMENT_H

#include <QApplication>
#include <QDateTime>
#include<QSqlQuery>

class UserComment
{
public:
    UserComment();

    qint64 getCommentID() const;
    void setCommentID(const qint64 &value);

    QDateTime getCommentDateTime() const;
    void setCommentDateTime(const QDateTime &value);

    QString getCommentContent() const;
    void setCommentContent(const QString &value);

    qint64 getUserID() const;
    void setUserID(const qint64 &value);

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<QString,int,QDateTime,qint64> getField(int index);
    static void fillEntry(UserComment &entry,const QSqlQuery &query);

private:
    qint64 commentID;
    QDateTime commentDateTime;
    QString commentContent;
    qint64 userID;
};

#endif // USERCOMMENT_H
