#include<cmath>
#include <ctime>
#include<string>
#include<iomanip>
#include<iostream>
#include <sstream>
#include<vector>
#include"ATM_card.h"
using namespace std;

#ifndef bankcustomerh
#define bankcustomerh

class bank_customer{
	private:
		char customer_name[20];
		char address[20];
		char email[20];
		long acc_number;
		ATM_card card;
	public:
		char* em(){return email;
		}
		ATM_card& getcard();
		bank_customer();
		long get_accno();
		long get_cardno();
        char * getname();
		bank_customer(char*,char*,char*,long,int);
		void insert_card();
		void select_transaction();
		void enter_PIN(int);
        void validate_PIN(int);
        void withdraw_cash(int);
        void accept_amount(int);
        string transaction_summary();
		void manager();
		void get_customer_details();
};
#endif
