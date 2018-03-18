//Michael Crookston
//Problem #04
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
const double SLEEP=2.3;
const double JOG=15.0;
const double SIT=1.7;
//Variables
//Program
void main ()
{
clrscr();
cout<<"Welcome to the Calorie Calculator."<<endl;
cout<<"Press return to see the data.";
getch();
clrscr();
cout<<setprecision(2)<<setiosflags(ios::showpoint);
cout<<"NUMBER OF CALORIES BURNED DURING DIFFERENT ACTIVITIES"<<endl<<endl;
cout<<"Activity"<<setw(20)<<"15 MINUTES"<<setw(20)<<"30 MINUTES";
cout<<setw(20)<<"60 MINUTES"<<endl;
cout<<"SLEEPING"<<setw(20)<<SLEEP*15<<setw(20)<<SLEEP*30;
cout<<setw(20)<<SLEEP*60<<endl;
cout<<"JOGGING"<<setw(21)<<JOG*15<<setw(20)<<JOG*30;
cout<<setw(20)<<JOG*60<<endl;
cout<<"SITTING"<<setw(21)<<SIT*15<<setw(20)<<SIT*30;
cout<<setw(20)<<SIT*60<<endl<<endl<<endl;
cout<<"Press return to leave the program.";
getch();

}
