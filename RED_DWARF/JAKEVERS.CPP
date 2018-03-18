//KRIS BICKHAM/ANDREW DOBBS
//GAME PROJECT
//DUE ONE DAY
//PERIOD 6
//MR. BAKER
//
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
#include <stdio.h>
//Struct---------------
struct fire
{
int Exist;
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
int Color;
apvector <fire> Fire_E;
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
ifstream Write;
ofstream Read;

//Arrays----------------
apvector <int> StarX (40);
apvector <int>  StarY (40);
apvector <fire> Fire_U (15);
apvector <user> Ship (1);
apvector <int> Time(1);
apvector <int> Wave(1);
apvector <enemy> Bad (20);
apvector <int> Delay (5);
apvector <int> Temp (2);
apvector <int> Blah (1);
apvector <long> Scoring (3);
//apvector <int> Names (10);
apstring Names [10];
apstring Trash;
apvector <int> Scores (10);
char Name [20];
apvector <int> Difficulty (1);
//PROTOTYPES------------
void gr_start (int&, int&, int&);
void star ();
void init ();
void movement ();
void background();
void fire();
void fireB ();
void wave ();
void badguy ();
void weaponselect ();
void collision ();
void game ();
void title();
void help();
void menu();
void score();
void highscore();
void convert(apstring);
void gameover();
void open();
//MAIN------------------
void main ()
{

gr_start(grdriver, grmode, errorcode);
open();
menu();






 getch();
};


//FUNCTIONS

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
int Num;

	if(Delay[0]==150)
		 {
					for(Num=0;Num<40;Num++)
						{putpixel(StarX[Num],StarY[Num],0);



							if(StarY[Num]>395)
							{ StarX[Num]=random(639)+1;
								StarY[Num]=10;};

								StarY[Num]+=2;
								putpixel(StarX[Num],StarY[Num],15);
						 };
			Delay[0]=0; };
};


//Init
void init ()
{ int I;
	int T;
	int Num;


randomize();
clrscr();
cleardevice();
setbkcolor(0);
do
{
cout<<"Enter Difficulty 1-Easy 2-Normal 3-Hard 4-Impossible 5-Special Wave Mode";
cout<<endl;
cin>>Difficulty[0];

}while(Difficulty[0]<1||Difficulty[0]>5);

clrscr();
gr_start(grdriver, grmode, errorcode);
cleardevice();

Scoring[0]=0000000000;
Scoring[1]=20;
Scoring[2]=20;
Blah[0]=0;
Ship[0].Y=350;
Ship[0].X=400;
Delay[0]=0;
Delay[1]=0;
Delay[2]=0;
Delay[3]=0;
Delay[4]=0;
Temp[0]=0;
Temp[1]=0;
Wave[0]=0;
Ship[0].W=1;
Ship[0].Life=5;
Ship[0].Hit=0;
Time[0]=random(100)+100;
// Star Random values
	for(Num=0;Num<40;Num++)
	 { StarX[Num]=random(639)+1;
	 StarY[Num]=random(479)+1;
	 };
// User Weapon init
	 for(Num=0;Num<15;Num++)
	{
		Fire_U[Num].Exist=0;
		Fire_U[Num].Xpos=0;
		Fire_U[Num].Ypos=0;
	};

background (); // draws the permanent background.
//Sets Enemy Data
for(I=0;I<20;I++)
	{
				 Bad[I].Exist=0;
				 Bad[I].X=0;			//Set  enemy stats
				 Bad[I].Y=0;
				 Bad[I].Life=1;
				 Bad[I].Hit=0;
				 Bad[I].Color=random(7)+1;
				 Bad[I].Fire_E.resize(5);

			for (T=0;T<5;T++)
			 {

				 Bad[I].Fire_E[T].Exist=0;
				 Bad[I].Fire_E[T].Xpos=0;
				 Bad[I].Fire_E[T].Ypos=0;
			 }
		};


};




// Movement
void movement ()
{


			 setfillstyle(0,0);
				bar(Ship[0].X-5,Ship[0].Y-15,Ship[0].X+5,Ship[0].Y+25);
				switch (getch())
					{case 72:if(Ship[0].Y>20)
									 Ship[0].Y=Ship[0].Y-6;
									 break;
					 case 77:if(Ship[0].X<620)
									 Ship[0].X+=6;
									 break;
					 case 75:if(Ship[0].X>20)
									 Ship[0].X=Ship[0].X-6;
									 break;
					 case 80:if(Ship[0].Y<360)
									 Ship[0].Y+=6;
									 break;
					 case 32:if(Temp[0]!=15)
										fire();
									 if(Temp[0]==15)
										{Ship[0].Hit+=1;
										 Blah[0]=1;
										 collision();
										};
										break;
					 case 9:weaponselect();
								 break;
					 case 27:Ship[0].Y=9000;
									break;
					};
				 setfillstyle(1,2);
				 fillellipse(Ship[0].X,Ship[0].Y,3,3);
				 fillellipse(Ship[0].X,Ship[0].Y+7,4,4);
				 fillellipse(Ship[0].X,Ship[0].Y+17,5,5);

};


