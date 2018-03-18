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
#include "shipdata.hpp"
#include "mybitmap.hpp"

//#define Ship_test
//Global Variables
#ifdef Ship_test //used for testing the ship picts
 apvector <Edat> Dat(10);
 Myship_dat Data;
 Bosses Boss;
 int grdriver, grmode, errorcode;
 apvector <Star> Space(100);
#endif

#ifdef Ship_test //used for testing the ship picts
static void gr_start(int&,int&,int&);

void main()
	{
	gr_start(grdriver,grmode,errorcode);
	draw_boss_shot1(Boss);
	getch();
	}
static void gr_start(int& grdriver,int& grmode,int& errorcode)
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



void draw_my_ship(Myship_dat& MyShip)
{
	//local vars
	int Temp,X,Y;
	X=639/2;
	Y=479/2;
	change_color();
#if 0

	Columns ^
					***
					***
					***              Rows >
					***
				 *****
				 *****
				 *****
				 *****
				*******
				**?O?** <      10
			 ***???***       11
 **		 **?????**    ** 12
 **		***?????***   ** 13
 ** 	**???????**   ** 14
 ** ****???????**** ** 15
 **	***?????????*** ** 16
 *********************
 *********************
 *********************
					 ^
		//	 789112345
		 //	 ^19x21>


#endif


	//Column 1 & 2, 20 & 21//guns - red
	for(Temp=Y+2;Temp <= Y+9;Temp++)
		{
		putpixel(X-10,Temp,9);
		putpixel(X-9,Temp,9);
		putpixel(X+10,Temp,9);
		putpixel(X+9,Temp,9);
		}

	//Column 3 & 19
	for(Temp=Y+7;Temp <= Y+9;Temp++)
		{
		putpixel(X-8,Temp,15);
		putpixel(X+8,Temp,15);
		}

	//Column 4 & 5, 17 & 18
	for(Temp=Y+5;Temp <= Y+9;Temp++)
		{
		putpixel(X-7,Temp,15);
		putpixel(X-6,Temp,15);
		putpixel(X+7,Temp,15);
		putpixel(X+6,Temp,15);
		}

	//Column 6 & 16
	for(Temp=Y+3;Temp <= Y+9;Temp++)
		{
		putpixel(X-5,Temp,15);
		putpixel(X+5,Temp,15);
		}


	//Column 7 & 15
	for(Temp=Y+1;Temp <= Y+9;Temp++)
		{
		putpixel(X-4,Temp,15);
		putpixel(X+4,Temp,15);
		}

	//Column 8 & 14
	for(Temp=Y-1;Temp <= Y+9;Temp++)
		{
		putpixel(X-3,Temp,15);
		putpixel(X+3,Temp,15);
		}

	//Column 9 & 13
	for(Temp=Y-5;Temp <= Y+9;Temp++)
		{
		putpixel(X-2,Temp,15);
		putpixel(X+2,Temp,15);
		}

	//Column 10,11,12
	for(Temp=Y-9;Temp <= Y+9;Temp++)
		{
		putpixel(X-1,Temp,15);
		putpixel(X,Temp,15);
		putpixel(X+1,Temp,15);
		}

	//cockpit 7-15, 10-16
	//row 16
	for(Temp=X-5;Temp <= X+5;Temp++)
		putpixel(Temp,Y+6,4);

	//row 45 & 44
	for(Temp=X-4;Temp <= X+4;Temp++)
		{
		putpixel(Temp,Y+5,4);
		putpixel(Temp,Y+4,4);
		}

	//row 13 & 12
	for(Temp=X-3;Temp <= X+3;Temp++)
		{
		putpixel(Temp,Y+3,4);
		putpixel(Temp,Y+2,4);
		}

	//row 11 & 10
	for(Temp=X-2;Temp <= X+2;Temp++)
		{
		putpixel(Temp,Y+1,4);
		putpixel(Temp,Y,4);
		putpixel(Temp,Y,4);
		putpixel(Temp,Y,4);
		putpixel(Temp,Y,4);
		}
	//store ship in mem
	//mem - 234
	MyShip.Mysize=imagesize(X-10,Y-9,X+10,Y+9);
	MyShip.Myship=farmalloc(MyShip.Mysize);
	if(!MyShip.Myship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata MyShip";
			getch();
			exit(1);
			}
	getimage(X-10,Y-9,X+10,Y+9,MyShip.Myship);
	putimage(X-10,Y-9,MyShip.Myship,XOR_PUT);

}


