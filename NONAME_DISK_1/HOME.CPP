//Jeff Stein
//6th Period
//Mr. Baker
//Program:
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
//#include <vector.h>
//#include <matrix.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
int Grdriver, Grmode, Errorcode;
void Graphic_Setup (int &, int &, int &);
void test ();
int Keypress ();
int midx;
int midy;
int i, z, x;
int Point;
int Key;
int Class;

char Trash[50], Name[50];
void main()
{
clrscr();

Graphic_Setup( Grdriver, Grmode, Errorcode);
setbkcolor(WHITE);
setcolor(BLUE);

rectangle (0, 0,300,475);
settextstyle(2,0,6);

outtextxy(20,50,"Character's Name?");
gotoxy(6,6);
cin>>Name
;


outtextxy(10,100,"Do you want a...");

outtextxy(30,155,"Warrior");

outtextxy(30,205,"Mage");

outtextxy(30,253,"Rogue");

//Mage= 3 14, 14 14
//Rouge=3 17, 14 17



	Point=11;
	gotoxy(3,11);
	cout<<"<";
	gotoxy(14,11);
	cout<<">";
	do{ Key=Keypress();
			switch(Key)
				{ case 72: gotoxy(3,Point);
									 cout<<" ";
									 gotoxy(14,Point);
									 cout<<" ";
									 Point=Point-3;
									 if (Point<11)
											Point=17;
									 gotoxy(3,Point);
									 cout<<'<';
									 gotoxy(14,Point);
									 cout<<'>';
									 gotoxy(3,Point);
									 break;  // Go UP

					case 80: gotoxy(3,Point);
									 cout<<" ";
									 gotoxy(14,Point);
									 cout<<" ";
									 Point=Point+3;
									 if (Point>17)
											Point=11;
									 gotoxy(3,Point);
									 cout<<'<';
									 gotoxy(14,Point);
									 cout<<'>';
									 gotoxy(3,Point);
									 break;  // Go Down

					case 13: Class=Point;
				}

		}
		while(Key!=13);





};



void test ()
{
int Point;
int Key;


	Point=3;
	gotoxy(2,3);
	cout<<"<";
	gotoxy(17,3);
	cout<<">";
	do{ Key=Keypress();
			switch(Key)
				{ case 72: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(17,Point);
									 cout<<" ";
									 Point--;
									 if (Point<3)
											Point=5;
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(17,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go UP

					case 80: gotoxy(2,Point);
									 cout<<" ";
									 gotoxy(17,Point);
									 cout<<" ";
									 Point++;
									 if (Point>5)
											Point=3;
									 gotoxy(2,Point);
									 cout<<'<';
									 gotoxy(17,Point);
									 cout<<'>';
									 gotoxy(2,Point);
									 break;  // Go Down
					case 77: cout<<"right"<<endl;break;
					//case 75: cout<<"left"<<endl;break;
					//case 13: Ship_Type=Point-2;
				}

		}
		while(Key!=13);

	}


void Graphic_Setup (int & Grdriver,int & Grmode,int & Errorcode)
	{
		Grdriver = VGA;
		Grmode = VGAHI;
		initgraph(&Grdriver, &Grmode, "C:\\TC\\BGI");
		Errorcode = graphresult();

		if (Errorcode !=grOk)
			{
				clrscr();
				cout<<"Graphic Error"<<endl;
				getch();
				exit(1);
			}
	}
int Keypress ()
{
while (!kbhit());
return getch();
}



