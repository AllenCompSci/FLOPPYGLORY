//Aaron Williams
//HELICOPTER
//period6

//library section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<graphics.h>
#include<stdio.h>
#include<alloc.h>
#include<dos.h>
#include"bitmap.h"
#include"math2.h"
//constant section
const OTW=100;

//struct sectioin




//variable section
char Ans;
int Grdriver, Grmode, Errorcode;//for graphics mode..duh-_-
image Helo;//helocopter image
image Airplane;//airplane imag
image Balloon;//balloon image
image Start;//shows image at menu screen
image Dead;//shows image when you lose
int P2;//Used to keep track of a for loop
int J2;//Used to keep track of a for loop
int Temp1;//Helps sort the high scores
int Sure;//Helps keep track of high scores
int I;//Keeps track of the main for loops.
int Choice;//Keeps track of what vehicle the user chooses
int Space; //Sets a number to show where the colon needs to go to show high scores.
int Sure1;//Keeps track with high scores
bool Exit;//Exits the game and takes you back to the menu.
int T,Z,Y;//Keeps track of for loops.
ifstream Score1;//Opens the high score document.
apvector<int>Score(10);//Holds the top scores.


//Proto section
void gr_start(int&, int&, int&);//graphics
void scene(apvector<int>&,int&,int&);//runs almost the whole program
void colors();//was to check the new pallate(i dno how to spell that)


void main()
{
randomize();
clrscr();
gr_start(Grdriver, Grmode, Errorcode);

Dead.open("A:\\Dead.bmp");
Balloon.open("A:\\Balloon.bmp");
Helo.open("A:\\Helo.bmp");
Airplane.open("A:\\Airplane.bmp");
Start.open("A:\\Start.bmp");
Choice=0;
Sure1=0;
Z=0;
Y=0;
cleardevice();
do{

if(Z<1)
{
Start.draw(0,0);
}
Z++;

Exit=false;
setcolor(GREEN);
settextjustify(1,1);
settextstyle(0,0,5);
outtextxy(300,30,"Helicopter");
setcolor(9);
settextstyle(2,0,6);
outtextxy(300,80,"By: Aaron and Marshall, the most ace programers ever");
setcolor(WHITE);
settextstyle(0,0,1);
outtextxy(getmaxx()/4-20,getmaxy()/6+30,"Please pick your aircraft");
outtextxy(getmaxx()/4-70,getmaxy()/6+70,"1:Balloon");
Balloon.draw(150,130);
outtextxy(getmaxx()/4-56,getmaxy()/6+150,"2:Helicopter");
Helo.draw(150,220);
outtextxy(getmaxx()/4-60,getmaxy()/6+230,"3:Airplane");
Airplane.draw(150,290);
outtextxy(getmaxx()/4-50,getmaxy()/6+280,"4.How to Play");
outtextxy(getmaxx()/4-50,getmaxy()/6+320,"5.High Scores");
outtextxy(getmaxx()/4-80,getmaxy()/6+360,"6.Exit");





if(kbhit())
switch(getch())
{
case 49:
Choice=1;
scene(Score,Sure1,Sure);

break;

case 50:

Choice=2;
scene(Score,Sure1,Sure);

				break;

case 51:

Choice=3;
scene(Score,Sure1,Sure);

break;

case 52:

cleardevice();
settextstyle(1,0,7);
outtextxy(getmaxx()/2,40,"Help");
setcolor(5);
settextstyle(0,0,1);
outtextxy(300,140,"Use the up down key to control your aircraft. ");
outtextxy(300,150,"When the arrow key is released the aircraft will fall");
outtextxy(300,160,"Negotiate the obsticals in cave and try to get the high score!");
outtextxy(300,250,"Press enter to continue back to the menu screen");
getch();
cleardevice();
break;

case 53:

Space=305;
cleardevice();


setcolor(2);
settextstyle(1,0,7);
outtextxy(getmaxx()/2-30,100,"High Scores:");
setcolor(5);
settextstyle(0,0,1);


Score1.open("A:\\HIGHSCOR.dat");
for(I=0;I<10;I++)
{
	Score1>>Score[I];
	if(Score[I]<=0)
	{
	 Score[I]=1;
	}
}



	for(P2=0; P2<10; P2++)
			{
				for(J2=P2; J2<10; J2++)
					{
						 if(Score[P2]<Score[J2])
						 {
						 Temp1=Score[P2];
						 Score[P2]=Score[J2];
						 Score[J2]=Temp1;
						 }
					}
			}


for(I=0;I<10;I++)
{


outtextxy(235,Space,itos(I+1).c_str());
outtextxy(245,Space,":");
outtextxy(280,Space,itos(Score[I]).c_str());
Space+=10;
}
Score1.close();


getch();
cleardevice();
				break;
case 54:

Exit=true;


};

}while(!Exit);


}
//cout<<"Do you want to run the program again?"<<endl;
//cin>>Ans;
	//	}while(Ans=='Y'||Ans=='y');

