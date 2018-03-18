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
char Choice;
long A;
//proto
long fib (long);
void main()
{clrscr();
do{
	 cout<<"What number would you like to stop at";
	 cin>>A;
	 cout<<fib(A)<<" Your Number"<<endl;
	 cout<<"Would you like to run the Program again";
	 cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
long fib(long A)
	{long B;
	 if(A<3)
		B=1;
		 else
			B=fib(A-1)+fib(A-2);
	 return B;
	}


