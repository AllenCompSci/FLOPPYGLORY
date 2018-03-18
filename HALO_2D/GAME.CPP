/*Comment Section
James Catalano
Game

1st period
*/
//Library Section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <apstring.h>
#include <apvector.h>
#include <stdlib.h>
#include <alloc.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "bitmap.h"
#include "gmouse.h"
//Structure Section
struct Bullets
	{
	int BulX,BulY;//bullets X and Y coordinates
	bool Damage;//sees if the bullet should still do damage after colision
	char Direct;//what direction the bullet is fired
	bool Flag;//checks to see if bullet is still on screen
	};
struct E_move
	{
	int Step; //makes the character look like he is walking
	int X,Y; //player location on the screen based on image
	bool Fire; //finds out if player shoots so the gun will fire
	int Clip; //Number of bullets that have been fired
	int Move; //controls user movement
	apvector <Bullets> E_bullet; //controls enemy bullet fire
	int Damage; //damage counter for enemies
	char Type; //type of enemy on screen
	int Left, Right; //farthest left or right the enemy can go;
	char Direct; //direction the enemy will walk
	};
struct My_Move
	{
	bool Dead; //controls if the player is dead or not
	bool Flagl,Flagr; //controls if the player can move left or right
	int Step; //makes the character look like he is walking
	int X,Y; //player location on the screen based on image
	bool Fire; //finds out if player shoots so the gun will fire
	apvector <Bullets> Bullet; //controls the firing of bullets
	int Clip; //Number of bullets that have been fired
	int Move; //controls user movement
	bool Jump; //controls if the user wants to jump or not
	bool Platjump; //controls if the user wants to jump on a platform
	int J; //Maximum height to which the user can jump
	int H; //makes the user actually jump
	bool Crouch; //lets the user crouch
	int Damage; //damage counter for main character
	char Direct; //direction the player is shooting
	int Ground; //ground that the player falls to after jumping
	};
struct Bounds
	{
	bool Flagu, Flagd, Flagr, Flagl;  //bool flags for directional boundaries
	};
struct Levels
	{
	apvector <int> Up;   //Up boundaries for level
	apvector <int> Down;//Down boundaries for level
	apvector <int> Left;//Left boundaries for level
	apvector <int> Right;//Right boundaries for level
	apvector <E_move> Enemy;//Enemy data based on level
	int Plats;//How many platforms on a given level
	int Peeps;//How many bad guys on a given level
	};
//Const Section
const apstring P1="A:\\part1.bmp";    // I used these b/c I'm too lazy to
const apstring P2="A:\\part2.bmp";    // Retype them all the time
const apstring P3="A:\\part3.bmp";    // :D
const apstring P4="A:\\part4.bmp";
const apstring P5="A:\\part5.bmp";
const apstring P6="A:\\part6.bmp";
const apstring P7="A:\\part7.bmp";


//Global Variable Section
int Case; //Remebers what 'button' you clicked on.
int X, Y; //Controls the X and Y coordinates of the body parts
int L; //Controls how many times to loop the body parts

