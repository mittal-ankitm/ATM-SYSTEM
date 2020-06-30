#include"savings_account.h"
savings_account::savings_account(){
;
}
savings_account::savings_account(long acn,double b):Account(acn,b){
	ofstream file_obj; 
  
   file_obj.open("saccount.dat", ios::app|ios::binary);
    file_obj.write((char*)this, sizeof(*this));
    file_obj.close();
}

void savings_account::calculate_interest(){
	balance+=(interest_rate/100)*balance;
}
