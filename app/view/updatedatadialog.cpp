#include "updatedatadialog.h"
#include "ui_updatedatadialog.h"
#include<QModelIndex>
#include<QDialog>
#include<QSqlRelationalTableModel>
UpdateDataDialog::UpdateDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateDataDialog)
{
    ui->setupUi(this);
    init();
}
UpdateDataDialog::~UpdateDataDialog()
{
    delete ui;
}
void UpdateDataDialog::init()
{
    this->setWindowTitle("修改");
    createConnections();
}
void UpdateDataDialog::createConnections()
{
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&UpdateDataDialog::onbuttonBoxaccepted);
    connect(ui->buttonBox,&QDialogButtonBox::rejected,this,&UpdateDataDialog::onbuttonBoxrejected);
}
void UpdateDataDialog::setModelIndex(QModelIndex &modelIndex)
{
    if(modelIndex.isValid())
    {
        QSqlRelationalTableModel* sqlTableModel = qobject_cast<QSqlRelationalTableModel*>(const_cast<QAbstractItemModel*>(modelIndex.model()));
        ui->tableView->setModel(sqlTableModel);
        connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
                    this, &UpdateDataDialog::onSelectionChanged);
        this->exec();
    }
}
void UpdateDataDialog::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QItemSelection newSelection;
    for (const QModelIndex &index : selected.indexes()) {
        if (index.column() != 0) {
            newSelection.select(index, index);
        }
    }
    selectionModel->select(newSelection, QItemSelectionModel::ClearAndSelect);
}
void UpdateDataDialog::onbuttonBoxaccepted()
{
    qobject_cast<QSqlTableModel*>(ui->tableView->model())->submitAll();
}

void UpdateDataDialog::onbuttonBoxrejected()
{
    qobject_cast<QSqlTableModel*>(ui->tableView->model())->revertAll();
}
