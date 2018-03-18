//Kris Bickham
//Prob25
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
int X;
int Y;
char Ans;
//Prototype
void pass_wrong (int, int);
void pass_right (int&, int&);
//Main
void main()
{
do
{
clrscr ();
cout<<"Please Enter a whole number: ";
cin>>X;
cout<<endl;
cout<<"Enter number 2: ";
cin>>Y;
clrscr ();
cout<<"Number 1 before pass_wrong: "<<X<<endl;
cout<<"Number 2 before pass_wrong: "<<Y<<endl;
pass_wrong (X, Y);
cout<<"Number 1 after pass_wrong: "<<X<<endl;
cout<<"Number 2 after pass_wrong: "<<Y<<endl;
cout<<endl;
cout<<"Number 1 before pass_right: "<<X<<endl;
cout<<"Number 2 before pass_right: "<<Y<<endl;
pass_right (X, Y);
cout<<"Number 1 after pass_right: "<<X<<endl;
cout<<"Number 2 after pass_right: "<<Y<<endl;
getch();
clrscr ();
cout<<"Do you want to run again? Y/N: ";
cin>>Ans;
clrscr ();
}while(Ans=='Y'||Ans=='y');
};
// Headers section
void pass_wrong (int X, int Y)
	{
	X+=5;
	cout<<"Number 1 during pass_wrong: "<<X<<endl;
	Y+=5;
	cout<<"Number 2 during pass_wrong: "<<Y<<endl;
	};
void pass_right (int&X,int&Y)
	{
	X+=7;
	cout<<"Number 1 during pass_right: "<<X<<endl;
	Y+=7;
	cout<<"Number 2 during pass_right: "<<Y<<endl;
	};