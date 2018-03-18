//Kenny Hoang, Tanzim Ahamed, Hunter Scott
//Brick Breaker
//Period 5
#include <conio.h>
#include <iomanip.h>
#include <iostream.h>
#include <apstring.h>
#include <graphics.h>
#include <STDlib.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
#include <time.h>
#include <dos.h>
#include <alloc.h>


/*Program Description
Our program sets up a game called Brick-Break. I'm sure most of you guys have
played this game before either on the Blackberry handheld or somewhere else.
The point of the game is to use a launching pad to destroy the bricks on the
upper half of the screen. Just do not allow the ball to fall under the
launching pad, or you will lose.
*/


/*Variable dictionary
Our 'int x,y' in the struct is just the X/Y coordinates for the placement of
our bricks on the top half of the screen.
The bool value in our struct represents whether a color has changed,
therefore telling the programmer/user if a brick has been hit.
The char End, Menu, and Yes all have the purpose of manipulating the title
screen.
grdriver, grmode, and errorcode are all default variables for graphics mode.
X_left represents the movement of the launch pad in respect to the left side
of the screen.
char Back and Play are meant for the title screen as well.
bool Flag is commented out, it was a test. Bool Exit is meant to exit the
game from the title screen.  Bool Gone has the purpose of creating a function
that destroys the bricks.
The IX and IY under the variable section are both counting mechanisms for the
movement of the ball.
Xc and Yc deal with the purpose of ball movement and the collision between
the ball and the launch pad.
int T and Y are both counting mechanisms for the destruction of the bricks.
int Key is also just a counting mechanism.*/




//Structs
struct Block
{
int X,Y;
bool On;
};

//Constants

//Global Variable
char End, Menu, Yes;
int grdriver, grmode, errorcode, X_left;
char Play, Back,Leave,Dir;
bool Flag, Exit, Gone;
int IX, IY,Xc, Yc, T, Y;
int Key;
apmatrix <Block> Blocks (10,10);

//Prototype
void gr_start(int&,int&,int&);
void display (apmatrix <Block>);
void check();
void init (apmatrix <Block>&);
void destroy (apmatrix <Block>);

