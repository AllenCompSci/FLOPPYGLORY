//Steve He
//Kevin Lemmon
//Missile Command Game
//4th Period

//VARIABLE DICTIONARY
////////////////////////////////////////////////////////////////
//constants:
//Y_END - Is the point on the y axis where all the missles stop
//LEVEL_MAX - Highest level possible

//Structs:
//Score_Data - Holds the players score and name
//Click_Data - The data used for the turret and its corrinants
//Move_Prop - The Move properties of the missiles
//Missile - The data for when the missile is being used
//Level_Data - The data that pertains to a certain level

//Unsigned:
//Missile_Intro - unsigned used for the pointer
//Base_S - unsigned used for the pointer
//Turret_S - unsigned used for the pointer
//Ground_S - unsinged used for the pointer

//void far:
//*Intro_Pointer - pointer to locate intro missile
//*Base_Pointer - pointer of which the base image is located
//*Turret_Pointer - pointer of which the turret image is located
//*Ground_Pointer - pointer of which the ground image is located

//int:
//I - variable used to keep values
//J - Variable used to keep values
//L - variable used to keep values
//X - assigns a x coordinate
//Y - assigns a y coordinate
//Xi - X initial
//Xf - X final
//Yi - Y initial
//Yf - Y final
//Base - base number
//Color - decides random color when used
//X_rel - relitive horizontal size of turret vs base
//Y_rel - relitive virtical size of base vs turret
//X_position - position of x
//X_Big - This is the biggest X
//X_Small - Smallest X
//Timer_Max - Used to keep the timer max value
//Timer_Count - Used to keep the counted value
//Exist_Total - Has the total existing missile number
//R_Done - Hold the radius done value
//Hit_Color - color of the position of the pixel
//Temp_Ammo - Ammo count
//Low_Element - element with the smallest data
//Hold - holds there till explosion
//DelY - delete Y
//X_Pos - X position
//Y_Pos - Y position
//Slope - slope number
//Timer - Timer counter for moving
//Speed - Speed counter
//Speed_Const - speed constant
//X_Start - starting x for enemy missile
//X_End - ending x for enemy missile
//Exist - number of existing missiles
//Del_Done - deletion number
//DelY_Pos - y deletion position
//DelX_Pos - x deletion position
//Exlpode_Done - explosion value for finishing
//Hit - hit value
//Missle_Number - Number of missiles
//Base_Count - number of remaining bases
//Ammo - Number of ammo in level


//double:
//R - Radius value
//R_Clear - Clears the radius value
//Delay - delay for the level


//long:
//Score - Player's score
//Temp_Score - temporary holder for score
//HighScore - The highscore


//apvector:
//Enemy - Enemy missile holding array
//Level - the level holding array
//Scores - holds the scores of the game
//Base - Bases in level


//apstring:
//Name - Name of player
//Trash - Clears getlines

//Score_Data:
//Temp - holds the score data

//Click_Data:
//Click - holds mouse info

//char:
//Repeat - letter to repeat

//Image:
//BG - background image holder for the intro page background bitmap
//Base - base image holder for the game background bitmap
//Turret - turret image holder for the games turret bitmap
//Ground - ground of which the base sits on during game play


//Prototype's:
//void intro - introduction of game
//void background - the back ground creating
//void init - starts all the data collection
//void level_init - starts level
//void level_display - displays level on
//void create_base - creates bases on screen
//void explode - function to explode missiles
//void destroy_base - Function to check and destroy base
//void missile_count - function to count missiles
//void show_score - function to show score
//void click_boom - function to click for turret missile
//void launch - function to launch missile
//void check_collide - function to check collisions
//void gameover - function if loose
//void win - function if win
//void high_score - function which has highscores


//ifstream:
//In - Input


//ofstream:
//Out - output

//Libraries
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <graphics.h>
#include <apvector.h>
#include <apstring.h>
#include <stdlib.h>
#include <dos.h>
#include <alloc.h>
#include <fstream.h>
#include "bitmap.h"
#include <gmouse.h>
#include <math2.h>

//Constants section
const int Y_END = 440; //Ending Y-position
const int LEVEL_MAX=6;
//Structures Section
struct Score_Data
{
 apstring Name;
 long Score;
};