//Background
void background ()
{
setfillstyle(1,4);
bar(0, 400, 639, 479);
bar(0, 0,  3, 400);
bar(0, 0, 640, 3);
bar(637, 0, 640, 400);
setcolor(8);
setfillstyle(1,7);
	 fillellipse(45, 440, 38,38);
	 setfillstyle(1,15);
	 pieslice(45,440,Temp[0]*24,360,35);
	 setfillstyle(1,1);
	 pieslice(45,440,0,Temp[0]*24,35);
	 setfillstyle(1,7);
	 fillellipse(45,440,25,25);
	 moveto(30, 435);
	 settextstyle(0, 0, 1);
	 outtext("Temp");

setfillstyle(1,15);
bar(100,450,243,470);
bar(248,450,400,470);
moveto(103,456);
setcolor(0);
outtext("Score: 0000000000  Kills to charge: 0");
moveto(104,456);
setcolor(12);

outtext("Score: 0000000000  Kills to charge: 0");
setcolor(0);
moveto(420, 410);
outtext("Lazer Cannons ");
moveto(420, 430);
outtext("Anti-matter beam ");
moveto(420, 450);
outtext("EM Missles ");

moveto(225,402);
setcolor(14);
outtext("Damage");
moveto(100,402);
outtext("0%");
moveto(370,402);
outtext("100%");
setfillstyle(1,12);
bar(100,420, 400,440);
};

//Fire
void fire ()
{
int I;

for(I=0;I<15;I++)
	if (Fire_U[I].Exist==0)
		{
		 Fire_U[I].Exist=1;
		 Fire_U[I].Xpos=Ship[0].X;
		 Fire_U[I].Ypos=Ship[0].Y;
		 I=14;
		 Temp[1]+=1;
		};




};




//Fire B
void fireB ()
{
int I;
int T;
int Num;


if(Temp[1]!=Temp[0])
 {	Temp[0]=Temp[1];
	 setcolor(0);
	 setfillstyle(1,7);
	 fillellipse(45, 440, 38,38);
	 setfillstyle(1,15);
	 pieslice(45,440,Temp[0]*24,360,35);
	 setfillstyle(1,1);
	 if(Temp[0]>6)
	 {	setfillstyle(1,9);
			if(Temp[0]>9)
			 {	setfillstyle(1,14);
					if(Temp[0]>12)
					 {	setfillstyle(1,12);

					 }
			 }
	 }
	 pieslice(45,440,0,Temp[0]*24,35);

	 setfillstyle(1,7);

	 if(Temp[0]>13)
		setfillstyle(1,12);

	 fillellipse(45,440,25,25);
	 moveto(30, 435);
	 settextstyle(0, 0, 1);
	 outtext("Temp");
	 if(Temp[0]==15)
		{ setfillstyle(1,12);
			fillellipse(45,440,38,38);
			moveto(17, 435);
			settextstyle(0, 0, 1);
			outtext("OVERHEAT");
		};

	};





//if (Delay[0]==20||Delay[0]==40||Delay[0]==60)
 //	 {
			for(I=0;I<15;I++)
				if(Fire_U[I].Exist==1)
						{  setfillstyle(0,0);

								bar(Fire_U[I].Xpos,Fire_U[I].Ypos-3,Fire_U[I].Xpos+4,Fire_U[I].Ypos);
							 Fire_U[I].Ypos-=1;

							 setfillstyle(1,	Ship[0].W);




									bar(Fire_U[I].Xpos,Fire_U[I].Ypos-3,Fire_U[I].Xpos+4,Fire_U[I].Ypos);

							if(Fire_U[I].Ypos<10)
								{	Fire_U[I].Exist=0;
									setfillstyle(0,7);
									bar(Fire_U[I].Xpos,Fire_U[I].Ypos-3,Fire_U[I].Xpos+4,Fire_U[I].Ypos);
									Temp[1]-=1;
									Fire_U[I].Xpos=0;
									Fire_U[I].Ypos=0;
									Fire_U[I].Exist=0;
								};

							};


	// };
};

