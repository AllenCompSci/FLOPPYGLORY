//Michael Crookston
//Prob#17
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int DNumber, C1, C2, C3, C4, C5, C6, C7, C8, C9, C0, CSize, CNumber, Star;
char Again;
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
for(CNumber=0; CNumber<10; CNumber++)
	{clrscr();
	cout<<"Size for Class "<<DNumber<<"0"<<CNumber<<":  ";
	cin>>CSize;
	if(CSize<41 && CSize>-1)
		{switch(CNumber)
			{case 1 : C1=CSize;
								break;
			 case 2 : C2=CSize;
								break;
			 case 3 : C3=CSize;
								break;
			 case 4 : C4=CSize;
								break;
			 case 5 : C5=CSize;
								break;
			 case 6 : C6=CSize;
								break;
			 case 7 : C7=CSize;
								break;
			 case 8 : C8=CSize;
								break;
			 case 9 : C9=CSize;
								break;
			 case 0 : C0=CSize;
								break;}}
	else
		CNumber--;}
clrscr();
for(CNumber=0; CNumber<10; CNumber++)
	{cout<<DNumber<<"0"<<CNumber<<"  ";
	switch(CNumber)
	{case 1 : CSize=C1;
						break;
	 case 2 : CSize=C2;
						break;
	 case 3 : CSize=C3;
						break;
	 case 4 : CSize=C4;
						break;
	 case 5 : CSize=C5;
						break;
	 case 6 : CSize=C6;
						break;
	 case 7 : CSize=C7;
						break;
	 case 8 : CSize=C8;
						break;
	 case 9 : CSize=C9;
						break;
	 case 0 : CSize=C0;
						break;}
	for(Star=1; Star<=CSize; Star++)
		{cout<<"*";}
	cout<<"  "<<CSize<<endl;}
cout<<"Do you want to do it again (Y/N):  ";
cin>>Again;}
while(Again=='Y' || Again=='y');
}
