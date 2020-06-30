#include"bank_customer.h"
#include"current_account.h"
#include"savings_account.h"
#include"tr.h"
#include<fstream>
#include<cstring>
#include<ctime>
#include<sstream>
#include"withdraw.h"
#include"deposit.h"
#include"welcome.h"
#include"login.h"
#include"selectpage.h"
extern ATM ATMINFO;
extern login *l;
extern welcome *w;
extern selectpage *p;
using namespace std;
bank_customer::bank_customer(){
	;
}

long bank_customer::get_accno(){
	return acc_number;
}
long bank_customer::get_cardno(){
	return card.get_cardno();
}

char * bank_customer::getname(){
    return customer_name;
}

bank_customer::bank_customer(char *nm,char *add,char *em,long acno,int pin){
	strcpy(customer_name,nm);
	strcpy(address,add);
	strcpy(email,em);
	acc_number=acno;
	long cno=acno;
	card=ATM_card(acno,cno,pin);
	if((int)(acno/pow(10,7))==1){
		current_account(acno,0);
	}
	else{
		savings_account(acno,0);
	}
	fstream file_obj; 
   file_obj.open("bankcustomer.dat", ios::app|ios::binary);
    file_obj.write((char*)this, sizeof(*this));
    file_obj.close();
	
}

void bank_customer::get_customer_details(){
		cout<<"\n\nname : "<<customer_name<<endl
			<<"acc no : "<<acc_number<<endl
			<<"email : "<<email<<"\n\n";
	}
	
void bank_customer::validate_PIN(int p){

	if(p==card.get_PIN()){
		select_transaction();
	}
	else{
        l->hide();
        w->show();w->clear();
        w->set("pin incorrect.");
    }
}


void bank_customer::select_transaction(){
    l->hide();p->show();
    p->setname();

}

void bank_customer::withdraw_cash(int amt){
	time_t _tm =time(NULL );

struct tm * curtime = localtime ( &_tm );
string dt=asctime(curtime);
    
    long cno=card.get_cardno();
    withdraw w(dt,amt,ATMINFO,cno);
    w.debit();

}


void bank_customer::accept_amount(int amt){

		
time_t _tm =time(NULL );

struct tm * curtime = localtime ( &_tm );
string dt=asctime(curtime);
    
    long cno=card.get_cardno();
   
    deposit d(dt,amt,ATMINFO,cno);
    
    d.credit();
}

ATM_card& bank_customer::getcard(){
	return card;
}

string bank_customer::transaction_summary(){
    long cno=get_cardno();stringstream str;
    vector<string> v;
 fstream filee;
 int count=0;
			filee.open("trsum.dat",ios::in|ios::out|ios::ate|ios::binary);
			filee.clear();
			filee.seekg(0);
            extern tr e;
		filee.read((char*)&e,sizeof(e));
            while(filee.tellp()!=-1){
				if(cno==e.card_no){
                    count++;
                    for(int i=0;e.date[i]!='\n';i++) str<<e.date[i];
                     str<<"       ";
                    str<<e.amount<<" INR";
                    str<<"\n";
                    v.push_back(str.str());
                    str.str("");
				}
				filee.read((char*)&e,sizeof(e));
			}
            if(count==0){
                str<<"No transaction found..\n\n";
			}
            else{
                str.str("");count=5;
                for(int i=v.size()-1;i>=0&&count>0;i--,count--){
                    str<<v[i];
                }
            }
			cout<<endl;
            filee.close();
            return str.str();
}