struct Click_Data
{
 int X;
 int Y;
 int Temp;
 int Hold;
 int X_Temp;
 int Y_Temp;
};

struct Move_Prop
{
 int X;
 int Y;            //Cycles 0 through Slope#
 int DelY;
};

struct Missile
{
 Move_Prop Move;
 int Slope;        //Slope  = Change in Y, then add 1 X
 int Y_Pos;        //Y_pos += Slope when Y=Slope;
 int X_Pos;
 int Timer;
 int Speed;
 int Speed_Const;
 int X_Start;      //Start X Position
 int X_End;        //End X Position
 int Exist;				 //Alive = 1, Dead = 0
 int Del_Done;
 int DelY_Pos;
 int DelX_Pos;
 int Explode_Done;
 int Hit;
 double R;
};

struct Level_Data
{
 int Missile_Number;
 double Delay;
 int Base_Count;
 int Ammo;
 apvector<int> Base;
};

//Global Variables Section
char Repeat;
int GrDriver;
int GrMode;
int ErrorCode;
int X_Big, X_Small, I, J, Timer_Max, Timer_Count, Exist_Total;
double R, R_Clear;//Radius
int R_Done;
int Hit_Color;
int L;
int Temp_Ammo;
long Score, Temp_Score;
apvector <Missile> Enemy (0);
apvector <Level_Data> Level(LEVEL_MAX); //Put All the Stuff into a Loop Using
apvector <Score_Data> Scores (10);
Click_Data Click;								  //Level
char Key;
bool Quit;
char Again;
long S;

//Prototype Section
void gr_start(int &, int&, int&);  //Initializes Graphics
void intro(void); //Creates Intro Animation
void background(void); //Sets Intro Background
void init(double&,apvector<Missile>&,Click_Data&,int); //Init Prelim Data
void level_init(apvector<Level_Data>&); //Sets level data
void level_display(int, long&, apvector<Level_Data>); //Displays Victory scr
void create_base(void); //Creates Bases
void explode(apvector<Missile> &, int); //Explosion of Missiles
void destroy_base(long&,apvector<Missile>, int, apvector<Level_Data>&,int);
void missile_count(apvector<Missile>,apvector<Level_Data>,int,int&,int&);
void show_score(int&,long,apvector<Level_Data>,int); //Displays Ammo/Score
void click_boom(Click_Data&,double&,apvector<Level_Data>&,int);//Shoots Mis.
void launch(apvector<Missile>&,int&); //Launches an enemy missile
void check_collide(int&,apvector<Missile>&,long&,int&); //Checks Collisions
void gameover(int &); //Gameover Screen
void win(void);       //Win Screen
void high_score(long, apvector<Score_Data>&); //Scoring Mechanism

//Beginning of Program

