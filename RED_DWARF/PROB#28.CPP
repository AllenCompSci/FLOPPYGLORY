//KRIS BICKHAM
//PROB#25A
//DUE  ..like tomorrow or something
//PERIOD 6
//MR. BAKER
//LIBRARIES---------------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apmatrix.h>
#include <stdlib.h>
//VARIABLES----------------------
int Mx;
int X;
int Y;
int Num;
int L;
int Word;
int Q;
int Blah;
int Empty;
int Wx;
int C;
int Wy;
int I;
int Direction;
char Screen[20][20];
int Length;
char Ans;
apstring Trash;
apvector <apstring> Words (20);
bool Id [20][20];
//Prototype

 background (int, int& X,int& Y);
void clear ();
void display (int&);
void words (int&);
void direction ();
void left (int);
void up_left (int);
void down_left (int);
void right (int);
void up_right (int);
void down_right (int);
void down (int);
void up (int);
//CONSTANTS-----------------------
//MAIN----------------------------
void main ()
{
clrscr ();
randomize ();
Num=0;
do
{


cout<<"Enter the dimensions of the matrix you desire: ";
cout<<"Across 2-20: ";
cin>>Y;
cout<<endl<<"Down 2-20: ";
cin>>X;
cout<<endl;
if(X>Y)
 Blah=X;
if(Y>X)
 Blah=Y;

words (Num);
background(1,X,Y);
direction ();



// placement -----------------------------------------------------


display(X);

gotoxy(2,25);
cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
}while(Ans=='Y'||Ans=='y');

};

void background (int J,int& X, int& Y)
{int I;
 int Q;
 clrscr ();
 if (J==0)
	for(I=0;I<X;I++)
	 for(Q=0;Q<Y;Q++)
		Screen[I][Q]=(char)random(26)+65;
	else
	 for(I=0;I<X;I++)
		for(Q=0;Q<Y;Q++)
		 Screen[I][Q]='*';
};

void clear    ()
{int I;
 int Q;
	for(I=0;I<20;I++)
	 for(Q=0;Q<20;Q++)
	 {Screen[I][Q]=' ';
		Id[I][Q]=false;}	  };

void display (int& X)
{int I;
 int Q;

 for(I=0;I<20;I++)
	 {for(Q=0;Q<20;Q++)
		 cout<<Screen[I][Q]<<" ";
		cout<<endl;}
	for(I=0;I<X;I++)
	 {gotoxy(50,I+1);
		cout<<Words[I];}		};

void words (int& Num)
{int I;
	cout<<"How many words do you want to enter (1-20)? "<<endl;
	cin>>Num;
	getline(cin,Trash);
	clrscr();
		for(I=0;I<Num;I++)
		{ do
			{cout<<"Word "<<I+1<<". ";
			 getline(cin,Words[I]);
			}while(Words[I].length()<2||Words[I].length()>8);
		}
};


void direction (int& Num);
{
for(Word=0;Word<Num;Word++)
{
Direction=random(8)+1;



		switch (Direction)
{case 1 :  right ();
 case 2 :  left ();
 case 3 :  up ();
 case 4 :  up_left ();
 case 5 :  down_right ();
 case 6 :   up_right ();
 case 7 :  down ();
 case 8 :  down_left ();
}



};

void left (int);
	{do                   //backwards horizontal
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y);
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy][Wx+Words[Word].length()-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;}
					break;
};


void up_left (int);
{  do                   //backward \
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy=Wy-1;}
					 break;
};


void down_left (int);
 do                   //backward /
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);


				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy++;}
				 break;}


void right (int);
{
do                   //forward horizontal
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y);
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;}
					 break;
};

void up_right (int);
									//forward /
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy=Wy-1;}
					 break;



void down_right (int);
{do                   //forward \
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy++;}
					 break;
};

void down (int);
{do                   //forward vertical
				 {
				 Empty=0;
				 Wx=random(Y);
				 Wy=1;//random(X-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy+=1;}
					 break;



};


void up (int);
{do                   //backwards vertical
				 {
				 Empty=0;
				 Wx=random(Y);
				 Wy=random(X-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy=Wy-1;}
					 break;

}