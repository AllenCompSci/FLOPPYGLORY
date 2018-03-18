//Comments Section
//Allison Arnold-Roksandich
//Mastermind
//4th Period
/*********************\
This program allows the user to play mastermind, a logic game that is used to
break color based codes. There are 36 levels that increase by slots or colors
each level. There is a maximum of 9 slots that resets and adds a new color
once the maximum is reached. There is a maximum of 10 colors.
\*********************/

//Library
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>
#include<iostream.h>
#include"math2.h"

//Const Section

//Struct Section
struct Scoring
{
int Pro;
apstring User;
};

/***VARIABLE DICTIONARY***\
Redo - loops the menu selection when another key outside of the keys used is
				pressed
X - Level Counter
Complete - put user through a level and recieves whether the level is finished
						or not
Key - collects what key is pressed by the user
GrDriver, GrMode,ErrorCode - graphics variables
\*************************/
//Global Variable Section
bool Redo,Complete;
int X,Select,GrDriver,GrMode,ErrorCode,Key;

//Prototype Section
void gr_start(int&,int&,int&);
void menu();
bool level(int);
void play(int&,int,int,int);
void solgen(apvector <int>&, long, long);
bool check(apvector <int>&, apvector <int>&, int, int);
void scorei(int);
void scored();
void readme();

