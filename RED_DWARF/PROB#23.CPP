//KRIS BICKHAM
//PROB#23
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apmatrix.h>
//VARIABLES------------
int Rand;
int I;
apvector <int> Num (15);
char Ans;
//CONSTANTS------------
//MAIN
void main ()
{randomize();
do
{
clrscr ();
for(I=0;I<15;I++)
 Num[I]=random(6)+1;
for(I=0;I<15;I++)
{cout<<"Random Number "<<I+1<<" :"<<Num[I];
 cout<<endl;}
cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

}

