//KRIS BICKHAM
//PROB#13
//DUE
//PERIOD 6
//MR. BAKER
//LIBRARIES------------
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
//VARIABLES------------
int Line;
int Again;
//CONSTANTS------------
//MAIN
void main ()
{
clrscr();
Line=1;
while(Line<=7)
{	 switch(Line)
 {case 1: cout<<setw(7)<<"*"<<endl;
					break;
	case 2: cout<<setw(9)<<"* * *"<<endl;
					break;
	case 3: cout<<setw(11)<<"* * * * *"<<endl;
					break;
	case 4: cout<<setw(13)<<"* * * * * * *"<<endl;
					break;
	case 5: cout<<setw(11)<<"* * * * *"<<endl;
					break;
	case 6: cout<<setw(9)<<"* * *"<<endl;
					break;
	case 7: cout<<setw(7)<<"*"<<endl;
					break;}
Line+=1;}





getch();





}

