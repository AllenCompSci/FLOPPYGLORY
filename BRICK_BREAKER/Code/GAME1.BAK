//Tanzim Ahamed, Hunter Scott, Kenny Hoang
//Brick-Breaker
//Period 5
#include <conio.h>
#include <iomanip.h>
#include <iostream.h>
#include <graphics.h>
#include <apstring.h>
#include <STDlib.h>
#include <apmatrix.h>
#include <fstream.h>
#include <apvector.h>
#include <time.h>
#include <dos.h>
#include <alloc.h>
//Struct
struct Block

{
int X,Y;
bool On;
};

//const

//Global var
char Yes;
int grdriver,grmode,errorcode,X_left;
bool Flag, Exit, Gone;
int RX,RY,IX,IY,Xc,Yc,T,Y;
int Key;
apmatrix <Block> Blocks (10,10);


//Prototype
void gr_start(int&,int&,int&);
void init (apmatrix <Block>&);
void display (apmatrix <Block>);
void destroy (apmatrix <Block>);
void check ();


void main()
{
do{clrscr();
gr_start(grdriver,grmode,errorcode);
randomize();

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
//Function
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
