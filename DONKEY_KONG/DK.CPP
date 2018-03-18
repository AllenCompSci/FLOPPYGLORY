//George Eleftheriou and Ben Walker
//PD 2
//DONKEY KONG!!!!

//Libraries
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <alloc.h>
#include "bitmap.h"
#include <mem.h>
#include "DBUFFER.h"
#include "DK.h"
#include <time.h>
#include "math2.h"
//Constants

//Struct

//Global Variables
int I;                  //Loop control variable

bool Start;             //Game control variable
bool Exit;              //Exit variable

unsigned long Frame;    //Frame number (used for timing)

M Mario;                //Mario structure

int Mjframe;            //Mario initial "jump" frame

Map Level;              //Level structure

time_t Start_t, Current_t;

int Score;              //The score


unsigned char far *Vidseg = (unsigned char far *)0xA0000000L;  //Video memory segment
unsigned char far Virseg[64000];                               //Buffer memory segment

//Prototype
void start_screen ();
int menu ();
void initialize();
void instructions ();
void drawlevel ();
void loadimage (char *, int, unsigned char far *);


bool mcollide (int, int,   								//X and Y position
							 int,        								//1-6 pixel positions, -1 left vertical, -2 right vertical, -3 first horizontal, -4 second horizontal, -5 third horizontal
							 int,                       //Color
							 unsigned char far *);      //Source

void score (int &);
void highscore (int &);

//Code
void main ()
{
Exit=false;
randomize();
graphinit(GR256);

start_screen ();

while (!Exit)
{
switch (menu())
	{
	case 0: drawlevel();
					Start = true;
					break;
	case 1: instructions();
					break;
	case 2: cleardevice();
					settextstyle(0,0,0);
					setcolor(15);
					outtextxy(20,20,"There will never be any high scores.");
					getch();
					break;
	case 3: Start = false;
					Exit=true;
	}
initialize();

while (Start)
	{

	delay(20);
	Frame++;
	Current_t=time(NULL);

	flip (Virseg,Vidseg);      //PUT THE BUFFER TO THE SCREEN


	transfer(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Mario.Background,Virseg); //REPLACE MARIO'S BACKGROUND


	///////////////////////////JUMPING///////////////////////////////////////
	if (!Mario.Jump)
		{
		if(Mario.Mx > 0)
			loadimage("A:\\MSR.img",0,Mario.Image);
		else
			{
			if(Mario.Mx < 0)
				loadimage("A:\\MSL.img",0,Mario.Image);
			}
		Mario.Mx=0;
		}

	if(Mario.Jump)
		{
		if ((Frame-Mjframe)==10)
			Mario.My=-2;
		if ((Frame-Mjframe)==15)
			Mario.My=-1;
		if ((Frame-Mjframe)==25)
			Mario.My=0;
		if ((Frame-Mjframe)==30)
			Mario.My=+1;
		if (mcollide(Mario.X,Mario.Y,-5,Level.Floor,Virseg))
			{
			Mario.My=0;
			Mario.Jump=false;
			}
		if (Mario.Mx==1)
			loadimage("A:\\MJR.img",0,Mario.Image);
		else
			{
			if(Mario.Mx==-1)
				loadimage("A:\\MJL.img",0,Mario.Image);
			}
		}

	if (mcollide(Mario.X,Mario.Y,-5,255,Virseg) && !Mario.Jump)
		Mario.My=1;
	else
		{
		if(!Mario.Jump)
			Mario.My=0;
		}
	///////////////////////////////////////////////////////////////////////////



	////////////////////////////////MOVEMENT///////////////////////////////////

	if (kbhit())
		{
		switch(getch())
			{
			case 77: if(mcollide(Mario.X,Mario.Y,-5,Level.Floor,Virseg))    								 //Right movement
								{
								Mario.Mx=4;
								}
							 else
								{
								if (Mario.Jump)
									Mario.Mx=1;
								}
								loadimage("A:\\MWR.img",0,Mario.Image);
								break;

			case 75: if(mcollide(Mario.X,Mario.Y,-5,Level.Floor,Virseg))     							 //Left movement
								{
								Mario.Mx=-4;
								}
							 else
								{
								if (Mario.Jump)
									Mario.Mx=-1;
								else
									{
									if (mcollide(Mario.X,Mario.Y,3,255,Virseg))
										Mario.Mx=-4;
									}
								}

								loadimage("A:\\MWL.img",0,Mario.Image);
								break;

			case 32: if(mcollide(Mario.X,Mario.Y,-5,Level.Floor,Virseg) && !Mario.Jump)    //Jumping initialization
								{
								Mario.My=-1;
								Mjframe=Frame;
								Mario.Jump=true;
								}
								break;
			case 27:  do
								{
								gotoxy(7,10);
								cout<<"Exiting the game now";
								gotoxy(7,11);
								cout<<"will lose your progress.";
								gotoxy(7,14);
								cout<<"Are you sure? (Y/N)";
								}
								while (!kbhit());
								Start=getch();

								if (Start==89 || Start==121)
									Start=false;
								clrscr();
								break;

			}
		}

	cutbackground(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Virseg,Mario.Background);

	Mario.X+=Mario.Mx;
	Mario.Y+=Mario.My;

	if (Mario.X < 1)
		Mario.X-=Mario.Mx;
	if (Mario.X > 303)
		Mario.X-=Mario.Mx;
	///////////////////////////////////////////////////////////////////////////

	transfer(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Mario.Image,Virseg);
	score(Score);

	/////////////////////////////DEATH/////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////

	if (mcollide(Mario.X,Mario.Y,3,66,Virseg) || mcollide(Mario.X,Mario.Y,6,66,Virseg) || mcollide(Mario.X,Mario.Y,2,66,Virseg) || mcollide(Mario.X,Mario.Y,5,66,Virseg) ||Mario.Y == 183)
		{
		for (I=0; I<4; I++)
			{
			flip(Virseg,Vidseg);

			transfer(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Mario.Background,Virseg);
			switch(I)
				{
				case 0: loadimage("A:\\MD_1.img",0,Mario.Image);
								break;
				case 1: loadimage("A:\\MD_2.img",0,Mario.Image);
								break;
				case 2: loadimage("A:\\MD_3.img",0,Mario.Image);
								break;
				case 3: loadimage("A:\\MD_4.img",0,Mario.Image);
								break;
				}

			settextstyle(0,0,3);
			setcolor(15);
			outtextxy(50,50,"GAME OVER");

			cutbackground(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Virseg,Mario.Background);
			transfer(Mario.X,Mario.Y,Mario.X+16,Mario.Y+16,Mario.Image,Virseg);

			delay(600);
			}
		Start=false;
		}

	}
 }
}

