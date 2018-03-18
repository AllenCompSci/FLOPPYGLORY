//KRIS BICKHAM
//PROB#20
//DUE DATE
//PERIOD 6
//MR. BAKER
//LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
//VARIABLES
char Ans;
apvector <int> Even (10);
apvector <int> Odd (10);
apvector <int> Num (20);
int M;
int O;
int E;
int Q;
int Y;
//CONSTANTS
//MAIN
void main ()
{
do
{
O=0;
E=0;
Y=1;
clrscr ();

for(M=0;M<20;M++)
 {Num[M]=M+1;}

cout<<"Odd Numbers"<<endl;
for(M=0;M<20;M++)
 {Q=Num[M]%2;
	if (Q!=0)
	 {Odd[O]=Num[M];
	 cout<<Odd[O]<<endl;
	 O++;}}
gotoxy(20,Y);
cout<<"Even Numbers";
for(M=0;M<20;M++)
 {Q=Num[M]%2;
	 if (Q==0)
	 {Even[E]=Num[M];
		gotoxy(20,Y+1);
		cout<<Even[E];
		E++;
		Y++;}}
cout<<endl<<"Do you want to run again (Y/N)? "<<endl;
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

getch ();


}