void draw_ship1(apvector <Edat>& EnemyShip)
{
	//local vars
	int X,Y,I,Z;

	X=639/2;
	Y=479/2;
	change_color();
#if 0 // Drone

								-------8 8-------
								*****************-
								*****************-
								*****************-
								** **&&&&&&&** **4
								**  **&&O&&**  **  <center
								**   **&&&**   **4
								**    **&**    **-
								**     ***     **-
								**      *      **-
												^center

										17> & 9^


#endif // Drone


	//back
	setcolor(15);
	line(X-8,Y-4,X+8,Y-4);
	line(X-8,Y-3,X+8,Y-3);
	line(X-8,Y-2,X+8,Y-2);

//shooters
setcolor(1);
line(X-8,Y-4,X-8,Y+4);
line(X-7,Y-4,X-7,Y+4);
line(X+8,Y-4,X+8,Y+4);
line(X+7,Y-4,X+7,Y+4);

//head
setcolor(15);
line(X-5,Y-1,X+5,Y-1);
line(X-4,Y,X+4,Y);
line(X-3,Y+1,X+3,Y+1);
line(X-2,Y+2,X+2,Y+2);
line(X-1,Y+3,X+1,Y+3);
putpixel(X,Y+4,15);

//cockpit
setcolor(1);
line(X-4,Y-1,X+4,Y-1);
line(X-3,Y,X+3,Y);
line(X-2,Y+1,X+2,Y+1);
line(X-1,Y+2,X+1,Y+2);
putpixel(X,Y+3,12);

//store in mem
for(I=0;I<10;I++)//mem - 114 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-8,Y-4,X+8,Y+4);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 1";
			getch();
			exit(1);
			}
		getimage(X-8,Y-4,X+8,Y+4,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-8,Y-4,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}


void draw_shot1(Myship_dat& MyShip, apvector <Edat>& EnemyShip)
{
//localvars
int Y,X,I,Z;

change_color();
#if 0 // Shot

					//10 over
				 **
				****
				****
				 **   <center
				 *O
				 **
				 **
				 **
					^center
				4x8

#endif // Shot

Y=479/2;
X=639/2;
setcolor(4);
//MyShot 1
putpixel(X+1,Y-3,1);
putpixel(X+1,Y-2,1);
putpixel(X-2,Y-3,1);
putpixel(X-2,Y-2,1);
line(X,Y-3,X,Y+3);
line(X-1,Y-3,X-1,Y+3);

//mem - 42
MyShip.Shotsize=imagesize(X-2,Y-4,X+1,Y+4);
MyShip.Shotpic=farmalloc(MyShip.Shotsize);
if(!MyShip.Shotpic)
{
	cout<<"Out of Mem"<<endl;
	cout<<"Shipdata MyShip shot";
	getch();
	exit(1);
}
getimage(X-2,Y-4,X+1,Y+4,MyShip.Shotpic);
putimage(X-2,Y-4,MyShip.Shotpic,XOR_PUT);
//Enemy Shot1
setcolor(1);
putpixel(X+1,Y+3,4);
putpixel(X+1,Y+2,4);
putpixel(X-2,Y+3,4);
putpixel(X-2,Y+2,4);
line(X,Y-3,X,Y+3);
line(X-1,Y-3,X-1,Y+3);

for(I=0;I<10;I++)//mem - 42 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Eshotsize=imagesize(X-2,Y-4,X+1,Y+4);
		EnemyShip[I].Eship[Z].Enemyshot=farmalloc(EnemyShip[I].Eship[Z].Eshotsize);
		if(!EnemyShip[I].Eship[Z].Enemyshot)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata Enemyshot";
			getch();
			exit(1);
			}
		getimage(X-2,Y-4,X+1,Y+4,EnemyShip[I].Eship[Z].Enemyshot);
	}
putimage(X-2,Y-4,EnemyShip[0].Eship[0].Enemyshot,XOR_PUT);
}

