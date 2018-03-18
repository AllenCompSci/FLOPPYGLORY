//Brad Koskowich
//Prob#40
//Block 02

	//Comments

	//Library
#include<conio.h>
#include<iomanip.h>
#include<iostream.h>
#include<apstring.h>
#include<bool.h>
#include<apvector.h>
#include<apmatrix.h>
#include<fstream.h>
#include<graphics.h>
#include<stdlib.h>
#include<alloc.h>
#include<dos.h>
#include<bitmap.h>
#include<math2.h>

	//Const
	int grdriver,grmode,errorcode;
	apstring PK;
	//Structs

	struct bullmove
		{
			int Bx,By,Dir;
			int Ex,Ey;
			bool Live;

		};

	struct Edat
	{int Type;
	 int Health;
	 long Points;
	 image Pic;
	 bool Collide;
	};

	//Global Domain

	char Ans;
	apstring Trash,Name,file_name;
	long Count, Not_Put, Xor_Put;
	unsigned long Size;
	int Level;

		//Kyle
	int Bombs;
	int Shoot;
	int Missl;
	int Lasr;
	int Beam;
	int Hmissl;
	int Sx, Sy;
	int Ex, Ey;
	int Key;
	int Z;
	int Bpower;

	//long Count;
	image Tship,Bullet;
	ImgData Tshipdata;
	//apstring Trash;
	apvector <bullmove> Bulletmove (8);

	//Vectors
	apvector <apstring> Manual (21);
	apvector <Edat> Enemies (30);

		//Kyle
		void movement (int&,int&,int&);
		void shooting (int&,int&,apvector<bullmove>&);

	//Prototypes
	void header(apstring);
	void ender();
	void grstart(int&,int&,int&);
	void far *P,*Q;

	void start();
		void menu();
			void setmenu();
				void stars();

	void game ();
		void play();
			void targetset(apvector <Edat>&);
			void target(apvector <Edat>&);
				void path(apvector<Edat>&, int&,int&,int&);
				void enemyfire();
				void erase();
		void end();
	void fireobject(int&,int&,apvector<bullmove>&);
	void help(apvector <apstring>);

	/*long score(apvector <Edat> Enemies);
		highscore();    */

	void main ()
{
	PK="Are you sure you want to quit?";
	grstart(grdriver,grmode,errorcode);
	do{

		start();

	ender();
		}while(Ans=='Y'||Ans=='y');
}
//Functions
//-----------------------------------------------------------------------Start
	void start()
	{//Locals
	int Star,Ranum;

	menu();
	};
//-----------------------------------------------------------------------Menu
	void menu()
	{//Locals
		int Key, Select;
		bool Quit;
		int X1,X2,Y1,Y2;
		setmenu();
	//Left=75, Right=77, Down=80, Up=72

		Select=0;
		X1=275;
		X2=285;
		Y1=310;
		Y2=312;

		setfillstyle(1,4);
		bar(X1,Y1,X2,Y2);
		 do{

			while(!kbhit());
			{}

			if(kbhit())
			{
				Key=getch();
				if(Key==0)
					Key=getch();
			}
			if(Key==80||Key==77)
			Select++;
			else if(Key==72||Key==75)
			Select--;

			if(Select==-1)
				Select=4;
			else if(Select==5)
				Select=0;

		 switch(Select)
		 {case 0:setfillstyle(1,0);
						 bar(X1,Y1,X2,Y2);
						 X1=275;
						 X2=285;
						 Y1=310;
						 Y2=312;
						 setfillstyle(1,4);
						 bar(X1,Y1,X2,Y2);
						 break;

			case 1:setfillstyle(1,0);
						 bar(X1,Y1,X2,Y2);
						 X1=248;
						 X2=258;
						 Y1=325;
						 Y2=327;
						 setfillstyle(1,4);
						 bar(X1,Y1,X2,Y2);
						 break;

			case 2:setfillstyle(1,0);
						 bar(X1,Y1,X2,Y2);
						 X1=255;
						 X2=265;
						 Y1=342;
						 Y2=344;
						 setfillstyle(1,4);
						 bar(X1,Y1,X2,Y2);
						 break;

			case 3:setfillstyle(1,0);
						 bar(X1,Y1,X2,Y2);
						 X1=278;
						 X2=288;
						 Y1=358;
						 Y2=360;
						 setfillstyle(1,4);
						 bar(X1,Y1,X2,Y2);
						 break;

			case 4:setfillstyle(1,0);
						 bar(X1,Y1,X2,Y2);
						 X1=275;
						 X2=285;
						 Y1=374;
						 Y2=376;
						 setfillstyle(1,4);
						 bar(X1,Y1,X2,Y2);
						 break;
		}
		}while(Key!=13);

	 switch(Select)
	 {
		case 0:game();
					 break;
		case 1:help(Manual);
					 clrscr();
					 cleardevice();
					 menu();
					 break;
		case 2://highscore();
					 break;
		case 3://code();
					 break;
		case 4://quit();
					 break;
	 }
	};
