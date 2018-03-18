//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
double Sweater;
double Skirt;
double Blouse;
double Bracelet;
double Combined;
//Program
void main ()
{
Sweater=35.00;
Skirt=28.50;
Blouse=22.95;
Bracelet=12.25;
Combined=Sweater+Skirt+Blouse+Bracelet;
clrscr();
cout<<setprecision(2)<<setiosflags(ios::showpoint);
cout<<"Sally wants to buy the following:"<<endl<<endl;
cout<<"Sweater:"<<setw(15)<<"$"<<Sweater<<endl;
cout<<"Skirt:"<<setw(17)<<"$"<<Skirt<<endl;
cout<<"Blouse:"<<setw(16)<<"$"<<Blouse<<endl;
cout<<"Bracelet:"<<setw(14)<<"$"<<Bracelet<<endl<<endl;
cout<<"All her items would cost:";
cout<<setw(5)<<"$"<<Combined<<endl<<endl<<endl;
cout<<"Press return to continue.";
getch();
clrscr();
Sweater=Sweater*.85;
Skirt=Skirt*.85;
Blouse=Blouse*.85;
cout<<"But wait!  Sally now knows about a sale on Tuesday."<<endl;
cout<<"Everything except jewelry will be 15% off."<<endl;
cout<<"That makes the prices:"<<endl<<endl;
cout<<"Sweater:"<<setw(15)<<"$"<<Sweater<<endl;
cout<<"Skirt:"<<setw(17)<<"$"<<Skirt<<endl;
cout<<"Blouse:"<<setw(16)<<"$"<<Blouse<<endl;
cout<<"Bracelet:"<<setw(14)<<"$"<<Bracelet<<endl<<endl<<endl;
cout<<"Now all her items would cost:";
cout<<setw(5)<<"$"<<Sweater+Skirt+Blouse+Bracelet<<endl;
cout<<"Wow!!  That would save her:";
cout<<setw(5)<<"$"<<Combined-(Sweater+Skirt+Blouse+Bracelet)<<endl<<endl;
cout<<"Press return to leave the program, and again rejoin the real world.";
getch();



}
