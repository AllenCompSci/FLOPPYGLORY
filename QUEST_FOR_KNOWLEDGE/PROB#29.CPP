//Michael Crookston
//Problem #29
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
long factorial (int);
//Global Variables
char Again;
int Number;
//Program
void main ()
{do
{clrscr();
cout<<"WELCOME TO THE FACTORIAL PROGRAM"<<endl;
do
{cout<<"What factorial would you like to see (0-12):  ";
cin>>Number;}
while(Number<0 || Number>12);
cout<<endl<<"Answer:  "<<factorial (Number);
getch();
clrscr();
cout<<"Would you like to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
long factorial (int Number)
{//Local Variables
long Answer;
Answer=0;
if(Number==1 || Number==0)
	Answer=1;
else
	Answer+=Number*factorial(Number-1);
return Answer;}