//Michael Crookston
//PROB#14
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
apstring Name;
char Again;
//Program
void main ()
{
do{
	clrscr();
	do
		{cout<<"Please enter a name:  "<<endl;
		cin>>Name;}
	while (Name != "ZZZ");
	cout<<"Do you want to play again (Y/N)?"<<endl;
	cin>>Again;}
while(Again=='Y' || Again=='y');
}