void main()
{
 randomize();
 gr_start(GrDriver,GrMode,ErrorCode);

 intro();		//Intro Animation

 do{
		cleardevice();

		background();     //Menu
		getch();
		getch();

		Level.resize(0);
		Level.resize(LEVEL_MAX);
		L=0;

		level_init(Level);  //Sets up Level Data

		Score=0; //Initial Score = 0


		for(L=0;L<LEVEL_MAX;L++)    //Level Loop
		 {
			level_display(L,Score,Level); //Displays Current Level & Scores

			graphinit(GR16);              //Initializes 16bit Graphics
			create_base();
			SetMouse();
			ShowMouse();
			Quit=false;                   //Default Quit to False

			Temp_Ammo=Level[L].Ammo;      //Start - Set Up Counters
			setcolor(15);
			settextstyle(0,0,1);
			moveto(1,470);
			outtext("Ammo: ");
			moveto(50,470);
			outtext(itos(Level[L].Ammo).c_str());

			moveto(300,470);
			outtext("Score: ");
			moveto(410,470);
			outtext(ltos(Score).c_str());                  //End - Set up Counters

			init(R,Enemy,Click,L);     //Initializes All Missile Data (slope,etc)

			//Launch Missiles
			do{
					Timer_Count=0;         //Initializes Timer & Total Existing
					Exist_Total=0;

					//Counts the # Missiles Being Shot
					missile_count(Enemy,Level,L,Timer_Count,Exist_Total);

					do{
						 for(I=0; I<Level[L].Missile_Number; I++)
							 {
								show_score(Temp_Ammo,Score,Level,L); //Updates Score

								if(Enemy[I].Timer==0&&Enemy[I].Exist==1)
									{
									 //Start Explode
									 click_boom(Click,R,Level,L);

									 //Checks for Escape Key
									 if(kbhit())
										{
										 Key=getch();
										 if(Key==27)
											 Quit=true;
										}

									//Fire Missile
									launch(Enemy,Exist_Total);
									}

								//Creates Enemy Missile Explosions
								if(Enemy[I].Hit==1&&Enemy[I].Explode_Done==0)
									 explode(Enemy,I);
							}
						}while(Exist_Total>0&&Level[L].Base_Count>0&&!Quit);
						//Loop Until No Missiles & No Base & Quit

					Timer_Max-=1;  //Subtracts one from Highest Timer


					//Subtract one from all timers
					for(I=0; I<Level[L].Missile_Number; I++)
						{
						 if(Enemy[I].Exist==1)
							Enemy[I].Timer-=1;
						}
				 }while(Timer_Max>=0&&Level[L].Base_Count>0&&!Quit);
					//Exhausts all Timers - Quit Key

			 if(Level[L].Base_Count==0)  //if No More Bases, display gameover
				{
				 gameover(L);
				 high_score(Score, Scores);
				}

			 if(L==LEVEL_MAX-1)          //if last level, display win
				{
				 win();
				 high_score(Score, Scores);
				}

			 if(Quit)                   //if Quit=true, exit for-loop
				{
					L=LEVEL_MAX-1;
					HideMouse();
				}

		 } //Level Loop End

		cleardevice();
		gotoxy(1,1);
		cout<<"Would you like to play again (y/n)? ";
		cin>>Again;

	 }while(Again=='y'||Again=='Y');   //Loops Game Again
}
//End of Void Main


void gr_start(int &GrDriver, int &GrMode, int &ErrorCode)
{
 GrDriver=VGA;
 GrMode=VGAHI;
 initgraph(&GrDriver, &GrMode, "C:\\TC\\BGI");
 ErrorCode=graphresult();
 if(ErrorCode!=grOk)
	{
	 clrscr();
	 cout<<"Error Code: "<<ErrorCode<<endl;
	 cout<<"Press Enter to Continue. ";
	 getch();
	 exit(1);
	}
};



//void intro(void)
//Function:
//Displays intro animation
void intro(void)
{
//void intro(void);

//Local Variables
unsigned Missile_Intro;
void far *Intro_Pointer;
int I,X,Y,R,Color;

//pointer for intro missile
	cleardevice();
	setcolor(15);
	setfillstyle(1,15);
	bar(0,0,3,7);
	Missile_Intro=imagesize(0,0,3,7);
	Intro_Pointer=farmalloc(Missile_Intro);
	getimage(0,0,3,7,Intro_Pointer);

//creates the title for the intro
	cleardevice();
	delay(1000);
	setcolor(15);
	settextstyle(3,0,4);
	moveto(40,150);
	outtext("Super Ultra Missle Command 20XX");
	delay(800);
	moveto(58,190);
	outtext("Turbo Alpha Platinum Edition ++");
	delay(800);
	moveto(240,240);
	outtext("X-TREME!");
	delay(2000);

//creates the exploding titles which blow up.
	for(I=20;I<100;I++)
		{
		do{
			X=random(578);
			Y=random(300);
			}while(Y<150);
		R=random(50);
		Color=WHITE;//random(15);
		setcolor(BLACK);
		setfillstyle(1,Color);
		fillellipse(X,Y,R,R);
		delay(15);
		setfillstyle(1,BLACK);
		fillellipse(X,Y,R,R);
		delay(55);
		}

//press enter sign
	setcolor(15);
	moveto(225,300);
	outtext("Press Enter");
	moveto(225,340);
	outtext("to continue");

//new title with flashing effect
	do{
		setcolor(random(14)+1);
		settextstyle(3,0,4);
		moveto(40,150);
		outtext("Super Ultra Missle Command 20XX");
		moveto(58,190);
		outtext("Turbo Alpha Platinum Edition ++");
		moveto(240,240);
		outtext("X-TREME!");
		delay(50);
		}while(!kbhit());

//firing of intro missle from bottom
	for(Y=getmaxy();Y>(getmaxy())/2;Y--)
		{
		putimage((getmaxx()/2),Y,Intro_Pointer,COPY_PUT);
		delay(15);
		putimage((getmaxx()/2),Y,Intro_Pointer,XOR_PUT);
		do{
			X=random(getmaxx()/2+7);
			}while(X<getmaxx()/2-4);
		putpixel(X,Y+7,15);
		}

//explosion of the intro missile
	for(R=0;R<400;R++)
		{
		setcolor(random(14)+1);
		setfillstyle(1,(random(14))+1);
		fillellipse(getmaxx()/2,getmaxy()/2,R,R);
		}
	cleardevice();
};


