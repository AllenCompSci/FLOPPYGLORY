//Chris Chapman
//Prob 12a
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const.section

//variable section
int K;
char Answer;

void main ()
{
do{
clrscr();
K=0;
cout<<"Odds"<<setw(15)<<"Evens"<<endl;
	for (K=0;K<20;K+=2)
		cout<<setw(3)<<K+1<<setw(15)<<K+2<<endl;


	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
