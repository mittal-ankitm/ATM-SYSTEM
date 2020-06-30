#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
#ifndef atmh
#define atmh
class ATM{
	private:
		char branch_name[20];
	public:
		char location[20];
		ATM(char *,char*);
		ATM();
		void setloc(char*);
		void setbranch(char*);
		void show();
};
#endif
