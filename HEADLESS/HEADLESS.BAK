
//Chris Perkic and Stephanie Hilz
//Mike the Headless Chicken, game like frogger, w/story line, incorporates
			//the true story of Mike the Headless Chicken
//Period #2
//Mr. Baker
//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<alloc.h>
#include<dos.h>
#include<ctype.h>
#include<bitmap.h>


//Cost Section
const int MxLn=8;//max lane number
//Structure Section
struct car//car structure
{
int x;//x coordinate of car
};
struct lane//lane structure
{
car cars [4];//array for car data in each lane
int numcars;//total num of cars per lane
int v;//velocity of cars in each lane
};
//Prototype Section
void squish(bool&,bool&,int,int);//Collision Detection between chicken and car
void gr_start(int &, int &, int &);  //Graphic Mode Function
void chick(int,bool&);  //Chicken Function
void startscn();  //Start Screen with menu
void instruct();  //Instruction Screen
void hiscore();  //High Score Screen
void go(bool);  //Game Over function
	void initlanes (int);//initializes car positions in lanes
	void placement ();//controls movement of cars in lanes
	void game();
	void level_change();//switch moving game through storyline and levels
	void story();//mikes story
	void overview();//game overview
	void menu();//menu instructions
	void credits();//game credits
	void play();//instructions for game play
	void setup();//instructions for game set up and scoring
//Global Varible Section
int grdriver, grmode, errorcode;
	int Points;//points for levels
 lane lanes [8];//lane natural array
	unsigned size;//size variable
	void far *S;//size variable for car
	image Road;//road image
	image Farm;//farm image
void main()
{
 clrscr();
 randomize();
 gr_start(grdriver, grmode, errorcode);
 Road.open("a:\\road2.bmp");//opens road background
		setbkcolor(0);
		//designs cars, sets their size
		setfillstyle(1,random(14)+1);
	 bar(0,40,20,20);
	 size=imagesize(0,40,20,20);
	 S=farmalloc(size);
	 getimage(0,40,20,20,S);
	 cleardevice();  //all of that just set size of car image, which is S
 cleardevice();
 startscn();
}



//Functions

//Graphics Mode Function

void gr_start(int & grdriver, int & grmode, int & errorcode)
 {
	grdriver=VGA;
	grmode=VGAHI;

	initgraph(&grdriver, &grmode, "C:\\Tc\\BGI");
	errorcode=graphresult();
	if(errorcode!=grOk)
	 {
		clrscr();
		cout<<"Error:"<<errorcode<<endl;
		cout<<"Press return to continue";
		getch();
		exit(1);
	 }
 };


