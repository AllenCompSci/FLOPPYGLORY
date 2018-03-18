//Info section
//Brett Nickols
//Prob#
//3rd period
/*
VARIABLE LIBRARY
char
	Ag-getch used to take in menu options
	A-getch variable used to enter power and angle
int
	X-used for, for loops
	Pix-reads what the current pixel is that the shot is at
	Nu-Decides whos turn it is buy using mod
	Lshotx-last x cordinate of the shot to cover the white bullet
	Lshoty-last y cordinate
	TankL-far left cordinate of the tank
	TankT-top cordinate of the tank
	TangleT-angle of the tank turret
	TankC-color of the tank
	O-for turret directon based on which tank color
	Ang-Angle of the computers shot
	Y-terrain explosion
	Fn-first number, 'for loop' number helps with terrain drawing
	Sn-second number, 'for loop' number helps with terrain drawing
double
	Shotx-current x cordinate of the shot
	Shoty-current y cordinate of the shot
	Powerx-power to go over certain amount of x values, from the formula
	Powery-power to go over certain amount of y value, from the formula
	Power-power entered by the user
	Angle-angle entered by the user
	X-for loop number
	I-for loop number
	Wind-random wind that changed left and right direction
	AngleT-angle of the turret

apvector
	land-holds the position of the land for explotions
bool
	collision-if the bullet hits something

FUNCTION DESCRIPTION
gr_start-starts the graphics mode
Pg-has the main program in it
Ter-draws the terrain of the map randomly
tank-draws the tank and moves the turret as the angle changes
Lhit-checks to see if land has been hit and then repaints it to show a
			hole where the bullet exploded
Title-shows the main select menue and the title screen
help-shows help and instructions also plot line to the game
Game-is a outer shell to run Pg, sees who won and who lost and changes
			computers angle/power
*/
//library section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <graphics.h>
#include <apvector.h>
#include <apmatrix.h>
#include <apstring.h>
#include <dos.h>
#include <math.h>
#include <alloc.h>
//constant section
//struct sect
//global variable section
char Ag;
int grdriver,grmode,errorcode,X;
//prototype section
void gr_start(int&,int&,int&);
int Pg(apvector <int>&,int,double);
void Ter(apvector <int>&);
void tank (int,int,int,int,double&,double&);
void Lhit (apvector <int>&,int);
void Title();
void help();
void Game();
//main
void main()
{
clrscr();

randomize();
gr_start(grdriver,grmode,errorcode);
do{
	for(X=0;X<13;X++)                           //spacing
		cout<<endl;
	Title();
	cout<<setw(40)<<"Main Menue"<<endl;         //menue
	cout<<setw(38)<<"1) start"<<endl;
	cout<<setw(37)<<"2) help"<<endl;
	cout<<setw(37)<<"3) exit"<<endl;
	Ag=getch();                                //enter selection
	switch(Ag)
		{
		case '1':Game();
							break;
		case '2':help();
							break;
		default :cout<<"try again"<<endl;
		}
	restorecrtmode();                              //clrscr
	clrscr();
	setgraphmode(getgraphmode());
	}while(Ag!='3');
}
//end main
//***************************************************************************
void Game ()                                  //outer shell of game
{
//local vars
apvector<int>Land(640);
int Pix,Nu,Ang;
Ter(Land);
Nu=0;
Ang=50;
do{
	Pix=Pg(Land,Nu,Ang);
	Nu++;
	if(Ang>80)
		Ang=50;
	if(Pix==1)                                      //result of game
		cout<<"you win"<<endl;
	if(Pix==4)
		cout<<"you lose"<<endl;
	if(Nu%2==0&&Pix==2)                            //computer correction
		Ang+=5;
	if(Nu%2==0&&Pix==14)
		Ang-=5;
}while(Pix!=1&&Pix!=4);
};

