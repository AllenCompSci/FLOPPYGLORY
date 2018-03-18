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
	lv6();
	}
#endif

int lv6()
{
//local vars
randomize();
EnemyShip.resize(10);
Space.resize(100);
for(X=0;X<10;X++)
	EnemyShip[X].Eship.resize(11);
clrscr();
Ecolmn=10;

#ifdef Level_test
gr_start(grdriver,grmode,errorcode);
#endif

cleardevice();
draw_ship6(EnemyShip);
draw_my_ship(MyShip);
draw_shot1(MyShip,EnemyShip);
MvScr=0;
Move=' ';
MyShip.X=320;
MyShip.Y=460;
MyShip.Shootnum=0;
for(Y=0;Y<10;Y++)
	for(X=0;X<11;X++)
		{
		if(Y==9)
			EnemyShip[Y].Eship[X].Frontrow=true;
		else
			EnemyShip[Y].Eship[X].Frontrow=false;
		EnemyShip[Y].Eship[X].X=(X*58)+18;
		EnemyShip[Y].Eship[X].Y=(Y*30)+7;
		EnemyShip[Y].Eship[X].Fire=false;
		EnemyShip[Y].Enumber=11;
		}
MyShip.Win=false;
MyShip.Lose=false;
init_space(Space);
putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,COPY_PUT);
for(Y=0;Y<10;Y++)
	for(X=0;X<11;X++)
	putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,COPY_PUT);
delay(5000);
while(MyShip.Win==false&&MyShip.Lose==false)
	{
	move_enemies();
	if(kbhit())
		control_me();
	}
