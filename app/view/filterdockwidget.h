#ifndef FILTERDOCKWIDGET_H
#define FILTERDOCKWIDGET_H

#include <QWidget>
#include<QMap>
namespace Ui {
class filterdockwidget;
}

class filterdockwidget : public QWidget
{
    Q_OBJECT

public:
    explicit filterdockwidget(QWidget *parent = nullptr);
    ~filterdockwidget();
    void init();
    void createConnections();
public slots:
    void setInfo(QStringList fields,bool type);
private:
    Ui::filterdockwidget *ui;
    QMap<QString,int> qsti;
    bool type;
signals:
    void preparedCompleteSIG();
public slots:
    void onbuttonBoxaccepted();
    void onbuttonBoxrejected();
    void addCondition(int index);
    void onDateTimeChanged(const QDateTime &dateTime);
};

#endif // FILTERDOCKWIDGET_H
