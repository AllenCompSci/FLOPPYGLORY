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
int Val1;
double Val2;
apstring Trash;
apstring Comp;
apstring Address;
//Prototype
apstring even (int);
double cube (double);
apstring comp (apstring);
apstring address (apstring);
void main ()
{clrscr();

cout<<"Please enter a value:"<<endl;
cin>>Val1;
cout<<even(Val1);
cout<<endl<<endl<<"Please hit return to continue.";
getch();
clrscr();

cout<<"Please enter a value to be cubed:"<<endl;
cin>>Val2;
cout<<cube(Val2);
cout<<endl<<endl<<"Please hit return to continue.";
getch();
clrscr();

getline(cin, Trash);
cout<<"Please enter the name of the company:"<<endl;
getline(cin,Comp);
cout<<endl<<"Please enter the company's address:"<<endl;
getline(cin,Address);
clrscr();
cout<<comp(Comp);
cout<<address(Address);

getch();
};

apstring even (int Val1)
{apstring Var;
if (Val1%2==0)
	Var="Even";
else
	Var="Odd";
return Var;
}

double cube (double Val2)
{return Val2*Val2*Val2;
}


apstring comp (apstring Comp)
{cout<<setw(Comp.length()/2+40);
 return Comp;
}

apstring address (apstring Address)
{gotoxy(1,5);
 cout<<setw(Address.length()/2+40);
 return Address;
}