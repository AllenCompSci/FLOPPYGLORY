//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
const int MOON=1;
const int MERCURY=2;
const int VENUS=3;
const int MARS=4;
const int JUPITER=5;
const int SATURN=6;
const int URANUS=7;
const int NEPTUNE=8;
const int PLUTO=9;
//var
int Weight;
int Planet;
void main()
{clrscr();
cout<<"Enter Weight=";
cin>>Weight;
cout<<"1=Moon"<<endl;
cout<<"2=Mercury"<<endl;
cout<<"3=Venus"<<endl;
cout<<"4=Mars"<<endl;
cout<<"5=Jupiter"<<endl;
cout<<"6=Saturn"<<endl;
cout<<"7=Uranus"<<endl;
cout<<"8=Neptune"<<endl;
cout<<"9=Pluto"<<endl;
cout<<"Select Planet=";
cin>>Planet;
cout<<"Your Weight=";
switch (Planet)
{
case MOON:cout<<Weight*.16;
break;
case MERCURY:cout<<Weight*.37;
break;
case VENUS:cout<<Weight*.88;
break;
case MARS:cout<<Weight*.38;
break;
case JUPITER:cout<<Weight*2.64;
break;
case SATURN:cout<<Weight*1.15;
break;
case URANUS:cout<<Weight*1.15;
break;
case NEPTUNE:cout<<Weight*1.12;
break;
case PLUTO:cout<<Weight*.04;
};
cout<<endl;
cout<<"Press Return to Continue";
getch();
}