//void background(void)
//Function:
//Displays main screen with simple instructions and logo
//Press enter to continue, escape to exit
void background(void)
{
char Key;

image BG;

BG.open("A:\\MenuBG.bmp");
BG.draw(0,0);

setcolor(15);
settextstyle(0,0,1);
moveto(235,229);
outtext("Object:");
moveto(235,242);
outtext("Fire Missiles from your");
moveto(235,256);
outtext("TURRET at falling ENEMY");
moveto(235,271);
outtext("missiles in order to");
moveto(235,284);
outtext("protect your BASES");
moveto(235,307);
outtext("Controls:");
moveto(235,323);
outtext("mouse - click area to fire");
moveto(235,336);
outtext("        a missile from the");
moveto(235,347);
outtext("        turret");
moveto(270,382);
outtext("Press a key to start");
moveto(270,394);
outtext("ESC to exit");

while(!kbhit())
	{
	 if(kbhit())
		{
		 Key=getch();
		 if(Key==27)
			{
			 exit(0);
			}
		 else
			 Quit=false;
		}
	}

};



//void init(double&R,apvector<Missile>&Enemy,Click_Data&Click,int L)
//Function:
//Initializes Preliminary Missile Data.
//Ex) Sets slope, timer, speed,etc.
void init(double&R,apvector<Missile>&Enemy,Click_Data&Click,int L)
{
 int X_Big;
 int X_Small;
 int I;
 int J;

 //Establishes # Missiles and Resizes Accordingly
 Enemy.resize(0);
 Enemy.resize(Level[L].Missile_Number);
 R=30;
 Click.Hold=0;

 //Establishes Missile Initialization Data (Time, Speed, Slope, Etc)
 for(I=0; I<Level[L].Missile_Number; I++)
	{
	 Enemy[I].Timer=random(5);
	 Enemy[I].Speed=random(10)+1;
	 Enemy[I].Move.Y=0;
	 Enemy[I].Exist=1;
	 Enemy[I].Explode_Done=0;
	 Enemy[I].R=0;
	 Enemy[I].Hit=0;

	 //Establishes Slope:
	 do{                     //DW C - Checks Slope !=0
		 do{                   //Do While A - Slope Has To Be Whole Number
				do{
						Enemy[I].X_Start=random(getmaxx()); //DoWhile B - Check D.x !=0

						//Base Positions
						switch(random(6))
						{
						 case 0: Enemy[I].X_End=60;
										 break;
						 case 1: Enemy[I].X_End=140;
										 break;
						 case 2: Enemy[I].X_End=220;
										 break;
						 case 3: Enemy[I].X_End=getmaxx()-60;
										 break;
						 case 4: Enemy[I].X_End=getmaxx()-140;
										 break;
						 case 5: Enemy[I].X_End=getmaxx()-220;
						};

						if(Enemy[I].X_Start>Enemy[I].X_End)
							{
							 X_Big=Enemy[I].X_Start;
							 X_Small=Enemy[I].X_End;
							}
						else
							{
							 X_Big=Enemy[I].X_End;
							 X_Small=Enemy[I].X_Start;
							}
					}while(X_Big-X_Small==0);
					 //End DoWhile B

			 }while(440%(X_Big-X_Small)!=0||440/(X_Big-X_Small)>40);
				//End DoWhile A

		 if(Enemy[I].X_Start<Enemy[I].X_End) //Calculate Slope Based on Position
			 Enemy[I].Slope=(getmaxy()-40)/(Enemy[I].X_End-Enemy[I].X_Start);
		 else
			 Enemy[I].Slope=(getmaxy()-40)/(Enemy[I].X_Start-Enemy[I].X_End);
		}while(Enemy[I].Slope==0||Enemy[I].Slope==1); //DoWhile C - End
	}
	//Ends for Loop for Initialization Data

	//Sets Timer_Max, Highest Timer to Control Launch Loop
	for(I=0; I<Level[L].Missile_Number; I++)
		{
		 for(J=I+1; J<Level[L].Missile_Number; J++)
		 {
			if(Enemy[J].Timer>Enemy[I].Timer)
				Timer_Max=Enemy[J].Timer;
			else
				Timer_Max=Enemy[I].Timer;
		 }
		}

	for(I=0; I<Level[L].Missile_Number; I++)
		{
		 Enemy[I].Y_Pos=0;
		 Enemy[I].X_Pos=Enemy[I].X_Start;
		 Enemy[I].Speed_Const=Enemy[I].Speed;
		}

 //Ends Initialization Data
};



