//Game
//Block 2

//Library Section
#include<conio.h>
#include<iomanip.h>
#include<iostream.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<alloc.h>

//Constant Section
const int BR=10; //Radius of ball
const int SR=32; //Slime radius

//Struct


//Global Var Section
int grdriver,grmode,errorcode;
int Livesl,Livesr,Cl,Cr,Input,Input_r,Lnx,Skips,Tl,Tr,Tl_ai,Tr_ai;
int OLx,OLy,ORx,ORy,OBx,OBy,Q,Diff;
bool Alivel,Aliver,X,Y,Z,A,B,Ai_l,Ai_r,End,Bounce,Spike;
char Ball;
double Lx,Ly,Rx,Ry,Vxl,Vxr,Vyl,Vyr,Bx,By,Vx,Vy,Aer,Ael,Av,Al,Ar,V,Lna;
double Slider,Slidel,Af,Hit_y,Hit_slope;
char Restart;
apstring Trash;
int In,Out,Out_2;
ofstream out_file;
ifstream in_file;

/*

	_______________________
	_______________________

	*Variable Explanations*
	_______________________
	_______________________

	For the double variables, l means left slime, x means horizontal,
	y means vertical, r means right slime, v means velocity, b means ball,
	a means angle.
	Ar and Al are the angles of collision on the arc of the slime.
	Ael and Aer are the angles of the eyes of the slimes.
	Av is the angle of the ball's movement, standing for Angle Velocity.
	For the ints, O means old. Example OLx means Old left slime x position.
	The reason they are ints is that no calculations are done with them.
	They are simply used to write over and erase the old frame.
	char Ball holds which player will start with the ball.
	Alivel and Aliver hold the information for whether the slimes are alive.
	Cl and Cr hold the color of each slime, which CAN change in super-slime mode
	Livesl and Livesr hold the number of lives of each slime.
	Tl and Tr are turbo left and turbo right.
	Slidel and Slider are the distances the left and right slimes will slide
	if the movement key is released. Helpful for AI.
	Skips is used to find the number of skips before landing, used for AI.
*/

//Prototype Section
void gr_start(int&,int&,int&);
void instructions(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&, bool&, bool&,int&,int&);
void options(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&, bool&, bool&,int&,int&);
void display_objects(int,int,int,int,int,int,int,int,int,int,double,double);
void initial_settings (double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&);
void movement_and_gravity(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&);
void collisions (double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&, bool&, bool&,int&,int&);
bool collision_check(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&, bool&, bool&,int&,int&);
double angle_find(double,double);
void key_inputs_and_artificial_intelligence(double&,double&,double&,double&,int&,int&);
void write_replay(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,int&,int&);
void game(double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&,double&, bool&, bool&,int&,int&);
int landing_x(double&,double&,double&,double&,bool&);
double landing_a(double&,double&,double&,double&);
void go_l(int);
void go_r(int);


/*
___________________
___________________
Function Explanations
___________________
___________________

instructions: takes user to instructions screen and 
allows them to get out of the isntructions screen

options: takes user to options screen and allows 
them to edit the
 options and allows them to return to main menu

display_objects: displays the two slimes and the 
ball and the eyes every frame and draws over the 
old ball and slimes

initial_settings: resets values of variables that
 affect gameplay such as the x location, etc, at 
the beginning of each round

movement_and_gravity: moves all objects each frame 
according to their velocities and changes velocities 
of objects that are subject to gravity

collisions: checks for collisions and appropriately 
changes x and y locations and velocities of objects 
when there is one

collision_check: checks to see if there are any 
collisions. this way, if the fix of one collision
results in another collision, a do while loop can keep 
fixing collisions until there are no collisions

angle_find: a function commonly used in different places 
which takes a vector in rectangular for (X and Y coordinates) 
and finds the angle in order to convert to polar form. this 
is used in many places, especially for when the ball collides 
with the slimes, which are circular

key_input_and_artificial_intelligence: changes the velocities 
of objects based on key inputs. also, if AI is on, determines 
the computer's key input for it to move

write_replay: writes the values of all the variables which 
determine what the screen will look like onto a file on the 
C drive each frame

game: runs the game and uses other functions which involve the 
game and also runs the replay

landing_x: determines the x location of the ball when it next 
lands using math. helps with the functioning of the AI

landing_angle: determines the angle at which the ball will land.
helps determine which side of the ball the computer will move to
and whether it will jump (or possibly spike) the ball
*/


