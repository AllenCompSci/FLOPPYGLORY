//Michael Crookston
//Prob#17
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apvector.h>
//Constants
//Variables
int DNumber, I, CSize, J;
char Again;
apvector<int>Class(10);
//Program
void main ()
{
do
{DNumber=10;
do
{clrscr();
cout<<"Please enter your Department ID Number (0-9):  ";
cin>>DNumber;}
while(DNumber>9 || DNumber<0);
clrscr();
for(I=0;I<10;I++)
	{clrscr();
	cout<<"Size of Class "<<DNumber<<"0"<<I<<" (0-40):  ";
	cin>>CSize;
	if(CSize<41 && CSize>-1)
		Class[I]=CSize;
	else
		I--;}
clrscr();
for(I=0;I<10;I++)
	{cout<<"Class "<<DNumber<<"0"<<I<<":  ";
	CSize=Class[I];
	for(J=0;J<CSize;J++)
		cout<<"*";
	cout<<endl;}
getch();
clrscr();
cout<<"Do you want to do it again (Y/N):  ";
cin>>Again;}
while(Again=='Y' || Again=='y');
}
