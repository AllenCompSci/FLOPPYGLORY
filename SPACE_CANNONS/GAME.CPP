//Zak Bennett & Michael Achilleos
//Space Cannons
//Block #2
//Mr. Baker

/*
Space cannons is a game where two players are put onto opposite sides of
the terrain and they shoot at each other with various weapons of their
choosing. They keep going until one person is dead.
*/

//Library section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <fstream.h>
#include <graphics.h>
#include <alloc.h>
#include <dos.h>
#include <math.h>

//Const section


//Struct section
struct records
{
apstring Names;
int Gamesplayed;
int Gameswon;
int Weapon;
};

//weapon data
struct P1w
{
int C;
int S;
int A;
};

struct P2w
{
int C;
int S;
int A;
};

//Prototype section

void gr_start (int&, int&, int&);
//in game
void game (int, int,int,int, int, int, bool, int, int, int, int,int,int,double,int,P1w,P2w,apvector <records>,int,int,int,bool & loop);
//main menu
void mainmenu (int, int,int,int, int, int, bool, int, int, int, int, int,int,double,int,apvector <records>,P1w,P2w);
//Terrain maker
void terrain(int, int, int&, int&);
//Shoot will display the shot across the screen
void shoot (int,int, int, double, double,bool,int,int,double,int,int,P1w&,P2w&,int&,int&);
//Makes menu
void makemenu (int,int,int,int,int,apvector <records>, bool);
//Show power
void showpow (int &, bool, int&,bool);
//Show angle
void showang (int &, bool, int&,bool);
//Function to show pow n angle
void pownang (int &,int &,bool,bool,int &, int &,bool,P1w &,P2w &,bool&);
//shows players turn
void pturn (bool,int,int,apvector <records>);
//Draws tanks
void tank (int,int);
//Gets y value with current power and angle
double gety (int,int,double, int,double);
//Gets B value with current power and angle
double getb (int,int,double,int,double);
//explosion
void explosion (int,double,P1w,P2w,bool);
//gets damage dealt
void damage (int, double, int, int, int, int, int, int, int&, int&,bool,P1w,P2w);
//redraws tank if covered
void redraw (int, int&);
//factors in wind
void changewind (double&, int);
//draws wind
void drawwind (int,int);
//shows records
void showrecord (int,apvector <records>,int,int,int);
//Fire STorm
void fstorm (int,double,int);
//changes weapon
void changeweap (bool,P1w &,P2w &,int);
//Remotely deployed Beam cannon (RDBC)
void rdbc (int,double);
//selecting players n such
void selectplayers (int,int,apvector <records> &,int&,int &,int &);
//BFB big flying bomb
void bfb (int,double);

//Variable section
//Used to take an answer when we have a question
char Answer;
//changing ints to chars
char Nums[10];
int grdriver,grmode,errorcode;
//Workhorse
int Z;
//X coordinate of shot
int X;
//y coordinate of shot
double Y;
//Coordinate to make shot go thru tank
double B;
//Y coordinate of player's tanks
int P1y,P2y;
//X coordinate of player's tanks
int P1x,P2x;
//Power of player 1/2
int P1,P2;
//Angle of player 1/2
int A1,A2;
//Max X and Y
int X2,Y2;
//THe health of the players
int P1h,P2h;
//Get key
int Get;
//Says is power/Angle is up or down
bool Powup, Angup;
//says whos turn it is (true = player 1, false = player 2)
bool Qturn;
//player health
int P1hp,P2hp;
//temporarily stores the damage dealt
int Dam;
apstring Trash;
//values for the user to see
int P2f,A2f;
// Wind
int Wind;
double T;
//for record section
int G;
int Size;
apvector <records> Stats (1);
//weapons
P1w P1wep;
P2w P2wep;
//profile choices
int P1pick,P2pick;

//Void
void main()
{
gr_start(grdriver,grmode,errorcode);
randomize();

X2=getmaxx();
Y2=getmaxy();

mainmenu(P1hp,P2hp,P1,A1,P2,A2,Qturn,P1x,P2x,P1y,P2y,X2,Y2,Y,Size,Stats,P1wep,P2wep);

}


void gr_start (int & grdriver, int & grmode, int & errorcode)
{

grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver, &grmode,"C:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
	{
	clrscr();
	cout<<"Error: "<<errorcode<<endl<<"Press return to continue";
	getch();
	exit(1);
	}
};

//This is the main function where everything in the game takes place
void game (int P1hp, int P2hp,int P1,int A1, int P2, int A2, bool Qturn, int P1x, int P2x, int P1y, int P2y, int X2, int Y2, double Y,int Wind,P1w P1wep,P2w P2wep,apvector <records> Stats,int P1pick, int P2pick,int Size,bool & Menu)
{
ofstream Send;
bool Noshot;

//starting values
Dam=0;
P1hp=200;
P2hp=200;
P1=50;
A1=50;
P2=100;
A2=60;
P2f=50;
A2f=50;
Qturn=true;
P1x=60;
P2x=X2-60;
P1wep.C=0;
P2wep.C=0;
P1wep.A=1;
P2wep.A=1;
Wind=random(15);

//makes menu
makemenu(X2,A1,A2f,P1,P2f,Stats,Qturn);
//makes terrain
terrain(X2,Y2,P1y,P2y);
//draws tank
tank(60,P1y);
tank(X2-60,P2y);

do
	{
	Menu=false;
	setcolor(0);
	Wind=random(15);
	changewind(T,Wind);
	drawwind(Wind,X2);

	//Checks to see if the tank needs to be redrawn
	if(getpixel(P1x-5,P1y-5)!=1&&getpixel(P1x-5,P1y)!=1&&getpixel(P1x+5,P1y)!=1&&getpixel(P1x+5,P1y-5)!=1)
				redraw(P1x,P1y);
		else if(getpixel(P1x-5,P1y-5)!=1||getpixel(P1x-5,P1y)!=1||getpixel(P1x+5,P1y)!=1||getpixel(P1x+5,P1y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P1x-5,P1y-5,P1x+5,P1y);
			}

		if(getpixel(P2x-5,P2y-5)!=1&&getpixel(P2x-5,P2y)!=1&&getpixel(P2x+5,P2y)!=1&&getpixel(P2x+5,P2y-5)!=1)
				redraw(P2x,P2y);
		else if(getpixel(P2x-5,P2y-5)!=1||getpixel(P2x-5,P2y)!=1||getpixel(P2x+5,P2y)!=1||getpixel(P2x+5,P2y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P2x-5,P2y-5,P2x+5,P2y);
			}

 do
	{

	//changes power and angle
	if(Qturn==true)
	pownang(P1,A1,Powup,Angup,P2f,A2f,Qturn,P1wep,P2wep/*,P1x,P1y,T*/,Menu);
	else
	pownang(P2,A2,Powup,Angup,P2f,A2f,Qturn,P1wep,P2wep/*,P2x,P2y,T*/,Menu);

Noshot=false;

if(Menu==false)
{

		//shoot, this calls a function to make the shot
		if(Qturn==true)
			{
				if(P1wep.C==0)
					shoot(P1,A1,P1y,Y,B,Qturn,P1x,X2,T,P2x,P2y,P1wep,P2wep,P1hp,P2hp);
				else if(P1wep.A>0)
					{
					setcolor(6);
					itoa(P1wep.A,Nums,10);
					outtextxy(225,5,Nums);
					P1wep.A--;
					setcolor(0);
					itoa(P1wep.A,Nums,10);
					outtextxy(225,5,Nums);
					shoot(P1,A1,P1y,Y,B,Qturn,P1x,X2,T,P2x,P2y,P1wep,P2wep,P1hp,P2hp);
					}
				else
					Noshot=true;
			}
		else
			{
				if(P2wep.C==0)
					shoot(P2,A2,P1y,Y,B,Qturn,P1x,X2,T,P2x,P2y,P1wep,P2wep,P1hp,P2hp);
				else if(P2wep.A>0)
					{
					setcolor(6);
					itoa(P2wep.A,Nums,10);
					outtextxy(X2-34,5,Nums);
					P2wep.A--;
					setcolor(0);
					itoa(P2wep.A,Nums,10);
					outtextxy(X2-34,5,Nums);
					shoot(P2,A2,P1y,Y,B,Qturn,P1x,X2,T,P2x,P2y,P1wep,P2wep,P1hp,P2hp);
					}
				else
					Noshot=true;
			}

		}

	}
while(Noshot==true);

if(Menu==false)
{

					//switch turn
					if(Qturn==true)
						Qturn=false;
					else
						Qturn=true;

			//shows switch in turn
			pturn(Qturn,P1pick,P2pick,Stats);


}
	}
	while(P1hp>=0&&P2hp>=0&&Menu==false);


if(Menu==false)
{
//States victory to winner
	setcolor(15);
	settextstyle(4,0,7);
	if(P1hp<=0)
	{
	outtextxy((X2/2)-225,(Y2/2)-100,"Victory");
	outtextxy((X2/2),Y2/2-100,Stats[P2pick].Names.c_str());
	Stats[P1pick].Gamesplayed++;
	Stats[P2pick].Gamesplayed++;
	Stats[P2pick].Gameswon++;
	}
	else if(P2hp<=0)
	{
	outtextxy((X2/2)-225,(Y2/2)-100,"Victory");
	outtextxy((X2/2),Y2/2-100,Stats[P1pick].Names.c_str());
	Stats[P1pick].Gamesplayed++;
	Stats[P2pick].Gamesplayed++;
	Stats[P1pick].Gameswon++;
	}
	Send.open("A:\\DATA.DAT");

	for(Z=0;Z<Size;Z++)
	{
	Send<<Stats[Z].Names<<endl;
	Send<<Stats[Z].Gamesplayed<<" ";
	Send<<Stats[Z].Gameswon<<" ";
	Send<<Stats[Z].Weapon<<endl;
	}

	Send.close();

	getch();
}
};

