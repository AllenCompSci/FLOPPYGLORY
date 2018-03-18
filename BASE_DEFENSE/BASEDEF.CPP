//COMMENT SECTION
//bryce boyd
//period 2
//shell
//LIBRARY SECTION
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<alloc.h>
#include"bitmap.h"
#include"math2.h"
//CONSTANT SECTION

//STRUCT SECTION
struct Ships
{
 void far *S;
 int XCoord;
 int YCoord;
 bool Flag;
 int Speed;
};

struct Lasers
{
 void far *L;
 int X;
 int Y;
 bool Flag;
 int Speed;
};

//GLOBAL VARIABLE SECTION
char Run;
int grdriver, grmode, errorcode;
int I;
apvector <long> Scores (8);
unsigned long Size;
//PROTOTYPE SECTION
void go ();
void gr_start(int&,int&,int&);
void env();
void ships(apvector <long>&);
void menu(apvector <long>&);

void main()
{
randomize();
do{
clrscr();
gr_start(grdriver,grmode,errorcode);

menu(Scores);


cout<<"Press 'y' to run the program again.";
cin>>Run;
}while (Run=='y'||Run=='Y');
}

//FUNCTION SECTION
void go()
{
cout<<"Press return to continue."<<endl;
getch();
}

void gr_start (int& grdriver, int&grmode, int& errorcode)
{
 grdriver=VGA;
 grmode=VGAHI;
 initgraph(&grdriver,&grmode,"C:\\TC\\BGI");
 errorcode=graphresult();
 if (errorcode!=grOk)
 {
 clrscr();
 cout<<"Error: "<<errorcode<<endl;
 cout<<"Press Return to continue";
 getch();
 exit(1);
 }
}

void env ()
{
image Base, Outpost;

Base.open("A:\\base.bmp");
Outpost.open("A:\\outpost.bmp");

 Base.draw(600,80);
 Outpost.draw(300,460);
 Outpost.draw(460,460);
 Outpost.draw(140,460);

}


