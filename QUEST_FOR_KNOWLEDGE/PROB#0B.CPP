//Michael Crookston
//Prob#00
//8/16/00
//Period 6
//Mr. Baker
//Libraries Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//Constants

const apstring CONTINUE = "Press Return to Continue.";

//Variables

apstring MyName;
apstring MyAddress;
apstring MyPhone;

//Program
void main ()
{

MyName = "Michael Crookston";
MyAddress = "1301 Lombardy Way";
MyPhone = "972-390-8721";

cout <<endl<<MyName<<endl<<MyAddress<<endl<<MyPhone<<endl<<CONTINUE<<endl;
getch();
clrscr();
}