//Code
//right 77
//left 75
//up 72
//down 80
//enter 13


void main()

{
 randomize();
 gr_start(grdriver,grmode,errorcode);

//----------menu----------//

Y=false;
Out=0;
do{
cleardevice();
X=true;
In=0;
Out_2=4;
setbkcolor(9);
//floor
setfillstyle(1,15);
bar(0,451,640,480);
//net
setfillstyle(1,4);
bar(319,450,321,420);

Lx=160;
Rx=480;
Ly=30;
Ry=30;

//menu pick

if(Z)
	{
	if(Y==true)
		In=getch();
	}

setcolor(15);
settextstyle(7,0,5);
outtextxy(100,80,"SLIME VOLLEYBALL");
settextstyle(7,0,4);
outtextxy(150,150,"PLAY");
settextstyle(7,0,4);
outtextxy(150,200,"INSTRUCTIONS");
settextstyle(7,0,4);
outtextxy(150,250,"OPTIONS");
settextstyle(7,0,4);
outtextxy(150,300,"EXIT");


if(In==char(80))
	{
	if(Out==3)
		Out=0;
	else
		Out++;
	}

if(In==char(72))
	{
	if(Out==0)
		Out=3;
	else
		Out--;
	}



switch(Out)
	{
	case 0: setcolor(1);
					settextstyle(7,0,4);
					outtextxy(150,150,"PLAY");
					In=getch();
					if(In==char(13)) //enter
						{
						Z=false;
						game(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Ar,Al,V,Av,Alivel,Aliver,Livesl,Livesr);
						}
					else
						Z=true;
	break;

	case 1:	setcolor(1);
					settextstyle(7,0,4);
					outtextxy(150,200,"INSTRUCTIONS");
					In=getch();
					if(In==char(13)) //enter
						{
						Z=false;
						instructions(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Ar,Al,V,Av,Alivel,Aliver,Livesl,Livesr);
						}
					else
						Z=true;
	break;

	case 2:	setcolor(1);
					settextstyle(7,0,4);
					outtextxy(150,250,"OPTIONS");
					In=getch();
					if(In==char(13)) //enter
						{
						Z=false;
						options(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Ar,Al,V,Av,Alivel,Aliver,Livesl,Livesr);
						}
					else
						Z=true;
	break;

	case 3:	setcolor(1);
					settextstyle(7,0,4);
					outtextxy(150,300,"EXIT");
					In=getch();
					if(In==char(13)) //enter
						X=false;
	break;

	}

Y=true;

}while(X);

}//end main

void gr_start (int &grdriver,int &grmode,int &errorcode)
{
grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
errorcode=graphresult();
if (errorcode!=grOk)
 {
 clrscr();
 cout<<"Error: "<<errorcode<<endl;
 cout<<"Press return to continue ";
 getch();
 exit (1);
 }
}



void instructions(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl, double& Ar,double& Al, double& V, double& Av, bool& Alivel, bool& Aliver, int& Livesl, int& Livesr)
{
cleardevice();
setcolor(15);
settextstyle(4,0,6);
outtextxy(50,40,"Instructions");
settextstyle(1,0,3);
outtextxy(100,100,"The object of the game is to bounce");
outtextxy(100,125,"the ball on the other side of the net");
outtextxy(100,150,"and hit the ground,just like volleyball.");
outtextxy(100,200,"Left player uses A for left,D for");
outtextxy(100,225,"right and W for jump. Right player");
outtextxy(100,250,"uses J ,L ,and I respectivly.");
outtextxy(100,275,"Each player has five lives to start");
outtextxy(100,300,"and gains and looses them.");
outtextxy(100,350,"Press 'enter' to return to the menu...");
do{
	In=getch();
	}while(In!=char(13));
}


