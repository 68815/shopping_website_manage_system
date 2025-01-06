/********************************************************************************
** Form generated from reading UI file 'updatedatadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEDATADIALOG_H
#define UI_UPDATEDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UpdateDataDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UpdateDataDialog)
    {
        if (UpdateDataDialog->objectName().isEmpty())
            UpdateDataDialog->setObjectName("UpdateDataDialog");
        UpdateDataDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(UpdateDataDialog);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(UpdateDataDialog);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        buttonBox = new QDialogButtonBox(UpdateDataDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(UpdateDataDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, UpdateDataDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, UpdateDataDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(UpdateDataDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateDataDialog)
    {
        UpdateDataDialog->setWindowTitle(QCoreApplication::translate("UpdateDataDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UpdateDataDialog: public Ui_UpdateDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEDATADIALOG_H
