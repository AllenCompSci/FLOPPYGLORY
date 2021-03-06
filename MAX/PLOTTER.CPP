// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


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



//variables
	int grdriver;
	int grmode;
	int errorcode;
	int X;
	int Y;
	int C;
	int I;
	int J;
	int Map[25][25];
	ifstream file;
	unsigned Size;
	apvector <apstring> maplist(15);

//prototypes
	void initialize();
	void show ();
	void maketile ();
	void drawscreen();
	apvector <int> points(768);

	void far *Wall;
	void far *Space;
	void far *Door;
	void far *Key;
	void far *Max;
	void far *Monster;
	void far *Space;

void main()
{

	initialize();

//	drawscreen();

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

		//Wall

		file.open("A:\\Wall.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Wall=farmalloc(Size);

		getimage(0,0,15,15,Wall);

		file.close();

		cleardevice();


		//Empty Space

		Size=imagesize(0,0,15,15);

		Space=farmalloc(Size);

		getimage(0,0,15,15,Space);



		//Door

		file.open("A:\\Door.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Door=farmalloc(Size);

		getimage(0,0,15,15,Door);

		file.close();
		cleardevice();



		//Key

		file.open("A:\\Key.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Key=farmalloc(Size);

		getimage(0,0,15,15,Key);

		file.close();
		cleardevice();



		//Max

		file.open("A:\\Max.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Max=farmalloc(Size);

		getimage(0,0,15,15,Max);

		file.close();
		cleardevice();



		//Monster

		file.open("A:\\Monster.icf");

		maketile();

		Size=imagesize(0,0,15,15);

		Monster=farmalloc(Size);

		getimage(0,0,15,15,Monster);

		file.close();
		cleardevice();







};

void drawscreen()

{
	for(Y=0;Y<25;Y++)

	{
		for(X=0;X<25;X++)

		{

			switch(Map[X][Y]);


				case 0:   putimage((240+(X*16)), (Y*16), Space, COPY_PUT); break;

				case 1:   putimage((240+(X*16)), (Y*16), Wall, COPY_PUT); break;

				case 2:   putimage((240+(X*16)), (Y*16), Key, COPY_PUT); break;

				case 3:   putimage((240+(X*16)), (Y*16), Monster, COPY_PUT); break;

				case 4:   putimage((240+(X*16)), (Y*16), Max, COPY_PUT); break;

				case 5:   putimage((240+(X*16)), (Y*16), Door, COPY_PUT); break;

		}

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