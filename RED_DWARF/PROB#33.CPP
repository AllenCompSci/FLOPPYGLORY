//Kris BIckham
//Prob33
//Tuesday
//Period 6
//Mr. Baker
//Libary Section
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
//Const Section
//Varible Section
char Ans;
int Line;
int B;
int I;
ifstream Load;
void display (apstring);
void base ();
//Protoypes

//Main
void main()
{
do
{
clrscr ();
do
{
clrscr ();
cout<<"Basic Planetary data:"<<endl;
cout<<"---------------------"<<endl;
cout<<"1.)           Mercury"<<endl;
cout<<"2.)             Venus"<<endl;
cout<<"3.)             Earth"<<endl;
cout<<"4.)              Mars"<<endl;
cout<<"5.)           Jupiter"<<endl;
cout<<"6.)            Saturn"<<endl;
cout<<"7.)            Uranus"<<endl;
cout<<"8.)           Neptune"<<endl;
cout<<"9.)             Pluto"<<endl<<endl;
cout<<"Chose a planet 1-9, to view it's data: ";
cin>>I;
}while(I>9||I<1);
clrscr ();
base();
switch (I)
{
 case 1: display("Mercury");
				 break;

 case 2: display("Venus");
				 break;

 case 3: display("Earth");
				 break;

 case 4: display("Mars");
				 break;

 case 5: display("Jupiter");
				 break;

 case 6: display("Saturn");
				 break;

 case 7: display("Uranus");
				 break;

 case 8: display("Neptune");
				 break;

 case 9: display("Pluto");
				 break;
};

cout<<endl<<"Do you want to run again? ";
cin>>Ans;
clrscr ();
}while(Ans=='Y'||Ans=='y');
};
void display (apstring Planet)
{
int A;
apstring Current;
Load.open("Planets.txt");
A=1;
do
{
getline(Load,Current);
if (Current==Planet)
 do
	{ gotoxy(1,A);
		cout<<Current<<endl;
		getline(Load,Current);
		getch ();
		A++;
	}while(Current!="End "+Planet);

}while(!Load.eof());
Load.close();
};

void base ()
{
cout<<"                    : Planet Name"<<endl;
cout<<"                    : Millions of kilometers from Sun"<<endl;
cout<<"                    : Millions of Miles from Sun"<<endl;
cout<<"                    : Period of revolution"<<endl;
cout<<"                    : Rotation period"<<endl;
cout<<"                    : Inclination of axis"<<endl;
cout<<"                    : Inclination of orbit to ecliptic"<<endl;
cout<<"                    : Eccentricity of orbit to ecliptic"<<endl;
cout<<"                    : Equatorial diameter in Km's"<<endl;
cout<<"                    : Equatorial diameter in Mi's"<<endl;
cout<<"                    : Atmoshpere (Main components)"<<endl;
cout<<"                    : Satellites"<<endl;
cout<<"                    : Rings"<<endl;
};