//void level_init(apvector<Level_Data>&Level)
//Function:
//Initializes preliminary level data
//Ex) #Bases Max, Missile Number, Ammo
void level_init(apvector<Level_Data>&Level)
{
 int L;
 int I;

 for(L=0; L<LEVEL_MAX; L++)
	{
	 Level[L].Base.resize(7);

	 for(I=0;I<7;I++)
		{
		 Level[L].Base[I]=0;
		}
	 Level[L].Base_Count=6;
	 Level[L].Missile_Number=(L+1)*12;
	 Level[L].Ammo=Level[L].Missile_Number-3*L;
	}

};


//void level_display(int L, long&Score, apvector<Level_Data> Level)
//Function:
//Displays the level/score screen at the beginning of each level
void level_display(int L, long&Score, apvector<Level_Data> Level)
{
 cleardevice();
 image BG;

 HideMouse();
 if(L==0)
 {
	moveto(230, getmaxy()/2-100);
	settextstyle(0,0,1);
	outtext("Level One!");
 };

 if(L>0)
	{
		BG.open("A:\\Victory.bmp");
		BG.draw(0,0);
		moveto(280,165);
		outtext("Level ");
		moveto(345,165);
		outtext(itos(L+1).c_str());
		moveto(200,210);
		outtext("Bases Survived: ");
		moveto(322,210);
		outtext(itos(Level[L-1].Base_Count).c_str());
		moveto(330,210);
		outtext(" x 5000 = ");
		moveto(405,210);
		outtext(ltos(Level[L-1].Base_Count*5000).c_str());
		Score+=Level[L-1].Base_Count*5000;

		moveto(200,230);
		outtext("Ammo Left: ");
		moveto(322,230);
		if(Level[L-1].Ammo==0)
			outtext("0");
		else
			outtext(itos(Level[L-1].Ammo).c_str());
		moveto(330,230);
		outtext(" x 100 = ");
		moveto(405,230);
		if(Level[L-1].Ammo==0)
			outtext("0");
		else
			outtext(ltos(Level[L-1].Ammo*100).c_str());
		Score+=Level[L-1].Ammo*100;

	}
 moveto(230,250);
 outtext("Press Enter To Continue");
 getch();
};

//void create_base(void)
//Function:
//Creates Bases & Turret Along The Bottom
void create_base(void)
{
 int X;
 int Y;
 int X_rel;   //Relative Horizontal Size of Turret vs Base
 int Y_rel;   //Relative Vertical Size of Turret vs Base
 int X_position;
 int I;
 image Base;
 image Turret;
 image Ground;

 unsigned Base_S;
 unsigned Turret_S;
 unsigned Ground_S;
 void far *Base_Pointer, *Turret_Pointer, *Ground_Pointer;


 X=40;
 Y=20;
 X_rel=0;
 Y_rel=0;
 Base.open("A:\\base.bmp");
 Turret.open("A:\\turret.bmp");
 Ground.open("A:\\ground.bmp");
 //Creates Image for Bases to Base
 Base.draw(0,0);
 Base_S=imagesize(0,0,X,Y);
 Base_Pointer=farmalloc(Base_S);
 getimage(0,0,X,Y,Base_Pointer);
 cleardevice();

 //Creates Image for Turret
 Turret.draw(0,0);
 Turret_S=imagesize(0,0,X+X_rel,Y+Y_rel);
 Turret_Pointer=farmalloc(Turret_S);
 getimage(0,0,X+X_rel,Y+Y_rel,Turret_Pointer);
 cleardevice();

 //Create Image for Ground
 Ground.draw(0,0);
 Ground_S=imagesize(0,0,getmaxx(),25);
 Ground_Pointer=farmalloc(Ground_S);
 getimage(0,0,getmaxx(),25,Ground_Pointer);
 cleardevice();

 Base.close();
 Turret.close();
 Ground.close();


	X_position=X;
 for(I=0; I<=2; I++)    //Places Bases on Left
	{
	 putimage(X_position, getmaxy()-60, Base_Pointer, COPY_PUT);
	 X_position+=X+40;
	}

 X_position=getmaxx()-X-40;    //Places Bases on Right

 for(I=0; I<=2; I++)
	{
	 putimage(X_position, getmaxy()-60, Base_Pointer, COPY_PUT);
	 X_position-=X+40;
	}


 //Places Turrent In Middle:
 putimage(getmaxx()/2-X/2, getmaxy()-60, Turret_Pointer, COPY_PUT);

 //Places Ground

 putimage(0,getmaxy()-40, Ground_Pointer, COPY_PUT);

}