void options(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl, double& Ar,double& Al, double& V, double& Av, bool& Alivel, bool& Aliver, int& Livesl, int& Livesr)
{

Out=0;
Out_2=0;
In=0;
A=true;
B=false;
Ai_l=false;
Ai_r=false;



cleardevice();
setcolor(15);
settextstyle(4,0,6);
outtextxy(100,40,"Options");
settextstyle(1,0,3);
outtextxy(100,100,"Player Left");
outtextxy(300,100,"Player Right");
outtextxy(100,150,"----Computer--AI----");
outtextxy(100,400,"Press 'Q' to go to main menu.");
outtextxy(100,300,"----AI-Difficulty----");
outtextxy(100,350,"Passive");
outtextxy(220,350,"Aggressive");
outtextxy(370,350,"Frickin Insane");

do{

	if(Out==0)
		setcolor(1);
	else
		setcolor(15);

	outtextxy(100,200,"ON");

	if(Out==1)
		setcolor(1);
	else
		setcolor(15);

	outtextxy(150,200,"OFF");

	if(Out==2)
		setcolor(1);

	else
		setcolor(15);

	outtextxy(300,200,"ON");

	if(Out==3)
		setcolor(1);

	else
		setcolor(15);

	outtextxy(350,200,"OFF");



	if(Out==0 && In==char(13))
		Ai_l=true;

	if(Out==1 && In==char(13))
		Ai_l=false;

	if(Out==2 && In==char(13))
		Ai_r=true;

	if(Out==3 && In==char(13))
		Ai_r=false;

	setfillstyle(1,9);
	bar(100,250,500,300);

	setcolor(15);

	if(Ai_l==true)
		outtextxy(100,250,"Left AI is ON");
	else
		outtextxy(100,250,"Left AI is OFF");

	if(Ai_r==true)
		outtextxy(300,250,"Right AI is ON");
	else
		outtextxy(300,250,"Right AI is OFF");

	In=getch();

	if(In==char(77))	//right
		{
		if(Out==3)
			Out=0;
		else
			Out++;
		}

	if(In==char(75))	//left
		{
		if(Out==0)
			Out=3;
		else
			Out--;
		}

	if(In==char(80))
		do{

			if(Out_2==0)
				setcolor(1);
			else
				setcolor(15);

			outtextxy(100,350,"Passive");

			if(Out_2==1)
				setcolor(1);
			else
				setcolor(15);

			outtextxy(220,350,"Aggressive");

			if(Out_2==2)
				setcolor(1);
			else
				setcolor(15);

			outtextxy(370,350,"Frickin Insane");

			In=getch();

			if(Out_2==0 && In==char(13))
				Diff=0;

			if(Out_2==1 && In==char(13))
				Diff=1;

			if(Out_2==2 && In==char(13))
				Diff=2;


			setcolor(15);

			if(In==char(77))	//right
				{
				if(Out_2==2)
					Out_2=0;
				else
					Out_2++;
				}

			if(In==char(75))	//left
				{
				if(Out_2==0)
					Out_2=2;
				else
					Out_2--;
				}

		}while(In!='Q'&&In!='q'&&In!=char(72));



}while(In!='Q'&&In!='q');

Out=2;
}