void draw_ship2(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z;

X=639/2;
Y=479/2;
change_color();
#if 0

						 45   54
							 *****   Engine
							*******
Shooter    6    Body
				** ************* **
				** ************* **  Shooter
				**  ***********  **
				**   *+++O+++*   ** <6
				**   **+++++**   **
				**    **+++**    **
				**     **+**     **
				**      ***      **
								 *
								 ^9

							17> 11^

#endif


//Draw Ship 1
//engine
setcolor(7);
line(X-4,Y-5,X+4,Y-5);
line(X-5,Y-4,X+5,Y-4);
putpixel(X-1,Y-5,8);
putpixel(X+1,Y-5,8);
putpixel(X-2,Y-4,8);
putpixel(X,Y-4,8);
putpixel(X+2,Y-4,8);

//body
//top 2 rows
line(X-6,Y-3,X+6,Y-3);
line(X-6,Y-2,X+6,Y-2);
//next  row
line(X-5,Y-1,X+5,Y-1);
//next 2
line(X-4,Y,X+4,Y);
line(X-4,Y+1,X+4,Y+1);
//next
line(X-3,Y+2,X+3,Y+2);
//next
line(X-2,Y+3,X+2,Y+3);
//next
line(X-1,Y+4,X+1,Y+4);
//next
putpixel(X,Y+5,7);

//shooters
setcolor(1);
line(X-8,Y-3,X-8,Y+4);
line(X-7,Y-3,X-7,Y+4);
line(X+8,Y-3,X+8,Y+4);
line(X+7,Y-3,X+7,Y+4);

//cockpit
setcolor(1);
line(X-3,Y,X+3,Y);
line(X-2,Y+1,X+2,Y+1);
line(X-1,Y+2,X+1,Y+2);
putpixel(X,Y+3,4);

for(I=0;I<10;I++)//mem - 138 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-8,Y-5,X+8,Y+5);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 2";
			getch();
			exit(1);
			}
		getimage(X-8,Y-5,X+8,Y+5,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-8,Y-5,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);

}

void draw_ship3(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z;

X=639/2;
Y=479/2;
change_color();
#if 0 // Ship #3

						*************
					 ***************
					*****************
				 *******************
				;;;***************;;;
				;;;*******O*******;;;<6
				;;; **.........** ;;;
				;;;  **.......**  ;;;
				;;;   **.....**   ;;;
				;;;    *******    ;;;
				;;;     *****     ;;;
									^11

								21> 11^


#endif // Ship #3


//draw shooters
setcolor(1);
line(X-10,Y-1,X-10,Y+5);
line(X-9,Y-1,X-9,Y+5);
line(X-8,Y-1,X-8,Y+5);
line(X+10,Y-1,X+10,Y+5);
line(X+9,Y-1,X+9,Y+5);
line(X+8,Y-1,X+8,Y+5);

//draw body
setcolor(7);
line(X-6,Y-5,X+6,Y-5);
line(X-7,Y-4,X+7,Y-4);
line(X-8,Y-3,X+8,Y-3);
line(X-9,Y-2,X+9,Y-2);
line(X-7,Y-1,X+7,Y-1);
line(X-7,Y,X+7,Y);
line(X-6,Y+1,X+6,Y+1);
line(X-5,Y+2,X+5,Y+2);
line(X-4,Y+3,X+4,Y+3);
line(X-3,Y+4,X+3,Y+4);
line(X-2,Y+5,X+2,Y+5);

//cockpit
setcolor(1);
line(X-4,Y+1,X+4,Y+1);
line(X-3,Y+2,X+3,Y+2);
line(X-2,Y+3,X+2,Y+3);

for(I=0;I<10;I++)//mem - 138 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-10,Y-5,X+10,Y+5);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 3";
			getch();
			exit(1);
			}
		getimage(X-10,Y-5,X+10,Y+5,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-10,Y-5,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}

void draw_ship4(apvector <Edat>& EnemyShip)
{
//local var
int X,Y,I,Z;

X=639/2;
Y=479/2;
change_color();
#if 0
										 20 20
					 *************************
				 *****************************
			 *********************************
		 **********.................**********
	 **********.....................**********
	 **********.....................**********
		 **********........O........********** <7
			 *********************************
				 *****************************
					 *************************
								;;;;;;;;;;;;;;;
									;;;;;;;;;;;
										;;;;;;;
											 ^21

										 41> 13^

#endif

//draw body
setcolor(8);
line(X-12,Y-6,X+12,Y-6);
line(X-12,Y+3,X+12,Y+3);

line(X-14,Y-5,X+14,Y-5);
line(X-14,Y+2,X+14,Y+2);

line(X-16,Y-4,X+16,Y-4);
line(X-16,Y+1,X+16,Y+1);

line(X-18,Y-3,X+18,Y-3);
line(X-18,Y,X+18,Y);

line(X-20,Y-2,X+20,Y-2);
line(X-20,Y-1,X+20,Y-1);

//cockpit
setcolor(1);
line(X-8,Y-3,X+8,Y-3);
line(X-8,Y,X+8,Y);

line(X-10,Y-2,X+10,Y-2);
line(X-10,Y-1,X+10,Y-1);

//firing sphere
setcolor(3);
line(X-7,Y+4,X+7,Y+4);
line(X-5,Y+5,X+5,Y+5);
line(X-3,Y+6,X+3,Y+6);

for(I=0;I<10;I++)//mem - 318 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-20,Y-6,X+20,Y+6);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 4";
			getch();
			exit(1);
			}
		getimage(X-20,Y-6,X+20,Y+6,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-20,Y-6,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}
