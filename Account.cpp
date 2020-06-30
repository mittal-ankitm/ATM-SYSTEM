#include"Account.h"
Account::Account(long acn,double b){
			acc_number=acn;
			balance=b;
		}
Account::Account(){
	;
}

void Account::calculate_interest(){
	;
}

void Account::update_balance(double bal){
	balance=bal;
}
long Account::return_account_no(){
	return acc_number;
}
double Account::get_balance(){
	return balance;
}
