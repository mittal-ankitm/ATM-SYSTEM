#include "login.h"
#include"bank_customer.h"
#include"welcome.h"
#include "ui_login.h"
#include<QIntValidator>
extern bank_customer f;
extern welcome *w;
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pwd->setValidator( new QIntValidator(0,9999, this) );
}

login::~login()
{
    delete ui;
}
void login::clear(){
    ui->pwd->setText("");
}
void login::on_pwd_returnPressed()
{
    int p=ui->pwd->text().toInt();
    f.validate_PIN(p);
}

void login::on_logbutton_clicked()
{
     int p=ui->pwd->text().toInt();
     f.validate_PIN(p);
}

void login::on_pushButton_clicked()
{
    hide();
    w->show();w->clear();
}
