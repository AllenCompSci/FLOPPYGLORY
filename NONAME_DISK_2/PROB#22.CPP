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
apvector<int> N(15);
int A;
char Choice;
void main()
{do{clrscr();
		randomize();
		for(A=0; A<15; A++)
		 {N[A]=random (6)+1;
			cout<<N[A]<<endl;
		 }
	 cout<<endl<<"Do you want to run the program again y/n";
	 cin>>Choice;
	}while(Choice=='y' || Choice=='Y');
}
