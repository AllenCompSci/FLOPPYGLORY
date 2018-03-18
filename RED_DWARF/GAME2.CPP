//KRIS BICKHAM
//GR#3
//DUE MON
//PERIOD 6
//MR. BAKER
//											PRESS ESC TO GENERATE ENEMIS
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

struct user
{
 int X;
 int Y;
 int Life;
 int Hit;
 int W;
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
int DelayC;
int Score;


//Arrays----------------
apvector <int> StarX (40);
apvector <int>  StarY (40);
apvector <fire> Fire_U (30);
apvector <user> Ship (1);
enemy Bad [3][4];


//PROTOTYPES------------
void gr_start (int&, int&, int&);
void star ();
void init ();
void movement ();
void background();
void fire();
void fireB (int);
void wave ();
void badguy (int);
void weaponselect ();
void collision ();

//MAIN------------------

void main ()
{
init();


	do
		{
			star ();
			movement ();
			fireB(Delay);



			Delay++;
			DelayB++;

	 if (DelayB>300)
			DelayB=0;


	 if (DelayB==300)
		 DelayC++;
	// if (DelayC==200)
		 //	wave();



		badguy(DelayB);




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
Score=0;
gr_start(grdriver, grmode, errorcode);
cleardevice();
Ship[1].Y=350;
Ship[1].X=400;
Delay=0;
Ship[1].W=1;
Ship[1].Life=5;
Ship[1].Hit=0;


// Star Random values
	for(Num=0;Num<40;Num++)
	 { StarX[Num]=random(639)+1;
	 StarY[Num]=random(479)+1;
	 };



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
				 Bad[I][Num].Life=1;
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
					 case 32:fire();
								break;
					 case 9:weaponselect();
								 break;
					 case 27: wave();
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
 bar(0, 400, 639, 479);
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
 moveto(420, 410);
 outtext("Lazer Cannons ");
 moveto(420, 430);
 outtext("Anti-matter beam ");
 moveto(420, 450);
 outtext("EM Missles ");
 moveto(1,1);
 setcolor(8);
 outtext("Score");
 setfillstyle(1,12);
 bar(100,420, 400,440);
};

//Fire
void fire ()
{
int I;

for(I=0;I<30;I++)
	if (Fire_U[I].Exist==0)
		{
		 Fire_U[I].Exist=1;
		 Fire_U[I].Xpos=Ship[1].X;
		 Fire_U[I].Ypos=Ship[1].Y;
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
						{  setfillstyle(0,0);
							 bar(Fire_U[I].Xpos-2,Fire_U[I].Ypos-3,Fire_U[I].Xpos+2,Fire_U[I].Ypos);

							 Fire_U[I].Ypos-=1;

							switch (Ship[1].W)
							 {case 1: setfillstyle (1,4);
												break;
								case 2: setfillstyle (1,5);
												break;
								case 3: setfillstyle (1,15);
												break;

							};
							 collision();
							 bar(Fire_U[I].Xpos-2,Fire_U[I].Ypos-3,Fire_U[I].Xpos+2,Fire_U[I].Ypos);


						};


					if(Fire_U[I].Ypos<10)
						{	Fire_U[I].Exist=0;
							setfillstyle(0,0);
							bar(Fire_U[I].Xpos-2,Fire_U[I].Ypos-3,Fire_U[I].Xpos+2,Fire_U[I].Ypos);

							Fire_U[I].Xpos=0;
							Fire_U[I].Ypos=0;
							Fire_U[I].Exist=0;
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
										 Bad[Type][N].Life=0;
										 badguy(Delay);

										 Bad[Type][N].Life=1;
										 Bad[Type][N].X=((N+1)*120); //placing enemies horizontally
										 Bad[Type][N].Y=13;

									};

									break;


				case 1:  for (N=0;N<4;N++)
									{  Bad[Type][N].Exist=1;
										 Bad[Type][N].Life=1;
										 badguy(Delay);
										 Bad[Type][N].Life=1;

										 Bad[Type][N].X=310; //placing horizontally
										 Bad[Type][N].Y=0-(N*10);

									};
									break;


				case 2: 	for (N=0;N<4;N++)
									{  Bad[Type][N].Exist=1;
										 Bad[Type][N].Life=1;
										 badguy(Delay);
										 Bad[Type][N].Life=1;

										 Bad[Type][N].X=random(620)+10;; //placing horizontally
										 Bad[Type][N].Y=13;


									};

									break;

				};


};





void badguy (int Delay)
{

if (Delay==80)
	{	for (I=0;I<3;I++)
			for (Num=0;Num<4;Num++)
			 {

					if (Bad[I][Num].Exist==1)
						{setfillstyle(1,0);

						 if(Bad[I][Num].Y>10)
							bar(Bad[I][Num].X, Bad[I][Num].Y, Bad[I][Num].X+10, Bad[I][Num].Y-2);

						 Bad[I][Num].Y+=(1+I);

						 setfillstyle(1,I+1);

						 if(Bad[I][Num].Y>10)
							bar(Bad[I][Num].X, Bad[I][Num].Y,  Bad[I][Num].X+10,   Bad[I][Num].Y-2);

						 if (Bad[I][Num].Life==0)
							 {
								setfillstyle(1,0);
								bar(Bad[I][Num].X, Bad[I][Num].Y, Bad[I][Num].X+10, Bad[I][Num].Y-2);
								Bad[I][Num].Exist=0;
								Bad[I][Num].Life=0;
								Bad[I][Num].Hit=0;
								Bad[I][Num].X=0;			//Set  enemy stats
								Bad[I][Num].Y=0;

							 };

						 if (Bad[I][Num].Y>=390)
							{ Bad[I][Num].Exist=0;
								Bad[I][Num].Life=0;
								Bad[I][Num].Hit=0;
								setfillstyle(1,0);
								bar(Bad[I][Num].X, Bad[I][Num].Y, Bad[I][Num].X+10, Bad[I][Num].Y-2);
								Bad[I][Num].X=0;			//Set  enemy stats
								Bad[I][Num].Y=0;
							};
					 };





			};
	 };





};

void weaponselect()
{switch (Ship[1].W)
	 {case 1: moveto(420, 450);
						setcolor(4);
						outtext("<EM Missiles>");
						moveto(420, 450);
						setcolor(0);
						outtext("EM Missiles");
						moveto(420, 410);
						setcolor(4);
						outtext("Lazer Canons");
						moveto(420, 410);
						setcolor(0);
						outtext("<Lazer Canons>");
						Ship[1].W++;
						break;
		case 2: moveto(420, 410);
						setcolor(4);
						outtext("<Lazer Canons>");
						moveto(420, 410);
						setcolor(0);
						outtext("Lazer Canons");
						moveto(420, 430);
						setcolor(4);
						outtext("Anti-matter beam");
						moveto(420, 430);
						setcolor(0);
						outtext("<Anti-matter beam>");
						Ship[1].W++;
						break;
		case 3: moveto(420, 430);
						setcolor(4);
						outtext("<Anti-matter beam>");
						moveto(420, 430);
						setcolor(0);
						outtext("Anti-matter beam");
						moveto(420, 450);
						setcolor(4);
						outtext("EM Missiles");
						setcolor(0);
						moveto(420, 450);
						outtext("<EM Missiles>");
						Ship[1].W=1;
						break;

	}
};


void collision ()
{
int I;
int Num;
int J;

for (I=0;I<3;I++)
		for (Num=0;Num<4;Num++)
				if (Bad[I][Num].Exist==1)
					for (J=0;J<30;J++)
						if(Fire_U[J].Ypos==Bad[I][Num].Y)
							 if(Fire_U[J].Xpos>=Bad[I][Num].X&&Fire_U[J].Xpos<=Bad[I][Num].X+10)
								 { Bad[I][Num].Life-=1;
									 Fire_U[J].Ypos=0;
									 Fire_U[J].Xpos=0;
									 Fire_U[J].Exist=0;
									 gotoxy(1,1);
									 Score+=500;
									 cout<<"Score: "<<Score;
									};


};



