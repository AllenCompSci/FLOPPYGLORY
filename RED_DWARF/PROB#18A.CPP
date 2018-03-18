//KRIS BICKHAM
//PROGRAM NAME
//DUE DATE
//PERIOD 6
//MR. BAKER
//LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES
long double Money;
int Quarter;
int Dollar;
int Dime;
int Nickel;
int Penny;
int Five;
char Ans;
//CONSTANTS  -
//MAIN
void main()
{
clrscr ();
do
{
cout<<"Enter a sum of money less than 10 dollars: ";
endl;
cin>>Money;
while (Money+5.00<=10.00)
{Money+=5.00;Five++;}
while (Money+1.00<=10.00)
{Money++;Dollar++;}
while (Money+.25<=10.00)
{Money+=.25;Quarter++;}
while (Money+.10<=10.00)
{Money+=.10;Dime++;}
while (Money+.05<=10.00)
{Money+=.05;Nickel++;}
while (Money<10.00)
{Money+=.01;Penny++;}
if (Five>0)
 {cout<<Five<<" Five";
	cout<<endl;}
if (Dollar>0)
 {cout<<Dollar<<" Dollar";
	if (Dollar>1)
	cout<<"s";
	cout<<endl;}
if (Quarter>0)
 {cout<<Quarter<<" Quarter";
	if (Quarter>1)
	cout<<"s";
	cout<<endl;}
if (Dime>0)
 {cout<<Dime<<" Dime";
	if (Dime>1)
	cout<<"s";
	cout<<endl;}
if (Nickel>0)
 {cout<<Nickel<<" Nickel";
	if (Nickel>1)
	cout<<"s";
	cout<<endl;}
if (Penny>0)
 {cout<<Penny<<" Penn";
	if (Penny==1)
	cout<<"y";
	else if (Penny>1)
	cout<<"ies";}
cout<<endl;
cout<<" Do you want to run again (Y/N)? ";
cin>>Ans;
Money=0;
Penny=0;
Dollar=0;
Five=0;
Quarter=0;
Nickel=0;
Dime=0;
}while(Ans=='y'||Ans=='Y');

getch();


}


