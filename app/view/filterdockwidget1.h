#ifndef FILTERDOCKWIDGET1_H
#define FILTERDOCKWIDGET1_H

#include <QDockWidget>

namespace Ui {
class FilterDockWidget1;
}

class FilterDockWidget1 : public QDockWidget
{
    Q_OBJECT

public:
    explicit FilterDockWidget1(QWidget *parent = nullptr);
    ~FilterDockWidget1();
    void init();
    void createConnections();

private:
    Ui::FilterDockWidget1 *ui;
    friend class Login;

public slots:
    void runSelf(QStringList fileds,bool type);
    void runSelf1();
signals:
    void runSelfSIG(QStringList fields,bool type);
};

#endif // FILTERDOCKWIDGET1_H