void start_screen ()
{
int I;

cleardevice();

setbkcolor(0);
settextstyle(0,0,3);
setcolor(7);
outtextxy(22,50,"DONKEY KONG");
settextstyle(0,0,3);
setcolor(1);
outtextxy(24,51,"DONKEY KONG");

settextstyle(0,0,0);
setcolor(15);
outtextxy(22,80,"PRESENTED BY: GEORGE ELEFTHERIOU");
outtextxy(100,90,"AND BEN WALKER");
I=1;
do
	{
	settextstyle(0,0,0);
	if (I%256 == 0)
		I++;
	setcolor(I);
	moveto(210,130);
	outtextxy(60,130,"press any key to continue");
	delay(25);
	I++;
	}
while (!kbhit());

}

void drawlevel ()
{

}

int menu ()
{
int Menu, Key, Key2, Y;

cleardevice();

setbkcolor(0);
settextstyle(0,0,2);

Y=1;

getch();

do
	{
	Key=0;

	if(kbhit())
		Key=getch();

	if (Key == 72)
		Y--;
	if (Key == 80)
		Y++;

	if (Y < 1)
		Y=4;
	if (Y > 4)
		Y=1;


	if (Y == 1)
		{
		setcolor(15);
		Menu=0;
		}
	else
		setcolor(1);

	outtextxy(10,10,"PLAY GAME");

	if (Y == 2)
		{
		setcolor(15);
		Menu=1;
		}
	else
		setcolor(1);

	outtextxy(10,40,"INSTRUCTIONS");

	if (Y == 3)
		{
		setcolor(15);
		Menu=2;
		}
	else
		setcolor(1);

	outtextxy(10,70,"HIGH SCORES");

	if (Y == 4)
		{
		setcolor(15);
		Menu=3;
		}
	else
		setcolor(1);

	outtextxy(10,100,"EXIT");

	}
while (Key!=13);



return Menu;
}

