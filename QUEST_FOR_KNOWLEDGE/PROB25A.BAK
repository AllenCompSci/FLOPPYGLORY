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
char Repeat;
int I, Switch, X, Y, A, J, B, Five;
char Again;
//Program
void main ()
{
do{
randomize();
clrscr();


for(A=0;A<21;A++)
	for(B=0;B<21;B++)
		Placement[A][B]=' ';

for(I=0;I<20;I++)
	{
	cout<<"Please enter 20 2-8  letter words "<<endl;
	cout<<"Word # "<<I+1<<"  ";
	cin>>Words[I];
		clrscr();
	if(Words[I].length()<2||Words[I].length()>8)
	{
	I=I-1;
	cout<<"Your word MUST be 2-8 letters long!";
	getch();
	clrscr();
	}
	}
/*
for(I=0;I<20;I++)
{
Words[I]="ab";
}
*/

for(I=0;I<20;I++)
	{Word=Words[I];
	do
		{Switch=random(8);
		X=random(20)+1;
		Y=random(20)+1;
		Five=0;
		Repeat='n';
		switch(Switch)
		{case 0 : if(X>16)
								Repeat='y';
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y]==' '||Placement[X+J][Y]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X+J][Y]=Word[J];}
							break;

		 case 1 : if(X<8)
								Repeat='y';
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y]==' '||Placement[X-J][Y]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X-J][Y]=Word[J];}
							break;

		 case 2 : if(Y>13)
								Repeat='y';
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X][Y+J]==' '||Placement[X][Y+J]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X][Y+J]=Word[J];}
							break;

		 case 3 : if(Y<8)
								Repeat='y';
							else
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X][Y-J]==' '||Placement[X][Y-J]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X][Y-J]=Word[J];}
							break;

		 case 4 : if(X>14)
								Repeat='y';
							if(Y>13)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y+J]==' '||Placement[X+J][Y+J]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X+J][Y+J]=Word[J];}
							break;

		 case 5 : if(X<8)
								Repeat='y';
							if(Y<8)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y-J]==' '||Placement[X-J][Y-J]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X-J][Y-J]=Word[J];}
							break;

		 case 6 : if(X<8)
								Repeat='y';
							if(Y>13)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X-J][Y+J]==' '||Placement[X-J][Y+J]==Word[J])
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X-J][Y+J]=Word[J];}
							break;

		 case 7 : if(X>13)
								Repeat='y';
							if(Y<8)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<Words[I].length();J++)
									{if(Placement[X+J][Y-J]==' '||Placement[X+J][Y-J]==' ')
										Five++;
									else
										{J=500;
										Repeat='y';}}
								if(Five==Words[I].length())
									for(J=0;J<Words[I].length();J++)
										Placement[X+J][Y-J]=Word[J];}
							break;}}
	while(Repeat=='y');}

for(I=0	;I<20;I++)
{for(J=0;J<20;J++)
if(Placement[I+1][J+1]==' ')
Placement[I+1][J+1]=random(26)+97;
}

for(I=0	;I<20;I++)
{for(J=0;J<20;J++)

cout<<Placement[I+1][J+1]<<" ";
cout<<endl;
}

for(I=0; I<20; I++)
{
gotoxy(70,I+1);
cout<<Words[I];
}

for(I=0; I<20; I++)
{
gotoxy(58,I+1);
cout<<"Word # "<<I+1<<" ";
}

cout<<endl<<endl<<"Would you like to do it again (y/n)"<<endl;
cin>>Again;

}
while(Again=='y'||Again=='Y');



getch();
}
