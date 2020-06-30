#include"current_account.h"
current_account::current_account(){
	;
}
current_account::current_account(long acn,double b):Account(acn,b){
	fstream file_obj; 
  
   file_obj.open("caccount.dat", ios::app|ios::binary);
    file_obj.write((char*)this, sizeof(*this));
    file_obj.close();
}

void current_account::calculate_interest(){
	balance+=(interest_rate/100)*balance;
}
