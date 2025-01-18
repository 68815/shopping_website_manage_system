#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "BaseOperatorInformation.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    //initUI();
    loadStyleSheet(":/style.qss");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initUI()
{
    //ui->toolBox->setStyleSheet("animation: example 3.5s linear infinite;");
}
void MainWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(sheetName);
    if (file.open(QFile::ReadOnly))
    {
         QString styleSheet = QLatin1String(file.readAll());
         qApp->setStyleSheet(styleSheet);
         file.close();
     }
    else
    {
         qWarning("Unable to open the stylesheet file.");
    }
}
void MainWindow::init()
{
    createActionsInMenubar();
    createActionsInToolbar();

    //createAnimations();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(0))->init();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(1))->init();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(2))->init();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(3))->init();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(4))->init();
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->widget(5))->init();
    createConections();
    ui->toolBox->setCurrentIndex(1);
    ui->toolBox->setCurrentIndex(0);
}
void MainWindow::createActionsInMenubar()
{
    QAction *action = new QAction("&新建",this);
    action->setStatusTip("新建");
    connect(action,&QAction::triggered,this,[]{

    });
    QMenu *menu = ui->menubar->addMenu(tr("文件"));
    menu->addAction(action);

    menu = ui->menubar->addMenu(tr("编辑"));

    menu = ui->menubar->addMenu(tr("查看"));

    menu = ui->menubar->addMenu(tr("收藏夹"));

    menu = ui->menubar->addMenu(tr("工具"));

    menu = ui->menubar->addMenu(tr("窗口"));

    menu = ui->menubar->addMenu(tr("帮助"));
}
void MainWindow::createActionsInToolbar()
{

}
void MainWindow::stackWidgetPageChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    static_cast<BaseOperatorInformation*>(ui->stackedWidget->currentWidget())->updateTableView();
}
void MainWindow::createConections()
{
    connect(ui->toolBox,&QToolBox::currentChanged,this,&MainWindow::stackWidgetPageChanged);
}
void MainWindow::createAnimations()
{
    QGraphicsColorizeEffect *colorizeEffect = new QGraphicsColorizeEffect(ui->toolBox);
    ui->toolBox->setGraphicsEffect(colorizeEffect);

    QPropertyAnimation *animation = new QPropertyAnimation(colorizeEffect, "color");
    animation->setDuration(3000);
    animation->setLoopCount(-1);
    animation->setStartValue(QColor("#333333"));
    animation->setKeyValueAt(0.5, QColor("#555555"));
    animation->setEndValue(QColor("#333333"));
    animation->start();
}
void MainWindow::updateChooseLabel(QStringList *sqlConditions)
{
    QLabel* la = ui->toolBox->currentWidget()->findChild<QLabel*>("le_chooseConditions_" + QString::number(ui->toolBox->currentIndex() + 1));
    QString poi = "筛选：";
    if(nullptr != sqlConditions)
    {
        for(int i = 0;i < sqlConditions->size(); i++)
        {
            poi += '\n';
            poi += sqlConditions->at(i);
        }
    }
    la->setText(poi);
}
