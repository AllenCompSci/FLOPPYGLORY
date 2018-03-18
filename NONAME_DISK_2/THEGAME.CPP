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
const apstring A="CROSS";
const apstring B="BLOCK";
const apstring INS="Instructions";
const apstring INS2="In this game you place blocks on the screen where";
const apstring INS3="you want them to go as they are falling from the ";
const apstring INS4="top of the screen.";

const apstring INS6="room for more blocks.";
const apstring CON1="Controls";
const apstring CON2="You can use the left and right arrow keys to move the" ;
const apstring CON3="blocks left and right you can use the down key to ";
const apstring CON4="quickly place a block.";

//var
int grdriver, grmode, errorcode;
int I, X;
char Choice;
//proto
int keypress();
void gr_start(int&, int&, int&);
void block1 ();  // Õ               1
void block2 ();  // Õº
void block3 ();  //  
void block4 ();  // []  ÕÕ
void block5 ();  //    Õ    ÕÕ
void block6 ();  //           Õ
void block7 ();  // »Õ
void block8 ();  // Œ
void main()
{
//clrscr();
do{
	 gr_start(grdriver, grmode, errorcode);

	 //TITLE/INSTRUCTIONS

setcolor(4);
settextstyle(7,0, 100);
outtextxy(100, 100, A.c_str());
settextstyle(7,0, 100);
outtextxy(200, 200, B.c_str());
//crossblock the actual block
rectangle(300,400,320, 420);
rectangle(300,420,320,440);
rectangle(300,380,320,420);
rectangle(280,400,340, 420);
getch();
cleardevice();
//closegraph();
//instructions
settextstyle(3,0, 2);
outtextxy(50, 100, INS.c_str());
outtextxy(50, 140, INS2.c_str());
outtextxy(50, 160, INS3.c_str());
outtextxy(50, 180, INS4.c_str());

outtextxy(50, 220, INS6.c_str());
outtextxy(50, 260, CON1.c_str());
outtextxy(50, 300, CON2.c_str());
outtextxy(50, 320, CON3.c_str());
outtextxy(50, 340, CON4.c_str());

getch();

	 cleardevice();
	 randomize();




	 do{
	 if(kbhit())
			 I=keypress();
				else
				 I=0;
	 setcolor(15);
	 rectangle(100, 0, 120, 479);
	 rectangle(420, 0, 440, 479);
	 //setcolor(1);
	 line(100, 461, 420, 461);
	 switch (random(8)+1)
	 { case 1:block1();
		 break;
		 case 2: block2();
		 break;
		 case 3: block3();
		 break;
		 case 4: block4();
		 break;
		 case 5: block5();
		 break;
		 case 6: block6();
		 break;
		 case 7: block7();
		 break;
		 case 8: block8();
	 }

		}while(I!=72);


	 //rectangle(500, 40, 600, 100);
	 //rectangle(500, 350, 600, 450);
	 //line(100, 479, 440, 479);


	//cout<<"Would you like to run the Program again";
		cin>>Choice;
	}while (Choice=='Y' || Choice=='y');
}

int keypress()
	 {if(kbhit);
		 return getch();
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
void block1 ()
	 {int A,B,C,D,E,F,G,K,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(B, F, C, G);
			rectangle(C, F, D, G);
			rectangle(D, F, E, G);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(D, F, E, G);

			}
			for(Z=A+1; Z<A+79; Z++)
			 {
				if(getpixel(Z, G+1)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }


								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}





		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(D, F, E, G);
			}

		 }while(!J);










	 }
	 void block2 ()
	 {int A,B,C,D,E,F,G,K,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;


		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(B, F, C, G);
			rectangle(C, F, D, G);
			rectangle(B, F-20, C, G-20);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(B, F-20, C, G-20);

			}
			for(Z=A+1; Z<A+59; Z++)
			 {
				if(getpixel(Z, G+1)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }

								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80://if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 



		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(B, F-20, C, G-20);
			}

		 }while(!J);
		}
