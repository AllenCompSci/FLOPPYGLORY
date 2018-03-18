#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<apstring.h>
#include<apmatrix.h>
#include<apvector.h>
#include<graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <fstream.h>
#include "lv.hpp"
#include "mainmenu.hpp"
#include "mybitmap.hpp"

//Constants

//Global Variables
//#define Level_test

#ifdef Level_test
static int grdriver, grmode, errorcode;
static void gr_start(int&,int&,int&);
#endif

static void control_shot();
static void move_enemies();
static void control_me();

#ifdef Level_test
void main()
	{
	boss1();
	}
#endif

int boss4()
{
//local var
randomize();
clrscr();
EnemyShip.resize(10);
Space.resize(100);
for(X=0;X<10;X++)
	EnemyShip[X].Eship.resize(11);
#ifdef Level_test
gr_start(grdriver,grmode,errorcode);
#endif

cleardevice();
draw_my_ship(MyShip);
draw_shot1(MyShip,EnemyShip);
draw_boss_shot1(Boss);
draw_boss4(Boss);
MvScr=0;
Move=' ';
MyShip.X=320;
MyShip.Y=460;
MyShip.Shootnum=0;
Boss.Numshot=0;
Boss.X=639-463;
Boss.Y=10;
MyShip.Lose=false;
init_space(Space);
putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,COPY_PUT);
putimage(Boss.X,Boss.Y,Boss.Bosspic,COPY_PUT);
delay(5000);
while(MyShip.Win==false&&MyShip.Lose==false)
	{
	move_enemies();
	if(kbhit())
		control_me();
	}
farfree(MyShip.Myship);
farfree(MyShip.Shotpic);
farfree(Boss.Bshot);
farfree(Boss.Bosshit);
farfree(Boss.Bosspic);
getch();
clrscr();
cleardevice();
if(MyShip.Win==true)
	return 1;
else
	return 0;
}
#ifdef Level_test
void gr_start(int& grdriver,int& grmode,int& errorcode)
{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"c:\\tc\\bgi");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
		clrscr();
		cout<<"Error:"<<errorcode<<endl;
		cout<<"Press Return to Continue";
		getch();
		exit(1);
		}
}
#endif

