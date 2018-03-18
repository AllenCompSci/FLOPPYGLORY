//Jeff Stein
//6th Period
//Mr. Baker
//Program:
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <iomanip.h>
#include <apvector.h>
#include <apmatrix.h>
#include <stdlib.h>

struct Game
{
	apstring Name;
	int Score;
	apstring Date;
};

Game High_Sc;
apvector <Game> Video (10);
apvector <Game> High (10);
int I;
int Total;
int A;
apstring Trash;
void sort();
void info();
void out();

void main()
{
 info();
 clrscr();
 sort();






getch();
}



void info()
{
 for(I=0;I<=10;I++)
	 {
			cout<<"Please put in your Name."<<endl;
				getline(cin,High_Sc.Name);

			cout<<"Please enter your score."<<endl;
				cin>>High_Sc.Score;
				getline(cin,Trash);

			cout<<"Please put the date."<<endl;
				getline(cin,High_Sc.Date);

			Video[A]=High_Sc;
			clrscr();

	 };

}


void sort ()
{
int J;
int A;
int K;





				if (Video[A].Score<High[J+1].Score)
				{
					K=Video[A].Score;
					Video[A].Score=K;
					Video[J+1].Score=A;
				}

}
void out ()
{
	cout<<"Name: "<<Video[A].Name<<endl;
	cout<<"Score: "<<Video[A].Score<<endl;
	cout<<"Date: "<<Video[A].Date <<endl;
	cout<<endl;

}

