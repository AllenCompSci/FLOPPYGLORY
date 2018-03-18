/*******************PHOENIX******************
//5-17-02
//Adam & Shoaib
//Computer Science 1 Final Exam
//To move right and left, move the mouse in the desired direction.  When
//shooting, you have three choices.  Click the right mouse button to shoot
//from the right side of the ship.  Click the left mouse button to shoot from
//the left side of the ship.  Click both buttons to have the computer decide
//randomly for each bullet.  You can score points by shooting enemies.  When
//you shoot an enemy, another one will appear at the top of the screen, so
//don't get lazy.  If you get hit by an enemy's bullet, your health meter will
//go down.  If your health meter goes all the way down, you die.  You may use
//another life (if you have any) to refill your health meter.
********************************************/
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<gmouse.h>
#include<bitmap.h>
#include<malloc.h>
#include<time.h>
#include"a:\game\mymouse.h"

//structures section
struct coordinates										//coordinates for bullets & ships
{
	int X,Y;														//X and Y loacation
};
struct enemy_type											//Enemy
{
	bool Shot;													//Has the ship ben shot
	coordinates Loc;										//Where is the ship
	int D;															//Which direction is the ship going
};
struct hi_score_type									//Hi Scores database
{
	apstring Name;											//I hope this goes without explanation
	long Score;
};

//constant section
const int B_PAUSE=500; 								//delay between bullets
const int ENEMIES=10;									//Number of enemies in game
const int _BLACK     =0;							//define custon colors
const int _DARKRED   =1;
const int _DARKGREEN =2;
const int _DARKYELLOW=3;
const int _DARKBLUE  =4;
const int _DARKPURPLE=5;
const int _DARKCYAN  =6;
const int _DARKGRAY  =7;
const int _GRAY      =8;
const int _RED       =9;
const int _GREEN     =10;
const int _YELLOW    =11;
const int _BLUE      =12;
const int _PURPLE    =13;
const int _CYAN      =14;
const int _WHITE     =15;


//variable section
int grdriver,grmode,errorcode;

void far *Ship;		 										//pointer to image of ship
void far *Bullet;											//pointer to image of bullet
void far *E_Bullet;										//pointer to image of enemy bullet
void far *Enemy;											//pointer to image of enemy
apvector <coordinates> Bullets (0);		//array of bullets
apvector <coordinates> E_Bullets (0);	//array of enemy bullets
apvector <enemy_type> Enemies (0);		//array of enemies
apvector <hi_score_type> Hi_Scores (0);	//array of high scores

void gr_start(int &,int &,int &);
void First_Load();										//Loads all images
void Pre_Load(int &E,int &B_Pause,int &P_count,double &Shields,bool &Done,bool &Died,coordinates &New);
																			//Sets all pre-game variables
void Game();													//contains main game loop
void draw_ship();											//draws ship on screen to be saved
void draw_enemy();										//draws enemy on screen to be saved
void P_Wp(long &Score);								//move bullets & collision detection
void M_Wave();												//fill array with enemies
void P_Enm(int &E);										//moves all ships
void P_Input(bool &Done);							//checks if esc was hit and quits
void P_En_Wp(coordinates &New,double &Shields,bool &Done,bool &Died);
																			//move E. bullets & collision detection
void Load_hi_scores();								//Loads high scores database from file
void Save_hi_scores();								//Read above, you can figure this out
void Sh_scores();											//Shows scores on screen
void Help();													//shows help file

