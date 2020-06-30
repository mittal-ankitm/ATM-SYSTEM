#include "welcome.h"
#include"login.h"
#include"selectpage.h"
#include <QApplication>
#include <iostream>
#include"bank_customer.h"
#include"current_account.h"
#include"tr.h"
#include"savings_account.h"
#include"Transaction.h"
#include"deposit.h"
#include"withdraw.h"
#include<cstdio>
#include<fstream>
#include"ATM.h"
int withdrawlimit=9000;
bank_customer a;
savings_account b;
current_account c;
Transaction d;
tr e;
bank_customer f;
ATM ATMINFO;
welcome *w;
login *l;
selectpage *p;
int main(int argc, char *argv[])
{
     // bank_customer at("anurag tiwari","delhi","at@gmail.com",12341234,1234);
     // bank_customer rm("ravindra meena","baran","rm@gmail.com",21212121,1212);
     // bank_customer om("om ji","delhi","omji@gmail.com",12345678,1111);
      ATMINFO.setloc("Delhi");
      ATMINFO.setbranch("RCX");
    QApplication a(argc, argv);
welcome ss;w=&ss;
login aas;l=&aas;
selectpage tt;p=&tt;
ss.show();
    return a.exec();
}
