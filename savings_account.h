#include"Account.h"
#ifndef savaccounth
#define savaccounth

class savings_account:public Account{
	private:
        static int const interest_rate=5;
	public:
		savings_account(long,double);
        savings_account();
		void calculate_interest();
		
};
#endif