//ENEMY GENERATION
void  wave ()
{ int Formation;
	int Type;
	int I;
	int N;
	int Form;


Form=random(3);

for(N=0;N<8;N++)
{	I=random(20);
			if(Bad[I].Exist==0)
			 {

								switch (Form)
			{ case 0:
										 Bad[I].Exist=1;
										 Bad[I].Life=0;
										 badguy();

										 Bad[I].Life=1;
										 Bad[I].X=((N+1)*120); //placing enemies horizontally
										 Bad[I].Y=13;
										 Bad[I].Color=random(7)+1;


									break;


				case 1:      Bad[I].Exist=1;
										 Bad[I].Life=1;
										 badguy();
										 Bad[I].Life=1;

										 Bad[I].X=random(580)+40; //placing horizontally
										 Bad[I].Y=0-(N*10);
										 Bad[I].Color=random(7)+1;

									break;


				case 2:
										 Bad[I].Exist=1;

										 badguy();
										 Bad[I].Life=1;

										 Bad[I].X=random(620)+10;; //placing horizontally
										 Bad[I].Y=0;
										 Bad[I].Color=random(7)+1;


									break;
				};
		};
	};
};


//ENEMY MOVEMENT
void badguy ()
{
int T;
int Q;
int W;
int I;
int Num;

W=random(4);
if (Delay[2]==500)
 { I=random(20);
		if(Bad[I].Exist==1)
		 { T=random(5);
			 if(Bad[I].Fire_E[T].Exist==0)
					if(W<=2)
							{ Bad[I].Fire_E[T].Exist=1;
								Bad[I].Fire_E[T].Xpos=Bad[I].X;
								Bad[I].Fire_E[T].Ypos=Bad[I].Y;
							 };
			};

	};


if(Delay[0]==20||Delay[0]==40||Delay[0]==60||Delay[0]==30||Delay[0]==10)
	for (I=0;I<20;I++)


			 for(T=0;T<5;T++)
				{


				if (Bad[I].Fire_E[T].Exist==1)
					if (Bad[I].Fire_E[T].Ypos>11)
					 {setfillstyle(1,0);

						bar(Bad[I].Fire_E[T].Xpos,Bad[I].Fire_E[T].Ypos-3,Bad[I].Fire_E[T].Xpos+4,Bad[I].Fire_E[T].Ypos);
						Bad[I].Fire_E[T].Ypos++;

						setfillstyle(1,15);

						bar(Bad[I].Fire_E[T].Xpos,Bad[I].Fire_E[T].Ypos-3,Bad[I].Fire_E[T].Xpos+4,Bad[I].Fire_E[T].Ypos);
						if(Bad[I].Fire_E[T].Ypos>390)
						 {setfillstyle(1,0);


bar(Bad[I].Fire_E[T].Xpos,Bad[I].Fire_E[T].Ypos-3,Bad[I].Fire_E[T].Xpos+4,Bad[I].Fire_E[T].Ypos);
							Bad[I].Fire_E[T].Exist=0;
							Bad[I].Fire_E[T].Xpos=0;
							Bad[I].Fire_E[T].Ypos=0;

						 };
						};
					};


if (Delay[0]==80||Delay[0]==40)
	for (I=0;I<20;I++)


			if (Bad[I].Exist==1)
				{setfillstyle(1,0);
					if(Bad[I].Y>15)
					{

					 bar(Bad[I].X, Bad[I].Y, Bad[I].X+3, Bad[I].Y-10);
					 bar(Bad[I].X-3,Bad[I].Y-10,Bad[I].X+6,Bad[I].Y-7);

					};
					Bad[I].Y+=1;
					W=random(5-Difficulty[0]);
						if(Difficulty[0]==5)
							W=random(4);

					if(W<1)
					 if(Ship[0].X>Bad[I].X)
						 Bad[I].X++;

					if(W<1)
					 if(Ship[0].X<Bad[I].X)
					 Bad[I].X-=1;


						setfillstyle(1,Bad[I].Color);
					if(Bad[I].Y>15)
						{bar(Bad[I].X, Bad[I].Y, Bad[I].X+3, Bad[I].Y-10);
						 bar(Bad[I].X-3,Bad[I].Y-10,Bad[I].X+6,Bad[I].Y-7);
						};


					if (Bad[I].Life==0)
							 {setfillstyle(1,0);
								bar(Bad[I].X, Bad[I].Y, Bad[I].X+3, Bad[I].Y-10);
								bar(Bad[I].X-3,Bad[I].Y-10,Bad[I].X+6,Bad[I].Y-7);

								Bad[I].Exist=0;
								Bad[I].Life=0;
								Bad[I].Hit=0;
								Bad[I].X=0;			//Set  enemy stats
								Bad[I].Y=0;


								}
					if (Bad[I].Y>=390)
							{ Bad[I].Exist=0;
								Bad[I].Life=0;
								Bad[I].Hit=0;
								setfillstyle(1,0);
								bar(Bad[I].X, Bad[I].Y, Bad[I].X+3, Bad[I].Y-10);
								bar(Bad[I].X-3,Bad[I].Y-10,Bad[I].X+6,Bad[I].Y-7);

								Bad[I].X=0;			//Set  enemy stats
								Bad[I].Y=0;
							}
				}
};

