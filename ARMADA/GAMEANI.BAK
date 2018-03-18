//Kathy Harrod
//6th
//Mr. Baker
//Program:
#include<iostream.h>
#include<conio.h>
#include<apstring.h>
#include<iomanip.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<dos.h>
//Constant
//Variable
int Grdriver;
int Grmode;
int Errorcode;
int I;
int Splash1;
int Splash2;
int Splash3;
int J;
int Explod1;
int Explod2;
int Wave;
int First1;
int First2;
int First3;
int Start1;
int Var;

//Prototype
void function (int&, int&, int&);
void title();
void screen();
void hit ();
void miss();
void sink();
void windowfill();
void win();
void lose();
void wwii ();
void main ()
{
//START OF VOID MAIN-->
clrscr();

function (Grdriver,Grmode,Errorcode);
cleardevice();
randomize();

//title();
//getch();
screen();
getch();

wwii();

hit ();
getch();
miss();
getch();
sink();
getch();

windowfill();
getch();
win();
getch();
lose();
getch();


};

void function (int& Grdriver, int& Grmode, int& Errorcode)
{Grdriver=VGA;
Grmode=VGAHI;
initgraph(&Grdriver, &Grmode,"C:\\TC\\BGI");
Errorcode=graphresult();
if (Errorcode!=grOk)
{clrscr();
cout<<"Error";
getch();
exit(1);
}

};

//START FUNCTIONS

void wwii ()
{setcolor(8);
 setfillstyle(1,8);
//w
 line(243,0,253,0);
 line(253,0,263,50);
 line(263,50,268,30);
 line(268,30,278,30);
 line(278,30,283,50);
 line(283,50,293,0);
 line(293,0,303,0);
 line(303,0,293,70);
 line(293,70,283,70);
 line(283,70,273,45);
 line(273,45,263,70);
 line(263,70,253,70);
 line(253,70,243,0);
 //w
 line(303,0,313,0);
 line(313,0,323,50);
 line(323,50,328,30);
 line(328,30,338,30);
 line(338,30,343,50);
 line(343,50,353,0);
 line(353,0,363,0);
 line(363,0,353,70);
 line(353,70,343,70);
 line(343,70,333,45);
 line(333,45,323,70);
 line(323,70,313,70);
 line(313,70,303,0);
 //I
 line(364,0,379,0);
 line(379,0,379,70);
 line(379,70,364,70);
 line(364,70,364,0);
 //I
 line(381,0,396,0);
 line(396,0,396,70);
 line(396,70,381,70);
 line(381,70,381,0);
 floodfill(248,3,8);
 floodfill(305,3,8);
 floodfill(383,3,8);
 floodfill(368,3,8);
 setcolor(RED);
 moveto(255,80);
 outtext("A  R  M  A  D  A");
 };
