//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Variables
int Number;
int Remainder;
//Program
void main ()
{
clrscr();
cout<<"This program will display an integer of your choice if it is even.";
cout<<endl<<endl;
cout<<"Please input your number, and press enter.  ";
cin>>Number;
Remainder=Number%2;
clrscr();
if(Remainder==0)
	{cout<<Number<<endl<<endl;
	cout<<"Congratulations.  You entered an even number."<<endl<<endl;
	cout<<"Press return to exit the program.";
	getch();}
else
	{cout<<"You did not enter an even number."<<endl<<endl;
	 cout<<"Press return to exit the program.";
	 getch();}
}
