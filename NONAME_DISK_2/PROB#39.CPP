//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
//struct

//const
//var
int Tickets;
apstring Name, Phone, Address, Trash;
char Choice, Choice1;
//proto
void main()
{clrscr();
do{
	 do{cout<<"Please enter your Name.";
			getline(cin, Name);
			cout<<"Please enter your phone number.";
			cin>>Phone;
			getline(cin, Trash);
			cout<<"Please enter your Address.";
			getline(cin, Address);
			cout<<"Is this information correct? Y/N";
			cin>>Choice1;
		 }while(Choice1=='N' || Choice1=='n');


		cout<<endl<<"Where would you like your Tickets to be?";
		cout<<1.<<"Lowest Level 1st 20 seats  $45.00"<<endl<<2.;
		cout<<"Lowest Level next 20 seats  $35.00"<<endl<<3.;
		cout<<"Middle Level  $25.00"<<endl<<4.<<"Highest Level  $15.00";





	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
