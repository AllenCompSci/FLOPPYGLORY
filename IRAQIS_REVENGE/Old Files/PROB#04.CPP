//Toni Whipple
//prob#04
//7th
//Mr. Baker

//library section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>

//const section
const double Sleep=2.3;
const double Jogging=15.0;
const double Sitting=1.7;

const double M_15=15.00;
const double M_30=30.00;
const double M_60=60.00;

//variable section
void main()
{
cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
clrscr();
cout<<"Activity";
cout<<setw(14);
cout<<"15 minutes";
cout<<setw(13);
cout<<"30 minutes";
cout<<setw(15);
cout<<"60 minutes"<<endl;
cout<<"sleeping";
cout<<setw(9);
cout<<Sleep*M_15;
cout<<setw(13);
cout<<Sleep*M_30;
cout<<setw(16);
cout<<Sleep*M_60<<endl;

cout<<"Jogging";
cout<<setw(10);
cout<<Jogging*M_15;
cout<<setw(14);
cout<<Jogging*M_30;
cout<<setw(15);
cout<<Jogging*M_60<<endl;

cout<<"Sitting";
cout<<setw(10);
cout<<Sitting*M_15;
cout<<setw(13);
cout<<Sitting*M_30;
cout<<setw(16);
cout<<Sitting*M_60<<endl;

getch();
}