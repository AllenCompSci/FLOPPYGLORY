//Sam Carson
//Shell
//3rd block

//Library Section
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <bool.h>
#include <apvector.h>
#include <apmatrix.h>
#include <fstream.h>
#include <graphics.h>

//Constant Section

//Struct
//Variable Dictionary
/*
Pick:is the matrix that makes sure the AI doesn't put a ship in the same spot
X:are the X coordinates used throughout the program;local
Y:Y coordinates;local
sink:need to split it up;it's the function that sinks user's ships;
			need to use the X and Y from the user_int
carrier:places the carrier on the map;uses Pick and Chk(from user_int)
					to make sure that it doesn't go over another ship;
cruiser:"     "
gunship:"     "
u_boat:"      "
aegis:"       "
M:is the int variable for the switch cases
I,J:are for for loops
K:is what is used inside the switch to add and subtract from the X and Y
Repeat:is a local variable that gets out of the do whiles
*/
//Global Variable Section
char Ans;
apmatrix <bool> Pick (23,16);
int grdriver,grmode,errorcode,M,I,J,K; //M is the value for the ship
//Prototype Section
void gr_start (int&,int&,int&);
//void pick (apmatrix<bool>&,apmatrix<bool>&,int&,int&);
void sink (apmatrix<bool>&);
void carrier (apmatrix<bool>&,apmatrix<bool>&);
void gunship (apmatrix<bool>&,apmatrix<bool>&);
void cruiser (apmatrix<bool>&,apmatrix<bool>&);
void u_boat (apmatrix<bool>&,apmatrix<bool>&);
void aegis (apmatrix<bool>&,apmatrix<bool>&);
void main()
{

clrscr();
gr_start(grdriver,grmode,errorcode);
cleardevice();
randomize();
//NEED A MATH FORMULA FOR THE SCALE PIXLES TO ARRAY
/*
Need to make it so the computer randomly picks places to bomb. If it does
find a ship then it should pick a reasonable place that could be part of the
ship. Need to interweave with the video of the bombing.
Random ship placement should use prob#25 for the concept of not picking a
spot that already has a ship in it. Also so it doesn't put the ship off the
screen. Only using left right and up down for possible positions.
*/
//use a do while to continue to pick numbers]
//PUT THIS INTO A FUNCTION
//NEED ANOTHER MATRIX THAT DOESN'T ALLOW THE COMPUTER TO PICK THE SAME SPOT
for(I=0;I<23;I++)
{for(J=0;J<22;J++)
	Pick[I][J]=false;
}
//pick(Pick,Spot,X,Y);
carrier(Pick,Chk);
cruiser(Pick,Chk);
gunship(Pick,Chk);
u_boat(Pick,Chk);
aegis(Pick,Chk);
sink(Spot);

getch();
}

//End Program

//***************************************************************************