apvector <Levels> Level (1);//apvector that holds info on all the levels and enemies
int grdriver, grmode, errorcode; //Starts graphics mode
int A,B,C; //workhorse variables
apvector <E_move> Enemies (3); //controls enemies and their movements
My_Move My;// controls main characters actions
apstring Rounds;//how many bullets the player has left
apstring Reload; //the word reload to be on screen when player is reloading
apstring Moveon; //tells the player to move to the end of the level to advance
int Co; // color of the background
int Check;//checks to see if damage changes to change health bar
int Repeat; //sees if the player wants to play again
apstring Damage_counter; //amount of damage player has left
apstring Scr; //screen that appears between the levels
apstring End; //Appears if you beat the game
apstring Die; //Appears if you lose the game
Bounds F; //countrols boundaries for platforms
bool Death;//checks to see if all enemies are dead
int Choice;//checks to see which level info to get when making level
//Prototype Section
void gr_start(int&, int&, int&);   //starts graphics mode
void player_movement(My_Move&); //controls player movement
void player_respawn(My_Move&);  //makes the player appear on screen
void enemy_respawn(apvector <E_move>&,apvector <Levels>,int);//spawns enemies
void bullet_fire(apvector <Bullets>&, int&, bool&); //fires weapons
void enemy_fire(apvector <Bullets>&, int&, bool&); //fires enemy weapons
void enemy_movement(E_move&); //controls enemy movement
void change(int, apstring&); //changes ints to apstrings
void edamage(Bullets&, E_move&);//controls damage for enemies
void damage(Bullets&, My_Move&);//controls damage for character
void boundary (apvector <int>,apvector <int>, int, bool&, bool&);//controls players left and right boundaries
void h_boundary (apvector <int>,apvector <int>, int, bool&);//controls left and right boundaries
void v_boundary (apvector <int>,apvector <int>, int, bool&, bool&); //controls up and down boundaries
void platforms(My_Move&,Bounds&,apvector <Levels>,int);//controls boundaries for platforms
void life(My_Move&);//puts a health bar on the screen
void get_data (apvector <Levels>&);//gets level and enemy data from dat file
void make_level(apvector <Levels>, int&);//draws the level on the screen
void draw_me (My_Move);//draws the player on the screen after every move
//Main Section
void main()
{
randomize();
gr_start(grdriver, grmode, errorcode);
graphinit(GR16);
//*****Initializes Menu*****\\
do{
Case=0;
L=0;

image Menu;
image generic;
image expload;
image flag;
Menu.open("A:\\halo2d2.bmp");
expload.open("A:\\12.bmp");
Menu.draw(0,0);
//outtextxy(0,10,"PLEASE HIT A BUTTON, NOT SPACE!@!@1");
delay(500);

//*****If you hit the secret button..******\\
/*if(getch()==32)
	{
	expload.draw(536,310,TRANSPARENT,15);
	delay(300);
	setfillstyle(1,0);
	bar(522,299,570,377);
	do
	{
		delay(250);
		L++;

		switch(random(6)+1)
			{
			case 1:generic.open(P1);
						 break;
			case 2:generic.open(P2);
						 break;
			case 3:generic.open(P3);
						 break;
			case 4:generic.open(P4);
						 break;
			case 5:generic.open(P5);
						 break;
			case 6:generic.open(P6);
						 break;
			case 7:generic.open(P7);
						 break;
			}
	X=random(600);
	Y=random(400);
	expload.draw(X,Y,TRANSPARENT,15);
	delay(150);
	bar(X,Y,X+(28),Y+(40));
	generic.draw(X,Y,TRANSPARENT,15);
	}while(L<10);
} */
//*********Initializes Mouse****************\\
SetMouse();
ShowMouse();
setfillstyle(1,0);
flag.open("A:\\flag.bmp");

//*****Puts a flag by the 'buttons'*********\\
do
{
delay(200);
if(GetMouseX()>=257&&GetMouseY()>=268&&GetMouseX()<=382&&GetMouseY()<=315)
	{
	flag.draw(220,270,TRANSPARENT,15);
	bar(240,390,270,442);
	bar(227,330,257,382);

	if(GetMouseButton()==true)
		Case=1;
	}
if(GetMouseX()>=257&&GetMouseY()>=338&&GetMouseX()<=382&&GetMouseY()<=365)
	{
	flag.draw(227,330,TRANSPARENT,15);
	bar(220,270,250,322);
	bar(240,390,270,442);

	if(GetMouseButton()==true)
		Case=2;
	}
if(GetMouseX()>=257&&GetMouseY()>=388&&GetMouseX()<=382&&GetMouseY()<=415)
	{
	flag.draw(240,390,TRANSPARENT,15);
	bar(220,270,250,322);
	bar(227,330,257,382);

	if(GetMouseButton()==true)
		Case=3;
	}
}while(Case==0||GetMouseButton()==false);
cleardevice();
//*****Close*****\\
Menu.close();
generic.close();
expload.close();
flag.close();

//********Chooses the option you want*******\\
switch(Case)
	{
	case 3: outtextxy(10,10,"hi");
					exit(1);
					break;

//************************************
//**********spawns characters*********
	case 1:
					HideMouse();
					cleardevice();
					get_data(Level);
					player_respawn(My);
					//enemy_respawn(Enemy,350);
					//enemy_respawn(Grunt,441);
					Choice=0;
					//delay(3000);
					enemy_respawn(Enemies,Level,Choice); //just added
					Co=0;
					//My.Stop=false;
//**********sets up background********
					setbkcolor(Co);
					setfillstyle(1,4);
					//bar(50,240,250,270);
					//bar(390,240,590,270);
					bar(0,440,640,480);
					make_level(Level,Choice);
					image Man1;
					image Cortana;
					image Maan1;
					Reload="Reloading...";
					Moveon="Please advance to Cortana to move to next level";
					Scr="Lock and Load.  Prepare for Next Level.";
					End="Congratulations.  You Beat the Game. Press any Key to Replay or Esc to End";
					Die="You Lose. You Have Let Humanity Down. Press any Key to Replay or Esc to End";
					outtextxy(200,200,Scr.c_str());
					delay(5000);
//**********game play*****************
					do{
						//do{
//**********enemy movement************
							Death=true;
							for(B=0; B<Enemies.length(); B++)
								{
								if(Enemies[B].Damage>0)
									{
									Death=false;
									enemy_movement(Enemies[B]);
									}
								}
							for(C=0; C<Enemies.length(); C++)
								{
								if(Enemies[C].Clip>-1)
									enemy_fire(Enemies[C].E_bullet,Enemies[C].Clip,Enemies[C].Fire);
								}
							if(Death==true)
								{
								setcolor(10);
								outtextxy(110,120,Moveon.c_str());
								//line(300,0,300,480);
								Cortana.open("A:\\Cortana.bmp");
								Cortana.draw(500,383,TRANSPARENT,15);
								Cortana.close();
								if(My.X>=450&&Choice!=12)
									{
									cleardevice();
									outtextxy(200,200,Scr.c_str());
									delay(5000);
									cleardevice();
									Choice++;
									setfillstyle(1,4);
									bar(0,440,640,480);
									make_level(Level,Choice);
									player_respawn(My);
									enemy_respawn(Enemies,Level,Choice);
									Check=0;
									}
								if(Choice==12&&My.X>450)
									{
									My.Dead=true;
									}
								}
//**********bullet firing*************
							if(My.Clip>-1)
								{
								bullet_fire(My.Bullet,My.Clip,My.Fire);
								}
//**********jumping*******************
							//boundary(Up,Down,My.Y,Flagu,Flagd);
							platforms(My,F,Level,Choice); //just added
							if(My.Damage<1)
								{
								My.Jump=false;
								My.Platjump=false;
								}

							if(My.Jump==true||My.Platjump==true)
								{
								setcolor(Co);
								bar(My.X,My.Y,My.X+42,My.Y+70);
								My.Y-=My.H;
								if(My.J>=My.Y)
									My.H=-5;
								if(My.Y>=My.Ground)
									{
									My.Platjump=false;
									My.Jump=false;
									My.H=5;
									}
								Man1.open("A:\\1.bmp");
								Maan1.open("A:\\Crouch1.bmp");
								if(My.Crouch==false)
									Man1.draw(My.X,My.Y,TRANSPARENT,15);
								else
									Maan1.draw(My.X,My.Y+13,TRANSPARENT,15);
								Man1.close();
								Maan1.close();

								}
//**********slows down game after enemy death****
							//if(Enemy.Damage<1&&My.Fire==false)
							//	delay(30);
//**********couts player damage*******
							if(My.H==5||My.H==-5)
								{
								if(My.Damage!=Check)
									{
									life(My);
									}
								Check=My.Damage;
								setfillstyle(1,Co);
								bar(540,20,640,60);
								setcolor(7);
								change(19-My.Clip,Rounds);
								outtextxy(600,20,Rounds.c_str());
								if(My.Clip==19)
									outtextxy(540,30,Reload.c_str());
								}
//************************************
							//}while(!kbhit());
//**********player movement***********
						if(kbhit())
							{
							My.Move=getch();
							if(My.Move==0)
								My.Move=getch();
							}
						while(kbhit())
							getch();
						gotoxy(30,1);
						//clreol();
						//gotoxy(30,1);
						//cout<<My.Move;
						//setcolor(random(15));
						//outtextxy(200,10,Reload.c_str());
						//if(My.Damage>0&&My.Move!=27)
						player_movement(My);
						}while(My.Dead==false);
//************************************

					if(My.Dead==true&&Choice!=12)
						{
						setcolor(10);
						cleardevice();
						outtextxy(15,200,Die.c_str());
						delay(2000);
						Repeat=getch();
						cleardevice();
						}
					else if(My.Dead==true&&Choice==12)
						{
						setcolor(10);
						cleardevice();
						outtextxy(15,200,End.c_str());
						delay(2000);
						Repeat=getch();
						cleardevice();
						}
					break;
	case 2: gotoxy(1,1);
					HideMouse();
					cleardevice();
					cout<<"Controls:"<<endl<<endl<<endl;
					cout<<"W:           Jump"<<endl<<endl;
					cout<<"A:           Move Left"<<endl<<endl;
					cout<<"S:           Toggle Crouch Mode"<<endl<<endl;
					cout<<"D:           Move Right"<<endl<<endl;
					cout<<"Arrow Keys:  Shoot in Direction of Arrow"<<endl<<endl;
					cout<<endl<<endl<<"Hit any key to return to menu or Esc to quit";
					getch();
					My.Move=0;
					cleardevice();
					break;
	}
	}while(Repeat!=27);
}//end

