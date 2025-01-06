#include "DBHelper.h"
#include <QtDebug>
#include <QSqlError>
#include <QSqlDriver>
QSqlDatabase DBHelper::db;
QMutex DBHelper::mutex;
QSqlDatabase DBHelper::getConnection()
{
    QString connection = "QMYSQL";
    QMutexLocker mutexLocker(&mutex);
    if(QSqlDatabase::contains("e1"))
    {
        DBHelper::db = QSqlDatabase::database("e1");
    }
    else {
        DBHelper::db = QSqlDatabase::addDatabase(connection,"e1");
        DBHelper::db.setHostName("localhost");
        DBHelper::db.setDatabaseName("website");
        DBHelper::db.setUserName("root");
        DBHelper::db.setPassword(std::getenv("DATABASE_ROOT_PASSWORD"));
        DBHelper::db.setPort(3306);
    }
    if (!DBHelper::db.open())
    {
        qDebug() << "Failed to connect to website database:" << DBHelper::db.lastError().text();
        qDebug() << "Available drivers:" << QSqlDatabase::drivers();
        return QSqlDatabase();
    }
    qDebug() << DBHelper::db.driver()->hasFeature(QSqlDriver::Transactions);
    return DBHelper::db;
}