void weaponselect()
{switch (Ship[0].W)
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
						Ship[0].W++;
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
						Ship[0].W++;
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
						Ship[0].W=1;
						break;

	}
};


//COLLISION DETECTION
void collision ()
{
int I;
int Num;
int J;
int T;

if(Temp[0]==15&&Blah[0]==1)
{ setfillstyle(1,12);
	bar(100,420, 400,440);
	setfillstyle(1,14);
	bar(105,425,105+58*(Ship[0].Hit)   ,435);
	Blah[0]=0;
};
if(Scoring[1]==0&&Blah[0]==1)
{ setfillstyle(1,12);
	bar(100,420, 400,440);
	setfillstyle(1,14);
	bar(105,425,105+58*(Ship[0].Hit)   ,435);
	Blah[0]=0;
};


for (I=0;I<20;I++)
	if(Bad[I].Exist==1)
	 {if(Ship[0].Y-3==Bad[I].Y+2)
			if(Ship[0].X>=Bad[I].X-14 && Ship[0].X<=Bad[I].X+14)
				{setfillstyle(1,12);
				 bar(100,420, 400,440);
				 setfillstyle(1,14);
				 Ship[0].Hit=5;
				 bar(105,425,105+58*(Ship[0].Hit)   ,435);
				 setfillstyle(1,0);
				 bar(Bad[I].X, Bad[I].Y, Bad[I].X+10, Bad[I].Y-2);
				 Bad[I].Exist=0;
				 Bad[I].Life=0;
				 Bad[I].Hit=0;
				 Bad[I].X=0;			//Set  enemy stats
				 Bad[I].Y=0;
				 };
			 for(T=0;T<5;T++)
				if(Bad[I].Fire_E[T].Exist==1)
					if(Bad[I].Fire_E[T].Ypos>=Ship[0].Y+3)
						 if(Bad[I].Fire_E[T].Ypos<=Ship[0].Y+17)
							if(Bad[I].Fire_E[T].Xpos>=Ship[0].X-8)
								if(Bad[I].Fire_E[T].Xpos<=Ship[0].X+4)
									{Ship[0].Hit++;
									 setfillstyle(1,0);

									 bar(Bad[I].Fire_E[T].Xpos,Bad[I].Fire_E[T].Ypos-3,Bad[I].Fire_E[T].Xpos+4,Bad[I].Fire_E[T].Ypos);
									 Bad[I].Fire_E[T].Exist=0;
									 Bad[I].Fire_E[T].Xpos=0;
									 Bad[I].Fire_E[T].Ypos=0;
									 setfillstyle(1,12);
									 bar(100,420, 400,440);
									 setfillstyle(1,14);
									 bar(105,425,105+58*(Ship[0].Hit)   ,435);
									};
};







for (J=0;J<15;J++)
 if(Fire_U[J].Exist==1)
	 for (I=0;I<20;I++)
		 if (Bad[I].Exist==1)
			 if(Fire_U[J].Ypos-1>=Bad[I].Y-10&&Fire_U[J].Ypos-2<=Bad[I].Y)
				if(Fire_U[J].Xpos+4>=Bad[I].X-3&&Fire_U[J].Xpos<=Bad[I].X+6)
				 { setfillstyle(1,0);
					bar(Bad[I].X, Bad[I].Y, Bad[I].X+3, Bad[I].Y-10);
					bar(Bad[I].X-3,Bad[I].Y-10,Bad[I].X+6,Bad[I].Y-7);
					bar(Fire_U[J].Xpos,Fire_U[J].Ypos-3,Fire_U[J].Xpos+4,Fire_U[J].Ypos);
					Bad[I].Life-=1;
					Fire_U[J].Ypos=0;
					Fire_U[J].Xpos=0;
					Fire_U[J].Exist=0;
					Temp[1]-=1;
					Scoring[0]+=random(13)+20;
					Scoring[1]-=1;
					score();
					};




	if(Ship[0].Hit==5)
	 {setfillstyle(1,14);
		bar(20,15,620,400);
		moveto(250,200);
		setcolor(1);
		settextstyle(0, 0, 2);
		outtext("Game Over");
		getch();
		getch();
		Ship[0].Y=9000;
		gameover();

	 };



	};

