#include "welcome.h"
#include "ui_welcome.h"
#include"checkacc.h"
welcome::welcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    ui->atmnum->setValidator( new QIntValidator(0,99999999, this) );
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_atmnum_returnPressed()
{
    checkacc();
}

void welcome::on_pushButton_clicked()
{
    checkacc();
}
void welcome::clear(){

        ui->atmnum->setText("");
        ui->bar->setText("");

}
void welcome::set(char *a){
    ui->bar->setText(a);
}
