//Information
//Joseph Olson
//Help
//Third Period

//Library
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <graphics.h>

//Constant

//Struct

//Global Variables
char Run_again;
int Help_Question;

/*Variable Declarations
Help_Question -- Asks what part of the help  that user wants to visit
Run_again     -- Asks the user if they would like to run the Help again
								 and view a different part of the game.
*/
//Prototypes
void gr_start(int&,int&,int&);
void fun_1();
void fun_2();
void fun_3();
void fun_4();
void readin();
void shiptypes();
/*Function Declarations

fun_1()    -- The basic instructions on how to play the game
fun_2()    -- How to place the ships on the screen
fun_3()    -- Instructions on how to attack
fun_4()    -- Tech support
readin()   -- Overall function that ties everything together
shiptypes()-- Documents the types of ships in the game and their health level

*/
//Program Section

void main()
	{
	do{
	clrscr();
	readin();


	cout<<"Do you want to learn any new information about the program? (y/n)"<<endl;
	cin>>Run_again;
	}while ((Run_again=='y')&&(Run_again!='n'));
	cout<<"Please hit enter to continue"<<endl;
	getch();
	}


//*********Function 2******
void readin()
{
	cout<<"Welcome to Super Battle Ship"<<endl;
do{
cout<<"1.  Basic Introduction to the Game"<<endl;
cout<<"2.  Instructions on how to place the ships"<<endl;
cout<<"3.  Instructions about how to attack"<<endl;
cout<<"4.  Comments or Tech Support"<<endl;
cout<<"(Please refer to Tech Support for any questions)"<<endl;
cin>>Help_Question;
if(Help_Question<0||Help_Question>4)
	{cout<<"Please enter a correct menu choice, try again -- Hit ENTER"<<endl;
	 getch();
	 clrscr();
	}
}while(Help_Question<0||Help_Question>4);


clrscr();
if(Help_Question==1)
	fun_1();
	else
 if(Help_Question==2)
	 fun_2();
	 else
	if(Help_Question==3)
		fun_3();
		else
		if(Help_Question==4)
		 fun_4();

};

//*********Function 3******
void fun_1()
{   gotoxy(12,2);
		cout<<"Instructions on how to play the game"<<endl<<endl;
		cout<<"The purpose of Battleship is to sink your opponent's ships."<<endl;
		cout<<"You are given five units in order to ";
		cout<<"accomplish this task."<<endl;

		cout<<"	1.) Carrier (5 pegs of health)"<<endl;
		cout<<"	2.) Gunship (4 pegs of health)"<<endl;
		cout<<"	3.) Cruiser (3 pegs of health)"<<endl;
		cout<<"	4.) U-Boat  (3 pegs of health)"<<endl;
		cout<<"	5.) Aegis   (2 pegs of health)"<<endl<<endl<<endl;


		cout<<"READY TO MOVE ON? (hit ENTER)"<<endl;
		getch();
		clrscr();
		gotoxy(5,3);
		cout<<"At the beginning of the game, you will be given these 5 ships"<<endl;
		gotoxy(5,4);
		cout<<"and will place them on the board. (Please refer to 'Part 2: "<<endl;
		gotoxy(5,5);
		cout<<"Instructions on how to place the ships' for detailed information)"<<endl;
		gotoxy(5,6);
		cout<<"You will use these 5 ships to attack your opponent - in this game,"<<endl;
		gotoxy(5,7);
		cout<<"the computer. (Please refer to 'Part 3: Instructions about how to"<<endl;
		gotoxy(5,8);
		cout<<"choose the coordinates for the attack')  Whenever you hit an"<<endl;
		gotoxy(5,9);
		cout<<"opponent, the box you choose will turn to red to indicate the hit."<<endl;
		gotoxy(5,10);
		cout<<"You will then let your opponent have his/her chance at hitting one"<<endl;
		gotoxy(5,11);
		cout<<"of your own ships. If he hits one of your ships, you will see that"<<endl;
		gotoxy(5,12);
		cout<<"ship's health indicator goes down one peg."<<endl<<endl;
		cout<<"Hit ENTER to view ship information"<<endl;
		getch();
		clrscr();
		shiptypes();


};