void game ()
{

init();


do
{

star ();

if (kbhit())
movement ();
if (Delay[0]==10||Delay[0]==20||Delay[0]==40||Delay[0]==60||Delay[0]==70)
fireB();

Delay[0]++;
Delay[1]++;
Delay[2]++;
Delay[3]++;
Delay[4]++;
collision();

badguy();

if (Delay[1]>300)
	 Delay[1]=0;

if (Delay[2]>502)
		Delay[2]=0;



if (Delay[3]==5000-(Difficulty[0]*1000))
		{wave();
			Delay[3]=0;
			}
if(Delay[4]==1000);
	Delay[4]=0;


}while(Ship[0].Y>10&&Ship[0].Y<380&&Ship[0].X>10&&Ship[0].X<630);

};

void title()
{
setbkcolor(3);
cleardevice();
//TOP BAR
//Fill
setfillstyle(1,9);
bar(3,3,637,18);
//Shade
setcolor(1);
line(2,19,637,19);
line(637,2,637,19);
//Highlight
setcolor(11);
line(2,2,637,2);
line(2,2,2,18);

	//TEXT
	//Shade
	moveto(210,4);
	setcolor(1);
	settextstyle(0,0,2);
	outtext("Red Dwarf v1.0");
	//Highlight
	moveto(207,4);
	setcolor(11);
	outtext("Red Dwarf v1.0");

//BOTTOM WINDOW
//Fill
setfillstyle(1,9);
bar(3,25,637,477);
//Shade
setcolor(1);
line(637,25,637,477);
line(2,477,637,477);
//Highlight
setcolor(11);
line(2,25,637,25);
line(2,25,2,477);

//---------------------ITems
//-------------------New Game
	settextstyle(0,0,2);

//Shade
setfillstyle(1,1);
bar(225,60,415,150);
//Highlight
setfillstyle(1,11);
bar(225,60,414,149);
//Fill
setfillstyle(1,9);
bar(226,61,414,149);
	//TEXT
	//Shade
	moveto(260,95);
	setcolor(1);
	outtext("New Game");
	//Highlight
	moveto(255,95);
	setcolor(11);
	outtext("New Game");
//-------------------High Scores
//Shade
setfillstyle(1,1);
bar(225,160,415,250);
//Highlight
setfillstyle(1,11);
bar(225,160,414,249);
//Fill
setfillstyle(1,9);
bar(226,161,414,249);
	//TEXT
	//Shade
	moveto(238,195);
	setcolor(1);
	outtext("High Scores");
	//Highlight
	moveto(233,195);
	setcolor(11);
	outtext("High Scores");

//-------------------Instructions
//Shade
setfillstyle(1,1);
bar(225,260,415,350);
//Highlight
setfillstyle(1,11);
bar(225,260,414,349);
//Fill
setfillstyle(1,9);
bar(226,261,414,349);
	//TEXT
	//Shade
	moveto(235,295);
	setcolor(1);
	outtext("Game Help ?");
	//Highlight
	moveto(230,295);
	setcolor(11);
	outtext("Game Help ?");

//-------------------Quit
//Shade
setfillstyle(1,1);
bar(225,360,415,450);
//Highlight
setfillstyle(1,11);
bar(225,360,414,449);
//Fill
setfillstyle(1,9);
bar(226,361,414,449);
	//TEXT
	//Shade
	moveto(250,395);
	setcolor(1);
	outtext("Quit Game");
	//Highlight
	moveto(245,395);
	setcolor(11);
	outtext("Quit Game");
};



