/********************************************************************************
** Form generated from reading UI file 'filterdockwidget1.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDOCKWIDGET1_H
#define UI_FILTERDOCKWIDGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterDockWidget1
{
public:

    void setupUi(QDockWidget *FilterDockWidget1)
    {
        if (FilterDockWidget1->objectName().isEmpty())
            FilterDockWidget1->setObjectName("FilterDockWidget1");
        FilterDockWidget1->resize(400, 300);
        FilterDockWidget1->setWindowOpacity(100.000000000000000);

        retranslateUi(FilterDockWidget1);

        QMetaObject::connectSlotsByName(FilterDockWidget1);
    } // setupUi

    void retranslateUi(QDockWidget *FilterDockWidget1)
    {
        FilterDockWidget1->setWindowTitle(QCoreApplication::translate("FilterDockWidget1", "DockWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDockWidget1: public Ui_FilterDockWidget1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDOCKWIDGET1_H
