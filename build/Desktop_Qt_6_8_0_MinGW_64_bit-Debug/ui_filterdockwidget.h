/********************************************************************************
** Form generated from reading UI file 'filterdockwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDOCKWIDGET_H
#define UI_FILTERDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filterdockwidget
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *cbb_a;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *filterdockwidget)
    {
        if (filterdockwidget->objectName().isEmpty())
            filterdockwidget->setObjectName("filterdockwidget");
        filterdockwidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(filterdockwidget);
        verticalLayout->setObjectName("verticalLayout");
        cbb_a = new QComboBox(filterdockwidget);
        cbb_a->setObjectName("cbb_a");

        verticalLayout->addWidget(cbb_a);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");

        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(filterdockwidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(filterdockwidget);

        QMetaObject::connectSlotsByName(filterdockwidget);
    } // setupUi

    void retranslateUi(QWidget *filterdockwidget)
    {
        filterdockwidget->setWindowTitle(QCoreApplication::translate("filterdockwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterdockwidget: public Ui_filterdockwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDOCKWIDGET_H
