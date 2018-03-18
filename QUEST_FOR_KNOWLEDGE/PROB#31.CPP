//Michael Crookston
//Problem #31
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Prototypes
long hanoi(int,char,char,char,long&);
//Global Variables
char Again;
int Rings;
long Ans;
//Program
void main ()
{do
{clrscr();
Ans=0;
cout<<"The Tower of Hanoi"<<endl<<endl;
cout<<"How many rings do you want to use:  ";
cin>>Rings;
cout<<"Total Moves:  "<<hanoi(Rings,'A','B','C',Ans);
getch();
clrscr();
cout<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
};
long hanoi(int Rings,char A,char B,char C,long & Ans)
{if(Rings<=1)
 {Ans++;
 cout<<"Move top ring from "<<A<<" to "<<C<<"."<<endl;}
 else
	{hanoi(Rings-1,A,C,B,Ans);
	Ans++;
	cout<<"Move top ring from "<<A<<" to "<<C<<"."<<endl;
	if(0==Ans%20)
		getch();
	hanoi(Rings-1,B,A,C,Ans);}
	return Ans;}