//Function Section

void gr_start(int& grdriver, int& grmode, int& errorcode)
	{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
		clrscr();
		cout<<"Error Code # "<<errorcode<<endl;
		cout<<"Press Return to Continue";
		getch();
		exit(1);
		}
	};//grstart
//**********************************
//**********************************
void get_data(apvector <Levels>& Level)
	{
	ifstream File;
	int Num,I,J;
	File.open("A:\\final.dat");

	File>>Num;
	Level.resize(Num);
	for(I=0; I<Level.length(); I++)
		{
		File>>Level[I].Plats;
		Level[I].Up.resize(3);
		Level[I].Down.resize(3);
		Level[I].Left.resize(3);
		Level[I].Right.resize(3);
		for(J=0; J<Level[I].Plats; J++)
			{
			File>>Level[I].Left[J]>>Level[I].Down[J]>>Level[I].Right[J];
			File>>Level[I].Up[J];
			}
		File>>Level[I].Peeps;
		Level[I].Enemy.resize(4);
		for(J=0; J<Level[I].Peeps; J++)
			{
			File>>Level[I].Enemy[J].Type>>Level[I].Enemy[J].X>>Level[I].Enemy[J].Y;
			File>>Num;
			Level[I].Enemy[J].E_bullet.resize(Num);
			File>>Level[I].Enemy[J].Clip>>Level[I].Enemy[J].Damage;
			File>>Level[I].Enemy[J].Left>>Level[I].Enemy[J].Right;
			}
		}
	File.close();
	};