void ships (apvector <long>& Scores)
{


 int A, B, X, X2, Y, Y2, J, Count, Z, C, Hits;
 unsigned long Size;
 int Shoot, Stop, Lspd, Sspd, Diff;
 apvector <Ships> Images  (8);
 apvector <Lasers> Shots (10);
 image Ship;
 image Laser;
 long Score, Temp, Key;
 apstring End, Begin, Select1, Select2;
 ifstream fin;
 ofstream fout;

 Select1="Select difficulty. (1-3)";
 Begin="Press a key to Start";

 settextstyle(3,0,3);
 setfillstyle(1,0);
 do{
	 bar(150,150,590,300);
	 outtextxy(150,150,Select1.c_str());
	 cin>>Diff;
	 if (Diff==3)
		{
		 Lspd=3;
		 Sspd=3;
		}
	 else if (Diff==2)
		{
		 Lspd=3;
		 Sspd=2;
		}
	 else
		{
		 Lspd=3;
		 Sspd=1;
		}
	 bar(150,150,590,300);
 }while (Diff>3||Diff<1);
 outtextxy(200,200,Begin.c_str());
 getch();
 bar(150,150,590,300);


Ship.open("A:\\ship.bmp");
setcolor(4);

for (A=0;A<8;A++)
	{
	 Images[A].XCoord=20;
	 X2=Images[A].XCoord+40;
	 Images[A].YCoord=random(340)+60;
	 Y2=Images[A].YCoord+40;
	 Ship.draw(Images[A].XCoord,Images[A].YCoord);
	 Size=imagesize(Images[A].XCoord,Images[A].YCoord,X2,Y2);
	 Images[A].S=farmalloc(Size);
	 getimage(Images[A].XCoord,Images[A].YCoord,X2,Y2,Images[A].S);
	 putimage(Images[A].XCoord,Images[A].YCoord,Images[A].S,XOR_PUT);
	 Images[A].Speed=random(Sspd)+1;
	 }

 Laser.open("A:\\laser.bmp");

 B=0;
 J=1;
 Count=0;
 Score=0;
 Hits=10;

 settextstyle(3,0,3);
 setfillstyle(1,0);
 outtextxy(216,10,itos(Score).c_str());
 outtextxy(432,10,itos(Hits).c_str());

for (Z=0;Z<10;Z++)
 Shots[Z].Flag=false;


do{//1
		Shoot=0;
		if (kbhit())
		Shoot=getch();
		 if (Shoot!=0)
			if (B<9)
				{//3
				 C=0;

				 while (Shots[C].Flag==true)
					C++;

					if (Shoot==106)
					 {//4
						Shots[C].X=160;
						Shots[C].Y=449;
						Laser.draw(Shots[C].X,Shots[C].Y);
						Size=imagesize(Shots[C].X,Shots[C].Y,162,459);
						Shots[C].L=farmalloc(Size);
						getimage(Shots[C].X,Shots[C].Y,162,459,Shots[C].L);
						putimage(Shots[C].X,Shots[C].Y,Shots[C].L,XOR_PUT);
						Shots[C].Flag=true;
						Shots[C].Speed=Lspd;
					 }//4
					if (Shoot==107)
					 {//4
						Shots[C].X=320;
						Shots[C].Y=449;
						Laser.draw(Shots[C].X,Shots[C].Y);
						Size=imagesize(Shots[C].X,Shots[C].Y,322,459);
						Shots[C].L=farmalloc(Size);
						getimage(Shots[C].X,Shots[C].Y,322,459,Shots[C].L);
						putimage(Shots[C].X,Shots[C].Y,Shots[C].L,XOR_PUT);
						Shots[C].Flag=true;
						Shots[C].Speed=Lspd;
					 }//4
					if (Shoot==108)
					 {//4
						Shots[C].X=480;
						Shots[C].Y=449;
						Laser.draw(Shots[C].X,Shots[C].Y);
						Size=imagesize(Shots[C].X,Shots[C].Y,482,459);
						Shots[C].L=farmalloc(Size);
						getimage(Shots[C].X,Shots[C].Y,482,459,Shots[C].L);
						putimage(Shots[C].X,Shots[C].Y,Shots[C].L,XOR_PUT);
						Shots[C].Flag=true;
						Shots[C].Speed=Lspd;
					 }//4
				B++;
				}//3



		if (Count>350&&J<=6)
		 {//2
			J++;
			Count=0;
		 }//2
		for(A=0;A<J;A++)
		 {//2
			if (Images[A].XCoord<=559)
				{//3
					putimage(Images[A].XCoord,Images[A].YCoord,Images[A].S,XOR_PUT);
					Images[A].XCoord=Images[A].XCoord+Images[A].Speed;
					putimage(Images[A].XCoord,Images[A].YCoord,Images[A].S,COPY_PUT);
				}//3
		 else
				{//3
					 putimage(Images[A].XCoord,Images[A].YCoord,Images[A].S,XOR_PUT);
					 Images[A].XCoord=0;
					 Images[A].YCoord=random(340)+60;
					 Hits--;
					 bar(432,10,472,50);
					 outtextxy(432,10,itos(Hits).c_str());
				}//3
		 }//2
		 for (Z=0;Z<10;Z++)
		 {//2

			 if (Shots[Z].Flag==true)
				 {//3
				if (Shots[Z].Y>20)
					 {//4
						putimage(Shots[Z].X,Shots[Z].Y,Shots[Z].L,XOR_PUT);
						Shots[Z].Y=Shots[Z].Y-Shots[Z].Speed;
						putimage(Shots[Z].X,Shots[Z].Y,Shots[Z].L,COPY_PUT);
					 }//4
				else
					{//4
						putimage(Shots[Z].X,Shots[Z].Y,Shots[Z].L,XOR_PUT);
						Shots[Z].Flag=false;
						Shots[Z].Y=449;
						B--;
					}//4
				for (A=0;A<8;A++)
				 {
					if (Shots[Z].X>Images[A].XCoord&&Shots[Z].X<Images[A].XCoord+40)
					 {
					 if (Shots[Z].Y>Images[A].YCoord&&Shots[Z].Y<Images[A].YCoord+40)
						{
						 putimage(Shots[Z].X,Shots[Z].Y,Shots[Z].L,XOR_PUT);
						 Shots[Z].Flag=false;
						 B--;
						 putimage(Images[A].XCoord,Images[A].YCoord,Images[A].S,XOR_PUT);
						 Images[A].XCoord=0;
						 Images[A].YCoord=random(340)+60;
						 Score+=10;
						 bar(216,10,256,50);
						 outtextxy(216,10,itos(Score).c_str());
						}
					 }
				 }
			}//3
		 }//2

		 if (J<3)
		 delay(8);
		if (J<6)
		 delay(4);



	 Count++;
	}while(Shoot!='q'&&Hits>0);

 End="GAME OVER";

 outtextxy(300,200,End.c_str());
 outtextxy(300,250,itos(Score).c_str());

 fin.open("SCORES.DAT");
	for (I=0;I<8;I++)
		fin>>Scores[I];
 fin.close();

I=0;

Stop=8;

for (I=0;I<8;I++)
 if (Score>Scores[I])
	{
	 Stop=I;
	 I=8;
	}
for (I=7;I>Stop;I--)
	Scores[I]=Scores[I-1];
if (Stop!=8)
 Scores[Stop]=Score;


 fout.open("SCORES.DAT");
 for (I=0;I<8;I++)
	fout<<Scores[I]<<endl;
 fout.close();
 }


