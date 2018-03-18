//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
//const
//var
long A;
char Choice;
apstring Name;
apstring Address;
apstring Trash;
int Number;
//proto
long cube(int);
apstring company(apstring Name, apstring Address);
apstring even(int Number);
void main()
{clrscr();
do{
	 cout<<"Please enter a number to be cubed"<<endl;
	 cin>>A;
	 cout<<"Here is your Number cubed "<<cube(A)<<endl;
	 cout<<"Press Enter to continue to next part";
	 getch();
	 clrscr();
	 cout<<"Enter Company Name";
	 getline(cin, Trash);
	 getline(cin, Name);
	 cout<<"Enter Company Address";
	 getline(cin, Address);
	 clrscr();

	 cout<<company(Name, Address)<<endl;
	 cout<<"Press Enter to continue to next part";
	 getch();
	 clrscr();
	 cout<<"Enter a number for even or odd";
	 cin>>Number;
	 cout<<even(Number)<<endl;



	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
long cube(int A)
	{return A*A*A;
	}
apstring company(apstring Name, apstring Address)
	{int B;
	 int C;
	 B=40-(Name.length()/2);
	 gotoxy(B, 1);
	 cout<<Name;

	 C=40-(Address.length()/2);
	 gotoxy(C,2);
	 cout<<Address;
	 return "";
	}
apstring even(int Number)
	{if (Number%2<1)
		cout<<"Your number is even";
			else
				cout<<"Your number is odd";
	return "";
	}