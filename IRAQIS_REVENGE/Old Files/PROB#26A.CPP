//Chris Chapman
//7th
//prob26a
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
int H, Y, X, L, N;
long E;
char Answer;
bool Flag;
apvector <apstring> Words (20);
apvector <apstring> Puzzle (20);
apmatrix <bool> Check (20,20);

void main ()
{
do{
	X=0;
	Y=0;
	clrscr();
	for (X=0;X<20;X++)
		for (Y=0;Y<20;Y++)
		{
			Puzzle [X]=Puzzle [X]+char(random(26)+65);
			Check [X][Y]=false;
		}
	cout<<"Enter words that are from 2- 8 letters in length, in all caps.";
	cout<<" When you have no more words, press 0"<<endl;

	do{
		cout<<"Word"<<E+1<<": ";
		getline(cin, Words[E]);
		E++;
		}while (E<20&&Words[E-1]!="0");

	 clrscr();
	for(N=0;N<E-1;N++)
		{
		L=Words[N].length();
		switch(random(8))
		{
			case 0: do{
							Flag=false;
							X=random(20);
							Y=random(20-(L-1));
							for (H=0;H<L;H++)
								if (Check[X][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X][Y+H]=Words[N][H];
									Check[X][Y+H]=true;
								}
							break;

			case 1: do{
							Flag=false;
							X=random(20);
							Y=random(20-L)+L;
							for (H=0;H<L;H++)
								if (Check[X][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X][Y-H]=Words[N][H];
									Check[X][Y-H]=true;
								}
							break;

		 case 2: do{
							Flag=false;
							X=random(20-(L-1));
							Y=random(20);
							for (H=0;H<L;H++)
								if (Check[X+H][Y])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X+H][Y]=Words[N][H];
									Check[X+H][Y]=true;
								}
							break;


		 case 3: do{
							Flag=false;
							X=random(20-L)+L;
							Y=random(20);
							for (H=0;H<5;H++)
								if (Check[X-L][Y])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X-H][Y]=Words[N][H];
									Check[X-H][Y]=true;
								}
							break;
		 case 4: do{
							Flag=false;
							X=random(20-(L-1));
							Y=random(20-(L-1));
							for (H=0;H<L;H++)
								if (Check[X+H][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X+H][Y+H]=Words[N][H];
									Check[X+H][Y+H]=true;
								}
							break;

		 case 5: do{
							Flag=false;
							X=random(20-L)+L;
							Y=random(20-(L-1));
							for (H=0;H<L;H++)
								if (Check[X-H][Y+H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X-H][Y+H]=Words[N][H];
									Check[X-H][Y+H]=true;
								}
							break;

		 case 6: do{
							Flag=false;
							X=random(20-L)+L;
							Y=random(20-L)+L;
							for (H=0;H<5;H++)
								if (Check[X-H][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X-H][Y-H]=Words[N][H];
									Check[X-H][Y-H]=true;
								}
							break;

		 case 7: do{
							Flag=false;
							X=random(20-(L-1));
							Y=random(20-L)+L;
							for (H=0;H<5;H++)
								if (Check[X+H][Y-H])
									 Flag=true;
							}while(Flag==true);
							for (H=0;H<L;H++)
								{
									Puzzle[X+H][Y-H]=Words[N][H];
									Check[X+H][Y-H]=true;
								}
							break;


		}


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
