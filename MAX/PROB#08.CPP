// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#08 find temp and recommend what to do


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>


int x;



void main ()  {
clrscr();

cout<<"What is the temperature outside?"<<endl<<endl;
cin>>x;


if (x>85)
	 cout<<"Go swim"<<endl<<endl;

else if (x>70)
	 cout<<"Go play tennis"<<endl<<endl;

else if (x>32)
	 cout<<"Go play golf"<<endl<<endl;

else if (x>10)
	 cout<<"Go skiing"<<endl<<endl;

else if (x<10)
	 cout<<"Go play checkers"<<endl<<endl;





cout<<"Please press return to continue.";
getch();
};