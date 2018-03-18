//KRIS BICKHAM
//PROB#05
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
double Pounds;
double Ounces;
double Weight;
//CONSTANTS------------
//MAIN
void main ()
{
Pounds=0;
Ounces=0;

cout<<setprecision(2);
cout<<setiosflags(ios::showpoint);
clrscr();
cout<<"How many pounds (How many FULL pounds)"<<endl;
cin>>Pounds;
cout<<"Now how many Ounces"<<endl;
cin>>Ounces;
clrscr();
Weight=Ounces+(Pounds*16);
cout<<"Your Total Weight in ounces is:"<<endl;
cout<<Weight;
getch();
clrscr();
cout<<setw(12)<<"Destination";
cout<<setw(12)<<"Total Cost"<<endl;
//
cout<<setw(12)<<"In City";
cout<<setw(12)<<Weight*.15<<endl;
//
cout<<setw(12)<<"In State";
cout<<setw(12)<<Weight*.35<<endl;
//
cout<<setw(12)<<"East Coast";
cout<<setw(12)<<Weight*.55<<endl;
//
cout<<setw(12)<<"Mid West";
cout<<setw(12)<<Weight*.42<<endl;
//
cout<<setw(12)<<"South";
cout<<setw(12)<<Weight*.38<<endl;
//
cout<<setw(12)<<"West Coast";
cout<<setw(12)<<Weight*.615<<endl;
//
cout<<setw(12)<<"Overseas";
cout<<setw(12)<<Weight*1.07<<endl;
//
getch();

}

