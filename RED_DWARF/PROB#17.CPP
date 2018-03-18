
//KRIS BICKHAM
//PROB17
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Department;
int DC0, DC1, DC2, DC3, DC4, DC5, DC6, DC7, DC8, DC9;
int Run;
//CONSTANTS------------
//MAIN
void main ()
{
clrscr();
cout<<"Enter Department ID#: ";
cin>>Department;
cout<<endl;

do
{cout<<"Enter number of students for Class 1 1-40: "<<endl;
cin>>DC0;
}while((DC0>41)||(DC0<0));

do
{cout<<"Enter number of students for Class 2 1-40: "<<endl;
cin>>DC1;
}while((DC1>41)||(DC1<0));

do
{cout<<"Enter number of students for Class 3 1-40: "<<endl;
cin>>DC2;
}while((DC2>41)||(DC2<0));

do
{cout<<"Enter number of students for Class 4 1-40: "<<endl;
cin>>DC3;
}while((DC3>41)||(DC3<0));

do
{cout<<"Enter number of students for Class 5 1-40: "<<endl;
cin>>DC4;
}while((DC4>41)||(DC4<0));

do
{cout<<"Enter number of students for Class 6 1-40: "<<endl;
cin>>DC5;
}while((DC5>41)||(DC5<0));

do
{cout<<"Enter number of students for Class 7 1-40: "<<endl;
cin>>DC6;
}while((DC6>41)||(DC6<0));

do
{cout<<"Enter number of students for Class 8 1-40: "<<endl;
cin>>DC7;
}while((DC7>41)||(DC7<0));

do
{cout<<"Enter number of students for Class 9 1-40: "<<endl;
cin>>DC8;
}while((DC8>41)||(DC8<0));

do
{cout<<"Enter number of students for Class 10 1-40: "<<endl;
cin>>DC9;
}while((DC9>41)||(DC9<0));

clrscr();
cout<<Department<<"00   ";
for (Run=0;Run<=DC0;Run++)
	cout<<"*";
cout<<setw(5)<<DC0<<endl;

cout<<Department<<"01   ";
for (Run=0;Run<=DC1;Run++)
	cout<<"*";
cout<<setw(5)<<DC1<<endl;

cout<<Department<<"02   ";
for (Run=0;Run<=DC2;Run++)
	cout<<"*";
cout<<setw(5)<<DC2<<endl;

cout<<Department<<"03   ";
for (Run=0;Run<=DC3;Run++)
	cout<<"*";
cout<<setw(5)<<DC3<<endl;

cout<<Department<<"04   ";
for (Run=0;Run<=DC4;Run++)
	cout<<"*";
cout<<setw(5)<<DC4<<endl;

cout<<Department<<"06   ";
for (Run=0;Run<=DC6;Run++)
	cout<<"*";
cout<<setw(5)<<DC6<<endl;

cout<<Department<<"07   ";
for (Run=0;Run<=DC7;Run++)
	cout<<"*";
cout<<setw(5)<<DC7<<endl;

cout<<Department<<"08   ";
for (Run=0;Run<=DC8;Run++)
	cout<<"*";
cout<<setw(5)<<DC8<<endl;

cout<<Department<<"09   ";
for (Run=0;Run<=DC9;Run++)
	cout<<"*";
cout<<setw(5)<<DC9<<endl;

getch ();
}