//Calls main menu to start the game
void mainmenu(int P1hp, int P2hp,int P1,int A1, int P2, int A2, bool Qturn, int P1x, int P2x, int P1y, int P2y, int X2, int Y2, double Y,int Size, apvector <records> Stats,P1w P1wep,P2w P2wep)
{
int A, B, C, Z, Spot1, Spot2, Spot3, CSpot;
bool Menu;
bool Loop;
do
{
setcolor(15);
X2=getmaxx();
Y2=getmaxy();
cleardevice();
X2/=2;
Spot1=Y2/2;
Spot2=Y2/1.7;
Spot3=Y2/1.5;
settextstyle(4,0,7);
Z=textwidth("Space Cannons");
outtextxy(X2-Z/2,Y2/4,"Space Cannons");

settextstyle(0,0,2);
Z=textwidth("New Game");
outtextxy(X2-Z/2,Spot1,"New Game");
Z=textwidth("Player Stats");
outtextxy(X2-Z/2,Spot2,"Player Stats");
Z=textwidth("Quit");
outtextxy(X2-Z/2,Spot3,"Quit");
setfillstyle(1,15);
fillellipse(X2-Z*1.7,Spot1+8,5,5);


do
{
Get=0;
Get=int(getch());
A=int(getpixel(X2-Z*1.7,Spot1+8));
B=int(getpixel(X2-Z*1.7,Spot2+8));
C=int(getpixel(X2-Z*1.7,Spot3+8));
if(Get==72)
{
 if(A==15)
	 {
		setcolor(0);
		setfillstyle(1,0);
		fillellipse(X2-Z*1.7,Spot1+8,5,5);
		setcolor(15);
		setfillstyle(1,15);
		fillellipse(X2-Z*1.7,Spot3+8,5,5);
	 }
 else if(B==15)
				{
				 setcolor(0);
				 setfillstyle(1,0);
				 fillellipse(X2-Z*1.7,Spot2+8,5,5);
				 setcolor(15);
				 setfillstyle(1,15);
				 fillellipse(X2-Z*1.7,Spot1+8,5,5);
				}
			else if(C==15)
						 {
							setcolor(0);
							setfillstyle(1,0);
							fillellipse(X2-Z*1.7,Spot3+8,5,5);
							setcolor(15);
							setfillstyle(1,15);
							fillellipse(X2-Z*1.7,Spot2+8,5,5);
						 }
}
else if(Get==80)
			 {
				if(A==15)
					{
					 setcolor(0);
					 setfillstyle(1,0);
					 fillellipse(X2-Z*1.7,Spot1+8,5,5);
					 setcolor(15);
						 setfillstyle(1,15);
					 fillellipse(X2-Z*1.7,Spot2+8,5,5);
					}
		 else if(B==15)
						{
						 setcolor(0);
						 setfillstyle(1,0);
						 fillellipse(X2-Z*1.7,Spot2+8,5,5);
						 setcolor(15);
						 setfillstyle(1,15);
						 fillellipse(X2-Z*1.7,Spot3+8,5,5);
						}
					else if(C==15)
								 {
									setcolor(0);
									setfillstyle(1,0);
									fillellipse(X2-Z*1.7,Spot3+8,5,5);
									setcolor(15);
									setfillstyle(1,15);
									fillellipse(X2-Z*1.7,Spot1+8,5,5);
								 }

			 }
}
while(Get!=13&&Get!=27);



Loop=false;

if(Get==13)
	{
	 A=int(getpixel(X2-Z*1.7,Spot1+8));
	 B=int(getpixel(X2-Z*1.7,Spot2+8));
	 C=int(getpixel(X2-Z*1.7,Spot3+8));
	 if(A==15)
		 {
		 X2*=2;
		 cleardevice();
		 selectplayers(X2,Y2,Stats,Size,P1pick,P2pick);
		 P1wep.S=Stats[P1pick].Weapon;
		 P2wep.S=Stats[P2pick].Weapon;
		 cleardevice();
		 game(P1hp,P2hp,P1,A1,P2,A2,Qturn,P1x,P2x,P1y,P2y,X2,Y2,Y,Wind,P1wep,P2wep,Stats,P1pick,P2pick,Size,Menu);
		 cleardevice();
		 if(Menu==false)
		 Loop=true;
		 }
	 else if(B==15)
					{
					showrecord(Size,Stats,X2,Y2,G);
					Loop=true;
					}
				else if(C==15)
							 {}
	}
}
while(Loop==true);
};