void help()
{



setbkcolor(3);
setcolor(11);
line(2,2,637,2);
line(2,2,2,18);

setfillstyle(1,9);
bar(3,25,637,477);
setcolor(1);
line(637,25,637,477);
line(2,477,637,477);
setcolor(11);
line(2,25,637,25);
line(2,25,2,477);
setcolor(0);
//User Controls

				 setfillstyle(1,2);
				 setcolor(2);
				 circle(20,35,3);
				 circle(20,35+7,4);
				 circle(20,35+17,5);
				 setfillstyle(1,2);
				 fillellipse(20,35,3,3);
				 fillellipse(20,35+7,4,4);
				 fillellipse(20,35+17,5,5);


settextstyle(0,0,1);
moveto(35,35);
setcolor(1);
outtext("This is your ship, Use the arrow keys to control it, and 'Space' to fire.");
moveto(32,35);
setcolor(11);
outtext("This is your ship, Use the arrow keys to control it, and 'Space' to fire.");

moveto(35,45);
setcolor(1);
outtext("Your goal is to destroy as much of the enemy ships as you can.");
moveto(32,45);
setcolor(11);
outtext("Your goal is to destroy as much of the enemy ships as you can.");
//Damge Help
	moveto(463,55);
	setcolor(14);
	outtext("Damage");
	moveto(332,55);
	outtext("0%");
	moveto(600,55);
	outtext("100%");
	setfillstyle(1,12);
	bar(332,65, 632,85);
moveto(20,65);
setcolor(1);
outtext("This displays your ship's damage level.");
moveto(17,65);
setcolor(11);
outtext("This displays your ship's damage level.");
moveto(20,75);
setcolor(1);
outtext("If your ship is hit five times by enemy");
moveto(17,75);
setcolor(11);
outtext("If your ship is hit five times by enemy");
moveto(20,87);
setcolor(1);
outtext("fire, or collides with the enemy once and it will destroy your ship.");
moveto(17,87);
setcolor(11);
outtext("fire, or collides with the enemy once and it will destroy your ship.");
//Enemy Description
	setfillstyle(1,2);
	bar(20, 117, 20+3, 117-10);
	bar(20-3,117-10,20+6,117-7);
moveto(35,107);
setcolor(1);
outtext("-An enemy ship, its goal is to shoot YOU! Destroy them, and avoid its fire.");
moveto(32,107);
setcolor(11);
outtext("-An enemy ship, its goal is to shoot YOU! Destroy them, and avoid its fire.");
//Temp help

setcolor(8);
setfillstyle(1,7);
	fillellipse(45, 175, 38,38);
setfillstyle(1,15);
	pieslice(45,175,3*24,360,35);
setfillstyle(1,1);
	pieslice(45,175,0,3*24,35);
setfillstyle(1,7);
	fillellipse(45,175,25,25);
	moveto(30, 173);
settextstyle(0, 0, 1);
outtext("Temp");

moveto(78,135);
setcolor(1);
outtext("This is the temperature gauge for your weapon systems. Try not to get");
moveto(75,135);
setcolor(11);
outtext("This is the temperature gauge for your weapon systems. Try not to get");
moveto(86,145);
setcolor(1);
outtext("trigger-happy, because the laser reflection modules can overheat.");
moveto(83,145);
setcolor(11);
outtext("trigger-happy, because the laser reflection modules can overheat.");

setcolor(1);
moveto(90,155);
outtext("Watch your gauge! If your weapons overheat and you fire, it will ");
moveto(87,155);
setcolor(11);
outtext("Watch your gauge! If your weapons overheat and you fire, it will ");

setcolor(1);
moveto(90,165);
outtext("cause damage to your ship.");
moveto(87,165);
setcolor(11);
outtext("cause damage to your ship.");
//Scoring help

setfillstyle(1,15);
bar(100-75,450-230,243-70,470-230);
bar(100-75,450-205,243-70,470-205);
moveto(103-75,456-230);
setcolor(8);
outtext("Score: 0000000000");
moveto(104-75,456-205);
outtext("Kills to charge: 0");

setcolor(12);
moveto(103-77,456-230);
outtext("Score: 0000000000");
moveto(104-77,456-205);
outtext("Kills to charge: 0");

setcolor(1);
moveto(182,226);
outtext("This Panel displays you current total score.");
moveto(180,226);
setcolor(11);
outtext("This Panel displays you current total score.");

setcolor(1);
moveto(182,226+26);
outtext("Once this reaches zero, the damage meter resets!");
moveto(180,226+26);
setcolor(11);
outtext("Once this reaches zero, the damage meter resets!");

//Weapons help

setcolor(8);
moveto(30, 273);
outtext("Lazer Cannons ");
moveto(30, 293);
outtext("Anti-matter beam ");
moveto(30, 313);
outtext("EM Missles ");

setcolor(1);
moveto(182,293);
outtext("Weapons: No real effect, just different pretty colors");
moveto(180,293);
setcolor(11);
outtext("Weapons: No real effect, just different pretty colors");



setcolor(1);
moveto(202,460);
outtext("Press any key to exit help");
moveto(200,460);
setcolor(11);
outtext("Press any key to exit help");
getche();

};


