#include "BaseOperatorInformation.h"
#include "ui_baseoperatorinformation.h"
#include <QtDebug>
#include <QSqlRecord>
#include "updatedatadialog.h"
#include "filterdockwidget1.h"
#include "websitecontroller.h"
#include "usercomment.h"
#include "purchaseorder.h"
#include "review.h"
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include "mainwindow.h"
#include <QShortcut>
#include<QTimer>
#include<QMessageBox>
#include<QString>
BaseOperatorInformation::BaseOperatorInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseOperatorInformation)
{
    ui->setupUi(this);
    //init();
    //initUI();
}

BaseOperatorInformation::~BaseOperatorInformation()
{
    delete ui;
    delete sqlTableModel;
    std::visit([](auto *controller){
        delete controller;
    },websiteControll);
}
void BaseOperatorInformation::init()
{
    sqlTableModel = nullptr;
    if(this->objectName() == "user_manage_widget_page")websiteControll = WebsiteController<User>::get();
    else if(this->objectName() == "marchandise_manage_widget_page")websiteControll = WebsiteController<Merchandise>::get();
    else if(this->objectName() == "user_leaveWord_manage_widget_page")websiteControll = WebsiteController<UserComment>::get();
    else if(this->objectName() == "supplier_manage_widget_page")websiteControll = WebsiteController<Supplier>::get();
    else if(this->objectName() == "purchandiseOrder_manage_widget_page")websiteControll = WebsiteController<PurchaseOrder>::get();
    else if(this->objectName() == "review_manag_widget_page")websiteControll = WebsiteController<Review>::get();
    createConnections();
}
void BaseOperatorInformation::initUI()
{
    QGraphicsColorizeEffect *colorizeEffect = new QGraphicsColorizeEffect(ui->tableView_dataShow);
    ui->tableView_dataShow->setGraphicsEffect(colorizeEffect);

    QPropertyAnimation *animation = new QPropertyAnimation(colorizeEffect, "color");
    animation->setDuration(3000);
    animation->setLoopCount(-1);
    animation->setStartValue(QColor("#ffffff"));
    animation->setKeyValueAt(0.5, QColor("green"));
    animation->setEndValue(QColor("#ffffff"));
    animation->start();
}
QMenu* BaseOperatorInformation::createContextMenu(QModelIndex model)
{
    QMenu* contextMenu = new QMenu("menu",this);
    contextMenu->setObjectName("menu");
    QAction *action = new QAction("&删除当前行",contextMenu);
    action->setStatusTip("删除当前行");
    connect(action,&QAction::triggered,this,[this,model](){
        this->deleteCurrentRow(model.row());
    });
    contextMenu->addAction(action);

    action = new QAction("&删除选中行",contextMenu);
    action->setStatusTip("删除选中行");
    connect(action,&QAction::triggered,this,[this](){
       QModelIndexList selectd = ui->tableView_dataShow->selectionModel()->selectedRows();
       for (int i = selectd.size()-1;i>=0;i--)
       {
           sqlTableModel->removeRows(selectd.at(i).row(),1);
       }
       sqlTableModel->submitAll();
       QMessageBox *msgBox = new QMessageBox();
       msgBox->setStandardButtons(nullptr);msgBox->setWindowModality(Qt::NonModal);msgBox->setWindowFlags(msgBox->windowFlags()|Qt::FramelessWindowHint);
       msgBox->setText("已删除" + QString::number(selectd.size()) + "条数据");msgBox->show();
       QTimer::singleShot(3500,[msgBox](){
           msgBox->close();
           delete msgBox;
       });
    });
    contextMenu->addAction(action);

    action = new QAction("&编辑当前页",contextMenu);
    action->setStatusTip("编辑当前页");
    connect(action,&QAction::triggered,this,[this,model](){
        this->updateRowWithDialog(model);
    });
    contextMenu->addAction(action);

    if(model.column() > 0 && sqlTableModel->headerData(model.column(),Qt::Horizontal,Qt::DisplayRole).toString().endsWith("ID"))
    {
        action = new QAction("&展开该列",contextMenu);
        action->setStatusTip("展开该列");
        connect(action,&QAction::triggered,this,[this,model](){
            QString foreignKeyName = sqlTableModel->headerData(model.column(),Qt::Horizontal,Qt::DisplayRole).toString();
            QString tableName = foreignKeyName.chopped(2);
            int column = model.column();
            std::visit([foreignKeyName,tableName,column,this](auto *controller){
               controller->updateForeignTable(foreignKeyName,tableName,column);
               this->updateTableView();
            },websiteControll);
        });
        contextMenu->addAction(action);
    }

    return contextMenu;
}
void BaseOperatorInformation::insertRow(QStringList* sqlInsert,QStringList* sqlFields)
{
    std::visit([sqlFields,sqlInsert](auto* controller){
        controller->addByAll(sqlInsert,sqlFields);
    },websiteControll);
}
void BaseOperatorInformation::deleteCurrentRow(int rowIndex)
{
    int currentId(0);
    std::visit([currentId,rowIndex,this](auto *controller)mutable{
        currentId = sqlTableModel->record(rowIndex).value(0).toInt();
        controller->deleteById(currentId);
    },websiteControll);
    if(sqlTableModel) sqlTableModel->removeRow(rowIndex);
}
void BaseOperatorInformation::updateRowWithDialog(QModelIndex modelItem)
{
    UpdateDataDialog* dialog = new UpdateDataDialog(this);
    dialog->setModelIndex(modelItem);
}
void BaseOperatorInformation::createConnections()
{
    connect(this,&BaseOperatorInformation::updatePageNavicatSIG,ui->page_navicat,&PagingToolPage::updateLab_totalDataCounts);
    connect(ui->tableView_dataShow,&QTableView::customContextMenuRequested,[&](const QPoint &pos){
        QModelIndex index = ui->tableView_dataShow->indexAt(pos);
        if(index.isValid())
        {
            QMenu* contextMenu = createContextMenu(index);
            contextMenu->exec(ui->tableView_dataShow->viewport()->mapToGlobal(pos));
            connect(contextMenu,&QMenu::aboutToHide,contextMenu,&QMenu::deleteLater);
        }
    });
    connect(ui->btn_choose,&QPushButton::clicked,this,[this](){
        this->runChooseDockWidget(false);
    });
    connect(ui->btn_addData,&QPushButton::clicked,this,[this](){
        this->runChooseDockWidget(true);
    });
    connect(ui->btn_clearChoose,&QPushButton::clicked,this,&BaseOperatorInformation::onbtnclearChooseclicked);
    connect(ui->tb_search,&QToolButton::clicked,this,[this](){
        QString iop = ui->le_search->text();
        if("" != iop)
        {
            QStringList* filedNames = new QStringList();
            int i = 0;
            for(;i<sqlTableModel->columnCount() - 1;i++)
            {
                QString poi = sqlTableModel->headerData(i,Qt::Horizontal).toString();
                poi += " like \'%" + iop + "%\' OR ";
                filedNames->append(poi);
            }
            QString poi = sqlTableModel->headerData(i,Qt::Horizontal).toString();
            poi += " like \'%" + iop + "%\' ";
            filedNames->append(poi);
            this->updateConditions(filedNames);
        }
    });

}
void BaseOperatorInformation::updateTableView()
{
     std::visit([this](auto* controller) {
        sqlTableModel = controller->getEntrysWithPagingAndConditions();
    }, websiteControll);
    std::visit([this](auto* controller){
       emit this->updatePageNavicatSIG(controller->getTotalCountsWithConditions());
    },websiteControll);
    if(sqlTableModel != nullptr)
    {
        ui->tableView_dataShow->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView_dataShow->setModel(sqlTableModel);
        ui->tableView_dataShow->resizeColumnsToContents();
        ui->tableView_dataShow->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    }
}
void BaseOperatorInformation::updateConditions(QStringList* sqlConditions)
{
    std::visit([sqlConditions](auto* controller){
        controller->updateSqlCondition(sqlConditions);
    },websiteControll);
    static_cast<MainWindow*>(static_cast<QWidget*>(static_cast<QStackedWidget*>(this->parent())->parent())->parent())->updateChooseLabel(sqlConditions);
    updateTableView();
}
void BaseOperatorInformation::gotoPreviousPage()
{
    std::visit([](auto* controller){
        controller->gotoPreviousPage();
    },websiteControll);
    updateTableView();
}
void BaseOperatorInformation::gotoNextPage()
{
    std::visit([](auto* controller){
        controller->gotoNextPage();
    },websiteControll);
    updateTableView();
}
void BaseOperatorInformation::gotoPage(int pageNumber)
{
    std::visit([pageNumber](auto* controller){
        controller->gotoSpecifiedPage(pageNumber);
    },websiteControll);
    updateTableView();
}
void BaseOperatorInformation::updatePageSize(qint8 pageSize)
{
    std::visit([pageSize](auto* controller){
        controller->updatePageSize(pageSize);
    },websiteControll);
    updateTableView();
}
void BaseOperatorInformation::runChooseDockWidget(bool type)
{
    QStringList filedNames;
    for(int i=0;i<sqlTableModel->columnCount();i++)
    {
        filedNames.append(sqlTableModel->headerData(i,Qt::Horizontal).toString());
    }
    FilterDockWidget1 *fdw = new FilterDockWidget1(this);
    fdw->runSelf(filedNames,type);
}
void BaseOperatorInformation::onbtnclearChooseclicked()
{
    std::visit([](auto* controller){
        controller->updateSqlCondition(nullptr);
    },websiteControll);
    static_cast<MainWindow*>(static_cast<QWidget*>(static_cast<QStackedWidget*>(this->parent())->parent())->parent())->updateChooseLabel(nullptr);
    ui->le_search->setText("");
    updateTableView();
}
void BaseOperatorInformation::insertByExcel(QStandardItemModel* model)
{
    std::visit([model](auto* controller){
        controller->addByExcel(model);
    },websiteControll);
}
