#ifndef DAOUTIL_H
#define DAOUTIL_H
#include <qsqldatabase.h>
#include<QMutex>
class DBHelper
{
public:
    static QSqlDatabase getConnection();
    static QSqlDatabase db;
    static QMutex mutex;
private:
    DBHelper();
    ~DBHelper();
};
#endif // DAOUTIL_H