//Main Section
void main()
{
randomize();
gr_start(GrDriver,GrMode,ErrorCode);
do{
	//Menu
	do{
		menu();
		Key=getch();
		switch(Key) //Menu selection Area
			{
			case 49:	//Game Play
								X=36;
								do{
									Complete=level(X);
									if(Complete==true)
										{
										delay(500);
										cleardevice();
										outtextxy(320,240,"Level Complete");

										outtextxy(320,280,"Press enter to go to the next level");
										getch();
										X++;
										if(X==37)
											{
											//Congrats
											cleardevice();
											outtextxy(320,240,"Congradulations! You win the game.");
											outtextxy(320,280,"Press enter to continue");
											getch();
											scorei(36);
											scored();
											cout<<endl;
											}
										}
									else
										{
										cleardevice();
										outtextxy(320,240,"Game Over");
										outtextxy(320,280,"Press enter to return to the menu");
										getch();
										scorei(X);
										scored();
										X=1;
										}
									}while(Complete==true&&X<37);
								Redo=true;
								break;
			case 50:	//Instructions
								readme();
								Redo=true;
								break;
			case 51:	//Hi-Scores
								scored();
								Redo=true;
								break;
			case 52:	//Quit
								Redo=false;
								break;
			default: 	Redo=true;
			}
		}while(Redo==true);
	setfillstyle(0,0);
	setcolor(4);
	bar(220,190,420,290);
	rectangle(220,190,420,290);
	settextstyle(0,0,0);
	outtextxy(320,220,"Are you sure you");
	outtextxy(320,230,"want to quit?");
	outtextxy(320,270,"Y or N");
	Key=getch();
	}while(Key!=121&&Key!=89);
}//end Main
/***GRAPHICS MODE***\
gr_start allows for graphics mode
\*******************/
void gr_start(int&GrDriver,int&GrMode,int&ErrorCode)
{
GrDriver=VGA;
GrMode=VGAHI;
initgraph(&GrDriver,&GrMode,"C:\\TC\\BGI");
ErrorCode=graphresult();
if(ErrorCode!=grOk)
	{
	clrscr();
	cout<<"ErrorCode: "<<ErrorCode;
	getch();
	exit(1);
	}
}//end function
/*******LEVEL*******\
Runs the game level by setting the game board, and sending out for a solution,
user guesses, and checks.

VARIABLE DICTIONARY
Num - same as X in the global mods
Add - how much is added to 3 in order to produce the slot number
Slot - the number of slots on a level
Color - the number of colors used on a level
L,R - loop variables
Result - tells is the level was completed; value is returned to equal Complete
Solution - holds the solution to the level;
Guess - holds the users guess
\*******************/
bool level(int Num)
{
//Local Vars
int Add,Slot,Color,L,R;
bool Result;
apvector <int> Solution (4);
apvector <int> Guess (4);

cleardevice();
setfillstyle(1,14);
bar(100,10,550,470);
setlinestyle(0,1,4);
line(300,15,300,465);
line (400,15,400,465);
outtextxy(475,200,"Color");
outtextxy(475,50,"Level");
outtextxy(475,70,itos(Num).c_str());
Result=true;
if(Num%6==0)
	Slot=9;
else
	{
	Add=Num%6;
	Slot=3+Add;
	}
setcolor(0);
setlinestyle(0,1,1);
for(L=0;L<10;L++)
	for(R=0;R<Slot;R++)
		{
		circle(110+20*R,20+40*L,5);
		circle(310+10*R,20+40*L,3);
		}
Color=5+((Num-1)-(Num-1)%6)/6;
for(L=0;L<Color;L++)
	{
	setfillstyle(1,L+1);
	setcolor(L+1);
	fillellipse(545-25*(5-L%5),250+25*((L-L%5)/5),10,10);
	setcolor(15);
	if(L!=9)
		R=L+1;
	else
		R=0;
	settextstyle(1,0,1);
	outtextxy(545-25*(5-L%5),245+25*((L-L%5)/5),itos(R).c_str());
	}
setcolor(8);
Solution.resize(Slot);
Guess.resize(Slot);
solgen(Solution, Slot, Color);
R=1;
do{
	for(L=0;L<Slot;L++)
		play(Guess[L],L,R-1,Color);
	Result=check(Guess, Solution, Slot,R-1);
	R++;
	}while(Result==false&&R<11);

return Result;
}
/*******PLAY********\
Allows a user to submit their guess for a specific slot on the level

VARIABLE DICTIONARY
Guessing - the current slot that is being guessed about
O - brought in from L in level function, used to tell where peg graphic goes
Row - brought in from R in level function, used to tell where peg graphic goes
CColor - user input for what color they want to use on the level
					(aka. "Current Color")
Max - maximum number of color selection
DoOver - loops selection process for when an extrenuous key is pressed
\*******************/
void play(int&Guessing, int O, int Row,int Max)
{
//Local Vars
int CColor;
bool DoOver;
do{
	CColor=getch();
	if(CColor>49+Max-1||(Max<10&&CColor==48))
		CColor=1;
	switch(CColor)
		{
		case 49:  Guessing=1;
							setfillstyle(1,1);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 50:  Guessing=2;
							setfillstyle(1,2);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 51:  Guessing=3;
							setfillstyle(1,3);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 52:  Guessing=4;
							setfillstyle(1,4);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 53:  Guessing=5;
							setfillstyle(1,5);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 54:  Guessing=6;
							setfillstyle(1,6);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 55:  Guessing=7;
							setfillstyle(1,7);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 56:  Guessing=8;
							setfillstyle(1,8);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 57:  Guessing=9;
							setfillstyle(1,9);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		case 48:  Guessing=10;
							setfillstyle(1,10);
							fillellipse(110+20*O,20+40*Row,5,5);
							DoOver=false;
							break;
		default:	DoOver=true;
							break;
		}
	}while(DoOver==true);
}
/******SOLGEN******\
This function generates the solution for a level

VARIABLE DICTIONARY
Solution, Slot, Color - see LEVEL Variable dictionary
K - loop Variable
\******************/
void solgen(apvector <int>&Solution, long Slot, long Color)
{
//Local Vars
int K;

for(K=0;K<Slot;K++)
	Solution[K]=random(Color)+1;
}
/******CHECK******\
This function is used to check the guess against the solution.

VARIABLE DICTIONARY
Guess, Solution, Slot - see LEVEL Variable Dictionary
Round - Determines the round user is on
N, S - loop variables
Correct - tells whether the solution and the guess are equal to each other
\*****************/
bool check(apvector <int>&Guess, apvector <int>&Solution, int Slot, int Round)
{
//Local Vars
int N,S;
bool Correct;

Correct=true;
for(N=0;N<Slot;N++)
	if(Guess[N]!=Solution[N])
		{
		Correct=false;
		for(S=0;S<Slot;S++)
			if(Guess[N]==Solution[S])
				{
				setfillstyle(1,15);
				fillellipse(310+10*N,20+40*Round,3,3);
				}
		}
	else
		{
		setfillstyle(1,0);
		fillellipse(310+10*N,20+40*Round,3,3);
		}
return Correct;
}
/********MENU**********\
This function draws all the graphics for the main menu

VARIABLE DICTIONARY
D - Loop variable
Dis1 - distance between circles length
Dis2 - distance between circles width
\**********************/
void menu()
{
//Local Vars Section
int D,Dis1,Dis2;

cleardevice();
setbkcolor(0);
setcolor(14);
setlinestyle(0,0,3);
rectangle(10,10,630,470);
setcolor(8);
settextjustify(1,1);
settextstyle(1,0,8);
outtextxy(320,50,"Mastermind");
setfillstyle(1,7);
floodfill(319,70,8);
floodfill(240,70,8);
floodfill(240,50,8);
floodfill(353,71,8);
floodfill(242,60,8);
floodfill(243,81,8);
floodfill(244,85,8);
floodfill(242,82,8);
floodfill(241,81,8);
floodfill(158,81,8);
floodfill(155,81,8);
floodfill(140,81,8);
floodfill(120,81,8);
floodfill(119,78,8);
floodfill(118,76,8);
floodfill(117,73,8);
floodfill(116,70,8);
floodfill(115,67,8);
floodfill(114,64,8);
floodfill(113,61,8);
floodfill(112,58,8);
floodfill(111,55,8);
floodfill(110,52,8);
floodfill(109,49,8);
floodfill(108,46,8);
floodfill(107,43,8);
floodfill(106,40,8);
floodfill(180,79,8);
floodfill(182,79,8);
floodfill(178,56,8);
floodfill(158,58,8);
floodfill(531,58,8);
floodfill(508,58,8);
floodfill(506,68,8);
floodfill(506,81,8);
floodfill(503,68,8);
floodfill(488,68,8);
floodfill(485,57,8);
floodfill(458,57,8);
floodfill(408,58,8);
floodfill(406,57,8);
floodfill(383,67,8);
floodfill(378,57,8);
floodfill(297,64,8);
floodfill(271,67,8);
floodfill(271,63,8);
floodfill(269,74,8);
floodfill(271,79,8);
floodfill(202,69,8);
floodfill(202,66,8);
floodfill(337,60,8);
floodfill(434,70,8);
settextstyle(1,0,4);
setcolor(8);
outtextxy(320,240,"1. New Game");
outtextxy(320,270,"2. Instructions");
outtextxy(320,300,"3. High Scores");
outtextxy(320,330,"4. Quit");
putpixel(316,253,8);
putpixel(308,253,8);
//rectangle dimensions (10,10,630,470)
Dis1=48;
Dis2=65;
for(D=0;D<10;D++)
	{
	setfillstyle(1,D+1);
	setcolor(D+1);
	fillellipse(26+Dis2*D,25,8,8);
	fillellipse(26,25+Dis1*D,8,8);
	if(D!=9)
		{
		fillellipse(614-Dis2*D,455,8,8);
		fillellipse(614,455-Dis1*D,8,8);
		}
	setcolor(8);
	}
}
/******SCOREI******\
Collects the high scores and orders them.

VARIABLE DICTIONARY
DiScore - displayed scores
InScore - Scores that are being stored
Temp - holder for change
Trash - getlin requirement
Players - holds all the players scores
Q,Z - loops variables
\******************/
void scorei(int L)
{
//Local Vars Section
ifstream DiScore;
ofstream InScore;
Scoring Temp;
apstring Trash;
apvector <Scoring> Players (11);
int Q,Z;

cleardevice();
DiScore.open("A:\\HISCORES.DAT");
Q=0;
do{
	getline(DiScore,Players[Q].User);
	DiScore>>Players[Q].Pro;
	getline(DiScore,Trash);
	Q++;
	}while(!DiScore.eof());
DiScore.close();
InScore.open("A:\\HISCORES.DAT");
if(L>Players[9].Pro)
	{
	outtextxy(320,240,"What is your name?");
	cin>>Players[10].User;
	clrscr();
	Players[10].Pro=L;
	for(Q=0;Q<11;Q++)
		for(Z=Q;Z<11;Z++)
			if(Players[Z].Pro>Players[Q].Pro)
				{
				Temp=Players[Z];
				Players[Z]=Players[Q];
				Players[Q]=Temp;
				}
	for(Z=0;Z<10;Z++)
		InScore<<Players[Z].User<<endl<<Players[Z].Pro<<endl;
	}
}
/******SCORED******\
This function displays the scores.

VARIABLE DICTIONARY
Show - display file
Q - loop variable
Trash - getline requirement
Highs - storage of the scores
\******************/
void scored()
{
//Local Vars Section
ifstream Show;
int Q;
apstring Trash;
apvector <Scoring> Highs (10);

cleardevice();
Show.open("A:\\HISCORES.DAT");
for(Q=0;Q<10;Q++)
	{
	getline(Show,Highs[Q].User);
	Show>>Highs[Q].Pro;
	getline(Show,Trash);
	}
Show.close();
outtextxy(320,10,"High Scores");
outtextxy(70,40,"Name");
outtextxy(500,40,"Level");
settextjustify(0,0);
settextstyle(1,0,2);
for(Q=0;Q<10;Q++)
	{
	outtextxy(0,80+20*Q,Highs[Q].User.c_str());
	outtextxy(500,80+20*Q,itos(Highs[Q].Pro).c_str());
	}
outtextxy(0,400,"Press Return to go back to main menu.");
getch();
}
void readme()
{
//Local Vars Section
apstring Trash,Title,Info;
apvector <apstring> Instructions(11);
ifstream Inform;
int B;

cleardevice();
Inform.open("A:\\readme.txt");
getline(Inform,Title);
getline(Inform,Info);
getline(Inform,Trash);
for(B=0;B<11;B++)
	getline(Inform,Instructions[B]);
Inform.close();
outtextxy(320,10,Title.c_str());
outtextxy(320,40,Info.c_str());
settextjustify(0,0);
settextstyle(1,0,1);
for(B=0;B<11;B++)
	outtextxy(10,100+B*25,Instructions[B].c_str());
outtextxy(0,400,"To print, open readme.txt on the A-drive, and press ctrl+P");
outtextxy(0,440,"Press Return to go back to main menu.");
getch();
}