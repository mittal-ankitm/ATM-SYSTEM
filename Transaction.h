#include"ATM.h"

#ifndef transactionh
#define transactionh
class Transaction{
	protected:
		string date;
		double amount;
		ATM atm_info;
		long card_no;
	public:
		Transaction();
		Transaction(string d,double amt,ATM atminfo,long cno);
		double calculate_balance();
		double get_account_balance();
		long get_cardno();
		double getamount();
		string getdate();
		ATM getatminfo();
		
};
#endif