void draw_ship8(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z;

X=639/2;
Y=479/2;
change_color();
#if 0
								*********************10   12
							*************************12
						*****************************14
					*********************************16
				*************************************18
			*****************************************20
										 ,,,,,,,,,,,
										 ,,,,,,,,,,,
			*****************************************
			*****************************************
			........       ,,,,,,,,,,,       ........
				....  			 ,,,,,,,,,,,         ....
				 ..  	************O************   ..  <13
				 .. 		*********************     ..
									*****************   ^12
										*************    ^10
											*********
												*****2
												 ***1
												 ***
												 ***
												 ***
												 ***
												 ***
													*
													^21

												^25  <41

#endif

//shooters
setcolor(1);
line(X-20,Y-2,X-13,Y-2);
line(X+20,Y-2,X+13,Y-2);

line(X-18,Y-1,X-15,Y-1);
line(X+18,Y-1,X+15,Y-1);

setcolor(3);
line(X-17,Y,X-17,Y+1);
line(X+17,Y,X+17,Y+1);

line(X-16,Y,X-16,Y+1);
line(X+16,Y,X+16,Y+1);

//connections
setcolor(7);
line(X-5,Y-6,X+5,Y-6);
line(X-5,Y-5,X+5,Y-5);
line(X-5,Y-2,X+5,Y-2);
line(X-5,Y-1,X+5,Y-1);

//body
setcolor(8);
line(X-10,Y-12,X+10,Y-12);
line(X-12,Y-11,X+12,Y-11);
line(X-14,Y-10,X+14,Y-10);
line(X-16,Y-9,X+16,Y-9);
line(X-18,Y-8,X+18,Y-8);
line(X-20,Y-7,X+20,Y-7);
line(X-20,Y-4,X+20,Y-4);
line(X-20,Y-3,X+20,Y-3);
line(X-12,Y,X+12,Y);
line(X-10,Y+1,X+10,Y+1);
line(X-8,Y+2,X+8,Y+2);
line(X-6,Y+3,X+6,Y+3);
line(X-4,Y+4,X+4,Y+4);
line(X-2,Y+5,X+2,Y+5);
line(X-1,Y+6,X-1,Y+11);
line(X,Y+6,X,Y+11);
line(X+1,Y+6,X+1,Y+11);
putpixel(X,Y+12,4);

for(I=0;I<10;I++)//mem - 606 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-20,Y-12,X+20,Y+12);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 8";
			getch();
			exit(1);
			}
		getimage(X-20,Y-12,X+20,Y+12,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-20,Y-12,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}


