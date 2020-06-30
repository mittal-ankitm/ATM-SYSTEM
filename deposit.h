#include<iostream>
#include"tr.h"
using namespace std;
#include"bank_customer.h"
#include"selectpage.h"
extern selectpage *p;
#ifndef deposith
#define deposith
class deposit:public Transaction{
	public:
		deposit(string d,double amt,ATM atminfo,long cno):Transaction(d,amt,atminfo,cno){
			;
		}
		deposit(){
			;
		}
		
		void credit(){
            if(amount<=0) {return;}
			long acno;
			fstream file;
			file.open("bankcustomer.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.clear();
			file.seekg(0);
			extern bank_customer a;
			file.read((char*)&a,sizeof(a));
			while(!file.eof()){
				
				if(card_no==a.get_cardno()){
					acno=a.get_accno();break;
				}
				file.read((char*)&a,sizeof(a));
			}
			file.close();
			if((int)(acno/pow(10,7))==1){
				
			file.open("caccount.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.clear();
			file.seekg(0);
			extern current_account c;
				file.read((char*)&c,sizeof(c));
			while(!file.eof()){
		
				if(acno==c.return_account_no()){
						c.update_balance(c.get_balance()+amount);
						file.seekp(file.tellp()-sizeof(c));
					file.write((char*)&c,sizeof(c));
					break;
				}
					file.read((char*)&c,sizeof(c));
		}
		file.close();
	}
	else{
		
		file.open("saccount.dat",ios::in|ios::out|ios::ate|ios::binary);
		file.clear();
			file.seekg(0);
			extern savings_account b;
			file.read((char*)&b,sizeof(b));
			while(!file.eof()){
				
				if(acno==b.return_account_no()){
						b.update_balance(b.get_balance()+amount);
						file.seekp(file.tellp()-sizeof(b));
					file.write((char*)&b,sizeof(b));
					break;
				}
				file.read((char*)&b,sizeof(b));
		}
		file.close();
	}
	tr t(getdate(),getamount(),get_cardno());
			fstream file_obj; 
   file_obj.open("trsum.dat", ios::app|ios::binary);
    file_obj.write((char*)&t, sizeof(t));
    file_obj.close();
		}
};
#endif
