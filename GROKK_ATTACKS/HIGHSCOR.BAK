//Library Section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <apstring.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include "lv.hpp"

//Constant Section

//Struct Section

//#define LV_test

//Global Variable Section
static bool HSClear;
static char HSPos;
static int N,M,HSOption;
static apstring HSTitle,HSPointer;
static ifstream in_file;
static ofstream out_file;
static char HSTemp[7];
static apvector <apstring> HSMenu (2);
static apvector <HS> HighScores (51);

//Prototype Section
static void input_data(apvector <HS>&);
static void clear_hs(apvector<HS>&);

void highscore()
{
randomize();
do
	{
	cleardevice();
	for (N=0;N<getmaxx();N++)
		for (M=0;M<getmaxy();M++)
			if (random(1000)<=1&&getpixel(N,M)==0)
				putpixel(N,M,15);
	HSTitle="High Scores";
	HSMenu[0]="   Main Menu";
	HSMenu[1]="   Reset Scores";
	HSPointer="¯";
	input_data(HighScores);
	setcolor(4);
	settextstyle(1,0,1);
	for (N=0;N<25;N++)
		{
		outtextxy(145,(16*N)+50,ltoa(N+1,HSTemp,10));
		outtextxy(180,(16*N)+50,HighScores[N].Name.c_str());
		outtextxy(245,(16*N)+50,ltoa(HighScores[N].Score,HSTemp,10));
		}
	for (N=25;N<50;N++)
		{
		outtextxy(355,(16*(N-25))+50,ltoa(N+1,HSTemp,10));
		outtextxy(390,(16*(N-25))+50,HighScores[N].Name.c_str());
		outtextxy(455,(16*(N-25))+50,ltoa(HighScores[N].Score,HSTemp,10));
		}
	settextstyle(1,0,2);
	outtextxy(100,455,HSMenu[0].c_str());
	outtextxy(100,455,HSPointer.c_str());
	outtextxy(350,455,HSMenu[1].c_str());
	setcolor(8);
	outtextxy(350,455,HSPointer.c_str());
	HSOption=0;
	HSPos='1';
	while (HSPos!=char(13))
		{
		while (!kbhit())
			{
			settextstyle(1,0,4);
			setcolor(random(14)+1);
			outtextxy(220,5,HSTitle.c_str());
			}
		settextstyle(1,0,2);
		HSPos=getch();
		if (HSPos==char(77)) //right
			if (HSOption==0)
				{
				HSOption++;
				setcolor(8);
				outtextxy(100,455,HSPointer.c_str());
				setcolor(4);
				outtextxy(350,455,HSPointer.c_str());
				}
		if (HSPos==char(75)) //left
			if (HSOption==1)
				{
				HSOption--;
				setcolor(8);
				outtextxy(350,455,HSPointer.c_str());
				setcolor(4);
				outtextxy(100,455,HSPointer.c_str());
				}
		}
	if (HSOption==1)
		{
		clear_hs(HighScores);
		HSClear=true;
		}
	else
		HSClear=false;
	}
while(HSClear);
}

/******************************** FUNCTIONS *********************************/


void input_data (apvector <HS>&HighScores)
{
//Local Variable Section
int I;

in_file.open("HS.DAT");
I=0;
while (!in_file.eof())
	{
	in_file>>HighScores[I].Name>>HighScores[I].Score;
	I++;
	};
in_file.close();
};

void clear_hs (apvector <HS>&HighScores)
{
//Local Variable Section
int I;

out_file.open("HS.DAT");
for (I=0;I<50;I++)
	{
	HighScores[I].Name="---";
	HighScores[I].Score=0;
	out_file<<HighScores[I].Name<<endl<<HighScores[I].Score;
	if (I!=49)
		out_file<<endl;
	}
out_file.close();
};