void make_level(apvector <Levels> Level, int& C)
	{
	int I;
	setfillstyle(1,4);
	for(I=0; I<Level[C].Plats; I++)
		{
		bar(Level[C].Left[I],Level[C].Down[I],Level[C].Right[I],Level[C].Up[I]);
		}
	};

//**********************************
//**********************************
void v_boundary(apvector <int> Up,apvector <int> Down,int Y,bool& Flagu,bool& Flagd)
	{
	int I;
	for(I=0; I<Up.length(); I++)
		{
		if(Y<Up[I]&&Y>Up[I]-5)
			Flagu=false;
		//else
			//Flagu=true;
		}
	for(I=0; I<Down.length(); I++)
		{
		if(Y>Down[I]&&Y<Down[I]+5)      //369>240+70   369<240+75
			Flagd=false;
		//else
			//Flagd=true;
		}
	};

void h_boundary(apvector <int> Left,apvector <int> Right,int X,bool& Flag)
	{
	int I;
	for(I=0; I<Left.length(); I++)
		{
		if(X>Left[I]&&X<Right[I])
			{
			Flag=true;
			//setcolor(random(16));
			//outtextxy(10,10,Reload.c_str());
			}
		}
	}

void platforms(My_Move& My, Bounds& F,apvector <Levels> Level, int C)
	{
	apvector <int> Down (Level[C].Plats);
	apvector <int> Up (Level[C].Plats);
	apvector <int> Left (Level[C].Plats);
	apvector <int> Right (Level[C].Plats);
	//Down[0]=240-75;
	//Up[0]=270;
	//Left[0]=50-40;
	//Right[0]=250;
	//Left[1]=390-40;
	//Right[1]=590;
	int I;
	for(I=0; I<Level[C].Plats; I++)
		{
		Down[I]=Level[C].Down[I]-75;
		Up[I]=Level[C].Up[I];
		Left[I]=Level[C].Left[I]-42;
		Right[I]=Level[C].Right[I];
		}

	bool Flag;
	Flag=false;
	F.Flagd=true;
	F.Flagu=true;

	h_boundary(Left,Right,My.X,Flag);
	v_boundary(Up,Down,My.Y,F.Flagu,F.Flagd);

	if(Flag==true)
		{
		if(F.Flagu==false)
			My.H=-5;
		if(F.Flagd==false)
			{
			My.Jump=false;
			My.H=5;
			My.Ground=My.Y;
			}
		}
	else if(Flag==false)
		{
		if(F.Flagd==false&&My.Ground!=369)
			{
			My.Jump=true;
			My.H=-5;
			My.J=My.Y;
			My.Ground=369;
			}
		}

//*******************************
My.Flagl=true;
My.Flagr=true;
Flag=false;
h_boundary(Down,Up,My.Y,Flag);
if(Flag==true)
	v_boundary(Left,Right,My.X,My.Flagr,My.Flagl);

//*******************************
	};

