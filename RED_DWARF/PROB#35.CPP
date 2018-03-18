//KRIS BICKHAM
//PROB#35
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
//STRUCTURES-----------
//VARIABLES------------
//CONSTANTS------------
//PROTOTYPE------------
//MAIN-----------------
struct Planet_Data
{double M_Sun;
 double Eng_Sun;
 apstring Period_Rev;
 apstring Period_Rot;
 apstring Axis_Inclin;
 apstring Orbit_Inclin;
 double Ecc_Orbit;
 long M_Diameter;
 long Eng_Diameter;
 apstring Atmosphere;
 int Satellites;
 int Rings;
};


apvector <Planet_Data> Planets (9);
int Choice;
char Ans;
void display (int);

void main ()
{
Planets[0].M_Sun=57.9;
Planets[0].Eng_Sun=36.0;
Planets[0].Period_Rev="88 days";
Planets[0].Period_Rot="59 days";
Planets[0].Axis_Inclin="Near 0 degrees";
Planets[0].Orbit_Inclin="7 degrees";
Planets[0].Ecc_Orbit=.206;
Planets[0].M_Diameter=4880;
Planets[0].Eng_Diameter=3032.4;
Planets[0].Atmosphere="Virtually none";
Planets[0].Satellites=0;
Planets[0].Rings=0;

Planets[1].M_Sun=108.2;
Planets[1].Eng_Sun=67.24;
Planets[1].Period_Rev="224.7 days";
Planets[1].Period_Rot="243 days retrograde";
Planets[1].Axis_Inclin="3 degrees";
Planets[1].Orbit_Inclin="3.4 degrees";
Planets[1].Ecc_Orbit=.007;
Planets[1].M_Diameter=72100;
Planets[1].Eng_Diameter=7519;
Planets[1].Atmosphere="Carbon dioxide";
Planets[1].Satellites=0;
Planets[1].Rings=0;

Planets[2].M_Sun=149.6;
Planets[2].Eng_Sun=92.9;
Planets[2].Period_Rev="365.2 days";
Planets[2].Period_Rot="23 hr,  56 min, 4 sec";
Planets[2].Axis_Inclin="23 degrees, 27'";
Planets[2].Orbit_Inclin="0 degrees";
Planets[2].Ecc_Orbit=.017;
Planets[2].M_Diameter=12756;
Planets[2].Eng_Diameter=7926.2;
Planets[2].Atmosphere="Nitrogen oxygen";
Planets[2].Satellites=1;
Planets[2].Rings=0;

Planets[3].M_Sun=227.9;
Planets[3].Eng_Sun=141.71;
Planets[3].Period_Rev="687 days";
Planets[3].Period_Rot="24 hr, 37 min";
Planets[3].Axis_Inclin="25 degrees, 12'";
Planets[3].Orbit_Inclin="1.9 degree";
Planets[3].Ecc_Orbit=.093;
Planets[3].M_Diameter=6794;
Planets[3].Eng_Diameter=4194;
Planets[3].Atmosphere="Carbon dioxide";
Planets[3].Satellites=2;
Planets[3].Rings=0;

Planets[4].M_Sun=778.3;
Planets[4].Eng_Sun=463.88;
Planets[4].Period_Rev="11.86 yrs";
Planets[4].Period_Rot="9 hr, 55 min, 30 sec";
Planets[4].Axis_Inclin="3 degrees. 5'";
Planets[4].Orbit_Inclin="1.3 degrees";
Planets[4].Ecc_Orbit=.048;
Planets[4].M_Diameter=142800;
Planets[4].Eng_Diameter=88736;
Planets[4].Atmosphere="Hydrogen helium";
Planets[4].Satellites=16;
Planets[4].Rings=1;

Planets[5].M_Sun=1427;
Planets[5].Eng_Sun=887.14;
Planets[5].Period_Rev="29.46 yrs";
Planets[5].Period_Rot="10 hr, 40 min, 24 sec";
Planets[5].Axis_Inclin="26 degrees, 44'";
Planets[5].Orbit_Inclin="2.5 degrees";
Planets[5].Ecc_Orbit=.056;
Planets[5].M_Diameter=120660;
Planets[5].Eng_Diameter=74978;
Planets[5].Atmosphere="Hydrogen helium";
Planets[5].Satellites=18;
Planets[5].Rings=1000;

Planets[6].M_Sun=2870;
Planets[6].Eng_Sun=1783.98;
Planets[6].Period_Rev="84 yrs";
Planets[6].Period_Rot="16.8 hr retrograde";
Planets[6].Axis_Inclin="97 degrees, 55'";
Planets[6].Orbit_Inclin=".8 degrees";
Planets[6].Ecc_Orbit=.047;
Planets[6].M_Diameter=51810;
Planets[6].Eng_Diameter=32193;
Planets[6].Atmosphere="Hydrogen methane";
Planets[6].Satellites=15;
Planets[6].Rings=11;

Planets[7].M_Sun=4497;
Planets[7].Eng_Sun=2796.46;
Planets[7].Period_Rev="165 years";
Planets[7].Period_Rot="16 hr, 11 min";
Planets[7].Axis_Inclin="28 degree, 48'";
Planets[7].Orbit_Inclin="1.8 degree";
Planets[7].Ecc_Orbit=.009;
Planets[7].M_Diameter=49528;
Planets[7].Eng_Diameter=30775;
Planets[7].Atmosphere="Hydrogen helium methane";
Planets[7].Satellites=8;
Planets[7].Rings=4;

Planets[8].M_Sun=5900;
Planets[8].Eng_Sun=3666;
Planets[8].Period_Rev="248 yrs";
Planets[8].Period_Rot="6 days, 9 hr, 18min retrograde";
Planets[8].Axis_Inclin="60 degrees";
Planets[8].Orbit_Inclin="17.2 degrees";
Planets[8].Ecc_Orbit=.254;
Planets[8].M_Diameter=2290;
Planets[8].Eng_Diameter=1423;
Planets[8].Atmosphere="None detected";
Planets[8].Satellites=15;
Planets[8].Rings=0;
do
{
cout<<"What planet do you want to view 1-9: ";
do
{cin>>Choice;
}while(Choice<1||Choice>9);

clrscr();
display(Choice);
getch();
clrscr();
cout<<"Run again? ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');


};





void display (int Num)
{
cout<<"Metric distance from sun: "<<Planets[Num-1].M_Sun<<endl;
cout<<"Englsih dstance :"<<Planets[Num-1].Eng_Sun<<endl;
cout<<"Period of revolution: "<<Planets[Num-1].Period_Rev<<endl;
cout<<"Period of rotation: "<<Planets[Num-1].Period_Rot<<endl;
cout<<"Inclination of axis: "<<Planets[Num-1].Axis_Inclin<<endl;
cout<<"Inclination of orbit: "<<Planets[Num-1].Orbit_Inclin<<endl;
cout<<"Eccentricity of orbit: "<<Planets[Num-1].Ecc_Orbit<<endl;
cout<<"Metric diameter: "<<Planets[Num-1].M_Diameter<<endl;
cout<<"English diamter: "<<Planets[Num-1].Eng_Diameter<<endl;
cout<<"Atomospheric components: "<<Planets[Num-1].Atmosphere<<endl;
cout<<"Number of satellites: "<<Planets[Num-1].Satellites<<endl;
cout<<"Number of rings: "<<Planets[Num-1].Rings<<endl;
};

