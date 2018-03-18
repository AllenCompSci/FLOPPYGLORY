#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <fstream.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>

int Keypress();
void newchar1 ();
void graphics_setup(int,int);
int i,a,b,c,d,z,x,y, v;
int GrMode, GrDriver;
int G;
apstring Name;
ifstream in_file;



void main()
{
graphics_setup(GrMode,GrDriver);

do
{
line(320,240,i,100);
delay(2);
i++;
}while(i<640);
i=100;

do
{

line(320,240,640,i);
delay(2);
i++;
}while(i<380);
i=100;
do
{

line(320,240,0,i);
delay(2);
i++;
}while(i<380);

i=0;
do
{

line(320,240,i,380);
delay(2);
i++;
}while(i<640);
settextstyle(2,0,6);
setcolor(RED);
outtextxy(50,150,"Transfering to Main System");
b=310;
do
 {
 outtextxy(b,150,".");
 b=b+10;
 delay(500);
 }while(b<=350);

outtextxy(100,200,"System Initialization Complete...");
delay(250);
outtextxy(125,220,"Loading...");
delay(350);
setcolor(BLACK);
do
 {
 line(c,100,d,380);
 c++;
 d++;
 delay(3);
 }while(c<=640);

delay(200);
setcolor(RED);
z=481;
x=-1;
do
{
z--;
x++;
line(0,z,640,x);
delay(2);
setcolor(BLACK);
line(0,z,640,x);
setcolor(RED);

}while((z>240)||(x<240));
line(0,z,640,x);
delay(200);
a=240;
b=240;
setcolor(WHITE);
do
{
line(0,a,640,a);
line(0,b,640,b);
delay(20);
a++;
b--;
}while((a<=340)||(b>=100));
setcolor(RED);
outtextxy(250,130,"- Main Menu -");
outtextxy(226,200,"Start New Character");
outtextxy(221,230,"Load Saved Character");
line(90,180,90,300);
line(130,160,130,310);
line(170,150,170,320);
i=0;
x=0;
z=0;
if(Keypress()!=13)
i=Keypress();
do
{
 i=Keypress();
 switch(i)
 {
 case 13 :
 if(i==0)
 z=1;

 if(z==1)
 v=1;
 if(z==2)
 v=2;break;

 case 72 :
	z=1;
	x=20;
	setcolor(WHITE);
	line(0,240,210,240);
	setcolor(RED);
	putpixel(90,240,4);
	putpixel(130,240,4);
	putpixel(170,240,4);
	putpixel(90,210,4);
	putpixel(130,210,4);
	putpixel(170,210,4);

	do
	{
	putpixel(x,210,4);
	x++;
	delay(2);
	}while(x<=216);break;

	case 80 :
	z=2;
	x=20;

		setcolor(WHITE);
	line(0,210,216,210);
	setcolor(RED);
		putpixel(90,240,4);
	putpixel(130,240,4);
	putpixel(170,240,4);
	putpixel(90,210,4);
	putpixel(130,210,4);
	putpixel(170,210,4);

	do
	{
	putpixel(x,240,4);
	x++;
	delay(2);
	}while(x<=210);break;
 };
}while(i!=13);


if(v==1)
cleardevice();


newchar1();



if(v==2)
{
cleardevice();

};
};

void loadchar1 ()
{
in_file.open(Name.c_str());
in_file>>Name;
setcolor(WHITE);
outtextxy(250,4,"Load Character");
outtextxy(20,60,"Character's Name");
gotoxy(6,6);
getline(cin,Name);



G=10;
	while(!in_file.eof())
	{
		gotoxy(10,G);
		cout<<Name<<endl;
		in_file>>Name;
		//G++;
	}
in_file.close();
getch();
};











