//Chris Chapman
//shell
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const.section

//variable section
char Answer;
int Day;
double Total;

void main ()
{
clrscr();
Day=1;
Total=.01;
do{

	for (Day=1;Day<=20;Day++)
	{  cout<<"Day "<<Day<<": $ ";
		 Total*=2;
		 cout<<Total-0.01<<endl;

	}
	cout<<"Total after 20 days: "<<Total<<endl;
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
