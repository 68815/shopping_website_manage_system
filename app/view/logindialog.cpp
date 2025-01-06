#include "logindialog.h"
#include "ui_logindialog.h"
#include "websitecontroller.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    poi(false)
{
    ui->setupUi(this);
    init();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
void LoginDialog::init()
{
    this->setStyleSheet("QDockWidget{background-color:#333333;color:#00e000}");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setAutoRepeat(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setAutoRepeat(false);
    createConnections();
}
void LoginDialog::createConnections()
{
    disconnect(ui->buttonBox,&QDialogButtonBox::accepted,this,&LoginDialog::accept);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&LoginDialog::onbuttonBoxaccepted);
    connect(ui->buttonBox,&QDialogButtonBox::rejected,this,&LoginDialog::onbuttonBoxrejected);
}
void LoginDialog::onbuttonBoxaccepted()
{
    poi = false;
    QString account = ui->le_account->text();
    QString password = ui->le_password->text();
    if(account.isEmpty() || password.isEmpty()) {QMessageBox::critical(this, "错误", "账号和密码不能为空。");return;}
    if(WebsiteController<User>::get()->getRoot(account,password))
    {
       poi = true;
       done(QDialog::Accepted);
       MainWindow *ww = new MainWindow();
       ww->show();
    }
    else {QMessageBox::critical(this, "错误", "不存在该root用户");return;}
}

void LoginDialog::onbuttonBoxrejected()
{
    poi = true;
    done(QDialog::Rejected);
}
void LoginDialog::done(int result)
{
    if(this->poi)
    {
        QDialog::done(result);
    }
}
