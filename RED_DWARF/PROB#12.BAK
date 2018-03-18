//KRIS BICKHAM
//PROB#12
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
double Cost;
apstring First;
apstring Last;
int Sa1;
apstring Sa2;
apstring Sa3;
int Cy;
int Cm;
int Cd;
int Dy;
int Dm;
int Dd;
apstring Toon;
apstring Movie;
apstring Cable;
int Late;
//Dates ,name, and subscriptions
void main ()
{
Late=2;
Cost=7;
clrscr ();
cout<<"Enter your name: ";
cin>>First;
cin>>Last;
cout<<endl;
cout<<"Enter your street address ie: 1001 Trenton Ct: ";
cin>>Sa1;
cin>>Sa2;
cin>>Sa3;
cout<<"Enter the current Date ie: 5 27 1993: ";
cin>>Cm;
cin>>Cd;
cin>>Cy;
cout<<endl;
cout<<"Enter the due Date: ie 6 21 2000: ";
cin>>Dm;
cin>>Dd;
cin>>Dy;
clrscr ();
cout<<"Do you recieve Cable (Yes/No): ";
cin>>Cable;
cout<<endl;
cout<<"Do you recieve the Cartoon Channel (Yes/No): ";
cin>>Toon;
cout<<endl;
cout<<"Do you get the Movie channel (Yes/No): ";
cin>>Movie;
clrscr ();
//date descisions
if (Dy<Cy)
 Late=1;
if (Dm==Cm&&Cd>Dd)
 Late=1;
if (Dm<Cm)
 Late=1;
cout<<"Name: ";
cout<<First;
cout<<" ";
cout<<Last;
cout<<endl;
cout<<"Address: ";
cout<<Sa1;
cout<<" ";
cout<<Sa2;
cout<<" ";
cout<<Sa3;
cout<<"          Due: ";
cout<<Dm;
cout<<"-";
cout<<Dd;
cout<<"-";
cout<<Dy;
cout<<endl;
cout<<endl;
cout<<"Services:";
cout<<endl;
cout<<setw(20)<<"Standard service";
cout<<setw(20)<<"$7.00";
cout<<endl;
if (Cable=="Yes")
 {Cost+=4;
	cout<<setw(17)<<"Cable Service";
	cout<<setw(23)<<"$4.00";
	cout<<endl;}
if (Toon=="Yes")
 {Cost+=2;
	cout<<setw(29)<<"Continual Cartoon Channel";
	cout<<setw(11)<<"$2.00";
	cout<<endl;}
if (Movie=="Yes")
 {Cost+=2;
	cout<<setw(23)<<"Home Cinema Channel";
	cout<<setw(17)<<"$2.00";
	cout<<endl;}
cout<<endl;
cout<<endl;
if (Late==2)
	{cout<<setw(21)<<"Total amount due:";
	 cout<<setw(29)<<"$"<<Cost;
	 cout<<endl;
	 cout<<endl;}
if (Late==1)
	{cout<<setw(20)<<"Past due amount:";
	 cout<<setw(20)<<"$"<<Cost*1.05;}
getch ();
}



