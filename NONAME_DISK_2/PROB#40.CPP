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
long A;
int grdriver, grmode, errorcode;
char Choice;
//proto
void gr_start(int&, int&, int&);
void main()
{clrscr();
do{
	 gr_start(grdriver, grmode, errorcode);
	 setgraphmode(getgraphmode());
	 rectangle(20, 450, 200, 250);
	 line(100, 50, 300, 50);
	 line(100, 200, 300, 200);
	 line(100, 50, 100, 200);
	 line(300, 50, 300, 200);
	 for(A=300; A<450; A++)
	 putpixel(350, A, 1);
	 for(A=350; A<500; A++)
	 putpixel(A, 300, 1);
	 for(A=300; A<450; A++)
	 putpixel(500, A, 1);
	 for(A=350; A<500; A++)
	 putpixel(A, 450, 1);
	 line(150, 90, 150, 150);
	 arc(130, 150, 180, 360, 20);
		arc(100, 300, 70, 270, 30);
	 arc(100, 360, 230, 450, 30);

	 line(375, 315, 375, 435);
	 line(375, 375, 425, 375);
	 line(425, 315, 425, 435);



	cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}

void gr_start(int &grdriver,int &grmode, int &errorcode)
{grdriver=VGA;
 grmode=VGAHI;

 initgraph(&grdriver, &grmode,"C:\\TC\\BGI");
 errorcode=graphresult();

 if(errorcode!=graphresult())
	 {clrscr();
		cout<<"Error"<<errorcode<<endl;
		cout<<"Press Return to continue";
		getch();
		exit(1);
	 }

}