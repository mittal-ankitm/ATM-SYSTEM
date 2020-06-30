#ifndef SELECTPAGE_H
#define SELECTPAGE_H
#include<sstream>
#include <QMainWindow>
using namespace std;
namespace Ui {
class selectpage;
}

class selectpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit selectpage(QWidget *parent = nullptr);
    ~selectpage();
    Ui::selectpage *ui;
    void setname();
    void barshow();
    void barhide();
    void bhide();
    void bshow();
    void set(char *);
    int choice;
private slots:

    void on_cancel_clicked();
    void on_submit_clicked();
    void on_dd_clicked();
    void on_ww_clicked();
    void on_bb_clicked();
    void on_pp_clicked();
    void on_tt_clicked();
    void on_ll_clicked();
    void on_val_returnPressed();
};

#endif // SELECTPAGE_H
