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
char Answer, A2;
int Fine, Type, Day;

void main ()
{
clrscr();
do{
Fine=0;
do{
	clrscr();
	cout<<"Choose the type of over- due book from the following list:"<<endl;
	cout<<"1 Paperback"<<endl<<"2 magazines"<<endl<<"3 Reference"<<endl;
	cout<<"4 Other"<<endl;
	cin>>Type;
	cout<<"How many days is the book overdue?"<<endl;
	cin>>Day;
	switch (Type)
	{
		case 1: Fine=(.20*Day);
						break;
		case 2: Fine=(.35*Day);
						break;
		case 3: Fine=(.75*Day);
						break;
		case 4: Fine=(.50*Day);
						break;
	 }
	cout<<"Are there more books? (Y/N)"<<endl;
	cin>>A2;
	}while(A2=='Y'||A2=='y');
	clrscr();
	cout<<"Fines are equal to $"<<Fine<<endl;
	getch();
	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