//SCREEN, HIT, MISS, SINK
void title ()
{

setfillstyle (1,9);
floodfill(1,1,15);
setfillstyle (1,1);
bar (0,360,640,480);

for (Wave=1;Wave<5;Wave++)
{
 for (Start1=1;Start1<300;Start1++)
 {
 setcolor(3);
 First1=random(641)-1;
 First2=random(641)-1;
 First3=random(120)+360;
 line(First1,First3,First2,First3);
 }

 for (Start1=1;Start1<200;Start1++)
 {
 setcolor(9);
 First1=random(641)-1;
 First2=random(641)-1;
 First3=random(120)+360;
 line(First1,First3,First2,First3);
 }

 for (Start1=1;Start1<200;Start1++)
 {setcolor(1);
 First1=random(641)-1;
 First2=random(641)-1;
 First3=random(120)+360;
 line(First1,First3,First2,First3);
 }
 for (Start1=1;Start1<50;Start1++)
 {setcolor(15);
 First1=random(641)-1;
 First2=random(641)-1;
 First3=random(120)+360;
 line(First1,First3,First2,First3);
 }
}

setcolor(0);
arc(700,240,90,70,300);
setfillstyle(1,0);
floodfill(500,240,0);
setfillstyle(1,9);
bar(455,85,615,145);
bar(455,165,615,225);
bar(455,245,615,305);
bar(455,325,615,385);
setfillstyle(1,15);
bar(460,80,620,140);
bar(460,160,620,220);
bar(460,240,620,300);
bar(460,320,620,380);

setcolor(4);
//Menu
line(470,20,470,70);
line(470,70,480,70);
line(480,70,480,40);
line(480,40,485,50);
line(485,50,490,40);
line(490,40,490,70);
line(490,70,500,70);
line(500,70,500,20);
line(500,20,490,20);
line(490,20,485,30);
line(485,30,480,20);
line(480,20,470,20);
line(510,20,510,70);
line(510,70,540,70);
line(540,70,540,60);
line(540,60,520,60);
line(520,60,520,50);
line(520,50,530,50);
line(530,50,530,40);
line(530,40,520,40);
line(520,40,520,30);
line(520,30,540,30);
line(540,30,540,20);
line(540,20,510,20);
line(550,20,550,70);
line(550,70,560,70);
line(560,70,560,40);
line(560,40,570,70);
line(570,70,580,70);
line(580,70,580,20);
line(580,20,570,20);
line(570,20,570,54);
line(570,54,560,20);
line(560,20,550,20);
line(590,20,590,70);
line(590,70,620,70);
line(620,70,620,20);
line(620,20,610,20);
line(610,20,610,60);
line(610,60,600,60);
line(600,60,600,20);
line(600,20,590,20);
setfillstyle(9,4);
floodfill(480,30,4);
floodfill(515,30,4);
floodfill(555,30,4);
floodfill(595,30,4);
floodfill(575,30,4);
outtextxy(580,420,"red");
setcolor(15);
outtextxy(490,420,"Select the");
outtextxy(490,430,"letter to choose");
outtextxy(490,440,"an option");
setcolor(0);
outtextxy(480,110," ntro");
outtextxy(480,190,"I structions");
outtextxy(480,270," lay");
outtextxy(480,350," uit");
setcolor(4);
outtextxy(480,110,"I");
outtextxy(486,190,"n");
outtextxy(480,270,"P");
outtextxy(480,350,"Q");
setcolor(0);

//Title Ship
line(20,260,380,260);
line(380,260,320,360);
line(320,360,80,360);
line(80,360,20,260);
line(80,260,80,200);
line(80,200,200,200);
line(200,200,200,260);
line(200,220,260,220);
line(260,220,260,260);
line(100,190,100,200);
line(100,190,160,190);
line(160,190,160,200);
setfillstyle(1,8);
floodfill(100,240,0);
floodfill(120,195,0);
floodfill(220,240,0);
floodfill(100,320,0);

circle(60,280,5);
circle(100,280,5);
circle(140,280,5);
circle(180,280,5);
circle(220,280,5);
circle(260,280,5);
circle(300,280,5);
circle(340,280,5);
setfillstyle(1,0);
floodfill(60,280,0);
floodfill(100,280,0);
floodfill(140,280,0);
floodfill(180,280,0);
floodfill(220,280,0);
floodfill(260,280,0);
floodfill(300,280,0);
floodfill(340,280,0);
line(300,285,300,310);
line(290,310,310,310);
circle(290,310,2);
circle(310,310,2);
circle(300,295,1);
outtextxy(245,265,"U.S.S. Lexington");
ellipse(40,260,0,180,15,18);
line(38,243,20,230);
line(34,244,18,237);

line(85,205,85,235);
line(85,235,120,235);
line(120,235,120,205);
line(120,205,85,205);

line(125,205,125,225);
line(125,225,160,225);
line(160,225,160,205);
line(160,205,125,205);

line(165,205,165,225);
line(165,225,195,225);
line(195,225,195,205);
line(195,205,165,205);
setfillstyle(1,9);
floodfill(100,220,0);
floodfill(140,220,0);
floodfill(180,220,0);

setfillstyle(1,8);
floodfill(30,250,0);

//WWII Words
//"W"
setcolor(15);
line(16,20,16,28);
line(16,28,20,28);
line(20,28,44,100);
line(44,100,64,100);
line(64,100,78,68);
line(78,68,92,100);
line(92,100,112,100);
line(112,100,136,28);
line(136,28,140,28);
line(140,28,140,20);
line(140,20,104,20);
line(104,20,104,28);
line(104,28,108,28);
line(108,28,100,76);
line(100,76,84,60);
line(84,60,86,60);
line(86,60,86,52);
line(86,52,70,52);
line(70,52,70,60);
line(70,60,72,60);
line(72,60,56,76);
line(56,76,48,28);
line(48,28,52,28);
line(52,28,52,20);
line(52,20,16,20);

line(148,20,148,28);
line(148,28,152,28);
line(152,28,176,100);
line(176,100,196,100);
line(196,100,210,68);
line(210,68,224,100);
line(224,100,244,100);
line(244,100,268,28);
line(268,28,272,28);
line(272,28,272,20);
line(272,20,236,20);
line(236,20,236,28);
line(236,28,240,28);
line(240,28,232,76);
line(232,76,216,60);
line(216,60,218,60);
line(218,60,218,52);
line(218,52,202,52);
line(202,52,202,60);
line(202,60,204,60);
line(204,60,188,76);
line(188,76,180,28);
line(180,28,184,28);
line(184,28,184,20);
line(184,20,148,20);
//"I"
line(280,20,280,28);
line(280,28,284,28);
line(284,28,284,92);
line(284,92,280,92);
line(280,92,280,100);
line(280,100,312,100);
line(312,100,312,92);
line(312,92,308,92);
line(308,92,308,28);
line(308,28,312,28);
line(312,28,312,20);
line(312,20,280,20);

line(320,20,320,28);
line(320,28,324,28);
line(324,28,324,92);
line(324,92,320,92);
line(320,92,320,100);
line(320,100,352,100);
line(352,100,352,92);
line(352,92,348,92);
line(348,92,348,28);
line(348,28,352,28);
line(352,28,352,20);
line(352,20,320,20);
setfillstyle(1,1);
delay(1000);
floodfill(40,40,15);
delay(1000);
floodfill(160,24,15);
delay(1000);
floodfill(300,28,15);
delay(1000);
floodfill(340,28,15);
delay(1500);

setcolor(0);
outtextxy(69,131,"A");
setcolor(15);
outtextxy(70,130,"A");
delay(500);
setcolor(0);
outtextxy(119,131,"R");
setcolor(15);
outtextxy(120,130,"R");
setcolor(0);
delay(500);
outtextxy(169,131,"M");
setcolor(15);
outtextxy(170,130,"M");
delay(500);
setcolor(0);
outtextxy(219,131,"A");
setcolor(15);
outtextxy(220,130,"A");
delay(500);
setcolor(0);
outtextxy(269,131,"D");
setcolor(15);
outtextxy(270,130,"D");
delay(500);
setcolor(0);
outtextxy(319,131,"A");
setcolor(15);
outtextxy(320,130,"A");





}