void draw_ship6(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z;

X=639/2;
Y=639/2;
change_color();
#if 0



								 ***********
							 l*************l
						 ***l***********l***
					 ******l*********l******
				 *********l*******l**********
			 *********** ,,,.,,, ************
		 *********** ,,,.....,,, ***********
		***********  ,....O....,  *********** <8
		**********   ,.........,   **********
		 **********  ,,,.....,,,  **********
			 **********  ,,,.,,,  **********
				 *******     ,,,     *******
					*****               *****
					 ***                 ***
						*                   *
											^19


										^15 <37

#endif

//draw dome
setcolor(3);
putpixel(X,Y-2,3);
line(X-2,Y-1,X+2,Y-1);
line(X-4,Y,X+4,Y);
line(X-4,Y+1,X+4,Y+1);
line(X-2,Y+2,X+2,Y+2);
putpixel(X,Y+3,3);

//draw dome armor
setcolor(8);
line(X-1,Y+4,X+1,Y+4);

line(X-3,Y-2,X-1,Y-2);
line(X+1,Y-2,X+3,Y-2);
line(X-3,Y+3,X-1,Y+3);
line(X+1,Y+3,X+3,Y+3);

line(X-5,Y-1,X-3,Y-1);
line(X+3,Y-1,X+5,Y-1);
line(X-5,Y+2,X-3,Y+2);
line(X+3,Y+2,X+5,Y+2);

putpixel(X-5,Y,8);
putpixel(X+5,Y,8);

putpixel(X-5,Y+1,8);
putpixel(X+5,Y+1,8);


//draw Body

setcolor(8);
line(X-5,Y-7,X+5,Y-7);
line(X-7,Y-6,X+7,Y-6);
line(X-9,Y-5,X+9,Y-5);
line(X-11,Y-4,X+11,Y-4);
line(X-13,Y-3,X+13,Y-3);

setcolor(1);
line(X-15,Y-2,X-5,Y-2);
line(X+5,Y-2,X+15,Y-2);

line(X-17,Y-1,X-7,Y-1);
line(X+7,Y-1,X+17,Y-1);

line(X-18,Y,X-8,Y);
line(X+8,Y,X+18,Y);

line(X-18,Y+1,X-9,Y+1);
line(X+9,Y+1,X+18,Y+1);

line(X-17,Y+2,X-8,Y+2);
line(X+8,Y+2,X+17,Y+2);

line(X-15,Y+3,X-6,Y+3);
line(X+6,Y+3,X+15,Y+3);

line(X-13,Y+4,X-7,Y+4);
line(X+7,Y+4,X+13,Y+4);

line(X-12,Y+5,X-8,Y+5);
line(X+8,Y+5,X+12,Y+5);

line(X-11,Y+6,X-9,Y+6);
line(X+9,Y+6,X+11,Y+6);

putpixel(X-10,Y+7,4);
putpixel(X+10,Y+7,4);

setcolor(7);
line(X-7,Y-6,X-4,Y-3);
line(X+7,Y-6,X+4,Y-3);

for(I=0;I<10;I++)//mem - 306 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-18,Y-7,X+18,Y+7);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 6";
			getch();
			exit(1);
			}
		getimage(X-18,Y-7,X+18,Y+7,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-18,Y-7,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);


}

void draw_ship7(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z,J,O;

X=639/2;
Y=479/2;
change_color();
#if 0

				***********************************************
					*******************************************
						***************************************
						 ,,,*******************************,,,
						 ,,,*******************************,,,
						 ,,,*******************************,,,
						 ,,,*******************************,,,
						 ,,, ,,,***********************,,, ,,,
						 ,,, ,,,***********************,,, ,,,
						 ,,, ,,,**********.O.**********,,, ,,, <10
						 ,,, ,,,********.......********,,, ,,,
							,	 ,,,  	  ...........   	 ,,,  ,
								 ,,,		...............    ,,,
								 ,,,	...................	 ,,,
								 ,,,	...................	 ,,,
									,			...............			,
													...;;;;;...
														..;;;..
															...
															 ^24

														 ^19 <47



#endif

//body
setcolor(8);
O=6;
line(X-23,Y-9,X+23,Y-9);
line(X-21,Y-8,X+21,Y-8);
line(X-19,Y-7,X+19,Y-7);
for(J=18;J>11;J--)
{
	line(X-J,Y-O,X+J,Y-O);
	O--;
}

//Shooters
setcolor(1);
line(X-18,Y-6,X-18,Y+1);
line(X+18,Y-6,X+18,Y+1);

line(X-17,Y-6,X-17,Y+1);
line(X+17,Y-6,X+17,Y+1);

line(X-16,Y-6,X-16,Y+1);
line(X+16,Y-6,X+16,Y+1);

line(X-14,Y-2,X-14,Y+5);
line(X+14,Y-2,X+14,Y+5);

line(X-13,Y-2,X-13,Y+5);
line(X+13,Y-2,X+13,Y+5);

line(X-12,Y-2,X-12,Y+5);
line(X+12,Y-2,X+12,Y+5);

putpixel(X-17,Y+2,3);
putpixel(X+17,Y+2,3);

putpixel(X-13,Y+6,3);
putpixel(X+13,Y+6,3);

//Ball
setcolor(7);
O=0;
for(J=1;J<=9;J+=2)
{
	line(X-J,Y+O,X+J,Y+O);
	O++;
}
for(J=9;J>=1;J-=2)
{
	line(X-J,Y+O,X+J,Y+O);
	O++;
}

setcolor(3);
line(X-2,Y+7,X+2,Y+7);
line(X-1,Y+8,X+1,Y+8);

for(I=0;I<10;I++)//mem - 462 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-23,Y-9,X+23,Y+9);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 7";
			getch();
			exit(1);
			}
		getimage(X-23,Y-9,X+23,Y+9,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-23,Y-9,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}


