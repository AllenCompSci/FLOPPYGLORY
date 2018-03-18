//Jeremy Higgins and Aaron Crutcher
//5-20-2002
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
int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void block1 ();  // Õ
void block2 ();  // Õº
void block3 ();  //  
void block4 ();  // []  ÕÕ
void block5 ();  //    Õ    ÕÕ
void block6 ();  //           Õ
void block7 ();  // »Õ
void block8 ();  // Œ

void main()
{clrscr();
do{
	 gr_start(grdriver, grmode, errorcode);

	 setcolor(1);
	 rectangle(100, 0, 120, 479);
	 rectangle(420, 0, 440, 479);
	 rectangle(520, 20, 560, 40);



	//cout<<"Would you like to run the Program again";
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
//void block1 ()
	// {