void display_objects(int Lx,int Ly,int Cl,int Rx,int Ry,int Cr,int Bx,int By,int SR,int BR,double Ael,double Aer)
{

//erase
setfillstyle(1,8);
bar(OLx-SR,480-SR-OLy,OLx+SR,480-OLy);
bar(ORx-SR,480-SR-ORy,ORx+SR,480-ORy);
bar(OBx-BR,480-OBy-BR,OBx+BR,480-OBy+BR);

OLx=Lx;
OLy=Ly;
ORx=Rx;
ORy=Ry;
OBx=Bx;
OBy=By;

//slime L
//setcolor(4);
setfillstyle(1,Cl);
pieslice(Lx,480-Ly,0,180,SR);
setfillstyle(1,15);
fillellipse(Lx+10,460-Ly,5,5);

//eye
setcolor(0);
setfillstyle(1,0);
fillellipse(int(Lx+10+4*cos(Ael)),int(460-Ly-4*sin(Ael)),2,2);
setcolor(15);

//slime R
//setcolor(2);
setfillstyle(1,Cr);
pieslice(Rx,480-Ry,0,180,SR);
setfillstyle(1,15);
fillellipse(Rx-10,460-Ry,5,5);

//eye
setcolor(0);
setfillstyle(1,0);
fillellipse(int(Rx-10+4*cos(Aer)),int(460-Ry-4*sin(Aer)),2,2);
setcolor(15);

//ball
setfillstyle(1,14);
fillellipse(Bx,480-By,BR,BR);

delay(25);

}

	 void initial_settings(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl)
	 {
	 setbkcolor(8);
	 //Floor
	 setfillstyle(1,15);
	 bar(0,451,640,480);
	 //Net
	 setfillstyle(1,4);
	 bar(319,450,321,420);

	 setcolor(15);

	 //Initial positions
	 Hit_slope=0;
	 Spike=false;
	 Bounce=false;
	 Lx=160;
	 Rx=480;
	 Ly=30;
	 Ry=30;
	 if (Ball=='L')
		Bx=Lx;
	 if (Ball=='R')
		Bx=Rx;
	 By=250;
	 Vx=0;
	 Vy=0;
	 Vxr=0;
	 Vyr=0;
	 Vxl=0;
	 Vyl=0;


	 //Both slimes alive
	 Alivel=true;
	 Aliver=true;

	 //Bar over old lives circles
	 setfillstyle(1,8);
	 bar(0,0,640,32);

	 //Show lives
	 setfillstyle(1,4);
	 for (X=0;X<Livesl;X++)
		fillellipse(30*(X+1),20,10,10);

	 setfillstyle(1,2);
	 for (X=0;X<Livesr;X++)
		fillellipse(640-30*(X+1),20,10,10);
	 }

		void movement_and_gravity(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl)
		{
		//Movement
		Bx+=Vx;
		By+=Vy;
		Lx+=Vxl;
		Rx+=Vxr;
		Ly+=Vyl;
		Ry+=Vyr;
		Skips--;

		//Gravity
		Vy-=.5;
		Vyr-=.5;
		Vyl-=.5;
		if (Tl>2)
		 Cl=random(16);
		else
		 Cl=4;
		if (Tr>2)
		 Cr=random(16);
		else
		 Cr=2;

		}

	void collisions(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl, double& Ar,double& Al, double& V, double& Av, bool& Alivel, bool& Aliver, int& Livesl, int& Livesr)
		{
		//Ball with back walls
		if (Bx<=BR)
		 {
		 Spike=false;
		 Bx=BR;
		 Vx*=-1;
		 Bounce=false;
		 }
		if (Bx>=640-BR)
		 {
		 Spike=false;
		 Bx=640-BR;
		 Vx*=-1;
		 Bounce=false;
		 }

		//Ball with floor
		if (By<=30+BR)
		 {
		 By=30+BR;
		 if (Bx<320)
			{
			Alivel=false;
			Livesl--;
			Livesr++;
			if (Tr<3)
			 Tr++;
			if (Ball=='L')
			 Tl=0;
			Ball='R';
			}
		 else
			{
			Aliver=false;
			if (Tl<3)
			 Tl++;
			if (Ball=='R')
			 Tr=0;
			Livesr--;
			Livesl++;
			Ball='L';
			}
		 }

		//Score lives circles when ball overwrites

		if (By>400)
		{
		//Bar over old lives circles
		setfillstyle(1,8);
		bar(0,0,640,32);

		//Show lives
		setfillstyle(1,4);
		for (X=0;X<Livesl;X++)
		 fillellipse(30*(X+1),20,10,10);

		setfillstyle(1,2);
		for (X=0;X<Livesr;X++)
		 fillellipse(640-30*(X+1),20,10,10);
		}

		//Ball with net
		if (Bx>318-BR&&Bx<322+BR)
		 {
		 if (By<60)
			{
			if (Vx>0)
			 Bx=318-BR;
			if (Vx<0)
			 Bx=322+BR;
			Vx*=-1;
			Skips=int(4*Vy);
			Hit_y=0;
			Spike=false;
			}
		 if (By<60+BR&&By>60)
			{
			By=60+BR;
			Vy*=-1;
			Skips=int(4*Vy);
			Hit_y=0;
			Spike=false;
			}
		 }

		//Slimes with back walls
		if (Lx<SR)
		 {
		 Lx=SR;
		 Vxl=0;
		 }
		if (Rx>640-SR)
		 {
		 Rx=640-SR;
		 Vxr=0;
		 }

		//Slimes with floor
		if (Ly<30)
		 {
		 Ly=30;
		 Vyl=0;
		 }
		if (Ry<30)
		 {
		 Ry=30;
		 Vyr=0;
		 }
		//Slimes with net
		if (Lx>318-SR)
		 {
		 Vxl=0;
		 Lx=318-SR;
		 }
		if (Rx<322+SR)
		 {
		 Vxr=0;
		 Rx=322+SR;
		 }

		//Slimes  with ball
		//Left slime collides with ball
		if ( (Bx-Lx)*(Bx-Lx)+(By-Ly)*(By-Ly)<=(SR+BR)*(SR+BR) && By>=Ly-7)
		 {
		 Bounce=false;
		 Al=angle_find(By-Ly,Bx-Lx);

		 Bx=Lx+(cos(Al)*(BR+SR+1));
		 By=Ly+(sin(Al)*(BR+SR+1));
		 V=sqrt((Vx*Vx)+(Vy*Vy));
		 if (V>16)
			V=16;
		 Av=angle_find(Vy-Vyl,Vx-Vxl);
		 if (Av<0)
			Av+=3.1416;
		 else
			Av-=3.1416;
		 Av=2*Al-Av;
		 Vx=V*cos(Av);
		 Vy=V*sin(Av);
		 Vx+=Vxl/5;
		 Vy+=Vyl/5;
		 Skips=int(4*Vy);
		 Hit_y=By-30-BR-SR;
		 Hit_slope=Vx/Vy;
		 if (Vy>0)
			Spike=false;
		 else
			Spike=true;
			//Helps with finding landing x which
		 //helps with AI
		 }

		 //Right slime collides with ball
		 if ( (Bx-Rx)*(Bx-Rx)+(By-Ry)*(By-Ry)<=(SR+BR)*(SR+BR) && By>=Ry-7)
			{
			Bounce=false;
			Ar=angle_find(By-Ry,Bx-Rx);

			Bx=Rx+( cos(Ar)*(BR+SR+1) );
			By=Ry+( sin(Ar)*(BR+SR+1) );
			V=sqrt( (Vx*Vx)+(Vy*Vy) );
			if (V>16)
			 V=16;
			Av=angle_find(Vy-Vyr,Vx-Vxr);
			if (Av<0)
			 Av+=3.1416;
			else
			 Av-=3.1416;

			Av=2*Ar-Av;
			Vx=V*cos(Av);
			Vy=V*sin(Av);
			Vx+=Vxr/5;
			Vy+=Vyr/5;
			Skips=int(4*Vy);
			Hit_y=By-30-BR-SR;
			Hit_slope=Vx/Vy;
			if (Vy>0)
			 Spike=false;
			else
			 Spike=true;
			 //Helps with finding landing x which
			//helps with AI
			}

			//finding the angle for the eye

		 //left eye find angle
		 Ael=angle_find(By-(Ly+20),Bx-(Lx+10));

		 //right eye find angle
		 Aer=angle_find(By-(Ry+20),Bx-(Rx-10));


		 }

		double angle_find (double Y, double X)
		 {
		 //Local
		 double Angle;

		 if (X==0)
			Angle=acos(0);
		 else
			Angle=atan(Y/X);

		 if (Angle<0&&Y>0)
			Angle+=3.1416;

		 if (Angle>0&&Y<0)
			Angle-=3.1416;

		 return Angle;
		 }

		void key_inputs_and_artificial_intelligence(double& Vxl,double& Vxr,double& Vyl,double& Vyr,int& Input,int& Input_r)
		 {
			if (kbhit())
			 {
			 Input=getch();
			 if (Input==0)
				{
				Input=getch();
				}
			 }
			else
			 {
			 Input=0;
			 Input_r=0;
			 }
			Input_r=Input;

			if (Input==27)
			 End=true;

			//Giving variables values so that the function doesn't have to be called over and over
			 Lnx=landing_x(Bx,By,Vx,Vy,Bounce);

			 Lna=landing_a(Bx,By,Vx,Vy);

			 //gotoxy(0,0);
			 //cout<<Lnx<<" ";
			 //getch();

			//Finding the distance the slimes will slide after the key is released
			Slidel=(abs(Vxl)*(abs(Vxl)+1))/2;
			if (Vxl<0)
			 Slidel*=-1;
			Slider=(abs(Vxr)*(abs(Vxr)+1))/2;
			if (Vxr<0)
			 Slider*=-1;

			//Slidel=Vxl;
			//Slider=Vxr;

			Af=angle_find(Vy,Vx);//Giving variable value so function doesn't have
			//to be called repeatedly


			//cout<<Af<<" "<<Lnx<<" ";
			//if (Bounce)
			 //cout<<"Yes  ";
			//else
			 //cout<<"No   ";
			//getch();

			//Left slime AI
			if (Ai_l&&Diff<2)
			 {
			 if (Diff>0&&(Af<-2.3||Af>2.6)&&Bx>Lx+40&&Bx<Lx+80&&By<30+BR+SR+130&&By>30+BR+SR+15&&Ly<32)
				Input=119;
			 else
				{
				if (!Bounce&&Vx<=0)
				 {
				 go_l(Lnx-6-Diff*13-random(6));
				 }
				else
				 {
				 if (Lna>-.8)
					go_l(Lnx+20);
				 else
					go_l(Lnx+12);
				 }
				}

			 }
			if (Ai_l&&Diff==2)
			 {
			 if (Bx-7<310-SR)
				Lx=Bx-7;
			 }

			//Right slime AI
			if (Ai_r&&Diff<2)
			 {
			 if (Diff>0&&Af>-.8&&Af<.5&&Bx>Rx-80&&Bx<Rx-40&&By<30+BR+SR+130&&By>30+BR+SR+15&&Ry<32)
				Input_r=72;
			 else
				{
				if (Bounce||Vx<0)
				 {
				 if (Lna<-2.3)
					go_r(Lnx-20);
				 else
					go_r(Lnx-12);
				 }
				else
				 {
				 go_r(Lnx+7+13*Diff+random(6));
				 }
				}

			 }
			if (Ai_r&&Diff==2)
			 {
			 if (Bx+7>330+SR)
				Rx=Bx+random(7);
			 }

			if (Tl<3)
			 Tl_ai=0;
			else
			 Tl_ai=4;

			if (Tr<3)
			 Tr_ai=0;
			else
			 Tr_ai=4;

	/*	if (Input==char(97)||Input==char(100)) //Mover
			 {
			 if (Input==char(97))
				Vxl=-8-Tl_ai;
			 if (Input==char(100))
				Vxl=8+Tl_ai;
			 }
			else   //Stopper
			 {
			 //if (Vxl>=-1&&Vxl<=1)
				Vxl=0;
			 //else
				{
				//if (Vxl>0)
				 //Vxl--;
				//if (Vxl<0)
				 //Vxl++;
				}
			 }

			if (Input==char(119) && Ly==30)
			 Vyl=10;

			if (Input_r==char(75)||Input_r==char(77)) //Mover
			 {
			 if (Input_r==char(75))
				Vxr=-8-Tr_ai;
			 if (Input_r==char(77))
				Vxr=8+Tr_ai;
			 }
			else //Stopper
			 {
			 //if (Vxr<=1&&Vxr>=-1)
				Vxr=0;
			// else
				//{
				//if (Vxr>0)
				 //Vxr--;
				//if (Vxr<0)
				 //Vxr++;
				//}

			 }

			if (Input_r==char(72) && Ry==30)
			 Vyr=10;
		*/

			if (Input==char(97)||Input==char(100)) //Mover
			 {
			 if (Input==char(97) && Vxl>-9-Tl*1.5)
				Vxl-=4.5;
			 if (Input==char(100) &&Vxl<9+Tl*1.5)
				Vxl+=4.5;
			 }
			else   //Stopper
			 {
			 if (Vxl>=-1&&Vxl<=1)
				Vxl=0;
			 else
				{
				if (Vxl>0)
				 Vxl--;
				if (Vxl<0)
				 Vxl++;
				}
			 }

			if ((Input==char(119) && Ly==30))
			 Vyl=10;

			if (Input_r==char(75)||Input_r==char(77)) //Mover
			 {
			 if ((Input_r==char(75) &&Vxr>-9-Tr*1.5))
				Vxr-=4.5;
			 if ((Input_r==char(77) && Vxr<9+Tr*1.5))
				Vxr+=4.5;
			 }
			else //Stopper
			 {
			 if (Vxr<=1&&Vxr>=-1)
				Vxr=0;
			 else
				{
				if (Vxr>0)
				 Vxr--;
				if (Vxr<0)
				 Vxr++;
				}

			 }

			if (Input_r==char(72) && Ry==30)
			 Vyr=10;
			while(kbhit())
			 Q=getch();

		 }


	void write_replay(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl,int& Cl,int& Cr)
		{

		out_file<<Lx<<endl<<Ly<<endl<<Cl<<endl<<Rx<<endl<<Ry<<endl;
		out_file<<Cr<<endl<<Bx<<endl<<By<<endl<<Ael<<endl<<Aer<<endl;
		display_objects(int(Lx),int(Ly),Cl,int(Rx),int(Ry),Cr,int(Bx),int(By),SR,BR,Ael,Aer);
		}

	bool collision_check(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl, double& Ar,double& Al, double& V, double& Av, bool& Alivel, bool& Aliver, int& Livesl, int& Livesr)
	 {
	 //Local
	 bool Collision;

	 Collision=false;

		if (Bx<BR)
		 Collision=true;

		if (Bx>640-BR)
		 Collision=true;

		if (By<30+BR)
		 Collision=true;

		if (Bx>318-BR&&Bx<322+BR)
		 {

		 if (By<60)
			Collision=true;

		 if (By<60+BR&&By>60)
			Collision=true;

		 }

		if (Lx<SR)
		 Collision=true;

		if (Rx>640-SR)
		 Collision=true;

		if (Ly<30)
		 Collision=true;

		if (Rx>640-SR)
		 Collision=true;

		if (Lx>318-SR)
		 Collision=true;

		if (Rx<322+SR)
		 Collision=true;

		if ( (Bx-Lx)*(Bx-Lx)+(By-Ly)*(By-Ly)<(SR+BR)*(SR+BR) && By>=Ly-5)
		 Collision=true;

		if ( (Bx-Rx)*(Bx-Rx)+(By-Ry)*(By-Ry)<(SR+BR)*(SR+BR) && By>=Ry-5)
		 Collision=true;

		return Collision;
	 }