void draw_ship5(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z,J,O;

X=639/2;
Y=479/2;
change_color();
#if 0




						***************7      9
					 *****************8
					*******************9
				 *********************10
				***********************11
			 *************************12
			***************************13
		 *****************************
		 *****************************
		 ****** *******O******* ******
		 ******  *************  ******
		 ******   ***********   ******
		 ******    **.....**    ******
			****      **...**      ****12
			****       *****       ****
			****        ***        ****
			****                   ****
			****                   ****
			 **                     **11




#endif
//body
setcolor(8);
line(X-7,Y-9,X+7,Y-9);
line(X-8,Y-8,X+8,Y-8);
line(X-9,Y-7,X+9,Y-7);
line(X-10,Y-6,X+10,Y-6);
line(X-11,Y-5,X+11,Y-5);
line(X-12,Y-4,X+12,Y-4);
line(X-13,Y-3,X+13,Y-3);
line(X-14,Y-2,X+14,Y-2);
line(X-15,Y-1,X+15,Y-1);

for(J=15;J>=10;J--)
{
	line(X-J,Y,X-J,Y+3);
	line(X+J,Y,X+J,Y+3);
}

O=0;
for(J=7;J>=1;J--)
{
	line(X-J,Y+O,X+J,Y+O);
	O++;
}

setcolor(8);
for(J=14;J>=11;J--)
{
 line(X-J,Y+4,X-J,Y+8);
 line(X+J,Y+4,X+J,Y+8);
}

setcolor(1);
line(X-13,Y+9,X-12,Y+9);
line(X+13,Y+9,X+12,Y+9);

//cockpit
setcolor(3);
line(X-2,Y+3,X+2,Y+3);
line(X-1,Y+4,X+1,Y+4);

for(I=0;I<10;I++)//mem - 310 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-14,Y-9,X+14,Y+9);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 5";
			getch();
			exit(1);
			}

		getimage(X-14,Y-9,X+14,Y+9,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-14,Y-9,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}

void draw_ship9(apvector <Edat>& EnemyShip)
{
//local vars
int X,Y,I,Z,J,U;

X=639/2;
Y=479/2;
change_color();
#if 0


									***             ***7  10
								 ***               ***8
								***                 ***9
							 ***                   ***10
							***                     ***11
						 ***                       ***12
						***                         ***13
						***                     11^ ***
						*** *********************** ***
						***  *********************  ***
						*********......O......********* <11
						**********...........**********
						*******************************
						***      *************      ***
						***       ***********       ***
						 ***        **   **        ***
							***       **   **       ***
							 ***                   ***
								***                 ***
								 ***               ***
									***             ***
													 ^16

											<31 ^21

#endif
//cockpit
setcolor(1);
line(X-5,Y+4,X+5,Y+4);
line(X-6,Y+3,X+6,Y+3);
line(X-7,Y+2,X+7,Y+2);
line(X-8,Y+1,X+8,Y+1);
line(X-9,Y,X+9,Y);
line(X-10,Y-1,X+10,Y-1);
line(X-11,Y-2,X+11,Y-2);

setcolor(3);
line(X-6,Y,X+6,Y);
line(X-5,Y+1,X+5,Y+1);
line(X-3,Y+5,X-3,Y+6);
line(X-2,Y+5,X-2,Y+6);
line(X+3,Y+5,X+3,Y+6);
line(X+2,Y+5,X+2,Y+6);


//body
setcolor(8);
line(X-12,Y+2,X-8,Y+2);
line(X+12,Y+2,X+8,Y+2);
line(X-12,Y+1,X-9,Y+1);
line(X+12,Y+1,X+9,Y+1);
line(X-12,Y,X-10,Y);
line(X+12,Y,X+10,Y);
U=10;
for(J=7;J<=13;J++)
	{
	line(X-J,Y-U,X-(J+3),Y-U);
	line(X+J,Y-U,X+(J+3),Y-U);
	line(X-J,Y+U,X-(J+3),Y+U);
	line(X+J,Y+U,X+(J+3),Y+U);
	U--;
	}
for(J=13;J<=16;J++)
	{
	line(X-J,Y-3,X-J,Y+3);
	line(X+J,Y-3,X+J,Y+3);
	}
for(I=0;I<10;I++)//mem - 342 for each
	for(Z=0;Z<11;Z++)
	{
		EnemyShip[I].Eship[Z].Enemysize=imagesize(X-15,Y-10,X+15,Y+10);
		EnemyShip[I].Eship[Z].Enemyship=farmalloc(EnemyShip[I].Eship[Z].Enemysize);
		if(!EnemyShip[I].Eship[Z].Enemyship)
			{
			cout<<"Out of Mem"<<endl;
			cout<<"Shipdata ship: 9";
			getch();
			exit(1);
			}
		getimage(X-15,Y-10,X+15,Y+10,EnemyShip[I].Eship[Z].Enemyship);
	}
putimage(X-15,Y-10,EnemyShip[0].Eship[0].Enemyship,XOR_PUT);
}

