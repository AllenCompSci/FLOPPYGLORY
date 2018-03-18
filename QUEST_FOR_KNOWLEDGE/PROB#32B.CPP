//Michael Crookston
//Problem #32B
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<fstream.h>
//Constants
//Prototypes
//Global Variables
ifstream Numbers;
int A,B;
//Program
void main ()
{clrscr();
Numbers.open("number.txt");
for(A=0;A<10;A++)
{Numbers>>B;
cout<<"Number "<<A+1<<" = "<<B<<endl;}
getch();
Numbers.close();
}
