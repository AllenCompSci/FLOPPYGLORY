#include<apvector.h>
//struct
typedef struct
{
	int X,Y;
	bool Putstar;
} Star;

typedef struct
{
	//Shots
	int X,Y,Mvup,Mvdwn;
	bool Shoot;
} Shot;

typedef struct
{
	//Myship
	int X,Y,Moveleft,Moveright,Shootnum;
	apvector <Shot> Myshot;
	bool Lose,Win,Win_game;
	void far *Myship, *Shotpic;
	unsigned Mysize,Shotsize;
	int Continue;
} Myship_dat;

typedef struct
{
	long X;      // Ship X position
	long Y;      // Ship Y position
	int Form;
	bool Frontrow;
	bool Fire;
	Shot Eshot1;
	Shot Eshot2;
	apvector <Shot> Eshots;
	void far *Enemyship;
	void far *Enemyshot;
	unsigned Enemysize;
	unsigned Eshotsize;
} Enemy;

typedef struct
{
	apvector <Enemy> Eship;
	int Enumber;
} Edat;

typedef struct
{
	int X;
	int Y;
	int NumKO;
	int Numshot;
	bool Fire;
	Shot Bshot1;
	Shot Bshot2;
	void far *Bosspic;
	void far *Bosshit;
	void far *Bshot;
	unsigned Bsize;
	unsigned Bshotsize;


} Bosses;


//Prototypes
void draw_my_ship(Myship_dat&);
void draw_ship1(apvector <Edat>&);
void draw_ship2(apvector <Edat>&);
void draw_ship3(apvector <Edat>&);
void draw_ship4(apvector <Edat>&);
void draw_ship5(apvector <Edat>&);
void draw_ship6(apvector <Edat>&);
void draw_ship7(apvector <Edat>&);
void draw_ship8(apvector <Edat>&);
void draw_ship9(apvector <Edat>&);
void draw_ship10f1();
void draw_ship10f2();
void draw_ship10r(Enemy&);
void draw_boss1(Bosses&);
void draw_boss2(Bosses&);
void draw_boss3(Bosses&);
void draw_boss4(Bosses&);
void draw_boss_shot1(Bosses&);
void draw_shot1(Myship_dat&, apvector <Edat>&);
void blow_up(int,int);
void init_space(apvector <Star>&);
void move_space(apvector <Star>&);
