//KRIS BICKHAM
//PROB#25
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
int Word;
int Q;
int Empty;
int Wx;
int Wy;
int I;
int Direction;
char Screen[20][20];
char Ans;
apvector <apstring> Words (20);
bool Id [20][20];
//CONSTANTS-----------------------
//MAIN----------------------------
void main ()
{clrscr ();
randomize ();
do
{
for(I=0;I<20;I++)
do
{
cout<<"Enter Word "<<I+1<<"-> ";
getline(cin,Words[I]);
}while(Words[I].length()!=5);
clrscr ();
for(I=0;I<20;I++)
 for(Q=0;Q<20;Q++)
	Screen[I][Q]=(char)random(26)+65;
// placement -----------------------------------------------------
for(Word=0;Word<20;Word++)
{
Direction=random(8)+1;
		switch (Direction)
{case 1 :do                   //forward horizontal
				 {
				 Empty=0;
				 Wx=random(16);
				 Wy=random(20);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;}
					 break;
case 2 :do                   //forward vertical
				 {
				 Empty=0;
				 Wx=random(20);
				 Wy=random(16);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy+Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy+=1;}
					 break;
case 3 :do                   //backwards horizontal
				 {
				 Empty=0;
				 Wx=random(15)+5;
				 Wy=random(20);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy][Wx+5-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;}
					break;
case 4 : do                   //backwards vertical
				 {
				 Empty=0;
				 Wx=random(20);
				 Wy=random(16)+4;
				 for(Q=0;Q<5;Q++)
						if(Id[Wy-Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy=Wy-1;}
					 break;
case 5 : do                   //forward \
				 {
				 Empty=0;
				 Wx=random(16);
				 Wy=random(16);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy+Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy++;}
					 break;
case 6 : do                   //backward \
				 {
				 Empty=0;
				 Wx=random(15)+5;
				 Wy=random(16)+4;
				 for(Q=0;Q<5;Q++)
						if(Id[Wy-Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy=Wy-1;}
					 break;
case 7 : do                   //forward /
				 {
				 Empty=0;
				 Wx=random(16);
				 Wy=random(16)+4;
				 for(Q=0;Q<5;Q++)
						if(Id[Wy-Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy=Wy-1;}
					 break;
case 8 : do                   //backward /
				 {
				 Empty=0;
				 Wx=random(15)+5;
				 Wy=random(16);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy+Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<5;I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy++;}
				 break;}
}


//----------------------------------------------------------------
// displaying screen
for(I=0;I<20;I++)
{for(Q=0;Q<20;Q++)
 cout<<Screen[I][Q]<<' ';
cout<<endl;}

for(I=0;I<20;I++)
 {gotoxy(50,I+1);
	 cout<<Words[I];}

gotoxy(2,25);
cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
// clearing------------------------------------------------------
clrscr ();
for(I=0;I<20;I++)
 for(Q=0;Q<20;Q++)
	{Screen[I][Q]=' ';
	 Id[I][Q]=false;}
}while(Ans=='Y'||Ans=='y');
}

