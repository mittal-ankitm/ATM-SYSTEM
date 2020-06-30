#ifndef A_H
#define A_H
#include "welcome.h"
#include"login.h"
#include<fstream>
#include"func.h"
#include<cstdlib>
#include"bank_customer.h"
extern  welcome *w;
extern login* l;
void checkacc(){
    long cno;int ff;fstream file;

        extern bank_customer f;
            fflush(stdin);
            ff=0;
            cno=w->ui->atmnum->text().toLong();

            file.open("bankcustomer.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
                file.seekg(0);
                file.read((char*)&f,sizeof(f));

               while(file.tellp()!=-1){

                    if(cno==f.get_cardno()){
                        ff=1;
                        break;
                    }
                    file.read((char*)&f,sizeof(f));
                }

                if(ff==0){
                    w->set("no account found");
                    return;
                }

        file.close();
        w->clear();
        w->hide();
        l->clear();
        l->show();


}
#endif // A_H
