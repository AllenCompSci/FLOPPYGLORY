//Jeff Stein
//6th Period
//Mr. Baker
//Program: Cube, Odd/Even, Company Name and addy using functions
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <iomanip.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>
double cube (double);
double X;
double Num;
int A ;
apstring Answer;
apstring number (apstring);
apstring Comp;
apstring Addy;
apstring co (apstring);
apstring ad (apstring);
apstring trash;
void main()
{
clrscr();

cout<<"Enter a number you wish to cube."<<endl;
cin>>Num;
cout<<"Answer is:  "<<cube(X);
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Enter a number."<<endl;
cin>>A;
cout<<"Your number is " <<number(Answer);
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Enter your company's Name.  Then enter the Address."<<endl;
getline(cin,trash);
getline(cin,Comp);
getline(cin,Addy);
cout<<endl;
cout<<endl;
cout<<co(Comp);
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<ad(Addy);


getch();
};

double cube (double X)
{
X=Num*Num*Num;
return X;
};

apstring number (apstring Answer)
{
		if(A%2==0)
			Answer="Even";
		else
			Answer="Odd";

		return Answer;
}

apstring co (apstring Comp)
{
	 cout<<setw(Comp.length()/2+40);
	 return Comp;
}

apstring ad (apstring Addy)
{
	 cout<<setw(Comp.length()/2+40);
	 return Addy;
}