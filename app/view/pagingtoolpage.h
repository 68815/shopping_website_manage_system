#ifndef PAGINGTOOLPAGE_H
#define PAGINGTOOLPAGE_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class PagingToolPage;
}

class PagingToolPage : public QWidget
{
    Q_OBJECT

public:
    explicit PagingToolPage(QWidget *parent = nullptr);
    ~PagingToolPage();
    QLabel* getLab_totalDataCounts();
    void CreateConnections();
    void init();
public slots:
    void updateLab_totalDataCounts(int index);//index 指示了对应的表
    void updateLab_currentPageNumber(int type);
private:
    Ui::PagingToolPage *ui;
    int currentPageNumber;
};

#endif // PAGINGTOOLPAGE_H
