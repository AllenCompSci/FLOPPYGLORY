//Chris Chapman
//prob#39
//7th Period
//Mr. Baker

//Library Section
#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>

//Constant Section

//Structure Section


//Prototype Section
void planet_data (ofstream&);
void choice (int&);
void screen (apstring);

//Global Variable Section
char Answer;
int N;
ofstream out_file;
apstring PLanet;



void main ()
{
do{
clrscr();



planet_data (out_file);

choice(N);

clrscr();

screen (PLanet);

cout<<"Run again? (Y/N)"<<endl;
cin>>Answer;
}while (Answer=='Y'||Answer=='y');
}

void planet_data (ofstream& out_file)
{
	out_file.open("a:\\Planets.Dat");

	out_file<<"Mercury"<<endl;
	out_file<<"57900000 km"<<endl;
	out_file<<"4880 km"<<endl;
	out_file<<"88 days"<<endl;
	out_file<<"59 days"<<endl;
	out_file<<"0"<<endl;
	out_file<<"0"<<endl;

	out_file<<"Venus"<<endl;
	out_file<<"108200000 km"<<endl;
	out_file<<"12100 km"<<endl;
	out_file<<"224.7 days"<<endl;
	out_file<<"243 days (retrograde)"<<endl;
	out_file<<"0"<<endl;
	out_file<<"0"<<endl;

	out_file<<"Earth"<<endl;
	out_file<<"149600000 km"<<endl;
	out_file<<"12756 km"<<endl;
	out_file<<"365.2 days"<<endl;
	out_file<<"23 hr 56 min 4 sec"<<endl;
	out_file<<"1"<<endl;
	out_file<<"0"<<endl;

	out_file<<"Mars"<<endl;
	out_file<<"227900000 km"<<endl;
	out_file<<"6794 km"<<endl;
	out_file<<"687 days"<<endl;
	out_file<<"24 hr 37 min"<<endl;
	out_file<<"2"<<endl;
	out_file<<"0"<<endl;

	out_file<<"Jupiter"<<endl;
	out_file<<"778300000 km"<<endl;
	out_file<<"142800 km"<<endl;
	out_file<<"11.86 yrs"<<endl;
	out_file<<"9 hr 55 min 30 sec"<<endl;
	out_file<<"16"<<endl;
	out_file<<"1"<<endl;

	out_file<<"Saturn"<<endl;
	out_file<<"1427000000 km"<<endl;
	out_file<<"120660 km"<<endl;
	out_file<<"29.46 yrs"<<endl;
	out_file<<"10 hr 40 min 24 sec"<<endl;
	out_file<<"18"<<endl;
	out_file<<"1000"<<endl;

	out_file<<"Uranus"<<endl;
	out_file<<"2870000000 km"<<endl;
	out_file<<"51810 km"<<endl;
	out_file<<"84 yrs"<<endl;
	out_file<<"16.8 hr (retrograde)"<<endl;
	out_file<<"15"<<endl;
	out_file<<"11"<<endl;

	out_file<<"Neptune"<<endl;
	out_file<<"4497000000 km"<<endl;
	out_file<<"49528 km"<<endl;
	out_file<<"165 yrs"<<endl;
	out_file<<"16 hr 11 min"<<endl;
	out_file<<"8"<<endl;
	out_file<<"4"<<endl;

	out_file<<"Pluto"<<endl;
	out_file<<"5900000000 km"<<endl;
	out_file<<"2290 km"<<endl;
	out_file<<"248 y"<<endl;
	out_file<<"6 days 9 hr 18 min (retrograde)"<<endl;
	out_file<<"1"<<endl;
	out_file<<"?"<<endl;

};

void choice (int& N)
{
 cout<<"1 Mercury"<<endl<<"2 Venus"<<endl<<"3 Earth"<<endl;
 cout<<"4 Mars"<<endl<<"5 Jupiter"<<endl<<"6 Saturn"<<endl;
 cout<<"7 Uranus"<<endl<<"8 Neptune"<<endl<<"9 Pluto"<<endl;

 do{
	 cout<<"Pick One: ";
	 cin>>N;
	 }while (N<1||N>9);

};

void screen (apstring PLanet)
{
	 struct Planets
		{
			apstring Revolution,Rotation,Distance,Diameter,Satellite,Ring,Name;
		};

	 ifstream in_file;
	 Planets Planet;

	 in_file.open("a:\\Planets.Dat");
	 in_file>>Planet.Name;
	 getline(in_file,Planet.Name);
	 getline(in_file,Planet.Distance);
	 getline(in_file,Planet.Diameter);
	 getline(in_file,Planet.Revolution);
	 getline(in_file,Planet.Rotation);
	 getline(in_file,Planet.Satellite);
	 getline(in_file,Planet.Ring);

	 in_file.close();

	 cout<<Planet.Name<<endl<<endl;
	 cout<<"Distance from Sun: "<<Planet.Distance<<endl;
	 cout<<"Diameter: "<<Planet.Diameter<<endl;
	 cout<<"Revolution: "<<Planet.Revolution<<endl;
	 cout<<"Rotation: "<<Planet.Rotation<<endl;
	 cout<<"Satellites: "<<Planet.Satellite<<endl;
	 cout<<"Rings: "<<Planet.Ring<<endl;

};