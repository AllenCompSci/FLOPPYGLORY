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
#include<stdio.h>
#include<dos.h>
#include<alloc.h>
//struct
//const
//var
unsigned Size,Size2;
void far *P, *Q;
int A;
int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void main()
{clrscr();
do{
	 gr_start(grdriver, grmode, errorcode);
	 setcolor(15);
	 bar(0, 0, 20, 20);
	 Size=imagesize(0, 0, 20, 20);
	 P=farmalloc(Size);
	 getimage(0, 0, 20, 20, P);
	 for(A=0; A<getmaxx()-20; A++)
	 {putimage(A, 40, P, COPY_PUT);
	 delay(5);
	 putimage(A, 40, P, NOT_PUT);
	 }
	 setfillstyle(1, 4);
	 bar(0, 21, 20, 41);
	 Size=imagesize(0, 21, 20, 41);
	 P=farmalloc(Size);
	 getimage(0, 21, 20, 41, P);
	 for(A=0; A<getmaxx()-20; A++)
	 {putimage(A, 40, P, COPY_PUT);
	 delay(5);
	 putimage(A, 40, P, XOR_PUT);
	 floodfill;
	 }





	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
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