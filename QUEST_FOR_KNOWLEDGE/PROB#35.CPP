//Michael Crookston
//Problem #35
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<fstream.h>
#include<apvector.h>
//Structures
struct Planet_Info
	{apstring Name,Revol,Rotation,Atmosphere,Axis;
	double Distance1,Distance2,Incli_Orbit,Eccen_Orbit,Diameter2;
	int Diameter1,Satellite,Rings;};
//Constants
//Prototypes
void Pick (int);
//Global Variables
apvector <Planet_Info>Planets(9);
int Choice;
char Again;
//Program
void main ()
{do
{clrscr();
Planets[0].Name="Mercury";
Planets[0].Distance1=57.9;
Planets[0].Distance2=36.0;
Planets[0].Revol="88 Days";
Planets[0].Rotation="59 Days";
Planets[0].Axis="Near 0 Degrees";
Planets[0].Incli_Orbit=7;
Planets[0].Eccen_Orbit=.206;
Planets[0].Diameter1=4880;
Planets[0].Diameter2=3032.4;
Planets[0].Atmosphere="Virtually None";
Planets[0].Satellite=0;
Planets[0].Rings=0;
Planets[1].Name="Venus";
Planets[1].Distance1=108.2;
Planets[1].Distance2=67.24;
Planets[1].Revol="224.7 Days";
Planets[1].Rotation="243 Days Retrograde";
Planets[1].Axis="3.0 Degrees";
Planets[1].Incli_Orbit=3.4;
Planets[1].Eccen_Orbit=.007;
Planets[1].Diameter1=4880;
Planets[1].Diameter2=3032.4;
Planets[1].Atmosphere="Carbon Dioxide";
Planets[1].Satellite=0;
Planets[1].Rings=0;
Planets[2].Name="Earth";
Planets[2].Distance1=149.6;
Planets[2].Distance2=92.9;
Planets[2].Revol="365.2 Days";
Planets[2].Rotation="23 hr 56 Min 4 Sec";
Planets[2].Axis="23 Degrees 27 Minutes";
Planets[2].Incli_Orbit=0;
Planets[2].Eccen_Orbit=.017;
Planets[2].Diameter1=12756;
Planets[2].Diameter2=7926.2;
Planets[2].Atmosphere="Nitrogen Oxygen";
Planets[2].Satellite=1;
Planets[2].Rings=0;
Planets[3].Name="Mars";
Planets[3].Distance1=227.9;
Planets[3].Distance2=141.71;
Planets[3].Revol="687 Days";
Planets[3].Rotation="24 Hr 37 Min";
Planets[3].Axis="25 Degrees 12 Minutes";
Planets[3].Incli_Orbit=1.9;
Planets[3].Eccen_Orbit=.093;
Planets[3].Diameter1=6794;
Planets[3].Diameter2=4194;
Planets[3].Atmosphere="Carbon Dioxide";
Planets[3].Satellite=2;
Planets[3].Rings=0;
Planets[4].Name="Jupiter";
Planets[4].Distance1=778.3;
Planets[4].Distance2=483.88;
Planets[4].Revol="11.86 Yrs";
Planets[4].Rotation="9 Hr 55 Min 30 Sec";
Planets[4].Axis="3 Degrees 5 Minutes";
Planets[4].Incli_Orbit=1.3;
Planets[4].Eccen_Orbit=.048;
Planets[4].Diameter1=142800;
Planets[4].Diameter2=88736;
Planets[4].Atmosphere="Hydrogen Helium";
Planets[4].Satellite=16;
Planets[4].Rings=1;
Planets[5].Name="Saturn";
Planets[5].Distance1=1427;
Planets[5].Distance2=887.14;
Planets[5].Revol="29.46 Yrs";
Planets[5].Rotation="10 Hr 40 Min 24 Sec";
Planets[5].Axis="26 Degrees 44 Minutes";
Planets[5].Incli_Orbit=2.5;
Planets[5].Eccen_Orbit=.056;
Planets[5].Diameter1=120660;
Planets[5].Diameter2=74978;
Planets[5].Atmosphere="Hydrogen Helium";
Planets[5].Satellite=18;
Planets[5].Rings=1000;
Planets[6].Name="Uranus";
Planets[6].Distance1=2870;
Planets[6].Distance2=1783.98;
Planets[6].Revol="84 Yrs";
Planets[6].Rotation="16.8 Hr Retrograde";
Planets[6].Axis="97 Degrees 55 Minutes";
Planets[6].Incli_Orbit=0.8;
Planets[6].Eccen_Orbit=.047;
Planets[6].Diameter1=51810;
Planets[6].Diameter2=32193;
Planets[6].Atmosphere="Helium Hydrogen Methane";
Planets[6].Satellite=15;
Planets[6].Rings=11;
Planets[7].Name="Neptune";
Planets[7].Distance1=4497;
Planets[7].Distance2=2796.46;
Planets[7].Revol="165 Yrs";
Planets[7].Rotation="16 Hr 11 Min(?)";
Planets[7].Axis="28 Degrees 48 Minutes";
Planets[7].Incli_Orbit=1.8;
Planets[7].Eccen_Orbit=.009;
Planets[7].Diameter1=49528;
Planets[7].Diameter2=30775;
Planets[7].Atmosphere="Hydrogen Helium Methane";
Planets[7].Satellite=8;
Planets[7].Rings=4;
Planets[8].Name="Pluto";
Planets[8].Distance1=5900;
Planets[8].Distance2=3666;
Planets[8].Revol="248 Yrs";
Planets[8].Rotation="6 Days 9 Hr 18 Mins Retrograde";
Planets[8].Axis="60 Degrees";
Planets[8].Incli_Orbit=17.2;
Planets[8].Eccen_Orbit=.254;
Planets[8].Diameter1=2290;
Planets[8].Diameter2=1423;
Planets[8].Atmosphere="None Detected";
Planets[8].Satellite=1;
Planets[8].Rings=0;
do
{clrscr();
cout<<"PLANET INFO"<<endl<<endl<<"1. Mercury"<<endl<<"2. Venus"<<endl;
cout<<"3. Earth"<<endl<<"4. Mars"<<endl<<"5. Jupiter"<<endl;
cout<<"6. Saturn"<<endl<<"7. Uranus"<<endl<<"8. Neptune"<<endl<<"9. Pluto";
cout<<endl<<endl<<endl<<"Pick a planet:  ";
cin>>Choice;}
while(Choice<1 || Choice>9);
Pick(Choice-1);
getch();
cout<<"Do you want to see more data (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
void Pick (int Choice)
	{clrscr();
	cout<<"Planet Name:                 "<<Planets[Choice].Name<<endl;
	cout<<"Mean Dist from Sun, Miles:   "<<Planets[Choice].Distance1<<endl;
	cout<<"Mean Dist from Sun, km:      "<<Planets[Choice].Distance2<<endl;
	cout<<"Period of Revolution:        "<<Planets[Choice].Revol<<endl;
	cout<<"Rotation Period:             "<<Planets[Choice].Rotation<<endl;
	cout<<"Inclination of Axis:         "<<Planets[Choice].Axis<<endl;
	cout<<"Inclination of Orbit:        "<<Planets[Choice].Incli_Orbit<<" Degrees"<<endl;
	cout<<"Eccentricity of Orbit:       "<<Planets[Choice].Eccen_Orbit<<endl;
	cout<<"Equatorial Diameter, km:     "<<Planets[Choice].Diameter1<<endl;
	cout<<"Equatorial Diameter, miles:  "<<Planets[Choice].Diameter2<<endl;
	cout<<"Atmosphere Components:       "<<Planets[Choice].Atmosphere<<endl;
	cout<<"Satellites:                  "<<Planets[Choice].Satellite<<endl;
	cout<<"Rings:                       "<<Planets[Choice].Rings<<endl;}