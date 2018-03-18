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
#include<dos.h>
//constants



//structure



//variables
int grdriver;
int grmode;
int errorcode;
int X;
int Y;
int R;
int D;

//prototypes
void show ();
void direction();


void main ()  {
show();

setbkcolor(0);
setcolor(15);

cleardevice();
randomize();
R=10;
X=random(getmaxx()-10)+10;
Y=random(getmaxy()-10)+10;
circle(X,Y,R);


D=random(8);

direction();








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


void direction()
{

do{switch(D)
 {case 0: if(X<(getmaxx()-R))
 {setcolor(0);
 circle(X,Y,R);

 X++;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 1: if(X>9)
 {setcolor(0);
 circle(X,Y,R);

 X--;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 2: if(Y>9)
 {setcolor(0);
 circle(X,Y,R);

 Y--;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 3: if(Y<(getmaxy()-10))
 {setcolor(0);
 circle(X,Y,R);

 Y++;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 4: if((Y<(getmaxy()-10))&&(X>9))
 {setcolor(0);
 circle(X,Y,R);

 Y++;
 X--;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 5: if((Y>9)&&(X<(getmaxx()-10)))
 {setcolor(0);
 circle(X,Y,R);


 Y--;
 X++;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 6: if((Y>9)&&(X>9))
 {setcolor(0);
 circle(X,Y,R);

 Y--;
 X--;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;

 case 7: if((Y<(getmaxy()-10))&&(X<(getmaxx()-10)))
 {setcolor(0);
 circle(X,Y,R);

 Y++;
 X++;
 setcolor(15);
 circle(X,Y,R);
 delay(10);
 }
 else
 {
 D=random(8);
 direction();
 }
 break;
 }
 }
 while(!kbhit());
 };