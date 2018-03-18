//Michael Crookston
//PROB#15
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int Day;
double Amount;
double Total;
char Again;
//Program
void main ()
{
do
{Day=1;
 Amount=.01;
 Total=.00;
	do
		{clrscr();
		cout<<"DAY "<<Day<<":"<<endl<<endl;
		cout<<"Yesterday's Donation:  "<<Amount<<endl;
		if (Day != 1)
			Amount*=2;
		cout<<"Today's Donation:  "<<Amount<<endl;
		Total+=Amount;
		cout<<"Total Amount Donated:  "<<Total<<endl<<endl;
		Day++;
		getch();}
	while (Day<21);
	cout<<"Do you want to play again (Y/N)?";
	cin>>Again;}
while (Again=='Y' || Again=='y');
}