//Draws a random terrain
void terrain(int X2, int Y2, int& P1y, int& P2y)
{
int Z;
setcolor(8);
setfillstyle(1,8);
moveto(0,Y2-(random(Y2/2)));
Z=Y2-(random(Y2/2)+1);
P1y=Z;
lineto(40,Z);
lineto(80,Z);
lineto((X2-160)/4+80,Y2-(random(Y2/2)+1));
lineto(((X2-160)/4)*2+80,Y2-(random(Y2/2)+1));
lineto(((X2-160)/4)*3+80,Y2-(random(Y2/2)+1));
Z=Y2-(random(Y2/2)+1);
P2y=Z;
lineto(((X2-160)/4)*4+80,Z);
lineto(X2-40,Z);
lineto(X2,Y2-(random(Y2/2)));
floodfill(60,P1y+1,8);
floodfill(X2-60,P2y+1,8);
};


void shoot (int P1, int A1, int P1y, double Y, double B, bool Qturn,int P1x,int X2,double T,int P2x, int P2y,P1w& P1wep,P2w& P2wep,int & P1hp, int & P2hp)
{

//Numbers for parabola equation
int X;
//tells when to stop showing shot
bool Stop;
//tells when to start drawing
bool Draw;
//says when end of tank reached so tank is not overwritten
bool Tankend;
//says if terrain is hit
bool Hit;

//Checks to redraw tank
if(getpixel(P1x-5,P1y-5)!=1&&getpixel(P1x-5,P1y)!=1&&getpixel(P1x+5,P1y)!=1&&getpixel(P1x+5,P1y-5)!=1)
	redraw(P1x,P1y);
else if(getpixel(P1x-5,P1y-5)!=1||getpixel(P1x-5,P1y)!=1||getpixel(P1x+5,P1y)!=1||getpixel(P1x+5,P1y-5)!=1)
			 {
			 setfillstyle(1,1);
			 bar(P1x-5,P1y-5,P1x+5,P1y);
			 }

if(getpixel(P2x-5,P2y-5)!=1&&getpixel(P2x-5,P2y)!=1&&getpixel(P2x+5,P2y)!=1&&getpixel(P2x+5,P2y-5)!=1)
	redraw(P2x,P2y);
else if(getpixel(P2x-5,P2y-5)!=1||getpixel(P2x-5,P2y)!=1||getpixel(P2x+5,P2y)!=1||getpixel(P2x+5,P2y-5)!=1)
			 {
			 setfillstyle(1,1);
			 bar(P2x-5,P2y-5,P2x+5,P2y);
			 }



//Checks to stop shot
if(Qturn==true)
{
X=60;
Y=P1y;
}
else
{
X=X2-60;
Y=P2y;
}

Stop=false;
Draw=false;
Tankend=false;
Hit=false;





char Nums [10];

if(Qturn==true)
B=getb(P1,A1,P1y,P1x,T);
else
B=getb(P1,A1,P2y,P2x,T);

do
	{


Y=gety(P1,A1,B,X,T);
if(Qturn==true)
	X++;
else
	X--;

		if(getpixel(X,Y)==1)
		Draw=true;

		if(Draw==true&&getpixel(X,Y)==0)
		Tankend=true;


		if(Draw==true&&Tankend==true)
		{

		do
		{



			if(Y>=77&&Stop==false)
			putpixel(X,Y,0);

					Y=gety(P1,A1,B,X,T);
		if(Qturn==true)
			X++;
		else
			X--;




	if(Y>=77&&Stop==false)
	{
			if((getpixel(X,Y)==8)||(getpixel(X,Y)==1))
			{
				Stop=true;
				Hit=true;
			}
			else
			{ putpixel(X,Y,15);
				delay(15);
			}

		if(kbhit()&&Y>79)
		{
			if(Qturn==true)
			{
				if(P1wep.C==2)
				{
				Stop=true;
				Hit=true;
				}
			}
			else
			{
				if(P2wep.C==2)
				{
				Stop=true;
				Hit=true;
				}
			}
		}
	}




		if(Y<77)
		delay(13);

		if(Y>=Y2)
		{
		Stop=true;
			if(X<=X2||X>=0)
				Hit=true;
		}


		}
		while(Stop==false);
		}

	if(Hit==true)
		explosion(X,Y,P1wep,P2wep,Qturn);

//Checks to redraw
if(getpixel(P1x-5,P1y-5)!=1&&getpixel(P1x-5,P1y)!=1&&getpixel(P1x+5,P1y)!=1&&getpixel(P1x+5,P1y-5)!=1)
				redraw(P1x,P1y);
		else if(getpixel(P1x-5,P1y-5)!=1||getpixel(P1x-5,P1y)!=1||getpixel(P1x+5,P1y)!=1||getpixel(P1x+5,P1y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P1x-5,P1y-5,P1x+5,P1y);
			}

		if(getpixel(P2x-5,P2y-5)!=1&&getpixel(P2x-5,P2y)!=1&&getpixel(P2x+5,P2y)!=1&&getpixel(P2x+5,P2y-5)!=1)
				redraw(P2x,P2y);
		else if(getpixel(P2x-5,P2y-5)!=1||getpixel(P2x-5,P2y)!=1||getpixel(P2x+5,P2y)!=1||getpixel(P2x+5,P2y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P2x-5,P2y-5,P2x+5,P2y);
			}


	}
	while(Stop==false);

	damage(X,Y,Dam,X2,P1x,P1y,P2x,P2y,P1hp,P2hp,Qturn,P1wep,P2wep);

};

//Makes the status bar on screen while playing
void makemenu (int X2,int A1,int A2f,int P1,int P2f,apvector <records> Stats, bool Qturn)
{
apstring Temp;

settextstyle(0,0,0);

//menu bar
setcolor(6);
setfillstyle(1,6);
rectangle(0,0,X2,75);
floodfill(1,1,6);
	//title
	setcolor(0);
	outtextxy((X2/2)-20,15,"SPACE");
	outtextxy((X2/2)-27,25,"CANNONS");
		//P1 health G2 Y14 R4
		setcolor(2);
		setfillstyle(1,2);
		rectangle(30,20,230,50);
		floodfill(40,30,2);

		setcolor(14);
		setfillstyle(1,14);
		rectangle(30,20,130,50);
		floodfill(40,30,14);

		setcolor(4);
		setfillstyle(1,4);
		rectangle(30,20,65,50);
		floodfill(40,30,4);

		setcolor(0);
		rectangle(29,19,231,51);

//P2 health
setcolor(2);
setfillstyle(1,2);
rectangle(X2-30,20,X2-230,50);
floodfill(X2-40,30,2);

setcolor(14);
setfillstyle(1,14);
rectangle(X2-30,20,X2-130,50);
floodfill(X2-40,30,14);

setcolor(4);
setfillstyle(1,4);
rectangle(X2-30,20,X2-65,50);
floodfill(X2-40,30,4);

setcolor(0);
rectangle(X2-29,19,X2-231,51);

//show P1 and A1
setcolor(0);
outtextxy(30,60,"Power=");
	itoa(P1,Nums,10);
outtextxy(80,60,Nums);

setcolor(0);
outtextxy(110,60,"Angle=");
	itoa(A1,Nums,10);
outtextxy(160,60,Nums);

//show P2 and A2
setcolor(0);
outtextxy(X2-89,60,"Angle=");
	itoa(A2f,Nums,10);
outtextxy(X2-39,60,Nums);

setcolor(0);
outtextxy(X2-169,60,"Power=");
	itoa(P2f,Nums,10);
outtextxy(X2-119,60,Nums);

//show weapons Player 1
setcolor(0);
outtextxy(30,5,"Weapon:");
outtextxy(100,5,"Bomb");
outtextxy(180,5,"Ammo:");

settextstyle(0,1,0);
outtextxy(230,4,"8");
settextstyle(0,0,0);

//Same for P2
outtextxy(X2-230,5,"Weapon:");
outtextxy(X2-160,5,"Bomb");
outtextxy(X2-80,5,"Ammo:");

settextstyle(0,1,0);
outtextxy(X2-30,4,"8");
settextstyle(0,0,0);

//player turn
pturn(Qturn,P1pick,P2pick,Stats);

};