void main()
{
	coordinates Mouse;									//where is the mouse
	bool Done;													//is the game done
	gr_start(grdriver,grmode,errorcode);//start graphics
	First_Load();												//load all pictures
	SetMouse();													//turn on mouse
	SetXLimits(0,getmaxx()-96);					//limit mouse to screensize - image size
	Done=false;													//not done yet
	do
	{
		clrscr();
		cleardevice();
		setcolor(_BLUE);									//set color to blue
		setfillstyle(1,_BLUE);						//set fill style to solid blue
		bar(6-4,93-4,194+4,123+4);				//draw boxes
		bar(6-4,153-4,194+4,183+4);
		bar(6-4,213-4,194+4,243+4);
		bar(6-4,273-4,194+4,303+4);
		settextjustify(CENTER_TEXT,CENTER_TEXT);	//center text
		settextstyle(1,HORIZ_DIR,0);			//set font
		setcolor(_WHITE);									//set color to white
		outtextxy(100,100,"Play");				//draw text
		outtextxy(100,160,"High Scores");
		outtextxy(100,220,"Help");
		outtextxy(100,280,"Quit");
		outtextxy(320,40,"PHOENIX");
		ShowMouse();											//let the user see where they click
		//Unusual mouse bug causes screen to flicker at this point
		GetMouseButton();									//weird programming bug????
		while(GetMouseButton()==0);				//wait for mouse click
		GetMouseButton();									//weird programming bug????
		Mouse.X=GetMouseX();							//save x cooridnate of mouse
		Mouse.Y=GetMouseY();							//save y cooridnate of mouse
		if(Mouse.X>2 && Mouse.X<198)			//if in the collum of buttons
		{
			if(Mouse.Y>89 && Mouse.Y<127)		//if play was clicked
			{
				GetMouseButton();							//weird programming bug????
				HideMouse();									//user dosen't want to see mouse in game
				Game();												//run game
			}
			if(Mouse.Y>149 && Mouse.Y<187)	//if high scores was clicked
			{
				GetMouseButton();							//weird programming bug????
				HideMouse();									//hide mouse in high scores
				Sh_scores();									//show the high scores
			}
			if(Mouse.Y>209 && Mouse.Y<247)	//if help was pressed
			{
				GetMouseButton();							//weird programming bug????
				HideMouse();									//hide mouse in help
				Help();												//show help file
			}
			if(Mouse.Y>269 && Mouse.Y<307)	//if quit was pressed
			{
				GetMouseButton();							//weird programming bug????
				Done=true;										//game is done
			}
		}
	GetMouseButton();										//weird programming bug????
	}while(!Done);											//keep going while not done
	closegraph();												//end graphics
}

