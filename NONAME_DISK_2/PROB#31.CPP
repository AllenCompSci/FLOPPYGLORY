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
int A;
char Choice;
//proto
long factorial(int);
void main()
{clrscr();
do{
cout<<"Please choose a Number";
cin>>A;
cout<<factorial(A)<<endl;
	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
long factorial(int A)
	 {long Number;
		if(A<2)
		 Number=1;
			else
			 Number=A*factorial(A-1);
		return Number;
	 }





