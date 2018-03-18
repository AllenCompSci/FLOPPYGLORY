//Chris Chapman
//Prob#28
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>

//Const Section

//Prototype Section
int cube (int);
void center (int&,int&,apstring,apstring);
apstring even_odd (int,apstring&);

//Global Variables Section
char Answer;
int Number,Number2,L_n,L_a;
apstring Name, Address, Trash, Response;

void main ()
{
//I am stupid today.
do{
	clrscr();
	cout<<"Enter a number that I can cube!!"<<endl;
	cin>>Number;
	cout<<cube(Number)<<endl;

	cout<<"Enter a company's name!"<<endl;
	getline (cin,Trash);
	getline (cin,Name);
	cout<<"Enter the address!"<<endl;
	getline (cin,Address);
	clrscr();
	center(L_n,L_a,Name,Address);
	gotoxy (L_n,1);
	cout<<Name;
	gotoxy (L_a,2);
	cout<<Address<<endl<<endl;

	cout<<"Please enter a number and I find out if it's even or odd!"<<endl;
	cin>>Number2;
	clrscr();
	cout<<Number2<<" is "<<even_odd (Number2,Response)<<endl<<endl;

	cout<<"Run again? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

int cube (int Number)
	{
		return Number*Number*Number;
	};

void center (int&L_n,int&L_a,apstring Name,apstring Address)
	{
		L_n=((80-Name.length())/2)+1;
		L_a=((80-Address.length())/2)+1;
	};

apstring even_odd (int Number2, apstring&Response)
	{
		if (Number2%2==0)
			Response="even";
		else
			Response="odd";

		return Response;
	};