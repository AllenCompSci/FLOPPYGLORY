//Rebecca Russell
//6th
//Mr.Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
//Constant
//Variable
int N;
long F1, F2, Next;
//Prototype
long fib (int, long, long);
void main ()
{clrscr();
F1=F2=1;
cout<<"Please enter a number to find its place in the ";
cout<<"fibonacci sequence: "<<endl;
cin>>N;
cout<<endl<<"The fibonacci value of "<<N<<" is: "<<fib(N, F1, F2);
getch();
};
long fib (int N, long F1, long F2)
{if (N<3)
	Next=1;
 else
 {Next=F1+F2;
	F1=F2;
	F2=Next;
	N--;
	if (N>2)
	fib(N, F1, F2);
 }
return Next;
}