void menu (apvector <long>& Scores)
{
 apstring Play, Inst, High, Quit, Title, Prob;
 int Choice, Y;
 ifstream fin;

 do{
 setfillstyle(1,0);
 settextstyle(3,0,3);
 Title="BASE DEFENSE";
 Play="1.Play";
 Inst="2.Instructions";
 High="3.High Scores";
 Prob="4.Problems";
 Quit="5.Quit";
 outtextxy(200,175,Title.c_str());
 outtextxy(200,200,Play.c_str());
 outtextxy(200,225,Inst.c_str());
 outtextxy(200,250,High.c_str());
 outtextxy(200,275,Prob.c_str());
 outtextxy(200,300,Quit.c_str());
 cin>>Choice;

 switch (Choice)
 {
	case 0:
	case 1: bar(200,175,400,400);
					env();
					ships(Scores);
					getch();
					settextstyle(3,0,3);
					cleardevice();
					break;

	case 2: bar(200,175,400,400);
					settextstyle(3,0,2);
					outtextxy(40,40, "BASE DEFENSE");
					outtextxy(40,60, "You and your men have been deployed to 3");
					outtextxy(40,80, "outposts near your headquarters. It is up");
					outtextxy(40,100,"to you to defend your leaders.");
					outtextxy(40,140,"Press 'j' to fire from the far left outpost,");
					outtextxy(40,160,"'k' to fire from the middle outpost, and 'l'");
					outtextxy(40,180,"to fire from the right outpost. The headquarters");
					outtextxy(40,200,"can only take 10 hits from the attackers. You");
					outtextxy(40,220,"must do your duty...");
					getch();
					bar(0,0,540,440);
					break;

	case 3: bar(200,175,400,400);
					settextstyle(3,0,2);
					fin.open("SCORES.DAT");
					for (I=0;I<8;I++)
					 fin>>Scores[I];
					outtextxy(40,40,"HIGH SCORES");
					Y=60;
					for (I=0;I<8;I++)
					{
					 Y+=20;
					 outtextxy(40,Y,itos(Scores[I]).c_str());
					}
					fin.close();
					getch();
					bar(0,0,540,440);
					break;

	case 4: bar(200,175,400,400);
					settextstyle(3,0,2);
					outtextxy(40,40,"PROBLEMS");
					outtextxy(40,60,"About once every ten plays the game will load and");
					outtextxy(40,80,"you will not be able to fire.  This is fixed by");
					outtextxy(40,100,"simply returning to the main menu and starting");
					outtextxy(40,120,"the game again.");
					outtextxy(40,160,"Any others errors should be handled by completely");
					outtextxy(40,180,"exiting the program and restarting it.");
					getch();
					bar(0,0,590,400);
					break;

 }
 }while (Choice!=5);

}

