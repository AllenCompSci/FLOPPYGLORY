
//Kristi Yakman
//Shell
//5th

//Library sec
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <alloc.h>
#include <dbuffer.h>
//const sec

//structs

//Global Variable Section
char Ans;
int GrDriver, GrMode, ErrorCode;
int A,B,C,D,E,F,I;
char Key;
unsigned int Size;
void far *P;
//Prototypes
void gr_start(int&,int&,int&);


//Main Section
void main()
{
do{
	clrscr();

	gr_start(GrDriver,GrMode,ErrorCode);
A=150;
B=100;
setcolor(2);
setfillstyle(1,3);
fillellipse(A+19,B+13,6,3);
fillellipse(A+3,B+13,6,3);
fillellipse(A,B,3,3);
fillellipse(A+22,B,3,3);
fillellipse(A+11,B+5,10,10);

I=0;


do{
 if(kbhit())
 {Key=getch();

 //down
 if(Key==80)
 B=B+20;

 //up
 if(Key==72)
 B=B-20;

 //right
 if(Key==77)
 A=A+30;

 //left
 if(Key==75)
 A=A-30;

 cleardevice();

 setcolor(2);
fillellipse(A+19,B+13,6,3);
fillellipse(A+3,B+13,6,3);
fillellipse(A,B,3,3);
fillellipse(A+22,B,3,3);
fillellipse(A+11,B+5,10,10); }



	}while(Key!=27);
	cout<<"Re-run? (Y/N)"<<endl;
	cin>>Ans;

	}while(Ans=='Y'||Ans=='y');



}//End Main

//Create functions here

void gr_start(int&GrDriver, int&GrMode, int&ErrorCode)
{GrDriver=VGA;
GrMode=VGAHI;
initgraph(&GrDriver, &GrMode, "C:\\TC\\BGI");
if(ErrorCode!=grOk)
{clrscr();
cout<<"Error:"<<ErrorCode;
getch();
exit(1);}}