//----------------Menu---------------------------------------------------------
	void setmenu()
	{//Locals
	stars();
	apstring S1,S2,S3,S4,S5;

		S1="Play";
		gotoxy((40-S1.length()/2),20);
		cout<<S1<<endl;

		S2="Instructions";
		gotoxy((40-S2.length()/2),21);
		cout<<S2<<endl;

		S3="Highscores";
		gotoxy((40-S3.length()/2),22);
		cout<<S3<<endl;

		S4="Codes";
		gotoxy((40-S4.length()/2),23);
		cout<<S4<<endl;

		S5="Quit";
		gotoxy((40-S5.length()/2),24);
		cout<<S5<<endl;
	};

	void stars()
	{//Locals
	 int Ranum,Star;

	 Ranum=random(400)+50;
	 cleardevice();

		for(Star=0;Star<=Ranum;Star++)
		 {
			setbkcolor(0);
			putpixel(random(640)+1,random(480)+1,15);
		 }
	}
//---------------------------Game----------------------------------------------
	void game()
	{//Locals

	//1.Enemy Setup
	targetset(Enemies);

	//2.Start; Render ship and load shooting and collision detection code
		play();
		//3.Load Target code in play fxn

	};
//-----------------------------------------------------------------------Targetset
	void targetset(apvector <Edat>&Enemies)
	{//Locals
	int K;
	apstring Picture;
	image Epic;
	ifstream in_file;

	 //Standards
	 for(K=0;K<20;K++)
		{
			Enemies[K].Type=K;
			Enemies[K].Health=K*2;
			Enemies[K].Points=K*40;
			Picture="A:\\RS\\Enemies\\";
			Picture+=itos(K)+".bmp";
			Epic.open(Picture);
			Enemies[K].Pic=Epic;
		}

	 //Bosses
	 for(K=20;K<25;K++)
		{
			Enemies[K].Type=K;
			Enemies[K].Health=(K*K)/2;
			Enemies[K].Points=K*K;
			Picture="A:\\RS\\Enemies\\";
			Picture+=itos(K)+".bmp";
			Epic.open(Picture);
			Enemies[K].Pic=Epic;
		}
	};

//-----------------------------------------------------------------------Movement
void movement (int &Sx,int &Sy, int&Key)
{
// setcolor(0);
// setfillstyle(1,0);
//Tship.draw(Sx,Sy,TRANSPARENT,15);


	switch (Key)
		{

		case 75: //left
		if (Sx>0)
			Sx-=3;
				break;
		case 77:  //right
		if (Sx<590)
			Sx+=3;
				break;
		case 72: //up
		if (Sy>300)
			Sy-=3;
				break;
		case 80: //down
		if (Sy<410)
			Sy+=3;
				break;
		}

		Tship.draw(Sx,Sy);
};
//-----------------------------------------------------------------------Shooting
void fireobject(int &Sx,int &Sy,apvector<bullmove>& Bulletmove)
{//Locals
	int Obj;
	bool Exit;

	Obj=0;
	Exit=false;

	do{
		if(!Bulletmove[Obj].Live)
			{
				Bulletmove[Obj].Live=true;
				Bulletmove[Obj].Bx=(Sx+23);
				Bulletmove[Obj].By=(Sy-2);
				Exit=true;
			}
		Obj++;
		}while(!Exit&&Obj<Bulletmove.length());

};
void shooting (int &Sx,int &Sy, apvector <bullmove>& Bulletmove)
{
int N;
int Z;

	/*switch (Bpower)
	 {
		case 0:
				if(Bulletmove.length()<8)
				{
					//Bulletmove.resize(Bulletmove.length()+1);
					Bulletmove[Bulletmove.length()-1].Bx=(Sx+23);
					Bulletmove[Bulletmove.length()-1].By=(Sy-2);
				}
		 break;

		case 1:
					if (Bulletmove.length()<16)
						{
							//Bulletmove.resize(Bulletmove.length()+2);
							Bulletmove[Bulletmove.length()-2].Bx=(Sx+12);
							Bulletmove[Bulletmove.length()-2].By=(Sy-2);
							Bulletmove[Bulletmove.length()-1].Bx=(Sx+34);
							Bulletmove[Bulletmove.length()-1].By=(Sy-2);
						}
		 break;

		case 2:
					if (Bulletmove.length()<24)
						{
							//Bulletmove.resize(Bulletmove.length()+3);
							Bulletmove[Bulletmove.length()-3].Bx=(Sx+23);
							Bulletmove[Bulletmove.length()-3].By=(Sy-2);
							Bulletmove[Bulletmove.length()-2].Bx=(Sx+34);
							Bulletmove[Bulletmove.length()-2].By=(Sy-2);
							Bulletmove[Bulletmove.length()-1].Bx=(Sx+12);
							Bulletmove[Bulletmove.length()-1].By=(Sy-2);
						}
	 }
			*/
		for(Z=0;Z<Bulletmove.length();Z++)
		 {
		 //delay(10/(Z+1));
		 if(Bulletmove[Z].Live)
			{ if(Bulletmove[Z].By>0)//&&Bulletmove[Z].Live)
			 {
				setfillstyle(1,0);
				bar(Bulletmove[Z].Bx,Bulletmove[Z].By,Bulletmove[Z].Bx+4,Bulletmove[Z].By+4);
				Bulletmove[Z].By-=5;
				Bullet.draw(Bulletmove[Z].Bx,Bulletmove[Z].By);
			 }

			 else
			 {
				/*for(N=(Z+1);N<Bulletmove.length();N++)
					 Bulletmove[N-1]=Bulletmove[N];

				Bulletmove.resize(Bulletmove.length()-1);
				Z--;*/
				setfillstyle(1,0);
				bar(Bulletmove[Z].Bx,Bulletmove[Z].By,Bulletmove[Z].Bx+4,Bulletmove[Z].By+4);
				Bulletmove[Z].Live=false;

			 }
			}
		 }

		};