/********************GAME*********************GAME********************/
void Game()
{
	int Lives;				 									//number of lives left
	int B_Pause;												//counts between shots
	int E;															//what enemy is currently going
	int Button;													//what buttons are being pressed
	int P_count;												//counts program loops
	long Score;			 										//keeps score
	double Shields;											//RED ALERT!! SHIELDS UP!
	bool Done;				 									//same as in main() but not related
	bool Died;													//has the player died
	coordinates New,Old;								//new and old coordinates;
	int S1,S2;													//indexed for high scores
	Score=0;														//score starts at 0
	Lives=5;														//you get 5 lives
/************FPS***********
	int Loops;													//counts program loops for finding fps
	time_t Old_t,New_t;									//keep time for fps
**************************/
	do
	{
/************FPS***********
		Loops=0;													//no loops yet
		time(&Old_t);											//get old time
**************************/
		Pre_Load(E,B_Pause,P_count,Shields,Done,Died,New);//clear all variables
		putimage(New.X,New.Y,Ship,COPY_PUT);//put ship on screen to start
		setcolor(_WHITE);									//setcolor to white
		line(0,479,639,479);							//draw full shields
		setcolor(_BLACK);									//setcolor to black
		do
		{
/************FPS***********
			if(Old_t<time(&New_t))					//if 1 sec has passed
			{
				gotoxy(1,1);									//at top of screen
				cout<<setw(5)<<Loops;					//draw the number of loops since
				Loops=0;											//reset number of loops
				time(&Old_t);									//set a new old time
			}
			Loops++;												//increment loops
**************************/

			if(kbhit())											//if a key has been pressed
				P_Input(Done);								//process it

			Old.X=New.X;										//save x coordinates
			New.X=GetMouseX();							//get new mouse x
			if(Old.X!=New.X)								//if x coordinate has changed
			{
				bar(Old.X,407,Old.X+95,407+71);	//erse old ship
				putimage(New.X,New.Y,Ship,COPY_PUT);	//draw new ship
			}

			P_count++;											//incrament program counter
			if(P_count==50)									//if program counter reaches 50
			{
				P_count=0;										//reset it
				E++;													//go to next enemy
				if(E==ENEMIES)								//if past the last enemy
					E=0;												//go to first
				Enemies[E].D=random(4);				//choose a random direction for the it
			}
			P_Enm(E);												//process the enemies

			if(B_Pause>0)										//if the bullet has a pause
				B_Pause--;										//decrement by one

			if(P_count%5==0)								//every five loops
			{
				P_Wp(Score);									//process weapons
				P_En_Wp(New,Shields,Done,Died);	//process enemy weapons
			}

			Button=GetMouseButton();				//save button state
			if(Button)											//if a button has been pressed
			{
				if(B_Pause==0)								//if there is no bullet pause
				{
					if(Button==3)								//if both buttons are being pressed
						Button=random(2)+1;				//pick randomly between guns
					if(Button==1)								//if left button was pressed
					{
						B_Pause=B_PAUSE;					//reinstate pause
						Bullets.resize(Bullets.length()+1);	//make space for new bullet
						Bullets[Bullets.length()-1].X=New.X+1;	//save x of bullet
						Bullets[Bullets.length()-1].Y=New.Y-9;	//save y of bullet
						putimage(New.X+1,New.Y-9,Bullet,COPY_PUT);	//draw bullet
					}
					if(Button==2)								//if right button was pressed
					{
						B_Pause=B_PAUSE;					//reinstate pause
						Bullets.resize(Bullets.length()+1);	//make space for new bullet
						Bullets[Bullets.length()-1].X=New.X+87;	//save x of bullet
						Bullets[Bullets.length()-1].Y=New.Y-9;	//save y of bullet
						putimage(New.X+87,New.Y-9,Bullet,COPY_PUT);	//draw new bullet
					}
				}
			}
		}while(!Done);										//continue while not done
		clrscr();
		cleardevice();
		if(Died)													//if the user died but diden't quit
		{
			Lives--;												//loose a live
			cout<<"You have died"<<endl<<endl;
			if(Lives)												//if they still have lives left
			{
				cout<<"You have "<<Lives<<" lives left."<<endl;
				cout<<"Your score: "<<Score<<endl<<endl;
			}
			else														//if thay have no lives left
			{
				cout<<"You have no lives left"<<endl;
				cout<<"Your final score is "<<Score<<endl<<endl;
			}
			cout<<"Press a key to continue";//I find users like to see the message
			getch();												//before continuing
		}
		else															//if the user did quit
			Lives=0;												//fake the do/while into quiting
	}while(Lives);											//stop when no lives left

	if(Score)														//if the user has a score
	{
		if(Hi_Scores.length()==0)					//if there are no scores
		{
			Hi_Scores.resize(1);						//make a spot
			clrscr();
			cleardevice();
			cout<<"You have a high score!"<<endl;
			cout<<"Enter your name:";
			getline(cin,Hi_Scores[0].Name);	//get users name
			Hi_Scores[0].Score=Score;				//save their score
			Save_hi_scores();								//save all scores
		}
		else
		{
			for(S1=0;S1<Hi_Scores.length();S1++)	//for all the existing scores
				if(Hi_Scores[S1].Score<Score)	//if their score is higher
				{
					if(Hi_Scores.length()<5)		//if their are less than 5 scores
						Hi_Scores.resize(Hi_Scores.length()+1);	//make space
					for(S2=Hi_Scores.length()-1;S2>S1;S2--)	//for all scores behind it
						Hi_Scores[S2]=Hi_Scores[S2-1];	//move them back
					clrscr();
					cleardevice();
					cout<<"You have a high score!"<<endl;
					cout<<"Enter your name:";
					getline(cin,Hi_Scores[S1].Name);	//get name
					Hi_Scores[S1].Score=Score;	//save score
					Save_hi_scores();						//save all scores
					break;											//stop looping
				}
		}
	}
	Sh_scores();												//show high scores
	SetXLimits(0,getmaxx());						//restore mouse limits
}

