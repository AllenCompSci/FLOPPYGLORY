// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#07 Movie ticket


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>


int x;



void main ()  {
clrscr();

cout<<"How old are you?"<<endl<<endl;
cin>>x;

if (x>12)
	 cout<<"You must pay $6.50 for the ticket"<<endl<<endl<<endl;

else if (x<13)
	 cout<<"You must pay $4.00 for the ticket"<<endl<<endl<<endl;




cout<<"Please press return to continue.";
getch();
};