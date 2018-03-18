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
apstring Name;
apstring Address;
double Start;
long End;
int Total;
apstring Trash;
char Choice;
void main()
{clrscr();
do{
	 cout<<"Enter Name ";
	 getline(cin, Name);
	 cout<<"Enter Address";
	 getline(cin, Address);
	 cout<<"What time did call start ";
	 cin>>Start;
	 cout<<"What time did call end ";
	 cin>>End;
	 if(Start<18 && Start>7.59)
		{Start-=18;
		 Start*=-6;
		 Start/=10;
		 Start*=.25;
		 cout<<Start;
		}
	 if(Start>800)
		{Start-=800;
		 Start*=-60;
		 Start/=100;
		 Start*=.18;
		 cout<<Start;
		}
	 if(Start>1759 && Start<2401)
		{Start-=1759;
		 Start*=60;
		 Start/=100;
		 Start*=.18;
		 cout<<Start;
		}





	 cout<<"Would you like to run the program again";
	 cin>>Choice;
	 getline(cin, Trash);
	}while(Choice=='y' || Choice=='Y');
 }