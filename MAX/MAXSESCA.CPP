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
struct Monster
{
int X;
int Y;
};



//variables
	int grdriver;
	int grmode;
	int errorcode;
	int X;
	int Y;
	int I;
	int J;
	int Direction;

	int Level;
	int Map[26][26];


	ifstream file;
	unsigned Size;
	apvector <char far *> maplist(15);

//prototypes
	void initialize();
	void changemap();
	void drawscreen();
	void show ();
	void maketile ();
	void think ();

	apvector <int> points(768);
	apvector <Monster> Mon(50);

	void far *Wall;
	void far *Door;
	void far *Key;
	void far *Max;
	void far *Monster;


void main()
{

initialize();
changemap();


drawscreen();
getch();

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


};


void changemap()
{
ifstream Mapfile;
char far * Load;


Load = maplist[Level];

Mapfile.open(Load);

I=0;

for(Y = 0; Y < 25; Y++)
	for(X = 0; X < 25; X++)
	{
	 Mapfile>>Map[X][Y];

	 if(Map[X][Y]==5)
		{
		 Mon[I].X=X;
		 Mon[I].Y=Y;

		 I++;
		}
	}



Mapfile.close();
Level++;
};


void drawscreen()
{

int Xoffset, Yoffset;

Xoffset = Yoffset = 0;



	for(Y=0;Y<25;Y++)
	{
		for(X=0;X<25;X++)
		{

			switch(Map[X][Y])
			{

				case 0: break;
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


void maketile()
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

/*void think()
{
	for(J=0;J<I;J++)
		{
			 Direction=random(4)+1;

			 Direction==1)
					Direction=
	*/