/***********SH_SCORES***********SH_SCORES*****************/
void Sh_scores()											//shows high scores
{
	int S;															//score index
	clrscr();
	cleardevice();
	if(Hi_Scores.length()==0)						//if there are no scores
		cout<<"There are currently no high scores."<<endl;
	else																//if there are scores
	{
		cout<<"High Scores"<<endl;
		cout<<setw(20)<<"Name"<<setw(10)<<"Score"<<endl;
		for(S=0;S<Hi_Scores.length();S++)	//for each score
		{
			cout<<setw(20)<<Hi_Scores[S].Name;	//show name and score
			cout<<setw(10)<<Hi_Scores[S].Score<<endl;
		}
	}
	cout<<endl<<"Press a key to continue.";	//whait for slow users
	getch();
}

/***********FIRST_LOAD**********FIRST_LOAD**************/
void First_Load()
{
	unsigned S;				 									//size of image
	image MyImage;											//image file
	int X_sense=20,Y_sense=20,B_sense=1;//mouse sensitiviy
	randomize();												//randomize program
	Load_hi_scores();										//load the hich scores database
	SetMouseSensitivity(&X_sense,&Y_sense,&B_sense);	//change mouse sensitivity
	clrscr();
	cleardevice();
	MyImage.open("A:\\game\\palette.bmp");	//load custom palette
	MyImage.close();										//close image of custom palette
	draw_ship();												//draw ship
	S=imagesize(0,0,95,71);							//get size of ship
	Ship=farmalloc(S);									//get memory for ship
	getimage(0,0,95,71,Ship);						//save image of ship
	cleardevice();											//clear image of ship
	draw_enemy();												//repeat last 5 images for enemy
	S=imagesize(0,0,32,21);
	Enemy=farmalloc(S);
	getimage(0,0,32,21,Enemy);
	cleardevice();
	setcolor(_YELLOW);									//set color of bullets
	line(0,2,0,5);											//draw bullet
	line(1,1,1,4);
	line(2,0,2,3);
	line(3,0,3,3);
	line(4,1,4,4);
	line(5,2,5,5);
	S=imagesize(0,0,5,5);								//get size of bullet
	Bullet=farmalloc(S);								//get memory for bullet
	getimage(0,0,5,5,Bullet);						//save image of bullet
	cleardevice();
	setcolor(_RED);											//set color of enemy bullets
	line(0,0,0,2);											//draw enemy bullet
	line(1,1,1,3);
	line(2,2,2,4);
	line(3,2,3,4);
	line(4,1,4,3);
	line(5,0,5,2);
	S=imagesize(0,0,5,5);								//get size of enemy bullet
	E_Bullet=farmalloc(S);							//get memory for enemy bullet
	getimage(0,0,5,5,E_Bullet);					//save image of enemy bullet
	clrscr();
	cleardevice();
}

/*************PRE_LOAD*************PRE_LOAD**************/
void Pre_Load(int &E,int &B_Pause,int &P_count,double &Shields,bool &Done,bool &Died,coordinates &New)
//resets all variables before game sesions
//takes in a tone of vars to clear
{
	M_Wave();														//fill enemy array
	Done=false;													//the game is not done when it starts
	Died=false;													//you havend died (yet)
	B_Pause=0;													//you can fire right away
	E=0;																//start with enemy #0
	P_count=0;													//no program loops
	Shields=1.00;												//shields at 100%
	New.Y=getmaxy()-72;									//set y coord. screensize - image size
	New.X=GetMouseX();									//set x coordinate
	setcolor(_BLACK);
	setfillstyle(1,_BLACK);							//set color and fill to solid black
	E_Bullets.resize(0);								//clear all bullets by setting size to 0
	Bullets.resize(0);									//and again for user bullets
	clrscr();
	cleardevice();
}

/***************P_INPUT**************P_INPUT**************/
void P_Input(bool &Done)							//checks for esc key
//leftover from when you used keys to move
{
	int Key;														//need a place to store the key
	Key=getch();												//save key
	if(Key==27)													//if key==escape
		Done=true;												//game is done
}

