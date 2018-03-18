// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

apvector<apstring> Words(20);
apvector<apstring> Puzzle(20);
bool Place[20][20];
int Col;
int Row;
int I;
int X;
int Y;
int Word_Num;
int Flag;
void main ()  {
clrscr();
randomize();


Words[0]  = "&****";
Words[1]  = "&****";
Words[2]  = "&****";
Words[3]  = "&****";
Words[4]  = "&****";
Words[5]  = "&****";
Words[6]  = "&****";
Words[7]  = "&****";
Words[8]  = "&****";
Words[9]  = "&****";
Words[10] = "&****";
Words[11] = "&****";
Words[12] = "&****";
Words[13] = "&****";
Words[14] = "&****";
Words[15] = "&****";
Words[16] = "&****";
Words[17] = "&****";
Words[18] = "&****";
Words[19] = "&****";
Word_Num  =0;
X=0;
Y=0;


for(Col=0; Col<20; Col++)
{
	for(Row=0; Row<20; Row++)
	{
		Puzzle[Col]=Puzzle[Col]+char(random(26)+65);
		Place[Col][Row]=false;
	}
}



//	for(Word_Num=0;Word_Num<20;Word_Num++)
//HORIZONTAL R
{
	X=random(20);
	Y=random(20);
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y][X+I])
	 Flag=false;
	}
};

//End HORIZONTAL R

 for(I=0;I<5;I++)
{
	Puzzle[Y][X+I]=Words[Word_Num][I];
	Place[Y][X+I]=true;
};


//
//VERTICAL D

	X=random(20);
	Y=random(16);
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y+I][X])
	 Flag=false;
	}

//end VERTICAL D

 for(I=0;I<5;I++)
{
	Puzzle[Y+I][X]=Words[Word_Num][I];
	Place[Y+I][X]=true;
};

//HORIZONTAL L

	X=random(16)+4;
	Y=random(20);
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y][X-I])
	 Flag=false;
	}

//end HORIZONTAL L

 for(I=0;I<5;I++)
{
	Puzzle[Y][X-I]=Words[Word_Num][I];
	Place[Y][X-I]=true;
};


//VERTICAL U

	X=random(20);
	Y=random(16)+4;
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y-I][X])
	 Flag=false;
	}

//end VERTICAL U

 for(I=0;I<5;I++)
{
	Puzzle[Y-I][X]=Words[Word_Num][I];
	Place[Y-I][X]=true;
};


//DIAGONAL SE

	X=random(16);
	Y=random(16)+4;
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y+I][X+I])
	 Flag=false;
	}
//end DIAGONAL SE

 for(I=0;I<5;I++)
{
	Puzzle[Y+I][X+I]=Words[Word_Num][I];
	Place[Y+I][X+I]=true;
};


//DIAGONAL SW

	X=random(16)+4;
	Y=random(16);
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y+I][X-I])
	 Flag=false;
	}
//end DIAGONAL SW

 for(I=0;I<5;I++)
{
	Puzzle[Y+I][X-I]=Words[Word_Num][I];
	Place[Y+I][X-I]=true;
};


//DIAGONAL NE

	X=random(16);
	Y=random(16)+4;
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[Y-I][X+I])
	 Flag=false;
	}
//end DIAGONAL NE

 for(I=0;I<5;I++)
{
	Puzzle[Y-I][X+I]=Words[Word_Num][I];
	Place[Y-I][X+I]=true;
};


//DIAGONAL NW

	X=random(16)+4;
	Y=random(16)+4;
	Flag=true;

	for(I=0;I<5;I++)
	{
	 if(Place[X-I][Y-I])
	 Flag=false;
	}
//end DIAGONAL NW

 for(I=0;I<5;I++)
{
	Puzzle[X-I][Y-I]=Words[Word_Num][I];
	Place[X-I][Y-I]=true;
};



for(Col=0;Col<20;Col++)
{
	for(Row=0;Row<20;Row++)
	 {
		cout<<Puzzle[Col][Row]<<" ";
	 }
		cout<<endl;

}


getch();
};