//void explode(apvector<Missile> &Enemy, int I)
//Function:
//Creates Explosion effect for enemy missiles when they are hit
void explode(apvector<Missile> &Enemy, int I)
{
 int Color;

 setcolor(0);

 do{
		Color=random(13)+1;
	 }while(Color==2);
 if(Enemy[I].R<=5)
	setfillstyle(1,Color);

 Enemy[I].R+=.15;
 fillellipse(Enemy[I].X_Pos,Enemy[I].Y_Pos,Enemy[I].R,Enemy[I].R);

	if(Enemy[I].R>=20)
	{
	 setfillstyle(1,0);
	 fillellipse(Enemy[I].X_Pos,Enemy[I].Y_Pos,Enemy[I].R,Enemy[I].R);
	 Enemy[I].Explode_Done=1;
	}

};

//void destroy_base(etc.)
//Function:
//Checks collision of missile versus base location and allocates score
//accordingly
void destroy_base(long&Score,apvector<Missile> Enemy, int I, apvector<Level_Data> &Level, int L)
{
 int Xi, Xf;
 int Yi, Yf;
 int Base;

 if(Level[L].Base_Count==0)
	cleardevice();
 else{

			if(Enemy[I].X_Pos>540)
				Base=6;
			else if(Enemy[I].X_Pos>460)
							Base=5;
					 else if(Enemy[I].X_Pos>380)
									Base=4;
								else if(Enemy[I].X_Pos>180)
											 Base=3;
										 else if(Enemy[I].X_Pos>100)
														Base=2;
													else
														Base=1;


			setfillstyle(1,0);

			switch(Base)
				{
				 case 1: Xi=40;
								 Xf=80;
								 break;
				 case 2: Xi=120;
								 Xf=160;
								 break;
				 case 3: Xi=200;
								 Xf=240;
								 break;
				 case 4: Xi=395;
								 Xf=440;
								 break;
				 case 5: Xi=475;
								 Xf=520;
								 break;
				 case 6: Xi=555;
								 Xf=600;
								 break;
			}

		 if(Level[L].Base[Base]!=1)
				{
				 Level[L].Base_Count-=1;
				 Level[L].Base[Base]=1;
				 Score-=5000;
				}

		 bar(Xi,getmaxy()-60,Xf,getmaxy()-40);
 //putimage(X, getmaxy()-60, Clear_Base, COPY_PUT);
	}

};


//void missile_count(etc)
//Function:
//Counts the # of missiles that are ready to launch
void missile_count(apvector<Missile>Enemy,apvector<Level_Data> Level,int L,int &Timer_Count,int &Exist_Total)
{
 int I;

 //Get # of Missiles With Timer = 0, Ready to Launch
 for(I=0; I<Level[L].Missile_Number; I++)
	{
	 if(Enemy[I].Timer==0&&Enemy[I].Exist==1)
		 {
			Timer_Count+=1;
			Exist_Total+=1;
		 }
	}
};


