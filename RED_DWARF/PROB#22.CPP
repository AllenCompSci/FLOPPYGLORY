//KRIS BICKHAM
//PROB#22
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
int Department;
apvector <int> Dc (10);
int Run;
int I;
char Ans;
//CONSTANTS------------
//MAIN
void main ()
{
do
{
for(Run=0;Run<10;Run++)  //clearing cause ya want it...
Dc[Run]=0;
clrscr();
do
{
cout<<"Enter Department ID#: ";
cin>>Department;
}while((Department>9)||(Department<0));
cout<<endl;
for(Run=0;Run<10;Run++)
 {cout<<"Enter # of students (1-40) for class "<<Run+1<<": ";
	cin>>Dc[Run];
	if (Dc[Run]>40||Dc[Run]<1)
	 Run=Run-1;}
clrscr();
cout<<"Department "<<Department<<endl;
for(Run=0;Run<10;Run++)
{cout<<endl;
 cout<<Department<<"0"<<Run<<":  ";
	for(I=0;I<Dc[Run];I++)
	 {cout<<"*";}}
getch ();
cout<<endl;
cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

}