//Puts the power of the shot to the screen
void showpow (int & P1, bool Powup, int & P2f, bool Qturn)
{
char Nums[10];
int Tempx;

if(Qturn==true)
Tempx=30;
else
Tempx=X2-170;
//erase
setcolor(6);
outtextxy(Tempx,60,"Power=");
if(Qturn==true)
itoa(P1,Nums,10);
else
itoa(P2f,Nums,10);
outtextxy(Tempx+50,60,Nums);

if(Powup==true&&Qturn==true)
	P1++;
else if(Qturn==true)
	P1--;


if(Qturn==false&&Powup==false)
	{
		P1++;
		P2f--;
		itoa(P2f,Nums,10);
	}
else if(Qturn==false)
	{
		P1--;
		P2f++;
		itoa(P2f,Nums,10);
	}

//show new
setcolor(0);
outtextxy(Tempx,60,"Power=");
if(Qturn==true)
itoa(P1,Nums,10);
outtextxy(Tempx+50,60,Nums);


};

//Puts the angle of the shot to the screen
void showang (int & A1, bool Angup, int & A2f, bool Qturn)
{
char Nums[10];
int Tempx;

if(Qturn==true)
Tempx=110;
else
Tempx=X2-90;

//erase
setcolor(6);
outtextxy(Tempx,60,"Angle=");
if(Qturn==true)
itoa(A1,Nums,10);
else
itoa(A2f,Nums,10);
outtextxy(Tempx+50,60,Nums);

if(Angup==true&&Qturn==true)
A1++;
else if(Qturn==true)
A1--;



if(Angup==false&&Qturn==false)
{
	A1--;
	A2f--;
	itoa(A2f,Nums,10);
}
else if(Qturn==false)
{
	A1++;
	A2f++;
	itoa(A2f,Nums,10);
}
//show new
setcolor(0);
outtextxy(Tempx,60,"Angle=");
if(Qturn==true)
itoa(A1,Nums,10);
outtextxy(Tempx+50,60,Nums);

};

void pownang (int & P1,int & A1,bool Powup,bool Angup,int & P2f,int & A2f, bool Qturn,P1w & P1wep, P2w & P2wep/*,int P1x,int P1y,double T*/,bool & Menu)
{

do
{
if(kbhit())
//resets so no flashing numbers
Get=0;
int S;
	Get=int(getch());

if(Qturn==true)
{

if(Get==77&&P1!=100)
	{
	Powup=true;
	showpow(P1,Powup,P2f,Qturn);
	}

if(Get==75&&P1!=20)
	{
	Powup=false;
	showpow(P1,Powup,P2f,Qturn);
	}

if(Get==72&&A1!=90)
	{
	Angup=true;
	showang(A1,Angup,A2f,Qturn);
	}

if(Get==80&&A1!=20)
	{
	Angup=false;
	showang(A1,Angup,A2f,Qturn);
	}
}
else
{
if(Get==77&&P2f!=100)
	{
	Powup=true;
	showpow(P1,Powup,P2f,Qturn);
	}

if(Get==75&&P2f!=20)
	{
	Powup=false;
	showpow(P1,Powup,P2f,Qturn);
	}

if(Get==72&&A2f!=90)
	{
	Angup=true;
	showang(A1,Angup,A2f,Qturn);
	}

if(Get==80&&A2f!=20)
	{
	Angup=false;
	showang(A1,Angup,A2f,Qturn);
	}
}

if(Get==27)
	{
	cleardevice();
	mainmenu(P1hp,P2hp,P1,A1,P2,A2,Qturn,P1x,P2x,P1y,P2y,X2,Y2,Y,Size,Stats,P1wep,P2wep);
	Menu=true;
	}

if(Get==13)
	{
	changeweap(Qturn,P1wep,P2wep,X2);

	if(Qturn==true&&P1wep.C==0)
		P1wep.C=P1wep.S;
	else if(Qturn==true)
		P1wep.C=0;

	if(Qturn==false&&P2wep.C==0)
		P2wep.C=P2wep.S;
	else if(Qturn==false)
		P2wep.C=0;
	}


 }
 while(Get!=32&&Menu==false);


};

//Changes the players turn
void pturn (bool Qturn,int P1pick,int P2pick,apvector <records> Stats)
{

int Z1;
int Z2;



Z1=textwidth(Stats[P1pick].Names.c_str());
Z2=textwidth(Stats[P2pick].Names.c_str());

settextstyle(0,0,0);
setcolor(6);
if(Qturn==true)
outtextxy((X2/2)-Z2-5,60,Stats[P2pick].Names.c_str());
else
outtextxy((X2/2)-Z1-5,60,Stats[P1pick].Names.c_str());

setcolor(0);
if(Qturn==true)
outtextxy((X2/2)-Z1-5,60,Stats[P1pick].Names.c_str());
else
outtextxy((X2/2)-Z2-5,60,Stats[P2pick].Names.c_str());


if(Qturn==true)
outtextxy((X2/2)-5,60,"'s");
else
outtextxy((X2/2)-5,60,"'s");

outtextxy((X2/2)+30,60,"turn");




};


//Draws the tank
void tank (int P1x, int P1y)
{

setcolor(1);
setfillstyle(1,1);
rectangle(P1x-5,P1y-5,P1x+5,P1y);
floodfill(P1x-2,P1y-2,1);

};

//Plugs in X to the equation to get Y
double gety (int P1, int A1, double B,int X,double T)
{

double Tem;




Tem=(pow((X-(P1*T)),2)/(A1*T))+B;
return Tem;

};

//Finds the B of the equation so the shot originates from tank
double getb (int P1, int A1, double Y, int P1x,double T)
{

double Temp;

Temp=(pow((P1x-(P1*T)),2)/(-1*A1*T))+Y;

return Temp;
};