void life(My_Move& My)
	{
	image full,half,none,neg1,neg2,neg3,neg4,neg5,neg6,neg7,neg8;
	full.open("A:\\full.bmp");
	half.open("A:\\half.bmp");
	none.open("A:\\no.bmp");
	neg1.open("A:\\minus1.bmp");
	neg2.open("A:\\minus2.bmp");
	neg3.open("A:\\minus3.bmp");
	neg4.open("A:\\minus4.bmp");
	neg5.open("A:\\minus5.bmp");
	neg6.open("A:\\minus6.bmp");
	neg7.open("A:\\minus7.bmp");
	neg8.open("A:\\dead.bmp");

	setfillstyle(1,0);
	bar(481,54,640,108);

	switch(My.Damage)
		{
		case 10: full.draw(481,54,TRANSPARENT,0);
						 break;
		case 9: half.draw(481,54,TRANSPARENT,0);
						break;
		case 8: none.draw(481,54,TRANSPARENT,0);
						break;
		case 7: neg1.draw(481,54,TRANSPARENT,0);
						break;
		case 6: neg2.draw(481,54,TRANSPARENT,0);
						break;
		case 5: neg3.draw(481,54,TRANSPARENT,0);
						break;
		case 4: neg4.draw(481,54,TRANSPARENT,0);
						break;
		case 3: neg5.draw(481,54,TRANSPARENT,0);
						break;
		case 2: neg6.draw(481,54,TRANSPARENT,0);
						break;
		case 1: neg7.draw(481,54,TRANSPARENT,0);
						break;
		default: neg8.draw(481,54,TRANSPARENT,0);
						 break;
		}

	full.close();
	half.close();
	none.close();
	neg1.close();
	neg2.close();
	neg3.close();
	neg4.close();
	neg5.close();
	neg6.close();
	neg7.close();
	neg8.close();
	};
//**********************************

void draw_me(My_Move My)
	{
	image Man1,Man2,Maan1,Maan2;
	if(My.Crouch==false)
		{
		if(My.Step%2==1)
			{
			Man1.open("A:\\1.bmp");
			Man1.draw(My.X,My.Y,TRANSPARENT,15);
			Man1.close();
			}
		else
			{
			Man2.open("A:\\2.bmp");
			Man2.draw(My.X,My.Y,TRANSPARENT,15);
			Man2.close();
			}
		}
	else
		{
		if(My.Step%2==1)
			{
			Maan1.open("A:\\crouch.bmp");
			Maan1.draw(My.X,My.Y+13,TRANSPARENT,15);
			Maan1.close();
			}
		else
			{
			Maan2.open("A:\\crouch1.bmp");
			Maan2.draw(My.X,My.Y+13,TRANSPARENT,15);
			Maan2.close();
			}
		}

	};

