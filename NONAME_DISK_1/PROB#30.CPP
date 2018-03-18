//Jeff Stein
//6th Period
//Mr. Baker
//Program:
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <iomanip.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>
double Wid;
double Leng;
double Final;
int Quit;
void calculate (double, double, double);
void get_data (double &, double &);

void main()
{
do
{
clrscr();
get_data (Leng, Wid);
calculate (Final, Leng, Wid);
cout<<endl;
cout<<endl;
cout<<"Do you want to run this again? 1 for No, 2 for Yes."<<endl;
cin>>Quit;
}
while(Quit!=1);

};

void get_data (double & Leng, double & Wid)
{
cout<<"Please enter the length and then the width."<<endl;
cin>>Leng;
cin>>Wid;
}

void calculate (double Final, double Leng, double Wid)
{
Final=Leng*Wid;
cout<<"The area is "<<Final<<endl;
}

