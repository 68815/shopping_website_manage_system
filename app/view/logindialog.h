#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    void init();
    void createConnections();
public slots:
    void onbuttonBoxaccepted();

    void onbuttonBoxrejected();

private:
    Ui::LoginDialog *ui;
    bool poi;
protected:
    void done(int result);
};

#endif // LOGINDIALOG_H
