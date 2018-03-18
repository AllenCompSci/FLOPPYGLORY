//Kris BIckham
//Prob33
//Tuesday
//Period 6
//Mr. Baker
//Libary Section
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
//Const Section
//Varible Section
char Ans;
apvector <apstring> Titles (5);
apvector <apstring> Personal (6);
apmatrix <bool> Id (3,1000);
apstring Trash;
int I;

//Protoypes
void p_info ();
void set_items ();
void m_screen ();
void custom (int);
void read_file ();
//Main
void main()
{
do
{
set_items();
clrscr ();
p_info();
clrscr ();
m_screen();






















gotoxy(1,24);
cout<<"Do you wish to do another entry? ";
cin>>Ans;
getline(cin,Trash);
clrscr ();
}while(Ans=='Y'||Ans=='y');
for(I=0;I<6;I++)
Personal[I]="";
};


void p_info ()
{
cout<<setw(49)<<"Customer Information"<<endl;
cout<<setw(49)<<"--------------------"<<endl<<endl;
cout<<"First Name:"<<endl;
cout<<"Last Name:"<<endl;
cout<<"Phone Number: ";
gotoxy(40,4);
cout<<"Address:";
gotoxy(40,5);
cout<<"City, State:";
gotoxy(40,6);
cout<<"Zip:";
gotoxy(13,4);
getline(cin,Personal[0]);
gotoxy(12,5);
getline(cin,Personal[1]);
gotoxy(15,6);
getline(cin,Personal[2]);
gotoxy(49,4);
getline(cin,Personal[3]);
gotoxy(53,5);
getline(cin,Personal[4]);
gotoxy(45,6);
getline(cin,Personal[5]);
};

void set_items ()
{
Titles[0]="Single Game (One Game)";
Titles[1]="Team Rivals (Five Games)";
Titles[2]="First Half of Season (20 Games)";
Titles[3]="Second half of Season (20 Games)";
Titles[4]="Full Season (40 Games)";
};




void m_screen()
{double I;
 int X;
 int Choice;

cout<<setw(49)<<"---Select Package--- "<<endl;
cout<<setw(49)<<"--------------------"<<endl<<endl;
for(I=0;I<5;I++)
 cout<<I+1<<".) "<<Titles[I]<<endl;
gotoxy(1,24);
cout<<"Selection:";
gotoxy(12,24);
cin>>Choice;
custom(Choice);
clrscr ();
};


void custom (int Package)
{
int Row;
double Price;
clrscr ();
cout<<setw(49)<<"----Package Info---- "<<endl;
cout<<setw(49)<<"--------------------"<<endl<<endl;
cout<<"1.) Row 1: 20$ a Game"<<endl;
cout<<"2.) Row 2: 40$ a Game"<<endl;
cout<<"3.) Row 3: 60$ a Game"<<endl;
gotoxy(1,24);
cout<<"Row:";
gotoxy(6,24);
cin>>Row;


switch (Row)
{  case 1:       switch (Package)
					 {case 1: Price=20*1;
										break;
						case 2: Price=20*5;
										break;
						case 3: Price=20*20;
										break;
						case 4: Price=20*20;
										break;
						case 5: Price=20*40;
						};
										break;

	 case 2:       switch (Package)
					 {case 1: Price=40*1;
										break;
						case 2: Price=40*5;
										break;
						case 3: Price=40*20;
										break;
						case 4: Price=40*20;
										break;
						case 5: Price=40*40;
						};


					break;

	case 3:       switch (Package)
					{ case 1: Price=60*1;
										break;
						case 2: Price=60*5;
										break;
						case 3: Price=60*20;
										break;
						case 4: Price=60*20;
										break;
						case 5: Price=60*40;
										 break; };
					};


cout<<"Your price is "<<Price<<", You have seat "<<"A-"<<Price;
getch();

};


void read  ();
{









}:






































