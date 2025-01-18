#ifndef UPDATEDATADIALOG_H
#define UPDATEDATADIALOG_H

#include <QDialog>
#include<QItemSelection>

namespace Ui {
class UpdateDataDialog;
}

class UpdateDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateDataDialog(QWidget *parent = nullptr);
    ~UpdateDataDialog();
    void init();
    void createConnections();
    void setModelIndex(QModelIndex& modelIndex);
private slots:
    void onbuttonBoxaccepted();
    void onbuttonBoxrejected();

private:
    Ui::UpdateDataDialog *ui;

    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

    friend class Login;
};

#endif // UPDATEDATADIALOG_H