void draw_ship10f()
{
	//local vars
	int X,Y,I,Z,U,J;

	X=639/2;
	Y=479/2;

	#if 0



										 *
										***
									 *****
									*******
								 *********
								***********
							 *************
							***************
						 *****************
						*******************
					 *---------O---------*
					***-----------------***
				 *****---------------*****
				*******-------------*******
			 *********-----------*********
			***********---------***********
		 *************-------*************
		***************-----***************
	 *****************---*****************
	*******************-*******************
 *****************************************



 #endif

	//body dark
	setcolor(15);
	U=10;
	for(J=20;J>10;J--)
	{
		line(X-J,Y+U,X+J,Y+U);
		U--;
	}
	U=0;
	for(J=10;J>=0;J--)
	{
		line(X-J,Y-U,X+J,Y-U);
		U++;
	}
	//light body
	setcolor(7);
	U=0;
	for(J=10;J>=0;J--)
	{
		line(X-J,Y+U,X+J,Y+U);
		U++;
	}
	getch();
	setcolor(4);
	U=10;
	for(J=20;J>10;J--)
	{
		line(X-J,Y+U,X+J,Y+U);
		U--;
	}
	U=0;
	for(J=10;J>=0;J--)
	{
		line(X-J,Y-U,X+J,Y-U);
		U++;
	}
	//light body
	setcolor(0);
	U=0;
	for(J=10;J>=0;J--)
	{
		line(X-J,Y+U,X+J,Y+U);
		U++;
	}
	delay(5000);
	U=0;
	while(U!=8000)
	{
		for(J=25;J>=-25;J--)
			{
			setcolor(random(14)+1);
			line(X+J,Y+25,X+J,Y-25);
			}
		U++;
	}
	setfillstyle(0,0);
	bar(X+25,Y+25,X-25,Y-25);
}

