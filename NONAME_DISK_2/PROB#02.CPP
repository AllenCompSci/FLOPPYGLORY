//Jeremy Higgins
//September 4, 2001
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
int First;
int Second;
int Third;
int Fourth;
void main()
{clrscr();
cout<<"Put in four ints under 10, enter after each"<<endl;
cin>>First;
cin>>Second;
cin>>Third;
cin>>Fourth;
clrscr();
cout<<"First"<<setw(16)<<"Second"<<setw(15)<<"Third";
cout<<setw(16)<<"Fourth"<<endl;
cout<<setw(5)<<First;
cout<<setw(16)<<Second;
cout<<setw(15)<<Third;
cout<<setw(16)<<Fourth;
getch();
}

