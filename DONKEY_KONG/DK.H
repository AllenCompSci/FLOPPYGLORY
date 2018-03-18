#include <time.h>

struct M                                //MARIO STRUCT
{
unsigned char far Image[16*16];         //Actual sprite
unsigned char far Background[16*16];    //Background holder
int X;                                  //X position
int Y;                                  //Y position
int Mx;                                 //Move x value
int My;                                 //Move y value
bool Jump;                              //Jump (T/F)
};

struct Map                              //LEVEL STRUCT
{
int Floor;                              //Floor color
};

struct B
{
unsigned char far Image[120];           //Sprite
unsigned char far Background[120];      //Background
int X;                                  //X position
int Y;                                  //Y position
int Mx;                                 //Move x value
int My;                                 //Move y value
bool Active;                            //Whether or not it is active
time_t Initialize;                      //Initialization time
time_t Terminate;                       //Termination time;
};