#include "filterdockwidget.h"
#include "ui_filterdockwidget.h"
#include "filterdockwidget1.h"
#include <QLabel>
#include<qobject.h>
#include"baseoperatorinformation.h"
#include<QLineEdit>
#include"merchandise.h"
#include"review.h"
#include"usercomment.h"
#include"purchaseorder.h"
#include"supplier.h"
#include <QDateTimeEdit>
#include<QPushButton>
#include<QCalendarWidget>
#include "Qxlsx/header/xlsxdocument.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItem>
#include <QWindow>
#include <QTimer>
#include <QTableView>
#include <QHeaderView>

filterdockwidget::filterdockwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::filterdockwidget)
{
    ui->setupUi(this);
    init();
}

filterdockwidget::~filterdockwidget()
{
    delete ui;
}
void filterdockwidget::init()
{
    qsti["userID"] = qsti["merchandisePrice"] = qsti["supplierID"] = qsti["merchandiseID"] = qsti["commentID"] = qsti["reviewID"] = qsti["reviewUserID"] = qsti["merchandiseCounts"] = qsti["orderState"] = 0;
    createConnections();
}
void filterdockwidget::createConnections()
{
    connect(this,&filterdockwidget::preparedCompleteSIG,static_cast<FilterDockWidget1*>(this->parent()),&FilterDockWidget1::runSelf1);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&filterdockwidget::onbuttonBoxaccepted);
    connect(ui->buttonBox,&QDialogButtonBox::rejected,this,&filterdockwidget::onbuttonBoxrejected);
}
void filterdockwidget::setInfo(QStringList fields,bool type)
{
    this->type = type;
    if(type)
    {
        ui->cbb_a->setVisible(false);
        for(int i = 0;i<fields.size();i++)
        {
            QLabel* la = new QLabel(this);
            la->setText(fields[i]);
            la->setMaximumHeight(50);
            la->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
            la->setStyleSheet("QLabel {background-color:#333333;color:#00e000}");
            ui->gridLayout->addWidget(la,1,i);
            if(la->text().endsWith("DateTime"))
            {
                QDateTimeEdit *editDate = new QDateTimeEdit(QDateTime());
                editDate->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
                editDate->setCalendarPopup(true);
                ui->gridLayout->addWidget(editDate, 2, i);
            }
            else {
                QLineEdit* le = new QLineEdit(this);
                le->setAlignment(Qt::AlignCenter);
                if(qsti.count(fields[i]))
                {
                    QIntValidator *intValidator = new QIntValidator(0,INT_MAX,le);
                    le->setValidator(intValidator);
                }
                if(i == 0)
                {
                    le->setEnabled(false);
                }
                ui->gridLayout->addWidget(le,2,i);
            }
        }
        QPushButton* pb_importFromExcel = new QPushButton();
        pb_importFromExcel->setText("从excel导入...");
        connect(pb_importFromExcel,&QPushButton::clicked,[this,fields](){
            QString fileName = QFileDialog::getOpenFileName(this, tr("Open Excel File"), "", tr("Excel Files (*.xlsx *.xls)"));
            if (fileName.isEmpty()) return;
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setStandardButtons(nullptr);msgBox->setWindowModality(Qt::NonModal);msgBox->setWindowFlags(msgBox->windowFlags()|Qt::FramelessWindowHint);
            QWindow *window = msgBox->windowHandle();
            if(window) window->setOpacity(0.5);
            QXlsx::Document xlsx(fileName);
            QXlsx::Worksheet *sheet = static_cast<QXlsx::Worksheet*>(xlsx.sheet(xlsx.sheetNames().at(0)));
            if (sheet)
            {
                int colCount = sheet->dimension().lastColumn();
                if(colCount == fields.size() - 1)
                {
                    int rowCount = sheet->dimension().lastRow();
                    QDialog* qd = new QDialog(this);
                    QDialogButtonBox *dbb = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,qd);
                    QVBoxLayout *layout = new QVBoxLayout(qd);
                    QTableView* qtv = new QTableView(qd);
                    qtv->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    layout->addWidget(qtv);layout->addWidget(dbb);
                    qd->setLayout(layout);
                    QStandardItemModel* model = new QStandardItemModel();
                    connect(dbb, &QDialogButtonBox::accepted,[this,model](){
                        static_cast<BaseOperatorInformation*>(static_cast<FilterDockWidget1*>(this->parent())->parent())->insertByExcel(model);
                    });
                    qtv->setModel(model);
                    model->setRowCount(rowCount);
                    model->setColumnCount(colCount);
                    for (int row = 1; row <= rowCount; ++row)
                    {
                        for (int col = 1; col <= colCount; ++col)
                        {
                            QXlsx::Cell *cell = sheet->cellAt(row, col).get();
                            model->setHeaderData(col - 1, Qt::Horizontal, fields[col]);
                            if (cell)
                            {
                                QVariant value = cell->value();
                                if (cell->format().isDateTimeFormat())
                                {
                                    value = cell->dateTime();
                                    QStandardItem *item = new QStandardItem();
                                    item->setData(value, Qt::EditRole);
                                    item->setText(value.toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                                    model->setItem(row - 1, col - 1, item);
                                }
                                else{
                                    QStandardItem *item = new QStandardItem();
                                    item->setData(value, Qt::EditRole);
                                    model->setItem(row - 1, col - 1, item);
                                }

                            }
                        }
                    }
                    qd->setWindowTitle("预览");
                    qtv->resizeColumnsToContents();
                    qtv->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
                    qd->show();
                }
                else msgBox->setText("数据不匹配");
            }
            else msgBox->setText("导入失败");
            msgBox->show();
            QTimer::singleShot(3000,[msgBox](){
                msgBox->close();
                delete msgBox;
            });
        });
        ui->gridLayout->addWidget(pb_importFromExcel,5,fields.size()/2);
    }
    else
    {
        for(int i = 0;i<fields.size();i++)
        {
            ui->cbb_a->addItem(fields[i]);
        }
        connect(ui->cbb_a,QOverload<int>::of(&QComboBox::activated),this,&filterdockwidget::addCondition);
    }
    emit this->preparedCompleteSIG();

}
void filterdockwidget::onbuttonBoxaccepted()
{
    if(type)
    {
        QStringList* sqlInsert = new QStringList();
        QStringList* sqlFields = new QStringList();
        int column = ui->gridLayout->columnCount();
        for(int i = 1;i < column; i++)
        {
            QString cup = "";
            if (static_cast<QLabel*>(ui->gridLayout->itemAtPosition(1,i)->widget())->text().endsWith("DateTime"))
            {
                QDateTimeEdit* dateTimeEdit = qobject_cast<QDateTimeEdit*>(ui->gridLayout->itemAtPosition(2,i)->widget());
                cup = dateTimeEdit->dateTime().toString(Qt::ISODate);
            }
            else
            {
                cup = static_cast<QLineEdit*>(ui->gridLayout->itemAtPosition(2,i)->widget())->text();
            }
            if(!cup.isEmpty())
            {
                sqlFields->append(static_cast<QLabel*>(ui->gridLayout->itemAtPosition(1,i)->widget())->text());
                sqlInsert->append(cup);
            }
        }
        (static_cast<BaseOperatorInformation*>(static_cast<FilterDockWidget1*>(this->parent())->parent())->insertRow(sqlInsert,sqlFields));
    }
    else
    {
        QStringList *sqlCondition = new QStringList();
        for(int i = 1;i<ui->gridLayout->rowCount();i++)
        {
            bool poi(true);
            QString single = qobject_cast<QLabel*>(ui->gridLayout->itemAtPosition(i,0)->widget())->text();
            single += ' ';
            single += qobject_cast<QComboBox*>(ui->gridLayout->itemAtPosition(i,1)->widget())->currentText();
            single += ' ';
            if (static_cast<QLabel*>(ui->gridLayout->itemAtPosition(i,0)->widget())->text().endsWith("DateTime"))
            {
                QDateTimeEdit* dateTimeEdit = qobject_cast<QDateTimeEdit*>(ui->gridLayout->itemAtPosition(i,2)->widget());
                if(dateTimeEdit)
                {
                    single += '\'';
                    single += dateTimeEdit->dateTime().toString(Qt::ISODate);
                    single += '\'';
                }
                else poi = false;
            }
            else
            {
                QComboBox* cbbEdit = qobject_cast<QComboBox*>(ui->gridLayout->itemAtPosition(i,2)->widget());
                QString curt = cbbEdit->currentText();
                if(!curt.isEmpty())
                {
                    if(!qsti.count(qobject_cast<QLabel*>(ui->gridLayout->itemAtPosition(i,0)->widget())->text()))
                    {
                        single += '\'';
                        single += curt;
                        single += '\'';
                    }
                    else
                    {
                        single += curt;
                    }
                    single += ' ';
                }
                else poi = false;
            }
            if(i < ui->gridLayout->rowCount() - 1)
            {
                single += qobject_cast<QComboBox*>(ui->gridLayout->itemAtPosition(i,3)->widget())->currentText();
                single += ' ';
            }
            if(poi)sqlCondition->append(single);
        }
        if (!sqlCondition->isEmpty())
        {
            static_cast<BaseOperatorInformation*>(static_cast<FilterDockWidget1*>(this->parent())->parent())->updateConditions(sqlCondition);
        }
    }
}
void filterdockwidget::onbuttonBoxrejected()
{
    static_cast<FilterDockWidget1*>(this->parent())->close();
}
void filterdockwidget::addCondition(int index)
{
    disconnect(ui->cbb_a,QOverload<int>::of(&QComboBox::activated),this,&filterdockwidget::addCondition);
    QLabel *label = new QLabel();
    label->setText(ui->cbb_a->currentText());
    ui->cbb_a->removeItem(index);
    connect(ui->cbb_a,QOverload<int>::of(&QComboBox::activated),this,&filterdockwidget::addCondition);
    QComboBox *comboBox = new QComboBox;
    comboBox->addItem("=");
    comboBox->addItem("<");
    comboBox->addItem(">");
    comboBox->addItem("<=");
    comboBox->addItem(">=");
    comboBox->addItem("!=");
    //comboBox->addItem("in");
    //comboBox->addItem("not in");
    int row = ui->gridLayout->rowCount();
    ui->gridLayout->addWidget(label,row,0);
    ui->gridLayout->addWidget(comboBox, row, 1);
    if(label->text().endsWith("DateTime"))
    {
        QDateTimeEdit *editDate = new QDateTimeEdit();
        editDate->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        editDate->setCalendarPopup(true);
        ui->gridLayout->addWidget(editDate, row, 2);
    }
    else
    {
        QComboBox *editableComboBox = new QComboBox;
        editableComboBox->setEditable(true);
        if(qsti.count(label->text()))
        {
            QIntValidator *intValidator = new QIntValidator(0,INT_MAX,editableComboBox);
            editableComboBox->setValidator(intValidator);
        }
        ui->gridLayout->addWidget(editableComboBox, row, 2);
    }
    if(row > 1)
    {
        QComboBox *andOrComboBox = new QComboBox;
        andOrComboBox->addItem("and");
        andOrComboBox->addItem("or");
        ui->gridLayout->addWidget(andOrComboBox, row - 1, 3);
    }
}
void filterdockwidget::onDateTimeChanged(const QDateTime &dateTime)
{

}