//void show_score(etc)
//Function:
//Updates Scores & Displays Score/Ammo Data
void show_score(int&Temp_Ammo,long Score,apvector<Level_Data> Level,int L)
{
 if(Level[L].Ammo<Temp_Ammo)
	 {
		setfillstyle(1,0);
		bar(50,470,200,480);
		bar(410,470,610,480);

		setcolor(15);
		settextstyle(0,0,1);
		moveto(50,470);
		outtext(itos(Level[L].Ammo).c_str());
		Temp_Ammo=Level[L].Ammo;
		moveto(410,470);
		outtext(ltos(Score).c_str());
	 }
};

//void click_boom
//Function:
//Allows user to click on screen and creates location at spot
void click_boom(Click_Data&Click,double&R,apvector<Level_Data>&Level,int L)
{
 int Color;

 if(Click.Hold==0||R==30)
		{
		 ShowMouse();
		 Click.Temp=GetMouseButton();
		 Click.X_Temp=GetMouseX();
		 Click.Y_Temp=GetMouseY();
		 R=0;
		}

 Click.Hold=Click.Temp;
 Click.X=Click.X_Temp;
 Click.Y=Click.Y_Temp;

 if(Click.Hold!=0&&R<=30&&Level[L].Ammo>0)
		{
		 HideMouse();
		 setcolor(0);

		 do{
			 Color=random(13)+1;
			 }while(Color==2);

		 if(R<=10)
			 setfillstyle(1,Color);

		 R+=.15;
		 fillellipse(Click.X,Click.Y,R,R);
		 if(R>=30)
			{
			 Click.Hold=0;
			 setfillstyle(1,0);
			 fillellipse(Click.X,Click.Y,R,R);
			 Level[L].Ammo--;
			}
		}
};


//void launch(etc);
//Function:
//Moves Missiles from top simultaneously
void launch(apvector<Missile>&Enemy,int&Exist_Total)
{
 if(Enemy[I].Y_Pos==Y_END)
		{
		 Enemy[I].Exist=0;
		 Exist_Total-=1;
		 Enemy[I].Hit=1;
		 Enemy[I].Del_Done=0;
		 Enemy[I].Move.DelY=0;
		 Enemy[I].DelY_Pos=0;
		 Enemy[I].DelX_Pos=Enemy[I].X_Start;
		 Enemy[I].Hit=1;
		 destroy_base(Score, Enemy, I, Level, L);

		 do{      //Start DoWhile Blah
				 Enemy[I].Move.DelY++;
				 Enemy[I].DelY_Pos++;
				 putpixel(Enemy[I].DelX_Pos,Enemy[I].DelY_Pos,0);
				 if(Enemy[I].Move.DelY==Enemy[I].Slope)
						{
						 if(Enemy[I].X_Start<Enemy[I].X_Pos)
							 Enemy[I].DelX_Pos++;
						 else
							 Enemy[I].DelX_Pos--;

						 Enemy[I].Move.DelY=0;
						 putpixel(Enemy[I].DelX_Pos,Enemy[I].DelY_Pos,0);
						}

				 if(Enemy[I].DelY_Pos==Enemy[I].Y_Pos)
						Enemy[I].Del_Done=1;     //1=Done Clearing

			 }while(Enemy[I].Del_Done!=1);

		}

	if(Enemy[I].Speed==0)
		{
		 Enemy[I].Move.Y+=1;
		 Enemy[I].Y_Pos+=1;
		 Enemy[I].Speed=Enemy[I].Speed_Const;

		 Hit_Color=getpixel(Enemy[I].X_Pos,Enemy[I].Y_Pos);
		 check_collide(Hit_Color,Enemy,Score,Exist_Total);

		 putpixel(Enemy[I].X_Pos, Enemy[I].Y_Pos, 2);
		}


 for(S=0; S<93500; S++);

 if(Enemy[I].Move.Y==Enemy[I].Slope&&Enemy[I].Exist==1)
		{
		 Enemy[I].Move.Y=0;

		 if(Enemy[I].X_Start<Enemy[I].X_End)
				Enemy[I].X_Pos+=1;
		 else
				Enemy[I].X_Pos-=1;

		 putpixel(Enemy[I].X_Pos, Enemy[I].Y_Pos, 2);
		}

 Enemy[I].Speed-=1;
};