#if 1
static void control_shot()
{
		if(Boss.Fire==true)
		{
			putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,XOR_PUT);
			putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,XOR_PUT);
			Boss.Bshot1.Y+=3;
			Boss.Bshot2.Y+=3;
			putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,COPY_PUT);
			putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,COPY_PUT);
			if(Boss.Bshot1.Y==MyShip.Y)
				if(((Boss.Bshot1.X>=MyShip.X-10&&Boss.Bshot1.X<=MyShip.X+10)||(Boss.Bshot1.X+4>=MyShip.X-10&&Boss.Bshot1.X+4<=MyShip.X+10))||((Boss.Bshot2.X>=MyShip.X-10&&Boss.Bshot2.X<=MyShip.X+10)||(Boss.Bshot2.X+4>=MyShip.X-10&&Boss.Bshot2.X+4<=MyShip.X+10)))
				{
					if(Boss.Bshot1.Y <=MyShip.Y+10&&Boss.Bshot1.Y >=MyShip.Y-10)
					{
						putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,XOR_PUT);
						putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,XOR_PUT);
						putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,XOR_PUT);
						blow_up(MyShip.X,MyShip.Y);
						MyShip.Lose=true;
					}
				}
			if(Boss.Bshot1.Y>479)
				{
				putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,XOR_PUT);
				putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,XOR_PUT);
				Boss.Fire=false;
				}
		}


	if (MyShip.Shootnum <= 0)
		return;

	for(Tmp=0;Tmp<MyShip.Shootnum;Tmp++)
	{

		if(MyShip.Myshot[Tmp].Y > 0)
		{
			Ekill=false;
					if((MyShip.Myshot[Tmp].Y<=Boss.Y+197)&&(MyShip.Myshot[Tmp].Y>=Boss.Y))
					{
						if(((MyShip.Myshot[Tmp].X-11>=Boss.X&&MyShip.Myshot[Tmp].X-11<=Boss.X+463)||(MyShip.Myshot[Tmp].X-8>=Boss.X&&MyShip.Myshot[Tmp].X-8<=Boss.X+463))||((MyShip.Myshot[Tmp].X+9>=Boss.X&&MyShip.Myshot[Tmp].X+463<=Boss.X)||(MyShip.Myshot[Tmp].X+12>=Boss.X&&MyShip.Myshot[Tmp].X+12<=Boss.X+463)))
						{
							putimage(MyShip.Myshot[Tmp].X-11,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
							putimage(MyShip.Myshot[Tmp].X+9,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
							if(Boss.Numshot==50)
							{
								putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,XOR_PUT);
								putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,XOR_PUT);
								putimage(Boss.X,Boss.Y,Boss.Bosspic,XOR_PUT);
								MyShip.Win=true;
							}
							else
							{
								putimage(Boss.X,Boss.Y,Boss.Bosspic,XOR_PUT);
								putimage(Boss.X,Boss.Y,Boss.Bosshit,COPY_PUT);
								Boss.Numshot++;
								delay(1);
								putimage(Boss.X,Boss.Y,Boss.Bosshit,XOR_PUT);
								putimage(Boss.X,Boss.Y,Boss.Bosspic,COPY_PUT);
							}
							MyShip.Myshot[Tmp]=MyShip.Myshot[MyShip.Shootnum-1];
							MyShip.Shootnum--;
							Ekill=true;
						}
					}
				if(Ekill==false)
				{
					Ekill=false;
					putimage(MyShip.Myshot[Tmp].X-11,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
					putimage(MyShip.Myshot[Tmp].X+9,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
					MyShip.Myshot[Tmp].Y--;
					putimage(MyShip.Myshot[Tmp].X-11,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,COPY_PUT);
					putimage(MyShip.Myshot[Tmp].X+9,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,COPY_PUT);
				}

		}
		else
		{
			putimage(MyShip.Myshot[Tmp].X-11,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
			putimage(MyShip.Myshot[Tmp].X+9,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
			MyShip.Myshot[Tmp]=MyShip.Myshot[MyShip.Shootnum-1];
			MyShip.Shootnum--;
		}
	} // end for (Tmp)

}


static void move_enemies()
{
if(MvScr%20 == 0)
	move_space(Space);
if(MvScr%5 == 0)
	control_shot();

if(Boss.Fire==false)
	if(MvScr%10==0)
	{
		if(random(100)==5)
		{
		if(MyShip.X>=Boss.X&&MyShip.X<=Boss.X+462)
			{
				Boss.Fire=true;
				Boss.Bshot1.X=random(100)+MyShip.X-random(100);
				Boss.Bshot1.Y=Boss.Y+197;
				do{
					Boss.Bshot2.X=random(100)+MyShip.X-random(100);
					}while((Boss.Bshot2.X<=Boss.Bshot1.X-20&&Boss.Bshot2.X>=Boss.Bshot1.X+20)&&(Boss.Bshot2.X>=Boss.X&&Boss.Bshot2.X<=Boss.X+300));
				Boss.Bshot2.Y=Boss.Y+197;
				putimage(Boss.Bshot1.X,Boss.Bshot1.Y,Boss.Bshot,COPY_PUT);
				putimage(Boss.Bshot2.X,Boss.Bshot2.Y,Boss.Bshot,COPY_PUT);
			}
		}

	}

MvScr++;
delay(1);
Time++;
}

static void control_me()
{
		Move=getch();
		delay(1);
		if(Move=='4')
			if(MyShip.X-5 > 11)
				{
				putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,XOR_PUT);
				MyShip.X-=5;
				}
		if(Move=='6')
			if(MyShip.X+5 < 628)
				{
				putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,XOR_PUT);
				MyShip.X+=5;
				}
		if(Move=='8')
		{
				if(MyShip.Shootnum <= 2)
				{
					MyShip.Shootnum++;
					MyShip.Myshot.resize(MyShip.Shootnum);
					MyShip.Myshot[MyShip.Shootnum-1].X=MyShip.X;
					MyShip.Myshot[MyShip.Shootnum-1].Y=MyShip.Y;
					MyShip.Myshot[MyShip.Shootnum-1].Shoot=true;
					putimage(MyShip.Myshot[MyShip.Shootnum-1].X-11,MyShip.Myshot[MyShip.Shootnum-1].Y,MyShip.Shotpic,COPY_PUT);
					putimage(MyShip.Myshot[MyShip.Shootnum-1].X+9,MyShip.Myshot[MyShip.Shootnum-1].Y,MyShip.Shotpic,COPY_PUT);
					}

		}
		putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,COPY_PUT);
}

#endif