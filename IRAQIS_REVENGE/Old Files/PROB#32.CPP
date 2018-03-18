//Chris Chapman
//7th
//Prob32
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//Prototype
long factorial (long);

//global variable section
long Ans, Num;
int E;
char Answer;


void main ()
{
do{
	clrscr();
	//Hello, there. How are we?
	cout<<"Enter any whole and positive number that you want the factoral of"<<endl;
	cin>>Num;
	cout<<factorial(Num);


		getch();
		clrscr();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

long factorial (long Num)
{
	long Ans;

	if(Num==1)
		Ans=1;
	else
		Ans=Num*factorial(Num-1);

return Ans;
};