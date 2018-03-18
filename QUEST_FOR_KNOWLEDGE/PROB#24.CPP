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
#include<apvector.h>
#include<stdlib.h>
//Constants
//Variables
char Again, Repeat;
apvector<int>Ticket(7);
apvector<int>Ticket2(7);
int I, TicketNum, Number, J, K, L;
//Program
void main ()
{
do
{randomize();
clrscr();
gotoxy(35,1);
cout<<"Welcome to the Lotto Ticket Generator"<<endl<<endl;
do
{clrscr();
cout<<"How many tickets do you want (1-5):  ";
cin>>TicketNum;}
while(TicketNum>5 || TicketNum<1);
for(I=0;I<TicketNum;I++)
	{clrscr();
	gotoxy(35,1);
	cout<<"Ticket Number "<<I+1<<endl;
	{for(J=1;J<7;J++)
		{Number=random(50)+1;
		 if(Number<51 && Number>0)
				{for(K=0;K<J;K++)
					{if(Number!=Ticket[K])
							Repeat='n';
					 else
							{Repeat='y';
							K=500;}
				 if(Repeat=='n')
						Ticket[J]=Number;
				 else
						J--;}}
		 else
				J--;}
	for(L=1;L<7;L++)
		cout<<Ticket[L]<<endl;
	getch();}}
cout<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='Y' || Again=='y');
}