int Pg(apvector <int>& Land,int Nu,double Angle)  //main program
{
//local vars
double Powerx,Powery,Wind,Shotx,Shoty,X,I=500;
int Lshotx,Lshoty,Y,Power;
char A;
cleardevice();
setcolor(2);
for(X=0;X<640;X++)                                //cout land
	{
	Y=0;
	putpixel(X,Land[X],2);
	if(X<639)
		{
		if(Land[X]-1>Land[X+1])              //make vertical lines to fill land
			do{
				Y++;
				putpixel(X,Land[X]-Y,2);
				}while((Land[X]-Y)-1>Land[X+1]);
		else if(Land[X]+1<Land[X+1])
			do{
				Y++;
				putpixel(X,Land[X]+Y,2);
				}while((Land[X]+Y)+1<Land[X+1]);
		}
	}
line(639,Land[X-1],639,360);             //rest of land
line(0,360,0,Land[0]);
line(0,360,640,360);
setfillstyle(1,2);
floodfill(1,355,2);
Wind=random(100)-50;                     //wind create and cout
gotoxy(1,24);
cout<<"the wind is going to the ";
if(Wind>0)
	cout<<"right "<<Wind<<" MPH"<<endl;
else
	cout<<"left "<<Wind*-1<<" MPH"<<endl;
Wind/=200000;                           //wind set up for calculations
bool Collision;
if(Nu%2==0)
	{                                      //print tank
	for(X=0;X<20;X++)
		if(Land[X+620]<I)
			I=Land[X+620];
		tank(620,I-13,Angle,1,Shotx,Shoty);
	I=1110;
	for(X=0;X<20;X++)
		if(Land[X]<I)
			I=Land[X];
		tank(0,I-13,50,4,Shotx,Shoty);
	Shoty=I-21;
	Shotx=21;
	}
else
	{
	for(X=0;X<20;X++)
		if(Land[X]<I)
			I=Land[X];
		tank(0,I-13,50,4,Shotx,Shoty);
	I=1110;
	for(X=0;X<20;X++)
		if(Land[X+620]<I)
			I=Land[X+620];
		tank(620,I-13,Angle,1,Shotx,Shoty);
	Shoty=I-21;
	Shotx=619;

	}
Lshotx=Shotx;                                //set up last shot
Lshoty=Shoty;
I=500;
if(Nu%2==0)
	{                                       //user enters his power and angle
	Power=50;
	Angle=50;
	do{
		gotoxy(1,25);
		for(X=0;X<20;X++)
			if(Land[X]<I)
				I=Land[X];
		tank(0,I-13,Angle,4,Shotx,Shoty);      //shows tank as barrel moves
		cout<<"use arrow keys to enter the power : "<<Power<<" angle : "<<Angle<<"      ";
		A='a';
		A=getch();                             //changes power and angle
		if(int(A)==72&&Angle<100)
			Angle++;
		if(int(A)==80&&Angle>0)
			Angle--;
		if(int(A)==75&&Power>0)
			Power--;
		if(int(A)==77&&Power<100)
			Power++;
		if(A=='q'||A=='Q')                      //surrender
			{
			Shotx=10;
			Shoty+=15;
			A=char(13);
			}
	}while(int(A)!=13);
	}
else
	{
	Power=random(10)+50;                           //shows comp power and angle
	cout<<"his power is : "<<Power<<endl;
	cout<<"his angle is : "<<Angle<<endl;
	I=1110;
	for(X=0;X<20;X++)
		if(Land[X+620]<I)
			I=Land[X+620];
		tank(620,I-13,Angle,1,Shotx,Shoty);
	delay(1000);
	Wind*=-1;
	}
Collision=false;
Angle*=3.141592654;                         //calculations
Angle/=180;
Powerx=cos(Angle)*Power/100;
Powery=sin(Angle)*Power/100;
while(!Collision)                        //bullet movement
	{
	putpixel(Shotx,Shoty,15);
	delay(3);
	putpixel(Shotx,Shoty,0);
	if(Nu%2==0)
		Shotx+=Powerx;
	else
		Shotx-=Powerx;
	Shoty-=Powery;
	Powerx+=Wind;
	Powery-=.0005;
	if(Lshotx!=Shotx||Lshoty!=Shoty)       //shows move
		{
		if(Shotx>1140||Shotx<-500||Shoty<-500||Shoty>980)
			return 14;
		if(Shotx<640&&Shotx>0&&Shoty<480&&Shoty>0)
			if(getpixel(Shotx,Shoty)!=0)
				{
				if(getpixel(Shotx,Shoty)==2)     //if hits land
					Lhit(Land,Shotx);
				else                             //if hits tank, explode
					{
					setcolor(12);
					for(X=0;X<10;X++)
						{
						delay(100);
						circle(Shotx,Shoty,X);
						}
					}
				return getpixel(Shotx,Shoty);    //returns with what hit
				}
		Lshotx=Shotx;                        //resets last shot
		Lshoty=Shoty;
		}
	}
return 16;
};

void Lhit (apvector <int>& Land,int Y)     //hit land
{
int X;
if(Land[Y]<345)                            //lower land if not at bottom
	Land[Y]+=10;
else
	Land[Y]=355;
for(X=9;X>0;X--)
	{
	if(Land[Y-(10-X)]<(355-X))
		Land[Y-(10-X)]+=X;
	else
		Land[Y-(10-X)]=355;
	if(Land[Y+(10-X)]<(355-X))
		Land[Y+(10-X)]+=X;
	else
		Land[Y+(10-X)]=355;
	}
};

