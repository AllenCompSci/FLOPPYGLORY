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

void graphics_setup(int,int);
int i,a,b,c,d,z,x,y;
int GrMode, GrDriver;
int G;
apstring Name;
ifstream in_file;



void main ()
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
 x=1;
 if(z==2)
 x=2;break;

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


if(x==1)
cleardevice();



























if(x==2)
{
cleardevice();
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