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
int Calllength;
apstring Trash;
int Hours1;
int Hours2;
int Hours2a;
int Hours2b;
int Hours1a;
int Hours1b;
long Price;
long Price1;
long Price1am;
long Price1pm;
long Price2am;
long Price2pm;
long Price2;

void main ()
{
clrscr();

cout<<"What is your name?"<<endl<<endl;
getline (cin,Name);


cout<<"What is your Address?"<<endl<<endl;
getline (cin,Address);


do
{
cout<<"What is the starting time of your call in Military time?"<<endl<<endl;
cin>>Starttime;

cout<<"What is the ending time of your call in Military time? (call can't be 24 hours or longer)"<<endl<<endl;
cin>>Endtime;
}while(Endtime=Starttime);

if ((Starttime>=800)&&(Starttime<1800))
if ((Endtime>=1800)||(Endtime<800))
{
if (Starttime>=1700)
 Hours1=1;

if (Starttime>=1600)
 Hours1=2;

if (Starttime>=1500)
 Hours1=3;

if (Starttime>=1400)
 Hours1=4;

if (Starttime>=1300)
 Hours1=5;

if (Starttime>=1200)
 Hours1=6;

if (Starttime>=1100)
 Hours1=7;

if (Starttime>=1000)
 Hours1=8;

if (Starttime>=900)
 Hours1=9;

if (Starttime>=800)
 Hours1=10;


Hours1=Hours1*40;

Price1=(1800-Starttime)-Hours1;
Price1=Price1*.25;


if (Endtime<800)
{

if (Endtime<100)
 Hours2=0;

if (Endtime<200)
 Hours2=1;

if (Endtime<300)
 Hours2=2;

if (Endtime<400)
 Hours2=3;

if (Endtime<500)
 Hours2=4;

if (Endtime<600)
 Hours2=5;

if (Endtime<700)
 Hours2=6;

if (Endtime<800)
 Hours2=7;

Hours2=Hours2*40;

Price2=((Endtime-Hours2)*.18)+108;
}

if (Endtime>=1800)
{
if (Endtime<1900)
 Hours2=0;

if (Endtime<2000)
 Hours2=1;

if (Endtime<2100)
 Hours2=2;

if (Endtime<2200)
 Hours2=3;

if (Endtime<2300)
 Hours2=4;

if (Endtime<2400)
 Hours2=5;

if (Endtime=2400)
 Hours2=6;

Hours2=Hours2*40;

Price2=((Endtime-1800)-Hours2)*.18;

}

}


if ((Starttime<800)&&(Endtime>=1800))
	Price1=149.75;
{

if (Endtime>=1800)
{
if (Endtime<1900)
 Hours2b=0;

if (Endtime<2000)
 Hours2b=1;

if (Endtime<2100)
 Hours2b=2;

if (Endtime<2200)
 Hours2b=3;

if (Endtime<2300)
 Hours2b=4;

if (Endtime<2400)
 Hours2b=5;

if (Endtime=2400)
 Hours2b=6;

Hours2b=Hours2b*40;

Price2pm=((Endtime-1800)-Hours2b)*.18;

}
if (Starttime<800)
{

if (Starttime<100)
 Hours2a=0;

if (Starttime<200)
 Hours2a=1;

if (Starttime<300)
 Hours2a=2;

if (Starttime<400)
 Hours2a=3;

if (Starttime<500)
 Hours2a=4;

if (Starttime<600)
 Hours2a=5;

if (Starttime<700)
 Hours2a=6;

if (Starttime<800)
 Hours2a=7;

Hours2a=Hours2a*40;

Price2am=(Endtime-Hours2a)*.18;



}
Price2=Price2am+Price2pm;

Price=Price1+Price2;

}




if ((Starttime>=800)&&(Starttime<1800))
if ((Endtime<Starttime)&&(Endtime>=800))

{
Price2=151.02;

if (Endtime<Starttime)
{

if (Endtime<900)
 Hours1a=0;

if (Endtime<1000)
 Hours1a=1;

if (Endtime<1100)
 Hours1a=2;

if (Endtime<1200)
 Hours1a=3;

if (Endtime<1300)
 Hours1a=4;

if (Endtime<1400)
 Hours1a=5;

if (Endtime<1500)
 Hours1a=6;

if (Endtime<1600)
 Hours1a=7;

if (Endtime<1700)
 Hours1a=8;

if (Endtime<1800)
 Hours1a=9;

if (Endtime=1800)
 Hours1a=10;

Hours1a=Hours1a*40;

Price1am=(Endtime-800)-Hours1a;
Price1am=Price1am*.25;

}
if (Starttime<1800)
{

if (Starttime>=1700)
 Hours1b=1

if (Starttime>=1600)
 Hours1b=2

if (Starttime>=1500)
 Hours1b=3

if (Starttime>=1400)
 Hours1b=4

if (Starttime>=1300)
 Hours1b=5

if (Starttime>=1200)
 Hours1b=6

if (Starttime>=1100)
 Hours1b=7

if (Starttime>=1000)
 Hours1b=8

if (Starttime>=900)
 Hours1b=9

if (Starttime>=800)
 Hours1b=10


}
if (((Starttime>=800)&&(Starttime<1800))&&((Endtime>Starttime)&&(Endtime<1800)))
{
if (Endtime-Starttime<=100)
	Hours2=1;

if (Endtime-Starttime<=200)
  Hours2=2;

if (Endtime-Starttime<=300)
  Hours2=3;

if (Endtime-Starttime<=400)
  Hours2=4;

if (Endtime-Starttime<=500)
  Hours2=5;

if (Endtime-Starttime<=600)
  Hours2=6;

if (Endtime-Starttime<=700)
  Hours2=7;

if (Endtime-Starttime<=800)
  Hours2=8;

if (Endtime-Starttime<=900)
  Hours2=9;

if (Endtime-Starttime<=1000)
  Hours2=10;

Hours1=Hours1*40;

Price1=(Endtime-Starttime)-Hours1;
Price1=Price1*.25;
}

cout<<"Please press return to continue.";
getch();
};