//-----------------------------------------------------------------------Target
	void target(apvector <Edat>&Enemies)//paths and animations
	{//Locals
	int Level, A;

	Level=1;
	/*if(score(Level*200))
		Level++;
							 */
	for(A=0;A<10;A++)
	 {
		path(Enemies, Level, Ex, Ey);
		delay(20/Level*2);
	 }
	};
//-----------------------------------------------------------------------Paths Targets Follow
	void path(apvector <Edat>&Enemy, int&Level,int&Ex,int&Ey)
		{//Locals
		int X;

			X=random(Level+1);

			switch(X)
				{
					case 0: X=random(Level+1);

								 for(Ex=320;Ex<640;Ex++)
									{
										Ey=0;
										Enemy[X].Pic.draw(Ex,Ey,TRANSPARENT,15);
										Ey+=(Ex%6)/(10*Enemy[X].Type);
										bar(Ex,Ey,Ex+70,Ey+70);

										if(Enemy[X].Collide)
											{
												//score(Enemy);
												erase();//?
											}
											else if(Ex%5==0)
												enemyfire();//mod from playerfire function

											if(Ex==640)
											erase();//how to erase enemy??????????
									}
										break;

					case 1:	X=random(Level+1);

									for(Ex=320;Ex<0;Ex--)
										{
											Ey=0;
											Enemy[X].Pic.draw(Ex,Ey,TRANSPARENT,15);
											Ey+=(Ex%6)/(10*Enemy[X].Type);
											bar(Ex,Ey,Ex+70,Ey+70);

											if(Enemy[X].Collide)
												{
													//score(Enemy);
													erase();//?
												}
											else if(Ex%5==0)
												enemyfire();//mod from playerfire function
											else if(Ex==0)
												erase();//how to erase enemy??????????
										}
											break;

					case 2:	X=random(Level+1);


									for(Ex=0;Ex<640;Ex++)
										{
											Ey=0;
											Enemy[X].Pic.draw(Ex,Ey,TRANSPARENT,15);
											Ey+=(Ex%6)/(10*Enemy[X].Type);
											bar(Ex,Ey,Ex+70,Ey+70);

											if(Enemy[X].Collide)
												{
													//score(Enemy);
													erase();//?
												}
											else if(Ex%5==0)
												enemyfire();//mod from playerfire function
											else if(Ex==640)
												erase();//how to erase enemy??????????
										}
											break;
					case 3:	X=random(Level+1);

									for(Ex=640;Ex<0;Ex--)
										{
											Ey=0;
											Enemy[X].Pic.draw(Ex,Ey,TRANSPARENT,15);
											Ey+=(Ex%6)/(10*Enemy[X].Type);
											bar(Ex,Ey,Ex+70,Ey+70);

											if(Enemy[X].Collide)
												{
													//score(Enemy);
													erase();//?
												}
											else if(Ex%5==0)
												enemyfire();//mod from playerfire function
											else if(Ex==0)
												erase();//how to erase enemy??????????
									 }
											break;
					case 4:	X=random(Level+1);

									for(Ex=640;Ex<0;Ex--)
										{
											Ey=0;
											Enemy[X].Pic.draw(Ex,Ey,TRANSPARENT,15);
											Ey+=(Ex%6)/(10*Enemy[X].Type);
											bar(Ex,Ey,Ex+70,Ey+70);

											if(Enemy[X].Collide)
											{
												//score(Enemy);
												erase();//?
											}
											else if(Ex%5==0)
												enemyfire();//mod from playerfire function
											else if(Ex==0)
												erase();//how to erase enemy??????????
										}
											break;
							}
				};