void screen()
{
cleardevice();
//GRID
setcolor (9);
moveto(110,170);
outtext("Japan");
line (20,180,240,180);
line (20,200,240,200);
line (20,220,240,220);
line (20,240,240,240);
line (20,260,240,260);
line (20,280,240,280);
line (20,300,240,300);
line (20,320,240,320);
line (20,340,240,340);
line (20,360,240,360);
line (20,380,240,380);
line (20,400,240,400);
line (20,180,20,400);
line (40,180,40,400);
line (60,180,60,400);
line (80,180,80,400);
line (100,180,100,400);
line (120,180,120,400);
line (140,180,140,400);
line (160,180,160,400);
line (180,180,180,400);
line (200,180,200,400);
line (220,180,220,400);
line (240,180,240,400);
//GRID 2
moveto(500,170);
outtext("USA");
line (400,180,620,180);
line (400,200,620,200);
line (400,220,620,220);
line (400,240,620,240);
line (400,260,620,260);
line (400,280,620,280);
line (400,300,620,300);
line (400,320,620,320);
line (400,340,620,340);
line (400,360,620,360);
line (400,380,620,380);
line (400,400,620,400);
line (400,180,400,400);
line (420,180,420,400);
line (440,180,440,400);
line (460,180,460,400);
line (480,180,480,400);
line (500,180,500,400);
line (520,180,520,400);
line (540,180,540,400);
line (560,180,560,400);
line (580,180,580,400);
line (600,180,600,400);
line (620,180,620,400);
setcolor (14);
outtextxy (428,187,"1");
outtextxy (448,187,"2");
outtextxy (468,187,"3");
outtextxy (488,187,"4");
outtextxy (508,187,"5");
outtextxy (528,187,"6");
outtextxy (548,187,"7");
outtextxy (568,187,"8");
outtextxy (588,187,"9");
outtextxy (603,187,"10");

outtextxy (48,187,"1");
outtextxy (68,187,"2");
outtextxy (88,187,"3");
outtextxy (108,187,"4");
outtextxy (128,187,"5");
outtextxy (148,187,"6");
outtextxy (168,187,"7");
outtextxy (188,187,"8");
outtextxy (208,187,"9");
outtextxy (223,187,"10");

outtextxy (28,210,"A");
outtextxy (28,230,"B");
outtextxy (28,250,"C");
outtextxy (28,270,"D");
outtextxy (28,290,"E");
outtextxy (28,310,"F");
outtextxy (28,330,"G");
outtextxy (28,350,"H");
outtextxy (28,370,"I");
outtextxy (28,390,"J");

outtextxy (408,210,"A");
outtextxy (408,230,"B");
outtextxy (408,250,"C");
outtextxy (408,270,"D");
outtextxy (408,290,"E");
outtextxy (408,310,"F");
outtextxy (408,330,"G");
outtextxy (408,350,"H");
outtextxy (408,370,"I");
outtextxy (408,390,"J");

outtextxy (278,100,"Created by:");
outtextxy (273,110,"Kathy Harrod");
outtextxy (267,120,"Rebecca Grigsby");
outtextxy(257,130,"& Rebecca Russell");

setcolor(8);
//Ships
line(290,250,300,258);
line(300,258,320,260);
line(320,260,340,258);
line(340,258,350,250);
line(350,250,340,242);
line(340,242,320,240);
line(320,240,300,242);
line(300,242,290,250);

line(300,280,290,290);
line(290,290,300,300);
line(300,300,340,300);
line(340,300,350,290);
line(350,290,340,280);
line(340,280,300,280);
}

