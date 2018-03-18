//KRIS BICKHAM
//PROB#07
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Age;

//CONSTANTS------------
//MAIN
void main ()
{
clrscr ();
Age=0;
cout<<"Enter your age"<<endl;
cin>>Age;
if (Age<12)
 cout<<"You'll have to pay 4.00$";
else
 cout<<"You'll have to payy 6.50$";
getch ();
}


