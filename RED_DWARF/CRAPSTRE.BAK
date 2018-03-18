#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apmatrix.h>
#include <stdlib.h>

int X;
int Y;
bool Id [20][20];
char Screen [20][20];
int I;
int Q;
int Run;
int B;
int Move;

void main ()
{
clrscr ();
randomize();
for(I=0;I<20;I++)
 for(Q=0;Q<20;Q++)
	Screen[I][Q]='.';

Run=random(10)+1;

//for(B=0;B<Run;B++)
//{ I=random(20);
//	Q=random(20);
//	Screen[I][Q]='^';
//	Id[I][Q]=false;}

X=1;
Y=1;

for(I=0;I<20;I++)
{
gotoxy(1,23);
cout<<"Which Direction? use numpad and hit return after";

cin>>Move;

	 switch(Move)
{case 8 : Screen[Y][X]=' ';
					Id[Y][X]=true;
					Y++;
					break;
 case 4 : Screen[Y][X]=' ';
					Id[Y][X]=true;
					X=X-1;
					break;
 case 6 : Screen[Y][X]=' ';
					Id[Y][X]=true;
					X++;
					break;
 case 5 : Screen[Y][X]=' ';
					Id[Y][X]=true;
					Y=Y-1;
					break;
}

Screen[Y][X]='K';

for(I=0;I<20;I++)
 {for(Q=0;Q<20;Q++)
	 cout<<Screen[I][Q]<<' ';
cout<<endl;
 }

}

}