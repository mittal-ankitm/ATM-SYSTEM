#include"Transaction.h"
#include"bank_customer.h"
#include"current_account.h"
#include"savings_account.h"

Transaction::Transaction(){
	;
}
double Transaction::getamount(){
	return amount;
}
ATM Transaction::getatminfo(){
	return atm_info;
}
string Transaction::getdate(){
	return date;
}
Transaction::Transaction(string d,double amt,ATM atminfo,long cno){
	date=d;amount=amt;atm_info=atminfo;card_no=cno;
}
double Transaction::calculate_balance(){
	
}

double Transaction::get_account_balance(){
	long acno;double bal;
			fstream file;
			file.open("bankcustomer.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.clear();
			file.seekg(0);
			extern bank_customer a;
			file.read((char*)&a,sizeof(a));
			while(!file.eof()){
				if(card_no==a.getcard().get_cardno()){
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
						bal=c.get_balance();
						break;
				}
				file.read((char*)&c,sizeof(c));
		}
		
	}
	else{
		file.open("saccount.dat",ios::in|ios::out|ios::ate|ios::binary);
		file.clear();
			file.seekg(0);
			extern savings_account b;
			file.read((char*)&b,sizeof(b));
			while(!file.eof()){
				if(acno==b.return_account_no()){
						bal=b.get_balance();
					break;
				}
				file.read((char*)&b,sizeof(b));
		}
	}
	return bal;
}
long Transaction::get_cardno(){
	return card_no;
}
