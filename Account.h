#include<fstream>
using namespace std;
#ifndef accounth
#define accounth
class Account{
	protected:
		long acc_number;
		double balance;
	public:
		Account();
		Account(long,double);
		virtual void calculate_interest();
		void update_balance(double);
		long return_account_no();
		double get_balance();
			
}; 
#endif
