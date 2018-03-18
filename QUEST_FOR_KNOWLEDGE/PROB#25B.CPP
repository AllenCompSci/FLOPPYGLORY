//Michael Crookston
//Program Name
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<stdlib.h>
//Constants
//Variables
char Placement[21][21];
apvector<apstring>Words(20);
apstring Word;
char Repeat, Again;
int I, Switch, X, Y, A, J, B, Valid, Amount, Width, Length, K, L, M, Rotate;
int Q;
//Program
void main ()
{
do
{Q=0;
Amount=0;
randomize();
clrscr();
do
{clrscr();
cout<<"How many spaces long do you want the puzzle (2-20):  ";
cin>>Width;}
while(Width<2 || Width>20);
do
{clrscr();
cout<<"How many spaces wide do you want the puzzle (2-20):  ";
cin>>Length;}
while(Length<2 || Length>20);
for(A=0;A<Width+1;A++)
	for(B=0;B<Length+1;B++)
		Placement[A][B]=' ';
if(Width>Length)
	{if(Width>8)
		K=8;
	 else
		K=Width;}
else
	{if(Length>8)
		K=8;
	 else
		K=Length;}
L=(Length*Width)/2;
if(L>20)
	L=20;
M=Length*Width;
do
	{clrscr();
	cout<<"How many words do you want to use (1-"<<L<<"):  ";
	cin>>Amount;}
while(Amount<1 || Amount>L);
for(I=0;I<Amount;I++)
	{if(M>K)
		cout<<"Please enter "<<Amount<<" 2-"<<K<<" letter words."<<endl;
	 else
		cout<<"Please enter "<<Amount<<" 2-"<<M<<" letter words."<<endl;
	cout<<"Word # "<<I+1<<"  ";
	cin>>Words[I];
	clrscr();
	if(M<K)
		K=M;
	if(Words[I].length()<2||Words[I].length()>K)
		{I--;
		cout<<"Your word MUST be 2-"<<K<<" letters long!";
		getch();
		clrscr();}
	else
		{M-=Words[I].length();
		cout<<"You have "<<M<<" letter(s) left to use"<<endl;
		if(M<=1)
			{Amount=I+1;
			cout<<"Sorry.  No more words can be entered.";
			getch();
			I=500;}}}
/*for(I=0;I<Amount;I++)
	Words[I]="abcdefgh";*/
for(I=0;I<Amount;I++)
	{Word=Words[I];
	do
		{Switch=random(8);
		X=random(Width)+1;
		Y=random(Length)+1;
		Valid=0;
		Repeat='n';
		switch(Switch)
		{case 0 : if(X>Width-Word.length())
								{Repeat='y';
								Q++;}
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X+J][Y]=Word[J];
										Q=0;}}
							break;

		 case 1 : if(X<Word.length())
								{Repeat='y';
								Q++;}
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X-J][Y]=Word[J];
										Q=0;}}
							break;

		 case 2 : if(Y>Length-Word.length())
								{Repeat='y';
								Q++;}
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X][Y+J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X][Y+J]=Word[J];
										Q=0;}}
							break;

		 case 3 : if(Y<Word.length())
								{Repeat='y';
								Q++;}
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X][Y-J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X][Y-J]=Word[J];
										Q=0;}}
							break;

		 case 4 : if(X>Width-Word.length())
								{Repeat='y';
								Q++;}
							if(Y>Length-Word.length())
								{Repeat='y';
								Q++;}
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y+J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X+J][Y+J]=Word[J];
										Q=0;}}
							break;

		 case 5 : if(X<Word.length())
								{Repeat='y';
								Q++;}
							if(Y<Word.length())
								{Repeat='y';
								Q++;}
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y-J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X-J][Y-J]=Word[J];
										Q=0;}}
							break;

		 case 6 : if(X<Word.length())
								{Repeat='y';
								Q++;}
							if(Y>Length-Word.length())
								{Repeat='y';
								Q++;}
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y+J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X-J][Y+J]=Word[J];
										Q=0;}}
							break;

		 case 7 : if(X>Width-Word.length())
								{Repeat='y';
								Q++;}
							if(Y<Word.length())
								{Repeat='y';
								Q++;}
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y-J]==' ')
										Valid++;
									else
										{J=500;
										Repeat='y';
										Q++;}}
								if(Valid==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										{Placement[X+J][Y-J]=Word[J];
										Q=0;}}
							break;}
		if(Q>100)
			{I=-1;
			Q=0;
			Repeat='n';
			for(A=0;A<Width+1;A++)
				for(B=0;B<Length+1;B++)
					Placement[A][B]=' ';}}
	while(Repeat=='y');}
clrscr();
for(I=0	;I<Width;I++)
	for(J=0;J<Length;J++)
		if(Placement[I+1][J+1]==' ')
			Placement[I+1][J+1]=random(26)+97;
for(I=0	;I<Width;I++)
	{for(J=0;J<Length;J++)
		cout<<Placement[I+1][J+1]<<" ";
	cout<<endl;}
for(I=0; I<Amount; I++)
	{gotoxy(70,I+2);
	cout<<Words[I];}
gotoxy(70,1);
cout<<"WORDBANK";
getch();
clrscr();
cout<<endl<<endl<<"Would you like to do it again (Y/N)"<<endl;
cin>>Again;
}
while(Again=='y' || Again=='Y');
}