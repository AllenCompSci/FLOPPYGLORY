//Michael Crookston
//Program #25
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
apvector<apstring>WordBank(20);
apstring Word;
char Repeat, Letter, Again;
int I, Switch, X, Y, A, J, B, Valid;
//Program
void main ()
{do
{randomize();
clrscr();
for(A=0;A<21;A++)
	for(B=0;B<21;B++)
		Placement[A][B]=' ';
for(I=0;I<20;I++)
	{clrscr();
	cout<<"Enter 5-Letter Word #"<<I+1<<":  ";
	cin>>Word;
	if(Word.length()==5)
		WordBank[I]=Word;
	else
		{cout<<endl<<endl<<"5 Letters Only!";
		I--;
		getch();}}
/*for(I=0;I<20;I++)
	WordBank[I]="ABCDE";*/
for(I=0;I<20;I++)
	{Word=WordBank[I];
	do
		{Switch=random(8);
		X=random(20)+1;
		Y=random(20)+1;
		Valid=0;
		Repeat='n';
		switch(Switch)
		{case 0 : if(X>16)
								Repeat='y';
							else
								{for(J=0;J<5;J++)
									{if(Placement[X+J][Y]==' '|| Placement[X+J][Y]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X+J][Y]=Word[J];}
							break;
		 case 1 : if(X<5)
								Repeat='y';
							else
								{for(J=0;J<5;J++)
									{if(Placement[X-J][Y]==' '|| Placement[X-J][Y]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X-J][Y]=Word[J];}
							break;
		 case 2 : if(Y>16)
								Repeat='y';
							else
								{for(J=0;J<5;J++)
									{if(Placement[X][Y+J]==' ' || Placement[X][Y+J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X][Y+J]=Word[J];}
							break;
		 case 3 : if(Y<5)
								Repeat='y';
							else
								{for(J=0;J<5;J++)
									{if(Placement[X][Y-J]==' ' || Placement[X][Y-J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X][Y-J]=Word[J];}
							break;
		 case 4 : if(X>16)
								Repeat='y';
							if(Y>16)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<5;J++)
									{if(Placement[X+J][Y+J]==' ' ||Placement[X+J][Y+J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X+J][Y+J]=Word[J];}
							break;
		 case 5 : if(X<5)
								Repeat='y';
							if(Y<5)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<5;J++)
									{if(Placement[X-J][Y-J]==' '||Placement[X-J][Y-J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X-J][Y-J]=Word[J];}
							break;
		 case 6 : if(X<5)
								Repeat='y';
							if(Y>16)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<5;J++)
									{if(Placement[X-J][Y+J]==' '||Placement[X-J][Y-J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X-J][Y+J]=Word[J];}
							break;
		 case 7 : if(X>16)
								Repeat='y';
							if(Y<5)
								Repeat='y';
							if(Repeat!='y')
								{for(J=0;J<5;J++)
									{if(Placement[X+J][Y-J]==' '||Placement[X-J][Y-J]==Word[J])
										Valid++;
									else
										{J=500;
										Repeat='y';}}
								if(Valid==5)
									for(J=0;J<5;J++)
										Placement[X+J][Y-J]=Word[J];}
							break;}}
	while(Repeat=='y');}
clrscr();
/*for(I=0;I<20;I++)
	for(J=0;J<20;J++)
		if(Placement[I+1][J+1]==' ')
			Placement[I+1][J+1]=random(26)+97;*/
for(I=0;I<20;I++)
	{for(J=0;J<20;J++)
		{if(Placement[I+1][J+1]==20)
			{Letter=random(26)+97;
			cout<<Letter;}
		 else
			cout<<Placement[I+1][J+1]<<" ";}
	 cout<<endl;}
gotoxy(70,1);
cout<<"WORDBANK";
for(I=0;I<20;I++)
	{gotoxy(70,I+2);
	cout<<WordBank[I];}
getch();
clrscr();
cout<<"Do you want to play again (Y/N):  ";
cin>>Again;}
while(Again=='y' || Again=='Y');
}
