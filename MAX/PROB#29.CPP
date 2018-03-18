// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

void swapright (int&, int&);
void swapwrong (int, int);

int val1;
int val2;


void main ()  {
clrscr();

cout<<"please insert two values"<<endl;
cin>>val1>>val2;
cout<<endl<<endl;

cout<<val1<<" "<<val2<<endl<<endl;

swapwrong (val1, val2);

cout<<val1<<" "<<val2<<endl<<endl;

swapright (val1, val2);

cout<<val1<<" "<<val2<<endl<<endl;

getch();

};

void swapwrong (int val1, int val2)
	{
	int other;

	other=val1;
	val1=val2;
	val2=other;
	};

void swapright (int &val1, int &val2)
	{
	int other;

	other=val1;
	val1=val2;
	val2=other;
	};