void hit ()
{
//WORDS
setfillstyle(1,15);
bar (400,0,640,160);
bar (0,0,240,160);

setcolor(0);
line(10,20,10,150);
line(40,150,10,150);
line(40,150,40,100);
line(40,100,70,100);
line(70,100,70,150);
line(70,150,100,150);
line(100,150,100,20);
line(100,20,70,20);
line(70,20,70,80);
line(70,80,40,80);
line(40,80,40,20);
line(110,20,110,150);
line(110,150,140,150);
line(140,150,140,20);
line(140,20,110,20);
line(150,20,150,50);

line(150,50,180,50);
line(180,50,180,150);
line(180,150,210,150);
line(210,150,210,50);
line(210,50,230,50);
line(230,50,230,20);
line(230,20,150,20);
line(10,20,40,20);

setfillstyle(4,4);
delay(500);
floodfill(15,25,0);
delay(500);
floodfill(120,30,0);
delay(500);
floodfill(190,40,0);
delay(1000);

//Ship
setfillstyle(2,1);
setcolor(1);
rectangle(400,120,640,160);
floodfill(520,150,1);
setcolor(BLACK);
line(490,80,520,140);
line(520,140,640,140);
line(640,140,640,80);
line(640,80,490,80);
line(520,50,580,50);
line(580,50,580,60);
line(580,60,620,60);
line(620,60,620,80);
line(530,50,530,20);
line(530,20,540,20);
line(540,20,540,50);
line(520,50,520,80);
setfillstyle(1,8);
floodfill(540,100,0);
floodfill(540,60,0);
floodfill(535,30,0);
setfillstyle(1,2);
delay(500);
setcolor(3);

for(I=0;I<6;I++)
{
	for(J=0;J<5;J++)
	{setcolor(YELLOW);
	delay(20);
	Explod1=random(68)+516;
	Explod2=random(68)+76;
	line(550,110,Explod1,Explod2);
	}

	for(J=0;J<5;J++)
	{setcolor(6);
	delay(20);
	Explod1=random(68)+516;
	Explod2=random(68)+76;
	line(550,110,Explod1,Explod2);
	}

	for(J=0;J<5;J++)
	{setcolor(RED);
	delay(20);
	Explod1=random(68)+516;
	Explod2=random(68)+76;
	line(550,110,Explod1,Explod2);
	}

}
}