//Draws an explosion
void explosion (int X, double Y, P1w P1wep,P2w P2wep,bool Qturn)
{

int J;
if(Qturn==true)
J=P1wep.C;
else
J=P2wep.C;


switch(J)
{
case 0:for(J=0;J<50;J++)
			 {
			 if(J%3==0)
				 {
				 setcolor(4);
				 setfillstyle(1,4);
				 fillellipse(X,Y,8,8);
				 }
			 else if(J%3==1)
						 {
						 setcolor(14);
						 setfillstyle(1,14);
						 fillellipse(X,Y,15,15);
						 }
					 else if(J%3==2)
									 {
									 setcolor(4);
									 setfillstyle(1,4);
									 fillellipse(X,Y,20,20);
									 }
			 delay(50);
			 setcolor(0);
			 setfillstyle(1,0);
			 fillellipse(X,Y,20,20);
			 }
			 break;

case 1:delay(5000);
			 fstorm(X,Y,Y2);
			 break;

case 2:rdbc(X,Y);
			 break;

case 3:bfb(X,Y);
			 break;
}
};

//Deals damage to the player
void damage (int X, double Y, int Dam, int X2, int P1x, int P1y, int P2x, int P2y, int & P1hp, int & P2hp, bool Qturn,P1w P1wep,P2w P2wep)
{
int J;
double Dist,V,C,M;
//previous HP
int PP1hp, PP2hp;
setcolor(0);
setfillstyle(1,0);
Dam=0;
PP1hp=P1hp;
PP2hp=P2hp;
C=0;
V=0;

if(Qturn==true)
J=P1wep.C;
else
J=P2wep.C;

switch(J)
{
case 0:

if(Qturn==false)
{

C=pow(P1x-X,2);
V=pow(P1y-Y,2);
Dist=sqrt(C+V);

Dam=(25-Dist)*4;
if(Dam<0)
Dam=0;

	P1hp-=Dam;


}
else if(Qturn==true)
{

C=pow(P2x-X,2);
V=pow(P2y-Y,2);
Dist=sqrt(C+V);

Dam=(25-Dist)*2;
if(Dam<0)
Dam=0;


		P2hp-=Dam;

}
break;

case 1:

if(Qturn==false)
	{

	C=P1x-X;
	if(C<0)
	C*=-1;

	if(C<30)
		{
		Dam+=35;

		if(C<25)
			{
			Dam+=15;

			if(C<20)
				{
				Dam+=25;

					if(C<10)
					Dam+=25;

				}
			}
		}

	P1hp-=Dam;
	}
else if(Qturn==true)
	{

	C=P2x-X;
	if(C<0)
	C*=-1;

		if(C<30)
		{
		Dam+=35;

			if(C<25)
			{
			Dam+=25;

				if(C<20)
					{
					Dam+=25;

						if(C<10)
						Dam+=15;
					}
			}
		}

	P2hp-=Dam;
	}
break;
case 2:

if(Qturn==false)
	{

	C=P1x-X;
	if(C<0)
	C*=-1;

	if(C<37)
		{
		Dam+=35;

		if(C<30)
			{
			Dam+=30;

			if(C<20)
				{
				Dam+=15;

					if(C<10)
					Dam+=15;

				}
			}
		}

	P1hp-=Dam;
	}
else if(Qturn==true)
	{

	C=P2x-X;
	if(C<0)
	C*=-1;

		if(C<37)
		{
		Dam+=35;

			if(C<30)
			{
			Dam+=30;

				if(C<20)
					{
					Dam+=15;

						if(C<10)
						Dam+=15;
					}
			}
		}

	P2hp-=Dam;
	}
break;

case 3:

if(Qturn==false)
{

C=pow(P1x-X,2);
V=pow(P1y-Y,2);
Dist=sqrt(C+V);

Dam=(200-Dist)/1.5;
if(Dam<0)
Dam=0;

	P1hp-=Dam;


}
else if(Qturn==true)
{

C=pow(P2x-X,2);
V=pow(P2y-Y,2);
Dist=sqrt(C+V);

Dam=(200-Dist)/1.5;
if(Dam<0)
Dam=0;


		P2hp-=Dam;

}
break;
}




if(Qturn==false)
{
	for(J=0;J<PP1hp-P1hp;J++)
		{
			if((30+PP1hp-J)>=30)
				{
				bar(30+PP1hp-J,20,30+PP1hp-1-J,50);
				J++;
				delay(50);
				}
		};

}
else
{
	for(J=0;J<PP2hp-P2hp;J++)
		{
			if((X2-30-PP2hp+J)<=(X2-30))
				{
				bar(X2-30-PP2hp+J,20,X2-30-PP2hp+1+J,50);
				J++;
				delay(50);
				}
		}
}
		//Checks to redraw
		if(getpixel(P1x-5,P1y-5)!=1&&getpixel(P1x-5,P1y)!=1&&getpixel(P1x+5,P1y)!=1&&getpixel(P1x+5,P1y-5)!=1)
				redraw(P1x,P1y);
		else if(getpixel(P1x-5,P1y-5)!=1||getpixel(P1x-5,P1y)!=1||getpixel(P1x+5,P1y)!=1||getpixel(P1x+5,P1y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P1x-5,P1y-5,P1x+5,P1y);
			}

		if(getpixel(P2x-5,P2y-5)!=1&&getpixel(P2x-5,P2y)!=1&&getpixel(P2x+5,P2y)!=1&&getpixel(P2x+5,P2y-5)!=1)
				redraw(P2x,P2y);
		else if(getpixel(P2x-5,P2y-5)!=1||getpixel(P2x-5,P2y)!=1||getpixel(P2x+5,P2y)!=1||getpixel(P2x+5,P2y-5)!=1)
			{
			setfillstyle(1,1);
			bar(P2x-5,P2y-5,P2x+5,P2y);
			}

};

//Redraws the tank if any part of it is destroyed
void redraw (int P1x, int& P1y)
{
bool Redraw;
do
{
if(getpixel(P1x,P1y)==8||P1y==getmaxy())
	{
	setfillstyle(1,1);
	bar(P1x-5,P1y-5,P1x+5,P1y);
	Redraw=true;
	}
else
	{
	P1y+=1;
	Redraw=false;
	}
}
while(Redraw==false);
};

//Changes the wind so the shots change
void changewind (double & T, int Wind)
{
T=4;
			if(Wind!=7)
			{
				if(Qturn==true)
				{
					if(Wind>7)
					T+=(Wind-7)*.1;
					else
					T-=(7-Wind)*.1;
				}
				else if(Qturn==false)
				{
					if(Wind<7)
					T-=(7-Wind)*.1;
					else
					T+=(Wind-7)*.1;
				}



			}
};

//Draws the direction the wind is blowing
void drawwind (int Wind, int X2)
{
setcolor(15);
rectangle((X2/2)-40,33,(X2/2)+40,52);
floodfill(X2/2,42.5,15);
setfillstyle(1,6);
setcolor(6);
floodfill(X2/2,42.5,6);



setcolor(0);
setfillstyle(1,1);
line(X2/2,35,X2/2,50);

if(Wind<7)
{
line((X2/2)-1-((7-Wind)*5),42.5,X2/2,35);
line((X2/2)-1-((7-Wind)*5),42.5,X2/2,50);
floodfill((X2/2)-1,42.5,0);
}
else if(Wind>7)
			 {
			 line((X2/2)+1+((Wind-7)*5),42.5,X2/2,35);
			 line((X2/2)+1+((Wind-7)*5),42.5,X2/2,50);
			 floodfill((X2/2)+1,42.5,0);
			 }

};