void player_movement(My_Move& My)
	{
	apvector <int> Left (1);
	apvector <int> Right (1);
	Left[0]=0;
	Right[0]=615;
	setfillstyle(0,15);
	//My.Flagl=true;
	//My.Flagr=true;
	boundary(Left,Right,My.X,My.Flagl,My.Flagr);
/*
	int I,Y,Color;
	for(I=0; I<8; I++)
		{
		Y=My.Y+(I*10);
		Color=getpixel(My.X,Y);
		if(Color==4)
			My.Flagr=false;
		Color=getpixel(My.X+50,Y);
		if(Color==4)
			My.Flagl=false;
		}  */

	My.Step++;
	switch(My.Move)
		{
		case 97: 	setcolor(Co);
							bar(My.X,My.Y,My.X+42,My.Y+70);
							if(My.Flagl==true)
								My.X-=3;
							//draw_me(My);
							break;
		case 115:	My.Crouch=!My.Crouch;
							setcolor(Co);
							bar(My.X,My.Y,My.X+42,My.Y+70);
							//draw_me(My);
							break;
		case 100: setcolor(Co);
							bar(My.X,My.Y,My.X+42,My.Y+70);
							if(My.Flagr==true)
								My.X+=3;
							//draw_me(My);
							break;
		case 77:
							if(My.Clip<19)
								{
								setcolor(Co);
								bar(My.X,My.Y,My.X+42,My.Y+70);

								My.Clip++;
								My.Bullet[My.Clip].BulX=My.X+46;
								My.Bullet[My.Clip].BulY=My.Y+20;
								My.Bullet[My.Clip].Damage=true;
								My.Bullet[My.Clip].Direct='R';
								if(My.Crouch==true)
									My.Bullet[My.Clip].BulY=My.Y+32;
								My.Fire=true;
								}
							break;
		case 75:  if(My.Clip<19)
								{
								setcolor(Co);
								bar(My.X,My.Y,My.X+42,My.Y+70);

								My.Clip++;
								My.Bullet[My.Clip].BulX=My.X;
								My.Bullet[My.Clip].BulY=My.Y+20;
								My.Bullet[My.Clip].Damage=true;
								My.Bullet[My.Clip].Direct='L';
								if(My.Crouch==true)
									My.Bullet[My.Clip].BulY=My.Y+32;
								My.Fire=true;
								}

							break;
//************************************
		case 72: if(My.Clip<19)
								{
								setcolor(Co);
								bar(My.X,My.Y,My.X+42,My.Y+70);

								My.Clip++;
								My.Bullet[My.Clip].BulX=My.X;
								My.Bullet[My.Clip].BulY=My.Y+20;
								My.Bullet[My.Clip].Damage=true;
								My.Bullet[My.Clip].Direct='U';
								if(My.Crouch==true)
									My.Bullet[My.Clip].BulY=My.Y+32;
								My.Fire=true;
								}
						 break;
		case 80: if(My.Clip<19)
								{
								setcolor(Co);
								bar(My.X,My.Y,My.X+42,My.Y+70);

								My.Clip++;
								My.Bullet[My.Clip].BulX=My.X;
								My.Bullet[My.Clip].BulY=My.Y+20;
								My.Bullet[My.Clip].Damage=true;
								My.Bullet[My.Clip].Direct='D';
								if(My.Crouch==true)
									My.Bullet[My.Clip].BulY=My.Y+32;
								My.Fire=true;
								}
						 break;
//************************************
		case 119: if(My.Y>350)
								{
								if(My.Jump==false&&My.Platjump==false)
									{
									My.Ground=My.Y;
									My.J=My.Y-250;
									}
								My.Jump=true;
								}
							else
								{
								if(My.Platjump==false&&My.Jump==false)
									{
									My.Ground=My.Y;
									My.J=My.Y-250;
									}
								My.Platjump=true;
								}
							break;
		case 27:  My.Dead=true;
							break;
		}
	if(My.Move>1)
		//{
		//setcolor(Co);
		//bar(My.X,My.Y,My.X+42,My.Y+70);
		draw_me(My);
		//}
	My.Move=0;
	};

void player_respawn(My_Move& My)
	{
	image Man;
	Man.open("A:\\2.bmp");
	setcolor(Co);
	My.Step=0;
	My.Crouch=false;
	My.Direct='R';
	My.X=20;
	My.Platjump=false;
	My.Jump=false;
	My.Y=369;
	My.Clip=-1;
	My.Bullet.resize(20);
	My.H=5;
	My.Damage=10;
	Man.draw(My.X,My.Y,TRANSPARENT,15);
	Man.close();
	My.Move=0;
	My.Dead=false;
	};

void enemy_respawn(apvector <E_move>& Enemies,apvector <Levels> Level,int C)
	{
	int I;
	Enemies.resize(Level[C].Peeps);
	for(I=0; I<Enemies.length(); I++)
		{
		Enemies[I].X=Level[C].Enemy[I].X;
		Enemies[I].Y=Level[C].Enemy[I].Y;
		Enemies[I].E_bullet.resize(Level[C].Enemy[I].E_bullet.length());
		Enemies[I].Clip=Level[C].Enemy[I].Clip;
		Enemies[I].Damage=Level[C].Enemy[I].Damage;
		Enemies[I].Type=Level[C].Enemy[I].Type;
		Enemies[I].Left=Level[C].Enemy[I].Left;
		Enemies[I].Right=Level[C].Enemy[I].Right;
		Enemies[I].Step=0;
		Enemies[I].Direct='L';
		}
	};

