//Chris Chapman
//7th
//prob26
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
#include<apvector.h>
#include<apmatrix.h>

//const.section

//variable section
int E, H,  Y, X;
char Answer;
bool Flag;
apvector <apstring> Words (20);
apvector <apstring> Puzzle (20);
apmatrix <bool> Check (20,20);

void main ()
{
do{
	clrscr();
	for (X=0;X<20;X++)
		for (Y=0;Y<20;Y++)
		{
			Puzzle [X]=Puzzle [X]+char(random(26)+65);
			Check [X][Y]=false;
		}

	cout<<"Please enter twenty five letter words, one at a time"<<endl;
	for (E=0;E<20;E++)
		getline(cin,Words[E]);


	/*
	Words[0]="water";
	Words[1]="nikki";
	Words[2]="watch";
	Words[3]="drink";
	Words[4]="droid";
	Words[5]="board";
	Words[6]="brain";
	Words[7]="notes";
	Words[8]="cords";
	Words[9]="allen";
	Words[10]="lunch";
	Words[11]="seven";
	Words[12]="light";
	Words[13]="rooms";
	Words[14]="eight";
	Words[15]="drunk";
	Words[16]="stick";
	Words[17]="enter";
	Words[18]="debug";
	Words[19]="world";
	*/
	clrscr();
	for(E=0;E<20;E++)
		switch(random(8))
		{
			case 0: do{
							Flag=false;
							X=random(20);
							Y=random(16);
							for (H=0;H<5;H++)
								if (Check[X][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X][Y+H]=Words[E][H];
									Check[X][Y+H]=true;
								}
							break;

			case 1: do{
							Flag=false;
							X=random(20);
							Y=random(15)+5;
							for (H=0;H<5;H++)
								if (Check[X][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X][Y-H]=Words[E][H];
									Check[X][Y-H]=true;
								}
							break;

		 case 2: do{
							Flag=false;
							X=random(16);
							Y=random(20);
							for (H=0;H<5;H++)
								if (Check[X+H][Y])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X+H][Y]=Words[E][H];
									Check[X+H][Y]=true;
								}
							break;


		 case 3: do{
							Flag=false;
							X=random(15)+5;
							Y=random(20);
							for (H=0;H<5;H++)
								if (Check[X-5][Y])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X-H][Y]=Words[E][H];
									Check[X-H][Y]=true;
								}
							break;
		 case 4: do{
							Flag=false;
							X=random(16);
							Y=random(16);
							for (H=0;H<5;H++)
								if (Check[X+H][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X+H][Y+H]=Words[E][H];
									Check[X+H][Y+H]=true;
								}
							break;

		 case 5: do{
							Flag=false;
							X=random(15)+5;
							Y=random(15);
							for (H=0;H<5;H++)
								if (Check[X-H][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X-H][Y+H]=Words[E][H];
									Check[X-H][Y+H]=true;
								}
							break;

		 case 6: do{
							Flag=false;
							X=random(15)+5;
							Y=random(15)+5;
							for (H=0;H<5;H++)
								if (Check[X-H][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X-H][Y-H]=Words[E][H];
									Check[X-H][Y-H]=true;
								}
							break;

		 case 7: do{
							Flag=false;
							X=random(15);
							Y=random(15)+5;
							for (H=0;H<5;H++)
								if (Check[X+H][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<5;H++)
								{
									Puzzle[X+H][Y-H]=Words[E][H];
									Check[X+H][Y-H]=true;
								}
							break;





		}
	 for (X=0;X<20;X++)
		{
			for (Y=0;Y<20;Y++)
			cout<<Puzzle[X][Y]<<" ";
			cout<<endl;
		}




		getch();
		cout<<"Run agian? (Y/N)";
		cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