//Shows the stats of the players in Player Stats
void showrecord (int Size,apvector <records> Stats, int X2, int Y2,int G)
{
apstring Trash;
ifstream Getstats;

Stats.resize(10);
cleardevice();
Getstats.open("A:\\DATA.DAT");

X2=getmaxx();
Y2=getmaxy();

Z=-1;
while(!Getstats.eof())
{
Z++;
getline(Getstats,Stats[Z].Names);
Getstats>>Stats[Z].Gamesplayed;
Getstats>>Stats[Z].Gameswon;
Getstats>>Stats[Z].Weapon;
getline(Getstats,Trash);

}


Getstats.close();
Size=Z;
Stats.resize(Size);

setcolor(15);
rectangle(1,50,X2-1,Y2-1);
rectangle(1,1,150,50);
rectangle(X2-1,1,X2-150,50);
setcolor(0);

line(2,50,150,50);

setcolor(15);

settextstyle(4,0,4);
outtextxy(165,1,"Space Cannon Records");

settextstyle(1,0,1);

outtextxy(80,50,"           Played       Won         Lost          Win %");
line(150,50,150,70+(Size*30));
line(260,50,260,70+(Size*30));
line(375,50,375,70+(Size*30));
line(X2-150,50,X2-150,70+(Size*30));

line(1,45+(1*30),X2,45+(1*30));

for(Z=0;Z<Size;Z++)
{
line(1,70+((Z+1)*30),X2,70+((Z+1)*30));
outtextxy(2,50+((Z+1)*30),Stats[Z].Names.c_str());

G=200;
if(Stats[Z].Gamesplayed>=10)
G-=10;
if(Stats[Z].Gamesplayed>=100)
G-=10;
itoa(Stats[Z].Gamesplayed,Nums,10);
outtextxy(G,50+((Z+1)*30),Nums);


G=310;
if(Stats[Z].Gameswon>=10)
G-=10;
if(Stats[Z].Gameswon>=100)
G-=10;
itoa(Stats[Z].Gameswon,Nums,10);
outtextxy(G,50+((Z+1)*30),Nums);


G=425;
if(Stats[Z].Gamesplayed-Stats[Z].Gameswon>=10)
G-=10;
if(Stats[Z].Gamesplayed-Stats[Z].Gameswon>=100)
G-=10;
itoa(Stats[Z].Gamesplayed-Stats[Z].Gameswon,Nums,10);
outtextxy(G,50+((Z+1)*30),Nums);

if(Stats[Z].Gamesplayed>Stats[Z].Gameswon)
{
G=X2-80;

	if((Stats[Z].Gameswon*100)/(Stats[Z].Gamesplayed)>=10)
	G-=10;

itoa((Stats[Z].Gameswon*100)/(Stats[Z].Gamesplayed),Nums,10);
}
else if(Stats[Z].Gameswon==Stats[Z].Gamesplayed&&Stats[Z].Gameswon!=0)
{
	G=X2-100;
	itoa(100,Nums,10);
}
else
{
	G=X2-80;
	itoa(0,Nums,10);
}


outtextxy(G,50+((Z+1)*30),Nums);
outtextxy(X2-65,50+((Z+1)*30),"%");

}

getch();
};

//The explosion animation for the Firestorm weapon
void fstorm (int X, double Y,int Y2)
{
int I;
Y=Y2;

for(Z=-200;Z<350;Z++)
{
if(Z>=-200&&Z<=-100)
	{
	setcolor(4);
	setfillstyle(1,4);
	fillellipse((X-25)+(random(45)+1),Y-1,1,1);
	setcolor(6);
	setfillstyle(1,6);
	fillellipse((X-25)+(random(45)+1),Y-1,1,1);
	delay(12);
	}
if(Z>=-100&&Z<=0)
	{
	setcolor(4);
	setfillstyle(1,4);
	fillellipse((X-24)+(random(44)+1),Y-1,2,2);
	setcolor(6);
	setfillstyle(1,6);
	fillellipse((X-24)+(random(44)+1),Y-1,2,2);
	delay(10);
	}
if(Z>=0&&Z<=100)
	{
	setcolor(4);
	setfillstyle(1,4);
	fillellipse((X-23)+(random(43)+1),Y-1,3,3);
	setcolor(6);
	setfillstyle(1,6);
	fillellipse((X-23)+(random(43)+1),Y-1,3,3);
	delay(8);
	}
if(Z>=100&&Z<=200)
	{
	setcolor(4);
	setfillstyle(1,4);
	fillellipse((X-22)+(random(42)+1),Y-1,4,4);
	setcolor(6);
	setfillstyle(1,6);
	fillellipse((X-22)+(random(42)+1),Y-1,4,4);
	delay(7);
	}
else if(Z>=200&&Z<=350)
	{
	setcolor(4);
	setfillstyle(1,4);
	fillellipse((X-21)+(random(41)+1),Y-1,5,5);
	setcolor(6);
	setfillstyle(1,6);
	fillellipse((X-21)+(random(41)+1),Y-1,5,5);
	setcolor(14);
	setfillstyle(1,14);
	fillellipse((X-21)+(random(41)+1),Y-1,5,5);
	delay(6);
	}
}

for(Z=0;Z<=Y2-(Y2-Y)-78;Z++)
{
	setcolor(4);
	setfillstyle(1,4);
	bar(X-25,Y-Z-1,X+25,Y-Z);
	if(Z<=Y2-(Y2-Y)-81)
		{
		fillellipse((X-22)+(random(44)+1),Y-1-Z,3,3);
		setcolor(6);
		setfillstyle(1,6);
		fillellipse((X-22)+(random(44)+1),Y-1-Z,3,3);
		setcolor(14);
		setfillstyle(1,14);
		fillellipse((X-22)+(random(44)+1),Y-1-Z,3,3);
		}
	delay(5);
}

setcolor(0);
setfillstyle(1,0);

for(Z=0;Z<=Y2-(Y2-Y)-78;Z++)
	{
	for(I=0;I<50;I++)
	putpixel((X-25)+(random(51)),Y-1-Z,0);
	bar(X-25,Y-Z-1,X+25,Y-Z);
	delay(5);
	}
};

