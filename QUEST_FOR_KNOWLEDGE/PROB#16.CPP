//Michael Crookston
//Problem #16
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
char More;
double Total;
int Late;
int Type;
double Fine;
char Again;
//Program
void main ()
{
do
{Total=0;
More='y';
clrscr();
while(More=='Y' || More=='y')
{clrscr();
cout<<"Welcome to the Library Fine Calculator."<<endl<<endl;
cout<<"What type of book is it:"<<endl;
cout<<"1.  Paperback"<<endl;
cout<<"2.  Magazine"<<endl;
cout<<"3.  Reference"<<endl;
cout<<"4.  General Book"<<endl;
cin>>Type;
clrscr();
cout<<"How many days late is the book:  ";
cin>>Late;
switch(Type)
{case 1 : Fine=.20*Late;
					break;
 case 2 : Fine=.35*Late;
					break;
 case 3 : Fine=.75*Late;
					break;
 case 4 : Fine=.50*Late;
					break;
 default: clrscr();
					cout<<"You entered an incorrect digit.  Please try again.";
					break;}
Total+=Fine;
cout<<"Is there another book (Y/N):  ";
cin>>More;}
clrscr();
cout<<setprecision(2)<<setiosflags(ios::showpoint);
cout<<"This is the bill total:  $"<<Total;
getch();
clrscr();
cout<<"Do you want to use again (Y/N):  ";
cin>>Again;}
while(Again=='Y' || Again=='y');
}
