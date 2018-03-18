// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>
#include<graphics.h>
#include<stdlib.h>

//constants



//structure



//variables
int grdriver;
int grmode;
int errorcode;
int I;

//prototypes
void show ();



void main ()  {
show();

setbkcolor(0);
setcolor(15);

rectangle(3,3,630,450);
line(10,10,610,10);
line(610,10,610,420);
line(610,420,10,420);
line(10,420,10,10);

I=20;

do{
putpixel(I,20,15);
I++;
}while(I!=590);

I=20;

do{
putpixel(590,I,15);
I++;
}while(I!=400);

I=590;

do{
putpixel(I,400,15);
I--;
}while(I!=20);

I=400;

do{
putpixel(20,I,15);
I--;
}while(I!=20);

line(30,30,30,200);
line(30,85,60,30);
line(30,85,60,200);

line(80,30,80,200);
line(80,30,100,200);
line(100,200,120,30);
line(120,30,120,200);

line(140,64,170,30);
line(170,30,200,30);
line(200,30,230,64);
line(140,64,140,94);
line(140,94,230,124);
line(230,124,230,154);
line(230,154,200,184);
line(200,184,170,184);
line(170,184,140,154);


getch();
closegraph();

};

void show()
{
grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver, &grmode, "c:\\TC\\BGI");
errorcode=graphresult();

if(errorcode!=grOk)
{clrscr();
cout<<"Error";
getch();
exit(1);
}};




