//John Harvey
//User Placement of Ships and mines
//Period 3
//library Section
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <fstream.h>
#include <graphics.h>
#include <bitmap.h>
#include <Gmouse.cpp>

//VARIABLE REFERENCE LIBRARY
/*
GLOBAL SECTION:
	int grdriver,grmode,errorcode: these variables run the graphics mode function
	image screen: this is the background the user sees as the map, panel, and logo


USER_SCREEN_CREATOR (LOCAL):
	int I: I is the for-loop operator variable and also is used throughtout
				the function as a reference point for the grid that is overlaid on the
				map

	apstring AB: AB is the AlphaBet letters used on the side of the screen
						vertically on the map. it runs as so: ABCDEFGHIJKLMNOP, 16 in all

USER_PLACE (LOCAL):
	int X,Y: X and Y are the primary variables, and they are used as the mouse
					button click coordinates when the mouse is clicked on the screen.
					they are used to return the values of the mouse, set limitations
					in Do-While loops used in the function, and also as a reference
					point for if-else statements.
					X and Y are also used at the start of the function to set Chk to
					false.

	int D,E: D and E are the primary variables for the function to reference
					from when it searched for the Spot[E][D] name, which is the
					designation seen by the user, ex: A1. D and E are used to draw
					circle and dots on the screen with the formula provided for ship
					placement.

	int ShipSel: ShipSel stands for Ship Selection, which in turn has the
							value of the ship being used, for example a carrier has 5, but
							a battleship has 4

	int H,I: These two variables run the for loops inside this function

	int V,W: The V and W are the E and D for the second click of the user,
					where the V and W represent the element of the array the user
					has selected for his direction of his ship.

	int Time: Time is the variable counter that stops the user from putting
						more than five ships onto the board.

	double XMax,YMax: These two variables are the ones used in the formula
									for finding the selected element on the grid, bool and
									apstring arrays.

	bool Exit1,Exit2,Exit3: these three exits are used for the do-while and if
													statements and tell the computer to end specific
													operations.

	bool Dchk,Car,Bat,Cru,Ub,Des: These bool variables tell the computer to end
																the current do-while loop so that the user
																does not have an error in selecting his/her
																desired ship.

	apmatrix Spot: is the grid with all the names of the elements, ie "A1"

	apmatrix Chk: Chk is the bool array overlaying the Spot array and prevents
								multiple ships from occupying one space on the map.





*/
//Constant Section


//Struct


//Global Variable Section
int grdriver,grmode,errorcode;
image Screen;
bool ShipSet;

//Prototype
//This function begins graphics mode
void gr_start(int&,int&,int&);
//creates the user map screen and graphics
void allied_screen_make();
//allows the user to place their ships onto the map.
void user_place();




//Main Section
void main()
{
clrscr();
gr_start(grdriver,grmode,errorcode);
allied_screen_make();
user_place();
getch();
}

