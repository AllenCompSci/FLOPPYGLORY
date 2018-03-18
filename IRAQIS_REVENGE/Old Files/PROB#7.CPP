//Toni Whipple
//prob#7
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const.section

//variable section
int Age;

void main ()
{
clrscr();
cout<<"Please enter your age"<<endl;
cin>>Age;
cout<<endl;

if (Age<12)

cout<<"Child ticket price (12 or under): $4.00"<<endl;

else (Age<13) cout<<"Adult ticket price (13 or older): $6.50"<<endl;

cout<<"Press enter eo exit"<<endl;
getch();



}
