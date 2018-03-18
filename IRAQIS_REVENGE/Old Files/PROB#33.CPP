//Chris Chapman
//7th
//prob33
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//Prototype
int fibonacci (int);

//variable section
int E;
char Answer;


void main ()
{
do{
	clrscr();
	//Hello, there. How are we?
	cout<<"Enter any number that you would like to see the fibonacci of."<<endl;
	cin>>E;
	cout<<"The fibonacci of "<<E<<" is "<<fibonacci(E)<<endl;

		getch();
		clrscr();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

int fibonacci (int E)
{
int Ans;

	if (E==1||E==0)
		Ans=1;
	else
		Ans=fibonacci(E-1)+fibonacci(E-2);
	return Ans;
};