#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <apstring.h>
#include <apvector.h>
#include <apmatrix.h>
#include <apstring.h>
#include <graphics.h>
#include <dos.h>
#include "lv.hpp"

void loose()
{
cleardevice();
delay(1000);
getch();
while(!kbhit())
{
	setcolor(random(14)+1);
	outtextxy(200,100,"YOU LOST TO GROKK!!");
}
 delay(100);
}