//Rebecca Russell
//6th
//Mr.Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<stdlib.h>
#include<apvector.h>
//Constant
char H =3;
char D =4;
char C =5;
char S =6;
int F =48;
//Variable
int Ans;
int Number;
int R;
int I;
int I2;
int K;
apvector <apstring> Hearts (13);
apvector <apstring> Diamonds (13);
apvector <apstring> Clubs (13);
apvector <apstring> Spades (13);
apvector <bool> Cardh (13);
apvector <bool> Cardd (13);
apvector <bool> Cardc (13);
apvector <bool> Cards (13);

//Prototype
void switchcase ();
void heart ();
void diamond ();
void club ();
void spade ();
void boolion ();
void main ()
{clrscr ();
do
{clrscr();
randomize ();
boolion ();
do
 {cout<<"How many hands of cards would you like to view(1-4)?"<<endl;
	cin>>Number;
 }
while ((Number>4) || (Number<1));
clrscr();
for(K=1; K<=Number; K++)
{cout<<"Hand "<<K<<endl;
	switchcase ();
 cout<<endl<<endl;
}
cout<<endl<<endl<<"Do you want to run the program again(1=yes, 2=no)?"<<endl;
cin>>Ans;
}
while(Ans==1);

getch();
};
void switchcase ()
{int Q;
for (Q=0; Q<7; Q++)
 {R=random (4) + 1;
 switch (R)
	{case 1:  heart ();
					break;
	 case 2:  diamond ();
					break;
	 case 3:  club ();
					break;
	 case 4:  spade ();
					break;
}
Q;}}
void boolion ()
{for (I=0; I<13; I++)
 {Cardh[I]=false;
	Cardd[I]=false;
	Cardc[I]=false;
	Cards[I]=false;
 }
}

void heart ()
{I=random (13);
 Hearts[0]="Ace";
 Hearts[1]="Jack";
 Hearts[10]="10";
 Hearts[11]="Queen";
 Hearts[12]="King";
 for(I2=2; I2<10; I2++)
	Hearts[I2]=I2 + F;
 if (Cardh[I]==false)
	{Cardh[I]=true;
	 cout<<Hearts[I]<<H<<"  ";
	}
 else
	heart ();
}

void diamond ()
{I=random (13);
 Diamonds[0]="Ace";
 Diamonds[1]="Jack";
 Diamonds[10]="10";
 Diamonds[11]="Queen";
 Diamonds[12]="King";
 for(I2=2; I2<10; I2++)
	Diamonds[I2]=I2 + F;
 if (Cardd[I]==false)
	{Cardd[I]=true;
	 cout<<Diamonds[I]<<D<<"  ";
	}
 else
	diamond ();
}

void club ()
{I=random (13);
 Clubs[0]="Ace";
 Clubs[1]="Jack";
 Clubs[10]="10";
 Clubs[11]="Queen";
 Clubs[12]="King";
 for(I2=2; I2<10; I2++)
	Clubs[I2]=I2 + F;
 if (Cardc[I]==false)
	{Cardc[I]=true;
	 cout<<Clubs[I]<<C<<"  ";
	}
 else
	club ();
}

void spade ()
{for (I=0; I<13; I++)
	Spades[I]=true;
 I=random (13);
 Spades[0]="Ace";
 Spades[1]="Jack";
 Spades[10]="10";
 Spades[11]="Queen";
 Spades[12]="King";
 for(I2=2; I2<10; I2++)
	Spades[I2]=I2 + F;
 if (Cards[I]==false)
	{Cards[I]=true;
	 cout<<Spades[I]<<S<<"  ";
	}
 else
	 spade ();
}