//Chicken function
void squish(bool &End,bool &Win,int X,int Y)
{
int Ln,Cr;
for (Ln=0;Ln<MxLn;Ln++)
	if (Ln*30+157==Y)
		for (Cr=0;Cr<lanes[Ln].numcars;Cr++)
			if ((X-10>=lanes[Ln].cars[Cr].x&&X-10<=lanes[Ln].cars[Cr].x+20)||
			(X+10>=lanes[Ln].cars[Cr].x&&X+10<=lanes[Ln].cars[Cr].x+20))
			{
				End=true;
				Win=false;
			}
};
//places and moves cars
void placement()
{
	int Ln,Cr;//lane and car counters
	for(Ln=0;Ln<MxLn;Ln++)//lane
	{
		for(Cr=0;Cr<lanes[Ln].numcars;Cr++)//car
		{
			if(lanes[Ln].cars[Cr].x>640)//if goes off screen
				lanes[Ln].cars[Cr].x=0;//resets to screen edge
		}
	}
	for(Ln=0;Ln<MxLn;Ln++)
		for(Cr=0;Cr<lanes[Ln].numcars;Cr++)
			putimage(lanes[Ln].cars[Cr].x,30*Ln+147, S, COPY_PUT);
	delay(15);
	for(Ln=0;Ln<MxLn;Ln++)
		for(Cr=0;Cr<lanes[Ln].numcars;Cr++)
		{
			putimage(lanes[Ln].cars[Cr].x,30*Ln+147,S, XOR_PUT);
			lanes[Ln].cars[Cr].x+=lanes[Ln].v;//adds v
		}
};
//initializes car starting positions
void initlanes(int Level)
{
	int Lev_spd;//speed of cars
	int Ln,Cr;//lane and car counters

	Lev_spd=Level/2;

	for(Ln=0;Ln<MxLn;Ln++)//lane
	{
		lanes[Ln].numcars=4;
		lanes[Ln].v=random(Lev_spd)+1;//sets velocity
		lanes[Ln].cars[0].x=random(640)+1;
		for(Cr=1;Cr<lanes[Ln].numcars;Cr++)//car
		{
			lanes[Ln].cars[Cr].x=lanes[Ln].cars[0].x+160*Cr;//starts out each car in a random x spot
			if(lanes[Ln].cars[Cr].x>640)
				lanes[Ln].cars[Cr].x-=640;
		}
	}
};
//chicken function
void chick(int Level,bool& Win)
 {
	//Local Vars
	int Dir;  //Direction entered from user
	int X,Y;  //Coordinates
	bool End;//bool for if game ends
	unsigned Size;  //Size of chicken
	void far *P;//size variable
	int A;  //Loop var

	X=getmaxx()/2;  //Coordinates where chicken starts
	Y=getmaxy()-82;

	//Chicken Image
	setcolor(WHITE);
	circle(X,Y, 10);
	Size=imagesize(X-10,Y-10, X+10,Y+10);
	P=farmalloc(Size);
	getimage(X-10,Y-10, X+10,Y+10, P);
	cleardevice();
	Road.draw(10,10);

	//Chicken Movement
	Dir=0;
	End=false;
	Win=false;
	initlanes(Level);
	putimage(X-10,Y-10, P, COPY_PUT);
	while (!End&&Dir!=27)
	{
		if(kbhit())
		{
			putimage(X-10,Y-10, P, XOR_PUT);
			Dir=int(getch());
			switch(Dir)
			{
				case 75:  //Left direction
								if(X-30>=11)
									X-=30;

							break;

				case 77:  //Right direction
								if(X+30<=630)
									X+=30;

						 break;

				case 72:  //Up direction
								if(Y-30>=110)
									Y-=30;
								else
									{
									End=true;
									Win=true;
									}

							break;
			}
			putimage(X-10,Y-10,P,COPY_PUT);

		}
		if(Dir!=27)//moves chicken if user not hit esc
			{
			placement();
			squish(End,Win,X,Y);
			}

		if(End) //total points for end of game (when either lose or finish game
		{
			cleardevice();
			go(Win);
			if ((Win&&Level==19)||!Win)
			{
			cout<<endl<<"Total Score: "<<Points;
					cout<<endl<<endl<<endl<<"Press any key to return to the menu";
					getch();
			}
			cleardevice();
		 }
}
		if(Dir==27)//goes back to menu if esc is hit
		 {
			cleardevice();
			startscn();
		 }

 };
