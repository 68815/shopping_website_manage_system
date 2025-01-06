#ifndef REVIEW_H
#define REVIEW_H

#include <QApplication>
#include <QDateTime>
#include <QSqlQuery>

class Review
{
public:
    Review();

    qint64 getReviewID() const;
    void setReviewID(const qint64 &value);

    QDateTime getReviewDateTime() const;
    void setReviewDateTime(const QDateTime &value);

    qint64 getUserID() const;
    void setUserID(const qint64 &value);

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<QString,int,QDateTime,qint64> getField(int index);
    static void fillEntry(Review &entry,const QSqlQuery &query);

private:
    qint64 reviewID;
    QDateTime reviewDateTime;
    qint64 userID;
};

#endif // REVIEW_H
