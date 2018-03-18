//Jevon Wang
//Shell
//2nd Block
//Mr. Baker

//Library Section

#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <math.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>

//Const section
int Size=20;//length/width for each block

//Structure Section

//Prototype section
void gr_start (int&, int&, int&);
void menu(char&);
void main_box (int&);
void high_score (int&);
void square (int,int,int,int,int,int,int,int);
void shape(int,int,int,int,int,int,int);
void shape1(int,int,int,int,int,int,int);
void rshape(int,int,int,int,int,int,int);
void rshape1(int,int,int,int,int,int,int);
void line(int,int,int,int,int,int,int);
void line1(int,int,int,int,int,int,int);
void RL(int,int,int,int,int,int,int);
void RL1(int,int,int,int,int,int,int);
void RL2(int,int,int,int,int,int,int);
void RL3(int,int,int,int,int,int,int);
void L(int,int,int,int,int,int,int);
void L1(int,int,int,int,int,int,int);
void L2(int,int,int,int,int,int,int);
void L3(int,int,int,int,int,int,int);
void dot(int,int,int,int,int,int);
void T(int,int,int,int,int,int,int);
void T1(int,int,int,int,int,int,int);
void T2(int,int,int,int,int,int,int);
void T3(int,int,int,int,int,int,int);
bool move(int,int&,int&,int&,int&,bool&,int&,int&);
void redraw(bool&,int,int,int);
//variable section
int grdriver,grmode,errorcode;
ifstream in_file;//for use with the high score file.
ofstream out_file;//"                           "
int Highscore;//read from the file and given to the user.
char Answer;//value the users gives for choices in the menu screen.
int Y1,Y2,X1,X2;//numbers used in the bar/rectangle function
int A,B;//used in the forloop that is used to check for a line. B=Y,A=X.
int J,K,C;//used in the forloop to set the matrix either true or false.
					//Used before the game happens to make sure no junk is sitting
					//where the false or true is supposed to be.
int I;//value changed +20 each time for use with moving the shape down.
int X;//value changed +20 each time for use with moving the shape left or right.
int Pick;//the shape picked
int Color;//used to change the color of shape
int Speed,GameSpeed;//speed of the delay used
int GameOver;//used in the do/while to tell if the game is over
int Xa,Ya;//used in the Box matrix to represent X and Y
int ShpNum;//every shape has a ShpNum and it just tells the switch case of
					 //move function what shape is being used to detemine which case
					 //is to be used
int NewPiece;//determines if a new piece is need or just a rotation
int Group;//the group of shapes used
int Score;//keep track of the score, starts at 0 and 10 is added for each line
int X0,Y0;//after a line has been deleted, these two values are used as the
					//x and y of the forloop that is checking to see if there is
					//anything above the delted line
bool Box[16][25];//main box where the game happens, takes up the left half
								 //of the screen and when there is a block at a certain spot
								 //on the screen it will be marked as true on the matrix but
								 //if there isn't, it will be marked as false on the matrix
								 //the matrix is 16 by 24 because each block is 20 and would
								 //make the size of the matrix 320 pixels by 480 pixels.