void instructions ()
{
cleardevice();

settextstyle(0,0,2);
setcolor(15);

outtextxy(10,20,"INSTRUCTIONS");

settextstyle(0,0,0);

outtextxy(10,50,"The game is simple.");
outtextxy(10,60,"Do not fall in the pit.");
outtextxy(10,70,"Do not hit the barrels.");
outtextxy(10,80,"Survive for as long as you can.");

outtextxy(10,100,"Spacebar:      Jump");
outtextxy(10,110,"Right arrow:   Move right");
outtextxy(10,120,"Left arrow:    Move left");

getch();

}

bool mcollide (int X, int Y, int Control, int Color, unsigned char far * Source)
{
bool Ans;

Ans=false;

if (Control>0 && Control<7)
	{
	if(Control<4)
		{
		if (Source[((Y+Control+13)*320)+X-1]==Color)
			Ans=true;
		}
	else
		{
		if (Source[((Y+Control+10)*320)+X+16]==Color)
			Ans=true;
		}
	}
else
	{
	if (Control==-1)
		{
		if (Source[((Y+14)*320)+X-1]==Color && Source[((Y+15)*320)+X-1]==Color && Source[((Y+16)*320)+X-1]==Color)
			Ans=true;
		}
	if (Control==-2)
		{
		if (Source[((Y+14)*320)+X+16]==Color && Source[((Y+15)*320)+X+16]==Color && Source[((Y+16)*320)+X+16]==Color)
			Ans=true;
		}
	if (Control==-3)
		{
		if (Source[((Y+14)*320)+X-1]==Color && Source[((Y+14)*320)+X+16]==Color)
			Ans=true;
		}
	if (Control==-4)
		{
		if (Source[((Y+15)*320)+X-1]==Color && Source[((Y+15)*320)+X+16]==Color)
			Ans=true;
		}
	if (Control==-5)
		{
		if (Source[((Y+16)*320)+X-1]==Color && Source[((Y+16)*320)+X+16]==Color)
			Ans=true;
		}
	}

return Ans;

}

void loadimage (char *File, int T, unsigned char far *Dest)
{
ifstream Image;
int A;
unsigned int C;

Image.open(File);
A=0;

do
{
Image>>C;
Dest[A]=C;
if (Dest[A]==T)
	Dest[A]=NULL;
A++;
}
while (!Image.eof());

Image.close();
}

void initialize ()
{
int A,B;

cleardevice();                    //Clears graphics screen
clearmem(Virseg,64000);           //Clears buffer
clearmem(Mario.Background,16*16); //Clears Mario's background

Frame=0;                          //Sets frame number to 0

Mario.Jump=false;                 //Mario is not jumping..

//TEST


loadimage("A:\\MSR.img",0,Mario.Image);
Mario.X=164;
Mario.Y=173;

loadimage("A:\\Floor.img",0,Level.Image);
transfer(1,189,320,199,Level.Image,Virseg);

Level.Floor=4;

for (A=0; A<5; A++)
	{
	B=random(30);
	loadimage("A:\\Barrel1.img",0,Level.Bimage);
	transfer(60*A+B,179,60*A+B+12,189,Level.Bimage,Virseg);
	}

Start_t=time(NULL);

}

void score (int & Score)
{
int Time;

Time=difftime(Current_t,Start_t);

settextstyle(0,0,0);
setcolor(15);

outtextxy(1,1,"You have survived");
outtextxy(5,10,ltos(Time).c_str());
outtextxy(30,10,"seconds");

settextstyle(0,0,2);
setcolor(random(200));
outtextxy(220,10,"SCORE");

Score=Time*20;

setcolor(random(200));
settextstyle(0,0,0);
outtextxy(220,30,ltos(Score).c_str());
}

