//Erik Carlsen-Landy
//Period 7
//Shell
/* Emily and Erik's form of Jeopardy is a game in which the player is given
a game board on which they can choose questions. The player can then answer
the questions and gain points based on whether or not the answer the question
correctly.
*/

//Library
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <apstring.h>
#include <graphics.h>
#include <stdlib.h>
#include <apvector.h>
#include "bitmap.h"
#include <fstream.h>
#include "gmouse.h"

//Const

//Struct Section
struct Highs
{
 apstring Name;
 int Points;
};


//Global Variables
int GrDriver, GrMode, ErrorCode, Choice, X, Y, Z, A, J, Key, Score;
char  Ans;
apvector <bool> Check (31);
ifstream in_file;
image MyPic;


/*
INTS:

-Choice is used on the main menu for the user to pick which screen
 they would like to go to.
-X is a variable for the x-coordinates of the mouse.
-Y is a variable for the y-coordinates of the mouse.
-Z is a variable to find which button was clicked on the mouse.
-A is a variable that controls teh for loop to make all choices true on the
 Jeopardy boards and also controls how many times the jeopardy board will run
 through.
-J is a variable that controls the for loop in the infile function that reads
 in the sentence lines.
-Key is a variable that determines what key the user has pushed on the main
 menu.
-Score is a variable that is used in the scores function that keeps track of
 the users current score in the game.

CHARS:

-Ans is a variable that sees if the user wants to return to the main menu
 after their game.

APVECTORS:

-Check is a bool that is used to determine if the user has already picked on
 a certain box, if they have, it turns false.

Ifstream:
-in_file infiles questions

MyPic:
-Variable used to open and draw the Jeopardy boards.

*/

//Prototype
void gr_start (int&, int&, int&);
void game (void);
void game2 (void);
void game3 (void);
void scores (void);
apstring infile (int&);

/*
gr_start-starts the ability for the use of graphics.
game-opens the first jeopardy board, starting the game.  The user can then
		 click on boxes to answer questions and play through the first round of
		 the game.
game2-opens the second jeopardy board, starting the second round.  The user
			can then click on boxes to answer questions and play through the second
			round of the game.
game3-opens the final jeopardy board, starting the round.  The user can then
			answer the final jeopardy question and either go back to the main menu,
			or just quit the program.
scores-infiles the high scores. Takes in the players scores and adjusts it as
			 the user plays.  If the user gets a high enough score, then their score
			 appears in the highscore menu.
infile-infiles the actual questions and allows them to be seen on the screen.

*/

//Void Main

void main()
{
	do  {randomize();

			 gr_start(GrDriver, GrMode, ErrorCode);
			 SizeMouseX(640);
			 SizeMouseY(480);
			 graphinit(GR16);

			 MyPic.open("a:\\jeop.bmp");
			 MyPic.draw(1, 1);

			 do{
					while(!kbhit);
					{
					Key=getch();
					if(Key==49)
					Choice=1;
					if(Key==50)
					Choice=2;
					if(Key==51)
					Choice=3;
					}
				 }while(Key!=49&&Key!=50&&Key!=51);

			 switch(Choice)
			 {
			 case 1:cleardevice();
							game();
							cout<<endl<<"Return to menu? (Y/N)"<<endl;
							cin>>Ans;
							break;
			 case 2:cleardevice();
							scores();
							cout<<endl<<"Return to menu? (Y/N)"<<endl;
							cin>>Ans;
							break;
			 };
			} while (Ans =='Y'||Ans=='y');
}

//End

//Function
void gr_start (int&GrDriver, int&GrMode, int&ErrorCode)
{
	GrDriver=VGA;
	GrMode=VGAHI;
	initgraph(&GrDriver, &GrMode, "c:\\TC\\BGI");
	ErrorCode=graphresult();
	while(ErrorCode!=grOk)
		{clrscr();
		 cout<<"Error code: "<<ErrorCode<<endl;
		 cout<<"Press return to continue";
			 getch();
			 exit(1);
		}
}
//End Function

void game (void)
{
A=0;
for(A=0; A<30; A++)
Check[A]=true;

MyPic.open("a:\\jeop1.bmp");
MyPic.draw(1,1);

ShowMouse();

	 for(A=0; A<31; A++)
	 do{GetMouseX();
			GetMouseY();
			GetMouseButton();
			X=GetMouseX();
			Y=GetMouseY();
			Z=GetMouseButton();

		if(X>=3&&X<=97&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[0]==true)
		 {
			Check[0]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
			bar(3, 83, 97, 158);
		 }
		}
		if(X>=3&&X<=97&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[1]==true)
		 {
			Check[1]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[2]==true)
		 {
			Check[2]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[3]==true)
		 {
			Check[3]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[4]==true)
		 {
			Check[4]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[5]==true)
		 {
			Check[5]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[6]==true)
		 {
			Check[6]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[7]==true)
		 {
			Check[7]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[8]==true)
		 {
			Check[8]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[9]==true)
		 {
			Check[9]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[10]==true)
		 {
			Check[10]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[11]==true)
		 {
			Check[11]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[12]==true)
		 {
			Check[12]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[13]==true)
		 {
			Check[13]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[14]==true)
		 {
			Check[14]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[15]==true)
		 {
			Check[15]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[16]==true)
		 {
			Check[16]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[17]==true)
		 {
			Check[17]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[18]==true)
		 {
			Check[18]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[19]==true)
		 {
			Check[19]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[20]==true)
		 {
			Check[20]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[21]==true)
		 {
			Check[21]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[22]==true)
		 {
			Check[22]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[23]==true)
		 {
			Check[23]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[24]==true)
		 {
			Check[24]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[25]==true)
		 {
			Check[25]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[26]==true)
		 {
			Check[26]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[27]==true)
		 {
			Check[27]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[28]==true)
		 {
			Check[28]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[29]==true)
		 {
			Check[29]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}

		}while(GetMouseButton()==0);

		HideMouse();
		cleardevice();
		clrscr();
		game2();
}

