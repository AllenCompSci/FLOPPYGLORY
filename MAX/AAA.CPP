// Andrew Closson, Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Max's Escape


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<alloc.h>
//constants



//structure

struct monster      //struct for monster info
{

int X, Y;           //monster coordinates
int State;          //monster movement type
int Timer;          //speed of movement

};



//variables
	int grdriver;     //graphics function
	int grmode;       //graphics function
	int errorcode;    //graphics function
	int X;            //matrix "X" axis
	int Y;            //matrix "Y" axis
	int I;            //LCV used to display graphics
	int J;            //another LCV used to display graphics
	int Debug;
	int Havekey;      //shows if Max has the key
	int Choice;       //option on main menu

	int Playerx, Playery;   //Max's coordinates

	int Level;              //used to load level
	int Exit;               //used to exit when needed
	int Map[30][30];        //matrix used for maps

	apvector <monster> Badie(30);  //stores info on all monsters

	ifstream file;                 //used for files (maps and images)
	unsigned Size;                      //used for size of tiles
	apvector <char far *> maplist(15);  //used for loading maps
	apvector <int> points(768);         //used to plot all of the point for images


//prototypes
	void initialize();
	void changemap();
	void drawscreen();
	void updatescreen();
	void movement();
	void think();
	void show ();
	void maketile ();
	void title ();
	void lose();
	void win();


	//Tiles

	void far *Wall;
	void far *Door;
	void far *Key;
	void far *Max;
	void far *Monster;
	void far *Space;


void main()
{

Debug = 1;


initialize();
title();
cleardevice();
changemap();

do{

updatescreen();
movement();
think();

}while(!Exit);



closegraph();
}




