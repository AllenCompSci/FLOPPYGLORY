// Mahmood Subhani
// Period 6
// Mr. Baker
// Program: Prob#00 Name, Address, Phone


#include<Iostream.h>
#include<conio.h>n
#include<apstring.h>
#include<iomanip.h>
#include<apvector.h>

apvector <apstring> Cards(17);
apvector <int> ID(28);
void assign();
void deal(int, int, int);
int X;
int I;
int J;
int K;
int Card;
int Suit;


void main ()  {

randomize();

clrscr();

assign();

for(J=0;J<28;J++)
{

ID[J]=0;
}


X=1;

K=0;

for(J=4;J>0;J--)
{
deal(I, Card, Suit);

cout<<endl<<endl;
}








};

void deal (int I, int Card, int Suit)
{


for(I=7;I>0;I--)
{

//do{

Card=random(13)+1;

Card--;

Suit=random(4)+1;
Suit=Suit+12;

ID[K]=Card+Suit;
K++;

/*}
while((ID[K]==ID[0])||(ID[K]==ID[1])||(ID[K]==ID[2])||(ID[K]==ID[3])||(ID[K]==ID[4])||
(ID[K]==ID[5])||(ID[K]==ID[6])||(ID[K]==ID[7])||(ID[K]==ID[8])||(ID[K]==ID[9])||
(ID[K]==ID[10])||(ID[K]==ID[11])||(ID[K]==ID[12])||(ID[K]==ID[13])||(ID[K]==ID[14])||
(ID[K]==ID[15])||(ID[K]==ID[16])||(ID[K]==ID[17])||(ID[K]==ID[18])||(ID[K]==ID[19])||
(ID[K]==ID[20])||(ID[K]==ID[21])||(ID[K]==ID[22])||(ID[K]==ID[23])||(ID[K]==ID[24])||
(ID[K]==ID[25])||(ID[K]==ID[26])||(ID[K]==ID[27]));
*/


cout<<Cards[Card]<<Cards[Suit]<<"  ";
}

getch();


}









void assign()
{
Cards[0] ="Ace";
Cards[1] ="2";
Cards[2] ="3";
Cards[3] ="4";
Cards[4] ="5";
Cards[5] ="6";
Cards[6] ="7";
Cards[7] ="8";
Cards[8] ="9";
Cards[9] ="10";
Cards[10]="Jack";
Cards[11]="Queen";
Cards[12]="King";

Cards[13]=" Spades";
Cards[14]=" Diamonds";
Cards[15]=" Clubs";
Cards[16]=" Hearts";


}
