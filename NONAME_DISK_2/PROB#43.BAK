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
int A,B;
int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void main()
{clrscr();
do{;
	 gr_start(grdriver, grmode, errorcode);
	 circle(40, 40, 7);

	 do{


	 for(A=40; A<632; A++)
	 {setcolor(0);
	 circle(A, 40, 7);
	 setcolor(15);
	 circle(A+1, 40, 7);
		delay(5);
	 }
	 for(A=632; A>320; A--)
	 {for(B=40; B<472; B++)
	 {	setcolor(0);
	 circle(A, B, 7);
	 setcolor(15);
	 circle(A+1, B+1, 7);
	 delay(5);
	 }
	 }
	 }while(!kbhit());





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