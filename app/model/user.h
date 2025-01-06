#ifndef USER_H
#define USER_H

#include<QApplication>
#include <iostream>
#include <QSqlQuery>
#include<QDateTime>
#include<variant>
class User
{
public:
    User();
    ~User();
    User(QString email,QString password);
    qint64 getId();
    void setId(qint64 id);
    QString getEmail();
    void setEmail(QString email);
    QString getPassword();
    void setPassword(QString pwd);
    QString getName();
    void setName(QString name);
    QDateTime getUserRegisterDateTime() const;
    void setUserRegisterDateTime(const QDateTime &value);
    QDateTime getUserLastloginDateTime() const;
    void setUserLastloginDateTime(const QDateTime &value);

    static QString getTableName();
    static QPair<QString,int> getInsertSqlAndFieldsAmounts();
    std::variant<QString,int,QDateTime,qint64> getField(int index);
    static void fillEntry(User &entry,const QSqlQuery &query);

    QString getUserHeadImageURL() const;
    void setUserHeadImageURL(const QString &value);

private:
    qint64 id;
    QString email;
    QString password;
    QString name;
    QString userHeadImageURL;
    QDateTime userRegisterDateTime;
    QDateTime userLastloginDateTime;
};
#endif // USER_H
