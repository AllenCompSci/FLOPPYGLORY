//Chris Chapman
//7th
//prob35
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//struct section
struct Points
{
apstring Name;
int Points;
apstring Date;
};

//Prototype

//global variable section
int E,K;
Points A;
char Answer;
apstring trash;
apvector <Points> Students (10);

void main ()
{
do{
	E=0;
	clrscr();
	for(E=0;E<10;E++)
		{
		cout<<"Enter the name of student number "<<E+1<<endl;
		getline (cin,Students[E].Name);
		cout<<"Enter the amount of points from 1- 100 for each student."<<endl;
		cin>>Students[E].Points;
		getline(cin,trash);
		cout<<"Enter today's date."<<endl;
		getline (cin,Students[E].Date);
		}

	for(E=0;E<10;E++)
		for(K=E;K<10;K++)
			if (Students[E].Points<Students[K].Points)
				{
				A=Students[E];
				Students[E]=Students[K];
				Students[K]=A;
				}
	clrscr();

	for(E=0;E<10;E++)
		{
		cout<<Students[E].Name;
		gotoxy(10,E+1);
		cout<<Students[E].Points;
		gotoxy(14,E+1);
		cout<<setw(10)<<Students[E].Date<<endl;
		}

		getch();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
