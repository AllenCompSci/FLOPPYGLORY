//KRIS BICKHAM
//GR#3
//DUE MON
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <apstring.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
#include <graphics.h>
#include <dos.h>
#include <alloc.h>
//Struct---------------

struct fire
{ int Exist;
	int Xpos;
	int Ypos;
};

struct enemy
{
 int Exist;
 int X;
 int Y;
 int Life;
 int Hit;
};

//VARIABLES------------
int grdriver;
int grmode;
int errorcode;
int X;
int Y;
int Num;
int Delay;
int I;
int DelayB;

//Arrays----------------
apvector <int> StarX (40);
apvector <int>  StarY (40);
apvector <fire> Fire_U (30);

enemy Bad [3][4];


//PROTOTYPES------------
void gr_start (int&, int&, int&);
void star ();
void init ();
void movement ();
void background();
void fire(int , int );
void fireB (int );

void wave ();
void badguy (int);

//MAIN------------------

void main ()
{
init();
wave();


 Bad[1][2].Exist=1;
 Bad[1][2].X=320;
 Bad[1][2].Y=-10;

	do
		{
			star ();
			movement ();
			fireB(Delay);

			badguy(DelayB);

			Delay++;
			DelayB++;

	 if (DelayB>300)
			DelayB=0;
		}while(Y>10&&Y<400&&X>10&&X<630);




getch();
};



//Gr Mode
void gr_start (int& grdriver, int& grmode, int& errorcode)
{	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
	errorcode=graphresult();
		if (errorcode!=grOk)
			{clrscr();
			 cout<<"Error: "<<errorcode;
			 getch();
			 exit(1);
			 };
};



//Star
 void star ()
{
	if(Delay==150)
		 {
					for(Num=0;Num<40;Num++)
						{putpixel(StarX[Num],StarY[Num],0);


							if(StarY[Num]>400)
							{ StarX[Num]=random(639)+1;
								StarY[Num]=1;};

								StarY[Num]+=2;
								putpixel(StarX[Num],StarY[Num],15);
						 };
			Delay=0; };
};



//Init
	void init ()
{ int I;
randomize();
clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();
Y=350;
X=400;
Delay=0;


// Star Random values
	for(Num=0;Num<40;Num++)
	 { StarX[Num]=random(639)+1;
	 StarY[Num]=random(479)+1;
	 };


//Sets Stars
	 for(Num=0;Num<30;Num++)
	{
		Fire_U[Num].Exist=0;
		Fire_U[Num].Xpos=0;
		Fire_U[Num].Ypos=0;
	};

background (); // draws the permanent background.

//Sets Enemy Data -NEW!!!!!!!
 for(I=0;I<3;I++)
	{
		for (Num=0;Num<4;Num++)
		{
				 Bad[I][Num].Exist=0;
				 Bad[I][Num].X=0;			//Set  enemy stats
				 Bad[I][Num].Y=0;
				 Bad[I][Num].Life=I+1;
				 Bad[I][Num].Hit=0;

		};
	};
};


// Movement
void movement ()

{
if(kbhit())
			{ setfillstyle(0,0);
				bar(X,Y,X+10,Y+10);
				switch (getch())
					{case 72:Y=Y-10;
								break;
					 case 77:X+=10;
								break;
					 case 75:X=X-10;
								break;
					 case 80:Y+=10;
								break;
					 case 32:fire(X,Y);
								break;
					};
				 setfillstyle(1,1);
				 bar(X,Y,X+10,Y+10);

			};


};


//Background
void background ()
{
 setfillstyle(1,4);
 bar(0, 400, 640, 480);
 bar(0, 0,  3, 400);
 bar(0, 0, 640, 3);
 bar(637, 0, 640, 400);
 setcolor(0);
 circle(45, 440, 38);
 circle(595, 440, 38);
 moveto(16, 435);
 settextstyle(0, 0, 2);
 outtext("Fuel");
 moveto(565, 435);
 settextstyle(0,0,1);
 outtext("Velocity");

};

//Fire
void fire (int X, int Y)
{
int I;

for(I=0;I<30;I++)
	if (Fire_U[I].Exist==0)
		{
		 Fire_U[I].Exist=1;
		 Fire_U[I].Xpos=X;
		 Fire_U[I].Ypos=Y;
		 I=29;
		};

};


//Fire B
 void fireB (int Delay)
{
	if (Delay==20||Delay==40||Delay==60)
	 {
			for(I=0;I<30;I++)
			 {
					if(Fire_U[I].Exist==1)
						{  putpixel(Fire_U[I].Xpos,Fire_U[I].Ypos,0);
							 putpixel(Fire_U[I].Xpos+1,Fire_U[I].Ypos+1,0);


							 Fire_U[I].Ypos-=1;

							 putpixel(Fire_U[I].Xpos,Fire_U[I].Ypos,6);
							 putpixel(Fire_U[I].Xpos+1,Fire_U[I].Ypos+1,6);
						};


					if(Fire_U[I].Ypos<10)
						{	Fire_U[I].Exist=0;
							putpixel(Fire_U[I].Xpos,Fire_U[I].Ypos, 0);
							putpixel(Fire_U[I].Xpos+1,Fire_U[I].Ypos+1, 0);
							Fire_U[I].Xpos=0;
							Fire_U[I].Ypos=0;
						};
			 };
	 };


};


void  wave ()
{ int Formation;
	int Type;
	int I;
	int N;

Formation=random(3);
Type=random(3);

		switch (Formation)
			{ case 0:  for (N=0;N<4;N++)
									{  Bad[Type][N].Exist=1;
										 Bad[Type][N].X=((N+1)*10)+20; //placing enemies horizontally
										 Bad[Type][N].Y=10;
									};
									break;


				case 1:  for (N=0;N<4;N++)
									{  Bad[Type][N].Exist=1;
										 Bad[Type][N].X=((N+2)*5)+300; //placing horizontally
										 Bad[Type][N].Y=10;
									};
								 break;


				case 2: 	for (N=0;N<4;N++)
									{  Bad[Type][N].Exist=1;
										 Bad[Type][N].X=((N+3)*20)+200; //placing horizontally
										 Bad[Type][N].Y=10;
									};
									break;

				};


};





void badguy (int Delay)
{

if (Delay==80)
	{	for (I=0;I<3;I++)
			for (Num=0;Num<4;Num++)
				if (Bad[I][Num].Exist==1)
				 { setfillstyle(1,0);
					 bar(Bad[I][Num].X, Bad[I][Num].Y, Bad[I][Num].X+10, Bad[I][Num].Y-2);

					 Bad[I][Num].Y+=(1+I);

					 setfillstyle(1,I+1);
					 bar(Bad[I][Num].X, Bad[I][Num].Y,  Bad[I][Num].X+10,   Bad[I][Num].Y-2);
				 };
	 };


};



//************************************
//

//NOTES:  4/25/01
// ADDED TO INIT:
//   							Sets initial enemy stats... ect
// ADDED FUNCTIONS:
// 									WAVE
// 									BADGUY
//************************************