//levels and story line
void level_change() //keeps track of levels, progresses player through levels
{
int Level;//keeps track of level
bool Win;//bool for if player win
Farm.open("a:\\farm.bmp");
Level=0;
Points=0;
//Why does the chicken cross the road?  Game "set up"
cout<<"Mike the Headless Chicken lives on a small farm in the middle of ";
cout<<endl<<"a network of busy highways.  Not only is Mike the Headless";
cout<<endl<<"Chicken known as a miracle chicken solely because he is ";
cout<<"headless.";
cout<<endl<<endl<<"Press any key to continue";
getch();
clrscr();
cleardevice();
cout<<"Mike also is known as a miracle chicken around the Olsen's farm due ";
cout<<endl<<"his extreme intelligence, even though he lacks a head.";
cout<<endl<<endl<<"Press any key to continue";
getch();
clrscr();
cleardevice();
cout<<endl<<"While not posing for publicity photos or being carted around";
cout<<endl<<"the world for show, Mike spends much of his time on the ";
cout<<endl<<"farm running errands for the family.  The only difficult ";
cout<<endl<<"aspects of these errands is that, in order to leave the farm";
cout<<endl<<"at all, Mike must cross one of the surrounding highways, ";
cout<<endl<<"which can be hard to do without a head.";
cout<<endl<<endl<<"Press any key to continue";
getch();
clrscr();
cleardevice();
cout<<"As the members of Mike's family give him tasks to perform, help ";
cout<<endl<<"help Mike to cross the road, retrieve the item(s), and";
cout<<endl<<"return safetly back to the farm";
cout<<endl<<endl<<"GOOD LUCK!!!!";
cout<<endl<<endl<<"Press any key to continue";
getch();

//actual switch through levels, which continues till Win is false
do{
Win=true;
clrscr();
cleardevice();
switch(Level)
{
	case 0://level 1
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Billy Bob's CD player has run out of batteries.  Mike, will you go";
					cout<<endl<<"to Radio Shack to get some more?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 1:
					cout<<"Half way there!  Mike has made it to Radio Shack and has purchased the";
					cout<<endl<<"batteries.  Now he must make it back to the farm.  Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 2: //level 2
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Cousin Betty Lou has the starring role in the school play tonight";
					cout<<endl<<"but cannot find her hairspray.  Mike, will you go to Drug";
					cout<<endl<<"Emporium to get her some please?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 3:
					cout<<"Half way there!  Mike has made it to Drug Emporium and has purchased";
					cout<<endl<<"the hairspray. Now he must make it back to the farm. Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 4: //level 3
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Its Billy Bob's birthday! Mrs. Olsen is trying to bake a cake, but doesn't";
					cout<<endl<<"have any flour.  Will you go to the grocery store to get some?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 5:
					cout<<"Half way there!  Mike has made it to the grocery store and gotten";
					cout<<endl<<"the flour.  Now he must make it safely back to the farm.";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 6: //level 4
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Mr.Olsen doesn't know what to get Mrs.Olsen for their anniversary.  Mike, you have";
					cout<<endl<<"such good taste in these matters!  Will you go and pick ";
					cout<<"something out?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 7:
					cout<<"Half way there!  Mike has made it to the jewlery store and gotten";
					cout<<endl<<"a lovely bracelet for Mrs.Olsen.  Now he must make it safely back";
					cout<<endl<<" to the farm.";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 8: //level 5
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"The family is hungry and Mrs.Olsen is too tired to cook.  Mike, will you";
					cout<<endl<<"go to KFC and get us something to eat please?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 9:
					cout<<"Half way there!  Mike has made it to KFC and gotten a nice family";
					cout<<endl<<"dinner pack.  Now he must make it safely back to the farm.";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 10: //level 6
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Ima Jean left her calculus book at her best friend's house the other";
					cout<<endl<<"day, and needs it tonight to finish her homework. Will you go";
					cout<<"get it for her?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 11:
					cout<<"Half way there!  Mike has made it to Ima Jean's friend's house and gotten";
					cout<<endl<<"the book.  Now he must make it safely back to the farm.";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 12://level 7
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Mike is sick of doing all these tasks for people, and is taking a ";
					cout<<endl<<"break.  He is planning on visiting his girlfriend,";
					cout<<endl<<"Leggless Jane, who lives across the street.";
					cout<<endl<<endl<<"Press any key to help Mike get to his girlfriend's house.";
					getch();
					break;
	case 13:
					cout<<"Mike has spent a romantic afternoon with Leggless Jane, but now needs";
					cout<<endl<<"to get safely back to the farm.";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 14://level 8
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"The family dog, Fluffy the doberman, is out of dog chow, and is so";
					cout<<endl<<"hungry, he is trying to eat the family hamster. Will you go to";
					cout<<endl<<"the pet store and get some more food for her, Mike?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 15:
					cout<<"Half way there!  Mike has made it to the pet store and has bought";
					cout<<endl<<"a bag of Dog Chow. Now he must make it back to the farm. ";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 16://level 9
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Mr.Olsen is hosting a super bowl party, but he and his friends are out ";
					cout<<endl<<"of drinks, and don't want to miss any of the game to get some";
					cout<<endl<<"more.  Mike, will you please go get them some?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 17:
					cout<<"Half way there!  Mike has made it to the gas station and has bought";
					cout<<endl<<"some drinks. Now he must make it safely back to the farm. ";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					break;
	case 18://level 10
					Farm.draw(1,1);
					delay(2000);
					cleardevice();
					cout<<"Mike's final task!  Mike the headless chicken has become extremely ";
					cout<<endl<<"famous over the past few months.  He has been asked to go in";
					cout<<endl<<"for one final publicity shoot for LIFE magazine, and then he";
					cout<<endl<<"will be able to retire for the rest of his life. Can you";
					cout<<endl<<"get him safely to the studio?";
					cout<<endl<<endl<<"Press any key to accept this mission";
					getch();
					break;
	case 19:
					cout<<"Mike has spent the morning doing his photo shoot.  Exhausted,";
					cout<<endl<<"he must make it safely back to the farm. ";
					cout<<" Good luck!";
					cout<<endl<<endl<<"Press any key to continue";
					getch();
					Win=false;
					break;

}
chick(Level,Win);
if(Level==19)
	{
	clrscr();
	cleardevice();
	cout<<"CONGRATULATIONS!!!";
	cout<<endl<<endl<<" Mike has completed all tasks! He can now ";
	cout<<endl<<"settle down into retirement :)  Way to go!";
	cout<<endl<<endl<<"Press any key to continue";
	getch();
	}
if(Level%2!=0&&Win)
	{
	clrscr();
	cleardevice();
	cout<<"CONGRATULATIONS!!!";
	cout<<endl<<endl<<"You have completed this task.  You may now move ";
	cout<<endl<<"on to your next mission.";
	cout<<endl<<"Points earned from this level: 200";
	cout<<endl<<"Total points: "<<Points+100;
	cout<<endl<<endl<<"Press any key to see your next errand";
	getch();
	}
Level++;
Points=Level*100;
}while(Win&&Level<20);
};
//Start Screen Function
void startscn()
 {
	//Local Vars
	char Choice;  //Menu choice of user
	int X,Y;  //Coordinates
	image Chicken;  //Chicken image

	X=getmaxx()/2;

	do
	 {
		//Display Start screen
		cleardevice();
		Chicken.open("a:\\chicken.bmp");
		Chicken.draw(70,300);
		setcolor(WHITE);
		settextstyle(3,0,5);
		outtextxy(10,10, "The Adventures of");
		outtextxy(50,50, "Mike The Headless Chicken");

		//Display Choice box
		settextstyle(2,0,5);
		outtextxy(X-130,210, "This menu can be reached anytime during play");
		outtextxy(X-130,220, "by hitting the Esc button");
		outtextxy(X-30,240, "(S)tart");
		outtextxy(X-30,250, "(I)nstructions");
		outtextxy(X-30,260, "(Q)uit");

		//Choice
		while(!kbhit());
		Choice=toupper(getch());
		cout<<Choice;

		switch(Choice)
		 {
			case 'S':  //Start

								 cleardevice();
								 level_change();

							break;

			case 'I':  //Instructions

								 cleardevice();
								 instruct();

							break;

			case 'Q':  //Quit

			default: break;
		 }

	 }
	while(Choice!='Q');

 };


