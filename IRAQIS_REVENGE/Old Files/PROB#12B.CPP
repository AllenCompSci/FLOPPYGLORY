//Chris Chapman
//Prob 12b
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
int Num1, Num2;

void main ()
{
do{
clrscr();
cout<<"Enter the first of a range of numbers, ex:7!"<<endl;
cin>>Num1;
clrscr();
cout<<"Enter the second of this range, it must be larger than your first, ";
cout<<"ex: 34"<<endl;
cin>>Num2;
clrscr();
cout<<"Odds"<<setw(15)<<"Evens"<<endl;
for (Num1=Num1;Num1<Num2;Num1+=1)
	 {
if (Num1%2==0)
	cout<<setw(15)<<Num1<<endl;
	else
		cout<<Num1;
if (Num2%2==0)
	cout<<setw(15)<<Num2<<endl;
	else
		cout<<Num2<<endl;
		}
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
