//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants
//Variables
int Num1;
int Num2;
int Num3;
int Num4;
//Program
void main ()
{
clrscr();
Num1=0;
Num2=0;
Num3=0;
Num4=0;
cout<<"Please input FOUR integers, and only four, with spaces seperating";
cout<<" them."<<endl<<"Then press return."<<endl;
cin>>Num1;
cin>>Num2;
cin>>Num3;
cin>>Num4;
cout<<setw(10)<<"First"<<setw(10)<<"Second"<<setw(10)<<"Third";
cout<<setw(10)<<"Fourth"<<endl;
cout<<setw(10)<<Num1<<setw(10)<<Num2<<setw(10)<<Num3<<setw(10)<<Num4;
getch();
}