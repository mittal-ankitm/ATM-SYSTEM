#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    Ui::login *ui;
    void clear();
private slots:
    void on_pwd_returnPressed();
    void on_logbutton_clicked();
    void on_pushButton_clicked();
};

#endif // LOGIN_H
