#include "pagingtoolpage.h"
#include "ui_pagingtoolpage.h"
#include <QPushButton>
#include "baseoperatorinformation.h"
PagingToolPage::PagingToolPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PagingToolPage)
{
    ui->setupUi(this);
    init();
}

PagingToolPage::~PagingToolPage()
{
    delete ui;
}
void PagingToolPage::init()
{
    QIntValidator *intValidator = new QIntValidator(0,INT_MAX,ui->le_gotoPage);
    ui->le_gotoPage->setValidator(intValidator);
    currentPageNumber = 1;
    CreateConnections();
}
void PagingToolPage::CreateConnections()
{
    connect(ui->btn_previousPage,&QPushButton::clicked,static_cast<BaseOperatorInformation*>(this->parent()),&BaseOperatorInformation::gotoPreviousPage);
    connect(ui->btn_previousPage,&QPushButton::clicked,this,[this](){
        this->updateLab_currentPageNumber(0);
    });
    connect(ui->btn_nextPage,&QPushButton::clicked,static_cast<BaseOperatorInformation*>(this->parent()),&BaseOperatorInformation::gotoNextPage);
    connect(ui->btn_nextPage,&QPushButton::clicked,this,[this](){
        this->updateLab_currentPageNumber(1);
    });
    connect(ui->cbb_pageSize,&QComboBox::currentTextChanged,this,[this](const QString &text){
        QString numberPart = text;
        numberPart.remove(QRegularExpression("[^0-9]"));
        static_cast<BaseOperatorInformation*>(this->parent())->updatePageSize(qint8(numberPart.toInt()));
    });
    connect(ui->le_gotoPage,&QLineEdit::textChanged,this,[this](const QString &text){
        static_cast<BaseOperatorInformation*>(this->parent())->gotoPage(text.toInt());
        this->updateLab_currentPageNumber(2);
    });
}
void PagingToolPage::updateLab_totalDataCounts(int totalDataCount)
{
    int totalPageCount(0);
    std::string tm = "";
    tm = ui->cbb_pageSize->currentText().toStdString();
    totalPageCount = totalDataCount / stoi(tm.substr(0,tm.find_first_not_of("0123456789")));
    if(totalDataCount % 10)totalPageCount++;
    ui->lab_totalDataCounts->setText("共" + QString::number(totalPageCount) + "页/" + QString::number(totalDataCount) + "条");
}
void PagingToolPage::updateLab_currentPageNumber(int type)
{
    if(type == 0)
    {
        currentPageNumber = std::max(1,currentPageNumber - 1);
    }
    else if(type == 1)
    {
        currentPageNumber++;
    }
    else
    {
        if("" != ui->le_gotoPage->text())currentPageNumber = ui->le_gotoPage->text().toInt();
    }
    ui->lab_currentPageNumber->setText(QString::number(currentPageNumber));
}
