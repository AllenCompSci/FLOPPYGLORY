//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int Age;
//Program
void main ()
{
clrscr();
cout<<"This program will give you the price of your ticket."<<endl<<endl;
cout<<"Please enter your age in whole years:  ";
cin>>Age;
clrscr();
if(Age<=12)
	cout<<"Your ticket will cost:   $4.00.";
else
	cout<<"Your ticket will cost:   $6.50.";
cout<<endl<<endl<<endl<<"Press return to exit the program.";
getch();
}
