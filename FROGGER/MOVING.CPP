//Comment
//Nick Vankemseke
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
	circle(A,B,50);


I=0;


do{
 if(kbhit())
 {Key=getch();

 if(Key==80)
 B++;

 if(Key==72)
 B--;

 if(Key==77)
 A++;

 if(Key== 75)
 A--;

 cleardevice();

 setcolor(15);
 circle(A,B,50);}



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