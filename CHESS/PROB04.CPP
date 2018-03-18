// Sean Murray
// Due Date
// Program
// Mr. Baker - 3rd pd.

// Libraries
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
//Constants
const double SLEEP = 2.3;
const double JOG = 15.0;
const double SIT = 1.7;

//Variables

void main ()
{
clrscr();
cout <<setw(10)<<"Activity"<<setw(10)<<"15 Min"<<setw(10)<<"30 Min";
cout <<setw(10)<<"60 Min"<<endl;

cout <<setw(10)<<"Sleeping"<<setw(10)<<SLEEP * 15<<setw(10)<<SLEEP * 30;
cout <<setw(10)<<SLEEP * 60<<endl;

cout <<setw(10)<<"Jogging"<<setw(10)<<JOG * 15<<setw(10)<<JOG * 30;
cout <<setw(10)<<JOG * 60<<endl;

cout <<setw(10)<<"Sitting"<<setw(10)<<SIT * 15<<setw(10)<<SIT * 30;
cout <<setw(10)<<SIT * 60<<endl;
getch();
}