farfree(MyShip.Myship);
farfree(MyShip.Shotpic);
if(Ecolmn != 0)
	for(Y=0;Y<Ecolmn;Y++)
		for(X=0;X<EnemyShip[Y].Enumber;X++)
		{
			farfree(EnemyShip[Y].Eship[X].Enemyship);
			farfree(EnemyShip[Y].Eship[X].Enemyshot);
		}
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
for(Y=0;Y<Ecolmn;Y++)
	for(X=0;X<EnemyShip[Y].Enumber;X++)
	{
		if(EnemyShip[Y].Eship[X].Fire==true)
		{
			putimage(EnemyShip[Y].Eship[X].Eshot1.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
			putimage(EnemyShip[Y].Eship[X].Eshot2.X,EnemyShip[Y].Eship[X].Eshot2.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
			EnemyShip[Y].Eship[X].Eshot1.Y++;
			EnemyShip[Y].Eship[X].Eshot2.Y++;
			putimage(EnemyShip[Y].Eship[X].Eshot1.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,COPY_PUT);
			putimage(EnemyShip[Y].Eship[X].Eshot2.X,EnemyShip[Y].Eship[X].Eshot2.Y,EnemyShip[Y].Eship[X].Enemyshot,COPY_PUT);
			if(EnemyShip[Y].Eship[X].Eshot1.Y==MyShip.Y)
				if(((EnemyShip[Y].Eship[X].Eshot1.X>=MyShip.X-10&&EnemyShip[Y].Eship[X].Eshot1.X<=MyShip.X+10)||(EnemyShip[Y].Eship[X].Eshot1.X+4>=MyShip.X-10&&EnemyShip[Y].Eship[X].Eshot1.X+4<=MyShip.X+10))||((EnemyShip[Y].Eship[X].Eshot2.X>=MyShip.X-10&&EnemyShip[Y].Eship[X].Eshot2.X<=MyShip.X+10)||(EnemyShip[Y].Eship[X].Eshot2.X+4>=MyShip.X-10&&EnemyShip[Y].Eship[X].Eshot2.X+4<=MyShip.X+10)))
				{
					if(EnemyShip[Y].Eship[X].Eshot1.Y <=MyShip.Y+10&&EnemyShip[Y].Eship[X].Eshot1.Y >=MyShip.Y-10)
					{
						putimage(EnemyShip[Y].Eship[X].Eshot1.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
						putimage(EnemyShip[Y].Eship[X].Eshot2.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
						putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,XOR_PUT);
						blow_up(MyShip.X,MyShip.Y);
						MyShip.Lose=true;
					}
				}
			if(EnemyShip[Y].Eship[X].Eshot1.Y>479)
				{
				putimage(EnemyShip[Y].Eship[X].Eshot1.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
				putimage(EnemyShip[Y].Eship[X].Eshot2.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
				EnemyShip[Y].Eship[X].Fire=false;
				}
		}
	}


	if (MyShip.Shootnum <= 0)
		return;

	for(Tmp=0;Tmp<MyShip.Shootnum;Tmp++)
	{

		if(MyShip.Myshot[Tmp].Y > 0)
		{
			Ekill=false;
			for(Y=0;Y<Ecolmn;Y++)
				for(X=0;X<EnemyShip[Y].Enumber;X++)
				{


					if((MyShip.Myshot[Tmp].Y<=EnemyShip[Y].Eship[X].Y+4)&&(MyShip.Myshot[Tmp].Y>=EnemyShip[Y].Eship[X].Y-7))
					{
						if(((MyShip.Myshot[Tmp].X-11>=EnemyShip[Y].Eship[X].X-18&&MyShip.Myshot[Tmp].X-11<=EnemyShip[Y].Eship[X].X+18)||(MyShip.Myshot[Tmp].X-8>=EnemyShip[Y].Eship[X].X-18&&MyShip.Myshot[Tmp].X-8<=EnemyShip[Y].Eship[X].X+18))||((MyShip.Myshot[Tmp].X+9>=EnemyShip[Y].Eship[X].X-18&&MyShip.Myshot[Tmp].X+9<=EnemyShip[Y].Eship[X].X+18)||(MyShip.Myshot[Tmp].X+12>=EnemyShip[Y].Eship[X].X-18&&MyShip.Myshot[Tmp].X+12<=EnemyShip[Y].Eship[X].X+18)))
						{
							putimage(MyShip.Myshot[Tmp].X-11,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
							putimage(MyShip.Myshot[Tmp].X+9,MyShip.Myshot[Tmp].Y,MyShip.Shotpic,XOR_PUT);
							putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,XOR_PUT);
							putimage(EnemyShip[Y].Eship[X].Eshot1.X,EnemyShip[Y].Eship[X].Eshot1.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
							putimage(EnemyShip[Y].Eship[X].Eshot2.X,EnemyShip[Y].Eship[X].Eshot2.Y,EnemyShip[Y].Eship[X].Enemyshot,XOR_PUT);
							blow_up(EnemyShip[Y].Eship[X].X,EnemyShip[Y].Eship[X].Y);
							MyShip.Myshot[Tmp]=MyShip.Myshot[MyShip.Shootnum-1];
							MyShip.Shootnum--;
							if(Y>0&&EnemyShip[Y].Eship[X].Frontrow==true)
								EnemyShip[Y-1].Eship[X].Frontrow=true;
							farfree(EnemyShip[Y].Eship[X].Enemyship);
							farfree(EnemyShip[Y].Eship[X].Enemyshot);
							EnemyShip[Y].Eship[X]=EnemyShip[Y].Eship[EnemyShip[Y].Enumber-1];
							EnemyShip[Y].Enumber--;
							EnemyShip[Y].Eship.resize(EnemyShip[Y].Enumber);
							if(EnemyShip[Y].Enumber==0)
							{
								EnemyShip[Y]=EnemyShip[Ecolmn-1];
								EnemyShip.resize(Ecolmn-1);
								Ecolmn--;
								Y--;
								if(Ecolmn==0)
								{
									MyShip.Win=true;
									return;
								}
							}
							Ekill=true;
						}
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

if(MvScr%10==0)
{
	for(Y=0;Y<Ecolmn;Y++)
		for(X=0;X<EnemyShip[Y].Enumber;X++)
		{
			if(EnemyShip[Y].Eship[X].Frontrow==true&&EnemyShip[Y].Eship[X].Fire==false)
				if(random(10)==5)
				{
					EnemyShip[Y].Eship[X].Fire=true;
					putimage(EnemyShip[Y].Eship[X].X-10,EnemyShip[Y].Eship[X].Y+8,EnemyShip[Y].Eship[X].Enemyshot,COPY_PUT);
					putimage(EnemyShip[Y].Eship[X].X+10,EnemyShip[Y].Eship[X].Y+8,EnemyShip[Y].Eship[X].Enemyshot,COPY_PUT);
					EnemyShip[Y].Eship[X].Eshot1.X=EnemyShip[Y].Eship[X].X-10;
					EnemyShip[Y].Eship[X].Eshot1.Y=EnemyShip[Y].Eship[X].Y+8;
					EnemyShip[Y].Eship[X].Eshot2.X=EnemyShip[Y].Eship[X].X+10;
					EnemyShip[Y].Eship[X].Eshot2.Y=EnemyShip[Y].Eship[X].Y+8;
				}
		}

}

if(MvScr==1000)      //Moves enemies after
		{
		for(Y=0;Y<Ecolmn;Y++)
			for(X=0;X<EnemyShip[Y].Enumber;X++)
			{
			putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,XOR_PUT);
			EnemyShip[Y].Eship[X].X+=5;
			MvScr++;
			putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,COPY_PUT);
			}
		}
	else if(MvScr==2000)
				{
				for(Y=0;Y<Ecolmn;Y++)
					for(X=0;X<EnemyShip[Y].Enumber;X++)
					{
					putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,XOR_PUT);
					EnemyShip[Y].Eship[X].Y+=7;
					MvScr++;
					putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,COPY_PUT);
					}
				}
		else if(MvScr==3000)
					{
					for(Y=0;Y<Ecolmn;Y++)
						for(X=0;X<EnemyShip[Y].Enumber;X++)
						{
						putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,XOR_PUT);
						EnemyShip[Y].Eship[X].X-=5;
						MvScr++;
						putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,COPY_PUT);
						}
					}
			else if(MvScr==4000)
						{
						for(Y=0;Y<Ecolmn;Y++)
							for(X=0;X<EnemyShip[Y].Enumber;X++)
							{
							putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,XOR_PUT);
							EnemyShip[Y].Eship[X].Y-=5;
							MvScr=0;
							putimage(EnemyShip[Y].Eship[X].X-18,EnemyShip[Y].Eship[X].Y-7,EnemyShip[Y].Eship[X].Enemyship,COPY_PUT);
							}
						}
			else
			{
				delay(1);
				MvScr++;
				Time++;
			}

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
			if(MyShip.Shootnum < 10)
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
		}
		putimage(MyShip.X-10,MyShip.Y,MyShip.Myship,COPY_PUT);
}

#endif