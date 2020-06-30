#include"ATM_card.h"
#include<fstream>
#include"bank_customer.h"
using namespace std;
ATM_card::ATM_card(long a,long c,int p){
	PIN=p;
	acc_number=a;
	card_no=c;
	
		}
ATM_card::ATM_card(){
	;
}	
long ATM_card::get_cardno(){
	return card_no;
}
long ATM_card::get_accno(){
	return acc_number;
}
void ATM_card::write_PIN(int pp){
    PIN=pp;
}
void ATM_card::set_PIN(int pp){
    if(pp<1000||pp>9999){
     return;
    }
			fstream file;
			file.open("bankcustomer.dat",ios::in|ios::out|ios::ate|ios::binary);
			file.clear();
            file.seekg(0);
			extern bank_customer a;
			file.read((char*)&a,sizeof(bank_customer));

            while(file.tellp()!=-1){
				
				if(acc_number==a.get_accno()){
                    a.getcard().write_PIN(pp);
					
                    file.clear();
                    file.seekp(file.tellp()-sizeof(bank_customer));cout<<file.tellp();
					file.write((char*)&a,sizeof(bank_customer));

					break;
				}
				file.read((char*)&a,sizeof(bank_customer));
			}
			file.close();
		}
		
int ATM_card::get_PIN(){
			return PIN;
		}