void miss()
{
setfillstyle(1,15);
bar (400,0,640,160);
bar (0,0,240,160);

//WORDS
delay(550);
setcolor(0);
line(30,10,10,150);
line(10,150,30,150);
line(30,150,40,50);
line(40,50,50,70);
line(50,70,60,70);
line(60,70,70,50);
line(70,50,80,150);
line(80,150,100,150);
line(100,150,80,10);
line(80,10,70,10);
line(70,10,60,50);
line(60,50,50,50);
line(50,50,40,10);
line(40,10,30,10);

line(110,10,110,150);
line(110,150,120,150);
line(120,150,120,10);
line(120,10,110,10);

line(130,10,130,80);
line(130,80,160,80);
line(160,80,160,140);
line(160,140,130,140);
line(130,140,130,150);
line(130,150,170,150);
line(170,150,170,70);
line(170,70,140,70);
line(140,70,140,20);
line(140,20,170,20);
line(170,20,170,10);
line(170,10,130,10);

line(180,10,180,80);
line(180,80,210,80);
line(210,80,210,140);
line(210,140,180,140);
line(180,140,180,150);
line(180,150,220,150);
line(220,150,220,70);
line(220,70,190,70);
line(190,70,190,20);
line(190,20,220,20);
line(220,20,220,10);
line(220,10,180,10);

setfillstyle(5,2);
floodfill(35,40,0);
delay(500);
floodfill(115,40,0);
delay(500);
floodfill(135,40,0);
delay(500);
floodfill(185,40,0);
delay(500);

//Ship
setcolor(15);
bar(400,0,640,160);
setfillstyle(1,15);
rectangle(400,0,640,160);
floodfill(520,80,15);
setfillstyle(2,1);
setcolor(1);
rectangle(400,120,640,160);
floodfill(520,150,1);
setcolor(BLACK);
line(490,80,520,140);
line(520,140,640,140);
line(640,140,640,80);
line(640,80,490,80);
line(520,50,580,50);
line(580,50,580,60);
line(580,60,620,60);
line(620,60,620,80);
line(530,50,530,20);
line(530,20,540,20);
line(540,20,540,50);
line(520,50,520,80);
setfillstyle(1,8);
floodfill(540,100,0);
floodfill(540,60,0);
floodfill(535,30,0);
setfillstyle(1,2);

for(I=0;I<6;I++)
{
	for(J=0;J<5;J++)
	{setcolor(WHITE);
	delay(20);
	Splash1=random(68)+426;
	Splash2=random(20)+90;
	Splash3=random(5)+459;
	line(Splash3,150,Splash1,Splash2);
	}

	for(J=0;J<5;J++)
	{setcolor(1);
	delay(20);
	Splash1=random(68)+426;
	Splash2=random(20)+90;
	Splash3=random(5)+459;
	line(Splash3,150,Splash1,Splash2);
	}

	for(J=0;J<5;J++)
	{setcolor(3);
	delay(20);
	Splash1=random(68)+426;
	Splash2=random(20)+90;
	Splash3=random(5)+459;
	line(Splash3,150,Splash1,Splash2);
	}

}
}