/*******************P_WP****************P_WP**************/
void P_Wp(long &Score)								//processes players weapons
{
	bool Hit;														//has an enemy been hit
	int B;															//bullet counter
	int D;															//delete counter
	int E;															//enemy counter
	for(B=0;B<Bullets.length();B++)			//for each bullet
	{
		bar(Bullets[B].X,		Bullets[B].Y,\
				Bullets[B].X+5,	Bullets[B].Y+5);	//erase bullet
		Bullets[B].Y--;										//move up
		if(Bullets[B].Y<0)								//if it has moved off the screen
		{
			for(D=B;D<Bullets.length()-1;D++)	//for all bullets ahead of it
				Bullets[D]=Bullets[D+1];			//move it back one
			Bullets.resize(D);							//resize array
			B--;														//reprocess bullet
		}
		else															//if still on screen
		{
			Hit=false;											//nothing has been hit
			for(E=0;E<ENEMIES;E++)					//for all enemies
			 if(Enemies[E].Loc.X<=Bullets[B].X+5)	//left side
				if(Enemies[E].Loc.X+30>=Bullets[B].X)	//right side
				 if(Enemies[E].Loc.Y>=Bullets[B].Y-5)	//top side
					if(Enemies[E].Loc.Y-19<=Bullets[B].Y )	//bottom side
					{
						Score+=10;								//give measley points
					 Enemies[E].Shot=true;			//enemy has been shot
					 for(D=B;D<Bullets.length()-1;D++)	//for all bullets ahead of it
						Bullets[D]=Bullets[D+1];	//move it back one
					 Bullets.resize(D);					//resize array
					 B--;												//reprocess bullet
					 Hit=true;									//bullet has hit somthing
					 break;											//stop checking enemies
					}
			if(!Hit)												//if bullet hasen't hit anything
				putimage(Bullets[B].X,Bullets[B].Y,Bullet,COPY_PUT);//draw new bullet
		}
	}
}

/****************P_EN_WP**************P_EN_WP*************/
void P_En_Wp(coordinates &New,double &Shields,bool &Done,bool &Died)
//process enemy weapons
{
	bool Hit;														//has the bullet hit the player
	int B,D;														//bullet counter, delete counter
	for(B=0;B<E_Bullets.length();B++)		//for each bullet
	{
		bar(E_Bullets[B].X,		E_Bullets[B].Y,\
				E_Bullets[B].X+5,	E_Bullets[B].Y+5);	//erase bullet
		E_Bullets[B].Y++;									//move down
		if(E_Bullets[B].Y>473)						//if it has moved off the screen
		{
			for(D=B;D<E_Bullets.length()-1;D++)	//for all bullets ahead of it
				E_Bullets[D]=E_Bullets[D+1];	//move it back one
			E_Bullets.resize(D);						//resize array
			B--;														//reprocess bullet
		}
		else															//if still on screen
		{
			Hit=false;											//nothing hit yet
			if(E_Bullets[B].Y+5>=407)				//left side
				if(E_Bullets[B].X+5>=New.X)		//right side
					if(E_Bullets[B].X<=New.X+94)//top side
					{
						Shields-=0.10;						//reduce shields by 10%
						if(Shields<=0.0)					//if shields gone
						{
							Done=true;							//game done
							Died=true;							//player has died
						}
						line(0,479,639,479);			//clear shields
						setcolor(_WHITE);					//set color of shields
						line(0,479,int(639.0*Shields),479);	//redraw shield bars
						setcolor(_BLACK);					//set color back
						for(D=B;D<E_Bullets.length()-1;D++)	//for all bullets ahead of it
							E_Bullets[D]=E_Bullets[D+1];	//move it back one
						E_Bullets.resize(D);			//resize array
						B--;											//reprocess bullet
						Hit=true;									//the bullet hit the player
					}
		if(!Hit)													//if the bullet diden't hit the player
	putimage(E_Bullets[B].X,E_Bullets[B].Y,E_Bullet,COPY_PUT);//draw new bullet
		}
	}
}