void main()
{
do{
clrscr();
gr_start(grdriver,grmode,errorcode);

//Title Screen

//B
setfillstyle(5,5);
bar(10,30,15,100);
bar(10,30,50,30);
bar(50,30,55,55);
bar(10,55,65,55);
bar(10,100,65,100);
bar(65,55,65,100);

//R
setfillstyle(9,3);
bar(80,30,85,100);
bar(80,30,120,30);
bar(120,30,125,55);
bar(80,55,120,55);
bar(119,55,119,100);

//I
setfillstyle(2,6);
bar(140,30,140,100);

//C
setfillstyle(8,9);
bar(155,30,155,100);
bar(155,30,190,30);
bar(155,100,190,100);

//K
setfillstyle(6,7);
bar(205,30,205,100);
line(205,65,250,30);
line(205,65,250,100);

//B
setfillstyle(5,5);
bar(80,110,85,180);
bar(80,110,120,110);
bar(120,110,125,135);
bar(80,135,135,135);
bar(80,180,135,180);
bar(135,135,135,180);

//R
setfillstyle(9,3);
bar(150,110,155,180);
bar(150,110,190,110);
bar(190,110,195,135);
bar(150,135,190,135);
bar(189,135,189,180);

//E
setfillstyle(4,8);
bar(205,110,210,180);
bar(205,110,235,110);
bar(205,145,235,145);
bar(205,180,235,180);

//A
setfillstyle(14,2);
line(250,180,270,110);
line(290,180,270,110);
bar(262,140,279,141);

//K
setfillstyle(6,7);
bar(305,110,305,180);
line(305,145,355,110);
line(305,145,355,180);

//E
setfillstyle(4,9);
bar(380,110,385,180);
bar(380,110,410,110);
bar(380,145,410,145);
bar(380,180,410,180);

//R
setfillstyle(9,3);
bar(430,110,435,180);
bar(430,110,470,110);
bar(470,110,475,135);
bar(430,135,470,135);
bar(469,135,469,180);

setfillstyle(1,7);
bar(250,469,325,479);

setfillstyle(1,6);
bar(500,25,540,35);
bar(550,80,590,90);
bar(400,50,440,60);
bar(350,30,390,40);
bar(300,60,340,70);
bar(20,400,60,410);
bar(25,350,65,360);
bar(35,200,75,210);
bar(55,250,95,260);
bar(100,290,140,300);
bar(500,350,540,360);
bar(540,370,580,380);
bar(450,250,490,260);
bar(430,500,470,510);
bar(600,400,640,410);




//Statements seen in the title screen
	outtextxy(256,250,"Brick Breaker");
	outtextxy(236,300,"Press 'P' to play");
	outtextxy(220,350,"Press 'D' for directions");
	outtextxy(235,400,"Press 'E' to end game");
	cin>>Dir;
	if(Dir=='D'||Dir=='d')
	{
	do{

//Instructions
	clrscr();
	cout<<"The objective of the game is to destroy the bricks with a flying";
	cout<<endl;
	cout<<"ball.  At the beginning of the game, the ball will show up on top of";
	cout<<endl;
	cout<<"a launch pad.  Press the space bar to launch the ball off the pad.";
	cout<<endl;
	cout<<"The ball will bounce around randomly.  Use right and left arrows to";
	cout<<endl;
	cout<<"control the pad at the bottom after the ball has been launched. Just";
	cout<<endl;
	cout<<"do not allow the ball to fall under the pad.  If the user allows";
	cout<<endl;
	cout<<"the ball to fall, the game is over.  Just go back to the user screen.";
	cout<<endl;

	cout<<"Press ESC to exit in the middle of the game. Hope you enjoy!";
	cout<<endl;
	cout<<"Press 'T' to go back to title page.";
	cin>>Leave;
			}while(Leave!='T'&&Leave!='t');
		}
	if(Play=='P'&&Play=='p')
	{
	 randomize();
		do{
			init(Blocks);

			int Barcolor, Score;
			setcolor(7);
			fillellipse(320,330,4,4);
			setfillstyle(1,4);
			X_left=260;
			Key=0;
		//Flag=true;
		//Exit=false;

			bool lose=true;


			IX=1;
			IY=-1;
			Xc=240;
			Yc=430;
			cleardevice();
			display(Blocks);
			do{
			setfillstyle(1,4);
		//Destroy the bricks

		for(T=0;T<10;T++)
					for(Y=0;Y<10;Y++)
					{
					if(Blocks[T][Y].On)
					if(Blocks[T][Y].X<Xc+10&&Blocks[T][Y].X+40>Xc-10)
					if(Blocks[T][Y].Y<Yc+10&&Blocks[T][Y].Y+10>Yc-10)
					{
						setcolor(0);
						setfillstyle(1,0);
						Blocks[T][Y].On=false;
						bar(Blocks[T][Y].X,Blocks[T][Y].Y,Blocks[T][Y].X+40,Blocks[T][Y].Y+10);

					}


					}



		if(kbhit())
			{
			Key=getch();

		//left
					 if(Key==75)
						if(X_left>0)
							{
							setfillstyle(0,7);
							setcolor(7);
							bar(X_left,437,X_left+100,462);
							setcolor(3);
							X_left=X_left-30;
							}
		//right
					 if(Key==77)
						if(X_left<540)
							{
							setfillstyle(0,7);
							setcolor(7);
							bar(X_left,437,X_left+100,462);
							X_left=X_left+30;
							}

				}
		//Movement

		//setbkcolor(random(0));

		//Color Boundary
		setcolor(4);
		line(639,0,639,479);
		line(639,479,1,479);
		line(1,479,1,0);
		line(1,0,639,0);



		//Ball movement



			if(Xc>=630||Xc<=10)
			IX*=-1;

			if(Yc<=10)
			IY*=-1;

				if(Yc>=430)
			{
				if(Xc<=X_left-10||Xc>=X_left+85)
				lose=false;
				else
				IY*=-1;
				}

				if(Yc==480)
				{
				cout<<"Press escape to exit the game, you have lost!";
				}



				 Xc+=IX;
				 Yc+=IY;
				 setcolor(random(0));
				 setfillstyle(0,4);
				 circle(Xc,Yc,10)  ;
				 fillellipse(Xc,Yc,10,10);
				 setcolor(4);
				 setfillstyle(1,4);
				 fillellipse(Xc,Yc,10,10);





				 bar(X_left,450,X_left+75,460);

				 setfillstyle(1,0);
				 delay(5);


				 bar(Xc-10,Yc-10,Xc+10,Yc+10);
				 setcolor(random(0));
				 setfillstyle(0,4);
				 circle(Xc,Yc,10)  ;
				 fillellipse(Xc,Yc,10,10);
				 setcolor(4);
				 setfillstyle(1,4);



}while(Key!=27||lose==true);

}while(!kbhit);
}


 }while(Play=='E'&&Play=='e');



 }


//Functions
void gr_start(int&grdriver,int&grmode,int&errorcode)
{grdriver=VGA;
 grmode=VGAHI;
 initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
 errorcode=graphresult();
 if (errorcode!=grOk)
 {clrscr();
	cout<<"Error: "<<errorcode<<endl;
	cout<<"Press enter to continue.";
 getch();
 exit(1);
 }
};


void init (apmatrix <Block> & Blocks)
{
	int Row,R;
	int Col,C;
	C=20;
	R=50;
	for(Row=0;Row<10;Row++)
	{
		for(Col=0;Col<10;Col++)
		{Blocks[Row][Col].On=true;
		 Blocks[Row][Col].X=C+(Col*60);
		 Blocks[Row][Col].Y=R;
		}
		R+=30;
	}
};

void display (apmatrix <Block> Blocks)
{
	int Row,R;
	int Col,C;
	setfillstyle(1,2);
	setcolor(2);
for(Row=0;Row<10;Row++)
	for(Col=0;Col<10;Col++)
		{
if(Blocks[Row][Col].On==true)
bar(Blocks[Row][Col].X,Blocks[Row][Col].Y,Blocks[Row][Col].X+40,Blocks[Row][Col].Y+10);
		}

//	for(Col=0;Col<10;Col++)
//bar(Blocks[0][Col].X,Blocks[0][Col].Y,Blocks[0][Col].X+40,Blocks[0][Col].Y+10);
};

/*int Barcolor, Score, I, Y2, X2;
void check()
{
for(I=0;I<100;I++)
{
	Barcolor=getpixel(I,462);
	if(Barcolor==4)
	{
		setfillstyle(1,0);
		setcolor(0);
		IX*=-1;
		Score++;
		bar(X_left,437,X_left+100,462);
	}
}
} */