//-----------------------------------------------------------------------Erase
void erase()
{

};
//-----------------------------------------------------------------------Efire
	void enemyfire(/*int&Ex,int&Ey*/)
	{//Locals
	 int A,M;

	 for(A=0;A<Bulletmove.length();A++)
		 {
		 delay(10/(A+1));
			 if(Bulletmove[A].By>0)
			 {
				setfillstyle(1,0);
				bar(Bulletmove[A].Ex,Bulletmove[A].Ey,Bulletmove[A].Ex+2,Bulletmove[A].Ey+2);
				Bulletmove[A].Ey-=5;
				Bullet.draw(Bulletmove[A].Ex,Bulletmove[A].Ey);
			 }
			 else
			 {
				for(M=(A+1);M<Bulletmove.length();M++)
					 Bulletmove[M-1]=Bulletmove[M];

				Bulletmove.resize(Bulletmove.length()-1);
				Z--;
			 }
		 }

	};
//-----------------------------------------------------------------------Play
	void play()
	{//Locals
	int C;
	long Count;

		cout<<setprecision(2);
		Tship.open("A:\\RS\\Objects\\Tship.bmp");
		Bullet.open("A:\\RS\\Objects\\bullet2.bmp");
		Bpower=0;
		Sx=300;
		Sy=410;
		Count=0;
		for(C=0;C<Bulletmove.length();C++)
			Bulletmove[C].Live=false;
		cleardevice();

			do{
				Tship.draw(Sx,Sy);

				Key=0;
				if (kbhit())
					{
					Key=getch();

					if(Key==0)
						Key=getch();
					}
					 if(Key==32)
						fireobject(Sx,Sy,Bulletmove);
					 //if(Count%10000==0)
						shooting (Sx,Sy,Bulletmove);
					 //if(Count%1000==0)
						movement (Sx, Sy, Key);

					 if(Count<=100000)
						Count++;
					 else
						Count=0;


					}while (Key!=27);
			 target(Enemies);

	};
//-----------------------------------------Score-----------------
/*long score(apvector <Edat> Enemy);
	{//Locals



	}; */
//-----------------------------------------Instructions-----------------------------
	void help(apvector <apstring> Manual)
	{//Locals

	int X,Y;
	cleardevice();

	X=0;
	 Manual.resize(X);

	 ifstream in_file;
	 file_name="A:\\RS\\RSManual.txt";
	 in_file.open(file_name.c_str());

	 do{
		Manual.resize(X+1);
		getline(in_file, Manual [X]);
		X++;
		 }while(!in_file.eof());

	 in_file.close();

	Manual.resize(X-1);
	X=Manual.length();


	for(Y=0;Y<X;Y++)
		{
			gotoxy(1,Y);
			cout<<Manual[Y];
			cout<<endl;
		}
	image Red, Blue, Purple;
	Red.open("A:\\RS\\Objects\\Red.bmp");
	Blue.open("A:\\RS\\Objects\\Blue.bmp");
	Purple.open("A:\\RS\\Objects\\Purple.bmp");

	Red.draw(30,260,TRANSPARENT,15);
	Blue.draw(160,260,TRANSPARENT,15);
	Purple.draw(280,260,TRANSPARENT,15);
	getch();

	};

	//Header
	void header (apstring Name)
	{ Name=="Red Star";
		gotoxy((40-Name.length()/2),1);
		cout<<Name<<endl;
		gotoxy(1,2);
	}

	//Ender
	void ender ()
	{
		cout<<"Do you want to run the program again?";
		cin>>Ans;
		getline(cin,Trash);
		clrscr();
	}

	//Grstart
	void grstart (int& grdriver, int&grmode, int&errorcode)
	{
		grdriver=VGA;
		grmode=VGAHI;
		initgraph(&grdriver,&grmode,"C:\\TC\\BGI");

		if(errorcode!=grOk)
			{
				clrscr();
				cout<<"Error:"<<errorcode<<endl<<PK;
				getch();
				exit(1);
			}
	};