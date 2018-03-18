//Michael Crookston
//Prob#11
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
//Constants
//Variables
int Weight;
int Planet;
//Program
void main ()
{
clrscr();
cout<<"Please enter your weight:  ";
cin>>Weight;
clrscr();
cout<<"1. Moon"<<endl<<"2. Mercury"<<endl<<"3. Venus"<<endl;
cout<<"4. Mars"<<endl<<"5. Jupiter"<<endl<<"6. Saturn"<<endl;
cout<<"7. Uranus"<<endl<<"8. Neptune"<<endl<<"9. Pluto"<<endl<<endl;
cout<<"Please choose the number of the planet/moon you would like to use:  ";
cin>>Planet;
clrscr();
cout<<"You would weigh:  ";
switch (Planet)
{case 1 : Weight=Weight*.16;
					break;
 case 2 : Weight=Weight*.37;
					break;
 case 3 : Weight=Weight*.88;
					break;
 case 4 : Weight=Weight*.38;
					break;
 case 5 : Weight=Weight*2.64;
					break;
 case 6 : Weight=Weight*1.15;
					break;
 case 7 : Weight=Weight*1.15;
					break;
 case 8 : Weight=Weight*1.12;
					break;
 case 9 : Weight=Weight*.04;
					break;
 default: cout<<"ERROR";}
cout<<Weight<<" lbs.";
cout<<endl<<"Press enter to leave the program.";
getch();
}