//}


void gr_start(int&Grdriver, int &Grmode, int&Errorcode)
{
Grdriver=VGA;
Grmode=VGAHI;

initgraph(&Grdriver,&Grmode,"C:\\TC\\BGI");

Errorcode=graphresult();

if(Errorcode!=grOk)
{
 clrscr();
	cout<<"Error:   "<<Errorcode<<endl;
	 cout<<"Press Return to continue."<<endl;
 getch();
		exit(1);
}
};


void scene(apvector<int> &Score, int&Sure1,int&Sure)
{
int I;//I is use for for loops
int E,E1,C,C1;//Points of the moving rectangles
int J;//Used with for loop
int Big;//Tracks the biggest point in the apvectors
int Size, Time, Move;//Moves and keeps track of the apvectors
int Temp;//Temp variable used to store temp data
int Key;//Used to keep track of things;
int Cheat;//Attempted cheat code..
long Track;//When track mod 5, Sure++
bool Exit,Flag;//Exits program, helps with high scores.
bool Check,Bmove;//Checks to see when things move.
apvector<int>Points(640);//Points for the floor
apvector<int>Points2(640);//Points for the ceiling
ofstream High;//Sends out scores

High.open("A:\\HIGHSCOR.dat");
Sure=0;
Track=0;

Big=0;
C=random(150)+150;
C1=random(150)+150;

setcolor(4);
setfillstyle(1,4);
bar(100,100,150,200);

Exit=false;
Bmove=false;

Size=getmaxx();
setcolor(4);

cleardevice();
setfillstyle(1,4);

Points[0]=430-random(30);
Points2[0]=100+random(50);


 for(I=1; I<getmaxx(); I++)
	{
	 Points[I]=Points[I-1]+(random(3)-1);
	 Points2[I]=Points2[I-1]+(random(3)-1);
		if(Points[I]>Big)
		 Big=Points[I];
	 line(I-1,Points[I-1],I-1,getmaxy());
	 line(I-1,0,I-1,Points2[I-1]);
	}
E=getmaxx();
E1=getmaxx();
Time=0;
Move=0;
I=1;
Y=300;
Key=77;

do{




		if(!kbhit())
			Key=56;

	if(kbhit())

		Key=getch();
	 switch(Key)
	 {
		 case 27:Exit=true;
							 break;

		case 54:cleardevice();
		 outtextxy(getmaxx()/2,getmaxy()/2,"YAY YOU WON -_-");
			 getch();
				 break;


		 case 56:
			Y+=2;
		 case 32:
		 if(Choice==1)
			Balloon.draw(OTW,Y);
		 else if(Choice==2)
			Helo.draw(OTW,Y);
		 else if(Choice==3)
			Airplane.draw(OTW,Y);
		 Move=1;


		 if(kbhit()==57)
				{
				 Cheat=2;
				}
		 else
				 Cheat=5;

			if(Key==32)
			 {
				Y=Y-4;
					if(Choice==1)
					 {
						setcolor(0);
						setfillstyle(1,0);
						bar(OTW,Y+47,OTW+53,Y+50);
					 }
			 //	delay();
			 }

 if(Choice==1)
 {
	if(getpixel(OTW+52,Y)==4||getpixel(OTW+52,Y+23)==4||getpixel(OTW+52,Y+46)==4||getpixel(OTW+26,Y+46)==4||getpixel(OTW+26,Y)==4||getpixel(OTW,Y+46)==4||getpixel(OTW,Y)==46)
	{     cleardevice();
				Dead.draw(0,0);
				getch();
				cleardevice();
				Exit=true;
				cleardevice();
	}
 }

	if(Choice==2)
 {
	if(getpixel(OTW+84,Y)==4||getpixel(OTW+84,Y+16)==4||getpixel(OTW+84,Y+32)==4||getpixel(OTW+42,Y+32)==4||getpixel(OTW+42,Y)==4||getpixel(OTW,Y)==4||getpixel(OTW,Y+32)==4)
	{     cleardevice();
				Dead.draw(0,0);
				getch();
				cleardevice();
				Exit=true;
				cleardevice();
	}
 }
	if(Choice==3)
 {
	if(getpixel(OTW+73,Y)==4||getpixel(OTW+73,Y+23)==4||getpixel(OTW+73,Y+45)==4||getpixel(OTW,Y+45)==4||getpixel(OTW+36,Y)==4||getpixel(OTW+36,Y+45)==4||getpixel(OTW,Y)==4)
	{     cleardevice();
				Dead.draw(0,0);
				getch();
				cleardevice();
				Exit=true;
				cleardevice();
	}
 }
	 }



	if(Move>0)
	 {

		if(I<Size)
		 {
		 setcolor(0);
		 line(I,0,I,Points2[I-1]);
		 line(I,Points[I-1],I,getmaxy());
		 delay(Time);
		 setcolor(4);
		 Points[I-1]=Points[I];
		 Points2[I-1]=Points2[I];
		 line(I,Points[I],I,getmaxy());
		 line(I,0,I,Points2[I]);
		 I++;

		 if(Points[Size-1]<350)
			Points[Size-1]++;
		 else if(Points[Size-1]>450)
			Points[Size-1]--;
		 else if(I%100==0)
				Points[Size-1]+=(random(3)-1);

		 if(Points2[Size-1]<50)
			Points2[Size-1]++;
			else if(Points2[Size-1]>250)
			 Points2[Size-1]--;
				else if(I%100==0)
				 Points2[Size-1]+=(random(3)-1);



		 if(Size-I>0)
			{
			if((Size-I)%1==0)
				{
				 setfillstyle(1,0);
				 bar(E,C,E+40,C+90);
				 E-=4;
				 setfillstyle(1,4);
				 bar(E,C,E+40,C+90);
				 //
					if(C>Points[I])
					 {
					 C-=40;
					 }
				 //
					 if(E<350||Bmove==true)
					 {
						 if(E1>20)
						 {
						 Bmove=true;
						 setfillstyle(1,0);
						 bar(E1,C1,E1+40,C1+90);
						 E1-=4;
						 setfillstyle(1,4);
						 bar(E1,C1,E1+40,C1+90);


				 //
					if(C1>Points[I])
					 {
					 C1-=40;
					 }
				 //
						 }
							else
							 {
								 setfillstyle(1,0);
								 bar(E1,C1,E1+40,C1+90);
								 E1=Size-20;
								 setfillstyle(1,4);
								 Bmove=false;
								if(Points[I]>Big)
								 C1=random(50)+Big;
								else
								 C1=random(175)+150;
				 //
					if(C1>Points[I])
					 {
					 C1-=40;
					 }
				 //
							 }
					}
				}
			}
		 else if(E<20)
			 {
			 setfillstyle(1,0);
			 bar(E,C,E+40,C+90);
			 E=Size-20;
			 setfillstyle(1,4);
				if(Points[I]>Big)
					C=random(50)+Big;
				else
					C=random(175)+150;

					//
					if(C>Points[I])
					 {
					 C-=40;
					 }
				 //
			 }
			}
		 else
		 I=1;


Track++;



if(Track%Cheat==0)
{
Sure++;
setcolor(2);
setfillstyle(1,0);
bar(0,0,80,20);
setfillstyle(1,0);
bar(540,0,getmaxx(),20);
setcolor(5);
outtextxy(25,10,"Score:");
outtextxy(560,10,"High:");
outtextxy(60,10,itos(Sure).c_str());
outtextxy(595,10,itos(Score[0]).c_str());


}




		 }
	}while(!Exit);




Flag=true;
for(I=0; I<10; I++)
{
if(Score[I]<Sure&&Flag)
 {
		for(J=9;J>I;J--)
			Score[J]=Score[J-1];
		Score[I]=Sure;
		Flag=false;
		cleardevice();
 }
High<<Score[I]<<endl;
cleardevice();
}

Sure1++;
High.close();
cleardevice();

};

void colors()
{
int I,X,X1,Y,Y1;
X=15;
X1=300;
Y=400;
Y1=300;

for(I=0; I<15; I++)
{

setcolor(I);
line(X,X1,Y,Y1);
Y1=Y+10;
X1=X1+10;
delay(10);
}


};




