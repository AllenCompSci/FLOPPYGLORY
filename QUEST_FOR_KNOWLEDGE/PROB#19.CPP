//Michael Crookston
//Problem #19
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
apvector<int>Number(5);
int I;
char Again;
//Program
void main ()
{
do
{clrscr();
cout<<"Enter 5 Numbers:"<<endl;
for(I=0;I<5;I++)
	cin>>Number[I];
cout<<"Forwards:  ";
for(I=0;I<5;I++)
	cout<<Number[I];
cout<<endl<<"Backwards:  ";
for(I=4;I>-1;I--)
	cout<<Number[I];
cout<<endl;
getch();
cout<<"Do you want to try again(Y/N):  ";
cin>>Again;}
while(Again=='y'||Again=='Y');
}