void block3 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;


		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(A, F-20, B, G-20);
			rectangle(B, F, C, G);
			rectangle(B, F-20, C, G-20);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(A, F-20, B, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F-20, C, G-20);

			}
			for(Z=A+1; Z<A+39; Z++)
			 {
				if(getpixel(Z, G+1)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(C<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;


		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(A, F-20, B, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F-20, C, G-20);
			}

		 }while(!J);
		}
void block4 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		K=1;
		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(B, F, C, G);
			rectangle(C, F, D, G);
			rectangle(C, F-20, D, G-20);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(C, F-20, D, G-20);

			}
			for(Z=A; Z<A+60; Z++)
			 {
				if(getpixel(Z, G+1)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(D<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;


		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(C, F-20, D, G-20);
			}

		 }while(!J);
		}
void block5 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		K=1;
		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(B, F, C, G);
			rectangle(C, F, D, G);
			rectangle(A, F-20, B, G-20);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(A, F-20, B, G-20);

			}
			for(Z=A+1; Z<A+59; Z++)
			 {
				if(getpixel(Z, G+1)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;


		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(B, F, C, G);
			 rectangle(C, F, D, G);
			 rectangle(A, F-20, B, G-20);
			}

		 }while(!J);
		}
void block6 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		K=1;
		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(A, F-20, B, G-20);
			rectangle(B, F, C, G);
			rectangle(B, F+20, C, G+20);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(A, F-20, B, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);

			}
			for(Z=B; Z<B+20; Z++)
			 {
				if(getpixel(Z, G+21)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;

		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(A, F-20, B, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);
			}

		 }while(!J);
		}
void block7 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		K=1;
		Z=0;
		J=false;
	 do{setcolor(15);
			rectangle(B, F, C, G);
			rectangle(B, F+20, C, G+20);
			rectangle(A, F+20, B, G+20);
			rectangle(A, F+40, B, G+40);
			delay(250);

			{setcolor(0);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);
			 rectangle(A, F+20, B, G+20);
			 rectangle(A, F+40, B, G+40);

			}
			//check this
			for(Z=A; Z<A+20; Z++)
			 {K=B;
				K++;
				 if(getpixel(Z, G+41)==15 || getpixel(K, G+21)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;

		 }
			if(J)
			{ setcolor(15);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);
			 rectangle(A, F+20, B, G+20);
			 rectangle(A, F+40, B, G+40);
			}

		 }while(!J);
		}

void block8 ()
	 {int A,B,C,D,E,F,G,K,W,Z,Key;
		bool J;
		A=230;
		B=250;
		C=270;
		D=290;
		E=310;
		F=0;
		G=20;

		K=1;
		Z=0;
		J=false;

		do{setcolor(15);
			rectangle(A, F, B, G);
			rectangle(B, F-20, C, G-20);
			rectangle(B, F, C, G);
			rectangle(B, F+20, C, G+20);
			rectangle(C, F, D, G);
			delay(250);

			{setcolor(0);
			 rectangle(A, F, B, G);
			 rectangle(B, F-20, C, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);
			 rectangle(C, F, D, G);

			}
			for(Z=B+1; Z<C-1; Z++)
			 {
				if(getpixel(Z, G+21)==15)
				 {J=true;
					putpixel(Z,G+1,1);
				 }
			 }
			if(!J)
			 {F+=10;
				G+=10;
			 }
			if(kbhit())
			 Key=keypress();
				else
				 Key=0;
			switch (Key)
			{case 77:if(E<400)
							 {if(getpixel(E+1, G)!=15)
								 {A+=20;
									B+=20;
									C+=20;
									D+=20;
									E+=20;
								 }
									else
									 J++;
								}
			 break;
			 case 75:if(A>140)
								{A-=20;
								 B-=20;
								 C-=20;
								 D-=20;
								 E-=20;
								}
			 break;
			 case 80:if(getpixel(E,G+1)==BLACK)
								{F+=20;
								 G+=20;
								}
								 else
									K++;


		 }
			if(J)
			{ setcolor(15);
			 rectangle(A, F, B, G);
			 rectangle(B, F-20, C, G-20);
			 rectangle(B, F, C, G);
			 rectangle(B, F+20, C, G+20);
			 rectangle(C, F, D, G);
			}

		 }while(!J);
		}