void menu()
{
int Item;
int Move;
int Exit;
int A;
A=0;
Item=0;
Move=0;
Exit=0;
setbkcolor(3);


do
{
setbkcolor(3);
setfillstyle(1,3);
bar(1,1,640,480);
title();

do
{


switch (Item)
{

 case 0:    if(Move==-1)
						{//Inactive
						setfillstyle(1,1);
						bar(225,160,415,250);
						setfillstyle(1,11);
						bar(225,160,414,249);
						setfillstyle(1,9);
						bar(226,161,414,249);
						moveto(238,195);
						setcolor(1);
						outtext("High Scores");
						moveto(233,195);
						setcolor(11);
						outtext("High Scores");
						};
						if(Move==1)
						{//Inactive
						setfillstyle(1,1);
						bar(225,360,415,450);
						setfillstyle(1,11);
						bar(225,360,414,449);
						setfillstyle(1,9);
						bar(226,361,414,449);
						moveto(250,395);
						setcolor(1);
						outtext("Quit Game");
						moveto(245,395);
						setcolor(11);
						outtext("Quit Game");
						};
						//Active
						setfillstyle(1,6);
						bar(225,60,415,150);
						setfillstyle(1,12);
						bar(225,60,414,149);
						setfillstyle(1,4);
						bar(226,61,414,149);
						moveto(260,95);
						setcolor(1);
						outtext("New Game");
						moveto(255,95);
						setcolor(11);
						outtext("New Game");
						break;
	case 1:   if(Move==-1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,260,415,350);
						setfillstyle(1,11);
						bar(225,260,414,349);
						setfillstyle(1,9);
						bar(226,261,414,349);
						moveto(235,295);
						setcolor(1);
						outtext("Game Help ?");
						moveto(230,295);
						setcolor(11);
						outtext("Game Help ?");
						};
						 if(Move==1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,60,415,150);
						setfillstyle(1,11);
						bar(225,60,414,149);
						setfillstyle(1,9);
						bar(226,61,414,149);
						moveto(260,95);
						setcolor(1);
						outtext("New Game");
						moveto(255,95);
						setcolor(11);
						outtext("New Game");
						};
						//Active
						setfillstyle(1,6);
						bar(225,160,415,250);
						setfillstyle(1,12);
						bar(225,160,414,249);
						setfillstyle(1,4);
						bar(226,161,414,249);
						moveto(238,195);
						setcolor(1);
						outtext("High Scores");
						moveto(233,195);
						setcolor(11);
						outtext("High Scores");
						break;
 case 2:    if(Move==-1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,360,415,450);
						setfillstyle(1,11);
						bar(225,360,414,449);
						setfillstyle(1,9);
						bar(226,361,414,449);
						moveto(250,395);
						setcolor(1);
						outtext("Quit Game");
						moveto(245,395);
						setcolor(11);
						outtext("Quit Game");
						};
						 if(Move==1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,160,415,250);
						setfillstyle(1,11);
						bar(225,160,414,249);
						setfillstyle(1,9);
						bar(226,161,414,249);
						moveto(238,195);
						setcolor(1);
						outtext("High Scores");
						moveto(233,195);
						setcolor(11);
						outtext("High Scores");
						};
						//Active
						setfillstyle(1,6);
						bar(225,260,415,350);
						setfillstyle(1,12);
						bar(225,260,414,349);
						setfillstyle(1,4);
						bar(226,261,414,349);
						moveto(235,295);
						setcolor(1);
						outtext("Game Help ?");
						moveto(230,295);
						setcolor(11);
						outtext("Game Help ?");
						break;
 case 3:    if(Move==-1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,60,415,150);
						setfillstyle(1,11);
						bar(225,60,414,149);
						setfillstyle(1,9);
						bar(226,61,414,149);
						moveto(260,95);
						setcolor(1);
						outtext("New Game");
						moveto(255,95);
						setcolor(11);
						outtext("New Game");
						};
						 if(Move==1)
						{
						//Inactive
						setfillstyle(1,1);
						bar(225,260,415,350);
						setfillstyle(1,11);
						bar(225,260,414,349);
						setfillstyle(1,9);
						bar(226,261,414,349);
						moveto(235,295);
						setcolor(1);
						outtext("Game Help ?");
						moveto(230,295);
						setcolor(11);
						outtext("Game Help ?");
						};
						//Active
						setfillstyle(1,4);
						bar(225,360,415,450);
						setfillstyle(1,12);
						bar(225,360,414,449);
						setfillstyle(1,6);
						bar(226,361,414,449);
						moveto(250,395);
						setcolor(1);
						outtext("Quit Game");
						moveto(245,395);
						setcolor(11);
						outtext("Quit Game");
						break;
 };

 do
{
A=0;

		switch (getch())
 {case 72:Move=-1;
					A=1;
					break;
	case 80:Move=1;
					A=1;
					break;
	case 13:Move=10;
					A=1;
					break;
	};

}while(A!=1);



if(Move!=10)
	Item+=Move;

if(Item==-1)
	Item=3;
if(Item==4)
	Item=0;



if (Item==3&&Move==10)
	Exit=1;
if (Item==0&&Move==10)
	Exit=1;
if (Item==2&&Move==10)
	Exit=1;
if (Item==1&&Move==10)
	Exit=1;


}while(Exit!=1);

if(Item==0&&Move==10)
 {	game();
		Exit=0;
		Move=0;
 };
if(Item==1&&Move==10)
 { highscore();
	 Exit=0;
	 Move=0;
 };

