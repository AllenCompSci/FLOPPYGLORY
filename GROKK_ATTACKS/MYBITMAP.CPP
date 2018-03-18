#include <bitmap.h>
#include "shipdata.hpp"
#include <malloc.h>

void menu_planets()
{
image Earth,Mars;
Earth.open("a:/grok/earth.bmp");
Mars.open("a:/grok/mars.bmp");
Earth.draw(5,5);
Mars.draw(430,330);
Earth.close();
Mars.close();

}

void draw_boss1(Bosses& Boss)
{
	image Boss1reg,Boss1hit;
	Boss1reg.open("a:/GROK/BOSS11.BMP");
	Boss1hit.open("a:/GROK/BOSS12.BMP");

	Boss1reg.draw(50,50);
	Boss.Bsize=imagesize(50,50,50+300,50+282);
	Boss.Bosspic=farmalloc(Boss.Bsize);
	if(!Boss.Bosspic)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(50,50,50+300,50+282,Boss.Bosspic);
	putimage(50,50,Boss.Bosspic,XOR_PUT);

	Boss1hit.draw(50,50);
	Boss.Bsize=imagesize(50,50,50+300,50+282);
	Boss.Bosshit=farmalloc(Boss.Bsize);
	if(!Boss.Bosshit)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(50,50,50+300,50+282,Boss.Bosshit);
	putimage(50,50,Boss.Bosshit,XOR_PUT);

	Boss1reg.close();
	Boss1hit.close();
}

void draw_boss2(Bosses& Boss)
{
	image Boss2reg,Boss2hit;
	Boss2reg.open("a:/GROK/BOSS21.BMP");
	Boss2hit.open("a:/GROK/BOSS22.BMP");

	Boss2reg.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+449,10+209);
	Boss.Bosspic=farmalloc(Boss.Bsize);
	if(!Boss.Bosspic)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+449,10+209,Boss.Bosspic);
	putimage(10,10,Boss.Bosspic,XOR_PUT);

	Boss2hit.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+449,10+210);
	Boss.Bosshit=farmalloc(Boss.Bsize);
	if(!Boss.Bosshit)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+449,10+210,Boss.Bosshit);
	putimage(10,10,Boss.Bosshit,XOR_PUT);
	Boss2reg.close();
	Boss2hit.close();
}

void draw_boss3(Bosses& Boss)
{
	image Boss3reg,Boss3hit;
	Boss3reg.open("a:/GROK/BOSS31.BMP");
	Boss3hit.open("a:/GROK/BOSS32.BMP");

	Boss3reg.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+462,10+243);
	Boss.Bosspic=farmalloc(Boss.Bsize);
	if(!Boss.Bosspic)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+462,10+243,Boss.Bosspic);
	putimage(10,10,Boss.Bosspic,XOR_PUT);

	Boss3hit.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+462,10+243);
	Boss.Bosshit=farmalloc(Boss.Bsize);
	if(!Boss.Bosshit)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+462,10+243,Boss.Bosshit);
	putimage(10,10,Boss.Bosshit,XOR_PUT);
	Boss3reg.close();
	Boss3hit.close();
}

void draw_boss4(Bosses& Boss)
{
	image Boss4reg,Boss4hit;
	Boss4reg.open("a:/GROK/BOSS34.BMP");
	Boss4hit.open("a:/GROK/BOSS35.BMP");

	Boss4reg.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+462,10+197);
	Boss.Bosspic=farmalloc(Boss.Bsize);
	if(!Boss.Bosspic)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+462,10+197,Boss.Bosspic);
	putimage(10,10,Boss.Bosspic,XOR_PUT);

	Boss4hit.draw(10,10);
	Boss.Bsize=imagesize(10,10,10+462,10+197);
	Boss.Bosshit=farmalloc(Boss.Bsize);
	if(!Boss.Bosshit)
	{
		cout<<"Out of Mem"<<endl;
		cout<<"Shipdata ship: 9";
		getch();
		exit(1);
	}
	getimage(10,10,10+462,10+197,Boss.Bosshit);
	putimage(10,10,Boss.Bosshit,XOR_PUT);
	Boss4reg.close();
	Boss4hit.close();

}

void change_color()
{
image pixl;
pixl.open("a:/grok/pixle.bmp");
pixl.draw(100,100);
putpixel(100,100,0);
pixl.close();
}