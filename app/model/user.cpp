
#include "user.h"
User::User()
{

}
User::~User()
{

}
User:: User(QString email,QString password)
{
    this->email=email;
    this->password=password;
    if(this->name.isNull())
    {
            this->name=email.split("@")[0];
    }
}
qint64 User::getId()
{
    return id;
}
void User::setId(qint64 id)
{
    this->id = id;
}
QString User::getEmail()
{
    return email;
}
void User::setEmail(QString email)
{
    this->email = email;
}
QString User::getPassword()
{
    return password;
}
void User::setPassword(QString password)
{
    this->password = password;
}
QString User::getName()
{
    return name;
}
void User::setName(QString name)
{
    this->name = name;
}
QDateTime User::getUserRegisterDateTime() const
{
    return userRegisterDateTime;
}
void User::setUserRegisterDateTime(const QDateTime &value)
{
    userRegisterDateTime = value;
}
QDateTime User::getUserLastloginDateTime() const
{
    return userLastloginDateTime;
}
void User::setUserLastloginDateTime(const QDateTime &value)
{
    userLastloginDateTime = value;
}
    QString User::getTableName()
    {
        return "user";
    }
    QPair<QString,int> User::getInsertSqlAndFieldsAmounts()
    {
        return QPair<QString,int>("insert into user(userName,userPassword,userEmail,userHeadImageURL,userRegisterDateTime,userLastloginDateTime) values(?,?,?,?,?,?)" , 6);
    }
    std::variant<QString,int,QDateTime,qint64> User::getField(int index)
    {
        if(index == 0)return id;
        if(index == 1)return name;
        if(index == 2)return password;
        if(index == 3)return email;
        if(index == 4)return userHeadImageURL;
        if(index == 5)return userRegisterDateTime;
        if(index == 6)return userLastloginDateTime;
        return 0;
    }
    void User::fillEntry(User &entry, const QSqlQuery& query)
    {
        entry.setId(query.value("userID").toInt());
        entry.setName(query.value("userName").toString());
        entry.setEmail(query.value("userEmail").toString());
        entry.setPassword(query.value("userPassword").toString());
        entry.setUserHeadImageURL(query.value("userHeadImageURL").toString());
        entry.setUserRegisterDateTime(QDateTime::fromString(query.value("userRegisterDateTime").toString(), Qt::ISODate));
        entry.setUserLastloginDateTime(QDateTime::fromString(query.value("userLastloginDateTime").toString(), Qt::ISODate));
    }

    QString User::getUserHeadImageURL() const
    {
        return userHeadImageURL;
    }

    void User::setUserHeadImageURL(const QString &value)
    {
        userHeadImageURL = value;
    }
