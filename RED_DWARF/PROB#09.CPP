//KRIS BICKHAM
//PROB#09
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Speed;
int Limit;
int Zone;
int Over;
//CONSTANTS------------
//MAIN
void main ()
{
Speed=0;
Limit=0;
Zone=1;
clrscr ();
cout<<"So, how fast where you going??? ";
cin>>Speed;
clrscr ();
cout<<"What was the speed limit ";
cin>>Limit;
clrscr ();
cout<<"So, were you driving in a school zone?? 1=Y / 2=N ";
cin>>Zone;
Over=Speed-Limit;
clrscr ();
if (Zone==2&&Over<30&&Over>0)        //NO SCHOOL ZONE, NOT 30 OVER
cout<<Over*3+30;
	else if (Zone==1&&Over<30&&Over>0)  //SCHOOL ZONE,NOT OVER 30
	cout<<Over*6+30;
		else if (Zone==2&&Over>=30)  //NO SCHOOL ZONE, OVER 30
		cout<<Over*3+130;
			else if (Zone==1&&Over>=30)  //SCHOOL ZONE, OVER 30
			cout<<Over*6+130;
				else if(Over<0)          //5
				cout<<"You're not breaking the law...";
getch() ;



}


