//Rebecca Russell
//6th
//Mr. Baker
//Program:Cross Word Puzzle
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
//Constant
//Variable
apvector <apstring> Words (20);
apvector <apstring> Puzzle (20);
bool Key [20][20];
int Col;
int Row;
int I;
int X;
int Y;
int D;
int Wn;
int End;
bool Flag;
void main ()
{randomize();
clrscr();
do
{clrscr();
for (I=0; I<20; I++)
 do
 {cout<<"Please enter a five letter word in all caps "<<I+1<<" of 20."<<endl;
	cin>>Words[I];
	clrscr();
 }
 while(Words[I].length()!=5);

/*
Words[0]="water";
Words[1]="leave";
Words[2]="black";
Words[3]="alien";
Words[4]="buses";
Words[5]="shift";
Words[6]="enter";
Words[7]="seven";
Words[8]="eight";
Words[9]="drink";
Words[10]="lunch";
Words[11]="entry";
Words[12]="allen";
Words[13]="candy";
Words[14]="debug";
Words[15]="rooms";
Words[15]="boxes";
Words[16]="docks";
Words[17]="couch";
Words[18]="furby";
Words[19]="micro";
*/
for (Col=0; Col<20; Col++)
	Puzzle[Col]="";

for (Col=0; Col<20; Col++)
	{for (Row=0; Row<20; Row++)
	{Puzzle[Col]=Puzzle[Col]+char(random(26)+65);
	 Key[Col][Row]=false;
	}}

for(Wn=0; Wn<20; Wn++)
{D=random(8)+1;
 switch (D)
 {case 1 : {do
						{X=random(16)+4;
						 Y=random(16)+4;
						 Flag=true;
						 for (I=0; I<5; I++)
							if (Key[X-I][Y-I])
							Flag=false;
						}
						while(!Flag);

						for (I=0; I<5; I++)
						{Puzzle[X-I][Y-I]=Words[Wn][I];
						 Key[X-I][Y-I]=true;
						}}
						 break;

case 2 : {do
					{X=random(16);
					 Y=random(16)+4;
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X+I][Y-I])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X+I][Y-I]=Words[Wn][I];
					 Key[X+I][Y-I]=true;
					}}
					 break;

case 3 : {do
					{X=random(16)+4;
					 Y=random(16);
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X-I][Y+I])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X-I][Y+I]=Words[Wn][I];
					 Key[X-I][Y+I]=true;
					}}
					 break;

case 4 : {do
					{X=random(16);
					 Y=random(16);
					 Flag=true;
					 for (I=0; I<5; I++)
					 if (Key[X+I][Y+I])
					 Flag=false;}
					 while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X+I][Y+I]=Words[Wn][I];
					 Key[X+I][Y+I]=true;}}
					 break;

case 5 : {do
					{X=random(16)+4;
					 Y=random(20);
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X-I][Y])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X-I][Y]=Words[Wn][I];
					 Key[X-I][Y]=true;
					}}
					break;

case 6 : {do
					{X=random(20);
					 Y=random(16)+4;
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X][Y-I])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X][Y-I]=Words[Wn][I];
					 Key[X][Y-I]=true;
					}}
					break;

case 7 : {do
					{X=random(16);
					 Y=random(20);
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X+I][Y])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X+I][Y]=Words[Wn][I];
					Key[X+I][Y]=true;}}
					break;

case 8 : {do
					{X=random(20);
					 Y=random(16);
					 Flag=true;
					for (I=0; I<5; I++)
					 if (Key[X][Y+I])
						Flag=false;
					}
					while(!Flag);

					for (I=0; I<5; I++)
					{Puzzle[X][Y+I]=Words[Wn][I];
					 Key[X][Y+I]=true;
					}}
					break;
					}}

gotoxy(13,1);
cout<<"Puzzle"<<endl;
for (Col=0; Col<20; Col++)
 {for (Row=0; Row<20; Row++)
	 cout<<Puzzle[Col][Row]<<" ";
	 cout<<endl;}

gotoxy(68,1);
cout<<"Word Bank"<<endl;
for (I=1; I<21; I++)
 {gotoxy(70,I+1);
	cout<<Words[I-1];}
do
{cout<<endl<<endl<<"Press 1 to run again or a 2 to end: "<<endl;
 cin>>End;
}
while((End<1)||(End>2));
}
while(End==1);
};