//Changes the weapons of the player
void changeweap (bool Qturn,P1w & P1wep,P2w & P2wep, int X2)
{
apstring Temp;
char Nums [10];

if(Qturn==true)
{
if(P1wep.C==0)
	{
	setcolor(6);
	outtextxy(100,5,"Bomb");

	settextstyle(0,1,0);
	outtextxy(230,4,"8");
	settextstyle(0,0,0);

	if(P1wep.S==1)
	Temp="Firestorm";
	else if(P1wep.S==2)
	Temp="RDBC";
	else if(P1wep.S==3)
	Temp="BFB";

	setcolor(0);
	outtextxy(100,5,Temp.c_str());
	itoa(P1wep.A,Nums,10);
	outtextxy(225,5,Nums);



	}
else if(P1wep.C==P1wep.S)
	{
	setcolor(6);
	if(P1wep.S==1)
	Temp="Firestorm";
	else if(P1wep.S==2)
	Temp="RDBC";
	else if(P1wep.S==3)
	Temp="BFB";

	outtextxy(100,5,Temp.c_str());
	itoa(P1wep.A,Nums,10);
	outtextxy(225,5,Nums);

	setcolor(0);
	outtextxy(100,5,"Bomb");

	settextstyle(0,1,0);
	outtextxy(230,4,"8");
	settextstyle(0,0,0);
	}
}
else
{
if(P2wep.C==0)
	{
	setcolor(6);
	outtextxy(X2-161,5,"Bomb");

	settextstyle(0,1,0);
	outtextxy(X2-31,4,"8");
	settextstyle(0,0,0);

	if(P2wep.S==1)
	Temp="Firestorm";
	else if(P2wep.S==2)
	Temp="RDBC";
	else if(P2wep.S==3)
	Temp="BFB";

	setcolor(0);
	outtextxy(X2-161,5,Temp.c_str());
		itoa(P2wep.A,Nums,10);
	outtextxy(X2-35,5,Nums);
}
else if(P2wep.C==P2wep.S)
	{
	setcolor(6);

	if(P2wep.S==1)
	Temp="Firestorm";
	else if(P2wep.S==2)
	Temp="RDBC";
	else if(P2wep.S==3)
	Temp="BFB";

	outtextxy(X2-161,5,Temp.c_str());
		itoa(P2wep.A,Nums,10);
	outtextxy(X2-35,5,Nums);

	setcolor(0);
	outtextxy(X2-161,5,"Bomb");

	settextstyle(0,1,0);
	outtextxy(X2-31,4,"8");
	settextstyle(0,0,0);
}


}

};

//Explosion animation for RDBC weapon
void rdbc (int X, double Y)
{
apstring Trash;

int Z,K,I;
setcolor(15);

putpixel(X,Y+1,15);
putpixel(X,Y-1,15);

for(Z=1;Z<33;Z++)
{
delay(150);
putpixel(X-Z,Y,15);
putpixel(X+Z,Y,15);
}
delay(1000);

for(Z=1;Z<3;Z++)
{
for(K=4;K<34;K+=4)
{
putpixel(X-K,Y-Z,15);
putpixel(X+K,Y-Z,15);
putpixel(X-K,Y+Z,15);
putpixel(X+K,Y+Z,15);
}
delay(1000);
}
line(X-32,Y-3,X-4,Y-3);
line(X+32,Y-3,X+4,Y-3);
line(X-32,Y+3,X-4,Y+3);
line(X+32,Y+3,X+4,Y+3);
delay(500);

setfillstyle(1,14);
for(I=0;I<3;I++)
{
for(Z=0;Z<15;Z++)
{
for(K=31;K>4;K-=4)
{
floodfill(X-K,Y-1,15);
floodfill(X+K,Y-1,15);
floodfill(X-K,Y+1,15);
floodfill(X+K,Y+1,15);

if(I==0)
{
if(Z==0)
delay(400);
else
delay(400/Z);
}
else
delay(15);
}
if(I==0)
setfillstyle(1,Z);
else if(Z%2==1)
setfillstyle(1,4);
else
setfillstyle(1,0);

}
}
delay(1000);
setfillstyle(1,9);

for(Z=0;Z<301;Z++)
{
if(Z<150)
{
bar(X-33,Y+4,X-3,480);
bar(X+3,Y+4,X+33,480);
}
else
{
bar(X-32-((Z-100)/50),Y+4,X-4+((Z-100)/50),480);
bar(X+3-((Z-100)/50),Y+4,X+33+((Z-100)/50),480);
}

if(Z%2==1)
setfillstyle(5,9);
else
setfillstyle(6,9);

delay(10);

}
setfillstyle(1,0);
bar(X-37,Y-4,X+37,480);

getline(cin, Trash);
};

