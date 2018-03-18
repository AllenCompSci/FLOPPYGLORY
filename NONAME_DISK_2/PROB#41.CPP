//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<graphics.h>
#include<stdlib.h>
//struct
//const
//var
int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void rectangle1();
void main()
{clrscr();
gr_start(grdriver, grmode, errorcode);
line(320, 0, 320, 479);
line(0, 240, 639, 240);


randomize();
do{
	 setcolor(random(15)+1);
	 switch(random(4)+1)
	 {case 1: rectangle(random(150),random(150), random(320), random(240));
		break;
		case 2: circle(random(255)+355, random(190)+25, random(25));
		break;
		case 3: line(random(319), random(239)+240, random(319), random(239)+240);
		break;
		case 4: putpixel(random(320)+319, random(240)+240, random(15)+1);
	 }
	}while(!kbhit());
}
void gr_start(int &grdriver,int &grmode, int &errorcode)
{grdriver=VGA;
 grmode=VGAHI;
 initgraph(&grdriver, &grmode,"C:\\TC\\BGI");
 errorcode=graphresult();
 if(errorcode!=grOk)
	 {clrscr();
		cout<<"Error"<<errorcode<<endl;
		cout<<"Press Return to continue";
		getch();
		exit(1);
	 }
 }
