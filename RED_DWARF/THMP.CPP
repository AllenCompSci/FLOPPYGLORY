//KRIS BICKHAM
//PROB#25
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apmatrix.h>
#include <stdlib.h>
//VARIABLES------------
int Q;
int Empty;
int Tx;
int Ty;
int Wx;
int Wy;
int X;
int I;
int All;
apvector <apstring> Words (20);
bool Id [20][20];
char Screen[20][20];
char Ans;
int Direction;
//CONSTANTS------------
//MAIN
void main ()
{clrscr ();
randomize ();
do
{
Words[0]="Kris0";
Words[1]="Kris1";
Words[2]="Kris2";
Words[3]="Kris3";
Words[4]="Kris4";
Words[5]="Kris5";
Words[6]="Kris6";
Words[7]="Kris7";
Words[8]="Kris8";
Words[9]="Kris9";
Words[10]="Kri10";
Words[11]="Kri11";
Words[12]="Kri12";
Words[13]="Kri13";
Words[14]="Kri14";
Words[15]="Kri15";
Words[16]="Kri16";
Words[17]="Kri17";
Words[18]="Kri18";
Words[19]="Kri19";
//Determining

Direction=2;
// placement -----------------------------------------------------


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

				 for(I=0;I<Words[0].length();I++)
					{Screen[Wy][Wx]=Words[0][I];
					 Id[Wy][Wx]=true;
					 Wx++;}
					 break;

case 2 :do                   //forward verticle
				 {
				 Empty=0;
				 Wx=random(20);
				 Wy=random(16);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy+Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[0].length();I++)
					{Screen[Wy][Wx]=Words[0][I];
					 Id[Wy][Wx]=true;
					 Wy+=1;}
					 break;
case 3 :do                   //backwards horizontal
				 {
				 Empty=0;
				 Wx=random(16);
				 Wy=random(20);
				 for(Q=0;Q<5;Q++)
						if(Id[Wy][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[0].length();I++)
					{Screen[Wy][Wx]=Words[0][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;}
					break;

case 4 : Wy=Wy-1;     //b v
					break;
case 5 : Wx++;
						Wy++; 		   //f \
					break;
case 6 : Wx=Wx-1;     //b \
						Wy=Wy-1;
					break;
case 7 : Wy=Wy-1;
						Wx++;        //f /
					break;
case 8 : Wy=Wy+1;
						Wx=Wx-1;     //b /
					break;}

//----------------------------------------------------------------

clrscr ();
for(I=0;I<20;I++)
{ for(X=0;X<20;X++)
	 cout<<Screen[I][X]<<'.';
 cout<<endl;}


cout<<endl;
cout<<"Do you want to run again? (Y/N): ";
cin>>Ans;
	 }while(Ans=='Y'||Ans=='y');


}

