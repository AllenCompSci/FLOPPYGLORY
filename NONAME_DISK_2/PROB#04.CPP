//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
const double SLEEP=2.3;
const double JOG=15.0;
const double SIT=1.7;
const int M15=15;
const int M30=30;
const int M60=60;
//var
void main()
{clrscr();
cout<<"Activity"<<setw(14)<<"15minutes"<<setw(14)<<"30minutes";
cout<<setw(14)<<"60minutes"<<endl;
cout<<"Sleeping"<<setw(14)<<SLEEP*M15<<setw(14)<<SLEEP*M30;
cout<<setw(14)<<SLEEP*M60<<endl;
cout<<"Jogging"<<setw(15)<<JOG*M15<<setw(14)<<JOG*M30;
cout<<setw(14)<<JOG*M60<<endl;
cout<<"Sitting"<<setw(15)<<SIT*M15<<setw(14)<<SIT*M30;
cout<<setw(14)<<SIT*M60;

getch();
}
