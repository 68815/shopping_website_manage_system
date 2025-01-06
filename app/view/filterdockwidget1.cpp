#include "filterdockwidget1.h"
#include "ui_filterdockwidget1.h"
#include "filterdockwidget.h"
#include <QTimer>
FilterDockWidget1::FilterDockWidget1(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::FilterDockWidget1)
{
    ui->setupUi(this);
    init();
}

FilterDockWidget1::~FilterDockWidget1()
{
    delete ui;
}
void FilterDockWidget1::init()
{
    filterdockwidget *wid = new filterdockwidget(this);
    this->setWidget(wid);
    this->setWindowOpacity(0);
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->setStyleSheet("QDockWidget { background: white; }");
    createConnections();
}
void FilterDockWidget1::createConnections()
{
    connect(this,&FilterDockWidget1::runSelfSIG,static_cast<filterdockwidget*>(this->widget()),&filterdockwidget::setInfo);
}
void FilterDockWidget1::runSelf(QStringList fields,bool type)
{
    emit runSelfSIG(fields,type);
}
void FilterDockWidget1::runSelf1()
{
    this->setStyleSheet("QDockWidget{background-color:#333333;color:#00e000}");
    this->setFloating(true);
    this->setVisible(true);
    this->raise();
    this->show();
}
