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
int Id;
int Class;
int Class1;
int Class2;
int Class3;
int Class4;
int Class5;
int Class6;
int Class7;
int Class8;
int Class9;
char Choice;
void main()
{clrscr();
do{
	 clrscr();
	 cout<<"Enter Department ID#";
	 cin>>Id;
	 cout<<"How many students in (Maximum is 40) "<<Id<<"00 ";
	 cin>>Class;
	 cout<<"In"<<Id<<"01 ";
	 cin>>Class1;
	 cout<<"In"<<Id<<"02 ";
	 cin>>Class2;
	 cout<<"In"<<Id<<"03 ";
	 cin>>Class3;
	 cout<<"In"<<Id<<"04 ";
	 cin>>Class4;
	 cout<<"In"<<Id<<"05 ";
	 cin>>Class5;
	 cout<<"In"<<Id<<"06 ";
	 cin>>Class6;
	 cout<<"In"<<Id<<"07 ";
	 cin>>Class7;
	 cout<<"In"<<Id<<"08 ";
	 cin>>Class8;
	 cout<<"In"<<Id<<"09 ";
	 cin>>Class9;
	 clrscr();
	 if(Class1<41 && Class2<41 && Class3<41 && Class4<41 && Class5<41 &&
	 Class6<41 && Class7<41 && Class8<41 && Class9<41)
	 {cout<<Id<<"00"<<"  "<<Class<<" ";
		for(Class; Class>0; Class--)
		 cout<<"*";
		cout<<endl<<Id<<"01"<<"  "<<Class1<<" ";
		for(Class1; Class1>0; Class1--)
		 cout<<"*";
		cout<<endl<<Id<<"02"<<"  "<<Class2<<" ";
		for(Class2; Class2>0; Class2--)
		 cout<<"*";
		cout<<endl<<Id<<"03"<<"  "<<Class3<<" ";
		for(Class3; Class3>0; Class3--)
		 cout<<"*";
		cout<<endl<<Id<<"04"<<"  "<<Class4<<" ";
		for(Class4; Class4>0; Class4--)
		 cout<<"*";
		cout<<endl<<Id<<"05"<<"  "<<Class5<<" ";
		for(Class5; Class5>0; Class5--)
		 cout<<"*";
		cout<<endl<<Id<<"06"<<"  "<<Class6<<" ";
		for(Class6; Class6>0; Class6--)
		 cout<<"*";
		cout<<endl<<Id<<"07"<<"  "<<Class7<<" ";
		for(Class7; Class7>0; Class7--)
		 cout<<"*";
		cout<<endl<<Id<<"08"<<"  "<<Class8<<" ";
		for(Class8; Class8>0; Class8--)
		 cout<<"*";
		cout<<endl<<Id<<"09"<<"  "<<Class9<<" ";
		for(Class9; Class9>0; Class9--)
		 cout<<"*";
	 }
	 else
		cout<<"Too Many students in a class please run program again"<<endl;
	 cout<<"Do you want to run the program again y/n";
	 cin>>Choice;
	}while(Choice=='y' || Choice=='Y');
}