void bullet_fire(apvector <Bullets>& Bullet, int& Clip, bool& Fire)
	{
	int A,I;
	apvector <int> Left (1);
	apvector <int> Right (1);
	Left[0]=-4;
	Right[0]=644;
	bool Flagr;
	Flagr=false;
	if(Fire==true)
		{
		A=-1;
		do{
			A++;
			if(Bullet[A].BulY<650&&Bullet[A].BulY>-10) //add
				{ //add
				if(Bullet[A].BulX<650&&Bullet[A].BulX>-10)
					{
					Bullet[A].Flag=true;
					setcolor(Co);
					circle(Bullet[A].BulX,Bullet[A].BulY,1);
					if(Bullet[A].Direct=='L')
						Bullet[A].BulX-=5;
					else if(Bullet[A].Direct=='R')
						Bullet[A].BulX+=5;
					else if(Bullet[A].Direct=='U') //add
						Bullet[A].BulY-=5;                //add
					else if(Bullet[A].Direct=='D')          //add
						Bullet[A].BulY+=5;                         //add
					setcolor(7);
					circle(Bullet[A].BulX,Bullet[A].BulY,1);
					//setcolor(Co);
					//if(Bullet[A].Direct=='L')
						//circle(Bullet[A].BulX+5,Bullet[A].BulY,1);
					//else if(Bullet[A].Direct=='R')
						//circle(Bullet[A].BulX-5,Bullet[A].BulY,1);
					for(I=0; I<Enemies.length(); I++)
						edamage(Bullet[A], Enemies[I]);
					//boundary(Left,Right,Bullet[A].BulX,Flagr,Flagl);
					}
				else if(Bullet[A].BulX>=650||Bullet[A].BulX<=-10)
					Bullet[A].Flag=false;
				} //add
			else if(Bullet[A].BulY>=650||Bullet[A].BulY<=-10) //add
				Bullet[A].Flag=false;                                //add
			}while(A<Clip);
		}

	 for(I=0; I<Clip+1; I++)
		{
		if(Bullet[I].Flag==true)
			Flagr=true;
		}

	if(Flagr==false)
		{
		Fire=false;
		if(Clip==19)
			Clip=-1;
		}
	};

void boundary(apvector <int> Left,apvector <int> Right,int X,bool& Flagl,bool& Flagr)
	{
	int I;
	for(I=0; I<Left.length(); I++)
		{
		if(X<Left[I])
			Flagl=false;
		//else
			//Flagl=true;
		//if(X>Left[I])
			//Flagl=false;
		}
	for(I=0; I<Right.length(); I++)
		{
		if(X>Right[I])
			Flagr=false;
		//else
			//Flagr=true;
		//if(X<Right[I])
			//Flagr=false;
		}
	};

void enemy_fire(apvector <Bullets>& Bullet, int& Clip, bool& Fire)
	{
	int A;
	if(Fire==true)
			{
			A=-1;
			do{
				A++;
				if(Bullet[A].BulX<650&&Bullet[A].BulX>-10) //add
					{
					Bullet[A].Flag=true;
					setcolor(Co);                           //add
					circle(Bullet[A].BulX,Bullet[A].BulY,2);     //add
					if(Bullet[A].Direct=='R') //add
						Bullet[A].BulX+=5;           //add
					else if(Bullet[A].Direct=='L')      //add
						Bullet[A].BulX-=5;                     //add
					//Bullet[A].BulX-=5;
					setcolor(2);
					circle(Bullet[A].BulX,Bullet[A].BulY,2);
					//setcolor(Co);
					//circle(Bullet[A].BulX+5,Bullet[A].BulY,2);
					damage(Bullet[A], My);
					}
				else if(Bullet[A].BulX>=650||Bullet[A].BulX<=-10)//add
					Bullet[A].Flag=false;                               //add
				}while(A<Clip);
			}
//	if(Bullet[Clip].BulX<-10)
	//	Fire=false;
//	if(Clip==19&&Bullet[Clip].BulX<-10)
	//	Clip=-1;
//**********************************
		bool Flagr;
		Flagr=false;
		int I;

		for(I=0; I<Clip+1; I++)
			{
			if(Bullet[I].Flag==true)
				Flagr=true;
			}

		if(Flagr==false)
			{
			Fire=false;
			if(Clip==19)
				Clip=-1;
			}
//**********************************
	};


void edamage (Bullets& Bullet, E_move& Enemy)
	{
	if(Bullet.BulX>Enemy.X&&Bullet.BulX<Enemy.X+60&&Bullet.Damage==true)
		{
		if(Bullet.BulY<Enemy.Y+85&&Bullet.BulY>Enemy.Y&&Enemy.Damage>0)
			{
			Enemy.Damage--;
			Bullet.Damage=false;
			if(Enemy.Damage<1)
				{
				setfillstyle(1,0);
				if(Enemy.Type=='G')
					bar(Enemy.X,Enemy.Y,Enemy.X+45,Enemy.Y+50);
				else
					bar(Enemy.X,Enemy.Y,Enemy.X+60,Enemy.Y+85);
				}
			}
		}
	};