void initialize()
{

int Loop;


	show();

		setbkcolor(0);
		setcolor(15);

		//Load maplist file

		file.open("maplist.lst");

		for(Loop = 0; Loop < 15; Loop++)
		{
		file>>maplist[Loop];
		}
		file.close();


		//Load Tiles and store to memory

		file.open("A:\\Wall.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Wall=farmalloc(Size);

		getimage(0,0,15,15,Wall);

		file.close();
		cleardevice();




		file.open("A:\\Key.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Key=farmalloc(Size);

		getimage(0,0,15,15,Key);

		file.close();
		cleardevice();



		file.open("A:\\Max.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Max=farmalloc(Size);

		getimage(0,0,15,15,Max);

		file.close();
		cleardevice();




		file.open("A:\\Monster.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Monster=farmalloc(Size);

		getimage(0,0,15,15,Monster);

		file.close();
		cleardevice();



		file.open("A:\\Door.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Door=farmalloc(Size);

		getimage(0,0,15,15,Door);

		file.close();
		cleardevice();




		Size=imagesize(0,0,15,15);

		Space=farmalloc(Size);

		getimage(0,0,15,15,Space);

		cleardevice();
};


void changemap()                  //Called at the end of every level
{
ifstream Mapfile;
//char far * Load;

int Monsternum = 0;



//Load = maplist[Level];

switch(Level)
	{
	case 0: Mapfile.open("a:\\map1.map"); break;
	case 1: Mapfile.open("a:\\map2.map"); break;
	case 2: Mapfile.open("a:\\map3.map"); break;
	case 3: Mapfile.open("a:\\map4.map"); break;
	case 4: Mapfile.open("a:\\map5.map"); break;
	case 5: Mapfile.open("a:\\map6.map"); break;
	case 6: Mapfile.open("a:\\map7.map"); break;
	case 7: Mapfile.open("a:\\map8.map"); break;
	case 8: Mapfile.open("a:\\map9.map"); break;
	case 9: Mapfile.open("a:\\map10.map"); break;
	case 10: win(); break;
	}




for(Y = 0; Y < 25; Y++)
	for(X = 0; X < 25; X++)
		{
		Mapfile>>Map[X][Y];

		if(Map[X][Y] == 5)            //Spawn Monster
			{
			Badie[Monsternum].X = X;
			Badie[Monsternum].Y = Y;
			Badie[Monsternum].State = 1;
			Monsternum++;
			}

		if(Map[X][Y] == 4)            //Find Player Start
			{
			Playerx = X;
			Playery = Y;

		//		if(Debug)
		//			cout << "Found Player Start." << endl;
			}
		}

Mapfile.close();
Level++;

//if(Debug)
//	cout << "End changemap()" << endl;


drawscreen();

};


void drawscreen()                 //Draws all the tiles
{

int Xoffset, Yoffset;

Xoffset = Yoffset = 0;



	for(Y=0;Y<25;Y++)
	{
		for(X=0;X<25;X++)
		{

			switch(Map[X][Y])
			{

				case 0: putimage(Xoffset, Yoffset, Space, COPY_PUT); break;
				case 1: putimage(Xoffset, Yoffset, Wall, COPY_PUT); break;
				case 2: putimage(Xoffset, Yoffset, Door, COPY_PUT); break;
				case 3: putimage(Xoffset, Yoffset, Key, COPY_PUT); break;
				case 4: putimage(Xoffset, Yoffset, Max, COPY_PUT); break;
				case 5: putimage(Xoffset, Yoffset, Monster, COPY_PUT); break;
			}
		Xoffset+=17;
		}
	Yoffset+=17;
	Xoffset = 0;
	}

};


void updatescreen()
{

int Xoffset, Yoffset;

Xoffset = Yoffset = 0;



	for(Y=0;Y<25;Y++)
	{
		for(X=0;X<25;X++)
		{

			switch(Map[X][Y])
			{

				case 0: putimage(Xoffset, Yoffset, Space, COPY_PUT); break;
				case 1: break;
				case 2: break;
				case 3: break;
				case 4: putimage(Xoffset, Yoffset, Max, COPY_PUT); break;
				case 5: putimage(Xoffset, Yoffset, Monster, COPY_PUT); break;
			}
		Xoffset+=17;
		}
	Yoffset+=17;
	Xoffset = 0;
	}


}


void movement()                    //Checks for input and moves player
{
int Keyhit;
int Tile;

int Oldpx, Oldpy;

Oldpx = Playerx;
Oldpy = Playery;

Map[Playerx][Playery] = 0;


if(kbhit())
	Keyhit = getch();
else
	Keyhit = 0;


switch(Keyhit)
	{
	case 72: Playery--; break;

	case 80: Playery++; break;

	case 75: Playerx--; break;

	case 77: Playerx++; break;

	case 27: Exit = 1; break;
	}


Tile = Map[Playerx][Playery];


switch(Tile)                                          //Collision Detection
	{
	case 0: Map[Playerx][Playery] = 4; break;
	case 1: Playerx = Oldpx; Playery = Oldpy; break;
	case 2: if(Havekey == 1)
						Map[Playerx][Playery] = 4;
					else
						{
						Playerx = Oldpx;
						Playery = Oldpy;
						}
						break;
	case 3: Map[Playerx][Playery] = 4; Havekey = 1; break;
	case 4: break;
	case 5: Map[Playerx][Playery] = 5; lose(); break;
	case 6: changemap(); break;
	}
};



void think()
{
int Loop;
int Dir;
int Moved;

randomize();

for(Loop = 0; Loop < 30; Loop++)
	{

	if(Badie[Loop].State != 0)
		Map[Badie[Loop].X][Badie[Loop].Y] = 0;


	if(Badie[Loop].Timer < 3)
		{
			if(Badie[Loop].State == 1)               //Random Movement
				{

					Dir = random(4);



					if(Dir == 1)
						if(Map[Badie[Loop].X + 1][Badie[Loop].Y] == 0)
							{
							Badie[Loop].X++;
							//Moved = 1;
							}
					if(Dir == 2)
						if(Map[Badie[Loop].X - 1][Badie[Loop].Y] == 0)
							{
							Badie[Loop].X--;
							//Moved = 1;
							}
					if(Dir == 3)
						if(Map[Badie[Loop].X][Badie[Loop].Y + 1] == 0)
							{
							Badie[Loop].Y++;
							//Moved = 1;
							}
					if(Dir == 4)
						if(Map[Badie[Loop].X][Badie[Loop].Y - 1] == 0)
							{
							Badie[Loop].Y--;
							//Moved = 1;
							}

				//if(Map[Badie[Loop].X][Badie[Loop].Y] == 4);
					//lose();
				}

		}
	Map[Badie[Loop].X][Badie[Loop].Y] = 5;

	if(Badie[Loop].Timer < 5)
		Badie[Loop].Timer++;
	else
		Badie[Loop].Timer=0;
	}
};


void show()

{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver, &grmode, "c:\\TC\\BGI");
	errorcode=graphresult();

	if(errorcode!=grOk)
	{clrscr();
	cout<<"Error";
	getch();
	exit(1);
}

};


void maketile()                       //Deal with graphic file
{
for(I=0;I<768;I++)
		{
			file>>points[I];
		}

	I=0;

	for(J=0;J<256;J++)
		{
			putpixel(points[I],points[I+1],points[I+2]);
			I=I+3;
		}
}


void title()
{
int Choice;
int midx;

cleardevice();


 midx = getmaxx() / 2;

settextstyle(3, HORIZ_DIR, 1);
setcolor(3);
outtextxy(midx-185, 120, "By: Andrew Closson and Mahmood Subhani");
settextstyle(2, HORIZ_DIR, 4);
setcolor(4);
outtextxy(midx-60, 150, "Please type a number:");
outtextxy(midx-40, 200, "1) Play");
outtextxy(midx-40, 220, "2) Instructions");
outtextxy(midx-40, 240, "3) Quit");

I=1;
do{
setcolor(I);
settextstyle(4, HORIZ_DIR, 6);
outtextxy(midx-75, 3, "Max's");
outtextxy(midx-85, 50, "Escape");

setcolor(0);
outtextxy(midx-75, 3, "Max's");
outtextxy(midx-85, 50, "Escape");
I++;
}while(!kbhit());



Choice=getch();

switch (Choice)
{

	case 49: break;


	case 50: cleardevice();
					 setcolor(4);
					 settextstyle(1, HORIZ_DIR, 1);
					 outtextxy(midx-180, 3, "Use the arrow keys to move Max.");
					 outtextxy(midx-310, 50, "Press Esc during game play when you want to return to the menu");
					 getch();
					 cleardevice();
					 title();            //Note: Recursive function call
					 break;



	case 51: Exit=1; break;

}

};


void lose()
{
int Choice;
int I;



cleardevice();
setcolor(3);
settextstyle(1, HORIZ_DIR, 1);
outtextxy(5, 3, "The monster drags your corpse off to a dark corner...");
outtextxy(5, 100, "Sorry, you lost.  Please play again.");
delay(140);
getch();
cleardevice();


Exit = 1;

};

void win()
{
int Choice;



cleardevice();
setcolor(4);
settextstyle(4, HORIZ_DIR, 3);
outtextxy(5, 3, "Congratulations,");
outtextxy(5, 100, "Max got out of the dungeon and flew back to Earth");
getch();

setcolor(1);
settextstyle(1, HORIZ_DIR, 1);
outtextxy(5, 300, "Please play again");
getch();

Exit = 1;

};