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
apvector <apstring> Words (20);
apvector <apstring> Puzzle (20);
bool Key [20][20];
bool Flag;
apstring Word;
apstring Wrd;
int Col;
int Row;
int X;
int Y;
int I;
int J;
int Words_Num;
int Ran_Case;
int Exit;
void main()
{

Words[0]="slave";
Words[1]="fired";
Words[2]="stein ";
Words[3]="crapy ";
Words[4]="cappy ";
Words[5]="mecha";
Words[6]="mechs ";
Words[7]="laser ";
Words[8]="plane ";
Words[9]="plain ";
Words[10]="spade ";
Words[11]="heart ";
Words[12]="fifth ";
Words[13]="third ";
Words[14]="debug ";
Words[15]="lizzy ";
Words[16]="sleep ";
Words[17]="dream ";
Words[18]="scary ";
Words[19]="rings ";


do
{



	clrscr();
/*	for(I=0;I<20;I++)
	Words[I]=" ";
	clrscr ();
	cout<<"Enter twenty, 5-letter words in capital letters."<<endl;
	cout<<"These will be the words that will appear in the puzzle."<<endl;
	for (I=0;I<20;I++)
	 {
		cin>>Wrd;
		Words [I]=Wrd;

		if((Words[I].length()<5)||(Words[I].length()>5))
		 {
			do
			 {
				cout<<"Five-letter words only!"<<endl;
				cin>>Wrd;
				Words[I]=Wrd;
			 }

			while(Words[I].length()!=5);
		 }
	 }
	clrscr();
 */

for(Col=0;Col<20;Col++)
	for(Row=0;Row<20;Row++)
	{
	 Puzzle[Col]=Puzzle[Col]+char(random(26)+65);
	 Key[Col][Row]=false;

	 }



 Words_Num=0;

for(Words_Num=0;Words_Num<20;Words_Num++)

{
 switch(random(8)+1)

	{
			case 1:
				{

					 do
						{
							X=random(20);
							Y=random(16);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X][Y+I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X] [Y+I]=Words [Words_Num] [I];
								Key [X] [Y+I]=true;
							}

							break;
	}
	case 2:
				{

					 do
						{
							X=random(16)+4;
							Y=random(16)+4;
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X][Y-I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X] [Y-I]=Words [Words_Num] [I];
								Key [X] [Y-I]=true;
							}

							break;
	}
		case 3:
				{

					 do
						{
							X=random(16)+4;
							Y=random(16)+4;
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X-I][Y-I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X-I] [Y-I]=Words [Words_Num] [I];
								Key [X-I] [Y-I]=true;
							}

							break;
	}

		case 4:
				{

					 do
						{
							X=random(16);
							Y=random(16);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X+I][Y+I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X+I] [Y+I]=Words [Words_Num] [I];
								Key [X+I] [Y+I]=true;
							}

							break;
	}

		case 5:
				{

					 do
						{
							X=random(20);
							Y=random(16);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X-I][Y+I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X-I] [Y+I]=Words [Words_Num] [I];
								Key [X-I] [Y+I]=true;
							}

							break;
	}

	case 6:
				{

					 do
						{
							X=random(20);
							Y=random(16);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X+I][Y-I])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X+I] [Y-I]=Words [Words_Num] [I];
								Key [X+I] [Y-I]=true;
							}

							break;
	}
	case 7:
				{

					 do
						{
							X=random(16)+4;
							Y=random(20);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X-I][Y])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X-I] [Y]=Words [Words_Num] [I];
								Key [X-I] [Y]=true;
							}

							break;
	}

	case 8:
				{

					 do
						{
							X=random(16)+4;
							Y=random(20);
							Flag=true;

							for(I=0;I<5;I++)
								if(Key[X+I][Y])
									Flag=false;

						 }
							while(!Flag);
							for(I=0;I<5;I++)
							{
								Puzzle[X+I] [Y]=Words [Words_Num] [I];
								Key [X+I] [Y]=true;
							}

							break;
	}







 }
}
for(Col=0;Col<20;Col++)
{
cout<<endl;
}
for(Row=0;Row<20;Row++)
{
		cout<< Puzzle[Col][Row]<<" ";

}


	gotoxy(58,1);
	cout<<"Word Bank"<<endl;
	for (I=0;I<20;I++)
	{
		gotoxy(60,I+3);
		cout<<Words[I]<<endl;
	 }
	gotoxy(1,24);
	cout<<"Press 'ENTER' to get to the menu."<<endl;
	getch();
	clrscr();
	cout<<"If you would like to create another puzzle, press 1 to exit, press 2.."<<endl;
	cin>>Exit;



	}
	while (Exit==2);
}


