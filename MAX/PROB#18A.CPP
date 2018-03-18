// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#18 phone bill


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>a

apstring Name;
apstring Address;
int Starttime;
int Endtime;
int StarttimeH;
int StarttimeM;
int EndtimeH;
int EndtimeM;
int Calllength;
apstring Trash;
long Price;
long Price1;
long Price2;
long Price1am;
long Price1pm;
long Price2am;
long Price2pm;


void main ()
{
clrscr();

cout<<"What is your name?"<<endl<<endl;
getline (cin,Name);


cout<<"What is your Address?"<<endl<<endl;
getline (cin,Address);


do
{
cout<<"What hour did you start your call in Military time? (hours must be 0-24)" <<endl<<endl;
cin>>StarttimeH;

cout<<"How many minutes past that Hour did you call? (minutes must be 0-59)"<<endl<<endl;
cin>>StarttimeM;

cout<<"What hour did you end your call in Military time? (call can't be 24 hours or longer, and it must be 0-24)"<<endl<<endl;
cin>>EndtimeH;

cout<<"How many minutes past that hour did you end your call? (call can't be 24 hours or longer and minutes must be 0-59)"<<endl<<endl;
cin>>EndtimeM;

StarttimeH=StarttimeH*100;
EndtimeH=EndtimeH*100;
Starttime=StarttimeH+StarttimeM;
Endtime=EndtimeH+EndtimeM;



}while((Endtime=Starttime)||(StarttimeM>59)||(StarttimeM<0)||(EndtimeM<0)||(EndtimeM>59));

if (Endtime>=1800)
if (Starttime<800)

{
Price1=150;

Hours1=8-StarttimeH
Price1am=(Hours1*60)-StarttimeM





cout<<"Please press return to continue.";
getch();
};