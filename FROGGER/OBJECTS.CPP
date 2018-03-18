//Kristi Yakman
//Shell
//Period 5

//library section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>
#include<math2.h>
#include<dbuffer.h>

//Const section



//Structs




//Var section
char Run;
int GrDriver,GrMode,ErrorCode;
char Ans;
unsigned long Size,Size2;
void far *P,*Q;
int I;

unsigned char far *Vidseg = (unsigned char far *)0xA0000000L;
unsigned char far Virseg[64000];


//Prototype section
void gr_start(int&,int&,int&);



//Main section
void main()
{
do{
clrscr();

gr_start(GrDriver,GrMode,ErrorCode);



//froggy's code!!!                        kristi is lame
setcolor(2);
setfillstyle(1,3);
fillellipse(108,108,6,3);
fillellipse(92,108,6,3);
fillellipse(89,95,3,3);
fillellipse(111,95,3,3);
fillellipse(100,100,10,10);

//trucks right                             kristi is lame
setfillstyle(9,8);
bar(255,100,275,125);
setfillstyle(1,3);
bar(276,103,281,122);
setcolor(1);
line(282,103,282,122);
setfillstyle(1,63);
bar(200,100,254,125);

//trucks left                              kristi is lame
setfillstyle(9,56);
bar(200,150,220,175);
setfillstyle(1,3);
bar(194,153,199,172);
setcolor(1);
line(193,153,193,172);
setfillstyle(1,63);
bar(221,150,275,175);

//cars right                                       kristi is lame
setfillstyle(1,1);
bar(320,100,345,115);
setfillstyle(1,8);
bar(324,98,329,101);
bar(336,98,341,101);
bar(324,114,329,117);
bar(336,114,341,117);
setfillstyle(1,3);
bar(343,101,346,114);
setcolor(8);
line(330,102,330,113);
line(335,102,335,113);

//cars left                                       kristi is lame
setfillstyle(1,4);
bar(320,150,345,165);
setfillstyle(1,8);
bar(324,148,329,151);
bar(336,148,341,151);
bar(324,164,329,167);
bar(336,164,341,167);
setfillstyle(1,3);
bar(319,151,322,164);
setcolor(8);
line(330,152,330,163);
line(335,152,335,163);

//logs                                         kristi is lame
setfillstyle(1,6);
bar(100,250,180,280);
setcolor(4);
line(115,257,170,257);
line(130,275,172,275);
line(110,265,175,265);

//turtles                               		 kristi is lame
setcolor(2);
setfillstyle(1,7);
fillellipse(300,250,30,15);
fillellipse(260,250,10,10);
pieslice(275,239,90,270,10);

//lily pads                          		 kristi is lame
setcolor(2);
setfillstyle(1,58);
pieslice(100,175,300,0,17);
pieslice(100,175,0,330,17);



//	setcolor(15);
// bar(0,0,20,20);
// Size2= imagesize(0,0,20,20);
// V=farmalloc(Size2);
// getimage(0,0,20,20,V);
// cleardevice();    kristi smells my house
 Size = imagesize(100,250,180,280);
 P=farmalloc(Size);
 getimage(100,250,180,280,P);

 setbkcolor(0);
 cleardevice();
 setcolor(4);
 setfillstyle(1,4);
 Size=imagesize(319,148,345,151);
 Q=farmalloc(Size);
 getimage(319,148,345,151,Q);

 flip(Virseg,Vidseg);

 I=getmaxx()-80;

 do{ if(I>1)
	 I--;
		else
		 I=getmaxx()-80;
 putimage(I,120,P,COPY_PUT);
 putimage(I,200,Q,COPY_PUT);
// putimage(I,100,V,COPY_PUT);
 delay(5);
 putimage(I,120,P,XOR_PUT);
 putimage(I,200,Q,XOR_PUT);
 delay(5);
// putimage(I,100,V,XOR_PUT);

 }while(!kbhit());


	cout<<"Would you like to run the program again? Enter y for yes."<<endl;
	cin>>Run;


	}while(Run=='Y' || Run=='y');

}//End main

void gr_start(int&GrDriver,int&GrMode,int&ErrorCode)
{
	GrDriver=VGA;
	GrMode=VGAHI;
	initgraph(&GrDriver,&GrMode,"C:\\TC\\BGI");
	ErrorCode=graphresult();

		if(ErrorCode!=grOk)
		{
			clrscr();
			cout<<"Error:"<<ErrorCode;
			getch();
			exit(1);
		}
}