void sink ()
{
setfillstyle(1,15);
bar (400,0,640,160);
bar (0,0,240,160);
//WORDS

setcolor (0);
line (10,10,10,80);
line (10,80,60,80);
line (60,80,60,140);
line (60,140,10,140);
line (10,140,10,150);
line (10,150,70,150);
line (70,150,70,70);
line (70,70,20,70);
line (20,70,20,20);
line (20,20,70,20);
line (70,20,70,10);
line (70,10,10,10);

line (80,10,80,150);
line (80,150,90,150);
line (90,150,90,10);
line (90,10,80,10);

line (100,10,100,150);
line (100,150,110,150);
line (110,150,110,60);
line (110,60,150,150);
line (150,150,160,150);
line (160,150,160,10);
line (160,10,150,10);
line (150,10,150,130);
line (150,130,110,10);
line (110,10,100,10);

line (170,10,170,150);
line (170,150,180,150);
line (180,150,180,80);
line (180,80,220,150);
line (220,150,230,150);
line (230,150,230,140);
line (230,140,190,70);
line (190,70,230,10);
line (230,10,220,10);
line (220,10,180,70);
line (180,70,180,10);
line (180,10,170,10);

setfillstyle (3,1);
delay(500);
floodfill(15,15,0);
delay(500);
floodfill(85,15,0);
delay(500);
floodfill(105,15,0);
delay(500);
floodfill(175,15,0);
delay(500);

//SHIP
setcolor(1);
setfillstyle (2,1);
rectangle (400,120,640,160);
floodfill (410,130,1);

setcolor (0);
line(540,10,454,60);
line(454,60,454,119);
line(454,119,540,119);
line(540,119,540,10);
line(540,40,570,40);
line(570,40,570,100);
line(570,100,560,100);
line(560,100,560,120);
line(560,120,540,120);
line(570,50,600,50);
line(600,50,600,60);
line(600,60,570,60);

setfillstyle(1,8);
floodfill(490,50,0);
floodfill(550,50,0);
floodfill(580,55,0);
delay(500);

setfillstyle(1,15);
bar(400,0,640,160);
setfillstyle(2,1);
bar (400,120,640,160);

setcolor(0);
line(454,120,454,90);
line(454,90,540,40);
line(540,40,540,120);
line(540,70,570,70);
line(570,70,570,120);
line(570,120,454,120);
line(570,80,600,80);
line(600,80,600,90);
line(600,90,570,90);

setfillstyle (1,8);
floodfill(490,90,0);
floodfill(550,90,0);
floodfill(580,85,0);
delay (500);

setfillstyle(1,15);
bar(400,0,640,160);
setfillstyle(2,1);
bar (400,120,640,160);

setcolor(0);
line(454,120,540,70);
line(540,70,540,100);
line(540,70,540,120);
line(540,100,570,100);
line(570,100,570,120);
line(578,120,454,120);
setfillstyle (1,8);
floodfill (510,100,0);
floodfill (550,110,0);
delay(500);

setfillstyle(1,15);
bar(400,0,640,160);
setfillstyle(2,1);
bar (400,120,640,160);

setcolor(0);
line(500,120,540,100);
line(540,100,540,120);
line(540,120,500,120);
setfillstyle(1,8);
floodfill(530,110,0);
delay (500);

setfillstyle(1,15);
bar(400,0,640,160);
setfillstyle(2,1);
bar (400,120,640,160);
}

void windowfill ()
{
setfillstyle(1,0);
bar(400,0,640,160);
bar(0,0,240,160);
setfillstyle(7,2);
bar (400,0,636,160);
bar (0,0,240,160);
setcolor(15);
outtextxy(50,60,"Waiting for launch");
outtextxy(65,80,"confirmation.");
outtextxy(460,70,"Standing By....");
setcolor(YELLOW);
}

void win ()
{
setfillstyle(1,15);
bar(20,120,620,340);
setfillstyle(1,1);
bar(40,140,600,320);
setfillstyle(1,9);
bar(60,160,580,300);
 setcolor(0);
//Y
line(80,180,100,240);
line(100,240,100,280);
line(100,280,120,280);
line(120,280,120,240);
line(120,240,140,180);
line(140,180,120,180);
line(120,180,110,220);
line(110,220,100,180);
line(100,180,80,180);
//0
line(148,200,148,260);
line(148,260,168,280);
line(168,280,188,280);
line(188,280,208,260);
line(208,260,208,200);
line(208,200,188,180);
line(188,180,168,180);
line(168,180,148,200);
line(172,200,168,204);
line(168,204,168,256);
line(168,256,172,260);
line(172,260,184,260);
line(184,260,188,256);
line(188,256,188,204);
line(188,204,184,200);
line(184,200,172,200);
//U
line(216,180,216,260);
line(216,260,236,280);
line(236,280,256,280);
line(256,280,276,260);
line(276,260,276,180);
line(276,180,256,180);
line(256,180,256,260);
line(256,260,236,260);
line(236,260,236,180);
line(236,180,216,180);
//W
line(336,180,360,280);
line(360,280,380,280);
line(380,280,400,240);
line(400,240,420,280);
line(420,280,440,280);
line(440,280,464,180);
line(464,180,444,180);
line(444,180,428,252);
line(428,252,408,220);
line(408,220,392,220);
line(392,220,372,252);
line(372,252,356,180);
line(356,180,336,180);
//I
line(472,180,472,280);
line(472,280,492,280);
line(492,280,492,180);
line(492,180,472,180);
//N
line(500,180,500,280);
line(500,280,520,280);
line(520,280,520,228);
line(520,228,540,280);
line(540,280,560,280);
line(560,280,560,180);
line(560,180,540,180);
line(540,180,540,232);
line(540,232,520,180);
line(520,180,500,180);

for(I=0;I<30;I++)
{Var=random(14)+1;
setfillstyle(1,Var);
floodfill(110,240,0);
floodfill(180,190,0);
floodfill(230,200,0);
floodfill(350,190,0);
floodfill(480,200,0);
floodfill(510,200,0);
delay(100);
}
setfillstyle(1,15);
floodfill(110,240,0);
floodfill(180,190,0);
floodfill(230,200,0);
floodfill(350,190,0);
floodfill(480,200,0);
floodfill(510,200,0);
setcolor(15);
outtextxy(170,440,"Press Any key to Exit the Program");



};

