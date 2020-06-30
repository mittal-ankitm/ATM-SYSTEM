#include"Transaction.h"
#include"tr.h"
#include"selectpage.h"
extern selectpage *p;
extern int withdrawlimit;
#ifndef withdrawh
#define withdrawh
class withdraw:public Transaction{
	public:
		withdraw(string d,double amt,ATM atminfo,long cno):Transaction(d,amt,atminfo,cno){
			;
		}
		
        void debit(){
            if(amount<=0) {return;}
            if(amount>withdrawlimit){
                return;
            }
			long acno;
			fstream file;
			file.open("bankcustomer.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.clear();
			file.seekg(0);
			extern bank_customer a;
			file.read((char*)&a,sizeof(a));
            while(file.tellp()!=-1){
				if(card_no==a.get_cardno()){
					acno=a.get_accno();
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
            while(file.tellp()!=-1){
				if(acno==c.return_account_no()){
					if(c.get_balance()>=amount){
						c.update_balance(c.get_balance()-amount);
						file.seekp(file.tellp()-sizeof(c));
					file.write((char*)&c,sizeof(c));
					break;
					}
                    else{
                        p->set("insufficient\nbalance");return;
					}
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
            while(file.tellp()!=-1){
				if(acno==b.return_account_no()){
					if(b.get_balance()>=amount){
						b.update_balance(b.get_balance()-amount);
						file.seekp(file.tellp()-sizeof(b));
					file.write((char*)&b,sizeof(b));
					break;
					}
                    else{
                        p->set("insufficient\nbalance");return;
					}
				}
				file.read((char*)&b,sizeof(b));
		}
		file.close();
	}
	fstream file_obj; 
  tr t(getdate(),getamount()*(-1.0),get_cardno());
   file_obj.open("trsum.dat", ios::app|ios::binary);
    file_obj.write((char*)&t, sizeof(t));
    file_obj.close();

}
};
#endif
