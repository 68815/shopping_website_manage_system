/********************************************************************************
** Form generated from reading UI file 'baseoperatorinformation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEOPERATORINFORMATION_H
#define UI_BASEOPERATORINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pagingtoolpage.h"

QT_BEGIN_NAMESPACE

class Ui_BaseOperatorInformation
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_choose;
    QPushButton *btn_clearChoose;
    QPushButton *btn_addData;
    QLineEdit *le_search;
    QToolButton *tb_search;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_dataShow;
    PagingToolPage *page_navicat;

    void setupUi(QWidget *BaseOperatorInformation)
    {
        if (BaseOperatorInformation->objectName().isEmpty())
            BaseOperatorInformation->setObjectName("BaseOperatorInformation");
        BaseOperatorInformation->resize(784, 383);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(BaseOperatorInformation->sizePolicy().hasHeightForWidth());
        BaseOperatorInformation->setSizePolicy(sizePolicy);
        BaseOperatorInformation->setSizeIncrement(QSize(0, 0));
        BaseOperatorInformation->setWindowOpacity(1.000000000000000);
        BaseOperatorInformation->setLayoutDirection(Qt::LeftToRight);
        BaseOperatorInformation->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(BaseOperatorInformation);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btn_choose = new QPushButton(BaseOperatorInformation);
        btn_choose->setObjectName("btn_choose");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_choose->sizePolicy().hasHeightForWidth());
        btn_choose->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btn_choose);

        btn_clearChoose = new QPushButton(BaseOperatorInformation);
        btn_clearChoose->setObjectName("btn_clearChoose");

        horizontalLayout->addWidget(btn_clearChoose);

        btn_addData = new QPushButton(BaseOperatorInformation);
        btn_addData->setObjectName("btn_addData");

        horizontalLayout->addWidget(btn_addData);

        le_search = new QLineEdit(BaseOperatorInformation);
        le_search->setObjectName("le_search");

        horizontalLayout->addWidget(le_search);

        tb_search = new QToolButton(BaseOperatorInformation);
        tb_search->setObjectName("tb_search");

        horizontalLayout->addWidget(tb_search);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView_dataShow = new QTableView(BaseOperatorInformation);
        tableView_dataShow->setObjectName("tableView_dataShow");
        QFont font;
        font.setPointSize(8);
        tableView_dataShow->setFont(font);
        tableView_dataShow->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView_dataShow->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableView_dataShow->verticalHeader()->setMinimumSectionSize(50);
        tableView_dataShow->verticalHeader()->setDefaultSectionSize(50);

        verticalLayout_2->addWidget(tableView_dataShow);

        page_navicat = new PagingToolPage(BaseOperatorInformation);
        page_navicat->setObjectName("page_navicat");

        verticalLayout_2->addWidget(page_navicat);

        verticalLayout_2->setStretch(0, 20);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout->setStretch(1, 20);

        retranslateUi(BaseOperatorInformation);

        QMetaObject::connectSlotsByName(BaseOperatorInformation);
    } // setupUi

    void retranslateUi(QWidget *BaseOperatorInformation)
    {
        BaseOperatorInformation->setWindowTitle(QCoreApplication::translate("BaseOperatorInformation", "Form", nullptr));
        btn_choose->setText(QCoreApplication::translate("BaseOperatorInformation", "\347\255\233\351\200\211", nullptr));
        btn_clearChoose->setText(QCoreApplication::translate("BaseOperatorInformation", "\346\270\205\351\231\244\347\255\233\351\200\211\345\222\214\346\220\234\347\264\242", nullptr));
        btn_addData->setText(QCoreApplication::translate("BaseOperatorInformation", "\346\267\273\345\212\240", nullptr));
        tb_search->setText(QCoreApplication::translate("BaseOperatorInformation", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseOperatorInformation: public Ui_BaseOperatorInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEOPERATORINFORMATION_H
