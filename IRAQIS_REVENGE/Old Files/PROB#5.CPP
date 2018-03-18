//Toni Whipple
//Prob#5
//7th
//Mr. Baker

//Library Section
#include<iostream.h>;
#include<iomanip.h>;
#include<conio.h>;
#include<apstring.h>;

//const.section


const double CITY=.15;
const double STATE=.35;
const double EASTCOAST=.55;
const double MIDWEST=.42;
const double SOUTH=.38;
const double WESTCOAST=.615;
const double OVERSEAS=1.07;
//variable section
int Oz;
int Lbs;
int weight;
void main()
{
clrscr();

cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
cout<<"Type the weight of package in pounds and ounces."<<endl;
cout<<"Press the enter key between the pounds and ounces."<<endl;
cout<<"Example: 2 pounds <enter> 3 ounces <enter>(no more then 10 pounds)"<<endl;
cout<<"Pounds:";
cin>>Lbs;
cout<<setw(10);
cout<<"Ounces:";
cin>>Oz;
weight=(Lbs*16)+Oz;
cout<<"your weight in ounces ..."<<endl<<endl<<weight<<endl<<endl;

cout<<"Cost in City="<<(Lbs*16+Oz)*CITY<<endl;
cout<<"Cost in State="<<(Lbs*16+Oz)*STATE<<endl;
cout<<"Cost in EastCoast="<<(Lbs*16+Oz)*EASTCOAST<<endl;
cout<<"Cost in Midwest="<<(Lbs*16+Oz)*MIDWEST<<endl;
cout<<"Cost in South="<<(Lbs*16+Oz)*SOUTH<<endl;
cout<<"Cost in Westcoast="<<(Lbs*16+Oz)*WESTCOAST<<endl;
cout<<"Cost in Overseas="<<(Lbs*16+Oz)*OVERSEAS<<endl;

getch();
		 }