/******************P_ENM******************P_ENM*************/
void P_Enm(int &E)										//process enemies
{
	if(Enemies[E].Shot)									//if the enemy has been shot
	{
		bar(Enemies[E].Loc.X-1,		Enemies[E].Loc.Y-1,\
				Enemies[E].Loc.X+30,Enemies[E].Loc.Y+19);	//erase it
		Enemies[E].Loc.X=random(609);			//give it random X
		Enemies[E].Loc.Y=0;								//start it at top
		Enemies[E].Shot=false;						//no longer shot
	}
	else																//if the enemy has not been shot
	{
		switch(Enemies[E].D)							//depending on direction going
		{
			case 0:	if(Enemies[E].Loc.Y>1)	//if it can move up
								Enemies[E].Loc.Y--;		//move it up
							break;									//don't move it anywhere else
			case 1:	if(Enemies[E].Loc.X<608)//repeat 3 lines above for right
								Enemies[E].Loc.X++;
							break;
			case 2:	if(Enemies[E].Loc.Y<350)//repeat again for down
								Enemies[E].Loc.Y++;
							break;
			case 3:	if(Enemies[E].Loc.X>1)	//and again for left
								Enemies[E].Loc.X--;
		}
		putimage(Enemies[E].Loc.X-1,Enemies[E].Loc.Y-1,Enemy,COPY_PUT);
														//redraw ship, includes 1 pixl border to old ship
		if(random(200)==0)								//a 1 in 200 shot
		{
			E_Bullets.resize(E_Bullets.length()+1);//make space for new bullet
			E_Bullets[E_Bullets.length()-1].X=Enemies[E].Loc.X+13;//save x of bullet
			E_Bullets[E_Bullets.length()-1].Y=Enemies[E].Loc.Y+20;//save y of bullet
			putimage(Enemies[E].Loc.X+13,Enemies[E].Loc.Y+20,E_Bullet,COPY_PUT);
																			//draw bullet
		}
	}
}

/**************M_WAVE*************M_WAVE*****************/
void M_Wave ()												//make all bullets
{
	int E;															//enemy counter
	Enemies.resize(ENEMIES);						//make space
	for(E=0;E<ENEMIES;E++)							//for all enemies
	{
		Enemies[E].Loc.X=random(609);			//random x
		Enemies[E].Loc.Y=0;								//at top
		Enemies[E].Shot=false;						//not shot
	}
}

/*********LOAD_HI_SCORES*********LOAD_HI_SCORES********/
void Load_hi_scores()									//gets high scores from file
{
	ifstream File;											//file handle
	apstring Trash;											//get rid of garbage
	int Scores;													//number of high scores
	int S;															//score counter
	File.open("a:\\game\\hiscores.dat");//open high scores files
	File>>Scores;												//finde out how many scores in it
	getline(File,Trash);								//before last cin/File, before getline
	Hi_Scores.resize(Scores);						//make enough space
	for(S=0;S<Scores;S++)								//for all scores in file
	{
		getline(File,Hi_Scores[S].Name);	//save name
		File>>Hi_Scores[S].Score;					//save score
		getline(File,Trash);							//again get garbage
	}
	File.close();												//close file
}

/********SAVE_HI_SCORES**********SAVE_HI_SCORES*********/
void Save_hi_scores()									//save high scores to file
{
	ofstream File;											//file handle
	int S;															//score counter
	File.open("a:\\game\\hiscores.dat");//open file
	File<<Hi_Scores.length()<<endl;			//write number of scores
	for(S=0;S<Hi_Scores.length();S++)		//for all scores
		File<<Hi_Scores[S].Name<<endl<<Hi_Scores[S].Score<<endl;
																			//write name and score
	File.close();												//close file
}