//void check_collide(etc)
//Function:
//Checks collision of explosion circle versus missiles
void check_collide(int&Hit_Color,apvector<Missile>&Enemy,long&Score,int&Exist_Total)
{
 if(Hit_Color!=0&&Hit_Color!=2&&Hit_Color!=15)//Hit Reg'd
		 {
			Enemy[I].Exist=0;
			Exist_Total-=1;
			Enemy[I].Del_Done=0;
			Enemy[I].Move.DelY=0;
			Enemy[I].DelY_Pos=0;
			Enemy[I].DelX_Pos=Enemy[I].X_Start;
			Enemy[I].Hit=1;
			Score+=1000;

			if(Enemy[I].Y_Pos>getmaxy()-80)
					destroy_base(Score,Enemy,I,Level,L);

			do{      //Start DoWhile Blah
				 Enemy[I].Move.DelY++;
				 Enemy[I].DelY_Pos++;
				 putpixel(Enemy[I].DelX_Pos,Enemy[I].DelY_Pos,0);
				 if(Enemy[I].Move.DelY==Enemy[I].Slope)
						{
						 if(Enemy[I].X_Start<Enemy[I].X_Pos)
							 Enemy[I].DelX_Pos++;
						 else
							 Enemy[I].DelX_Pos--;

						 Enemy[I].Move.DelY=0;
						 putpixel(Enemy[I].DelX_Pos,Enemy[I].DelY_Pos,0);
						}

				 if(Enemy[I].DelY_Pos==Enemy[I].Y_Pos)
						Enemy[I].Del_Done=1;     //1=Done Clearing

				 }while(Enemy[I].Del_Done!=1); //End DoWhile Blah
		 }
};


//void gameover()
//	Function:
//Displays Gameover Screen
void gameover(int &L)
{
 image BG;

 cleardevice();
 clrscr();

 BG.open("A:\\gameover.bmp");
 BG.draw(0,0);

 moveto(230, 400);
 settextstyle(0,0,1);
 outtext("Press Enter to Continue");
 L=LEVEL_MAX;
 getch();
};

void win(void)
{
 apstring Trash;
 image BG;

 cleardevice();
 clrscr();
 HideMouse();

 BG.open("A:\\Win.bmp");
 BG.draw(0,0);

 getch();
};

//void high_score
//Function:
//Updates high score
void high_score(long Score, apvector<Score_Data>&Scores)
{
 ifstream In;
 ofstream Out;

 long Highscore;
 apstring Name;
 apstring Trash;
 Score_Data Temp;
 int I;
 int J;
 int G;
 int Low_Element;

 clrscr();
 cleardevice();

 G=165;
 Low_Element=0;

 In.open("A:\\SCORE.DAT");
 for(I=0; I<10; I++)
	{
		getline(In, Name);
		Scores[I].Name=Name;
		In>>Highscore;
		getline(In,Trash);
		Scores[I].Score=Highscore;
	}
 In.close();

 for(I=0; I<10; I++)
	{
	 for(J=I+1; J<10; J++)
		{
		 if(Scores[J].Score<Scores[I].Score)
			Low_Element=J;
		}
	}

 if(Score>Scores[Low_Element].Score)
	{
	 cout<<"Enter Name: ";
	 getline(cin, Scores[Low_Element].Name);
	 Scores[Low_Element].Score=Score;

	 for(I=0; I<10; I++)
		 {
			for(J=I+1; J<10; J++)
				{
				 if(Scores[J].Score>Scores[I].Score)
					 {
						Temp=Scores[J];
						Scores[J]=Scores[I];
						Scores[I]=Temp;
					 }
				}
			}

	 Out.open("A:\\SCORE.DAT");
	 for(I=0; I<10; I++)
	 {
		Out<<Scores[I].Name;
		Out<<endl<<Scores[I].Score<<endl;
	 }
	 Out.close();
	}

 setcolor(15);
 settextstyle(0,0,1);

 moveto(280,100);
 outtext("High Scores");

 moveto(160,150);
 outtext("Name");
 moveto(440,150);
 outtext("Score");
 for(I=0; I<10; I++)
	{
	 G+=15;
	 moveto(160,G);
	 outtext(Scores[I].Name.c_str());
	 moveto(440,G);
	 if(Scores[I].Score==0)
		outtext("0");
	 else
		outtext(ltos(Scores[I].Score).c_str());
	}

 moveto(230,400);
 outtext("Press Enter To Continue");
 getch();
};
