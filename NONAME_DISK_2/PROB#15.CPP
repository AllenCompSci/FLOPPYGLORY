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
char Choice;
int Late;
double Total;
double Fine;
int Book;
void main()
{clrscr();
Total=0;
do{
	 cout<<"Please Choose Type of Late book"<<endl<<"1. Paperback";
	 cout<<endl<<"2. Magazines"<<endl<<"3. Reference Book"<<endl;
	 cout<<"4. Other General Books";
	 cin>>Book;
	 switch (Book)
	 {case 1:Fine=.20;
		break;
		case 2:Fine=.35;
		break;
		case 3:Fine=.75;
		break;
		case 4:Fine=.50;
	 }
	 cout<<endl<<"How Many Days has the book been Late";
	 cin>>Late;
	 Total+=Fine*Late;
	 cout<<setprecision(2)<<setiosflags(ios::showpoint);
	 cout<<"The Fee Total= "<<Total<<endl;
	 cout<<"Do you have another Late Book";
	 cin>>Choice;
	}while(Choice=='Y' || Choice=='y');
}