/***********DRAW_ENEMY**********DRAW_ENEMY**************/
void draw_enemy()											//draw enemy ship on screen
//because bitmap functions only get everyother column of pixels I choose to
//draw it myself to maintain high resolution.
{
	setfillstyle(1,_BLUE);
	setcolor(_BLUE);
	bar(12,1,20,10);
	setcolor(_YELLOW);
	setfillstyle(1,_YELLOW);
	bar(12,11,20,12);
	bar(13,13,19,14);
	bar(14,15,18,16);
	bar(15,17,17,18);
	line(16,19,16,20);
	setcolor(_CYAN);
	setfillstyle(1,_CYAN);
	putpixel(21,8,_CYAN);
	bar(21,1,27,7);
	putpixel(27,8,_CYAN);
	bar(28,2,29,17);
	line(30,3,30,17);
	line(31,5,31,17);
	putpixel(11,9,_CYAN);
	bar(11,1,5,8);
	putpixel(5,9,_CYAN);
	bar(4,2,3,17);
	line(2,3,2,17);
	line(1,5,1,17);
	setcolor(_RED);
	rectangle(2,18,3,19);
	rectangle(29,18,30,19);
}

/**************DRAW_SHIP******************DRAW_SHIP**************/
void draw_ship()											//draws ship on screen
																			//see above for reason
{
	/*****************GRAY*****************/
	setcolor(_GRAY);
	setfillstyle(1,_GRAY);
	/*****************NOSE*****************/
	line(43,0,52,0);
	line(41,1,54,1);
	line(40,2,55,2);
	line(39,3,56,3);
	line(38,4,57,4);
	line(37,5,58,5);
	bar(36,6,59,7);
	bar(35,8,60,9);
	bar(34,10,61,25);
	/***************LEFT WING**************/
	bar(0,10,9,11);
	bar(0,12,10,13);
	bar(0,14,11,15);
	bar(0,16,12,17);
	bar(0,18,13,19);
	bar(0,20,14,21);
	bar(0,22,15,23);
	bar(0,24,16,25);
	/**************RIGHT WING**************/
	bar(86,10,95,11);
	bar(85,12,95,13);
	bar(84,14,95,15);
	bar(83,16,95,17);
	bar(82,18,95,19);
	bar(81,20,95,21);
	bar(80,22,95,23);
	bar(79,24,95,25);
	/**************MAIN BODY***************/
	bar(0,26,95,48);
	/****************BOTTOM****************/
	line(2,49,93,49);
	line(4,50,91,50);
	line(6,51,89,51);
	line(8,52,87,52);
	line(10,53,85,53);
	line(12,54,83,54);
	line(14,55,81,55);
	/*************LEFT ENGINE**************/
	line(23,56,36,56);
	bar(24,57,35,59);
	/*************RIGHT ENGINE*************/
	line(59,56,72,56);
	bar(60,57,71,59);

	/*****************RED******************/
	setcolor(_RED);
	setfillstyle(1,_RED);
	/**************LEFT WING***************/
	bar(4,0,4,1);
	bar(3,2,5,3);
	bar(2,4,6,5);
	bar(1,6,7,7);
	/**************RIGHT WING**************/
	bar(91,0,91,1);
	bar(90,2,92,3);
	bar(89,4,93,5);
	bar(88,6,94,7);
	/*************LEFT ENGINE**************/
	line(25,68,34,68);
	line(26,69,33,69);
	line(27,70,32,70);
	line(28,71,31,71);
	/************RIGHT ENGINE**************/
	line(61,68,70,68);
	line(62,69,69,69);
	line(63,70,68,70);
	line(64,71,67,71);

	/**************DARK GRAY***************/
	setcolor(_DARKGRAY);
	setfillstyle(1,_DARKGRAY);
	/**************LEFT WING***************/
	bar(0,8,8,9);
	/*************RIGHT WING***************/
	bar(87,8,95,9);
	/****************COLLAR****************/
	putpixel(34,25,_DARKGRAY);
	putpixel(61,25,_DARKGRAY);
	line(31,26,35,26);
	line(60,26,64,26);
	line(32,27,37,27);
	line(58,27,63,27);
	line(33,28,39,28);
	line(56,28,62,28);
	line(35,29,41,29);
	line(54,29,60,29);
	line(37,30,58,30);
	line(39,31,56,31);
	line(41,32,54,32);
	/*************LEFT ENGINE**************/
	line(23,60,36,60);
	line(22,61,37,61);
	line(21,62,38,62);
	line(20,63,39,63);
	/*************RIGHT ENGINE*************/
	line(59,60,72,60);
	line(58,61,73,61);
	line(57,62,74,62);
	line(56,63,75,63);

	/*****************CYAN*****************/
	setcolor(_CYAN);
	setfillstyle(1,_CYAN);
	/*************FRONT WINDOW*************/
	bar(43,4,52,13);
	bar(42,5,53,12);
	bar(41,6,54,12);
	bar(40,7,55,12);
	bar(39,9,56,12);
	line(38,11,57,11);
	line(47,14,48,14);
	/*************LEFT WINDOW**************/
	bar(39,16,45,25);
	line(39,15,42,15);
	line(38,16,38,24);
	line(46,17,46,24);
	/*************RIGHT WINDOW*************/
	bar(50,16,56,25);
	line(53,15,56,15);
	line(49,17,49,24);
	line(57,16,57,24);

	/****************YELLOW****************/
	setcolor(_YELLOW);
	/**************LEFT WING***************/
	line(0,12,2,10);
	line(0,13,3,10);
	line(0,14,4,10);
	line(0,15,5,10);
	line(5,15,9,11);
	line(6,15,9,12);
	line(7,15,10,12);
	line(8,15,10,13);
	/**************RIGHT WING**************/
	line(84,14,88,10);
	line(84,15,89,10);
	line(85,15,90,10);
	line(86,15,91,10);
	line(91,15,95,11);
	line(92,15,95,12);
	line(93,15,95,13);
	line(94,15,95,14);
	/****************BOTTOM****************/
	line(4,50,7,50);				//1
	putpixel(6,51,_YELLOW);
	line(10,52,12,50);			//2
	line(10,53,13,50);
	line(11,53,14,50);
	line(12,53,15,50);
	line(15,55,20,50);			//3
	line(16,55,21,50);
	line(17,55,22,50);
	line(18,55,23,50);
	line(23,55,28,50);			//4
	line(24,55,29,50);
	line(25,55,30,50);
	line(26,55,31,50);
	line(31,55,36,50);			//5
	line(32,55,37,50);
	line(33,55,38,50);
	line(34,55,39,50);
	line(39,55,44,50);			//6
	line(40,55,45,50);
	line(41,55,46,50);
	line(42,55,47,50);
	line(47,55,52,50);			//7
	line(48,55,53,50);
	line(49,55,54,50);
	line(50,55,55,50);
	line(55,55,60,50);			//8
	line(56,55,61,50);
	line(57,55,62,50);
	line(58,55,63,50);
	line(63,55,68,50);			//9
	line(64,55,69,50);
	line(65,55,70,50);
	line(66,55,71,50);
	line(71,55,76,50);			//10
	line(72,55,77,50);
	line(73,55,78,50);
	line(74,55,79,50);
	line(79,55,84,50);			//11
	line(80,55,85,50);
	line(81,55,86,50);
	line(83,54,87,50);
	/**************LEFT ENGINE*************/
	line(21,64,38,64);
	line(22,65,37,65);
	line(23,66,36,66);
	line(24,67,35,67);
	/*************RIGHT ENGINE*************/
	line(57,64,74,64);
	line(58,65,73,65);
	line(59,66,72,66);
	line(60,67,71,67);
}

void Help()
{
	ifstream File;
	apstring Line;
	int L;
	clrscr();
	cleardevice();
	File.open("a:\\game\\readme.dat");
	for(L=0;L<50;L++)
	{
		getline(File,Line);
		if(Line.length()==1 && Line[0]=='#')
		{
			cout<<endl<<"Press A Key To Continue";
			getch();
			clrscr();
			cleardevice();
		}
		else
		{
			cout<<Line;
			if(Line.length()!=80)
				cout<<endl;
		}
	}
	File.close();
}

void gr_start(int & grdriver,int & grmode,int & errorcode)
{
	grdriver=VGA;
	grmode=VGAHI;
	initgraph(& grdriver,& grmode,"C:\\TC\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		clrscr();
		cout<<"error:"<<errorcode<<endl;
		cout<<"Press Return to Continue.";
		getch();
		exit(1);
	}
}