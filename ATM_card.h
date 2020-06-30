#ifndef atmcardh
#define atmcardh
class ATM_card{
	private:
		int PIN;
		long card_no;
		long acc_number;
	public:
		ATM_card(long,long,int);
		ATM_card();
		void set_PIN(int);
		void write_PIN(int);
		int get_PIN();
		long get_cardno();
		long get_accno();
		
	};
#endif
