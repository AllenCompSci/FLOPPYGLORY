	#include <graphics.h>
	#include <stdlib.h>
	#include <apvector.h>
	#include <bool.h>
	#include <dos.h>

int grdriver;
int grmode;
int errorcode;


void gr_start(int &, int &, int &);
void bsod();


void gr_start(int &grdriver, int &grmode, int &errorcode)
{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode !=grOk)
	{
		clrscr();
		cout<<"Error: "<<errorcode<<endl;
		cout<<"Press return to continue";
		getch();
		exit(1);
	}
};
//****************************************************************
void bsod()
{
	bool Dead;
	apstring Random,RandomSm;
	char New;
	int X;
	gr_start(grdriver,grmode,errorcode);

	Dead=true;
	while(Dead)
	{

		Random="";
		RandomSm="0";
		RandomSm=RandomSm+char(random(6)+65);


		for(X=0;X<4;X++)
		{
			New=random(16);
			if(New<10)
				New+=48;
			else
				New+=55;
			Random=Random+char(New);
		}
		Random=Random+':';
		for(X=0;X<8;X++)
		{
			New=random(16);
			if(New<10)
				New+=48;
			else
				New+=55;
			Random=Random+char(New);
		}
		setfillstyle(1,1);
		bar(0,0,639,479);
		setcolor(15);

		settextstyle(0,0,1);
		outtextxy(40,200,"A fatal exception ");
		outtextxy(180,200,RandomSm.c_str());
		outtextxy(193,200," has occurred at ");
		outtextxy(325,200,Random.c_str());
		outtextxy(425,200,". The current");
		outtextxy(40,215,"application will be terminated.");

		outtextxy(48,240,"* Press any key to restart the current application.");
		outtextxy(48,255,"* Press CTRL + ALT + DEL again to restart your computer. You will");
		outtextxy(48,270,"lose any unsaved information in all applications.");
		outtextxy(200,295,"Press any key to continue.");

		setcolor(1);
		setfillstyle(1,7);
		bar(253,170,330,185);
		outtextxy(265,175,"Windows");

		getch();
		setcolor(0);
		cleardevice();
		delay(15);

		Dead=true;
	}
	exit(1);
};
//********************************************************************