void Ter (apvector <int>& Land)            //creates terrain
{
int X,Fn,Sn;
Fn=random(100)+200;                        //height at start
Sn=random(100)-50;                         //goes up or down for Sn pixels
for(X=0;X<640;X++)
	{
	if(Fn==Sn+200)                          //if done going up or down
		Sn=random(100)-50;
	else
		if(Sn+200<Fn)                         //move up or down
			Fn--;
		else
			Fn++;
	Land[X]=Fn;                             //set vector with land height
	}
};

void gr_start(int &grdriver,int &grmode,int &errorcode)  //start graphics
{
grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver,&grmode,"c:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)                            //check for error
	{
	clrscr();
	cout<<"error:"<<errorcode<<endl;
	cout<<"press return to continue";
	getch();
	exit(1);
	}
};

void tank (int TankL,int TankT,int TangleT,int TankC,double& Shotx,double& Shoty)
{                                     //print tank and set bullet cordinants
int O;
double AngleT;
if(TankC==4)                     //for turret direction based on which tank
	O=20;
else
	O=10;
AngleT=TangleT;
setfillstyle(1,TankC);
AngleT*=(11.1111);              //math to convert angle from 0-9 to 0-100
AngleT/=100;
setcolor(0);            //display black lines to erase old turret positions
line(TankL+10,TankT-2,TankL+O-(AngleT+1),TankT-2-(AngleT+1));
line(TankL+10,TankT-2,TankL+O-(AngleT-1),TankT-2-(AngleT-1));
setcolor(TankC);
bar(TankL,TankT,TankL+20,TankT+13);    //print box to make main part of tank
putpixel(TankL+20,TankT,0);            //put black pixels to round corners
putpixel(TankL+20,TankT+1,0);
putpixel(TankL+19,TankT,0);
putpixel(TankL,TankT,0);
putpixel(TankL,TankT+1,0);
putpixel(TankL+1,TankT,0);
putpixel(TankL,TankT+13,0);
putpixel(TankL,TankT+12,0);
putpixel(TankL+1,TankT+13,0);
putpixel(TankL+20,TankT+13,0);
putpixel(TankL+20,TankT+12,0);
putpixel(TankL+19,TankT+13,0);
setcolor(TankC);                //rounded top to make turret look better
circle(TankL+10,TankT+1,5);
floodfill(TankL+10,TankT-2,TankC);
line(TankL+10,TankT-2,TankL+O-(AngleT),TankT-2-(AngleT)); //turret
Shotx=TankL+O-(AngleT);                 //set bullet cordinants
Shoty=TankT-2-(AngleT);
setcolor(0);                    //make black lines to make tank look better
line(TankL+1,TankT+10,TankL+19,TankT+10);
line(TankL+5,TankT,TankL+15,TankT);

};

void Title ()                    //display the word TANK on menue
{
setfillstyle(1,4);
setcolor(4);
bar(70,40,180,50);               //makes T
bar(110,40,140,150);
line(170,150,230,40);           //makes A
line(170,150,200,150);
line(200,150,230,90);
line(230,40,300,150);
line(230,90,265,150);
line(265,150,300,150);
bar(210,130,253,110);           //makes N
floodfill(185,145,4);
bar(310,150,320,40);
line(320,40,370,130);
line(310,40,370,150);
bar(370,150,380,40);
line(310,40,321,40);
line(370,130,370,150);
floodfill(330,66,4);
bar(410,150,420,40);            // makes K
line(420,85,470,150);
line(410,85,460,150);
line(470,150,460,150);
floodfill(463,149,4);
line(420,85,470,40);
line(410,85,460,40);
line(470,40,460,40);
floodfill(463,41,4);
};

void help()                   //writes to the screen, how to play
{
cleardevice();
gotoxy(1,1);
cout<<setw(48)<<"Welcome to Tank Wars"<<endl<<"You are an allied tank ";
cout<<"commander who is cut off from his platoon.  In order to  survive you ";
cout<<"must travel to Padaborn and meet up with your comrades. On the way ";
cout<<" you encounter a German tank ";
cout<<"unfortunately your tank is badly damaged from the   last battle, so ";
cout<<"it will only take one shot to destroy you.  You must";
cout<<" defeat yourenemy to save yourself from living in a concentration ";
cout<<"camp.";
cout<<endl<<setw(40)<<"To Play"<<endl<<"Start by selecting new game at the ";
cout<<"start menu. You must then select a power and angle to shoot at your";
cout<<" enemy";
cout<<", to choose power and angle up and down  arrows for angle and right ";
cout<<"and left for power. Pay attention to wind direction and ";
cout<<"strengthto aim perfectly.  Should you wish to surrender";
cout<<" while entereng you power and "<<endl<<"angle press q.";
cout<<endl<<endl<<"press any key to return to menu";
getch();                 //waits till reader is done
};