//Graphics function
void gr_start (int&grdriver,int&grmode,int&errorcode)
{grdriver=VGA;
grmode=VGAHI;
initgraph (&grdriver,&grmode,"c:\\TC\\BGI");
errorcode=graphresult();
	if(errorcode!=grOk)
		{clrscr();
			cout<<"Error:"<<errorcode<<endl;
			cout<<"Press enter to continue";
			getch();
			exit(1);
		}
};
//Pick Function
void pick (apmatrix<bool>Pick&,apmatrix<bool>Spot&)
{
bool Repeat;
do{
		X=random(22);     //goes to P and 23 may not need the +65
		Y=random(15);
		Repeat=false;
			if(Pick[X][Y]||Chk[X][Y])
				Repeat=true;
			else
			 carrier(Pick,Chk,X,Y);	//FUNCTION THAT PLACES THE SHIP
	}while(Repeat);      //place an if in the main function that will do
											//the next function if needed
};
//Sink Ship Function
void sink (apmatrix<bool>Spot&)
{
int X,Y;
bool Repeat;
do{
		X=random(23);
		Y=random(22);
		Repeat=false;
		do{
			 if(Spot[X][Y])
			 {
					//need something that will put the graphic of the ship being hit
					X++;
			 }
				else
					X-=2;
					//graphic of miss
			 }while(Spot[X][Y]);
		do{
			 if(Spot[X][Y])
			 {
				//image of ship being hit
				X--;
			 }
			 else
				//graphic of miss
				X++;
				Y++;
			}while(Spot[X][Y]);
		do{
			 if(Spot[X][Y])
			 {
				//ship hit
				Y++;
			 }
			 else
			 //graphic of miss
			 Y-=2;
			}while(Spot[X][Y]);
		do{
			 if(Spot[X][Y])
			 {
				//ship hit
				Y--;
			 }
			 else
			 //graphic of miss
			 Repeat=true;
			}while(Spot[X][Y]);
	}while(Repeat);
};
//Carrier Placement Function
void carrier (apmatrix<bool>&Pick,apmatrix<bool>&Chk)
{
int M,K,X,Y;     //use actual X and Y
bool Repeat;
M=random(3);
switch(M)
	{ //carrier
			case 0:do{
								X=random(23);
								Y=random(17);
								Repeat=false;
								for(K=0;K<5;K++)          //need to use the users choice
									if(Chk[X][Y+K]||Pick[X][Y+K])         //to decide which direction
										Repeat=true;
								for(K=0;K<5;K++)
									Pick[X][Y+K]=true;
							 }while(Repeat);
						 break;
			case 1:do{
								X=random(18);
								Y=random(22);
								Repeat=false;    //top bottom
								for(K=0;K<5;K++)
									if(Chk[X+K][Y]||Pick[X+K][Y])
										Repeat=true;
								for(K=0;K<5;K++)
									Pick[X+K][Y];
							 }while(Repeat);
						 break;
			case 2:do{
								X=random(18)+5;
								Y=random(22);
								Repeat=false;     //bottom top
								for(K=0;K<5;K++)
									if(Chk[X-K][Y||Pick[X-K][Y]])
										Repeat=true;
								for(K=0;K<5;K++)
									Pick[X-K][Y]=true;
							 }while(Repeat);
						 break;
			case 3:do{
								X=random(23);
								Y=random(17)+5;
								Repeat=false;
								for(K=0;K<5;K++)
									if(Chk[X][Y-K]||Pick[X][Y-K])
										Repeat=true;
								for(K=0;K<5;K++)
									Pick[X][Y-K]=true;
							 }while(Repeat);
						 break;
	}
};
//PUT THIS INTO ANOTHER FUNCTION WITH EACH SHIP AND THEN PLACE BOOL VARIABLES
//EQUAL TO EACH SHIP AND  AN IF IN FRONT THAT ONLY ALLOWS IT TO PLACE THAT
//SHIP WHEN IT IS FALSE
//Gunship Placement Function
void gunship (apmatrix<bool>&Pick,apmatrix<bool>&Chk)
{
int M,K,X,Y;     //use actual X and Y
bool Repeat;
M=random(3);
switch(M)
	{ //carrier
			case 0:do{
								X=random(23);
								Y=random(18);
								Repeat=false;
								for(K=0;K<4;K++)          //need to use the users choice
									if(Chk[X][Y+K]||Pick[X][Y+K])         //to decide which direction
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X][Y+K]=true;
							 }while(Repeat);
						 break;
			case 1:do{
								X=random(19);
								Y=random(22);
								Repeat=false;    //top bottom
								for(K=0;K<4;K++)
									if(Chk[X+K][Y]||Pick[X+K][Y])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X+K][Y];
							 }while(Repeat);
						 break;
			case 2:do{
								X=random(19)+4;
								Y=random(22);
								Repeat=false;     //bottom top
								for(K=0;K<4;K++)
									if(Chk[X-K][Y||Pick[X-K][Y]])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X-K][Y]=true;
							 }while(Repeat);
						 break;
			case 3:do{
								X=random(23);
								Y=random(18)+4;    //right to left
								Repeat=false;
								for(K=0;K<4;K++)
									if(Chk[X][Y-K]||Pick[X][Y-K])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X][Y-K]=true;
							 }while(Repeat);
						 break;
	}
};

