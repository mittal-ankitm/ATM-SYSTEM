#include"Account.h"
#ifndef curraccounth
#define curraccounth
class current_account:public Account{
	private:
        static int const interest_rate=3;
	public:
		current_account(long,double);
		current_account();
		void calculate_interest();
		
};
#endif
