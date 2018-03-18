// Chris Hogan  && Josh Kessell
// 6th Block
// Galaga


//Library
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <fstream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <alloc.h>
#include <dos.h>
#include "math2.h"

//Const


//Structure
struct scoredat
{
	apstring Name;
	apstring Score;
	int Scoreint;
};

//Variables
int Grdriver, Grmode, Errorcode;
int I, Temp;
long G;
char Choice;
bool Exit, Back, Back2, Exit2;
ifstream Scores;
ofstream outfile;
apvector <scoredat> H_Scores(10);
apvector <int> TwinkleX(100);
apvector <int> TwinkleY(100);
apstring Level;
int X, Y, Fx, Fy, D, D2, D3, L, ShipHit, AD2, AD3, Lives, Bullets;
int Speed, Shoot, Score, ShipCount, Count, Count2, Spacing, L2, S_Shot;
int Mx,My,M_D,M_Speed;
bool Fire,Hit,L_Stop,R_Stop,T_Stop,B_Stop,A_Explode,H_Explode,Die,Spawn;
bool Moved,Align,Dodge,DirSet,Missile,AL_Stop,AR_Stop;
void far *H_Ship,*A_Ship,*H_Ex,*A_Ex;
unsigned Size;
apvector <int> A_D;
apvector <int> Ax;
apvector <int> Ay;
apvector <int> AFx;
apvector <int> AFy;
apvector <bool> A_Fire;
apvector <bool> Dead;
apvector <bool> M_Left;
apvector <bool> M_Right;
apvector <int> Dir;
apvector <bool> Move;
apvector <int> GoalX;
apvector <int> SFx;
apvector <int> SFy;
long SpawnCount,Del,MissileCount;
int Delaytime=1000;
apstring Livesap;

//Variable Dictionary

/*
I is a general loop variable.
Temp is a variable used in data swapping.
G is a counter for loops.
Choice is a menu choice for the switch case.
Exit, Back, Back2, and Exit 2 are for menu navigation.
Scores is the storage for... well... scores of the game.
H_Scores is the array for the HS list.
TwinkleX/Y are variables for the random generation of stars.
Level is the storage for the title of each level.
X and Y are the coords of the human ship.
Fx and Fy are the shooting coords for the human ship.
D, D2, and D3 are counters.
L and L2 is a loop variable.
ShipHit is a storage variable for data swapping.
AD2 and AD3 are other counter variables.
Lives are the remaning lives for the human ship.
Bullets is the control variable for the number of bullets a boss can fire.
Speed is the control variable for the speed of the bosses.
Shoot is the speed of firing for the alien ships.
Shipcount is the number of remaining enemy ships.
Count and Count2 are more counter variables.
Spacing is used for the spacing of the ships after one dies.
S_Shot is used for the number of bullets a boss ship can fire.
Mx and My are the coordinates for the missile.
M_D is a loop variable for the movement of the missile.
M_Speed controls the speed of the missile for each boss.
Fire and Hit work with human firing and whether it hits an alien or not.
L,R,T, and B stop work with the limits on where a human ship can move.
A and H Explode work with the explosion animation when a human or alien dies.
Die is when a human ship dies and spawn is the time after it dies and before
----the human ship respawns.
Moved and Align work together to align the ships after an enemy ship dies.
Dirset works with the alternating movement of the ships.
Missile determines when a missile is fired.
AL and AR Stop controls the movement of the boss ships off the screen.
H_Ship and A_Ship are the images for the human and alien ships.
H_Ex and A_Ex are the images for the explosions of the human and alien ships.
Size helps with the storage of the images.
A_D is a counter for alien fire.
Ax and Ay are alien coods.
AFx and AFy are alien bullet coords.
A_Fire is when an alien fires its gun.
Dead checks if a ship is destroyed.
M_Left and M_Right control whether a ship moves left or right.
Dir is a counter for movement of a ship.
Move works with the movements of the ships.
GoalX works with the alignment of the ships.
SFx and SFy are the coords of the alien boss bullets.
SpawnCount works with the respawning of the ships.
MissileCount is the counter for firing boss missiles.
DelayTime sets the... Delay Time before the start of each level.
Livesap stores the apstring of the level for outtextxy-ing.
*/

//Prototype
void level_1 (int,int,bool&);
void level_2 (int,int,bool&);
void level_3 (int,int,bool&);
void difficult (int,int,int,int,bool&);
void gr_start (int&, int&, int&);
void con ();
void H_Score_Sort(apvector<scoredat>&);
void Menu(apvector<int>, apvector<int>);


