//KRIS BICKHAM
//PROB#10
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------

int Total;
int Screen;
int Hours;
int SS;
apstring Res;
apstring Last;

//Main/Data Entry
void main ()
{
Total=0;
Screen=1;
Res="NO";
Hours=1;
Last="Krisrules";
SS=1;
clrscr ();
cout<<"Enter your Last name ";
cin>>Last;
cout<<"Enter Social Security Number ";
cin>>SS;
cout<<"How many full credit hours do you have ";
cin>>Hours;
cout<<"Are you a resident? Type YES or NO ";
cin>>Res;
if (Res=="NO")                     //Resident= Yes
{if (Hours>=1&&Hours<=4)            //1-4
	Screen=1;
 if (Hours>=5&&Hours<=12)           //5-12
	Screen=2;
 if (Hours>=13)                     //13+
	Screen=3;}
if (Res=="YES")                      //Resident= No
{if (Hours>=1&&Hours<=4)            //1-4
	Screen=4;
 if (Hours>=5&&Hours<=12)           //5-12
	Screen=5;
 if (Hours>=13)                     //13+
	Screen=6;}
switch (Screen)
{ case 1 : Total=Hours*80; break;
	case 2 : Total=Hours*70; break;
	case 3 : Total=900; break;
	case 4 : Total=Hours*120; break;
	case 5 : Total=Hours*110; break;
	case 6 : Total=1400; break;}
clrscr ();
cout<<setw(10)<<"Bill For: ";
cout<<setw(10)<<Last <<endl;
cout<<setw(10)<<"Credit Hours: ";
cout<<setw(10)<<Hours <<endl;
cout<<setw(10)<<"Resident: ";
cout<<setw(10)<<Res <<endl;
cout<<setw(10)<<"Ammount Owed: ";
cout<<Total;
getch ();
}



