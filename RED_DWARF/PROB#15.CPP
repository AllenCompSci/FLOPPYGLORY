//KRIS BICKHAM
//PROB15
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
double Amount;
int Day;
double Total;
//CONSTANTS------------
//MAIN
void main ()
{
clrscr();
Day=1;
Amount=.01;
Total=0;
cout<<"Donations: press return to advance a day ";
cout<<endl;
for (Day=1 ; Day<21 ; Day++)
	{Total=Total+Amount;
	 cout<<"Day "<<Day<<", Donated:"<<" $"<<Amount<<endl;
	 Amount*=2;
	 getch ();}
cout<<endl;
cout<<"Day 20 Total:"<<Total;
getch ();
}

