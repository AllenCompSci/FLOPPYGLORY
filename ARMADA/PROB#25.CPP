//Rebecca Russell
//6th
//Mr. Baker
//Program: Lottery tickets.
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<stdlib.h>
//Constant
//Variable
int Ticket;
apvector <bool> Numbers(50);
int Num;
int Count;
int N;
void main ()
{clrscr();
randomize();
do
{cout<<"Please enter the number of tickets you want.  Maximum is 5 tickets."<<endl;
cin>>Ticket;
clrscr();}
while((Ticket<1)||(Ticket>5));


cout<<"Tickets:"<<endl;

Count=0;

do
{for (Num=0; Num<50; Num++)
	Numbers[Num]=false;


		for(N=0; N<6; N++)
			{	do
				Num=random(50);
				while (Numbers[Num]==true);
			Numbers[Num]=true;}
		for (Num=0;Num<50; Num++)
			if (Numbers[Num])
				cout<<Num+1<<" ";
		cout<<endl;
		Count++;}
while (Count<Ticket);

getch();
};
