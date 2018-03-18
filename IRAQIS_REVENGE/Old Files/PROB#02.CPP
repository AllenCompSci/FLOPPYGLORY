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
int Day, Total;

void main ()
{
clrscr();
Day=1;
Total=1;
do{
	for (Day=1;Day<=20;Day++)
	{  cout<<"Day "<<Day<<endl;
			for (Total=1;Total>=1;Total*=2)
				{
				gotoxy (7,1);
				cout<<Total<<endl;
				}
	}
	cout<<"Total after 20 days: "<<Total<<endl;
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
