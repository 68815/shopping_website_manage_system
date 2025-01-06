#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtDebug>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "logindialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ww;
    ww.show();

    return a.exec();
}
