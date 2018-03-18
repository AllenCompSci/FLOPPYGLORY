
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
#include "lv.hpp"

//Constant Section

//Struct Section

//Global Variable Section
static int I,J,K;
static apstring NewName;
static HSA HSATemp;
static ifstream in_file;
static ofstream out_file;
static apvector <HSA> HSArrange (51);

//Prototype Section

void newscore(long NewScore)
{
cleardevice();
NewScore/=1000;
in_file.open("HS.DAT");
I=0;
while (!in_file.eof())
	{
	in_file>>HSArrange[I].Name>>HSArrange[I].Score;
	I++;
	};
in_file.close();

if (NewScore<HSArrange[49].Score)
	{
	outtextxy(0,0,"Congratulations!  You have entered a high score.");
	outtextxy(0,20,"Please enter your name below.");
	NewName[0]=getch();
	NewName[1]=getch();
	NewName[2]=getch();
	HSArrange[49].Name=NewName;
	HSArrange[49].Score=NewScore;
	for (J=0;J<50;J++)
		for (K=J+1;K<50;K++)
			if (HSArrange[J].Score>HSArrange[K].Score)
				{
				HSATemp=HSArrange[K];
				HSArrange[K]=HSArrange[J];
				HSArrange[J]=HSATemp;
				}
	}
out_file.open("HS.DAT");
for (I=0;I<50;I++)
	{
	out_file<<HSArrange[I].Name<<endl<<HSArrange[I].Score;
	if (I!=49)
		out_file<<endl;
	}
out_file.close();
}

/******************************** FUNCTIONS *********************************/