void game(double& Lx,double& Rx,double& Ly,double& Ry,double& Bx,double& By,double& Vx,double& Vy,double& Vxr,double& Vyr,double& Vxl,double& Vyl, double& Ar,double& Al, double& V, double& Av, bool& Alivel, bool& Aliver, int& Livesl, int& Livesr)
{
	cleardevice();
	End=false;
	//Initial conditions
	if (Ai_l)
	 Ball='R';
	else
	 Ball='L';
	Livesl=5;
	Livesr=5;
	Cl=4;
	Cr=2;
	Tl=0;
	Tr=0;

	out_file.open("C:\\junk\\replay.txt");
	in_file.open("C:\\junk\\replay.txt");
	out_file<<setprecision(3)<<setiosflags(ios::fixed);

	do
	 {

	 cleardevice();
	 setcolor(1);
	 settextstyle(0,0,7);
	 outtextxy(300,220,"3");
	 delay(1000);
	 cleardevice();

	 outtextxy(300,220,"2");
	 delay(1000);
	 cleardevice();

	 outtextxy(300,220,"1");
	 delay(1000);
	 cleardevice();

	 initial_settings(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl);

	 do
		{

		//Physics

		movement_and_gravity(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl);

		do
		 {
		 collisions(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Ar,Al,V,Av,Alivel,Aliver,Livesl,Livesr);
		 }while(collision_check(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Ar,Al,V,Av,Alivel,Aliver,Livesl,Livesr)&&Alivel&&Aliver);

		key_inputs_and_artificial_intelligence(Vxl,Vxr,Vyl,Vyr,Input,Input_r);

		write_replay(Lx,Rx,Ly,Ry,Bx,By,Vx,Vy,Vxr,Vyr,Vxl,Vyl,Cl,Cr);



		}while(Alivel&&Aliver&&!End);
		//One life (do while both slimes are alive)
	 if (!End&&!(Ai_l&&Ai_r))
	 {

	 getch();

	 setcolor(5);
	 settextstyle(2,0,5);
	 outtextxy(300,454,"Replay");
	 settextstyle(7,0,4);
	 setcolor(15);

	 //Read from file and show replay
	 while(!in_file.eof()&&!kbhit())
		{
		in_file>>Lx;
		in_file>>Ly;
		in_file>>Cl;
		in_file>>Rx;
		in_file>>Ry;
		in_file>>Cr;
		in_file>>Bx;
		in_file>>By;
		in_file>>Ael;
		in_file>>Aer;

		display_objects(int(Lx),int(Ly),Cl,int(Rx),int(Ry),Cr,int(Bx),int(By),SR,BR,Ael,Aer);

		}

	 Input=0;

	 in_file.close();
	 in_file.open("C:\\junk\\replay.txt");

	 out_file.close();
	 out_file.open("C:\\junk\\replay.txt");
	 }
	 if (!End)
		getch();

	 }while(Livesl>0&&Livesr>0&&!End);
	 //Game over (do while both slimes have lives)

	 settextstyle(0,0,7);
	 if(Ball=='L')
		 {
		 setcolor(4);
		 outtextxy(80,220,"RED WINS");
		 }
	 if(Ball=='R')
		 {
		 setcolor(2);
		 outtextxy(60,220,"GREEN WINS");
		 }

		if (!End)
		 delay(5000);

}

int landing_x(double& Bx,double& By,double& Vx,double& Vy,bool& Bounce)
{
//Local
double X;
double T_by;
double T_vy;
double T_vx;
//T means temporary

T_by=By;
T_vy=Vy;
T_vx=Vx;
X=Bx;

while(T_by>SR+BR+30)
 {
 T_vy-=.5;
 T_by+=T_vy;
 X+=T_vx;
 if (X<=BR)
	{
	X=BR;
	T_vx*=-1;
	Bounce=true;
	}
 if (X>=640-BR)
	{
	X=640-BR;
	T_vx*=-1;
	Bounce=true;
	}
 }
return int(X);
}

double landing_a(double& Bx,double& By,double& Vx,double& Vy)
{
//Local
double A;
double Y;  //Landing Y velocity

Y=Vy+Skips/2;
if (!Bounce)
 A=angle_find(Y,Vx);
else
 A=angle_find(Y,-Vx);


return A;
}

void go_l(int X)
{
if (Lx+Slidel>X+5)
 Input=97;

if (Lx+Slidel<X-5)
 Input=100;
}

void go_r(int X)
{
if (Rx+Slider>X+5)
 Input_r=75;
if (Rx+Slider<X-5)
 Input_r=77;
}

























