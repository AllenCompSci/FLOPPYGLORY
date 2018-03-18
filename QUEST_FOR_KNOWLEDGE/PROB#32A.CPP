//Michael Crookston
//Problem #32A
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
ofstream Numbers;
int A,B;
//Program
void main ()
{clrscr();
A=0;
Numbers.open("number.txt");
cout<<"Enter 10 Numbers:  "<<endl;
do{
cout<<"Number "<<A+1<<":  ";
cin>>B;
Numbers<<B<<" ";
A++;}
while(A!=10);
Numbers.close();
}
