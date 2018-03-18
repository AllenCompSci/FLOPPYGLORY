/*************************************************************************
*THE DOUBLE BUFFER LIBRARY FOR TURBO C++                                 *
*																																				 *
*CREATED BY GEORGE ELEFTHERIOU                                           *
*																																				 *
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/*
FUNCTIONS:

cutbackground ( X position, Y position, X1 position, Y1 position, Source, Destination)
	-Takes a section of Source, (X,Y) to (X1,Y1) and puts it in Destination

flip (Source, Destination)
	-Literally flips the source to the destination, the "double buffer" action

clearmem (Source, Length of array)
	-Fills the array with black

transfer ( X position, Y position, X1 position, Y2 position, Source, Destination)
	-Transfers a memory segment to another (ie, the buffer) at (X,Y) to (X1,Y1) position

** The following were not created by me, only modified (I do not know his name, but thanks)

getcol (int Color)
	-Takes a color number and returns its corresponding 4-bit color

loadbitmap (Filename, Transparency color, Dest)
	-Opens a bitmap at the filename location and puts it in an unsigned char far Destination. **Transparent colors are filled with NULL


*/



void cutbackground (int X, int Y, int X1, int Y1, unsigned char far * Source, unsigned char far * Dest)
{
int A, B, Width, Height;

Width = abs(X1-X);
Height = abs(Y1-Y);

for (B=0; B<Width; B++)
	{
	for (A=0; A<Height; A++)
		Dest[(Width*B)+A]=Source[(320*B)+A];
	}
}

void flip (unsigned char far * Source, unsigned char far * Dest)
{
asm{
	push ds			 					 	//Saves the data segment
	les di,Dest 						//Sets destination
	lds si,Source 	 				//Sets source
	mov cx,(320*200)/2      //Tells how much memory to move
	cld											//Words
	rep movsw  							//Does the movement
	pop ds									//Restores the data segment
	}
}

void clearmem(unsigned char far * Dest, unsigned int Length)
{
unsigned int A;

for (A=0; A<Length; A++)
	Dest[A]=255;

}
void transfer (int X, int Y, int X1, int Y1, unsigned char far * Source, unsigned char far * Dest)
{
int A, B, Width, Height;

Width = abs(X1-X);
Height = abs(Y1-Y);

for (B=0; B<Height; B++)
	{
	for (A=0; A<Width; A++)
		if (Source[(B*Width)+A]!=NULL)
			Dest[((B+Y)*320)+A+X]=Source[(B*Width)+A];
	}

}

//BITMAP LOADING

int getcol(int col)
{
       switch(col)
       {
               case 0: return 0;        //BLACK;
               case 1: return 4;        //RED;
               case 2: return 2;        //GREEN
               case 3: return 6;        //BROWN
               case 4: return 1;        //BLUE;
               case 5: return 5;        //MAGENTA;
               case 6: return 3;        //CYAN;
               case 7: return 7;        //LIGHTGRAY;
               case 8: return 8;        //DARKGRAY;
							 case 9: return 12;       //LIGHTRED;
							 case 10:return 10;    		//LIGHTGREEN
							 case 11:return 14;    		//YELLOW;
							 case 12:return 9;     		//LIGHTBLUE;
							 case 13:return 13;    		//LIGHTMAGENTA
							 case 14:return 11;    		//LIGHTCYAN;
							 case 15:return 15;    		//WHITE;
       }
       return col;
}

int loadbitmap(char *filename, int T, unsigned char far * Dest)
{
       FILE *ptr=NULL;														//file handle to open bitmap file
       int width,height; 
		 int ch,ch1,ch2;                              //width and height of the bitmap
			 unsigned long temp=0,i=0,j=0;							//some variables i need
       unsigned long ww;
	   Dest[1]=5;
			 ptr=fopen(filename,"rb");									//open the bitmap file
       if(!ptr) return 0;                                                   //if its not there return
       width=0;height=0;													//initialise wisth and height to zero
			 fseek(ptr,18,SEEK_SET);										//got to offset 18 in file
			 for(i=0x1;i<=0x10000;i*=0x100)						  //read the width
       {
               temp=fgetc(ptr);
               width+=(temp*i);
       }
			 fseek(ptr,22,SEEK_SET);										//go to offset 22 in file
			 for(i=0x1;i<=0x10000;i*=0x100)							//read the height
       {
               temp=fgetc(ptr);
               height+=(temp*i);
       }

			 ww=width;                                  //ww is the number of reads to make for each horizontal line
			 if(ww%2)                                   //ww has to be half of width - since each pixel is only 4 bits of information
			 ww++;ww/=2;                                //just getting the correct value
			 if(ww%4)                                   //now - ww is stored as sets of 4 pixels each - i think !?! :so this is the adjustment    made
			 ww=(ww/4)*4+4;                             //if width is less than ww*2 we ignore what we read

			 fseek(ptr,119,SEEK_SET);                   //Ok! offset 119 - lets read the pixels - remember the bitmap is stroed up - side - down
       for(i=0;i<height;i++)
       for(j=0;j<ww;j++)
       {
							 ch=fgetc(ptr);                     //each character read is 2 pixels - yes 4 bits per pixel - so 16 colors
							 ch1=ch;ch2=ch;                     //find those colors using bitwise ops
							 ch1=ch1&(0xf0);ch1=ch1>>4;
							 ch2=ch2&(0x0f);

				 if(j*2<width)
					{
					if  (getcol(ch1)==T)
						Dest[(i*width)+j*2]=NULL;

					else
						Dest[(i*width)+j*2]=getcol(ch1);
					}

				 if(j*2+1<width)
					{
					if (getcol(ch2)==T)
						Dest[(i*width)+j*2+1]=NULL;

					else
						Dest[(i*width)+j*2+1]=getcol(ch2);
					}

       }	
			 fclose(ptr);
											//close the file handle
       return 1;
}

