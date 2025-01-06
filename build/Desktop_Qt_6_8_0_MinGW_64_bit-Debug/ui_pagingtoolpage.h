/********************************************************************************
** Form generated from reading UI file 'pagingtoolpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGINGTOOLPAGE_H
#define UI_PAGINGTOOLPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PagingToolPage
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lab_totalDataCounts;
    QComboBox *cbb_pageSize;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_previousPage;
    QLabel *lab_currentPageNumber;
    QPushButton *btn_nextPage;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_constText;
    QLineEdit *le_gotoPage;
    QLabel *lab_constText2;

    void setupUi(QWidget *PagingToolPage)
    {
        if (PagingToolPage->objectName().isEmpty())
            PagingToolPage->setObjectName("PagingToolPage");
        PagingToolPage->resize(437, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(PagingToolPage->sizePolicy().hasHeightForWidth());
        PagingToolPage->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(PagingToolPage);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, 10, -1);
        lab_totalDataCounts = new QLabel(PagingToolPage);
        lab_totalDataCounts->setObjectName("lab_totalDataCounts");
        lab_totalDataCounts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lab_totalDataCounts);

        cbb_pageSize = new QComboBox(PagingToolPage);
        cbb_pageSize->addItem(QString());
        cbb_pageSize->addItem(QString());
        cbb_pageSize->addItem(QString());
        cbb_pageSize->setObjectName("cbb_pageSize");
        cbb_pageSize->setStyleSheet(QString::fromUtf8("text-align: center;"));

        horizontalLayout_4->addWidget(cbb_pageSize);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btn_previousPage = new QPushButton(PagingToolPage);
        btn_previousPage->setObjectName("btn_previousPage");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_previousPage->sizePolicy().hasHeightForWidth());
        btn_previousPage->setSizePolicy(sizePolicy1);
        btn_previousPage->setMaximumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(btn_previousPage);

        lab_currentPageNumber = new QLabel(PagingToolPage);
        lab_currentPageNumber->setObjectName("lab_currentPageNumber");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lab_currentPageNumber->sizePolicy().hasHeightForWidth());
        lab_currentPageNumber->setSizePolicy(sizePolicy2);
        lab_currentPageNumber->setMaximumSize(QSize(50, 16777215));
        lab_currentPageNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_currentPageNumber);

        btn_nextPage = new QPushButton(PagingToolPage);
        btn_nextPage->setObjectName("btn_nextPage");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_nextPage->sizePolicy().hasHeightForWidth());
        btn_nextPage->setSizePolicy(sizePolicy3);
        btn_nextPage->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(btn_nextPage);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, -1, -1, -1);
        lab_constText = new QLabel(PagingToolPage);
        lab_constText->setObjectName("lab_constText");
        lab_constText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lab_constText);

        le_gotoPage = new QLineEdit(PagingToolPage);
        le_gotoPage->setObjectName("le_gotoPage");
        le_gotoPage->setMaximumSize(QSize(30, 30));
        le_gotoPage->setInputMethodHints(Qt::ImhNone);
        le_gotoPage->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(le_gotoPage);

        lab_constText2 = new QLabel(PagingToolPage);
        lab_constText2->setObjectName("lab_constText2");

        horizontalLayout_3->addWidget(lab_constText2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 1);

        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(PagingToolPage);

        QMetaObject::connectSlotsByName(PagingToolPage);
    } // setupUi

    void retranslateUi(QWidget *PagingToolPage)
    {
        PagingToolPage->setWindowTitle(QCoreApplication::translate("PagingToolPage", "Form", nullptr));
        lab_totalDataCounts->setText(QCoreApplication::translate("PagingToolPage", "\345\205\26110\351\241\265/50\346\235\241", nullptr));
        cbb_pageSize->setItemText(0, QCoreApplication::translate("PagingToolPage", "10\346\235\241/\351\241\265", nullptr));
        cbb_pageSize->setItemText(1, QCoreApplication::translate("PagingToolPage", "20\346\235\241/\351\241\265", nullptr));
        cbb_pageSize->setItemText(2, QCoreApplication::translate("PagingToolPage", "30\346\235\241/\351\241\265", nullptr));

        btn_previousPage->setText(QCoreApplication::translate("PagingToolPage", "<", nullptr));
#if QT_CONFIG(shortcut)
        btn_previousPage->setShortcut(QCoreApplication::translate("PagingToolPage", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        lab_currentPageNumber->setText(QCoreApplication::translate("PagingToolPage", "1", nullptr));
        btn_nextPage->setText(QCoreApplication::translate("PagingToolPage", ">", nullptr));
#if QT_CONFIG(shortcut)
        btn_nextPage->setShortcut(QCoreApplication::translate("PagingToolPage", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        lab_constText->setText(QCoreApplication::translate("PagingToolPage", "\345\211\215\345\276\200", nullptr));
        lab_constText2->setText(QCoreApplication::translate("PagingToolPage", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PagingToolPage: public Ui_PagingToolPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINGTOOLPAGE_H
