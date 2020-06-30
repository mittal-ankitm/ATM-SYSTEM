#include"ATM.h"


ATM::ATM(char *branch,char *loc){
			strcpy(branch_name,branch);
			strcpy(location,loc);
			ofstream file_obj; 
  
   file_obj.open("ATM.dat", ios::app|ios::binary);
    file_obj.write((char*)this, sizeof(*this));
    file_obj.close();
		}
ATM::ATM(){
	;
}
void ATM::setloc(char *a){
	strcpy(location,a);
}
void ATM::setbranch(char *a){
	strcpy(branch_name,a);
}
void ATM::show(){
			cout<<"\nATM details:\n"
				<<"branch name : "<<branch_name<<endl
				<<"location : "<<location<<"\n\n";
		}


