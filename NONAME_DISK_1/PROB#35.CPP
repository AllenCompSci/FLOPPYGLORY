//Jeff Stein
//6th
//Mr. Baker
//Program: Poker

#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<apstring.h>
#include<apmatrix.h>
#include<apvector.h>
#include<stdlib.h>
bool Check [52];
apstring Card [52];
void cards ();
void deal (int, int);
int W;
int I;
int X;
int A;
apstring Quit;
void main ()
{
 do
 {
	clrscr ();
	randomize();
	for (A=0;A<=51;A++)
	 {
		Check [A] = true;
	 }
	cards ();
	deal (W,I);
	endl;
	getch ();
	cout<<endl;
	deal (W,I);
	getch ();
	cout<<endl;;
	deal (W,I);
	getch ();
	cout<<endl;;
	deal (W,I);
	getch ();
	clrscr ();
	cout<<"Would you like to play again?"<<endl;

	cout<<"1 for Yes , 2 for No "<<endl;

	cin>>Quit;
 }
 while (Quit!="2");
};
void cards ()
 {
	Card [14] = "Ace of Hearts";
	Card [15] = "2 of Hearts";
	Card [16] = "3 of Hearts";
	Card [17] = "4 of Hearts";
	Card [18] = "5 of Hearts";
	Card [19] = "6 of Hearts";
	Card [20] = "7 of Hearts";
	Card [21] = "8 of Hearts";
	Card [22] = "9 of Hearts";
	Card [23] = "10 of Hearts";
	Card [24] = "Jack of Hearts";
	Card [25] = "Queen of Hearts";
	Card [26] = "King of Hearts";
	Card [40] = "Ace of Diamonds";
	Card [41] = "2 of Diamonds";
	Card [42] = "3 of Diamonds";
	Card [43] = "4 of Diamonds";
	Card [44] = "5 of Diamonds";
	Card [45] = "6 of Diamonds";
	Card [46] = "7 of Diamonds";
	Card [47] = "8 of Diamonds";
	Card [48] = "9 of Diamonds";
	Card [49] = "10 of Diamonds";
	Card [50] = "Jack of Diamonds";
	Card [51] = "Queen of Diamonds";
	Card [52] = "King of Diamonds";
	Card [27] = "Ace of Clubs";
	Card [28] = "2 of Clubs";
	Card [29] = "3 of Clubs";
	Card [30] = "4 of Clubs";
	Card [31] = "5 of Clubs";
	Card [32] = "6 of Clubs";
	Card [33] = "7 of Clubs";
	Card [34] = "8 of Clubs";
	Card [35] = "9 of Clubs";
	Card [36] = "10 of Clubs";
	Card [37] = "Jack of Clubs";
	Card [38] = "Queen of Clubs";
	Card [39] = "King of Clubs";
	Card [1] = "Ace of Spades";
	Card [2] = "2 of Spades";
	Card [3] = "3 of Spades";
	Card [4] = "4 of Spades";
	Card [5] = "5 of Spades";
	Card [6] = "6 of Spades";
	Card [7] = "7 of Spades";
	Card [8] = "8 of Spades";
	Card [9] = "9 of Spades";
	Card [10] = "10 of Spades";
	Card [11] = "Jack of Spades";
	Card [12] = "Queen of Spades";
	Card [13] = "King of Spades";


 }
 void deal (int W, int I)
 {
	W=I=0;
	while (W<=6)
	 {
		W++;
		I = random (51);
		if (Check [I] == true)
		 {
			cout<<Card [I] <<endl;
			Check [I] = false;
		 }
		else
		 {
			do
			 {
				I = random (52)+1;
			 }
			while (Check [I] == false);
			cout<<Card [I] <<endl;
			Check [I] = false;
		 }
	 }
 }