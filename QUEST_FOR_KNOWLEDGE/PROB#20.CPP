//Michael Crookston
//Problem #20
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
//Constants
//Variables
apvector<int>First(20);
apvector<int>Odd(10);
apvector<int>Even(10);
int I, J, K, L, M, N;
char Again;
//Program
void main ()
{do
{clrscr();
K=1;
J=0;
M=0;
N=2;
for(I=0;I<20;I++)
	 {First[I]=K;
	 K++;}
for(I=0;I<20;I++)
	 {L=First[I]%2;
	 if(L==1)
			{Odd[J]=First[I];
			J++;}
	 else
			{Even[M]=First[I];
			M++;}}
cout<<"Odds";
gotoxy(40,1);
cout<<"Evens";
for(I=0;I<10;I++)
	{gotoxy(1,N);
	cout<<Odd[I]<<endl;
	N++;}
N=2;
for(I=0;I<10;I++)
	{gotoxy(40,N);
	cout<<Even[I]<<endl;
	N++;}
getch();
cout<<endl<<endl<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