bool Moved, MovedPlus;//bool used to tell if the user tried to move the shape
void main()
{
randomize();
gr_start(grdriver, grmode, errorcode);

	menu(Answer);
	high_score(Highscore);//////////////////////////////
 /////////////////////////used to set all the space //
	for(J=0;J<16;J++)     //used for the game as false//
		for(K=0;K<25;K++)   //which is all of the left  //
			Box[J][K]=false;  //half of the screen        //
 /////////////////////////////////////////////////////
 ///////////////////////////////////////////////////
	for(C=0;C<16;C++) //sets the line under the game//
		Box[C][24]=true;//as true so shape stop when  //
 /////////////////////they reach that border      //
 ///////////////////////////////////////////////////
	if(Answer=='1')
		{
			NewPiece=true;
			cleardevice();
			main_box(Highscore);
			GameSpeed=250;
			do
			{
			setcolor(1);
			rectangle(0,0,getmaxx(),getmaxy());
			line(((getmaxx()/2)+1),0,((getmaxx()/2)+1),getmaxy());
			if(NewPiece==true)
			{
				Speed=GameSpeed;
				X=0;
				I=0;
				Xa=7;
				Ya=0;
				X1=140;
				X2=160;
				Y1=0;
				Y2=20;
				for(B=0;B<24;B++)
				{
					J=0;
					for(A=0;A<16;A++)
					{
						if(Box[A][B]==true)
							J++;
						if(J==16)
						{
							if(Score==100)
								GameSpeed=GameSpeed-20;
							if(Score==300)
								GameSpeed=GameSpeed-20;
							if(Score>500)
								GameSpeed=GameSpeed-1;
							Score=Score+10;
							setfillstyle(1,0);
							bar(getmaxx()/2+45,60,getmaxx()/2+145,99);
							gotoxy(55,5);
							cout<<Score;
							setfillstyle(1,0);
							bar(0,B*20,320,B*20+Size);
							for(K=0;K<16;K++)
								Box[K][B]=false;
							for(Y0=B;Y0>-1;Y0--)
								for(X0=0;X0<16;X0++)
								{
									if(Box[X0][Y0]==true)
									{
										Box[X0][Y0]=false;
										setfillstyle(1,0);
										bar(X0*20,Y0*20,X0*20+Size,Y0*20+Size);
										setcolor(0);
										rectangle(X0*20,Y0*20,X0*20+Size,Y0*20+Size);
										Box[X0][Y0+1]=true;
										setfillstyle(1,8);
										bar(X0*20,Y0*20+Size,X0*20+Size,Y0*20+2*Size);
										setcolor(0);
										rectangle(X0*20,Y0*20+Size,X0*20+Size,Y0*20+2*Size);
									}
								}
						}
					}
			}
			Group=random(8);
			//////////////////////
			//Picks the group   //
			//to be used. Pick  //
			//is the first shape//
			//of the group      //
			//////////////////////
			switch(Group)
			{
				case 0:
					Pick=0;
					if(Box[Xa][Ya]==true||Box[Xa+1][Ya]==true||Box[Xa][Ya+1]==true||Box[Xa+1][Ya+1]==true)
						GameOver=true;
				break;
				case 1:
					Pick=1;
					if(Box[Xa][Ya]==true||Box[Xa+1][Ya]==true||Box[Xa+2][Ya+1]==true||Box[Xa+1][Ya+1]==true)
						GameOver=true;
				break;
				case 2:
					Pick=3;
					if(Box[Xa][Ya+1]==true||Box[Xa+1][Ya]==true||Box[Xa+1][Ya+1]==true||Box[Xa+2][Ya]==true)
						GameOver=true;
				break;
				case 3:
					Pick=5;
					if(Box[Xa][Ya]==true||Box[Xa+1][Ya]==true||Box[Xa+2][Ya]==true||Box[Xa+3][Ya]==true)
						GameOver=true;
				break;
				case 4:
					Pick=7;
					if(Box[Xa+1][Ya]==true||Box[Xa+1][Ya+1]==true||Box[Xa+1][Ya+2]==true||Box[Xa][Ya+2]==true)
						GameOver=true;
				break;
				case 5:
					Pick=11;
					if(Box[Xa][Ya]==true||Box[Xa][Ya+1]==true||Box[Xa][Ya+2]==true||Box[Xa+1][Ya+2]==true)
						GameOver=true;
				break;
				case 6:
					Pick=15;
					if(Box[Xa][Ya]==true)
						GameOver=true;
				break;
				case 7:
					Pick=16;
					if(Box[Xa][Ya]==true||Box[Xa+1][Ya]==true||Box[Xa+2][Ya]==true||Box[Xa+1][Ya+1]==true)
					GameOver=true;
				break;
			}
		}
		else
			NewPiece=true;
		//////////////////////////////////
		//This is main switch where all //
		//the shapes are kept. Here they//
		//are given values of true or   //
		//false but in the functions    //
		//they call is where the visual //
		//part of the shape is drawn.   //
		//The colors are given values   //
		//in the switch and used in the //
		//functions. The move functions //
		//are places each of the cases, //
		//they are just to get the input//
		//the user inputs and depending //
		//on what it is, the function   //
		//will process it and give a    //
		//reaction if one is neccessary //
		//////////////////////////////////
		switch(Pick)
		{
			case 0:
					do
					{
						ShpNum=0;
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Color=15;
						square(X1,X2,Y1,Y2,I,Size,Color,X);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa+1][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa+1][Ya+1]=false;
						Color=0;
						square(X1,X2,Y1,Y2,I,Size,Color,X);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+2]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Color=8;
						square(X1,X2,Y1,Y2,I,Size,Color,X);
						NewPiece=true;
					}
				break;
			case 1:
					do
					{
						ShpNum=1;
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+2][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Color=3;
						shape(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa+1][Ya]=false;
						Box[Xa+2][Ya+1]=false;
						Box[Xa+1][Ya+1]=false;
						Color=0;
						shape(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+2])==false);
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+2][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Color=8;
						shape(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}

				break;
			case 2:
					do
					{
						ShpNum=2;
						Box[Xa+1][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa+1][Ya+1]=true;
						Color=3;
						shape1(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa+1][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa][Ya+2]=false;
						Box[Xa+1][Ya+1]=false;
						Color=0;
						shape1(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+3]==false)&&(Box[Xa+1][Ya+2]==false));
					if(NewPiece!=false)
					{
						Box[Xa+1][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa+1][Ya+1]=true;
						Color=8;
						shape1(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}

				break;
			case 3:
					do
					{
						ShpNum=3;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+2][Ya]=true;
						Color=2;
						rshape(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya+1]=false;
						Box[Xa+1][Ya]=false;
						Box[Xa+1][Ya+1]=false;
						Box[Xa+2][Ya]=false;
						Color=0;
						rshape(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+1]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+2][Ya]=true;
						Color=8;
						rshape(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
				break;
			case 4:
					do
					{
						ShpNum=4;
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+1][Ya+2]=true;
						Color=2;
						rshape1(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa+1][Ya+1]=false;
						Box[Xa+1][Ya+2]=false;
						Color=0;
						rshape1(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+3]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+1][Ya+2]=true;
						Color=8;
						rshape1(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
				break;
			case 5:
					do
					{
						ShpNum=5;
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+2][Ya]=true;
						Box[Xa+3][Ya]=true;
						Color=4;
						line(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa+1][Ya]=false;
						Box[Xa+2][Ya]=false;
						Box[Xa+3][Ya]=false;
						Color=0;
						line(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+1]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+3][Ya+1]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa+1][Ya]=true;
						Box[Xa+2][Ya]=true;
						Box[Xa+3][Ya]=true;
						Color=8;
						line(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}

				break;
			case 6:
					do
					{
						ShpNum=6;
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa][Ya+3]=true;
						Color=4;
						line1(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa][Ya+2]=false;
						Box[Xa][Ya+3]=false;
						Color=0;
						line1(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+4]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa][Ya+3]=true;
						Color=8;
						line1(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
					break;
			case 7:
					do
					{
						ShpNum=7;
						Box[Xa+1][Ya]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+1][Ya+2]=true;
						Box[Xa][Ya+2]=true;
						Color=9;
						RL(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa+1][Ya]=false;
						Box[Xa+1][Ya+1]=false;
						Box[Xa+1][Ya+2]=false;
						Box[Xa][Ya+2]=false;
						Color=0;
						RL(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+3]==false)&&(Box[Xa+1][Ya+3]==false));
					if(NewPiece!=false)
					{
						Box[Xa+1][Ya]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+1][Ya+2]=true;
						Box[Xa][Ya+2]=true;
						Color=8;
						RL(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
			break;
			case 8:
					do
					{
						ShpNum=8;
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+2][Ya+1]=true;
						Color=9;
						RL1(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa+1][Ya+1]=false;
						Box[Xa+2][Ya+1]=false;
						Color=0;
						RL1(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+2]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa+1][Ya+1]=true;
						Box[Xa+2][Ya+1]=true;
						Color=8;
						RL1(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
			break;
			case 9:
					do
					{
						ShpNum=9;
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa+1][Ya]=true;
						Color=9;
						RL2(X1,X2,Y1,Y2,I,Size,Color);
						delay(Speed);
						Box[Xa][Ya]=false;
						Box[Xa][Ya+1]=false;
						Box[Xa][Ya+2]=false;
						Box[Xa+1][Ya]=false;
						Color=0;
						RL2(X1,X2,Y1,Y2,I,Size,Color);
						Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
						if(NewPiece==false)
							break;
						if(!Moved&&!MovedPlus)
						{
							I=I+Size;
							Ya++;
						}
					}while((Box[Xa][Ya+3]==false)&&(Box[Xa+1][Ya+1]==false));
					if(NewPiece!=false)
					{
						Box[Xa][Ya]=true;
						Box[Xa][Ya+1]=true;
						Box[Xa][Ya+2]=true;
						Box[Xa+1][Ya]=true;
						Color=8;
						RL2(X1,X2,Y1,Y2,I,Size,Color);
						NewPiece=true;
					}
			break;
			case 10:
				do
				{
					ShpNum=10;
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa+2][Ya+1]=true;
					Color=9;
					RL3(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa+1][Ya]=false;
					Box[Xa+2][Ya]=false;
					Box[Xa+2][Ya+1]=false;
					Color=0;
					RL3(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+1]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa+2][Ya+1]=true;
					Color=8;
					RL3(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 11:
				do
				{
					ShpNum=11;
					Box[Xa][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa][Ya+2]=true;
					Box[Xa+1][Ya+2]=true;
					Color=13;
					L(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa][Ya+1]=false;
					Box[Xa][Ya+2]=false;
					Box[Xa+1][Ya+2]=false;
					Color=0;
					L(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
							I=I+Size;
							Ya++;
					}
				}while((Box[Xa][Ya+3]==false)&&(Box[Xa+1][Ya+3]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa][Ya+2]=true;
					Box[Xa+1][Ya+2]=true;
					Color=8;
					L(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 12:
				do
				{
					ShpNum=12;
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa][Ya+1]=true;
					Color=13;
					L1(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa+1][Ya]=false;
					Box[Xa+2][Ya]=false;
					Box[Xa][Ya+1]=false;
					Color=0;
					L1(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+2][Ya+1]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa][Ya+1]=true;
					Color=8;
					L1(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 13:
				do
				{
					ShpNum=13;
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+1][Ya+2]=true;
					Color=13;
					L2(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa+1][Ya]=false;
					Box[Xa+1][Ya+1]=false;
					Box[Xa+1][Ya+2]=false;
					Color=0;
					L2(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+1]==false)&&(Box[Xa+1][Ya+3]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+1][Ya+2]=true;
					Color=8;
					L2(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 14:
				do
				{
					ShpNum=14;
					Box[Xa][Ya+1]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+2][Ya+1]=true;
					Box[Xa+2][Ya]=true;
					Color=13;
					L3(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya+1]=false;
					Box[Xa+1][Ya+1]=false;
					Box[Xa+2][Ya+1]=false;
					Box[Xa+2][Ya]=false;
					Color=0;
					L3(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+2]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya+1]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+2][Ya+1]=true;
					Box[Xa+2][Ya]=true;
					Color=8;
					L3(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 15:
				do
				{
					ShpNum=15;
					Box[Xa][Ya]=true;
					Color=random(16)+1;
					dot(X1,X2,Y1,Y2,I,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Color=0;
					dot(X1,X2,Y1,Y2,I,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
						break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
						break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+1]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Color=8;
					dot(X1,X2,Y1,Y2,I,Color);
				}
			break;
			case 16:
				do
				{
					ShpNum=16;
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Color=14;
					T(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa+1][Ya]=false;
					Box[Xa+2][Ya]=false;
					Box[Xa+1][Ya+1]=false;
					Color=0;
					T(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+1]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa+1][Ya]=true;
					Box[Xa+2][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Color=8;
					T(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 17:
				do
				{
					ShpNum=17;
					Box[Xa+1][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+1][Ya+2]=true;
					Box[Xa][Ya+1]=true;
					Color=14;
					T1(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa+1][Ya]=false;
					Box[Xa+1][Ya+1]=false;
					Box[Xa+1][Ya+2]=false;
					Box[Xa][Ya+1]=false;
					Color=0;
					T1(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+3]==false));
				if(NewPiece!=false)
				{
					Box[Xa+1][Ya]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+1][Ya+2]=true;
					Box[Xa][Ya+1]=true;
					Color=8;
					T1(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 18:
				do
				{
					ShpNum=18;
					Box[Xa+1][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+2][Ya+1]=true;
					Color=14;
					T2(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa+1][Ya]=false;
					Box[Xa][Ya+1]=false;
					Box[Xa+1][Ya+1]=false;
					Box[Xa+2][Ya+1]=false;
					Color=0;
					T2(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+2]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+2][Ya+2]==false));
				if(NewPiece!=false)
				{
					Box[Xa+1][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa+1][Ya+1]=true;
					Box[Xa+2][Ya+1]=true;
					Color=8;
					T2(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
			case 19:
				do
				{
					ShpNum=19;
					Box[Xa][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa][Ya+2]=true;
					Box[Xa+1][Ya+1]=true;
					Color=14;
					T3(X1,X2,Y1,Y2,I,Size,Color);
					delay(Speed);
					Box[Xa][Ya]=false;
					Box[Xa][Ya+1]=false;
					Box[Xa][Ya+2]=false;
					Box[Xa+1][Ya+1]=false;
					Color=0;
					T3(X1,X2,Y1,Y2,I,Size,Color);
					Moved=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					MovedPlus=move(Size,X,Xa,Speed,ShpNum,NewPiece,Pick,GameOver);
					if(NewPiece==false)
							break;
					if(!Moved&&!MovedPlus)
					{
						I=I+Size;
						Ya++;
					}
				}while((Box[Xa][Ya+3]==false)&&(Box[Xa+1][Ya+2]==false));
				if(NewPiece!=false)
				{
					Box[Xa][Ya]=true;
					Box[Xa][Ya+1]=true;
					Box[Xa][Ya+2]=true;
					Box[Xa+1][Ya+1]=true;
					Color=8;
					T3(X1,X2,Y1,Y2,I,Size,Color);
					NewPiece=true;
				}
			break;
		 }
		}while(GameOver==false);
		cleardevice();
		gotoxy(35,8);
		cout<<"GAME OVER"<<endl;
		gotoxy(28,9);
		cout<<"Press any key to exit game"<<endl;
		getch();
		if(Score>Highscore)
		{
			out_file.open("A:\\HS.DAT");
			out_file<<Score;
			out_file.close();
		}

	}
	if(Answer=='2')
		{
		cleardevice();
		cout<<"High score: "<<Highscore<<endl;
		cout<<"Press any key to return to main menu";
		getch();
		clrscr();
		}
	cleardevice();

}


void gr_start(int& grdriver, int& grmode, int& errorcode)
{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(&grdriver, &grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
		{
			clrscr();
			cout<<"Error:"<<errorcode<<endl;
			cout<<"Press Return to Continue:";
			getch();
			exit(1);
		}
};


////////////////////////////////
//The menu function is used to//
//draw the menu and writes out//
//the choices the user has to //
//pick from and get the input //
//from the user.              //
////////////////////////////////
void menu(char &Answer)
{
	moveto(0,0);
	setcolor(4);
	outtext("---------------------------------------------------------------------------");
	moveto(0,10);
	outtext("  ::::::::::: :::::::::: ::::::::::: :::::::::  ::::::::::: ::::::::");
	moveto(0,20);
	outtext("      :+:     :+:            :+:     :+:    :+:     :+:    :+:    :+:");
	moveto(0,30);
	outtext("     +:+     +:+            +:+     +:+    +:+     +:+    +:+");
	moveto(0,40);
	outtext("    +#+     +#++:++#       +#+     +#++:++#:      +#+    +#++:++#++");
	moveto(0,50);
	outtext("   +#+     +#+            +#+     +#+    +#+     +#+           +#+");
	moveto(0,60);
	outtext("  #+#     #+#            #+#     #+#    #+#     #+#    #+#    #+#");
	moveto(0,70);
	outtext(" ###     ##########     ###     ###    ### ########### ########");
	setcolor(1);
	outtextxy(0,150,"Please pick a menu option:");
	outtextxy(0,180,"1:Start Game");
	outtextxy(0,210,"2:High Score");
	outtextxy(0,240,"Any Other Key:Exit");

	Answer=getche();

};


///////////////////////////////////
//The main_box function is used  //
//to draw the blue borders and   //
//to give the information on the //
//right half of the screen such  //
//as the the keys to play the    //
//game, the current score and the//
//current high score to beat.    //
///////////////////////////////////
void main_box (int &Highscore)
{
 cleardevice();
 rectangle(0,0,getmaxx(),getmaxy());
 line(((getmaxx()/2)+1),0,((getmaxx()/2)+1),getmaxy());
 moveto(getmaxx()/2+50,50);
 setcolor(15);
 outtextxy(getmaxx()/2+50,50,"Your Score");
 gotoxy(55,5);
 cout<<0;
 outtextxy(getmaxx()/2+50,100,"Previous High Score");
 gotoxy(55,9);
 cout<<Highscore;
 outtextxy(getmaxx()/2+50,175,"Left-Left arrow");
 outtextxy(getmaxx()/2+50,200,"Right-Right arrow");
 outtextxy(getmaxx()/2+50,225,"Up-Rotate Block");
 outtextxy(getmaxx()/2+50,250,"Esc-Exit Game");
};


/////////////////////////////////////
//The high_score function opens up //
//the HS.DAT file and gets the most//
//recent high score from the file. //
/////////////////////////////////////
void high_score (int &Highscore)
{
 in_file.open("A:\\HS.DAT");
 assert(!in_file.fail());
 in_file>>Highscore;
 in_file.close();
};


///////////////////////////////////////
//The move function that gets the    //
//user's input and analyzes it and   //
//determines where the user pressed  //
//esc,up,down,left,or right and gives//
//the appropriate response after     //
//checking on a few limitations      //
///////////////////////////////////////
bool move (int Size,int &X,int &Xa,int &Speed,int &ShpNum,bool &NewPiece,int &Pick,int &GameOver)
{
	if(kbhit())
		{
			switch(int (getche()))
				{
					case 77:
						switch(ShpNum)
						{
							case 0:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+2][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 1:
								if((Xa+3<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+3][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 2:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 3:
								if((Xa+3<16)&&(Box[Xa+3][Ya]==false)&&(Box[Xa+2][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 4:
								if((Xa+2<16)&&(Box[Xa+1][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 5:
								if((Xa+4<16)&&(Box[Xa+4][Ya]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 6:
								if((Xa+1<16)&&(Box[Xa+1][Ya]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false)&&(Box[Xa+1][Ya+3]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 7:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 8:
								if((Xa+3<16)&&(Box[Xa+1][Ya]==false)&&(Box[Xa+3][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 9:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 10:
								if((Xa+3<16)&&(Box[Xa+3][Ya]==false)&&(Box[Xa+3][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 11:
								if((Xa+2<16)&&(Box[Xa+1][Ya]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 12:
								if((Xa+3<16)&&(Box[Xa+3][Ya]==false)&&(Box[Xa+1][Ya+1]==false)&&(Box[Xa+1][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 13:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 14:
								if((Xa+3<16)&&(Box[Xa+3][Ya]==false)&&(Box[Xa+3][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 15:
								if((Xa+1<16)&&(Box[Xa+1][Ya]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 16:
								if((Xa+3<16)&&(Box[Xa+3][Ya]==false)&&(Box[Xa+2][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 17:
								if((Xa+2<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+2][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 18:
								if((Xa+3<16)&&(Box[Xa+2][Ya]==false)&&(Box[Xa+3][Ya+1]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
							case 19:
								if((Xa+2<16)&&(Box[Xa+1][Ya]==false)&&(Box[Xa+2][Ya+1]==false)&&(Box[Xa+1][Ya+2]==false))
								{
									Xa++;
									X=X+Size;
									return true;
								}
							break;
						}
					break;
					case 75:
						switch(ShpNum)
						{
							case 0:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 1:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 2:
								if((Xa-1>-1)&&(Box[Xa][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 3:
								if((Xa-1>-1)&&(Box[Xa][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 4:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa][Ya-2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 5:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 6:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false)&&(Box[Xa-1][Ya+3]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 7:
								if((Xa-1>-1)&&(Box[Xa][Ya]==false)&&(Box[Xa][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 8:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 9:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 10:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa+1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 11:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 12:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 13:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa][Ya+1]==false)&&(Box[Xa][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 14:
								if((Xa-1>-1)&&(Box[Xa+1][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 15:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 16:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 17:
								if((Xa-1>-1)&&(Box[Xa][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 18:
								if((Xa-1>-1)&&(Box[Xa][Ya]==false)&&(Box[Xa-1][Ya+1]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
							case 19:
								if((Xa-1>-1)&&(Box[Xa-1][Ya]==false)&&(Box[Xa-1][Ya+1]==false)&&(Box[Xa-1][Ya+2]==false))
								{
									Xa--;
									X=X-Size;
									return true;
								}
							break;
						}
					break;
					case 80:
						Speed=50;
					break;
					case 72:
						switch(ShpNum)
						{
							case 1:
								if(Ya+3<25&&Box[Xa+1][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa][Ya+3]==false&&Box[Xa+1][Ya+2]==false)
								{
									NewPiece=false;
									Pick=2;
									return true;
								}
							break;
							case 2:
								if(Ya+2<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+2][Ya+2]==false&&Box[Xa+1][Ya+2]==false)
								{
									NewPiece=false;
									Pick=1;
									return true;
								}
							break;
							case 3:
								if(Ya+3<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+1][Ya+3]==false)
								{
									NewPiece=false;
									Pick=4;
									return true;
								}
							break;
							case 4:
								if(Ya+2<25&&Box[Xa][Ya+2]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+2][Ya+1]==false)
								{
									NewPiece=false;
									Pick=3;
									return true;
								}
							break;
							case 5:
								if(Ya+4<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa][Ya+3]==false&&Box[Xa][Ya+4]==false)
								{
									NewPiece=false;
									Pick=6;
									return true;
								}
							break;
							case 6:
								if(Ya+1<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+2][Ya+1]==false&&Box[Xa+3][Ya+1]==false)
								{
									NewPiece=false;
									Pick=5;
									return true;
								}
							break;
							case 7:
								if(Ya+2<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+2][Ya+2]==false)
								{
									NewPiece=false;
									Pick=8;
									return true;
								}
							break;
							case 8:
								if(Ya+3<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa][Ya+3]==false&&Box[Xa+1][Ya+1]==false)
								{
									NewPiece=false;
									Pick=9;
									return true;
								}
							break;
							case 9:
								if(Ya+2<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+2][Ya+1]==false&&Box[Xa+2][Ya+2]==false)
								{
									NewPiece=false;
									Pick=10;
									return true;
								}
							break;
							case 10:
								if(Ya+3<25&&Box[Xa+1][Ya+1]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+1][Ya+3]==false&&Box[Xa][Ya+3]==false)
								{
									NewPiece=false;
									Pick=7;
									return true;
								}
							break;
							case 11:
								if(Ya+2<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+2][Ya+1]==false&&Box[Xa][Ya+2]==false)
								{
									NewPiece=false;
									Pick=12;
									return true;
								}
							break;
							case 12:
								if(Ya+3<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+1][Ya+3]==false)
								{
									NewPiece=false;
									Pick=13;
									return true;
								}
							break;
							case 13:
								if(Ya+2<25&&Box[Xa][Ya+2]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+2][Ya+2]==false&&Box[Xa+2][Ya+1]==false)
								{
									NewPiece=false;
									Pick=14;
									return true;
								}
							break;
							case 14:
								if(Ya+3<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa][Ya+3]==false&&Box[Xa+1][Ya+3]==false)
								{
									NewPiece=false;
									Pick=11;
									return true;
								}
							break;
							case 16:
								if(Ya+3<25&&Box[Xa+1][Ya+1]==false&&Box[Xa+1][Ya+2]==false&&Box[Xa+1][Ya+3]==false&&Box[Xa][Ya+2]==false)
								{
									NewPiece=false;
									Pick=17;
									return true;
								}
							break;
							case 17:
								if(Ya+2<25&&Box[Xa+1][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa+1][Ya+3]==false&&Box[Xa+2][Ya+2]==false)
								{
									NewPiece=false;
									Pick=18;
									return true;
								}
							break;
							case 18:
								if(Ya+3<25&&Box[Xa][Ya+1]==false&&Box[Xa][Ya+2]==false&&Box[Xa][Ya+3]==false&&Box[Xa+1][Ya+2]==false)
								{
									NewPiece=false;
									Pick=19;
									return true;
								}
							break;
							case 19:
								if(Ya+2<25&&Box[Xa][Ya+1]==false&&Box[Xa+1][Ya+1]==false&&Box[Xa+2][Ya+1]==false&&Box[Xa+1][Ya+2]==false)
								{
									NewPiece=false;
									Pick=16;
									return true;
								}
							break;
						}
						break;
					case 27:
						NewPiece=false;
						GameOver=true;
					break;
				}
		}
	 return false;
};


///////////////////////////////////////
//The following functions are used   //
//by the appropriate shapes to draw  //
//the graphical shape onto the screen//
///////////////////////////////////////
void square (int X1,int X2,int Y1,int Y2,int I,int Size,int Color,int X)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
};
void shape (int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+Size*2+X,Y1+Size+I,X2+Size*2+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+Size*2+X,Y1+Size+I,X2+Size*2+X,Y2+Size+I);
};

void shape1 (int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
};
void rshape (int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);

};
void rshape1 (int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
};
void line (int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+Size*2+X,Y1+I,X2+Size*2+X,Y2+I);
	bar(X1+Size*3+X,Y1+I,X2+Size*3+X,Y2+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+Size*2+X,Y1+I,X2+Size*2+X,Y2+I);
	rectangle(X1+Size*3+X,Y1+I,X2+Size*3+X,Y2+I);
};
void line1(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+I+Size,X2+X,Y2+I+Size);
	bar(X1+X,Y1+I+Size*2,X2+X,Y2+I+Size*2);
	bar(X1+X,Y1+I+Size*3,X2+X,Y2+I+Size*3);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+I+Size,X2+X,Y2+I+Size);
	rectangle(X1+X,Y1+I+Size*2,X2+X,Y2+I+Size*2);
	rectangle(X1+X,Y1+I+Size*3,X2+X,Y2+I+Size*3);
};
void RL(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	bar(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	setcolor(0);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	rectangle(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);


};
void RL1(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
};
void RL2(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
};
void RL3(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	bar(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	rectangle(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
};
void L(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	bar(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	rectangle(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
};
void L1(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
};
void L2(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
};
void L3(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
	bar(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	setcolor(0);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
	rectangle(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);

};
void dot(int X1,int X2,int Y1,int Y2,int I,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
};
void T(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+2*Size+X,Y1+I,X2+2*Size+X,Y2+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);

};
void T1(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
	setcolor(0);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+2*Size+I,X2+Size+X,Y2+2*Size+I);
};
void T2(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	bar(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+Size+X,Y1+I,X2+Size+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	rectangle(X1+2*Size+X,Y1+Size+I,X2+2*Size+X,Y2+Size+I);

};
void T3(int X1,int X2,int Y1,int Y2,int I,int Size,int Color)
{
	setfillstyle(1,Color);
	bar(X1+X,Y1+I,X2+X,Y2+I);
	bar(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	bar(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	bar(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
	setcolor(0);
	rectangle(X1+X,Y1+I,X2+X,Y2+I);
	rectangle(X1+X,Y1+Size+I,X2+X,Y2+Size+I);
	rectangle(X1+X,Y1+2*Size+I,X2+X,Y2+2*Size+I);
	rectangle(X1+Size+X,Y1+Size+I,X2+Size+X,Y2+Size+I);
};