void draw_ship10r()
{
	//local vars
	int Temp,X,Y;
	X=639/2;
	Y=479/2;

#if 0

	Columns ^
					***
					***
					***              Rows >
					***
				 *****
				 *****
				 *****
				 *****
				*******
				**?O?** <      10
			 ***???***       11
 **		 **?????**    ** 12
 **		***?????***   ** 13
 ** 	**???????**   ** 14
 ** ****???????**** ** 15
 **	***?????????*** ** 16
 *********************
 *********************
 *********************
					 ^
		//	 789112345
		 //	 ^19x21>


#endif


	//Column 1 & 2, 20 & 21//guns - red
	for(Temp=Y-2;Temp >= Y-9;Temp--)
		{
		putpixel(X-10,Temp,12);
		putpixel(X-9,Temp,12);
		putpixel(X+10,Temp,12);
		putpixel(X+9,Temp,12);
		}

	//Column 3 & 19
	for(Temp=Y-7;Temp >= Y-9;Temp--)
		{
		putpixel(X-8,Temp,15);
		putpixel(X+8,Temp,15);
		}

	//Column 4 & 5, 17 & 18
	for(Temp=Y-5;Temp >= Y-9;Temp--)
		{
		putpixel(X-7,Temp,15);
		putpixel(X-6,Temp,15);
		putpixel(X+7,Temp,15);
		putpixel(X+6,Temp,15);
		}

	//Column 6 & 16
	for(Temp=Y-3;Temp >= Y-9;Temp--)
		{
		putpixel(X-5,Temp,15);
		putpixel(X+5,Temp,15);
		}


	//Column 7 & 15
	for(Temp=Y-1;Temp >= Y-9;Temp--)
		{
		putpixel(X-4,Temp,15);
		putpixel(X+4,Temp,15);
		}

	//Column 8 & 14
	for(Temp=Y+1;Temp >= Y-9;Temp--)
		{
		putpixel(X-3,Temp,15);
		putpixel(X+3,Temp,15);
		}

	//Column 9 & 13
	for(Temp=Y+5;Temp >= Y-9;Temp--)
		{
		putpixel(X-2,Temp,15);
		putpixel(X+2,Temp,15);
		}

	//Column 10,11,12
	for(Temp=Y+9;Temp >= Y-9;Temp--)
		{
		putpixel(X-1,Temp,15);
		putpixel(X,Temp,15);
		putpixel(X+1,Temp,15);
		}

	//cockpit 7-15, 10-16
	//row 16
	for(Temp=X-5;Temp <= X+5;Temp++)
		putpixel(Temp,Y-6,1);

	//row 15 & 14
	for(Temp=X-4;Temp <= X+4;Temp++)
		{
		putpixel(Temp,Y-5,1);
		putpixel(Temp,Y-4,1);
		}

	//row 13 & 12
	for(Temp=X-3;Temp <= X+3;Temp++)
		{
		putpixel(Temp,Y-3,1);
		putpixel(Temp,Y-2,1);
		}

	//row 11 & 10
	for(Temp=X-2;Temp <= X+2;Temp++)
		{
		putpixel(Temp,Y-1,1);
		putpixel(Temp,Y,1);
		putpixel(Temp,Y,1);
		putpixel(Temp,Y,1);
		putpixel(Temp,Y,1);
		}


}

void blow_up(int X,int Y)
{
//local vars
int J,I;

for(J=0;J<37;J+=3)
{
	if(J<25)
	{
		setcolor(1);
		circle(X,Y,J);
	}
	if(J>=25)
		{
		setcolor(11);
		circle(X,Y,J-30);
		}
	delay(10);
}
for(J=0;J<25;J+=3)
{
	setcolor(0);
	circle(X,Y,J);
	delay(1);
}


}

void init_space(apvector <Star>& Space)
{
	//local vars
	int I;

	for(I=0;I<100;I++)
	{
		Space[I].X=random(639)+1;
		Space[I].Y=random(479)+1;
		if(getpixel(Space[I].X,Space[I].Y)==0)
		{
			putpixel(Space[I].X,Space[I].Y,15);
			Space[I].Putstar=true;
		}
		else
			Space[I].Putstar=false;
	}


}//End

void move_space(apvector <Star>& Space)
{
	//local vars
	int I;

	for(I=0;I<100;I++)
	{
		if(Space[I].Putstar==true)
			putpixel(Space[I].X,Space[I].Y,0);
		if(Space[I].Y+1 <= 479)
		{
			Space[I].Y++;
			Space[I].Putstar=true;
		}
		else
		{
			Space[I].X=random(639)+1;
			Space[I].Y=random(1)+1;
		}
		if(getpixel(Space[I].X,Space[I].Y+1)==0)
		{
			Space[I].Y++;
			putpixel(Space[I].X,Space[I].Y,15);
		}
		else
			Space[I].Putstar=false;
	}


}


void draw_boss_shot1(Bosses & Boss)
{
	//local vars
	int X,Y;

	X=639/2;
	Y=479/2;

	#if 0
			*****
			*****
			*****
			*****
			*****
			*****
			*****
			*****
			*****
			**O**
			*****
			*****
	 ***********
	 ***********
	 ***********
			*****
			*****

	#endif

	setcolor(1);
	line(X-2,Y-8,X-2,Y+8);
	line(X-1,Y-8,X-1,Y+8);
	line(X,Y-8,X,Y+8);
	line(X+1,Y-8,X+1,Y+8);
	line(X+2,Y-8,X+2,Y+8);
	line(X-5,Y+3,X+5,Y+3);
	line(X-5,Y+4,X+5,Y+4);
	line(X-5,Y+5,X+5,Y+5);

	Boss.Bshotsize=imagesize(X-5,Y-8,X+5,Y+8);
	Boss.Bshot=farmalloc(Boss.Bshotsize);
	if(!Boss.Bshot)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(X-5,Y-8,X+5,Y+8,Boss.Bshot);
	putimage(X-5,Y-8,Boss.Bshot,XOR_PUT);


}
