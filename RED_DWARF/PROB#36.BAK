//KRIS BICKHAM
//PROGRAM NAME
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
//STRUCT---------------
struct Info
{ apstring F_Name;
	apstring L_Name;
	apstring Address;
	apstring City;
	apstring State_Zip;
	apstring P_Num;
	int Tickets;
	int Package;
	int Price;
	int Section;
	int Row;
	int Seat;
};

//CONSTANTS------------
//VARIABLES------------
char Ans;
apstring Title;
apmatrix <bool> Section1 (5,25);
apmatrix <bool> Section2 (5,25);
apmatrix <bool> Section3 (5,25);
apmatrix <bool> Section4 (5,25);
apmatrix <bool> Section5 (5,25);
apvector <Info> Data;
int Resize;
apstring Trash;
int Entry;
int Section;
int Seat;
int Row;
//PROTOTYPE------------
void Titles ();
void Infop ();
void Finalize (char&);
void Price (int&, int&, int&);
//MAIN-----------------

void main ()
{
Entry=0;
clrscr();
cout<<"Resize? ";
cin>>Resize;
getline(cin,Trash);
if (Resize==0)
cout<<"ok";
else if (Resize!=0)
 Data.resize(Resize);
clrscr();
Titles();
Infop();


clrscr ();
cout<<"Choose a Package: "<<endl;
cout<<"1.) Single Game           -  1 Game"<<endl;
cout<<"2.) Team Rivals           -  5 Games"<<endl;
cout<<"3.) Full season           -  20 Games"<<endl;
cout<<"4.) First  hal of season  -  10 Games"<<endl;
cout<<"5.) Second half of season -  10 Games"<<endl;
cout<<"6.) Package: ";
cin>>Data[0].Package;

clrscr();

do
{
 cout<<"Choose a Section:"<<endl;
 cout<<"Section 1 - 10$"<<endl;
 cout<<"Section 2 - 20$"<<endl;
 cout<<"Section 3 - 30$"<<endl;
 cout<<"Section 4 - 40$"<<endl;
 cout<<"Section 5 - 50$"<<endl;
 cout<<"Section: ";
 cin>>Section;

 clrscr();

 cout<<"Choose a Row:"<<endl;
 cout<<"(Row 1-25)"<<endl;
 cout<<"Row: ";
 cin>>Row;

 clrscr();

 cout<<"Choose a Seat"<<endl;
 cout<<"(Seat 1-25)"<<endl;
 cout<<"Seat: ";
 cin>>Seat;

}while((Section==Data[0].Section)&&(Row==Data[0].Row)&&(Seat==Data[0].Row));
Data[0].Section=Section;
Data[0].Row=Row;
Data[0].Seat=Seat;

Finalize(Ans);
cout<<Ans;

getch();
};


void Titles ()
{
cout<<"北北北北北北北北"<<endl;
cout<<"北Ticket Sales北鞍"<<endl;
cout<<"北北北北北北北北鞍"<<endl;
cout<<"  鞍鞍鞍鞍鞍鞍鞍鞍"<<endl;
};


void Infop ()
{clrscr ();
 cout<<"Enter First Name: ";
 getline(cin,Data[0].F_Name);
 cout<<endl<<"Enter Last Name: ";
 getline(cin,Data[0].L_Name);
 cout<<endl<<"Enter Address: ";
 getline(cin,Data[0].Address);
 cout<<endl<<"Enter City: ";
 getline(cin,Data[0].City);
 cout<<endl<<"enter State, Zip: ";
 getline(cin,Data[0].State_Zip);
 cout<<endl<< "Enter Phone Number: ";
 getline(cin,Data[0].P_Num);
};

void Finalize (char & Ans)
{
 clrscr ();
 cout<<"Buyer Information:"<<endl;

 cout<<"First Name: ";
 cout<<Data[0].F_Name<<endl;

 cout<<"Last Name: ";
 cout<<Data[0].L_Name<<endl;

 cout<<"Address: ";
 cout<<Data[0].Address<<endl;

 cout<<"City: ";
 cout<<Data[0].City<<endl;

 cout<<"State, Zip: ";
 cout<<Data[0].State_Zip<<endl;

 cout<<"Phone Number: ";
 cout<<Data[0].P_Num<<endl;

 cout<<"******************"<<endl;

 cout<<"Seat: ";
 cout<<Data[0].Seat<<endl;

 cout<<"Row: ";
 cout<<Data[0].Row<<endl;

 cout<<"Section: ";
 cout<<Data[0].Section<<endl;

 cout<<"Package: ";
 cout<<Data[0].Package<<endl;

 cout<<"*******************"<<endl;
 cout<<"Tickets: ";
 cout<<Data[0].Tickets<<endl;
 cout<<"Price: ";
 cout<<Data[0].Price<<endl;
 cout<<"Is this Correct? ";
 cin>>Ans;

};

void Price (int& Package, int& Section, int& Tickets, int& Price)
{


switch (Section)
{ case 1 : ;

	case 2 :

	case 3 :

	case 4 :

	case 5 :


} ;
