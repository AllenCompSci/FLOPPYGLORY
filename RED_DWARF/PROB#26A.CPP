//Ryan Pettersson
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
//Prototype
int numbers (int, int);
//Main
void main()
{
clrscr ();
cout<<"Please Enter a whole number: ";
cin>>X;
cout<<endl;
cout<<"Enter number 2: ";
cin>>Y;
cout<<"Number 1: "<<X<<endl;
cout<<"Number 2: "<<Y<<endl;
getch;
numbers (X, Y);
cout<<"Number 1: "<<X<<endl;
cout<<"Number 2: "<<Y<<endl;
getch();
}
int numbers (int X&, int Y& )
{
X+=5;
cout<<"Number 1 modified: "<<X<<endl;
Y+=5;
cout<<"Number 2 modified: "<<Y<<endl;
}