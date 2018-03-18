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

void help()
{
cleardevice();
setcolor(1);
outtextxy(50,50,"Instructions:");
outtextxy(50,70,"Numpad 4: Move left");
outtextxy(50,90,"Numpad 6: Move right");
outtextxy(50,110,"Numpad 8: Shoot");
getch();


}