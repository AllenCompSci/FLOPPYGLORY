//KRIS BICKHAM
//PROB#11
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
double Weight;
int Planet;
//Main/Data Entry

void main ()
{
clrscr ();
cout<<"Enter weight: ";
cin>>Weight;
cout<<"Out of these, which do you want to know your weight on?"<<endl;
cout<<"1 = Our Moon"<<endl;
cout<<"2 = Mercury"<<endl;;
cout<<"3 = Venus"<<endl;
cout<<"4 = Mars"<<endl;
cout<<"5 = Jupiter"<<endl;
cout<<"6 = Saturn"<<endl;
cout<<"7 = Uranus"<<endl;
cout<<"8 = Neptune"<<endl;
cout<<"9 = Pluto"<<endl;
cin>>Planet;
clrscr ();
switch (Planet)
{ case 1 : cout<<Weight*.16; break;
	case 2 : cout<<Weight*.37; break;
	case 3 : cout<<Weight*.88; break;
	case 4 : cout<<Weight*.38; break;
	case 5 : cout<<Weight*2.64; break;
	case 6 : cout<<Weight*1.15; break;
	case 7 : cout<<Weight*1.15; break;
	case 8 : cout<<Weight*1.12; break;
	case 9 : cout<<Weight*.04; break;}
cout<<" pounds is your weight";
getch ();

}



