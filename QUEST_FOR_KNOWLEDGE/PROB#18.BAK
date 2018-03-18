//Michael Crookston
//Prob #18
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Variables
apstring Name, Address, Trash;
char Again;
int StartH, StartM, EndH, EndM, Call1, Call2, StartT, EndT, I;
double Charge;
//Program
void main ()
{
Again='n';
do
{clrscr();
Call1=0;
Call2=0;
Trash="";
Name="";
Address="";
while(Again=='n')
	{cout<<"Welcome to Phone Bill Calculator"<<endl;
	Again=' ';}
getline(cin, Trash);
cout<<"Name:  ";
getline(cin, Name);
cout<<"Address:  ";
getline(cin, Address);
do
{clrscr();
cout<<"Starting Time (Military, 00-23) Hour:  ";
cin>>StartH;}
while(StartH<0 || StartH>23);
do
{clrscr();
cout<<"Starting Time (Military, 00-59) Minutes:  ";
cin>>StartM;}
while(StartM<0 || StartM>59);
StartT=(StartH*60)+StartM;
do
{clrscr();
cout<<"Ending Time (Military, 00-23) Hour:  ";
cin>>EndH;}
while(EndH<0  || EndH>23);
do
{clrscr();
cout<<"Ending Time (Military, 00-59) Minutes:  ";
cin>>EndM;}
while(EndM<0 || EndM>59);
EndT=(EndH*60)+EndM;
clrscr();
for(I=StartT; I!=EndT; I++)
	{if (I==1440)
		 I=0;
	 if (I>=480 && I<=1079)
		Call1++;
	 else
		Call2++;}
clrscr();
cout<<Name<<endl;
cout<<Address<<endl<<endl;
cout<<"Minutes At $.25 Per Minute:  "<<Call1<<endl;
cout<<"Minutes At $.18 Per Minute:  "<<Call2<<endl;
cout<<"Total Length of Call In Minutes:  "<<Call1+Call2<<endl;
cout<<setprecision(2)<<setiosflags(ios::showpoint);
Charge=(Call1*.25)+(Call2*.18);
cout<<"Total Charge:  $"<<Charge;
getch();
clrscr();
cout<<"Do you want to run the program again?";
cin>>Again;}
while(Again=='Y' || Again=='y');
}
