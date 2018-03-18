//Rebecca Russell
//6th
//Mr.Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
//Constant
//Structs
struct Planet
{apstring Planet;
 apstring Dist;
 apstring Rev;
 apstring Rot;
 apstring Diam;
 apstring SatNum;
 apstring RingNum;
};
//Variable
int I;
int Ans;
apvector <Planet> Info (9);
//Prototype
void begin ();
void infoall (int);

void main ()
{begin ();
 clrscr();
 getch();
};

void begin()
{do
{
 do
 {clrscr();
	cout<<"Pick a planet by it's number to view info on it: "<<endl<<endl;
	cout<<"Mercury = 0"<<endl;
	cout<<"Venus = 1"<<endl;
	cout<<"Earth = 2"<<endl;
	cout<<"Mars = 3"<<endl;
	cout<<"Jupiter = 4"<<endl;
	cout<<"Saturn = 5"<<endl;
	cout<<"Uranus = 6"<<endl;
	cout<<"Neptune = 7"<<endl;
	cout<<"Pluto = 8"<<endl<<endl;
	cin>>I;
 }
 while((I>8)||(I<0));
 infoall (I);
 getch();
 do
 {cout<<endl<<endl<<"Would you like to run the program again(1=Yes, 2=No)? ";
	cin>>Ans;
 }
 while ((Ans>2)||(Ans<1));
 clrscr();
}
 while(Ans==1);

}

void infoall (int I)
{
Info[0].Planet="Mercury";
Info[0].Dist="36 millions of miles";
Info[0].Rev="88 days";
Info[0].Rot="59 days";
Info[0].Diam="4880 kilometers";
Info[0].SatNum="0";
Info[0].RingNum="0";
Info[1].Planet="Venus";
Info[1].Dist="67.24 millions of miles";
Info[1].Rev="224.7 days";
Info[1].Rot="243 days";
Info[1].Diam="12100 kilometers";
Info[1].SatNum="0";
Info[1].RingNum="0";
Info[2].Planet="Earth";
Info[2].Dist="92.9 millions of miles";
Info[2].Rev="365.2 days";
Info[2].Rot="23 hr 56 mins 4 sec";
Info[2].Diam="12756 kilometers";
Info[2].SatNum="1";
Info[2].RingNum="0";
Info[3].Planet="Mars";
Info[3].Dist="141.71 millions of miles";
Info[3].Rev="687 days";
Info[3].Rot="24 hr 37 mins";
Info[3].Diam="6794 kilometers";
Info[3].SatNum="2";
Info[3].RingNum="0";
Info[4].Planet="Jupiter";
Info[4].Dist="483.88 millions of miles";
Info[4].Rev="11.86 years";
Info[4].Rot="9 hr 55 mins 30 sec";
Info[4].Diam="142800 kilometers";
Info[4].SatNum="16";
Info[4].RingNum="1";
Info[5].Planet="Saturn";
Info[5].Dist="887.14 millions of miles";
Info[5].Rev="29.46 years";
Info[5].Rot="10 hr 40 mins 24 sec";
Info[5].Diam="120660 kilometers";
Info[5].SatNum="18+1";
Info[5].RingNum="1000+?";
Info[6].Planet="Uranus";
Info[6].Dist="1783.98 millions of miles";
Info[6].Rev="84 years";
Info[6].Rot="16.8 hr?";
Info[6].Diam="51810 kilometers";
Info[6].SatNum="15";
Info[6].RingNum="11";
Info[7].Planet="Neptune";
Info[7].Dist="2796.46 millions of miles";
Info[7].Rev="165 hours";
Info[7].Rot="16 hr 11 min?";
Info[7].Diam="49528 kilometers";
Info[7].SatNum="8";
Info[7].RingNum="4";
Info[8].Planet="Pluto";
Info[8].Dist="3666 millions of miles";
Info[8].Rev="248 years";
Info[8].Rot="6 days 9 hr 18 mins";
Info[8].Diam="2290 kilometers";
Info[8].SatNum="1";
Info[8].RingNum="?";
clrscr ();
cout<<"Planet: "<<Info[I].Planet<<endl;
cout<<"Distance from Sun: "<<Info[I].Dist<<endl;
cout<<"Period of Revolution: "<<Info[I].Rev<<endl;
cout<<"Rotation: "<<Info[I].Rot<<endl;
cout<<"Equatorial Diameter: "<<Info[I].Diam<<endl;
cout<<"Satellites: "<<Info[I].SatNum<<endl;
cout<<"Rings: "<<Info[I].RingNum<<endl;
}