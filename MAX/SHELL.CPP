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


//prototypes
void show ();



void main ()  {
show();

setbkcolor(0);
setcolor(15);













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