//Allows players to select their names
void selectplayers (int X2, int Y2, apvector <records> & Stats, int & Size,int & P1pick, int & P2pick)
{
int Z,L,C;
ifstream Getstats;
X2=getmaxx();
Y2=getmaxy();
char Nums [10];
apvector <apstring> Name (1);
apstring Newname;
int Newwep;
bool Clear;
bool New;
bool Start,Fturn;
ofstream Send;
Fturn=true;
Start=false;
do
{
Get=0;

New=false;

Getstats.open("A:\\DATA.DAT");

Stats.resize(10);
Z=-1;
while(!Getstats.eof())
{
Z++;
getline(Getstats,Stats[Z].Names);
Getstats>>Stats[Z].Gamesplayed;
Getstats>>Stats[Z].Gameswon;
Getstats>>Stats[Z].Weapon;
getline(Getstats,Trash);
}
if(Z==-1)
Z=0;

Getstats.close();
Size=Z;
Stats.resize(Size);

setcolor(15);
settextstyle(4,0,4);
Z=textwidth("Profiles");
outtextxy(X2-Z,Y2/Y2,"Profiles");

settextstyle(0,0,0);

outtextxy(1,1,"Please select a profile by pushing");
outtextxy(1,10,"the number of the desired profile");
outtextxy(1,19,"followed by enter");
setcolor(15);
for(Z=0;Z<Size;Z++)
{
itoa(Z+1,Nums,10);
outtextxy(1,(Z+2)*30,Nums);
outtextxy(7,(Z+2)*30,".");
outtextxy(13,(Z+2)*30,Stats[Z].Names.c_str());
}
if(Size==9)
setcolor(8);

outtextxy(1,360,"0");
outtextxy(7,360,".");
outtextxy(13,360,"NEW");

setcolor(10);
setfillstyle(1,10);
rectangle(1,400,160,Y2-15);
floodfill(2,401,10);

do
{
New=false;
	if(kbhit())
	{
	Get=0;
	Get=int(getch());

		if(Get>48&&Get<=48+Size)
		{
		setcolor(4);
		setfillstyle(1,4);
		floodfill(2,401,0);
		setfillstyle(1,10);
		floodfill(2,401,0);

		outtextxy(2,405,"Name:");
		outtextxy(2,417,"Games Played:");
		outtextxy(2,429,"Games Won:");
		outtextxy(2,441,"Current Special");
		outtextxy(2,453,"Weapon:");

		C=Get-49;

		outtextxy(42,405,Stats[C].Names.c_str());
		itoa(Stats[C].Gamesplayed,Nums,10);
		outtextxy(106,417,Nums);
		itoa(Stats[C].Gameswon,Nums,10);
		outtextxy(82,429,Nums);
		if(Stats[C].Weapon==1)
		outtextxy(58,453,"Firestorm");
		else if(Stats[C].Weapon==2)
		outtextxy(58,453,"RDBC");

		}

		if(Get==48&&Size!=9)
		{
		setcolor(10);
		setfillstyle(1,10);
		rectangle(X2-200,300,X2,Y2);
		floodfill(X2-1,Y2-1,10);

		setcolor(4);
		settextstyle(1,0,3);
		outtextxy(X2-195,300,"New Profile");

		settextstyle(0,0,0);
		outtextxy(X2-195,350,"Name:");


		Name[0]="";
		L=0;

		do
		{

				if(kbhit()&&L<10)
				{
				Get=0;
				Get=int(getch());

					if(Get>=65&&Get<=90)
					{
					Name[L]=char(Get);
					L++;
					Name.resize(L+1);
					}

					if(Get>=97&&Get<=122)
					{
					Name[L]=char(Get);
					L++;
					Name.resize(L+1);
					}

					if(Get==32)
					{
					Name[L]=char(Get);
					L++;
					Name.resize(L+1);
					}

					if(Get==8)
					{
					setcolor(10);
					for(Z=0;Z<L;Z++)
					outtextxy(X2-153+(Z*8),350,Name[Z].c_str());

					L--;
					Name.resize(L+1);
					}

					if(Get!=0)
					{
					setcolor(4);
					for(Z=0;Z<L;Z++)
					outtextxy(X2-153+(Z*8),350,Name[Z].c_str());
					}
				}
		}
		while(Get!=13&&Get!=27);

		if(Get==27)
		Get=30;

		if(Get!=30)
		{
		for(Z=0;Z<L;Z++)
		Newname+=Name[Z];

		outtextxy(X2-195,380,"Please select a");
		outtextxy(X2-195,390,"special weapon");
		outtextxy(X2-195,410,"1.Firestorm");
		outtextxy(X2-195,420,"2.RDBC");
		outtextxy(X2-195,430,"3.BFB");
		outtextxy(X2-195,470,"Press enter after select");
		Get=0;
		Clear=false;
		do
		{
			if(kbhit())
			{

			Get=0;
			Get=int(getch());

			if(Clear==true)
			{
				setfillstyle(1,4);
				floodfill((X2/2)-150+1,200,0);
			}
				setcolor(10);
				setfillstyle(1,10);
				rectangle((X2/2)-150,100,350,300);
				floodfill((X2/2)-150+1,200,10);

				Clear=false;
				if(Get==49)
				{
				setcolor(4);
				settextstyle(1,0,3);
				outtextxy((X2/2)-145,105,"Firestorm:");
				settextstyle(0,0,0);
				outtextxy((X2/2)-145,145,"A powerful attack that");
				outtextxy((X2/2)-145,155,"comes from deep within");
				outtextxy((X2/2)-145,165,"the land.It erupts");
				outtextxy((X2/2)-145,175,"vertically destroying");
				outtextxy((X2/2)-145,185,"anything in its path.");
				Newwep=1;
				Clear=true;
				}

				if(Get==50)
				{
				setcolor(4);
				settextstyle(1,0,3);
				outtextxy((X2/2)-145,105,"RDBC:");
				settextstyle(0,0,0);
				outtextxy((X2/2)-145,145,"The RDBC is a high");
				outtextxy((X2/2)-145,155,"tech device. It is a");
				outtextxy((X2/2)-145,165,"Remotely Deployable");
				outtextxy((X2/2)-145,175,"Beam Cannon.When using");
				outtextxy((X2/2)-145,185,"this you must remember");
				outtextxy((X2/2)-145,195,"to push enter after");
				outtextxy((X2/2)-145,205,"you launch it to tell");
				outtextxy((X2/2)-145,215,"it when to deploy");
				Newwep=2;
				Clear=true;
				}

				if(Get==51)
				{
				setcolor(4);
				settextstyle(1,0,3);
				outtextxy((X2/2)-145,105,"BFB:");
				settextstyle(0,0,0);
				outtextxy((X2/2)-145,145,"The BFB is a giant");
				outtextxy((X2/2)-145,155,"bomb so devastating,");
				outtextxy((X2/2)-145,165,"it's use has been");
				outtextxy((X2/2)-145,175,"outlawed in normal");
				outtextxy((X2/2)-145,185,"warfare. It is only");
				outtextxy((X2/2)-145,195,"used now in Space");
				outtextxy((X2/2)-145,205,"Cannons.");
				Newwep=3;
				Clear=true;
				}


			}
		New=true;
		}
		while(Get!=13);
		}
	setfillstyle(1,0);
	floodfill((X2/2)-150+1,200,0);
	floodfill(X2-1,Y2-1,10);

	if(New==true)
	{
	setcolor(15);
	outtextxy((X2/2)-160,Y2/2,"Creating Profile...");
	Size++;
	Stats.resize(Size);

	Stats[Size-1].Names=Newname;
	Stats[Size-1].Gamesplayed=0;
	Stats[Size-1].Gameswon=0;
	Stats[Size-1].Weapon=Newwep;

	Send.open("A:\\DATA.DAT");

	for(Z=0;Z<Size;Z++)
	{
	Send<<Stats[Z].Names<<endl;
	Send<<Stats[Z].Gamesplayed<<" ";
	Send<<Stats[Z].Gameswon<<" ";
	Send<<Stats[Z].Weapon<<endl;
	}

	Send.close();

	setcolor(0);
	outtextxy((X2/2)-160,Y2/2,"Creating Profile...");
	cleardevice();
	Get=27;
	}
	}
	if(Get==30)
	{
	setfillstyle(1,0);
	floodfill(X2-1,Y2-1,0);
	}
}
	if(Get==13)
	{

				setcolor(10);
				setfillstyle(1,10);
				rectangle((X2/2)-150,80,430,300);
				floodfill((X2/2)-150+1,200,10);



				setcolor(4);

				settextstyle(1,0,5);
				outtextxy((X2/2)-145,85,Stats[C].Names.c_str());
				outtextxy((X2/2)-145,155,"1.Select");
				outtextxy((X2/2)-145,195,"2.Delete");

				do
				{

				if(kbhit())
				{
					Get=0;
					Get=int(getch());


					if(Get==49)
					{
					if(Fturn==true)
						{
						P1pick=C;
						Fturn=false;
						Get=27;
						}
					else
						{
						P2pick=C;
						Start=true;
						Get=27;
						}
					}

					if(Get==50)
					{

						Send.open("A:\\DATA.DAT");

						for(Z=0;Z<Size;Z++)
						{
						if(Z<C||Z>C)
							{
							Send<<Stats[Z].Names<<endl;
							Send<<Stats[Z].Gamesplayed<<" ";
							Send<<Stats[Z].Gameswon<<" ";
							Send<<Stats[Z].Weapon<<endl;
							}
						}

						Send.close();

					Get=27;
					}

				}
				}
				while(Get!=27);

		setfillstyle(1,4);
		floodfill(2,401,0);
		setfillstyle(1,10);
		floodfill(2,401,0);
		setfillstyle(1,0);
		floodfill((X2/2)-150+1,200,0);
	}

}
while(Get!=27);

cleardevice();
}
while(Start==false);


};

//Explosion animation for BFB
void bfb (int X, double Y)
{
int K;
int I;


setcolor(15);
for(K=0;K<50;K++)
{
for(I=0;I<K;I++)
arc(X,Y,0,180,I);

if(K%2==1)
	setcolor(14);
else if(K%2==2)
	setcolor(6);
else
	setcolor(4);
delay(50);
}
setcolor(0);

for(I=50;I>0;I--)
{
arc(X,Y,0,180,I);
delay(10);
}
setcolor(4);
for(I=0;I<100;I++)
{
arc(X,Y,160-(I/4),180,I);
arc(X,Y,0,20+(I/4),I);
delay(5);

if(I%2==1)
	setcolor(4);
else if(I%3==2)
	setcolor(14);

}
setcolor(0);
setfillstyle(1,0);
for(I=0;I<100;I++)
{
arc(X,Y,160-(I/4),180,I);
arc(X,Y,0,20+(I/4),I);
fillellipse(X,Y,I+I/2,I);
delay(5);

}

};