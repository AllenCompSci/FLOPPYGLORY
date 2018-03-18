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
//Prototype Section
void pass_wrong (int,int);
void pass_right (int&,int&);
//Variables
char Again;
int One, Two;
//Program
void main ()
{
do
{clrscr();
cout<<"Please enter integer #1:  ";
cin>>One;
cout<<endl<<"Please enter integer #2:  ";
cin>>Two;
cout<<"Your integers before the function:  "<<One<<" "<<Two<<endl;
cout<<"Your integers inside the function:  ";
pass_wrong (One, Two);
cout<<endl<<"Your integers after the function:  "<<One<<" "<<Two<<endl;
getch();
clrscr();
cout<<"Your integers will now be passed through a new function."<<endl;
cout<<"Your integers before the function:  "<<One<<" "<<Two<<endl;
cout<<"Your integers inside the function:  ";
pass_right (One, Two);
cout<<endl<<"Your integers after the function:  "<<One<<" "<<Two<<endl;
getch();
clrscr();
cout<<"Do you want to run it again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
void pass_wrong (int One, int Two)
{cout<<One+5;
cout<<" "<<Two-3;}
void pass_right (int&One, int&Two)
{One+=5;
Two-=3;
cout<<One<<" "<<Two;}