//End Void Main
//***************************************************************************
//Function 1
void gr_start(int&grdriver,int&grmode,int&errorcode)
{grdriver=VGA;
grmode=VGAHI;
initgraph(&grdriver,&grmode,"c:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
	{clrscr();
	cout<<"ERROR:"<<errorcode<<endl;
	cout<<"Press return to continue";
	getch();
	exit(1);
	}
};

//User Screen creator
void allied_screen_make()
{int I;
apstring AB;
graphinit(GR16);
Screen.open("a:\\USSC.bmp");
Screen.draw(0,0);
Screen.close();
setcolor(0);
line(110,110,110,getmaxy());
for(I=0;I<23;I++)
		{setcolor(0);
		line(110+(I*23),110,110+(I*23),getmaxy());
		line(110,110+(I*23),getmaxx(),110+(I*23));
		setcolor(7);
		outtextxy(100,115,"A");
		outtextxy(100,138,"B");
		outtextxy(100,161,"C");
		outtextxy(100,184,"D");
		outtextxy(100,207,"E");
		outtextxy(100,230,"F");
		outtextxy(100,253,"G");
		outtextxy(100,276,"H");
		outtextxy(100,299,"I");
		outtextxy(100,322,"J");
		outtextxy(100,345,"K");
		outtextxy(100,368,"L");
		outtextxy(100,391,"M");
		outtextxy(100,414,"N");
		outtextxy(100,437,"O");
		outtextxy(100,460,"P");
		}
setcolor(11);
outtextxy(110,100," 1  2  3  4  5  6  7  8  9");
outtextxy(322,100,"10 11 12 13 14 15 16");
outtextxy(482,100,"17 18 19 20 21 22");
outtextxy(620,100,"23");
setcolor(6);
outtextxy(40,100,"US");
outtextxy(26,111,"CARRIER");
setfillstyle(1,1);
bar(26,120,35,130);
setfillstyle(1,9);
bar(36,120,48,130);
setfillstyle(1,11);
bar(49,120,60,130);
setfillstyle(1,10);
bar(61,120,72,130);
setfillstyle(1,2);
bar(73,120,85,130);
outtextxy(26,135,"GUNSHIP");
setfillstyle(1,1);
bar(26,145,35,155);
setfillstyle(1,9);
bar(36,145,48,155);
setfillstyle(1,11);
bar(49,145,60,155);
setfillstyle(1,2);
bar(61,145,72,155);
outtextxy(26,160,"CRUISER");
setfillstyle(1,9);
bar(26,170,35,180);
setfillstyle(1,11);
bar(36,170,48,180);
setfillstyle(1,10);
bar(49,170,60,180);
outtextxy(26,185,"U-BOAT");
setfillstyle(1,9);
bar(26,195,35,205);
setfillstyle(1,11);
bar(36,195,48,205);
setfillstyle(1,10);
bar(49,195,60,205);
outtextxy(26,210,"AEGIS");
setfillstyle(1,9);
bar(26,220,35,230);
setfillstyle(1,10);
bar(36,220,48,230);
setcolor(9);
line(24,235,88,235);
setcolor(13);
outtextxy(40,240,"THEM");
setcolor(10);
outtextxy(26,250,"CARRIER");
outtextxy(26,270,"GUNSHIP");
outtextxy(26,290,"CRUISER");
outtextxy(26,310,"U-BOAT");
outtextxy(26,330,"AEGIS");
setcolor(15);
outtextxy(26,360,"TARGET:");
setcolor(14);
outtextxy(26,390,"FIRE CTL");
setcolor(1);
outtextxy(30,415,"SHOOT?");

setcolor(9);
circle(40,435,10);
outtextxy(36,430,"Y");
setcolor(11);
circle(70,435,10);
outtextxy(66,430,"N");


};

//user_place allows the user to coordinate and place vessels
void user_place()
{int X,Y,D,E,ShipSel,H,I,V,W,Time;
double XMax,YMax;
bool Exit1,Exit2,Exit3,Dchk,Car,Bat,Cru,Ub,Des;
apstring AB="ABCDEFGHIJKLMNOP";
apmatrix<apstring> Spot(23,16);
apmatrix<bool> Chk(24,17);
Car=true;
Bat=true;
Cru=true;
Ub=true;
Des=true;
for(X=0;X<23;X++)
	{for(Y=0;Y<16;Y++)
		{Chk[X][Y]=false;
		}
	}

Spot[0][0]="A1 ";
Spot[0][1]="B1 ";
Spot[0][2]="C1 ";
Spot[0][3]="D1 ";
Spot[0][4]="E1 ";
Spot[0][5]="F1 ";
Spot[0][6]="G1 ";
Spot[0][7]="H1 ";
Spot[0][8]="I1 ";
Spot[0][9]="J1 ";
Spot[0][10]="K1 ";
Spot[0][11]="L1 ";
Spot[0][12]="M1 ";
Spot[0][13]="N1 ";
Spot[0][14]="O1 ";
Spot[0][15]="P1 ";

Spot[1][0]="A2 ";
Spot[1][1]="B2 ";
Spot[1][2]="C2 ";
Spot[1][3]="D2 ";
Spot[1][4]="E2 ";
Spot[1][5]="F2 ";
Spot[1][6]="G2 ";
Spot[1][7]="H2 ";
Spot[1][8]="I2 ";
Spot[1][9]="J2 ";
Spot[1][10]="K2 ";
Spot[1][11]="L2 ";
Spot[1][12]="M2 ";
Spot[1][13]="N2 ";
Spot[1][14]="O2 ";
Spot[1][15]="P2 ";

Spot[2][0]="A3 ";
Spot[2][1]="B3 ";
Spot[2][2]="C3 ";
Spot[2][3]="D3 ";
Spot[2][4]="E3 ";
Spot[2][5]="F3 ";
Spot[2][6]="G3 ";
Spot[2][7]="H3 ";
Spot[2][8]="I3 ";
Spot[2][9]="J3 ";
Spot[2][10]="K3 ";
Spot[2][11]="L3 ";
Spot[2][12]="M3 ";
Spot[2][13]="N3 ";
Spot[2][14]="O3 ";
Spot[2][15]="P3 ";

Spot[3][0]="A4 ";
Spot[3][1]="B4 ";
Spot[3][2]="C4 ";
Spot[3][3]="D4 ";
Spot[3][4]="E4 ";
Spot[3][5]="F4 ";
Spot[3][6]="G4 ";
Spot[3][7]="H4 ";
Spot[3][8]="I4 ";
Spot[3][9]="J4 ";
Spot[3][10]="K4 ";
Spot[3][11]="L4 ";
Spot[3][12]="M4 ";
Spot[3][13]="N4 ";
Spot[3][14]="O4 ";
Spot[3][15]="P4 ";

Spot[4][0]="A5 ";
Spot[4][1]="B5 ";
Spot[4][2]="C5 ";
Spot[4][3]="D5 ";
Spot[4][4]="E5 ";
Spot[4][5]="F5 ";
Spot[4][6]="G5 ";
Spot[4][7]="H5 ";
Spot[4][8]="I5 ";
Spot[4][9]="J5 ";
Spot[4][10]="K5 ";
Spot[4][11]="L5 ";
Spot[4][12]="M5 ";
Spot[4][13]="N5 ";
Spot[4][14]="O5 ";
Spot[4][15]="P5 ";

Spot[5][0]="A6 ";
Spot[5][1]="B6 ";
Spot[5][2]="C6 ";
Spot[5][3]="D6 ";
Spot[5][4]="E6 ";
Spot[5][5]="F6 ";
Spot[5][6]="G6 ";
Spot[5][7]="H6 ";
Spot[5][8]="I6 ";
Spot[5][9]="J6 ";
Spot[5][10]="K6 ";
Spot[5][11]="L6 ";
Spot[5][12]="M6 ";
Spot[5][13]="N6 ";
Spot[5][14]="O6 ";
Spot[5][15]="P6 ";

Spot[6][0]="A7 ";
Spot[6][1]="B7 ";
Spot[6][2]="C7 ";
Spot[6][3]="D7 ";
Spot[6][4]="E7 ";
Spot[6][5]="F7 ";
Spot[6][6]="G7 ";
Spot[6][7]="H7 ";
Spot[6][8]="I7 ";
Spot[6][9]="J7 ";
Spot[6][10]="K7 ";
Spot[6][11]="L7 ";
Spot[6][12]="M7 ";
Spot[6][13]="N7 ";
Spot[6][14]="O7 ";
Spot[6][15]="P7 ";

Spot[7][0]="A8 ";
Spot[7][1]="B8 ";
Spot[7][2]="C8 ";
Spot[7][3]="D8 ";
Spot[7][4]="E8 ";
Spot[7][5]="F8 ";
Spot[7][6]="G8 ";
Spot[7][7]="H8 ";
Spot[7][8]="I8 ";
Spot[7][9]="J8 ";
Spot[7][10]="K8 ";
Spot[7][11]="L8 ";
Spot[7][12]="M8 ";
Spot[7][13]="N8 ";
Spot[7][14]="O8 ";
Spot[7][15]="P8 ";

Spot[8][0]="A9 ";
Spot[8][1]="B9 ";
Spot[8][2]="C9 ";
Spot[8][3]="D9 ";
Spot[8][4]="E9 ";
Spot[8][5]="F9 ";
Spot[8][6]="G9 ";
Spot[8][7]="H9 ";
Spot[8][8]="I9 ";
Spot[8][9]="J9 ";
Spot[8][10]="K9 ";
Spot[8][11]="L9 ";
Spot[8][12]="M9 ";
Spot[8][13]="N9 ";
Spot[8][14]="O9 ";
Spot[8][15]="P9 ";

Spot[9][0]="A10";
Spot[9][1]="B10";
Spot[9][2]="C10";
Spot[9][3]="D10";
Spot[9][4]="E10";
Spot[9][5]="F10";
Spot[9][6]="G10";
Spot[9][7]="H10";
Spot[9][8]="I10";
Spot[9][9]="J10";
Spot[9][10]="K10";
Spot[9][11]="L10";
Spot[9][12]="M10";
Spot[9][13]="N10";
Spot[9][14]="O10";
Spot[9][15]="P10";

Spot[10][0]="A11";
Spot[10][1]="B11";
Spot[10][2]="C11";
Spot[10][3]="D11";
Spot[10][4]="E11";
Spot[10][5]="F11";
Spot[10][6]="G11";
Spot[10][7]="H11";
Spot[10][8]="I11";
Spot[10][9]="J11";
Spot[10][10]="K11";
Spot[10][11]="L11";
Spot[10][12]="M11";
Spot[10][13]="N11";
Spot[10][14]="O11";
Spot[10][15]="P11";

Spot[11][0]="A12";
Spot[11][1]="B12";
Spot[11][2]="C12";
Spot[11][3]="D12";
Spot[11][4]="E12";
Spot[11][5]="F12";
Spot[11][6]="G12";
Spot[11][7]="H12";
Spot[11][8]="I12";
Spot[11][9]="J12";
Spot[11][10]="K12";
Spot[11][11]="L12";
Spot[11][12]="M12";
Spot[11][13]="N12";
Spot[11][14]="O12";
Spot[11][15]="P12";

Spot[12][0]="A13";
Spot[12][1]="B13";
Spot[12][2]="C13";
Spot[12][3]="D13";
Spot[12][4]="E13";
Spot[12][5]="F13";
Spot[12][6]="G13";
Spot[12][7]="H13";
Spot[12][8]="I13";
Spot[12][9]="J13";
Spot[12][10]="K13";
Spot[12][11]="L13";
Spot[12][12]="M13";
Spot[12][13]="N13";
Spot[12][14]="O13";
Spot[12][15]="P13";

Spot[13][0]="A14";
Spot[13][1]="B14";
Spot[13][2]="C14";
Spot[13][3]="D14";
Spot[13][4]="E14";
Spot[13][5]="F14";
Spot[13][6]="G14";
Spot[13][7]="H14";
Spot[13][8]="I14";
Spot[13][9]="J14";
Spot[13][10]="K14";
Spot[13][11]="L14";
Spot[13][12]="M14";
Spot[13][13]="N14";
Spot[13][14]="O14";
Spot[13][15]="P14";

Spot[14][0]="A15";
Spot[14][1]="B15";
Spot[14][2]="C15";
Spot[14][3]="D15";
Spot[14][4]="E15";
Spot[14][5]="F15";
Spot[14][6]="G15";
Spot[14][7]="H15";
Spot[14][8]="I15";
Spot[14][9]="J15";
Spot[14][10]="K15";
Spot[14][11]="L15";
Spot[14][12]="M15";
Spot[14][13]="N15";
Spot[14][14]="O15";
Spot[14][15]="P15";

Spot[15][0]="A16";
Spot[15][1]="B16";
Spot[15][2]="C16";
Spot[15][3]="D16";
Spot[15][4]="E16";
Spot[15][5]="F16";
Spot[15][6]="G16";
Spot[15][7]="H16";
Spot[15][8]="I16";
Spot[15][9]="J16";
Spot[15][10]="K16";
Spot[15][11]="L16";
Spot[15][12]="M16";
Spot[15][13]="N16";
Spot[15][14]="O16";
Spot[15][15]="P16";

Spot[16][0]="A17";
Spot[16][1]="B17";
Spot[16][2]="C17";
Spot[16][3]="D17";
Spot[16][4]="E17";
Spot[16][5]="F17";
Spot[16][6]="G17";
Spot[16][7]="H17";
Spot[16][8]="I17";
Spot[16][9]="J17";
Spot[16][10]="K17";
Spot[16][11]="L17";
Spot[16][12]="M17";
Spot[16][13]="N17";
Spot[16][14]="O17";
Spot[16][15]="P17";

Spot[17][0]="A18";
Spot[17][1]="B18";
Spot[17][2]="C18";
Spot[17][3]="D18";
Spot[17][4]="E18";
Spot[17][5]="F18";
Spot[17][6]="G18";
Spot[17][7]="H18";
Spot[17][8]="I18";
Spot[17][9]="J18";
Spot[17][10]="K18";
Spot[17][11]="L18";
Spot[17][12]="M18";
Spot[17][13]="N18";
Spot[17][14]="O18";
Spot[17][15]="P18";

Spot[18][0]="A19";
Spot[18][1]="B19";
Spot[18][2]="C19";
Spot[18][3]="D19";
Spot[18][4]="E19";
Spot[18][5]="F19";
Spot[18][6]="G19";
Spot[18][7]="H19";
Spot[18][8]="I19";
Spot[18][9]="J19";
Spot[18][10]="K19";
Spot[18][11]="L19";
Spot[18][12]="M19";
Spot[18][13]="N19";
Spot[18][14]="O19";
Spot[18][15]="P19";

Spot[19][0]="A20";
Spot[19][1]="B20";
Spot[19][2]="C20";
Spot[19][3]="D20";
Spot[19][4]="E20";
Spot[19][5]="F20";
Spot[19][6]="G20";
Spot[19][7]="H20";
Spot[19][8]="I20";
Spot[19][9]="J20";
Spot[19][10]="K20";
Spot[19][11]="L20";
Spot[19][12]="M20";
Spot[19][13]="N20";
Spot[19][14]="O20";
Spot[19][15]="P20";

Spot[20][0]="A21";
Spot[20][1]="B21";
Spot[20][2]="C21";
Spot[20][3]="D21";
Spot[20][4]="E21";
Spot[20][5]="F21";
Spot[20][6]="G21";
Spot[20][7]="H21";
Spot[20][8]="I21";
Spot[20][9]="J21";
Spot[20][10]="K21";
Spot[20][11]="L21";
Spot[20][12]="M21";
Spot[20][13]="N21";
Spot[20][14]="O21";
Spot[20][15]="P21";

Spot[21][0]="A22";
Spot[21][1]="B22";
Spot[21][2]="C22";
Spot[21][3]="D22";
Spot[21][4]="E22";
Spot[21][5]="F22";
Spot[21][6]="G22";
Spot[21][7]="H22";
Spot[21][8]="I22";
Spot[21][9]="J22";
Spot[21][10]="K22";
Spot[21][11]="L22";
Spot[21][12]="M22";
Spot[21][13]="N22";
Spot[21][14]="O22";
Spot[21][15]="P22";

Spot[22][0]="A23";
Spot[22][1]="B23";
Spot[22][2]="C23";
Spot[22][3]="D23";
Spot[22][4]="E23";
Spot[22][5]="F23";
Spot[22][6]="G23";
Spot[22][7]="H23";
Spot[22][8]="I23";
Spot[22][9]="J23";
Spot[22][10]="K23";
Spot[22][11]="L23";
Spot[22][12]="M23";
Spot[22][13]="N23";
Spot[22][14]="O23";
Spot[22][15]="P23";
Time=0;
do{
	Exit1=true;
	Exit2=false;
	Exit3=false;
	ShowMouse();
	if(Exit1&&Time<5)
	do{
		while(GetMouseButton()==0);
		X=GetMouseX();
		Y=GetMouseY();
		if((X>22&&X<90)&&(Y>109&&Y<130)&&Car)
				 {ShipSel=5;
				 setcolor(10);
				 outtextxy(12,112,"*");
				 Exit1=false;
				 Time++;
				 Car=false;
				 }
			 if((X>22&&X<90)&&(Y>134&&Y<156)&&Bat)
								{ShipSel=4;
								setcolor(10);
								outtextxy(12,142,"*");
								Exit1=false;
								Time++;
								Bat=false;
								}
						 if((X>22&&X<90)&&(Y>159&&Y<180)&&Cru)
										{ShipSel=3;
										setcolor(10);
										outtextxy(12,172,"*");
										Exit1=false;
										Time++;
										Cru=false;
										}
									if((X>22&&X<90)&&(Y>184&&Y<205)&&Ub)
													{ShipSel=3;
													setcolor(10);
													outtextxy(12,192,"*");
													Exit1=false;
													Time++;
													Ub=false;
													}
													if((X>22&&X<90)&&(Y>207&&Y<233)&&Des)
																{ShipSel=2;
																setcolor(10);
																outtextxy(12,219,"*");
																Exit1=false;
																Time++;
																Des=false;
																}






		}while(((X>90||X<21)||(Y<108))&&Exit1);

		do{
			while(GetMouseButton()==0);
			X=GetMouseX();
			Y=GetMouseY();
			if(X>110&&Y>110)
				{XMax=0;
				XMax=(X-111);
				E=0;
				XMax/=23;
				E=int(XMax);
				YMax=0;
				YMax=(Y-111);
				D=0;
				YMax/=23;
				D=int(YMax);
				gotoxy(6,24);
				cout<<Spot[E][D];
				Chk[E][D]=true;
				HideMouse();
				setcolor(8);
				circle((((E+1)*23)+98),(((D+1)*23)+98),9);
				setfillstyle(1,8);
				floodfill((((E+1)*23)+98),(((D+1)*23)+98),8);
				//Left to right

					if(E+ShipSel<=23)
						{ Dchk=false;
							for(H=0;H<ShipSel;H++)
								if(Chk[E+H][D]&&Dchk)
									Dchk=true;
							if(!Dchk)
								for(H=0;H<ShipSel;H++)
									{
									circle((((E+ShipSel)*23)+98),(((D+1)*23)+98),9);
									setfillstyle(1,8);
									floodfill((((E+ShipSel)*23)+98),(((D+1)*23)+98),8);

									}

						}



			 //Right to left

				if(E-ShipSel+1>=0)
						{ Dchk=false;
							for(H=0;H<ShipSel;H++)
								if(Chk[E-H][D]&&Dchk)
									Dchk=true;
							if(!Dchk)
								for(H=0;H<ShipSel;H++)
									{
									circle((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),9);
									setfillstyle(1,8);
									floodfill((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),8);

									}

						}

			//Top to bottom
			if(D+ShipSel<=16)
						{ Dchk=false;
							for(H=0;H<ShipSel;H++)
								if(Chk[E][D+H]&&Dchk)
									Dchk=true;
							if(!Dchk)
								for(H=0;H<ShipSel;H++)
									{
									circle((((E+1)*23)+98),(((D+ShipSel)*23)+98),9);
									setfillstyle(1,8);
									floodfill((((E+1)*23)+98),(((D+ShipSel)*23)+98),8);

									}

						}


			//Bottom To Top
			if(D-ShipSel+1>=0)
						{ Dchk=false;
							for(H=0;H<ShipSel;H++)
								if(Chk[E][D-H]&&Dchk)
									Dchk=true;
							if(!Dchk)
								for(H=0;H<ShipSel;H++)
									{
									circle((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),9);
									setfillstyle(1,8);
									floodfill((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),8);

									}

						}
				Exit2=true;
				}
			 }while((X<110||Y<110||!Exit2));
	 do{ShowMouse();
		while(GetMouseButton()==0);
		{X=GetMouseX();
		Y=GetMouseY();
		}
		if(X>110&&Y>110)
			{XMax=0;
			XMax=(X-111);
			V=0;
			XMax/=23;
			V=int(XMax);
			YMax=0;
			YMax=(Y-111);
			W=0;
			YMax/=23;
			W=int(YMax);
			Chk[V][W]=true;

		if(V==E+ShipSel-1&&W==D)
				{HideMouse();
				setcolor(14);
			 if((E-ShipSel+2)>0)
				{circle((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),14);
				}

				circle((((E+1)*23)+98),(((D+ShipSel)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E+1)*23)+98),(((D+ShipSel)*23)+98),14);

			 if((D-ShipSel+2)>0)
				{circle((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),14);
				}
				for(I=E;I<V;I++)
					{Chk[I][W]=true;
					setcolor(8);
					circle((((I+1)*23)+98),(((D+1)*23)+98),9);
					setfillstyle(1,8);
					floodfill((((I+1)*23)+98),(((D+1)*23)+98),8);
					}
					ShowMouse();
				Exit3=true;
				}
		else {if(V==E-ShipSel+1&&W==D)
				{HideMouse();
				setcolor(14);

				circle((((E+ShipSel)*23)+98),(((D+1)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E+ShipSel)*23)+98),(((D+1)*23)+98),14);


				circle((((E+1)*23)+98),(((D+ShipSel)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E+1)*23)+98),(((D+ShipSel)*23)+98),14);

			 if((D-ShipSel+2)>0)
				{circle((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),9);
				setfillstyle(1,14);
				floodfill((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),14);
				}
				for(I=V;I<E;I++)
					{Chk[I][W]=true;
					setcolor(8);
					circle((((I+1)*23)+98),(((D+1)*23)+98),9);
					setfillstyle(1,8);
					floodfill((((I+1)*23)+98),(((D+1)*23)+98),8);
					}
					ShowMouse();
					Exit3=true;
				}
				else {if(V==E&&W==D+ShipSel-1)
						{HideMouse();
						setcolor(14);

						circle((((E+ShipSel)*23)+98),(((D+1)*23)+98),9);
						setfillstyle(1,14);
						floodfill((((E+ShipSel)*23)+98),(((D+1)*23)+98),14);

						setcolor(14);
					 if((E-ShipSel+2)>0)
						{circle((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),9);
						setfillstyle(1,14);
						floodfill((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),14);
						}
					if((D-ShipSel+2)>0)
						{circle((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),9);
						setfillstyle(1,14);
						floodfill((((E+1)*23)+98),(((D-ShipSel+2)*23)+98),14);
						}
						for(I=D;I<W;I++)
							{Chk[V][I]=true;
							setcolor(8);
							circle((((E+1)*23)+98),(((I+1)*23)+98),9);
							setfillstyle(1,8);
							floodfill((((E+1)*23)+98),(((I+1)*23)+98),8);
							}
							ShowMouse();
							Exit3=true;
						}
						else	{if(V==E&&W==D-ShipSel+1)
										{HideMouse();
										setcolor(14);

										circle((((E+ShipSel)*23)+98),(((D+1)*23)+98),9);
										setfillstyle(1,14);
										floodfill((((E+ShipSel)*23)+98),(((D+1)*23)+98),14);

										setcolor(14);
									 if((E-ShipSel+2)>0)
										{circle((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),9);
										setfillstyle(1,14);
										floodfill((((E-ShipSel+2)*23)+98),(((D+1)*23)+98),14);
										}

										circle((((E+1)*23)+98),(((D+ShipSel)*23)+98),9);
										setfillstyle(1,14);
										floodfill((((E+1)*23)+98),(((D+ShipSel)*23)+98),14);

										for(I=W;I<D;I++)
											{Chk[V][I]=true;
											setcolor(8);
											circle((((E+1)*23)+98),(((I+1)*23)+98),9);
											setfillstyle(1,8);
											floodfill((((E+1)*23)+98),(((I+1)*23)+98),8);
											}
											ShowMouse();
											Exit3=true;
										}
									}
						 }
				}

		 }

	 }while(!Exit3);
	//end if
	X=0;
	Y=0;
	XMax=0;
	YMax=0;
	V=0;
	W=0;
	I=0;
	H=0;
 }while(Time<5);


};

/op
