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
#include<fstream.h>
//struct
//const
//var
apvector<int> Data (10);
int A;
ifstream in;
char Choice;
//proto
void main()
{clrscr();
do{
	 in.open("a:\\number.dat");
	 for(A=0;A<10;A++)
	 {in>>Data[A];
		cout<<Data[A];
	 }







	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}
