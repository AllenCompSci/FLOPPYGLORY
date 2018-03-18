#include <svga.h>
#include <conio.h>
#include <iomanip.h>

#define W	0.836601f
#define H 8

void box(int x, int y, float w, float h, BYTE r, BYTE g, BYTE b)
{
	setfillstyle(SOLID_FILL, r, g, b);

	bar((float)x*w, (float)y*h, (float)x*w+w-1, (float)y*h+h-1);
}

int scaleX(int x)
{
	return x * 2;
}

int scaleY(int y)
{
	return y * 2;
}

void main()
{
	BYTE c;
	int graph_driver = VGA, graph_mode = VGAHI;

	gotoxy(33, 12);
	cout<<"The old way...";
	getch();

	initgraph(&graph_driver, &graph_mode, "c:/tc/bgi");

	for (c=0; c<16; c++)
	{
		setfillstyle(SOLID_FILL, c);
		bar(c*40, 0, c*40+39, 479);
	}

	getch();

	cleardevice();

	for (int x=0; x<600; x++)
	{
		setfillstyle(SOLID_FILL, 1);
		bar(x, 220, x+40, 260);
		delay(10);
		setfillstyle(SOLID_FILL, 0);
		bar(x, 220, x+40, 260);
	}

	closegraph();

	gotoxy(34, 12);
	cout<<"THE NEW WAY!";

	getch();
	clrscr();

	if (gr_init(SVGATC, 6, "c:/tc/bgi") == grOk)
	{
		int i;
		for (i=0, c=0; i<256; i++, c++)
			for (int y=0; y<128; y++)
			{
				if (c >= 128)
					box(c, y, W, H, 255-y, c-((float)(c-128)/128.0f)*(float)y, y);
				else
					box(c, y, W, H, 255-y, c+((float)(128-c)/128.0f)*(float)y, y);
			}

		for (i=0, c=255; i<256; i++, c--)
			for (y=0; y<128; y++)
			{
				if (c >= 128)
					box(i+256, y, W, H, c-((float)(c-128)/128.0f)*(float)y, 255-y, y);
				else
					box(i+256, y, W, H, c-((float)(c-128)/128.0f)*(float)y, 255-y, y);
			}

		for (i=0, c=0; i<256; i++, c++)
			for (y=0; y<128; y++)
			{
				if (c >= 128)
					box(c+512, y, W, H, y, 255-y, c-((float)(c-128)/128.0f)*(float)y);
				else
					box(c+512, y, W, H, y, 255-y, c+((float)(128-c)/128.0f)*(float)y);
			}

		for (i=0, c=255; i<256; i++, c--)
			for (y=0; y<128; y++)
			{
				if (c >= 128)
					box(i+768, y, W, H, y, c-((float)(c-128)/128.0f)*(float)y, 255-y);
				else
					box(i+768, y, W, H, y, c-((float)(c-128)/128.0f)*(float)y, 255-y);
			}

		for (i=0, c=0; i<256; i++, c++)
			for (y=0; y<128; y++)
			{
				if (c >= 128)
					box(c+1024, y, W, H, c-((float)(c-128)/128.0f)*(float)y, y, 255-y);
				else
					box(c+1024, y, W, H, c+((float)(128-c)/128.0f)*(float)y, y, 255-y);
			}

		for (i=0, c=255; i<256; i++, c--)
			for (y=0; y<128; y++)
			{
				if (c >= 128)
					box(i+1280, y, W, H, 255-y, y, c-((float)(c-128)/128.0f)*(float)y);
				else
					box(i+1280, y, W, H, 255-y, y, c-((float)(c-128)/128.0f)*(float)y);
			}

		getch();
		cleardevice();

		for (int x=0; x<1240; x++)
		{
			setfillstyle(SOLID_FILL, 134, 74, 147);
			bar(x, 492, x+40, 532);
			//setfillstyle(SOLID_FILL, 0, 0, 255);
			//bar(2*x, 492*2, (x+40)*2, 1064);
			delay(10);
			setfillstyle(SOLID_FILL, 0, 0, 0);
			bar(x, 492, x+40, 532);
			//bar(2*x, 492*2, (x+40)*2, 1064);
		}

	}

	closegraph();

	gotoxy(28, 12);
	cout<<"Use new SVGA Modes with";
	gotoxy(31, 13);
	cout<<"your newest game!";
	getch();
}