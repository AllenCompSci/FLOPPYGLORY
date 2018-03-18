//Michael Crookston
//Problem GR#3
//Due Date
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<fstream.h>
#include<graphics.h>
#include<apvector.h>
#include<stdlib.h>
//Structures
struct Tree_Info
	{apstring Name;
	long Amount;};
//Constants
//Prototypes
void gr_start (int&,int&,int&);
void convert (char String[],apstring);
void treetoscreen (int);
//Global Variables
int A,B,C,I,Number,Side;
apstring Trash;
Tree_Info Info[100];
ifstream In_File;
char String[50];
//Program
void main ()
{clrscr();
randomize();
Number=0;
In_File.open("U:\\F123\\Trees.dat");
while(!In_File.eof())
	{getline(In_File,Info[Number].Name);
	In_File>>Info[Number].Amount;
	getline(In_File,Trash);
	Info[Number].Amount=(300*Info[Number].Amount)/1000;
	if(Info[Number].Name!="")
		Number++;}
In_File.close();
clrscr();
gr_start(A,B,C);
line(50,1,50,301);
line(50,301,640,301);
convert(String,"0");
outtextxy(40,300,String);
convert(String,"500");
outtextxy(25,150,String);
convert(String,"1000");
outtextxy(18,1,String);
treetoscreen (Number-1);
getch();
};
void gr_start (int&grdriver,int&grmode,int&errorcode)
	{grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{clrscr();
		cout<<"Error:"<<errorcode;
		getch();
		exit(1);}
	};
void convert (char String[],apstring Sent_In)
	{int I;
	for(I=0;I<Sent_In.length();I++)
		String[I]=Sent_In[I];
	};
void treetoscreen (int Number)
	{int I,X,Y,J,C;
	X=55;
	Y=305;
	for(I=0;I<Number+1;I++)
		{settextstyle(2,2,4);
		C=random(15)+1;
		setcolor(C);
		convert(String,Info[I].Name);
		outtextxy(X,Y,String);
		setfillstyle(random(8)+1,C);
		bar(X,300,X+15,300-Info[I].Amount);
		for(J=0;J<Info[I].Name.length();J++)
			String[J]=0;
		X+=20;}
	};