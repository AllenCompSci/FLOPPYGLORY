// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

void get_data ();
void calculate (int&, int&, int&);
int length;
int width;
int area;

void main ()  {
clrscr();

get_data();
calculate(area, length, width);
cout<<area;




getch();

};


void get_data ()
	{
	 cout<<"Enter the length"<<endl;
	 cin>>length;

	 clrscr();

	 cout<<"Enter the width"<<endl;
	 cin>>width;

	 clrscr();


	};

void calculate (int &area, int &length, int &width)
	{
	area= length*width;

	};