if(Item==2&&Move==10)
 { help();
		Exit=0;
		Move=0;
 };
getline(cin,Trash);


}while(Exit!=1);

};


void score ()
{
char buf [10];
setfillstyle(1,15);
settextstyle(0, 0, 1);

bar(167,450,243,470);
bar(315,450,400,470);

moveto(103,456);
setcolor(0);
outtext("Score:             Kills to charge:");
moveto(104,456);
setcolor(12);
outtext("Score:             Kills to charge:");

bar(157,450,243,470);
bar(380,450,400,470);

setcolor(0);
moveto(157,456); //score
sprintf(buf,"%d",Scoring[0]);
outtext(buf);

setcolor(12);
moveto(158,456);
outtext(buf);


setcolor(0);
moveto(382,456); //kils left
sprintf(buf,"%d",Scoring[1]);
outtext(buf);

setcolor(12);
moveto(383,456);
outtext(buf);


if(Scoring[1]==0)
{ Ship[0].Hit=0;
	Blah[0]=1;
	collision();
	Scoring[1]=Scoring[2];
	Scoring[2]+=20;
	Blah[0]=0;
};

};

void highscore ()
{ifstream Read;
 int X;
 int Y;
 char buf [20];
 char Name [10];
 apstring Namen;
settextstyle(0,0,1);
setbkcolor(3);
setcolor(11);
line(2,2,637,2);
line(2,2,2,18);
setfillstyle(1,9);
bar(3,25,637,477);
setcolor(1);
line(637,25,637,477);
line(2,477,637,477);
setcolor(11);
line(2,25,637,25);
line(2,25,2,477);
setcolor(0);

moveto(35,35);
setcolor(1);
outtext("These are the legendary pilots who have given their lives to our cause.");
moveto(31,35);
setcolor(11);
outtext("These are the legendary pilots who have given their lives to our cause.");



Read.open("C:\\Junk\\Score.txt");
for(X=0;X<10;X++)
 {Read>>Names[X];
	Read>>Scores[X];
 }
Read.close();


for(Y=0;Y<10;Y++)
{
		 moveto(20+200,100+(Y*10));
		 setcolor(1);
		 convert(Names[Y]);



		 moveto(17+200,100+(Y*10));
		 setcolor(11);
		 convert(Names[Y]);


		 moveto(20+300,100+(Y*10));
		 sprintf(buf,"%d",Scores[Y]);
		 setcolor(1);
		 outtext(buf);

		 moveto(17+300,100+(Y*10));
		 sprintf(buf,"%d",Scores[Y]);
		 setcolor(11);
		 outtext(buf);
};



getche();
};

void convert (apstring Word)
{int I;
for(I=0;I<Word.length();I++)
 Name[I]=Word[I];

for(I=Word.length();I<20-Word.length();I++)
 Name[I]=' ';
outtext(Name);

setcolor(1);
moveto(202,460);
outtext("Press any key to exit");
moveto(200,460);
setcolor(11);
outtext("Press any key to exit");
delay(500);


};


void gameover ()
{ifstream Read;
 ofstream Write;
 int X;
 int Place;
 int Temp;
 apstring Tempname;
 Place=499;
Temp=0;
Read.open("C:\\Junk\\Score.txt");

for(X=0;X<10;X++)
 {Read>>Names[X];
	Read>>Scores[X];
	 if(Scoring[0]>Scores[X]&&Temp==0)
		 {Place=X;
			Temp=1;
		 };
	}
Temp=0;
Read.close();

										 if(Place!=499)
 {cleardevice();
	cout<<"Enter your name for the high score list less than 10 characters:";
	cout<<endl;
	do
	{
	cin>>Tempname;
	}while (Tempname.length()>10);

	Names[Place]=Tempname;
	Scores[Place]=Scoring[0];

	 Write.open("C:\\Junk\\Score.txt");
	 for(X=0;X<10;X++)
		 {
			 Write<<Names[X]<<endl;
			 Write<<Scores[X]<<endl;

		 };
		Write.close();


 };


};

void open ()
{
 int X;
 int Y;
 int X2;
 int Y2;
 X=315;
 Y=235;
 X2=325;
 Y2=245;
 bar(X,Y,X2,Y2);
 while(X>2)
			{X-=1;
			 Y-=1;
			 X2+=1;
			 Y2+=1;
			 setfillstyle(1,4);
			 bar(X,Y,X2,Y2);
			 delay(10);
			};
setcolor(0);
line(80,40,80,145);
arc(80,65,270,90,26);
line(80,91,106,145);
line(116,40,116,145);
line(116,40,142,40);
line(116,75,135,75);
line(116,145,142,145);
delay(1000);
cleardevice();



};