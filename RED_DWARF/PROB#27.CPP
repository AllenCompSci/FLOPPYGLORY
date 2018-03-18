//Kris Bickham
//Prob27
//Tuesday
//Period 6
//Mr. Baker

//Libary Section
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
//Const Section
//Varible Section
char Ans;
//Prototype
void verse1();
void verse2();
void verse3();
void verse4();
void verse5();
void chorus();
//Main
void main()
{

do
{
clrscr ();
verse1 ();
chorus ();
getch ();
clrscr ();

verse2 ();
chorus ();
getch ();
clrscr ();

verse3 ();
chorus ();
getch ();
clrscr ();

verse4 ();
chorus ();
getch ();
clrscr ();

verse5 ();
getch ();
clrscr ();
cout<<"Do you want to run again? Y/N: ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

};
void verse1 ()
	{cout<<"There's a war goin doin between,"<<endl;
	 cout<<"My brothers tonight."<<endl;
	 cout<<"I don't want no war,"<<endl;
	 cout<<"Goin down, Goin down tonight."<<endl;
	 };
void verse2 ()
	{cout<<"Civilization!? Ha I call it as I see it,"<<endl;
	 cout<<"I call it cow-patty, You know I still cannot believe it."<<endl;
	 cout<<"Our evolution, Now has gone the way of hate,"<<endl;
	 cout<<"Our world involved, revovled into this stupid fate."<<endl;
	};
void verse3 ()
	{cout<<"All so different...Yeah I say we're all the same,"<<endl;
	 cout<<"All caught you know, in the division game."<<endl;
	 cout<<"Self destruction fast impending like a bullet,"<<endl;
	 cout<<"No one can stop it, once it's fired no one can control it."<<endl;
	};
void verse4 ()
	{cout<<"A final word. Wait this ain't no call to action,"<<endl;
	 cout<<"We ain't no sect. No we ain't stinking faction."<<endl;
	 cout<<"Unity, Unity, Unity you've heard it all before,"<<endl;
	 cout<<"This time it's not exclusive, we wanna stop the war."<<endl;
	};
void verse5 ()
	{cout<<"Unity, as one stand together!"<<endl;
	 cout<<"Unity, Evolutions gotta come!"<<endl;
	};
void chorus ()
	{cout<<"Stop this... war!"<<endl;
	 cout<<"Stop this... war!"<<endl;
	};

