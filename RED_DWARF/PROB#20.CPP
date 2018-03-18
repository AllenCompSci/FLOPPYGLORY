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
//CONSTANTS
//MAIN
void main ()
{
O=0;
E=0;
do
{clrscr ();

for(M=0;M<20;M++)
 {Num[M]=M+1;}

for(M=0;M<20;M++)
 {if (Num[M]%2!=0)
	 Num[M]=Odd[O];
	 O++;}
	if (Num[M]%2==0)
	{Num[M]=Even[E];
	 E++;}

cout<<"Odd Numbers";
for(O=0;O<=9;O++)
{cout<<endl;
 cout<<Odd[O];}

gotoxy(20,1);
for(E=0;E<10;E++)
{gotoxy(20,E+2);
 cout<<Even[E];}
getch ();
cout<<endl<<"Do you want to run again? ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

}


