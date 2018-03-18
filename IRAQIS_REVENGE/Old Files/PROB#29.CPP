//Chris Chapman
//7th
//prob29
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>

//const.section

//Prototype
void swap_wrong (int, int);
void swap_right (int&, int&);

//variable section
int E, N1, N2, S;
char Answer;


void main ()
{
do{
	clrscr();
	//Hello, there. How are we?
	cout<<"Enter a number between 1 and 30."<<endl;
	cin>>N1;
	cout<<"Enter a second number, with the same parameters."<<endl;
	cin>>N2;
	clrscr();
	cout<<"Number 1: "<<N1<<endl;
	cout<<"Number 2: "<<N2<<endl;
	getch();
	cout<<"After swap_wrong: "<<endl;
	swap_wrong (N1,N2) ;
	cout<<"Number 1: "<<N1<<endl<<"Number 2: "<<N2;
	getch();
	cout<<endl<<"After swap_right: "<<endl;
	swap_right (N1,N2);
	cout<<"Number 1: "<<N1<<endl<<"Number 2: "<<N2<<endl;
		getch();
		clrscr();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}

void swap_wrong (int N1, int N2)
	{
	N1;
	N2;
	};
void swap_right (int& N1, int& N2)
	{
	if(N1<N2)
		{
		S=N2-N1;
		N1+=S;
		N2-=S;
		}
			else
				{
				N1-=S;
				N2+=S;
				}

	 };
