#include "selectpage.h"
#include"bank_customer.h"
#include"Transaction.h"
#include"ATM.h"
#include<string>
#include<sstream>
#include "ui_selectpage.h"
#include "welcome.h"
#include"login.h"
#include<QIntValidator>
extern int withdrawlimit;
char st[500];
void stoa(string a){
    int i;
    for(i=0;i<a.length();i++){
        st[i]=a[i];
    }
    st[i]='\0';
}
stringstream strr;

using namespace std;
extern bank_customer f;
extern ATM ATMINFO;
extern login *l;
extern welcome *w;
selectpage::selectpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selectpage)
{
    ui->setupUi(this);
    ui->val->setValidator( new QIntValidator(0,9999, this) );
}
void selectpage::barshow(){
    ui->val->show();
    ui->submit->show();
    ui->cancel->show();
    ui->bar->setText("");
    ui->val->setText("");
}
void selectpage::barhide(){
    ui->val->hide();
    ui->submit->hide();
    ui->cancel->hide();
    ui->bar->setText("");

}
void selectpage::bhide(){
    ui->bb->hide();
    ui->ww->hide();
    ui->tt->hide();
    ui->pp->hide();
    ui->dd->hide();
    ui->ll->hide();
}
void selectpage::bshow(){
    ui->bb->show();
    ui->ww->show();
    ui->tt->show();
    ui->pp->show();
    ui->dd->show();
    ui->ll->show();
    ui->val->setText("");
}
void selectpage::set(char * a){
    ui->bar->setText(a);ui->bar->show();
}
selectpage::~selectpage()
{
    delete ui;
}
void selectpage::setname(){

    ui->name->setText(f.getname());barhide();bshow();
}


void selectpage::on_cancel_clicked()
{
    barhide();
    on_ll_clicked();
}

void selectpage::on_submit_clicked()
{
    if(choice==1){
        barhide();
        int reqam=ui->val->text().toInt();
        f.accept_amount(reqam);
        if(reqam>0){
        Transaction t("",0,ATMINFO,f.getcard().get_cardno());barhide();
        strr.str("");strr<<"deposit successful\n\n";
        strr<<"balance\n"<<t.get_account_balance()<<" INR";
        stoa(strr.str());
        set(st);
        }else{
            set("invalid amount");
        }
        ui->ll->show();

    }
    else if(choice==2){
        barhide();
        int reqam=ui->val->text().toInt();
        f.withdraw_cash(reqam);
        if(reqam<=0){
            set("invalid amount");
        }
        else if(reqam>withdrawlimit){
            set("out of\nwithdraw\nlimit");
        }else if(ui->bar->text()==""){
        Transaction t("",0,ATMINFO,f.getcard().get_cardno());
        strr.str("");strr<<"withdraw successful\n\n";
        strr<<"balance\n"<<t.get_account_balance()<<" INR";
        stoa(strr.str());
        set(st);
        }
        ui->ll->show();
    }
    else if(choice==3){
        barhide();
        Transaction t("",0,ATMINFO,f.getcard().get_cardno());
        strr.str("");
        strr<<"balance\n"<<t.get_account_balance()<<" INR";
        stoa(strr.str());
        set(st);
        ui->ll->show();

    }
    else if(choice==4){
        barhide();ui->val->setEchoMode(QLineEdit::Normal);
        int cpin=ui->val->text().toInt();
        f.getcard().set_PIN(cpin);barhide();
        if(cpin<1000||cpin>9999){
            set("invalid pin");
        }
        else{
        set("PIN changed successfully");
        }
        ui->ll->show();
    }
    else if(choice==5){
       barhide();
        strr.str("");
        strr<< f.transaction_summary();
        stoa(strr.str());
        set(st);
        ui->ll->show();
    }
    else if(choice==6){
        hide();barhide();
        w->show();w->clear();
    }
}
void selectpage::on_dd_clicked()
{
    choice=1;
    barshow();
    bhide();
}

void selectpage::on_ww_clicked()
{
    choice=2;
    barshow();bhide();
}

void selectpage::on_bb_clicked()
{
choice=3;
bhide();
on_submit_clicked();
}

void selectpage::on_pp_clicked()
{
    choice=4;ui->val->setEchoMode(QLineEdit::Password);
    barshow();bhide();
}

void selectpage::on_tt_clicked()
{
    choice=5;
    bhide();
    on_submit_clicked();

}

void selectpage::on_ll_clicked()
{
    choice=6;
    bhide();
    on_submit_clicked();
}

void selectpage::on_val_returnPressed()
{
    on_submit_clicked();
}
