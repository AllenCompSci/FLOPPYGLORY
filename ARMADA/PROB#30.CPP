//Rebecca Russell
//6th
//Mr.Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
//Constant
//Variable
int L;
int W;
int Area;
int Answer;
//Prototype
void get_data (int&, int&);
double calculate (int, int);
void main ()
{clrscr();
do
{clrscr();
get_data (L, W);
clrscr();
cout<<"Area: "<<calculate (L, W)<<endl<<endl;
cout<<"Press Return to Continue: "<<endl;
getch();
clrscr();
cout<<"To run the program again press 1, to end press 2: ";
cin>>Answer;
}
while (Answer==1);
getch();
};
void get_data (int& L, int& W)
{cout<<"Please enter a value (length):"<<endl;
 cin>>L;
 cout<<endl<<"Please enter another value(width)"<<endl;
 cin>>W;
 cout<<"Length: "<<L<<endl<<"Width: "<<W<<endl<<endl;
}

double calculate (int L, int W)
{return L*W;
}