void main()
{

		 clrscr();


		 /*Scores.open("A:\\Scores.dat");
		 for(I=0;I<10;I++)
			{
			 getline(Scores,H_Scores[I].Name);
			 getline(Scores,H_Scores[I].Score);
			}
		 Scores.close();

		 for(I=0;I<10;I++)
			H_Scores[I].Scoreint= atoi(H_Scores[I].Score.c_str());
		 */

		 gr_start(Grdriver, Grmode, Errorcode);

		 //Ship creation
			setfillstyle(1,BLUE);
			bar(0,7,20,16);
			bar(6,17,14,20);
			setcolor(BLUE);
			line(0,16,5,20);
			line(15,20,20,16);
			floodfill(3,17,BLUE);
			floodfill(18,17,BLUE);
			setfillstyle(1,WHITE);
			bar(7,4,13,20);
			setcolor(WHITE);
			circle(10,4,3);
			floodfill(10,3,WHITE);
			bar(1,2,2,6);
			bar(17,2,18,6);
			setcolor(RED);
			circle(10,5,2);
			setfillstyle(1,RED);
			floodfill(10,5,RED);

			Size=imagesize(0,0,20,20);
			H_Ship=farmalloc(Size);
			getimage(0,0,20,20,H_Ship);
			cleardevice();

			setfillstyle(1,RED);
			bar(0,7,20,16);
			bar(6,17,14,20);
			setcolor(RED);
			line(0,16,5,20);
			line(15,20,20,16);
			floodfill(3,17,RED);
			floodfill(18,17,RED);
			setfillstyle(1,YELLOW);
			bar(7,4,13,20);
			setcolor(YELLOW);
			circle(10,4,3);
			floodfill(10,3,YELLOW);
			bar(1,2,2,6);
			bar(17,2,18,6);
			setcolor(MAGENTA);
			circle(10,5,2);
			setfillstyle(1,MAGENTA);
			floodfill(10,5,MAGENTA);

			H_Ex=farmalloc(Size);
			getimage(0,0,20,20,H_Ex);
			cleardevice();

			setfillstyle(1,GREEN);
			setcolor(GREEN);
			pieslice(10,10,0,180,10);
			line(0,10,10,15);
			line(20,10,10,15);
			floodfill(10,12,GREEN);
			setcolor(MAGENTA);
			setfillstyle(1,MAGENTA);
			pieslice(10,10,0,180,8);
			setfillstyle(1,GREEN);
			bar(9,15,11,20);
			bar(0,0,2,10);
			bar(18,0,20,10);

			A_Ship=farmalloc(Size);
			getimage(0,0,20,20,A_Ship);
			cleardevice();

			setfillstyle(1,RED);
			setcolor(RED);
			pieslice(10,10,0,180,10);
			line(0,10,10,15);
			line(20,10,10,15);
			floodfill(10,12,RED);
			setcolor(YELLOW);
			setfillstyle(1,YELLOW);
			pieslice(10,10,0,180,8);
			setfillstyle(1,RED);
			bar(9,15,11,20);
			bar(0,0,2,10);
			bar(18,0,20,10);

			A_Ex=farmalloc(Size);
			getimage(0,0,20,20,A_Ex);
			cleardevice();

		 //Program




		 //Stars

		 for(I=0;I<100;I++)
			{
			 TwinkleX[I]=random(640);
			 TwinkleY[I]=random(480);
			}


		 do{
		 Menu(TwinkleX,TwinkleY);
		 Lives=3;


			Exit=false;
			if(kbhit())
			switch(getch())
			{
			case 115:

			cleardevice();
			setcolor(WHITE);


			Bullets=0;
			Speed=0;
			Shoot=0;
			M_Speed=0;
			Level="Level One";
			Back2=false;
			line(535,0,535,480);
			level_1(Speed,Shoot,Back2);
			cleardevice();


			if(!Back2)
				{
				Level="Level Two";
				setcolor(WHITE);
				line(535,0,535,480);
				level_2(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Level="Level Three";
				setcolor(WHITE);
				line(535,0,535,480);
				level_3(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Speed=500;
				Level="Boss One";
				setcolor(WHITE);
				line(535,0,535,480);
				difficult(Speed,Shoot,Bullets,M_Speed,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Speed=1000;
				Shoot=30;
				Bullets=2;
				M_Speed=500;
				Level="Level Four";
				setcolor(WHITE);
				line(535,0,535,480);
				level_1(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Level="Level Five";
				setcolor(WHITE);
				line(535,0,535,480);
				level_2(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Level="Level Six";
				setcolor(WHITE);
				line(535,0,535,480);
				level_3(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Speed=1500;
				Level="Boss Two";
				setcolor(WHITE);
				line(535,0,535,480);
				difficult(Speed,Shoot,Bullets,M_Speed,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Speed=1500;
				Shoot=60;
				Bullets=4;
				M_Speed=1000;
				Level="Level Seven";
				setcolor(WHITE);
				line(535,0,535,480);
				level_1(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Level="Level Eight";
				setcolor(WHITE);
				line(535,0,535,480);
				level_2(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Level="Level Nine";
				setcolor(WHITE);
				line(535,0,535,480);
				level_3(Speed,Shoot,Back2);
				cleardevice();
				}
			if(!Back2)
				{
				Speed=1500;
				Level="Boss Three";
				setcolor(WHITE);
				line(535,0,535,480);
				difficult(Speed,Shoot,Bullets,M_Speed,Back2);
				cleardevice();
				}
			break;
			case 104: Scores.open("A:\\Scores.dat");
								for(I=0;I<10;I++)
								{
								 getline(Scores,H_Scores[I].Name);
								 getline(Scores,H_Scores[I].Score);
								}
								Scores.close();

								for(I=0;I<10;I++)
								H_Scores[I].Scoreint= atoi(H_Scores[I].Score.c_str());

								H_Score_Sort(H_Scores);
								cleardevice();
								for(I=0;I<100;I++)
								 putpixel(random(640),random(480),15);
								settextstyle(1,0,7);
								outtextxy(getmaxx()/2,80,"High Scores");
								settextstyle(0,0,0);
								for(I=0;I<10;I++)
								{
								outtextxy(getmaxx()/4,(120+((I+1)*30)),H_Scores[I].Name.c_str());
								//itoa(H_Scores[I].Score, string, 5);
								outtextxy(((getmaxx()/4)*3),(120+((I+1)*30)),H_Scores[I].Score.c_str());
												}
								setcolor(4);
								settextstyle(2,0,7);
								outtextxy(getmaxx()/2,460,"B   ");
								setcolor(15);
								outtextxy(getmaxx()/2,460," ack");
								do{
									switch(getch())
									{
									 case 27: Exit2=true;

									 case 98: cleardevice();
														Back=true;
														break;

									 default: Back=false;
									}
								}while(!Back);

								break;
			case 101: cleardevice();
								for(I=0;I<100;I++)
								 putpixel(random(640),random(480),15);
								settextstyle(1,0,7);
								outtextxy(getmaxx()/2,80,"Help");
								settextjustify(0,1);
								settextstyle(0,0,0);
								putimage(200,200,H_Ship,COPY_PUT);
								outtextxy(260,160,"Human Ship:");
								outtextxy(260,180,"This is your ship, you use this ship");
								outtextxy(260,200,"to completely and utterly obliterate");
								outtextxy(260,220,"the enemies. You move your ship by ");
								outtextxy(260,240,"pressing the arrow keys.");
								putimage(200,320,A_Ship,COPY_PUT);
								outtextxy((260),280,"Enemy Ship:");
								outtextxy((260),300,"This is the enemy ship. Your main goal is ");
								outtextxy((260),320,"to destroy all ships like this on the screen ");
								outtextxy((260),340,"This ship will try to kill you, so kill it  ");
								outtextxy((260),360,"back...first!.");
								setcolor(4);
								settextstyle(2,0,7);
								settextjustify(1,1);
								outtextxy(getmaxx()/2,460,"B   ");
								setcolor(15);
								outtextxy(getmaxx()/2,460," ack");
								do{
									switch(getch())
									{
									 case 27: Exit2=true;

									 case 98: cleardevice();
														Back=true;
														break;
									 default: Back=false;
									}
								}while(!Back);
								break;
			case 27: Exit2=true;
			default: break;
			}
		 }while(!Exit2);
		 }









void con ()
	{
	cout<<endl<<endl<<"Press RETURN to continue.";
	getch();
	clrscr();
	};

void gr_start (int&Grdriver, int&Grmode, int&Errorcode)
{
	Grdriver=VGA;
	Grmode=VGAHI;
	initgraph(&Grdriver, &Grmode, "C:\\TC\\BGI");
	Errorcode=graphresult();
	if(Errorcode!=grOk)
	{
	 clrscr();
	 cout<<"Error: "<<Errorcode<<endl;
	 cout<<"Press return to continue.";
	 getch();
	 exit(1);
	}
};




void H_Score_Sort (apvector<scoredat>&H_Scores)
	{
	 int I, J, Small, Num;
	 scoredat Temp;
	 Num=10;

	 for(I=Num-1;I>0;I--)
	 {
		Small=0;
		for(J=1;J<=I;J++)
		 {
			if(H_Scores[J].Scoreint<H_Scores[Small].Scoreint)
			 {
				Small=J;
			 }
		 }
		Temp=H_Scores[Small];
		H_Scores[Small]=H_Scores[I];
		H_Scores[I]=Temp;
	 }
	 };

void Menu(apvector<int>TwinkleX,apvector<int>TwinkleY)
{
 for(I=0;I<100;I++)
	putpixel(TwinkleX[I],TwinkleY[I],15);
 settextstyle(1,0,7);
 settextjustify(1,1);
 setcolor(15);
 outtextxy(getmaxx()/2,120,"GALAGA");
 settextstyle(2,0,7);
 setcolor(4);
 outtextxy((getmaxx()/2),200,"S    ");
 setcolor(15);
 outtextxy((getmaxx()/2),200," tart");
 setcolor(4);
 outtextxy((getmaxx()/2),240,"H         ");
 setcolor(15);
 outtextxy((getmaxx()/2),240," igh Score");
 setcolor(4);
 outtextxy((getmaxx()/2),280," e  ");
 setcolor(15);
 outtextxy((getmaxx()/2),280,"H lp");
 outtextxy((getmaxx()/2),320,"Exit     ");
 setcolor(4);
 outtextxy((getmaxx()/2),320,"    (ESC)");
 setcolor(15);
 }







		 //Level 1







void level_1 (int Speed, int Shoot, bool&Back2)
		 {
		 bool ScoreCheck;
		 ScoreCheck=false;
		 I=2;
		 Back2=false;
		 randomize();
		 X=230;
		 Y=420;
		 Ax.resize(6);
		 Ay.resize(6);
		 A_Fire.resize(6);
		 A_D.resize(6);
		 AFx.resize(6);
		 AFy.resize(6);
		 Dead.resize(6);
		 Move.resize(6);
		 Dir.resize(6);
		 M_Left.resize(6);
		 M_Right.resize(6);
		 GoalX.resize(6);
		 for(L=0;L<6;L++)
			 {
			 A_Fire[L]=false;
			 Dead[L]=false;
			 M_Right[L]=true;
			 M_Left[L]=false;
			 Dir[L]=0;
			 }
		 Moved=false;
		 ShipCount=6;
		 Die=false;
		 putimage(X,Y,H_Ship,COPY_PUT);
		 L=480/7;
		 Ax[0]=L;
		 Ax[1]=L*2;
		 Ax[2]=L*3;
		 Ax[3]=L*4;
		 Ax[4]=L*5;
		 Ax[5]=L*6;
		 for(L=0;L<ShipCount;L++)
			 Ay[L]=80;
		 putimage(Ax[0],Ay[0],A_Ship,COPY_PUT);
		 putimage(Ax[1],Ay[1],A_Ship,COPY_PUT);
		 putimage(Ax[2],Ay[2],A_Ship,COPY_PUT);
		 putimage(Ax[3],Ay[3],A_Ship,COPY_PUT);
		 putimage(Ax[4],Ay[4],A_Ship,COPY_PUT);
		 putimage(Ax[5],Ay[5],A_Ship,COPY_PUT);

		 setcolor(WHITE);
		 settextjustify(1,1);
		 outtextxy(230,240,Level.c_str());
		 delay(1500);
		 setfillstyle(1,BLACK);
		 bar(150,260,310,220);

		 do{
		 if(I>=1)
			 {
			 settextstyle(0,0,0);
			 outtextxy(580,380,"Score: ");
			 outtextxy(580,420,"Lives: ");
			 if(Lives==3)
				 Livesap="3";
			 else if (Lives==2)
				 Livesap="2";
			 else
				 Livesap="1";
			 outtextxy(620,420,Livesap.c_str());
			 if(I==2)
				 {
				 setfillstyle(1,0);
				 bar(605,375,640,430);
				 outtextxy(620,380,itos(Score).c_str());
				 outtextxy(620,420,Livesap.c_str());
				 }
			 }
		 I=0;
		 Exit=false;
		 if(kbhit())
			 switch(getch())
				 {
				 case 75: if(!L_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X-=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 77: if(!R_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X+=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 80: if(!T_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y+=10,H_Ship,COPY_PUT);
										}
									break;
				 case 72: if(!B_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y-=10,H_Ship,COPY_PUT);
										}
									break;
				 case 27: Exit=true;
									break;
				 case 32: if(!Fire&&!Die)
										{
										Fire=true;
										Fx=X+10;
										Fy=Y-12;
										D=249;
										Hit=false;
										}
				 default: break;
				 }

			 if (Fire&&!Hit)
					 {
					 D++;
					 if(D>=200)
						 {
						 D=0;
						 setfillstyle(1,0);
						 bar(Fx-1,Fy+3,Fx+1,Fy+7);
						 setfillstyle(1,14);
						 bar(Fx-1,Fy-2,Fx+1,Fy+2);
						 Fy--;
						 if(Fy<=-5)
							 Fire=false;
						 }
					 }

			 for(L=0;L<ShipCount;L++)
				 if (((Fx<=Ax[L]+21)&&(Fx>=Ax[L]))&&((Fy<=Ay[L]+20)&&(Fy>=Ay[L]))&&!Dead[L])
					 {
					 ShipCount--;
					 ShipHit=L;
					 Hit=true;
					 setfillstyle(1,0);
					 bar(Ax[L]-5,Ay[L]-5,Ax[L]+25,Ay[L]+25);
					 A_Explode=true;
					 D2=4999;
					 D3=0;
					 Fx=X;
					 Fy=Y;
					 Fire=false;
					 }

			 if(A_Explode)
				 {
				 if(D3==6)
					 {
					 A_Explode=false;
					 for(L=ShipHit;L<ShipCount;L++)
						 {
						 Ax[L]=Ax[L+1];
						 Dead[L]=Dead[L+1];
						 M_Right[L]=M_Right[L+1];
						 M_Left[L]=M_Left[L+1];
						 Move[L]=Move[L+1];
						 }
					 Ax[ShipCount]=-200;
					 Dead[ShipCount]=true;
					 Align=true;
					 I=2;
					 Score+=100;
					 Count=0;
					 Count2=0;
					 }
				 if(D2==5000)
					 putimage(Ax[ShipHit],Ay[ShipHit],A_Ex,COPY_PUT);
				 if(D2==10000)
					 {
					 setfillstyle(1,0);
					 bar(Ax[ShipHit]-5,Ay[ShipHit]-5,Ax[ShipHit]+25,Ay[ShipHit]+25);
					 D2=0;
					 D3++;
					 }
				 D2++;
				 }

			 for(L=0;L<ShipCount;L++)
				 if (((AFx[L]<=X+19)&&(AFx[L]>=X-10))&&((AFy[L]<=Y)&&(AFy[L]>=Y-10)))
					 {
					 Die=true;
					 setfillstyle(1,0);
					 bar(AFx[L]-15,AFy[L],AFx[L]+25,AFy[L]+30);
					 A_Fire[L]=false;
					 AD2=4999;
					 AD3=0;
					 AFx[L]=-500;
					 AFy[L]=-500;
					 L_Stop=true;
					 R_Stop=true;
					 T_Stop=true;
					 B_Stop=true;
					 }

			 if(Die)
				 {
				 AD2++;
				 if(AD3==6)
					 {
					 Lives--;
					 I=2;
					 Spawn=true;
					 X=230;
					 Y=420;
					 Back2=false;
					 if(Lives>0)
						 Die=false;
					 else
						 {
						 Exit=true;
						 Back=true;
						 Back2=true;
						 H_Score_Sort(H_Scores);
						 if(Score>H_Scores[9].Scoreint)
							ScoreCheck=true;
						 }
					 if(ScoreCheck)
						{
						 H_Scores[9].Scoreint=Score;
						 cleardevice();
						 outtextxy(300,10,"Please enter your name");
						 gotoxy(35,3);
						 getline(cin,H_Scores[9].Name);
						 outfile.open("A:\\Scores.dat");
						 for(I=0;I<10;I++)
						 {
							outfile<<H_Scores[I].Name <<endl;
							outfile<<H_Scores[I].Scoreint <<endl;
						 }
						 outfile.close();
						}
					 for(L=0;L<ShipCount;L++)
						 A_Fire[L]=true;
					 }
				 if(AD2==5000)
					 putimage(X,Y,H_Ex,COPY_PUT);
				 if(AD2==10000)
					 {
					 setfillstyle(1,0);
					 bar(X-5,Y-5,X+25,Y+25);
					 AD2=0;
					 AD3++;
					 }
				 }

			 if(Spawn)
				 {
				 SpawnCount++;
				 if(SpawnCount==250000)
					 {
					 Spawn=false;
					 SpawnCount=0;
					 putimage(X,Y,H_Ship,COPY_PUT);
					 }
				 }

			 if (X<=10)
				 L_Stop=true;
			 else if(!Die&&!Spawn)
				 L_Stop=false;
			 if (X>=500)
				 R_Stop=true;
			 else if(!Die&&!Spawn)
				 R_Stop=false;
			 if (Y>=460)
				 T_Stop=true;
			 else if(!Die&&!Spawn)
				 T_Stop=false;
			 if (Y<=380)
				 B_Stop=true;
			 else if(!Die&&!Spawn)
				 B_Stop=false;

			 for(L=0;L<ShipCount;L++)
				 if(!A_Fire[L]&&!Die&&!Spawn&&!Dead[L])
					 if((random(300-Shoot)>=299-Shoot)&&(random(250-Shoot)>=249-Shoot))
						 {
						 A_Fire[L]=true;
						 AFx[L]=Ax[L];
						 AFy[L]=Ay[L];
						 }

			 for(L=0;L<ShipCount;L++)
				 if(A_Fire[L])
					 {
					 A_D[L]++;
					 if(A_D[L]>=300)
						 {
						 A_D[L]=0;
						 setfillstyle(1,0);
						 bar(AFx[L]+9,AFy[L]+20,AFx[L]+11,AFy[L]+22);
						 setfillstyle(1,14);
						 bar(AFx[L]+9,AFy[L]+25,AFx[L]+11,AFy[L]+27);
						 AFy[L]++;
						 if(AFy[L]>=485&&!Die&&!Spawn)
							 {
							 A_Fire[L]=false;
							 setfillstyle(1,0);
							 bar(1,100,515,480);
							 putimage(X,Y,H_Ship,COPY_PUT);
							 }
						 }
					 }

				 if(!Align)
					 for(L=0;L<ShipCount;L++)
						 {
						 if(!Dead[L])
						 {
						 Move[L]++;
						 if(Dir[L]==20)
							 {
							 M_Right[L]=false;
							 M_Left[L]=true;
							 }
						 if(Dir[L]==-20)
							 {
							 M_Right[L]=true;
							 M_Left[L]=false;
							 }
						 if(Move[L]==7000-Speed)
							 {
							 Move[L]=0;
							 putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							 if(M_Right[L])
								 {
								 Dir[L]++;
								 putimage(Ax[L]+=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 if(M_Left[L])
								 {
								 Dir[L]--;
								 putimage(Ax[L]-=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 }
						 }
						 }

					if(Align&&!Moved)
						{
						Spacing=480/(ShipCount+1);
						for(L2=0;L2<ShipCount;L2++)
							GoalX[L2]=(L2+1)*Spacing;
						for(L=0;L<ShipCount;L++)
							{
							if(GoalX[L]>=Ax[L])
								{
								M_Right[L]=true;
								M_Left[L]=false;
								GoalX[L]=int((GoalX[L]-Ax[L])/15);
								}
							else
								{
								M_Left[L]=true;
								M_Right[L]=false;
								GoalX[L]=int((Ax[L]-GoalX[L])/15);
								}
							}
						}

				if(Align)
					{
					Moved=true;
					Count++;
					if(Count==(7000-Speed))
					{ if(Count2!=15)
						{
						Count2++;
						Count=0;
						for(L=0;L<ShipCount;L++)
							{
							putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							if(M_Right[L])
								putimage(Ax[L]+=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							if(M_Left[L])
								putimage(Ax[L]-=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							}
						}
						else
						{
						Align=false;
						Moved=false;
						for(L=0;L<ShipCount;L++)
							{
							Dir[L]=0;
							M_Right[L]=true;
							M_Left[L]=false;
							}
						}
					}
				 }
				if(Dead[0]&&!A_Explode&&!Die&&!Spawn)
					return;

			 }while(!Exit);
		 }




		 //Level 2







void level_2 (int Speed, int Shoot, bool&Back2)
		 {
		 bool ScoreCheck;
		 ScoreCheck=false;
		 I=2;
		 Back2=false;
		 randomize();
		 X=230;
		 Y=420;
		 Ax.resize(8);
		 Ay.resize(8);
		 A_Fire.resize(8);
		 A_D.resize(8);
		 AFx.resize(8);
		 AFy.resize(8);
		 Dead.resize(8);
		 Move.resize(8);
		 Dir.resize(8);
		 M_Left.resize(8);
		 M_Right.resize(8);
		 GoalX.resize(8);
		 for(L=0;L<8;L++)
			 {
			 A_Fire[L]=false;
			 Dead[L]=false;
			 M_Right[L]=true;
			 M_Left[L]=false;
			 Dir[L]=0;
			 }
		 Moved=false;
		 ShipCount=8;
		 Die=false;
		 putimage(X,Y,H_Ship,COPY_PUT);
		 L=480/9;
		 Ax[0]=L;
		 Ax[1]=L*2;
		 Ax[2]=L*3;
		 Ax[3]=L*4;
		 Ax[4]=L*5;
		 Ax[5]=L*6;
		 Ax[6]=L*7;
		 Ax[7]=L*8;
		 for(L=0;L<ShipCount;L++)
			 Ay[L]=80;
		 putimage(Ax[0],Ay[0],A_Ship,COPY_PUT);
		 putimage(Ax[1],Ay[1],A_Ship,COPY_PUT);
		 putimage(Ax[2],Ay[2],A_Ship,COPY_PUT);
		 putimage(Ax[3],Ay[3],A_Ship,COPY_PUT);
		 putimage(Ax[4],Ay[4],A_Ship,COPY_PUT);
		 putimage(Ax[5],Ay[5],A_Ship,COPY_PUT);
		 putimage(Ax[6],Ay[6],A_Ship,COPY_PUT);
		 putimage(Ax[7],Ay[7],A_Ship,COPY_PUT);

		 setcolor(WHITE);
		 settextjustify(1,1);
		 outtextxy(230,240,Level.c_str());
		 delay(1500);
		 setfillstyle(1,BLACK);
		 bar(150,260,310,220);

		 do{
		 if(I>=1)
			 {
			 outtextxy(580,380,"Score: ");
			 outtextxy(580,420,"Lives: ");
			 if(Lives==3)
				 Livesap="3";
			 else if (Lives==2)
				 Livesap="2";
			 else
				 Livesap="1";
			 outtextxy(620,420,Livesap.c_str());
			 if(I==2)
				 {
				 setfillstyle(1,0);
				 bar(605,375,640,430);
				 outtextxy(620,380,itos(Score).c_str());
				 outtextxy(620,420,Livesap.c_str());
				 }
			 }
		 I=0;
		 Exit=false;
		 if(kbhit())
			 switch(getch())
				 {
				 case 75: if(!L_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X-=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 77: if(!R_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X+=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 80: if(!T_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y+=10,H_Ship,COPY_PUT);
										}
									break;
				 case 72: if(!B_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y-=10,H_Ship,COPY_PUT);
										}
									break;
				 case 27: Exit=true;
									break;
				 case 32: if(!Fire&&!Die)
										{
										Fire=true;
										Fx=X+10;
										Fy=Y-12;
										D=249;
										Hit=false;
										}
				 default: break;
				 }

			 if (Fire&&!Hit)
					 {
					 D++;
					 if(D>=200)
						 {
						 D=0;
						 setfillstyle(1,0);
						 bar(Fx-1,Fy+3,Fx+1,Fy+7);
						 setfillstyle(1,14);
						 bar(Fx-1,Fy-2,Fx+1,Fy+2);
						 Fy--;
						 if(Fy<=-5)
							 Fire=false;
						 }
					 }

			 for(L=0;L<ShipCount;L++)
				 if (((Fx<=Ax[L]+21)&&(Fx>=Ax[L]))&&((Fy<=Ay[L]+20)&&(Fy>=Ay[L]))&&!Dead[L])
					 {
					 ShipCount--;
					 ShipHit=L;
					 Hit=true;
					 setfillstyle(1,0);
					 bar(Ax[L]-5,Ay[L]-5,Ax[L]+25,Ay[L]+25);
					 A_Explode=true;
					 D2=4999;
					 D3=0;
					 Fx=X;
					 Fy=Y;
					 Fire=false;
					 }

			 if(A_Explode)
				 {
				 if(D3==6)
					 {
					 A_Explode=false;
					 for(L=ShipHit;L<ShipCount;L++)
						 {
						 Ax[L]=Ax[L+1];
						 Dead[L]=Dead[L+1];
						 M_Right[L]=M_Right[L+1];
						 M_Left[L]=M_Left[L+1];
						 Move[L]=Move[L+1];
						 }
					 Ax[ShipCount]=-200;
					 Dead[ShipCount]=true;
					 Align=true;
					 Count=0;
					 Count2=0;
					 I=2;
					 Score+=100;
					 }
				 if(D2==5000)
					 putimage(Ax[ShipHit],Ay[ShipHit],A_Ex,COPY_PUT);
				 if(D2==10000)
					 {
					 setfillstyle(1,0);
					 bar(Ax[ShipHit]-5,Ay[ShipHit]-5,Ax[ShipHit]+25,Ay[ShipHit]+25);
					 D2=0;
					 D3++;
					 }
				 D2++;
				 }

			 for(L=0;L<ShipCount;L++)
				 if (((AFx[L]<=X+19)&&(AFx[L]>=X-10))&&((AFy[L]<=Y)&&(AFy[L]>=Y-10)))
					 {
					 Die=true;
					 setfillstyle(1,0);
					 bar(AFx[L]-15,AFy[L],AFx[L]+25,AFy[L]+30);
					 A_Fire[L]=false;
					 AD2=4999;
					 AD3=0;
					 AFx[L]=-500;
					 AFy[L]=-500;
					 L_Stop=true;
					 R_Stop=true;
					 T_Stop=true;
					 B_Stop=true;
					 }

			 if(Die)
				 {
				 AD2++;
				 if(AD3==6)
					 {
					 Lives--;
					 I=2;
					 Back2=false;
					 Spawn=true;
					 X=230;
					 Y=420;
					 if(Lives>0)
						 Die=false;
					 else
						 {
						 Exit=true;
						 Back=true;
						 Back2=true;
						 H_Score_Sort(H_Scores);
						 if(Score>H_Scores[9].Scoreint)
							ScoreCheck=true;
						 }
					 if(ScoreCheck)
						{
						 H_Scores[9].Scoreint=Score;
						 cleardevice();
						 outtextxy(300,10,"Please enter your name");
						 gotoxy(35,3);
						 getline(cin,H_Scores[9].Name);
						 outfile.open("A:\\Scores.dat");
						 for(I=0;I<10;I++)
						 {
							outfile<<H_Scores[I].Name <<endl;
							outfile<<H_Scores[I].Scoreint <<endl;
						 }
						 outfile.close();
						 Score=0;
						}

					 for(L=0;L<ShipCount;L++)
						 A_Fire[L]=true;
					 }
				 if(AD2==5000)
					 putimage(X,Y,H_Ex,COPY_PUT);
				 if(AD2==10000)
					 {
					 setfillstyle(1,0);
					 bar(X-5,Y-5,X+25,Y+25);
					 AD2=0;
					 AD3++;
					 }
				 }

			 if(Spawn)
				 {
				 SpawnCount++;
				 if(SpawnCount==250000)
					 {
					 Spawn=false;
					 SpawnCount=0;
					 putimage(X,Y,H_Ship,COPY_PUT);
					 }
				 }

			 if (X<=10)
				 L_Stop=true;
			 else if(!Die&&!Spawn)
				 L_Stop=false;
			 if (X>=500)
				 R_Stop=true;
			 else if(!Die&&!Spawn)
				 R_Stop=false;
			 if (Y>=460)
				 T_Stop=true;
			 else if(!Die&&!Spawn)
				 T_Stop=false;
			 if (Y<=380)
				 B_Stop=true;
			 else if(!Die&&!Spawn)
				 B_Stop=false;

			 for(L=0;L<ShipCount;L++)
				 if(!A_Fire[L]&&!Die&&!Spawn&&!Dead[L])
					 if((random(300-Shoot)>=299-Shoot)&&(random(250-Shoot)>=249-Shoot))
						 {
						 A_Fire[L]=true;
						 AFx[L]=Ax[L];
						 AFy[L]=Ay[L];
						 }

			 for(L=0;L<ShipCount;L++)
				 if(A_Fire[L])
					 {
					 A_D[L]++;
					 if(A_D[L]>=300)
						 {
						 A_D[L]=0;
						 setfillstyle(1,0);
						 bar(AFx[L]+9,AFy[L]+20,AFx[L]+11,AFy[L]+22);
						 setfillstyle(1,14);
						 bar(AFx[L]+9,AFy[L]+25,AFx[L]+11,AFy[L]+27);
						 AFy[L]++;
						 if(AFy[L]>=485&&!Die&&!Spawn)
							 {
							 A_Fire[L]=false;
							 setfillstyle(1,0);
							 bar(1,100,515,410);
							 }
						 }
					 }

				 if(!Align)
					 for(L=0;L<ShipCount;L++)
						 {
						 if(!Dead[L])
						 {
						 Move[L]++;
						 if(Dir[L]==20)
							 {
							 M_Right[L]=false;
							 M_Left[L]=true;
							 }
						 if(Dir[L]==-20)
							 {
							 M_Right[L]=true;
							 M_Left[L]=false;
							 }
						 if(Move[L]==7000-Speed)
							 {
							 Move[L]=0;
							 putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							 if(M_Right[L])
								 {
								 Dir[L]++;
								 putimage(Ax[L]+=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 if(M_Left[L])
								 {
								 Dir[L]--;
								 putimage(Ax[L]-=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 }
						 }
						 }

					if(Align&&!Moved)
						{
						Spacing=480/(ShipCount+1);
						for(L2=0;L2<ShipCount;L2++)
							GoalX[L2]=(L2+1)*Spacing;
						for(L=0;L<ShipCount;L++)
							{
							if(GoalX[L]>=Ax[L])
								{
								M_Right[L]=true;
								M_Left[L]=false;
								GoalX[L]=int((GoalX[L]-Ax[L])/15);
								}
							else
								{
								M_Left[L]=true;
								M_Right[L]=false;
								GoalX[L]=int((Ax[L]-GoalX[L])/15);
								}
							}
						}

				if(Align)
					{
					Moved=true;
					Count++;
					if(Count==(7000-Speed))
					{ if(Count2!=15)
						{
						Count2++;
						Count=0;
						for(L=0;L<ShipCount;L++)
							{
							putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							if(M_Right[L])
								putimage(Ax[L]+=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							if(M_Left[L])
								putimage(Ax[L]-=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							}
						}
						else
						{
						Align=false;
						Moved=false;
						for(L=0;L<ShipCount;L++)
							{
							Dir[L]=0;
							M_Right[L]=true;
							M_Left[L]=false;
							}
						}
					}
				 }
				if(Dead[0]&&!A_Explode&&!Die&&!Spawn)
					return;

			 }while(!Exit);
		 }




		 //Level 3







void level_3 (int Speed, int Shoot, bool&Back2)
		 {
		 bool ScoreCheck;
		 ScoreCheck=false;
		 I=2;
		 Back2=false;
		 randomize();
		 X=230;
		 Y=420;
		 Ax.resize(10);
		 Ay.resize(10);
		 A_Fire.resize(10);
		 A_D.resize(10);
		 AFx.resize(10);
		 AFy.resize(10);
		 Dead.resize(10);
		 Move.resize(10);
		 Dir.resize(10);
		 M_Left.resize(10);
		 M_Right.resize(10);
		 GoalX.resize(10);
		 for(L=0;L<10;L++)
			 {
			 A_Fire[L]=false;
			 Dead[L]=false;
			 M_Right[L]=true;
			 M_Left[L]=false;
			 Dir[L]=0;
			 }
		 Moved=false;
		 ShipCount=10;
		 Die=false;
		 putimage(X,Y,H_Ship,COPY_PUT);
		 L=480/11;
		 Ax[0]=L;
		 Ax[1]=L*2;
		 Ax[2]=L*3;
		 Ax[3]=L*4;
		 Ax[4]=L*5;
		 Ax[5]=L*6;
		 Ax[6]=L*7;
		 Ax[7]=L*8;
		 Ax[8]=L*9;
		 Ax[9]=L*10;
		 Ay[0]=70;
		 Ay[1]=90;
		 Ay[2]=70;
		 Ay[3]=90;
		 Ay[4]=70;
		 Ay[5]=70;
		 Ay[6]=90;
		 Ay[7]=70;
		 Ay[8]=90;
		 Ay[9]=70;
		 putimage(Ax[0],Ay[0],A_Ship,COPY_PUT);
		 putimage(Ax[1],Ay[1],A_Ship,COPY_PUT);
		 putimage(Ax[2],Ay[2],A_Ship,COPY_PUT);
		 putimage(Ax[3],Ay[3],A_Ship,COPY_PUT);
		 putimage(Ax[4],Ay[4],A_Ship,COPY_PUT);
		 putimage(Ax[5],Ay[5],A_Ship,COPY_PUT);
		 putimage(Ax[6],Ay[6],A_Ship,COPY_PUT);
		 putimage(Ax[7],Ay[7],A_Ship,COPY_PUT);
		 putimage(Ax[8],Ay[8],A_Ship,COPY_PUT);
		 putimage(Ax[9],Ay[9],A_Ship,COPY_PUT);

		 setcolor(WHITE);
		 settextjustify(1,1);
		 outtextxy(230,240,Level.c_str());
		 delay(1500);
		 setfillstyle(1,BLACK);
		 bar(150,260,310,220);

		 do{
		 if(I>=1)
			 {
			 outtextxy(580,380,"Score: ");
			 outtextxy(580,420,"Lives: ");
			 if(Lives==3)
				 Livesap="3";
			 else if (Lives==2)
				 Livesap="2";
			 else
				 Livesap="1";
			 outtextxy(620,420,Livesap.c_str());
			 if(I==2)
				 {
				 setfillstyle(1,0);
				 bar(605,375,640,430);
				 outtextxy(620,380,itos(Score).c_str());
				 outtextxy(620,420,Livesap.c_str());
				 }
			 }
		 I=0;
		 Exit=false;
		 if(kbhit())
			 switch(getch())
				 {
				 case 75: if(!L_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X-=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 77: if(!R_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X+=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 80: if(!T_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y+=10,H_Ship,COPY_PUT);
										}
									break;
				 case 72: if(!B_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y-=10,H_Ship,COPY_PUT);
										}
									break;
				 case 27: Exit=true;
									break;
				 case 32: if(!Fire&&!Die)
										{
										Fire=true;
										Fx=X+10;
										Fy=Y-12;
										D=249;
										Hit=false;
										}
				 default: break;
				 }

			 if (Fire&&!Hit)
					 {
					 D++;
					 if(D>=200)
						 {
						 D=0;
						 setfillstyle(1,0);
						 bar(Fx-1,Fy+3,Fx+1,Fy+7);
						 setfillstyle(1,14);
						 bar(Fx-1,Fy-2,Fx+1,Fy+2);
						 Fy--;
						 if(Fy<=-5)
							 Fire=false;
						 }
					 }

			 for(L=0;L<ShipCount;L++)
				 if (((Fx<=Ax[L]+21)&&(Fx>=Ax[L]))&&((Fy<=Ay[L]+20)&&(Fy>=Ay[L]))&&!Dead[L])
					 {
					 ShipCount--;
					 ShipHit=L;
					 Hit=true;
					 setfillstyle(1,0);
					 bar(Ax[L]-5,Ay[L]-5,Ax[L]+25,Ay[L]+25);
					 A_Explode=true;
					 D2=4999;
					 D3=0;
					 Fx=X;
					 Fy=Y;
					 Fire=false;
					 }

			 if(A_Explode)
				 {
				 if(D3==6)
					 {
					 A_Explode=false;
					 for(L=ShipHit;L<ShipCount;L++)
						 {
						 Ax[L]=Ax[L+1];
						 Ay[L]=Ay[L+1];
						 Dead[L]=Dead[L+1];
						 M_Right[L]=M_Right[L+1];
						 M_Left[L]=M_Left[L+1];
						 Move[L]=Move[L+1];
						 }
					 Ax[ShipCount]=-200;
					 Dead[ShipCount]=true;
					 Align=true;
					 Count=0;
					 Count2=0;
					 Score+=100;
					 I=2;
					 }
				 if(D2==5000)
					 putimage(Ax[ShipHit],Ay[ShipHit],A_Ex,COPY_PUT);
				 if(D2==10000)
					 {
					 setfillstyle(1,0);
					 bar(Ax[ShipHit]-5,Ay[ShipHit]-5,Ax[ShipHit]+25,Ay[ShipHit]+25);
					 D2=0;
					 D3++;
					 }
				 D2++;
				 }

			 for(L=0;L<ShipCount;L++)
				 if (((AFx[L]<=X+19)&&(AFx[L]>=X-10))&&((AFy[L]<=Y)&&(AFy[L]>=Y-10)))
					 {
					 Die=true;
					 setfillstyle(1,0);
					 bar(AFx[L]-15,AFy[L],AFx[L]+25,AFy[L]+30);
					 A_Fire[L]=false;
					 AD2=4999;
					 AD3=0;
					 AFx[L]=-500;
					 AFy[L]=-500;
					 L_Stop=true;
					 R_Stop=true;
					 T_Stop=true;
					 B_Stop=true;
					 }

			 if(Die)
				 {
				 AD2++;
				 if(AD3==6)
					 {
					 Lives--;
					 Spawn=true;
					 I=2;
					 Back2=false;
					 X=230;
					 Y=420;
					 if(Lives>0)
						 Die=false;
					 else
						 {
						 Exit=true;
						 Back=true;
						 Back2=true;
						 H_Score_Sort(H_Scores);
						 if(Score>H_Scores[9].Scoreint)
							ScoreCheck=true;
						 }
					 if(ScoreCheck)
						{
						 H_Scores[9].Scoreint=Score;
						 cleardevice();
						 outtextxy(300,10,"Please enter your name");
						 gotoxy(35,3);
						 getline(cin,H_Scores[9].Name);
						 outfile.open("A:\\Scores.dat");
						 for(I=0;I<10;I++)
						 {
							outfile<<H_Scores[I].Name <<endl;
							outfile<<H_Scores[I].Scoreint <<endl;
						 }
						 outfile.close();
						 Score=0;
						}

					 for(L=0;L<ShipCount;L++)
						 A_Fire[L]=true;
					 }
				 if(AD2==5000)
					 putimage(X,Y,H_Ex,COPY_PUT);
				 if(AD2==10000)
					 {
					 setfillstyle(1,0);
					 bar(X-5,Y-5,X+25,Y+25);
					 AD2=0;
					 AD3++;
					 }
				 }

			 if(Spawn)
				 {
				 SpawnCount++;
				 if(SpawnCount==250000)
					 {
					 Spawn=false;
					 SpawnCount=0;
					 putimage(X,Y,H_Ship,COPY_PUT);
					 }
				 }

			 if (X<=10)
				 L_Stop=true;
			 else if(!Die&&!Spawn)
				 L_Stop=false;
			 if (X>=500)
				 R_Stop=true;
			 else if(!Die&&!Spawn)
				 R_Stop=false;
			 if (Y>=460)
				 T_Stop=true;
			 else if(!Die&&!Spawn)
				 T_Stop=false;
			 if (Y<=380)
				 B_Stop=true;
			 else if(!Die&&!Spawn)
				 B_Stop=false;

			 for(L=0;L<ShipCount;L++)
				 if(!A_Fire[L]&&!Die&&!Spawn&&!Dead[L])
					 if((random(300-Shoot)>=299-Shoot)&&(random(250-Shoot)>=249-Shoot))
						 {
						 A_Fire[L]=true;
						 AFx[L]=Ax[L];
						 AFy[L]=Ay[L];
						 }

			 for(L=0;L<ShipCount;L++)
				 if(A_Fire[L])
					 {
					 A_D[L]++;
					 if(A_D[L]>=300)
						 {
						 A_D[L]=0;
						 setfillstyle(1,0);
						 bar(AFx[L]+9,AFy[L]+20,AFx[L]+11,AFy[L]+22);
						 setfillstyle(1,14);
						 bar(AFx[L]+9,AFy[L]+25,AFx[L]+11,AFy[L]+27);
						 AFy[L]++;
						 if(AFy[L]>=485&&!Die&&!Spawn)
							 {
							 A_Fire[L]=false;
							 setfillstyle(1,0);
							 bar(1,100,515,410);
							 }
						 }
					 }

				 if(!Align)
					 for(L=0;L<ShipCount;L++)
						 {
						 if(!Dead[L])
						 {
						 Move[L]++;
						 if(Dir[L]==20)
							 {
							 M_Right[L]=false;
							 M_Left[L]=true;
							 }
						 if(Dir[L]==-20)
							 {
							 M_Right[L]=true;
							 M_Left[L]=false;
							 }
						 if(Move[L]==7000-Speed)
							 {
							 Move[L]=0;
							 putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							 if(M_Right[L])
								 {
								 Dir[L]++;
								 putimage(Ax[L]+=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 if(M_Left[L])
								 {
								 Dir[L]--;
								 putimage(Ax[L]-=2,Ay[L],A_Ship,COPY_PUT);
								 }
							 }
						 }
						 }

					if(Align&&!Moved)
						{
						Spacing=480/(ShipCount+1);
						for(L2=0;L2<ShipCount;L2++)
							GoalX[L2]=(L2+1)*Spacing;
						for(L=0;L<ShipCount;L++)
							{
							if(GoalX[L]>=Ax[L])
								{
								M_Right[L]=true;
								M_Left[L]=false;
								GoalX[L]=int((GoalX[L]-Ax[L])/15);
								}
							else
								{
								Dir[L]=0;
								M_Left[L]=true;
								M_Right[L]=false;
								GoalX[L]=int((Ax[L]-GoalX[L])/15);
								}
							}
						}

				if(Align)
					{
					Moved=true;
					Count++;
					if(Count==(7000-Speed))
					{ if(Count2!=15)
						{
						Count2++;
						Count=0;
						for(L=0;L<ShipCount;L++)
							{
							putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
							if(M_Right[L])
								putimage(Ax[L]+=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							if(M_Left[L])
								putimage(Ax[L]-=GoalX[L],Ay[L],A_Ship,COPY_PUT);
							}
						}
						else
						{
						Align=false;
						Moved=false;
						for(L=0;L<ShipCount;L++)
							{
							M_Right[L]=true;
							M_Left[L]=false;
							}
						}
					}
				 }
				if(Dead[0]&&!A_Explode&&!Die&&!Spawn)
					return;

			 }while(!Exit);
		 }




		 //BOSSES







void difficult (int Speed,int Shoot,int Bullets,int M_Speed,bool&Back2)
		 {
		 bool ScoreCheck;
		 ScoreCheck=false;
		 I=2;
		 Align=false;
		 Back2=false;
		 randomize();
		 X=230;
		 Y=420;
		 Mx=0;
		 My=0;
		 AL_Stop=false;
		 AR_Stop=false;
		 M_D=0;
		 MissileCount=0;
		 Missile=false;
		 Dodge=false;
		 S_Shot=0;
		 Ax.resize(1);
		 Ay.resize(1);
		 A_Fire.resize(5+Bullets);
		 A_D.resize(5+Bullets);
		 AFx.resize(1);
		 AFy.resize(1);
		 Dead.resize(1);
		 Move.resize(1);
		 Dir.resize(1);
		 M_Left.resize(1);
		 M_Right.resize(1);
		 GoalX.resize(1);
		 SFx.resize(5+Bullets);
		 SFy.resize(5+Bullets);
		 for(L=0;L<1;L++)
			 {
			 A_Fire[L]=false;
			 Dead[L]=false;
			 M_Right[L]=false;
			 M_Left[L]=false;
			 Dir[L]=0;
			 }
		 Moved=false;
		 ShipCount=1;
		 Die=false;
		 putimage(X,Y,H_Ship,COPY_PUT);
		 L=480/2;
		 Ax[0]=L;
		 for(L=0;L<ShipCount;L++)
			 Ay[L]=80;
		 putimage(Ax[0],Ay[0],A_Ship,COPY_PUT);

		 setcolor(WHITE);
		 settextjustify(1,1);
		 outtextxy(230,240,Level.c_str());
		 delay(1500);
		 setfillstyle(1,BLACK);
		 bar(150,260,310,220);

		 do{
		 if(I>=1)
			 {
			 outtextxy(580,380,"Score: ");
			 outtextxy(580,420,"Lives: ");
			 if(Lives==3)
				 Livesap="3";
			 else if (Lives==2)
				 Livesap="2";
			 else
				 Livesap="1";
			 outtextxy(620,420,Livesap.c_str());
			 if(I==2)
				 {
				 setfillstyle(1,0);
				 bar(605,375,640,430);
				 outtextxy(620,380,itos(Score).c_str());
				 outtextxy(620,420,Livesap.c_str());
				 }
			 }
		 I=0;
		 Exit=false;
		 if(kbhit())
			 switch(getch())
				 {
				 case 75: if(!L_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X-=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 77: if(!R_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X+=10,Y,H_Ship,COPY_PUT);
										}
									break;
				 case 80: if(!T_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y+=10,H_Ship,COPY_PUT);
										}
									break;
				 case 72: if(!B_Stop)
										{
										putimage(X,Y,H_Ship,XOR_PUT);
										putimage(X,Y-=10,H_Ship,COPY_PUT);
										}
									break;
				 case 27: Exit=true;
									break;
				 case 32: if(!Fire&&!Die)
										{
										Fire=true;
										Fx=X+10;
										Fy=Y-12;
										D=249;
										Hit=false;
										}
				 default: break;
				 }

			 if (Fire&&!Hit)
					 {
					 D++;
					 if(D>=200)
						 {
						 D=0;
						 setfillstyle(1,0);
						 bar(Fx-1,Fy+3,Fx+1,Fy+7);
						 setfillstyle(1,14);
						 bar(Fx-1,Fy-2,Fx+1,Fy+2);
						 Fy--;
						 if(Fy<=-5)
							 Fire=false;
						 }
					 }

			 for(L=0;L<ShipCount;L++)
				 if (((Fx<=Ax[L]+21)&&(Fx>=Ax[L]))&&((Fy<=Ay[L]+20)&&(Fy>=Ay[L]))&&!Dead[L])
					 {
					 ShipCount--;
					 ShipHit=L;
					 Hit=true;
					 setfillstyle(1,0);
					 bar(Ax[L]-5,Ay[L]-5,Ax[L]+25,Ay[L]+25);
					 A_Explode=true;
					 D2=4999;
					 D3=0;
					 Fx=X;
					 Fy=Y;
					 Fire=false;
					 }

			 if(A_Explode)
				 {
				 if(D3==6)
					 {
					 A_Explode=false;
					 Ax[ShipCount]=-200;
					 Dead[ShipCount]=true;
					 Align=true;
					 Count=0;
					 Count2=0;
					 I=2;
					 Score+=500;
					 }
				 if(D2==5000)
					 putimage(Ax[ShipHit],Ay[ShipHit],A_Ex,COPY_PUT);
				 if(D2==10000)
					 {
					 setfillstyle(1,0);
					 bar(Ax[ShipHit]-5,Ay[ShipHit]-5,Ax[ShipHit]+25,Ay[ShipHit]+25);
					 D2=0;
					 D3++;
					 }
				 D2++;
				 }

			 for(L=0;L<S_Shot;L++)
				 if (((SFx[L]<=X+19)&&(SFx[L]>=X-10))&&((SFy[L]<=Y)&&(SFy[L]>=Y-10)))
					 if(!Die&&!Spawn)
						 {
						 Die=true;
						 setfillstyle(1,0);
						 bar(AFx[L]-15,AFy[L],AFx[L]+25,AFy[L]+30);
						 A_Fire[L]=false;
						 AD2=4999;
						 AD3=0;
						 SFx[L]=-500;
						 SFy[L]=-500;
						 L_Stop=true;
						 R_Stop=true;
						 T_Stop=true;
						 B_Stop=true;
						 }

				 if (((Mx<=X+22)&&(Mx>=X-2))&&((My<=Y)&&(My>=Y-28)))
					 if(!Die&&!Spawn)
						 {
						 Die=true;
						 setfillstyle(1,0);
						 bar(Mx-15,My,Mx+25,My+30);
						 Mx=-500;
						 My=-500;
						 Missile=false;
						 L_Stop=true;
						 R_Stop=true;
						 T_Stop=true;
						 B_Stop=true;
						 }

			 if(Die)
				 {
				 AD2++;
				 if(AD3==6)
					 {
					 Lives--;
					 Spawn=true;
					 X=230;
					 Y=420;
					 I=2;
					 Back2=false;
					 if(Lives>0)
						 Die=false;
					 else
						 {
						 Exit=true;
						 Back=true;
						 Back2=true;
						 H_Score_Sort(H_Scores);
						 if(Score>H_Scores[9].Scoreint)
							ScoreCheck=true;
						 }
					 if(ScoreCheck)
						{
						 H_Scores[9].Scoreint=Score;
						 cleardevice();
						 outtextxy(300,10,"Please enter your name");
						 gotoxy(35,3);
						 getline(cin,H_Scores[9].Name);
						 outfile.open("A:\\Scores.dat");
						 for(I=0;I<10;I++)
						 {
							outfile<<H_Scores[I].Name <<endl;
							outfile<<H_Scores[I].Scoreint <<endl;
						 }
						 outfile.close();
						 Score=0;
						}

					 for(L=0;L<S_Shot;L++)
						 A_Fire[L]=true;
					 }
				 if(AD2==5000)
					 putimage(X,Y,H_Ex,COPY_PUT);
				 if(AD2==10000)
					 {
					 setfillstyle(1,0);
					 bar(X-5,Y-5,X+25,Y+25);
					 AD2=0;
					 AD3++;
					 }
				 }

			 if(Spawn)
				 {
				 SpawnCount++;
				 if(SpawnCount==250000)
					 {
					 Spawn=false;
					 SpawnCount=0;
					 putimage(X,Y,H_Ship,COPY_PUT);
					 }
				 }

			 if (X<=10)
				 L_Stop=true;
			 else if(!Die&&!Spawn)
				 L_Stop=false;
			 if (X>=500)
				 R_Stop=true;
			 else if(!Die&&!Spawn)
				 R_Stop=false;
			 if (Y>=460)
				 T_Stop=true;
			 else if(!Die&&!Spawn)
				 T_Stop=false;
			 if (Y<=380)
				 B_Stop=true;
			 else if(!Die&&!Spawn)
				 B_Stop=false;

			 for(L=0;L<ShipCount;L++)
				 if(!Die&&!Spawn&&!Dead[L])
					 if((random(220-Shoot)>=219-Shoot)&&(random(220-Shoot)>=219-Shoot))
						 {
						 if(S_Shot<5+Bullets)
							 {
							 S_Shot++;
							 A_Fire[S_Shot-1]=true;
							 SFx[S_Shot-1]=Ax[L];
							 SFy[S_Shot-1]=Ay[L];
							 }
						 }

			 for(L=0;L<S_Shot;L++)
				 if(A_Fire[L])
					 {
					 A_D[L]++;
					 if(A_D[L]>=300)
						 {
						 A_D[L]=0;
						 setfillstyle(1,0);
						 bar(SFx[L]+9,SFy[L]+20,SFx[L]+11,SFy[L]+22);
						 setfillstyle(1,14);
						 bar(SFx[L]+9,SFy[L]+25,SFx[L]+11,SFy[L]+27);
						 SFy[L]++;
						 if(SFy[L]>=485&&!Die&&!Spawn)
							 {
							 for(L2=L;L<S_Shot-1;L++)
								 {
								 SFx[L]=SFx[L+1];
								 SFy[L]=SFy[L+1];
								 A_Fire[L]=A_Fire[L+1];
								 A_D[L]=A_D[L+1];
								 }
							 S_Shot--;
							 A_Fire[L]=false;
							 setfillstyle(1,0);
							 bar(1,100,515,410);
							 }
						 }
					 }

				 if(!Align&&!Dodge)
					 for(L=0;L<ShipCount;L++)
						 {
						 if(!Dead[L])
						 {
						 Move[L]++;
						 if(X<Ax[L])
							 {
							 Del++;
							 if(Del==40000)
								 {
								 Del=0;
								 M_Right[L]=false;
								 M_Left[L]=true;
								 }
							 }
						 if(X>Ax[L])
							 {
							 Del++;
							 if(Del==40000)
								 {
								 Del=0;
								 M_Right[L]=true;
								 M_Left[L]=false;
								 }
							 }
						 if(X==Ax[L])
							 {
							 M_Right[L]=false;
							 M_Left[L]=false;
							 }
						 if(Move[L]==5000-Speed)
							 {
							 Move[L]=0;
							 if(M_Right[L])
								 {
								 putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
								 putimage(Ax[L]+=5,Ay[L],A_Ship,COPY_PUT);
								 }
							 if(M_Left[L])
								 {
								 putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
								 putimage(Ax[L]-=5,Ay[L],A_Ship,COPY_PUT);
								 }
							 }
						 }
						 }

				for(L=0;L<ShipCount;L++)
				 if(!Dodge)
				 if (((Fx<=Ax[L]+35)&&(Fx>=Ax[L]-15))&&((Fy<=Ay[L]+50)&&(Fy>=Ay[L]))&&!Dead[L])
					 {
					 Dodge=true;
					 DirSet=false;
					 Count=0;
					 Count2=0;
					 }

				L=0;
				if(Dodge)
					{
					if(!DirSet&&(random(10)+1)==1)
						if(Ax[L]+10>Fx)
							{
							M_Right[L]=true;
							M_Left[L]=false;
							DirSet=true;
							if(AR_Stop)
								{
								M_Right[L]=false;
								M_Left[L]=true;
								}
							}
						else
							{
							M_Right[L]=false;
							M_Left[L]=true;
							DirSet=true;
							if(AL_Stop)
								{
								M_Right[L]=true;
								M_Left[L]=false;
								}
							}
					else
						DirSet=true;
					Count++;
					if(Count==2000-Speed)
						if(Count2!=6)
							{
							Count=0;
							Count2++;
							if(M_Right[L])
								{
								putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
								putimage(Ax[L]+=5,Ay[L],A_Ship,COPY_PUT);
								}
							else
								{
								putimage(Ax[L],Ay[L],A_Ship,XOR_PUT);
								putimage(Ax[L]-=5,Ay[L],A_Ship,COPY_PUT);
								}
							}
						else if(Count2==6)
							{
							Dodge=false;
							DirSet=false;
							}
					}

				if(!Missile&&!Spawn&&!Die)
					MissileCount++;

				if(MissileCount==100000-Speed)
					{
					Missile=true;
					MissileCount=0;
					L=0;
					Mx=Ax[L];
					My=Ay[L];
					}

				if(Missile&&!Die&&!Spawn)
					{
					M_D++;
					if(M_D>=(2000-M_Speed))
						 {
						 M_D=0;
						 setfillstyle(1,0);
						 setcolor(0);
						 fillellipse(Mx+10,My+25,10,10);
						 setfillstyle(1,11);
						 setcolor(11);
						 fillellipse(Mx+10,My+30,2,4);
						 My++;
						 if(My>=485&&!Die&&!Spawn)
							 Missile=false;
							 if(Mx<X)
								 Mx++;
							 else if(Mx>X)
								 Mx--;
						 }
					 }

				if(Missile&&(Die||Spawn))
					{
					Missile=false;
					setfillstyle(1,0);
					setcolor(0);
					fillellipse(Mx+10,My+25,10,10);
					Mx=-500;
					My=-500;
					}

			 L=0;
			 if (Ax[L]<=10)
				 AL_Stop=true;
			 else if(!Die&&!Spawn)
				 AL_Stop=false;
			 if (Ax[L]>=500)
				 AR_Stop=true;
			 else if(!Die&&!Spawn)
				 AR_Stop=false;

				if(Dead[0])
					return;

			 }while(!Exit);
		 }