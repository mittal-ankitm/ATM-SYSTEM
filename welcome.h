#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include<QIntValidator>
namespace Ui {
class welcome;
}

class welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();

    Ui::welcome *ui;
    void clear();
    void set(char *);
private slots:
    void on_atmnum_returnPressed();

    void on_pushButton_clicked();


};

#endif // WELCOME_H
