//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
//struct
struct info
{double Sun;
 double Revo;
 double Rotation;
 double Diameter;
 int Satellite;
 int Ring;
};
//const
//var
long Pick, A, B;
char Choice;
apvector<info> Planets(9);
ifstream in;
//proto
void choice(long&);
void main()
{clrscr();
do{choice(Pick);
	 in.open("a:\\PLANETS.dat");
	 for(B=0, A=0; B<9; B++, A++)
	 {in>>Planets[A].Sun;
		in>>Planets[A].Revo;
		in>>Planets[A].Rotation;
		in>>Planets[A].Diameter;
		in>>Planets[A].Satellite;
		in>>Planets[A].Ring;
	 }
	 clrscr();
		cout<<Planets[Pick].Sun<<" Millions of Miles"<<endl;
		cout<<Planets[Pick].Revo<<endl;
		cout<<Planets[Pick].Rotation<<endl;
		cout<<Planets[Pick].Diameter<<" Miles"<<endl;
		cout<<Planets[Pick].Satellite<<" Satellites"<<endl;
		cout<<Planets[Pick].Ring<<" Rings"<<endl;
	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
void choice(long &Pick)
	 {cout<<"Pick a planet to see info:";
		cout<<endl<<0.<<" Mercury"<<endl<<1.<<" Venus"<<endl<<2.<<" Earth"<<endl;
		cout<<3.<<" Mars"<<endl<<4.<<" Jupiter"<<endl<<5.<<" Saturn"<<endl;
		cout<<6.<<" Uranus"<<endl<<7.<<" Neptune"<<endl<<8.<<" Pluto"<<endl;
		cin>>Pick;
	 }