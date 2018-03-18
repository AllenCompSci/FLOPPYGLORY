//KRIS BICKHAM
//PROB#06
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Answer;

//CONSTANTS------------
//MAIN
void main ()
{
Answer=12;
clrscr ();
cout<<"Gimme a number, preferably even."<<endl;
cin>>Answer;
clrscr ();
if (Answer%2==0)
	cout<<Answer;
getch();
}