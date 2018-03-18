//Michael Crookston
//Problem #30
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
long fibonacci (int);
//Global Variables
char Again;
int Number;
//Program
void main ()
{do
{clrscr();
cout<<"Welcome to the Fibonacci Sequence Program"<<endl<<endl;
cout<<"What number of the Fibonacci Sequence do you want:  ";
cin>>Number;
cout<<endl<<endl<<"Answer:  "<<fibonacci (Number);
getch();
clrscr();
cout<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
long fibonacci (int Number)
{//Local Variables
long Answer;
if(Number<=1)
	Answer=0;
else if(Number<=3)
			Answer=1;
		 else
			Answer=fibonacci(Number-1)+fibonacci(Number-2);
return Answer;
};