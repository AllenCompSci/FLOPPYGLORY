//Michael Crookston
//Problem #05
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
const double CITY=.15;
const double STATE=.35;
const double EAST=.55;
const double MID=.42;
const double SOUTH=.38;
const double WEST=.615;
const double SEAS=1.07;
//Variables
double Packlbs;
double Packoz;
double Totalpack;
//Program
void main ()
{
clrscr();
cout<<"This program will tell you how much a package will cost."<<endl;
cout<<"NOTE: Is not accurate for packages over 10 lbs."<<endl<<endl;
cout<<"Please enter the number of whole pounds the package is:  ";
cin>>Packlbs;
cout<<endl;
cout<<"Now enter how many ounces there are:  ";
cin>>Packoz;
Totalpack=(Packlbs*16)+Packoz;
clrscr();
cout<<"Your package will cost this much in the following places:"<<endl;
cout<<endl<<endl;
cout<<setprecision(2)<<setiosflags(ios::showpoint);
cout<<"Place"<<setw(23)<<"Cost"<<endl<<endl;
cout<<"In city"<<setw(18)<<"$"<<CITY*Totalpack<<endl;
cout<<"In state"<<setw(17)<<"$"<<STATE*Totalpack<<endl;
cout<<"East Coast"<<setw(15)<<"$"<<EAST*Totalpack<<endl;
cout<<"Mid West"<<setw(17)<<"$"<<MID*Totalpack<<endl;
cout<<"South"<<setw(20)<<"$"<<SOUTH*Totalpack<<endl;
cout<<"West Coast"<<setw(15)<<"$"<<WEST*Totalpack<<endl;
cout<<"Overseas"<<setw(17)<<"$"<<SEAS*Totalpack<<endl<<endl<<endl;
cout<<"Press return to exit program.";
getch();
}