//Cruiser Placement Function
void cruiser (apmatrix<bool>&Pick,apmatrix<bool>&Chk)
{
int M,K;     //use actual X and Y
bool Repeat;
M=random(3);
switch(M)
	{ //carrier
			case 0:do{
								X=random(23);
								Y=random(18);
								Repeat=false;
								for(K=0;K<4;K++)          //need to use the users choice
									if(Chk[X][Y+K]||Pick[X][Y+K])         //to decide which direction
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X][Y+K]=true;
							 }while(Repeat);
						 break;
			case 1:do{
								X=random(19);
								Y=random(22);
								Repeat=false;    //top bottom
								for(K=0;K<4;K++)
									if(Chk[X+K][Y]||Pick[X+K][Y])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X+K][Y];
							 }while(Repeat);
						 break;
			case 2:do{
								X=random(19)+4;
								Y=random(22);
								Repeat=false;     //bottom top
								for(K=0;K<4;K++)
									if(Chk[X-K][Y||Pick[X-K][Y]])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X-K][Y]=true;
							 }while(Repeat);
						 break;
			case 3:do{
								X=random(23);
								Y=random(18)+4;
								Repeat=false;
								for(K=0;K<4;K++)
									if(Chk[X][Y-K]||Pick[X][Y-K])
										Repeat=true;
								for(K=0;K<4;K++)
									Pick[X][Y-K]=true;
							 }while(Repeat);
						 break;
	}};

//U-Boat Placement Function
void u_boat (apmatrix<bool>&Pick,apmatrix<bool>&Chk)
{
int M,K;     //use actual X and Y
bool Repeat;
M=random(3);
switch(M)
	{ //carrier
			case 0:do{
								X=random(23);
								Y=random(19);
								Repeat=false;
								for(K=0;K<3;K++)          //need to use the users choice
									if(Chk[X][Y+K]||Pick[X][Y+K])         //to decide which direction
										Repeat=true;
								for(K=0;K<3;K++)
									Pick[X][Y+K]=true;
							 }while(Repeat);
						 break;
			case 1:do{
								X=random(20);
								Y=random(22);
								Repeat=false;    //top bottom
								for(K=0;K<3;K++)
									if(Chk[X+K][Y]||Pick[X+K][Y])
										Repeat=true;
								for(K=0;K<3;K++)
									Pick[X+K][Y];
							 }while(Repeat);
						 break;
			case 2:do{
								X=random(20)+3;
								Y=random(22);
								Repeat=false;     //bottom top
								for(K=0;K<3;K++)
									if(Chk[X-K][Y||Pick[X-K][Y]])
										Repeat=true;
								for(K=0;K<3;K++)
									Pick[X-K][Y]=true;
							 }while(Repeat);
						 break;
			case 3:do{
								X=random(23);
								Y=random(19)+3;
								Repeat=false;
								for(K=0;K<3;K++)
									if(Chk[X][Y-K]||Pick[X][Y-K])
										Repeat=true;
								for(K=0;K<3;K++)
									Pick[X][Y-K]=true;
							 }while(Repeat);
						 break;
	}
};

//Aegis Placement Function
void aegis (apmatrix<bool>&Pick,apmatrix<bool>&Chk)
{
int M,K;     //use actual X and Y
bool Repeat;
M=random(3);
switch(M)
	{ //carrier
			case 0:do{
								X=random(21);
								Y=random(22);
								Repeat=false;
								for(K=0;K<2;K++)          //need to use the users choice
									if(Chk[X][Y+K]||Pick[X][Y+K])         //to decide which direction
										Repeat=true;
								for(K=0;K<2;K++)
									Pick[X][Y+K]=true;
							 }while(Repeat);
						 break;
			case 1:do{
								X=random(23);
								Y=random(20);
								Repeat=false;    //top bottom
								for(K=0;K<2;K++)
									if(Chk[X+K][Y]||Pick[X+K][Y])
										Repeat=true;
								for(K=0;K<2;K++)
									Pick[X+K][Y];
							 }while(Repeat);
						 break;
			case 2:do{
								X=random(21)+2;
								Y=random(22);
								Repeat=false;     //bottom top
								for(K=0;K<2;K++)
									if(Chk[X-K][Y||Pick[X-K][Y]])
										Repeat=true;
								for(K=0;K<2;K++)
									Pick[X-K][Y]=true;
							 }while(Repeat);
						 break;
			case 3:do{
								X=random(23);
								Y=random(20)+2;
								Repeat=false;
								for(K=0;K<2;K++)
									if(Chk[X][Y-K]||Pick[X][Y-K])
										Repeat=true;
								for(K=0;K<2;K++)
									Pick[X][Y-K]=true;
							 }while(Repeat);
						 break;
	}
};