void shiptypes()
{

			gotoxy(10,3);
			cout<<"1.)  Carrier (5 hp)"<<endl;
			cout<<"	 a. Dark Green   - 100%"<<endl;
			cout<<"	 b. Light Green  - 80%"<<endl;
			cout<<"	 c. Yellow       - 60%"<<endl;
			cout<<"	 d. Light Red    - 40%"<<endl;
			cout<<"	 e. Dark Red     - 20%"<<endl;
			cout<<"	 f. Black        - 0% "<<endl;
			cout<<"		I. You have lost this ship to enemy gunfire"<<endl;
			cout<<endl<<endl;
			cout<<"Hit ENTER"<<endl;
			getch();
			clrscr();
			gotoxy(10,3);
			cout<<"2.)  Gunship (4 hp)"<<endl;
			cout<<"	 a. Dark Green   - 100%"<<endl;
			cout<<"	 b. Yellow       - 75%"<<endl;
			cout<<"	 c. Light Red    - 50%"<<endl;
			cout<<"	 d. Dark Red     - 25%"<<endl;
			cout<<"	 e. Black        - 0%"<<endl;
			cout<<"		I. You have lost this ship to enemy gunfire"<<endl;
			cout<<endl<<endl;
			cout<<"Hit ENTER"<<endl;
			getch();
			clrscr();
			gotoxy(10,3);
			cout<<"3.)  Cruiser (3 hp)"<<endl;
			cout<<"	 a. Light Green - 100%"<<endl;
			cout<<"	 b. Yellow      - 66%"<<endl;
			cout<<"	 c. Light Red   - 33%"<<endl;
			cout<<"	 d. Black       - 0%"<<endl;
			cout<<"		I. You have lost this ship to enemy gunfire"<<endl;
			cout<<endl<<endl;
			cout<<"Hit ENTER"<<endl;
			getch();
			clrscr();
			gotoxy(10,3);
			cout<<"4.)  U-Boat  (3 hp)"<<endl;
			cout<<"	 a. Light Green - 100%"<<endl;
			cout<<"	 b. Yellow      - 66%"<<endl;
			cout<<"	 c. Light Red   - 33%"<<endl;
			cout<<"	 d. Black       - 0% "<<endl;
			cout<<"		I. You have lost this ship to enemy gunfire"<<endl;
			cout<<endl<<endl;
			cout<<"Hit ENTER"<<endl;
			getch();
			clrscr();
			gotoxy(10,3);
			cout<<"5.)  Aegis   (2 hp)"<<endl;
			cout<<"	 a. Light Green - 100%"<<endl;
			cout<<"	 b. Light Red   - 50%"<<endl;
			cout<<"	 c. Black       - 0%"<<endl;
			cout<<"		I. You have lost this ship to enemy gunfire"<<endl;
			cout<<endl<<endl;
			cout<<"Hit ENTER"<<endl;
			getch();
			clrscr();


};

//***********Function *******
void fun_2()
{
	gotoxy(16,2);
	cout<<"2.  Instructions on how to place the ships"<<endl<<endl;
	gotoxy(5,6);
	cout<<"When you are placing the ships on the board, you will need to give the"<<endl;
	gotoxy(5,7);
	cout<<"computer the starting coordinates for where you want the program to "<<endl;
	gotoxy(5,8);
	cout<<"place your ship. To do this, you will need to place your mouse on the"<<endl;
	gotoxy(5,9);
	cout<<"coordinate from which you want the ship to be placed. Four dots will "<<endl;
	gotoxy(5,10);
	cout<<"appear on the screen.  Please click on the endpoint of your choice."<<endl;
	gotoxy(5,11);
	cout<<"The space will then fill with pegs.  Then select another ship and "<<endl;
	gotoxy(5,12);
	cout<<"pick a point that gives the chosen ship enough room to fit upon the"<<endl;
	gotoxy(5,13);
	cout<<"screen without overwriting any other ships.  To select ships, click"<<endl;
	gotoxy(5,14);
	cout<<"on the name of a ship in the upper left hand corner.  When you have"<<endl;
	gotoxy(5,15);
	cout<<"clicked on a ship, a yellow asterick will appear by the name.  Then,"<<endl;
	gotoxy(5,16);
	cout<<"click on the usermap coordinate and follow the preceding directions."<<endl;
	gotoxy(5,17);
	cout<<"Please place the ships IN ORDER -- Carrier, then Battlecruiser, then"<<endl;
	gotoxy(5,18);
	cout<<"Cruiser, then U-Boat, and then Aegis."<<endl;


	cout<<endl<<endl;

}

//**********Function ********
void fun_3()
{
	gotoxy(18,2);
	cout<<"3.  Instructions about how to attack"<<endl<<endl<<endl;

	cout<<"	Please move the cursor over the grid, and when you have picked"<<endl;
	cout<<"	a coordinate, click on the coordinate with your left mouse"<<endl;
	cout<<"	button. Then, when you are ready to fire, click on the red"<<endl;
	cout<<"	button on the bottom left of the screen that has a 'Y' in "<<endl;
	cout<<"	its center.  If you wish to pick a new coordinate, instead,"<<endl;
	cout<<"	click on the yellow button that has a 'N' in its center; and"<<endl;
	cout<<"	then repeat the process until you are satisfied with your"<<endl;
	cout<<"	chosen coordinate.  After hitting the 'Y' button, you will"<<endl;
	cout<<"	see either a 'M' in the grid you chose, or you will see the"<<endl;
	cout<<"	grid turn red.  If an 'M' is placed, you missed all of your"<<endl;
	cout<<"	opponent's ships; but, if the square is painted red, that"<<endl;
	cout<<"	means you have hit one of your opponent's ships."<<endl;

	cout<<endl<<endl;

 };
 //*******Function 4*********
 void fun_4()
 {
 cout<<"Please read the manual"<<endl<<endl<<endl<<endl;

 };
