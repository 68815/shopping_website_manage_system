#ifndef BASEOPERATORINFORMATION_H
#define BASEOPERATORINFORMATION_H

#include <QWidget>
#include "pagingtoolpage.h"
#include "user.h"
#include <QSqlTableModel>
#include <QMenu>
#include "websitecontroller.h"
#include <any>
#include <QSqlRelationalTableModel>
#include "Qxlsx/header/xlsxdocument.h"
#include <QStandardItemModel>
namespace Ui {
class BaseOperatorInformation;
}

class BaseOperatorInformation : public QWidget
{
    Q_OBJECT

public:
    explicit BaseOperatorInformation(QWidget *parent = nullptr);
    ~BaseOperatorInformation();

    void insertByExcel(QStandardItemModel* model);

    void init();
    void initUI();
    void createConnections();
    QMenu* createContextMenu(QModelIndex model);
signals:
    void updatePageNavicatSIG(qint64 index);
    void updateTableViewSIG(int index);
public slots:
    void updateTableView();
    void updateConditions(QStringList* sqlConditions);
    void gotoNextPage();
    void gotoPreviousPage();
    void gotoPage(int pageNumber);
    void deleteCurrentRow(int rowIndex);
    void updateRowWithDialog(QModelIndex modelItem);
    void updatePageSize(qint8 pageSize);
    void runChooseDockWidget(bool type);
    void onbtnclearChooseclicked();
    void insertRow(QStringList* sqlInsert,QStringList* sqlFields);
private:
    Ui::BaseOperatorInformation *ui;
    std::variant<
            WebsiteController<User>*,
            WebsiteController<PurchaseOrder>*,
            WebsiteController<Review>*,
            WebsiteController<Merchandise>*,
            WebsiteController<Supplier>*,
            WebsiteController<UserComment>*
        > websiteControll;
    QSqlRelationalTableModel* sqlTableModel;
};

#endif // BASEOPERATORINFORMATION_H
