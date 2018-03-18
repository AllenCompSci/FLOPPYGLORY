//Rebecca Russell
//6th
//Mr.Baker
//Program: Displays info. from user, then changes value in function...but it
//displays the same, then does same thing, but changes original value
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
//Constant
//Variable
int A;
int B;
//Prototype
void swap_wrong (int, int);
void swap_right (int&, int&);
void main ()
{clrscr();
cout<<"Please enter a Number:"<<endl;
cin>>A;
cout<<endl<<"Please enter another Number"<<endl;
cin>>B;
clrscr();
cout<<A<<", "<<B<<endl<<endl;
swap_wrong (A, B);
cout<<A<<", "<<B<<endl<<endl;
swap_right (A, B);
cout<<A<<", "<<B;

getch();
};
void swap_wrong (int A, int B)
{int Aa;
 Aa=A;
 A=B;
 B=Aa;
}

void swap_right (int& A, int&B)
{int Aa;
 Aa=A;
 A=B;
 B=Aa;
}