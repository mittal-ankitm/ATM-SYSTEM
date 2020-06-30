#include"ATM.h"
#include<string.h>
#ifndef trh
#define trh
class tr{
	public:
		char date[50];
		double amount;
		long card_no;
		tr(){
			;
		}
		tr(string d,double a,long cno){
		strcpy(date,d.c_str());
		date[d.length()]='\0';
			amount=a;
			card_no=cno;
		}
};
#endif