//Instuction Screen Function
void instruct()
 {
 int Numo;
	//Display instruction screen graphic
	clrscr();
	cleardevice();
	outtextxy(10,10, "INSTRUCTIONS MENU");
	cout<<endl<<endl<<endl<<endl<<"Choose one of the following options";
	cout<<endl<<"by entering the number to the left of option.";
	cout<<endl<<"1. Mike's Story"<<endl<<"2. Game Overview"<<endl<<"3. Menu";
	cout<<endl<<"4. Game Set Up and Scoring"<<endl<<"5. Game Play";
	cout<<endl<<"6. Credits"<<endl<<"7. Main Menu"<<endl<<"Enter choice: ";
	cin>>Numo;
	switch(Numo)
	{
	case 1: story();
					break;
	case 2: overview();
					break;
	case 3: menu();
					break;
	case 4: setup();
					break;
	case 5:	play();
					break;
	case 6: credits();
					break;
	case 7: startscn();
	}
};
//Game Over Function
void go(bool Win)
 {
	if(!Win)
	{
		outtextxy((getmaxx()/2)-40,50, "GAME OVER");
	}
 };

//Mikes Story
void story()
{
clrscr();
cleardevice();
cout<<"	 Though it is hard to believe, a headless chicken actually DID exist";
cout<<endl<<"Mike the miracle completely normal Wyandotte rooster in Fruita,";
cout<<endl<<" Colorado, on a farm owned by Lloyd and Clara Olsen.";
cout<<endl<<"		On September 10, 1945, the Olsen's went out to slaughter a ";
cout<<endl<<"a bunch of chickens for food by cutting off their heads, ";
cout<<endl<<"including Mike's.  However, even though his head was lying on";
cout<<endl<<"the barn floor, Mike continued to strut around the farm yard";
cout<<endl<<"as if nothing had happened.  After discovering that Mike was ";
cout<<endl<<"not going to die, Mr. Olsen decided to feed him, using an ";
cout<<endl<<"dropper to squirt food into his open esophagus, to see how long";
cout<<endl<<"Mike would actually stay alive.";
cout<<endl<<"As Mike continued to live on, acting quite like a normal ";
cout<<endl<<"chicken save that he lacked a head, he began to draw lots of";
cout<<endl<<"attention. Eventually, Mr. Olsen went on the road with Mike, ";
cout<<endl<<"traveling around with him and charging spectators to see his";
cout<<endl<<"famous headless chicken";
cout<<endl<<"		Finally, 18 months after Mike's head was originally severed,";
cout<<endl<<"Mike choked to death on his own mucus (he lacked the ability";
cout<<endl<<"to swallow, as he lacked a mouth), and died;";
cout<<endl<<"		Why was Mike able to live so long without a head?  Scientist";
cout<<endl<<"believe it is because when Mr. Olsen cut off Mike's head, he ";
cout<<endl<<"happened to leave the brain stem itself, where most of a ";
cout<<endl<<"chicken's behaviors are controlled, in tact";
cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();
}
//Game Overview
void overview()
{
clrscr();
cleardevice();
cout<<"		Mike lives on a small farm in Fruita, Colorado, surrounded by a ";
cout<<endl<<"network of busy highways.  He is known as a miracle chicken for";
cout<<endl<<"more reasons than just being headless.  Mike also is quite a ";
cout<<endl<<"miracle chicken due to his amazing intelligence, which is quite";
cout<<endl<<"impressive, seeing as how he lacks a head.  When not traveling ";
cout<<endl<<"the world or posing for bublicity shots, Mike the Headless";
cout<<endl<<"Chicken spends most of his time around the Olsen's farm, ";
cout<<endl<<"running errands for the family. However, these errands aren't";
cout<<endl<<"that eat, for Mike must cross at least one bust highway each";
cout<<endl<<"time he wishes to leave the farm to perform a task.  And the ";
cout<<endl<<"fact that he lacks a head makes the errands Mike runs even ";
cout<<endl<<"harder.  As Mike's family members ask him to run an errand for";
cout<<endl<<"them, help Mike to cross the bust Fruita highways to retrieve";
cout<<endl<<"the item(s) asked for, then cross them once again to get safely";
cout<<endl<<"back to the farm. GOOD LUCK!";
cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();
};
void menu()
{
cout<<"		The menu acts as the general control panel for the entire game";
cout<<endl<<"		STARTING: To start game play, press the letter 's' on the ";
cout<<endl<<"keyboard.  This should lead you into the first screen of the ";
cout<<endl<<"game, which begins with an overview of the game itself.";
cout<<endl<<endl<<"		QUITTING: To quit the game from the menu, press the ";
cout<<endl<<"letter 'q'.  This should lead you back to Turbo, to the code";
cout<<endl<<endl<<"		INSTRUTIONS: This is where you currently are!";
cout<<endl<<endl<<"		To see the menu at any time during game play, press";
cout<<endl<<"the escape key located on your keyboard";
cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();
};
void setup()
{
cout<<"		The game begins with ab introduction to the game, explaining, all";
cout<<endl<<"in all, why the chicken crosses the road to begin with.  As ";
cout<<endl<<"the game proceeds, the player will be asked to complete an ";
cout<<endl<<"errand for each level.  In order to complete an errand, the ";
cout<<endl<<"player must accept the mission, cross the road, obtain the ";
cout<<endl<<"needed item, and cross the road again to return safely back to";
cout<<endl<<"to the farm.";
cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();
};
void credits()
{
cout<<"		This game is dedicated to Mike the Headless Chicken, who I now";
cout<<endl<<"believe exists";
cout<<endl<<endl<<"		This game was created by Stephanie Hilz and Chris ";
cout<<endl<<"Perkic, for Mr. Baker's PreAP comp sci class in May of 2003";
cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();
};
void play()
{
 cout<<"		To begin a mission or continue game play after you have retrieved ";
 cout<<endl<<"an item, follow the directions at the bottom of the storyline,";
 cout<<endl<<" which will instruct you to press any key to continue/accept ";
 cout<<endl<<"the mission.  The game will begin with an 8-laned road.  ";
 cout<<endl<<"The boxes moving along the lanes, which will appear as ";
 cout<<endl<<"different colors each time the game is compiled, are the ";
 cout<<endl<<"'cars'.  The white circle, which will begin on the shoulder of";
 cout<<endl<<" the road nearest the bottom of the screen, is the 'chicken'.";
 cout<<endl<<"		To guide the chicken across the road, use the left, right,";
 cout<<endl<<" and up arrow keys on your keyboard to move him in those ";
 cout<<endl<<"directions.  Each time you press a key, the chicken will move ";
 cout<<endl<<"one 'jump'(which is equal to a lane width), in that direction.";
 cout<<endl<<"  The chicken DOES NOT move down, so there is no need to hit ";
 cout<<endl<<"the down arrow key.  Move the chicken across the road, ";
 cout<<endl<<"avoiding the cars, until he makes it safely to the shoulder ";
 cout<<endl<<"of the road on the other side.  Once on the shoulder, to ";
 cout<<endl<<"complete your journey across the road, press the up arrow ";
 cout<<endl<<"key ONE more time to move on to the next screen.  Pressing ";
 cout<<endl<<"the key more than once will result in skipping the next ";
 cout<<endl<<"storyline screen.";
 cout<<endl<<"		If the chicken is hit by a car on the way across, your ";
 cout<<endl<<"game is over.  You should see a game over screen.  By ";
 cout<<endl<<"pressing Esc from this screen, you can return to the menu ";
 cout<<endl<<"and begin the game all over again.";
 cout<<endl<<endl<<"Press any key to return to the instructions menu";
getch();
instruct();

};