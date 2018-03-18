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
char Choice;
apstring Trash;
void main()
{clrscr();
do{
	 do{cout<<"Enter Name: ";
			getline(cin, Name);
		 }while (Name!="ZZZ");
	 cout<<"Do you want to run the Program again";
	 cin>>Choice;
	 getline(cin, Trash);
	}while (Choice=='Y' || Choice=='y');
}