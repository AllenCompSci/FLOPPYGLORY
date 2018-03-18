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
#include <dbuffer.h>
//const sec

//structs

//Global Variable Section
char Ans;
int GrDriver, GrMode, ErrorCode;
unsigned char far *Vidseg = (unsigned char far *)0xA0000000L;
unsigned char far Virseg[64000];

//Prototypes
void gr_start(int&,int&,int&);


//Main Section
void main()
{
do{
	clrscr();



	gr_start(GrDriver,GrMode,ErrorCode);

	loadbitmap("A:\\Game\Untitled.bmp",4,Virseg);
	transfer(100,150,96,96,Vidseg,Virseg);

	flip(Virseg,Vidseg);











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