void damage (Bullets& Bullet,My_Move& My)
	{
	if(Bullet.BulX>My.X&&Bullet.BulX<My.X+50&&Bullet.Damage==true)
		{
		if(My.Crouch==false&&Bullet.BulY<My.Y+70&&Bullet.BulY>My.Y)
			{
			My.Damage--;
			Bullet.Damage=false;
			if(My.Damage<1)
				{
				My.Dead=true;
				setfillstyle(1,0);
				bar(My.X,My.Y,My.X+50,My.Y+70);
				}
			}
		else if(My.Crouch==true&&Bullet.BulY<My.Y+70&&Bullet.BulY>My.Y+13)
			{
			My.Damage--;
			Bullet.Damage=false;
			if(My.Damage<1)
				{
				My.Dead=true;
				setfillstyle(1,0);
				bar(My.X,My.Y,My.X+50,My.Y+70);
				}
			}
		}
	};

void enemy_movement(E_move& Enemy)
	{
	image Alien,Grunt,Grunt1,Jackal,Alien1,Jackal1;
	Alien.open("A:\\Alien.bmp");
	Grunt.open("A:\\Grunt.bmp");
	Jackal.open("A:\\Jackal.bmp");
	Grunt1.open("A:\\Grunt1.bmp");
	Alien1.open("A:\\Alien1.bmp");
	Jackal1.open("A:\\jackal1.bmp");

	apvector <int> Left (1);
	apvector <int> Right (1);
	Left[0]=Enemy.Left;
	Right[0]=Enemy.Right-50;
	bool Flagr,Flagl;
	boundary(Left,Right,Enemy.X,Flagl,Flagr);

	int Move;
	//delay(20);
	Move=random(10);
	Enemy.Step++;
	switch(Move)
		{
		//case 0:
		case 5:   ;
		case 6:   ;
		case 1:   ;
		case 2: 	setfillstyle(1,0);
							if(Enemy.Type=='G')
								bar(Enemy.X,Enemy.Y,Enemy.X+48,Enemy.Y+50);
							else
								bar(Enemy.X,Enemy.Y,Enemy.X+60,Enemy.Y+85);
//****************************************
							//if(Flagl==false)
							//	Enemy.X-=3;

							if(Flagl==false)
								Enemy.Direct='R';
							if(Flagr==false)
								Enemy.Direct='L';
							if(Enemy.Direct=='R')
								Enemy.X+=3;
							else if(Enemy.Direct=='L')
								Enemy.X-=3;
//****************************************
							setcolor(5);
							if(Enemy.Step%2==1)
								{
								if(Enemy.Type=='E')
									Alien.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								if(Enemy.Type=='G')
									Grunt.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								if(Enemy.Type=='J')
									Jackal.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								}
							else
								{
								if(Enemy.Type=='E')
									Alien1.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								if(Enemy.Type=='G')
									Grunt1.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								if(Enemy.Type=='J')
									Jackal1.draw(Enemy.X,Enemy.Y,TRANSPARENT,15);
								}
							break;

		case 3:   if(Enemy.Clip<19)
								{
								Enemy.Clip++;
								Enemy.E_bullet[Enemy.Clip].BulX=Enemy.X;
								Enemy.E_bullet[Enemy.Clip].BulY=Enemy.Y+25;
								Enemy.Fire=true;
								Enemy.E_bullet[Enemy.Clip].Damage=true;
								if(My.X>=Enemy.X)                       //add
									Enemy.E_bullet[Enemy.Clip].Direct='R';     //add
								else                                              //add
									Enemy.E_bullet[Enemy.Clip].Direct='L';               //add
								}
							break;
		case 0:   ; /*
		case 4:   setcolor(15);
							rectangle(Enemy.X,Enemy.Y,Enemy.X+40,Enemy.Y+80);
							Enemy.X+=5;
							setcolor(5);
							rectangle(Enemy.X,Enemy.Y,Enemy.X+40,Enemy.Y+80);
							break;*/
							;
		case 7:   ;
		case 8:   ;
		case 9:   break;
		}
	Alien.close();
	Jackal.close();
	Grunt1.close();
	Grunt.close();
	Alien1.close();
	Jackal1.close();
	};

void change (int Num,apstring& Number)
	{
	int H,T,O;
		if(Num==0)
			Number="0";
			else
				{
				H=Num;
				T=Num%100;
				H-=T;
				O=T%10;
				T-=O;
				T/=10;
				H/=100;
				if(H==0&&T==0)
					Number=char(48+O);
				else if(H==0)
					{
					Number=char(48+T);
					Number=Number+char(48+O);
					}
				else
					{
					Number=char(48+H);
					Number=Number+char(48+T);
					Number=Number+char(48+O);
					}
				}
	};