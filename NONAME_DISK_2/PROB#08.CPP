//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
int Temp;
void main()
{clrscr();
cout<<"Enter Temperature";
cin>>Temp;
if (Temp>85)
	cout<<"Swimming";
		else if (70<Temp)
		cout<<"Tennis";
			else if (32<Temp)
			cout<<"Golf";
				else if (10<Temp)
				cout<<"Skiing";
					else
					cout<<"Checkers";
cout<<"press return to continue";
getch();
}