void newchar1()
{
apstring tempclass, Na;
int Keypress ();
int midx;
int midy;
int i, z, x;
int Point;
int Key;
int Class;
ofstream out_file;
struct Charinfo
{
apstring Name;
apstring Class;
apvector <bool> Spells;
int classnum;
int HP;
int MP;
int SK;
int EXP;
};
Charinfo Character;









Character.Spells.resize(4);
clrscr();


setbkcolor(WHITE);
setcolor(RED);

rectangle (0, 0,300,475);
settextstyle(2,0,6);

outtextxy(20,50,"Character's Name?");
gotoxy(6,6);
getline(cin,Na);


outtextxy(10,100,"Choose your Class...");

outtextxy(30,155,"Warrior");

outtextxy(30,205,"Mage");

outtextxy(30,253,"Rogue");

//Mage= 3 14, 14 14
//Rouge=3 17, 14 17



	Point=11;
	gotoxy(3,11);
	cout<<"<";
	gotoxy(14,11);
	cout<<">";
	do{ Key=Keypress();
			switch(Key)
				{ case 72: gotoxy(3,Point);
									 cout<<" ";
									 gotoxy(14,Point);
									 cout<<" ";
									 Point=Point-3;
									 if (Point<11)
											Point=17;
									 gotoxy(3,Point);
									 cout<<'<';
									 gotoxy(14,Point);
									 cout<<'>';
									 gotoxy(3,Point);
									 break;  // Go UP

					case 80: gotoxy(3,Point);
									 cout<<" ";
									 gotoxy(14,Point);
									 cout<<" ";
									 Point=Point+3;
									 if (Point>17)
											Point=11;
									 gotoxy(3,Point);
									 cout<<'<';
									 gotoxy(14,Point);
									 cout<<'>';
									 gotoxy(3,Point);
									 break;  // Go Down

					case 13: Class=Point;
				}

		}
		while(Key!=13);
switch(Point)
{
case 11 :
Character.classnum=1;
break;
case 14 :
Character.classnum=2;
break;
case 17 :
Character.classnum=3;
break;
};

switch(Character.classnum)
{
case 1 :
Character.Class="Warrior";
Character.classnum=1;
Character.HP=30;
Character.MP=8;
Character.SK=20;
Character.EXP=0;
Character.Name=Na;
Character.Spells[0]=true;
Character.Spells[1]=false;
Character.Spells[2]=false;
Character.Spells[3]=false;
break;

case 2 :
Character.Class="Mage";
Character.classnum=2;
Character.HP=30;
Character.MP=20;
Character.SK=8;
Character.EXP=0;
Character.Name=Na;
Character.Spells[0]=true;
Character.Spells[1]=false;
Character.Spells[2]=true;
Character.Spells[3]=false;
break;

case 3 :
Character.Class="Rogue";
Character.classnum=3;
Character.HP=30;
Character.MP=14;
Character.SK=14;
Character.EXP=0;
Character.Name=Na;
Character.Spells[0]=false;
Character.Spells[1]=true;
Character.Spells[2]=false;
Character.Spells[3]=false;
break;
};



switch(Point)
{
case 11 :
x=30;
do
{
line(300,0,300,475);
setcolor(WHITE);
outtextxy(x,155,"Warrior");
setcolor(RED);
x++;
outtextxy(x,155,"Warrior");
delay(3);
}while(x<=450);
setcolor(WHITE);
outtextxy(x,155,"Warrior");
x=155;
do
{
setcolor(WHITE);
outtextxy(450,x,"Warrior");
setcolor(RED);
x--;
outtextxy(450,x,"Warrior");
delay(3);
}while(x>=10);
break;

case 14:
x=30;
do
{
line(300,0,300,475);
setcolor(WHITE);
outtextxy(x,205,"Mage");
setcolor(RED);
x++;
outtextxy(x,205,"Mage");
delay(3);
}while(x<=450);
setcolor(WHITE);
outtextxy(x,205,"Mage");
x=205;
do
{
setcolor(WHITE);
outtextxy(450,x,"Mage");
setcolor(RED);
x--;
outtextxy(450,x,"Mage");
delay(3);
}while(x>=10);
break;




case 17:
x=30;
do
{
line(300,0,300,475);
setcolor(WHITE);
outtextxy(x,253,"Rogue");
setcolor(RED);
x++;
outtextxy(x,253,"Rogue");
delay(3);
}while(x<=450);
setcolor(WHITE);
outtextxy(x,253,"Rogue");
x=253;
do
{
setcolor(WHITE);
outtextxy(450,x,"Rogue");
setcolor(RED);
x--;
outtextxy(450,x,"Rogue");
delay(3);
}while(x>=10);
break;

};

if(Character.Class=="Warrior")
{
outtextxy(450,50,"HP : 30");
outtextxy(445,70,"Mana : 8");
outtextxy(440,90,"Skill : 20");
outtextxy(400,110,"Spell : Lightning Bolt");
};

if(Character.Class=="Mage")
{
outtextxy(450,50,"HP : 30");
outtextxy(445,70,"Mana : 20");
outtextxy(445,90,"Skill : 8");
outtextxy(385,110,"Spells : Lightning Bolt,");
outtextxy(440,130,"Ice Storm");
};

if(Character.Class=="Rogue")
{
outtextxy(450,50,"HP : 30");
outtextxy(445,70,"Mana : 14");
outtextxy(440,90,"Skill : 14");
outtextxy(430,110,"Spell : Quake");
};

out_file.open(Character.Name.c_str());
out_file<<Character.Name<<endl;
out_file<<Character.Class<<endl;
out_file<<Character.HP<<endl;
out_file<<Character.MP<<endl;
out_file<<Character.SK<<endl;
out_file<<Character.EXP<<endl;
out_file<<Character.Spells[0]<<endl;
out_file<<Character.Spells[1]<<endl;
out_file<<Character.Spells[2]<<endl;
out_file<<Character.Spells[3]<<endl ;
out_file.close();

getch();

};











void graphics_setup (int GrMode, int GrDriver)
{
GrMode=VGA;
GrDriver=VGAHI;
initgraph(&GrMode,&GrDriver,"C:\\TC\\BGI");
}

int Keypress ()
{
while(!kbhit());
return getch();
}