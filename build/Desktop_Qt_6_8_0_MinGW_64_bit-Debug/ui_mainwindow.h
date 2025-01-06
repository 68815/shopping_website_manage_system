/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "baseoperatorinformation.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *user_manage_widget;
    QVBoxLayout *verticalLayout;
    QLabel *le_chooseConditions_1;
    QWidget *marchandise_manage_widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *le_chooseConditions_2;
    QWidget *user_leaveWords_widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *le_chooseConditions_3;
    QWidget *supplier_manage_widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *le_chooseConditions_4;
    QWidget *purchandiseOrder_manage_widget;
    QVBoxLayout *verticalLayout_5;
    QLabel *le_chooseConditions_5;
    QWidget *review_manag_widget;
    QVBoxLayout *verticalLayout_6;
    QLabel *le_chooseConditions_6;
    QStackedWidget *stackedWidget;
    BaseOperatorInformation *user_manage_widget_page;
    QHBoxLayout *horizontalLayout_3;
    BaseOperatorInformation *marchandise_manage_widget_page;
    QHBoxLayout *horizontalLayout_4;
    BaseOperatorInformation *user_leaveWord_manage_widget_page;
    QHBoxLayout *horizontalLayout_5;
    BaseOperatorInformation *supplier_manage_widget_page;
    QHBoxLayout *horizontalLayout_6;
    BaseOperatorInformation *purchandiseOrder_manage_widget_page;
    QHBoxLayout *horizontalLayout_7;
    BaseOperatorInformation *review_manag_widget_page;
    QHBoxLayout *horizontalLayout_8;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(815, 510);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        toolBox->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        toolBox->setStyleSheet(QString::fromUtf8("animation: example 3.5s linear infinite;"));
        user_manage_widget = new QWidget();
        user_manage_widget->setObjectName("user_manage_widget");
        user_manage_widget->setGeometry(QRect(0, 0, 132, 273));
        user_manage_widget->setStyleSheet(QString::fromUtf8("anianimation: example 3.5s linear infinite;"));
        verticalLayout = new QVBoxLayout(user_manage_widget);
        verticalLayout->setObjectName("verticalLayout");
        le_chooseConditions_1 = new QLabel(user_manage_widget);
        le_chooseConditions_1->setObjectName("le_chooseConditions_1");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(le_chooseConditions_1->sizePolicy().hasHeightForWidth());
        le_chooseConditions_1->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(le_chooseConditions_1);

        toolBox->addItem(user_manage_widget, QString::fromUtf8("\347\224\250\346\210\267\347\256\241\347\220\206"));
        marchandise_manage_widget = new QWidget();
        marchandise_manage_widget->setObjectName("marchandise_manage_widget");
        marchandise_manage_widget->setGeometry(QRect(0, 0, 132, 273));
        verticalLayout_2 = new QVBoxLayout(marchandise_manage_widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        le_chooseConditions_2 = new QLabel(marchandise_manage_widget);
        le_chooseConditions_2->setObjectName("le_chooseConditions_2");
        sizePolicy2.setHeightForWidth(le_chooseConditions_2->sizePolicy().hasHeightForWidth());
        le_chooseConditions_2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(le_chooseConditions_2);

        toolBox->addItem(marchandise_manage_widget, QString::fromUtf8("\345\225\206\345\223\201\347\256\241\347\220\206"));
        user_leaveWords_widget = new QWidget();
        user_leaveWords_widget->setObjectName("user_leaveWords_widget");
        user_leaveWords_widget->setGeometry(QRect(0, 0, 132, 273));
        verticalLayout_3 = new QVBoxLayout(user_leaveWords_widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        le_chooseConditions_3 = new QLabel(user_leaveWords_widget);
        le_chooseConditions_3->setObjectName("le_chooseConditions_3");
        sizePolicy2.setHeightForWidth(le_chooseConditions_3->sizePolicy().hasHeightForWidth());
        le_chooseConditions_3->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(le_chooseConditions_3);

        toolBox->addItem(user_leaveWords_widget, QString::fromUtf8("\347\224\250\346\210\267\345\217\215\351\246\210"));
        supplier_manage_widget = new QWidget();
        supplier_manage_widget->setObjectName("supplier_manage_widget");
        supplier_manage_widget->setGeometry(QRect(0, 0, 132, 273));
        verticalLayout_4 = new QVBoxLayout(supplier_manage_widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        le_chooseConditions_4 = new QLabel(supplier_manage_widget);
        le_chooseConditions_4->setObjectName("le_chooseConditions_4");
        sizePolicy2.setHeightForWidth(le_chooseConditions_4->sizePolicy().hasHeightForWidth());
        le_chooseConditions_4->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(le_chooseConditions_4);

        toolBox->addItem(supplier_manage_widget, QString::fromUtf8("\344\276\233\345\272\224\345\225\206\344\277\241\346\201\257"));
        purchandiseOrder_manage_widget = new QWidget();
        purchandiseOrder_manage_widget->setObjectName("purchandiseOrder_manage_widget");
        purchandiseOrder_manage_widget->setGeometry(QRect(0, 0, 132, 273));
        verticalLayout_5 = new QVBoxLayout(purchandiseOrder_manage_widget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        le_chooseConditions_5 = new QLabel(purchandiseOrder_manage_widget);
        le_chooseConditions_5->setObjectName("le_chooseConditions_5");
        sizePolicy2.setHeightForWidth(le_chooseConditions_5->sizePolicy().hasHeightForWidth());
        le_chooseConditions_5->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(le_chooseConditions_5);

        toolBox->addItem(purchandiseOrder_manage_widget, QString::fromUtf8("\350\256\242\345\215\225\344\277\241\346\201\257"));
        review_manag_widget = new QWidget();
        review_manag_widget->setObjectName("review_manag_widget");
        review_manag_widget->setGeometry(QRect(0, 0, 132, 273));
        verticalLayout_6 = new QVBoxLayout(review_manag_widget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        le_chooseConditions_6 = new QLabel(review_manag_widget);
        le_chooseConditions_6->setObjectName("le_chooseConditions_6");
        sizePolicy2.setHeightForWidth(le_chooseConditions_6->sizePolicy().hasHeightForWidth());
        le_chooseConditions_6->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(le_chooseConditions_6);

        toolBox->addItem(review_manag_widget, QString::fromUtf8("\350\257\204\350\256\272"));

        horizontalLayout->addWidget(toolBox);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        user_manage_widget_page = new BaseOperatorInformation();
        user_manage_widget_page->setObjectName("user_manage_widget_page");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(user_manage_widget_page->sizePolicy().hasHeightForWidth());
        user_manage_widget_page->setSizePolicy(sizePolicy4);
        user_manage_widget_page->setLayoutDirection(Qt::LeftToRight);
        user_manage_widget_page->setAutoFillBackground(true);
        horizontalLayout_3 = new QHBoxLayout(user_manage_widget_page);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(user_manage_widget_page);
        marchandise_manage_widget_page = new BaseOperatorInformation();
        marchandise_manage_widget_page->setObjectName("marchandise_manage_widget_page");
        sizePolicy4.setHeightForWidth(marchandise_manage_widget_page->sizePolicy().hasHeightForWidth());
        marchandise_manage_widget_page->setSizePolicy(sizePolicy4);
        horizontalLayout_4 = new QHBoxLayout(marchandise_manage_widget_page);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        stackedWidget->addWidget(marchandise_manage_widget_page);
        user_leaveWord_manage_widget_page = new BaseOperatorInformation();
        user_leaveWord_manage_widget_page->setObjectName("user_leaveWord_manage_widget_page");
        sizePolicy4.setHeightForWidth(user_leaveWord_manage_widget_page->sizePolicy().hasHeightForWidth());
        user_leaveWord_manage_widget_page->setSizePolicy(sizePolicy4);
        horizontalLayout_5 = new QHBoxLayout(user_leaveWord_manage_widget_page);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        stackedWidget->addWidget(user_leaveWord_manage_widget_page);
        supplier_manage_widget_page = new BaseOperatorInformation();
        supplier_manage_widget_page->setObjectName("supplier_manage_widget_page");
        horizontalLayout_6 = new QHBoxLayout(supplier_manage_widget_page);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        stackedWidget->addWidget(supplier_manage_widget_page);
        purchandiseOrder_manage_widget_page = new BaseOperatorInformation();
        purchandiseOrder_manage_widget_page->setObjectName("purchandiseOrder_manage_widget_page");
        horizontalLayout_7 = new QHBoxLayout(purchandiseOrder_manage_widget_page);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        stackedWidget->addWidget(purchandiseOrder_manage_widget_page);
        review_manag_widget_page = new BaseOperatorInformation();
        review_manag_widget_page->setObjectName("review_manag_widget_page");
        horizontalLayout_8 = new QHBoxLayout(review_manag_widget_page);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        stackedWidget->addWidget(review_manag_widget_page);

        horizontalLayout->addWidget(stackedWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 815, 22));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lower Navicat Premium", nullptr));
        le_chooseConditions_1->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211:", nullptr));
        toolBox->setItemText(toolBox->indexOf(user_manage_widget), QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        le_chooseConditions_2->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(marchandise_manage_widget), QCoreApplication::translate("MainWindow", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        le_chooseConditions_3->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(user_leaveWords_widget), QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\217\215\351\246\210", nullptr));
        le_chooseConditions_4->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(supplier_manage_widget), QCoreApplication::translate("MainWindow", "\344\276\233\345\272\224\345\225\206\344\277\241\346\201\257", nullptr));
        le_chooseConditions_5->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(purchandiseOrder_manage_widget), QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257", nullptr));
        le_chooseConditions_6->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", nullptr));
        toolBox->setItemText(toolBox->indexOf(review_manag_widget), QCoreApplication::translate("MainWindow", "\350\257\204\350\256\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
