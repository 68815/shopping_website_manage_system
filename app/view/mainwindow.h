#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateChooseLabel(QStringList* sqlConditions);

public slots:
    void stackWidgetPageChanged(int index);
private:
    Ui::MainWindow *ui;
    void loadStyleSheet(const QString &sheetName);
    void initUI();
    void init();
    void createActionsInMenubar();
    void createActionsInToolbar();
    void createChildrens();
    void createConections();
    void createAnimations();

};

#endif // MAINWINDOW_H