//End Function

void game2 (void)
{
A=0;

for(A=0; A<30; A++)
Check[A]=true;

MyPic.open("a:\\jeop2.bmp");
MyPic.draw(1,1);

ShowMouse();
cout<<"Choose a question!"<<endl;

	 for(A=0; A<31; A++)
	 {
	 do{GetMouseX();
			GetMouseY();
			GetMouseButton();
			X=GetMouseX();
			Y=GetMouseY();
			Z=GetMouseButton();

		if(X>=3&&X<=97&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[0]==true)
		 {
			Check[0]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[1]==true)
		 {
			Check[1]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[2]==true)
		 {
			Check[2]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[3]==true)
		 {
			Check[3]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=3&&X<=97&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[4]==true)
		 {
			Check[4]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[5]==true)
		 {
			Check[5]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[6]==true)
		 {
			Check[6]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[7]==true)
		 {
			Check[7]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[8]==true)
		 {
			Check[8]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=98&&X<=208&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[9]==true)
		 {
			Check[9]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[10]==true)
		 {
			Check[10]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[11]==true)
		 {
			Check[11]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[12]==true)
		 {
			Check[12]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[13]==true)
		 {
			Check[13]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=209&&X<=323&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[14]==true)
		 {
			Check[14]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[15]==true)
		 {
			Check[15]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[16]==true)
		 {
			Check[16]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[14]==true)
		 {
			Check[17]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[18]==true)
		 {
			Check[18]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=324&&X<=422&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[19]==true)
		 {
			Check[19]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[20]==true)
		 {
			Check[20]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[21]==true)
		 {
			Check[21]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[22]==true)
		 {
			Check[22]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[23]==true)
		 {
			Check[23]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[24]==true)
		 {
			Check[24]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=423&&X<=531&&Y>=396&&Y<=479&&Z==1)
		{
		 if(Check[25]==true)
		 {
			Check[25]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=83&&Y<=161&&Z==1)
		{
		 if(Check[26]==true)
		 {
			Check[26]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=162&&Y<=242&&Z==1)
		{
		 if(Check[27]==true)
		 {
			Check[27]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=243&&Y<=315&&Z==1)
		{
		 if(Check[28]==true)
		 {
			Check[28]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}
		if(X>=532&&X<=640&&Y>=316&&Y<=395&&Z==1)
		{
		 if(Check[29]==true)
		 {
			Check[29]=false;
			HideMouse();
			cleardevice();
			ShowMouse();
			infile(Score);
			getch();
			HideMouse();
			clrscr();
			cleardevice();
			MyPic.draw(1,1);
			ShowMouse();
		 }
		}


		}while(GetMouseButton()==0);

	 }

	HideMouse();
	cleardevice();
	clrscr();
	game3();
	}

//End Function

void game3 (void)
{
	MyPic.open("a:\\final.bmp");
	MyPic.draw(1,1);
	ShowMouse();
	infile(Score);
}
//End of Function

void scores ()
{
//Local Variable
apvector <int> HighScores (10);
int J, B,K, Temp;
ofstream out_file;

 in_file.open("a:\\scores.dat");
 J=0;
 for(J=0; J<10; J++)
 in_file>>HighScores[J];
 in_file.close();

 for(J=0; J<10; J++)
 if(Score>HighScores[J])
			{
			cout<<"You got a high score!"<<endl;
			for(K=9; K>J; K--)
			HighScores[K]=HighScores[K-1];
			HighScores[J]=Score;
			J=10;
			}

	out_file.open("a:\\scores.dat");
	cout<<"High Scores"<<endl<<endl;
	for(J=0; J<10; J++)
	{
	out_file<<HighScores[J]<<endl;
	cout<<J+1<<"."<<HighScores[J]<<endl;
	}
	out_file.close();
};

//End Function


apstring infile (int&Score)
{
//Local Variable
apstring Sentence, Filename;
ifstream In_file;
apstring Answer, Ans;
apstring Response;
int X;

 Filename="a:\\Jeopardy\\C";
 Filename+=char(random(10)+48);
 Filename+=char(random(10)+48);
 Filename+=".dat";
 In_file.open(Filename.c_str());
 for(J=0; J<5; J++)
 {
	getline(In_file, Sentence);
	if(Sentence.length()>0 && Sentence[Sentence.length()-1]=='*')
	 {Answer=Sentence[0];
		Ans="";
		for(X=0; X<Sentence.length()-1; X++)
		Ans+=Sentence[X];
		Sentence=Ans;
		}
	cout<<Sentence<<endl;
 }
 cin>>Response;
 if(Response==Answer)
	{
	 cout<<"You got the right answer!"<<endl;
	 cout<<"Your score is now ";
	 Score+=50;
	 cout<<Score;
	}
	else
	 cout<<"You got the wrong answer!"<<endl;

 In_file.close();
 return Answer;
};


//End Function













