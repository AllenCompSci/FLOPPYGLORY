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
#include<stdlib.h>
#include<apvector.h>
//Constants
//Variables
char Again;
apvector<int>Numbers(15);
int I;
//Program
void main ()
{
do
	{randomize();
	clrscr();
	for(I=0;I<=14;I++)
		{Numbers[I]=random(6)+1;
		cout<<Numbers[I]<<endl;}
getch();
clrscr();
cout<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