void lose ()
{
setfillstyle(1,15);
bar(20,120,620,340);
setfillstyle(1,1);
bar(40,140,600,320);
setfillstyle(1,9);
bar(60,160,580,300);
 setcolor(0);
//Y
line(80,180,100,240);
line(100,240,100,280);
line(100,280,120,280);
line(120,280,120,240);
line(120,240,140,180);
line(140,180,120,180);
line(120,180,110,220);
line(110,220,100,180);
line(100,180,80,180);
//0
line(148,200,148,260);
line(148,260,168,280);
line(168,280,188,280);
line(188,280,208,260);
line(208,260,208,200);
line(208,200,188,180);
line(188,180,168,180);
line(168,180,148,200);
line(172,200,168,204);
line(168,204,168,256);
line(168,256,172,260);
line(172,260,184,260);
line(184,260,188,256);
line(188,256,188,204);
line(188,204,184,200);
line(184,200,172,200);
//U
line(216,180,216,260);
line(216,260,236,280);
line(236,280,256,280);
line(256,280,276,260);
line(276,260,276,180);
line(276,180,256,180);
line(256,180,256,260);
line(256,260,236,260);
line(236,260,236,180);
line(236,180,216,180);
//L
line(300,180,300,280);
line(300,280,360,280);
line(360,280,360,260);
line(360,260,320,260);
line(320,260,320,180);
line(320,180,300,180);
//O
line(368,200,368,260);
line(368,260,388,280);
line(388,280,408,280);
line(408,280,428,260);
line(428,260,428,200);
line(428,200,408,180);
line(408,180,388,180);
line(388,180,368,200);
line(388,204,388,256);
line(388,256,392,260);
line(392,260,404,260);
line(404,260,408,256);
line(408,256,408,204);
line(408,204,404,200);
line(404,200,392,200);
line(392,200,388,204);
//S
line(436,200,436,224);
line(436,224,444,232);
line(444,232,468,232);
line(468,232,476,240);
line(476,240,476,260);
line(476,260,456,260);
line(456,260,456,240);
line(456,240,436,240);
line(436,240,436,260);
line(436,260,456,280);
line(456,280,476,280);
line(476,280,496,260);
line(496,260,496,240);
line(496,240,488,228);
line(488,228,464,228);
line(464,228,456,220);
line(456,220,456,200);
line(456,200,476,200);
line(476,200,476,220);
line(476,220,496,220);
line(496,220,496,200);
line(496,200,476,180);
line(476,180,456,180);
line(456,180,436,200);
//E
line(504,180,504,280);
line(504,280,560,280);
line(560,280,560,260);
line(560,260,524,260);
line(524,260,524,240);
line(524,240,544,240);
line(544,240,544,220);
line(544,220,524,220);
line(524,220,524,200);
line(524,200,560,200);
line(560,200,560,180);
line(560,180,504,180);
for(I=0;I<30;I++)
{Var=random(14)+1;
setfillstyle(1,Var);
floodfill(110,240,0);
floodfill(180,190,0);
floodfill(230,200,0);
floodfill(310,190,0);
floodfill(370,200,0);
floodfill(460,190,0);
floodfill(510,200,0);
delay(100);
}
setfillstyle(1,15);
floodfill(110,240,0);
floodfill(180,190,0);
floodfill(230,200,0);
floodfill(310,190,0);
floodfill(370,200,0);
floodfill(460,190,0);
floodfill(510,200,0);

setcolor(15);
outtextxy(170,440,"Press Any key to Exit the Program");
}