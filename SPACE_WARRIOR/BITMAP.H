/////////////////////////////////////////////////////////////////////////////
//*HEADER FILE*//////////////////////////////////////////////////////////////
//                                                                         //
//      WINDOWS BITMAP LOADER -v1.0- AUGUST 2001                               //
//      CODED BY RYAN BUNKER                                                   //
//                                                                         //
//      LOADS AND DRAWS A BITMAP BY USE OF AN image CLASS                      //
//      NOTES:                                                                 //
//              * CURRENT VERSION DOES NOT SUPPORT 8 BIT (256) OR 24 BIT             //
//              (16.7 million) COLOR DEPTH                                                                                                                                                       //
//              * GRAPHICS MODE MUST BE INITIALIZED TO USE DRAW FUNCTION             //
//              * CALLING image::open WILL SET AND OVERWRITE THE CURRENT PALETTE     //
//              * CALLING image::draw WILL OVERWRITE UNDERLYING IMAGE ON SCREEN AND  //
//                      ORIGINAL IMAGE WILL NOT BE RESCUABLE                               //
//      FEATURES                                                               //
//      * IMAGE CAN BE ROTATED, SMALLEST ROTATION SIZE, 1 DEGREE             //
//              * IMAGE CAN BE DRAWN TRANSPARENT                                     //
//              * IMAGE CAN BE DRAWN TRANSLUCENT (LIMITED ABILITY IN 16 COLORS)                  //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#ifndef __BITMAP_H__
#define __BITMAP_H__
#define explicit

#include<conio.h>
#include<apstring.h>
#include<fstream.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>

//STRUCTURES
struct BMPFileHead
{       unsigned char bfType[3],      // FILE TYPE, MUST BE "BM"
                                                                bfSize[5],      // SIZE OF FILE, IN BYTES
                                                                bfReserved1[3], // ALWAYS SET TO 0
                                                                bfReserved2[3], // ALWAYS SET TO 0
                                                                bfOffBits[5];   // OFFSET FROM BEGINNING OF FILE TO BMP DATA
};

struct BMPInfoHead
{       unsigned char biSize[5],          // SIZE OF BITMAP INFO HEADER
                                                                biWidth[5],         // WIDTH OF IMAGE, IN PIXELS
                                                                biHeight[5],        // HEIGHT OF IMAGE, IN PIXELS
                                                                biPlanes[3],        // # OF PLANES OF TARGET DEVICE
                                                                biBitCount[3],      // # OF BITS PER PIXEL
                                                                biCompression[5],   // TYPE OF COMPRESSION
                                                                biSizeImage[5],     // SIZE OF IMAGE DATA
                                                                biXPelsPerMeter[5], // HORIZONTAL PIXELS PER METER OF DEVICE
                                                                biYPelsPerMeter[5], // VERTICAL PIXELS PER METER OF DEVICE
                                                                biClrUsed[5],       // # OF COLORS USED IN BITMAP
                                                                biClrImportant[5];  // # NUMBER OF IMPORTANT COLORS
};

struct RGBQuad
{       unsigned char rgbBlue[2];     // BLUE PART OF COLOR, 0-255
        unsigned char   rgbGreen[2];    // GREEN PART OF COLOR, 0-255
        unsigned char   rgbRed[2];      // RED PART OF COLOR, 0-255
        unsigned char   rgbReserved[2]; // ALWAYS SET TO 0
};

//THIS STRUCT IS USED AS PART OF image::data AS A RETURN TYPE
//FOR THE BITMAP DATA
struct ImgData
{ double FileSize,                                                      // SIZE OF FILE, IN BYTES
                                 Width, Height,                                 // WIDTH AND HEIGHT OF BITMAP, IN PIXELS
                                 BitsPerPixel,          // # OF BITS PER PIXEL
                                 Colors,                // # OF COLORS USED IN BITMAP
                                 ImportantColors;       // # OF IMPORTANT COLORS
        RGBQuad Palette[16];                            // COLOR PALETTE
};

//DESCRIBES ALL THE PROPERTIES OF AN ERROR
struct Error
{       apstring Description, // DESCRIPTION OF ERROR
                                         Source;                        // SOURCE OF ERROR
        int Number;                                             // ERROR CODE
};

//ALLOWS ERROR HANDLING
struct ErrHandler
{       bool On;                                                        // SETS WHETHER ERROR HANDLING IS ON OR OFF
        Error Err;                                              // STORES DESCRIPTION OF ERROR IF ONE IS ENCOUNTERED
};

struct palettetype CPalette;

ErrHandler GErrors;

//CLASSES
class image
{
/*      CLASS IMAGE--V 1.0

                Variables:
                        Private
                                Integers
                                        Height = image height
                                        Width = image width
                                        BPP = bits per pixel
                                        grdriver = Graphics Driver ID
                                        grmode = Graphics Mode
                                        errorcode = error returned by graphics initialization
                                FILE
                                        In (pointer) = points to bitmap file
                                        InA (pointer) = points to alpha data file
                                BMPFileHead (struct)
                                        BFH = struct to hold Bitmap File Header data
                                BMPInfoHead (struct)
                                        BIH = struct to hold Bitmap Info Header data
                                RGBQuad (struct)
                                        Palette[16] = color palette for image
                        Public
                                <NONE>
                Functions:
                        Private
                                bool biton(unsigned char, int)
                                        takes a byte and returns whether the specified bit is on

                                unsigned char splitbyte(unsigned char, int)
                                        takes a byte and returns either the left or right half
                                        of the byte, depending on passed in integer

                                void rotate(int&,int&,int)
                                        takes an X,Y coordinate and rotates it by a specified
                                        angle, used to rotate bitmaps

                                void pixelplot(int x, int y, int a, int t, unsigned char c)
                                        does the actual drawing of the image along with rotation by
                                        a if a!=0 and with transparency of type T using color c

                                void gr_start(int&,int&,int&)
                                        initializes graphics in either 640x580x16 or 320x240x256
                        Public
                                bool open(apstring filename)
                                        takes filename and opens bitmap to draw, returns true if
                                        open is succesful, false if it isn't

                                void close()
                                        closes image file

                                bool draw(int Y, int X)
                                        takes x and y coordinates and draws image there, returns
                                        true if draw is succesful, false if it isn't

                                bool draw(int X, int Y, int A)
                                        takes x and y coordinates and draws image there rotating by
                                        a degrees

                                bool draw(int X, int Y, int T, unsigned char C)
                                        takes x and y coordinates and draws image there with transpa-
                                        rency of type T using color C

                                ImgData data(bool)
                                        returns image data and prints to screen if specified
*/
                int Height,Width,BPP;
                FILE *In;
                BMPFileHead BFH;
                BMPInfoHead BIH;
                RGBQuad Palette[16];
                ErrHandler Errors;

                bool biton(unsigned char,int);
                unsigned char splitbyte(unsigned char,int);
                void rotate(int&,int&,int);
                bool pixelplot(int, int, int, int, unsigned char);

        public:
                int colormatch(unsigned char,unsigned char,unsigned char);
                bool open(apstring);

                void close()                  { fclose(In);                   };
                bool draw(int X,int Y)        { return pixelplot(X,Y,0,-1,0); };
                bool draw(int X,int Y, int A) { return pixelplot(X,Y,A,-1,0); };
								bool draw(int X,int Y, int T,unsigned char C)
																							{ return pixelplot(X,Y,0, T,C); };
								ImgData data(int X,int Y);
                ImgData data()                { return data(-1,-1);           };

                //ERROR HANDLING
                void SetErrHandling(bool On)  { Errors.On=On;                 };
                Error GetError()                                                  { return Errors.Err;            };
};

//GLOBAL FUNCTIONS
//used to detect 256 Color graphic drivers
int huge DetectVGA256();
void graphinit(int);
void SetGErrHandling(bool On) { GErrors.On=On; };

//GLOBAL CONSTANTS
//SPLIT_LEFT AND SPLIT_RIGHT USED IN FUNCTION splitbit
const int SPLIT_LEFT=128,SPLIT_RIGHT=8;
//PRINT AND NO_PRINT USED IN FUNCTION data
const bool PRINT=true,NO_PRINT=false;
//TRANSPARENCY OPTIONS
const int TRANSPARENT=1,TRANSLUCENT=0;
//ERROR HANDLING ON/OFF SETTINGS
const bool ON=true,OFF=false;
//COLOR CONVERSION CONSTANT FROM 255 SYSTEM TO 63 SYSTEM
const long double CC=0.247058823529411764705882352941176;
//GRAPH MODE CONSTANTS FOR 16 OR 256 COLORS
const int GR16=16,GR256=256;
//ERROR CONSTANTS
const int bmpFileNotFound  = 111;
const int bmpWrongType     = 112;
const int bmpWrongBitDepth = 113;
const int bmpNoGraphInit   = 121;
const int bmpUndefinedFile = 122;

bool image::open(apstring Bitmap)
{ /*
        Integers
                I = Loop control variable
                Colors = Number of colors in Bitmap palette
                RowWidth = Byte Offset of pixel data
        Characters
                File[50] = natural string for filename
                RowNull[4] = reads in Byte OffSet
                Byte = temporary read in
        Apstrings
                Bitmap (passed in) = filename of bitmap
        */

        int I,Colors,RowWidth;
        char File[50],RowNull[4],Byte[1];

        //RESET ERRORS
        Errors.Err.Number=0;

        //CONVERTS APSTRING FILENAME TO NATURAL FILENAME
        for (I=0;I<Bitmap.length();I++) File[I]=' ';
        for (I=0;I<Bitmap.length();I++) File[I]=Bitmap[I];
        //APPENDS NULL CHARACTER ON ARRAY
        File[I]='\0';

        //CLOSES FILE TO PREPARE FOR NEW IMAGE
        fclose(In);

        //OPENS FILE, READ BINARY, AND CHECKS IF FILE EXISTS
        In=fopen(File,"rb");
        if (In==NULL)
        { if (!Errors.On)
                        cout<<"||error image::open -> FILE NOT FOUND||";
                else
                {       Errors.Err.Description="FILE NOT FOUND";
                        Errors.Err.Source="image::open";
                        Errors.Err.Number=111;
                }
                return false;
        }

        //READS IN FILE TYPE AND CHECKS IF ITS A BITMAP
        fread(BFH.bfType,sizeof(char),2,In);
        BFH.bfType[2]='\0';
        if (BFH.bfType!="BM" && feof(In))
        { if (!Errors.On)
                        cout<<"error image::open -> FILE NOT OF BITMAP TYPE";
                else
                {       Errors.Err.Description="FILE NOT OF BITMAP TYPE";
                        Errors.Err.Source="image::open";
                        Errors.Err.Number=112;
                }
                return false;
        }

        //READS IN FILE INFORMATION ACCORDING TO BITMAP FORMAT
        fread(BFH.bfSize,sizeof(char),4,In);
        fread(BFH.bfReserved1,sizeof(char),2,In);
        fread(BFH.bfReserved2,sizeof(char),2,In);
        fread(BFH.bfOffBits,sizeof(char),4,In);
        BFH.bfSize[4]='\0';
        BFH.bfReserved1[2]='\0';
        BFH.bfReserved2[2]='\0';
        BFH.bfOffBits[4]='\0';

        //READS IN FILE HEADER ACCORDING TO BITMAP FORMAT
        fread(BIH.biSize,sizeof(char),4,In);
        fread(BIH.biWidth,sizeof(char),4,In);
        fread(BIH.biHeight,sizeof(char),4,In);
        fread(BIH.biPlanes,sizeof(char),2,In);
        fread(BIH.biBitCount,sizeof(char),2,In);

        //GET CURRENT COLOR PALETTE
        getpalette(&CPalette);

        //DOES NOT SUPPORT 24BIT OR 8BIT COLOR DEPTH
        if ((BIH.biBitCount[1]*256+BIH.biBitCount[0])==24 ||
                        ((BIH.biBitCount[1]*256+BIH.biBitCount[0])==8 &&
                        getgraphmode()!=0                             ))
        { if (!Errors.On)
                {       cout<<"||error image::open -> ";
                        cout<<(BIH.biBitCount[1]*256+BIH.biBitCount[0]);
                        cout<<"BIT COLOR DEPTH NOT SUPPORTED||";
                }
                else
                {       Errors.Err.Description="COLOR DEPTH NOT SUPPORTED";
                        Errors.Err.Source="image::open";
                        Errors.Err.Number=113;
                }
                return false;
        }

        fread(BIH.biCompression,sizeof(char),4,In);
        fread(BIH.biSizeImage,sizeof(char),4,In);
        fread(BIH.biXPelsPerMeter,sizeof(char),4,In);
        fread(BIH.biYPelsPerMeter,sizeof(char),4,In);
        fread(BIH.biClrUsed,sizeof(char),4,In);
        fread(BIH.biClrImportant,sizeof(char),4,In);

        //FINDS BITS PER PIXEL (BPP)
        BPP=BIH.biBitCount[1]*256+BIH.biBitCount[0];

        //FIND AMOUNT OF COLORS USED
        if ((BIH.biClrUsed[3]*256+BIH.biClrUsed[2]))
                Colors=BIH.biClrUsed[3]*256+BIH.biClrUsed[2];
        else
                Colors=pow(2,BPP);

        //LOAD COLOR PALETTE
        for (I=0;I<Colors;I++)
        {       fread(Palette[I].rgbBlue,sizeof(char),1,In);
                fread(Palette[I].rgbGreen,sizeof(char),1,In);
                fread(Palette[I].rgbRed,sizeof(char),1,In);
                fread(Palette[I].rgbReserved,sizeof(char),1,In);

                Palette[I].rgbRed[0]  =Palette[I].rgbRed[0]  *CC;
                Palette[I].rgbGreen[0]=Palette[I].rgbGreen[0]*CC;
                Palette[I].rgbBlue[0] =Palette[I].rgbBlue[0] *CC;

                setrgbpalette(CPalette.colors[I],Palette[I].rgbRed[0]+0,Palette[I].rgbGreen[0]+0,Palette[I].rgbBlue[0]+0);
//--DEBUGGING CODE-----------------------------------------------------------
//              clrscr();
//              cout<<I<<"  R:"<<Palette[I].rgbRed[0]+0<<"  G:"<<Palette[I].rgbGreen[0]+0;
//              cout<<"  B:"<<Palette[I].rgbBlue[0]+0;
//              cout<<endl;
//              getch();
//-----------------------------------------------------------------------------

        }

//      cout<<"END";

        //FIND WIDTH AND HEIGHT OF IMAGE
        Width=BIH.biWidth[1]*256+BIH.biWidth[0];
        Height=BIH.biHeight[1]*256+BIH.biHeight[0];

//      gr_start(grdriver,grmode,errorcode);

        //RETURN SUCCESSFUL
        return true;
}

/////////////////////////////////////////////////////////////////////////////

ImgData image::data(int X, int Y)
{
/*Integers
                Colors = number of colors used in image
                X, Y (passed in) = X, Y location to print data, if -1, dont print
        ImgData (struct)
                retData = the data to return
        RGBQuad (struct)
                ptrPal (pointer) = pointer to first element in Palette
*/

        int Colors;
        ImgData retData;
        RGBQuad *ptrPal;

        //COPY MEMBER IMAGE DATA TO retData
/*      retData.FileSize        = BFH.bfSize;
        retData.Width           = BIH.biWidth;
        retData.Height          = BIH.biHeight;
        retData.BitsPerPixel    = BIH.biBitCount;
        retData.Colors          = BIH.biClrUsed;
        retData.ImportantColors = BIH.biClrImportant;*/
        //POINT ptrPal TO Palette[0] FOR ARRAY COPYING
        ptrPal=&Palette[0];
        retData.Palette[0]=*ptrPal;

        //PRINT DATA IF Print IS TRUE
        if (X>=0 || Y>=0)
        { /*if ((BIH.biClrUsed[3]*256+BIH.biClrUsed[2]))
                        Colors=BIH.biClrUsed[3]*256+BIH.biClrUsed[2];
                else
                        Colors=pow(2,BPP);*/

                gotoxy(X,Y+0); cout<<"SIZE  :"<<retData.FileSize       ;
                gotoxy(X,Y+1); cout<<"WIDTH :"<<retData.Width          ;
                gotoxy(X,Y+2); cout<<"HEIGHT:"<<retData.Height         ;
                gotoxy(X,Y+3); cout<<"BITCNT:"<<retData.BitsPerPixel   ;
                gotoxy(X,Y+4); cout<<"CLRUSE:"<<retData.Colors         ;
                gotoxy(X,Y+5); cout<<"CLRIMP:"<<retData.ImportantColors;
        }

        //RETURN DATA
        return retData;
};

/////////////////////////////////////////////////////////////////////////////

bool image::pixelplot(int X,int Y,int A,int T,unsigned char C)
{
/*Integers
                X (passed in) = X location to draw image
                Y (passed in) = Y location to draw image
                A (passed in) = Angle to rotate, none if 0
                T (passed in) = Type of transparency, -1=none, 0=translucent,
                                                                                1=transparent
                C (passed in) = Transparent color, only used if T=0
                XX, YY = coordinate loop variables
                Tx, Ty = Temporary coordinates, used with rotating
                I, M = One bit per pixel loop control variables
                RowWidth = byte offset of image
        Unsigned Characters
                Byte[2] = array used to read bytes from file
                RowNull[4] = trash array for null bytes at end of row
*/

        int XX,YY,Tx,Ty,Fc,Bc,r1,g1,b1,I,M,RowWidth;
        unsigned char Byte[2],RowNull[4];

        //CHECK TO MAKE SURE GRAPHICS HAS BEEN INITIALIZED
        if (getgraphmode()==-1)
        { if (!Errors.On)
                        cout<<"||error image::draw -> GRAPHICS NOT INITIALIZED||";
                else
                {       Errors.Err.Description="GRAPHICS NOT INITTIALIZED";
                        Errors.Err.Source="image::draw";
                        Errors.Err.Number=121;
                }
                //RETURN UNSUCCESSFUL
                return false;
        }

        //CHECK TO MAKE SURE IMAGE HAS BEEN OPENED
        if (fseek(In,(BFH.bfOffBits[1]*256+BFH.bfOffBits[0]),SEEK_SET))
        { if (!Errors.On)
                        cout<<"||error image::draw -> UNDEFINED FILE||";
                else
                {       Errors.Err.Description="UNDEFINED FILE";
                        Errors.Err.Source="image::draw";
                        Errors.Err.Number=122;
                }
                //RETURN UNSUCCESSFUL
                return false;
        }

        //FIND RowWidth BASED ON BITS PER PIXEL
        if (BPP==1)
                RowWidth=(((((Width/8)+((Width%8)!=0))%4)!=0)*4)-((Width/8)+((Width%8)!=0))%4;
        else if (BPP==4)
                RowWidth=(((((Width/2)+(Width%2))%4)!=0)*4)-((Width/2)+(Width%2))%4;
        else if (BPP==8)
                RowWidth=(((Width%4)!=0)*4)-(Width%4);


        //MAIN DRAWING LOOP
        for (YY=Y+Height-1;YY>=Y;YY--)
        { if (BPP==8)
                {       for (XX=X;XX<Width+X;XX++)
                        { //READ IN SINGLE BYTE CORRESPONDING TO PIXEL'S
                                //COLOR VALUE STORED IN THE COLOR TABLE
                                fread(Byte,sizeof(char),1,In);
                                putpixel(XX,YY,Byte[0]);
                                if (Byte[0]==109)
                                        M=4;
                        }
                }
                else if (BPP==4)
                {       for (XX=X;XX<Width+X;XX+=2)
                        { //READ IN SINGLE BYTE AND SPLIT IT, FINDING
                                //THE TWO COLOR TABLE VALUES STORED IN IT
                                fread(Byte,sizeof(char),1,In);
                                Tx=XX;
                                Ty=YY;
                                if (A!=0)
                                {       Tx-=(Width/2+X);
                                        Ty=(Height/2+Y)-Ty;
                                        rotate(Tx,Ty,A);
                                        Tx+=Width/2+X;
                                        Ty=(Height/2+Y)-Ty;
                                }
																Fc=splitbyte(Byte[0],SPLIT_LEFT);
																//cout<<"!"<<Fc<<"!";
                                if (T==0)
                                {       Bc=getpixel(Tx,Ty);

                                        r1=Palette[Bc].rgbRed[0];
                                        g1=Palette[Bc].rgbGreen[0];
                                        b1=Palette[Bc].rgbBlue[0];

                                        r1 = ((Palette[Bc].rgbRed[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbRed[0]*(256-(C*256/255)))) / 256;
                                        g1 = ((Palette[Bc].rgbGreen[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbGreen[0]*(256-(C*256/255)))) / 256;
                                        b1 = ((Palette[Bc].rgbBlue[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbBlue[0]*(256-(C*256/255)))) / 256;

                                        Fc=colormatch(r1,g1,b1);
                                        putpixel(Tx,Ty,Fc);
                                }
                                else if (T==1)
                                { if (Fc!=C)
                                                putpixel(Tx,Ty,Fc);
                                }
                                else if (T==-1)
                                                putpixel(Tx,Ty,Fc);

                                Tx=XX+1;
                                Ty=YY;
                                if (A!=0)
                                {       Tx-=(Width/2+X);
                                        Ty=(Height/2+Y)-Ty;
                                        rotate(Tx,Ty,A);
                                        Tx+=Width/2+X;
                                        Ty=(Height/2+Y)-Ty;
                                }
                                Fc=splitbyte(Byte[0],SPLIT_LEFT);
                                if (T==0)
                                {       Bc=getpixel(Tx,Ty);

                                        r1=Palette[Bc].rgbRed[0];
                                        g1=Palette[Bc].rgbGreen[0];
                                        b1=Palette[Bc].rgbBlue[0];

                                        r1 = ((Palette[Bc].rgbRed[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbRed[0]*(256-(C*256/255)))) / 256;
                                        g1 = ((Palette[Bc].rgbGreen[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbGreen[0]*(256-(C*256/255)))) / 256;
                                        b1 = ((Palette[Bc].rgbBlue[0]*(C*256/255)) +
                                                         (Palette[Fc].rgbBlue[0]*(256-(C*256/255)))) / 256;

                                        Fc=colormatch(r1,g1,b1);
                                        putpixel(Tx,Ty,Fc);
                                }
                                else if (T==1)
                                { if (Fc!=C)
                                                putpixel(Tx,Ty,Fc);
                                }
                                else if (T==-1)
                                                putpixel(Tx,Ty,Fc);
                        }
                }
                else if (BPP==1)
                {       for (XX=X;XX<Width+X;XX+=8)
                        { //READ IN SINGLE BYTE AND CHECK EACH BIT TO SEE
                                //IF THE PIXEL IS FOREGROUND(1) OR BACKGROUND(0)
                                fread(Byte,sizeof(char),1,In);
                                for (I=0,M=7;I<8;I++,M--)
                                { Tx=XX+I;
                                        Ty=YY;
                                        if (A!=0)
                                        {       Tx+=Width/2+X;
                                                Ty=(Height/2+Y)-Ty;
                                                rotate(Tx,Ty,A);
                                        }
                                        putpixel(Tx,Ty,biton(Byte[0],M));
                                }
                        }
                }
                //READ EXTRA NULL BYTES INTO TRASH
                fread(RowNull,sizeof(char),RowWidth,In);
        }


        //RETURN SUCCESFUL
        return true;
};

/////////////////////////////////////////////////////////////////////////////
// END IMAGE MEMBER FUNCTIONS////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

bool image::biton(unsigned char Byte,int Bit)
{ //CHECK TO SEE WHETHER BIT, Bit IS ON USING
        //THE FACT THAT IF BIT b, IN BYTE, byte IS 1
        //THEN (byte|b)==byte
        if ((Byte|(int)(pow(2,Bit)))!=Byte)
                return false;
        return true;
}

/////////////////////////////////////////////////////////////////////////////

unsigned char image::splitbyte(unsigned char Byte,int LorR)
{
/*Integers
                LorR (passed in) = determines whether to return Right(8),
                                                                                         or Left(128) half of byte
                I,B,X = loop control variables
        Unsigned Characters
                Byte (passed in) = Byte to split
                rByte = return byte
*/

        int I,B,X;
        unsigned char rByte;

        //SPLIT BIT ACCORDING TO WHETHER LorR IS 128(L)
        //OR 8(R) USING THE FACT THAT IF BIT b, IN BYTE,
        //byte IS 1 THEN (byte|b)==byte
        rByte=0;
        for (I=0,B=LorR,X=120;I<4;I++,B/=2,X/=2)
        {       if ((Byte|B)==Byte && LorR==8)
                        rByte+=B;
                else if ((Byte|B)==Byte && LorR==128)
                        rByte+=B-X;
        }
        return rByte;
}

void image::rotate(int &X, int &Y, int a)
{
/*Static Variables
                Float
                        SLUT[361] = sin lookup table, calculated on first run through
                                                                        function to speed up rotation in later calls
                        CLUT[361] = cosine lookup table
                Bool
                        FirstTime = on first call, set to true, after first call set to
                                                                        false. prevents the tables from being built every time
        Integers
                angle = the angle used for calculating tables, 0 to 360 in a for loop
        Float
                rad = radian value for the angle, used in the cos() and sin() functions
                tx, ty = temporary x and y for calculating rotated value

        TAKES AN X AND Y AND ROTATES BY A USING A LOOKUP TABLE FOR FASTER
        COS AND SIN VALUES
*/

        static float SLUT[361], CLUT[361];
        static bool FirstTime = true;
        int angle;
        float rad,tx,ty;

        if (FirstTime)
        { for (angle=0;angle<=360;angle++)
                { rad=angle*0.0174532925199432957692369076848861;

                        CLUT[angle] = (float)cos(rad);
                        SLUT[angle] = (float)sin(rad);
                }
        }

        tx = X*(CLUT[a]) - Y*(SLUT[a]);
        ty = X*(SLUT[a]) + Y*(CLUT[a]);

        X=tx;
        Y=ty;

};

int image::colormatch(unsigned char r, unsigned char g, unsigned char b)
{
        int i, d, MD, Color;


        for (i=0; i<16; i++)
        { d = abs(int(Palette[i].rgbRed[0]-r)) +
                                abs(int(Palette[i].rgbGreen[0]-g)) +
                                abs(int(Palette[i].rgbBlue[0]-b));

                if (d < MD)
                {       MD=d;
                        Color=i;
                }
        }

        return Color;
}

void graphinit(int Mode)
{ int grdriver,grmode,errorcode;
        apstring Desc;

        closegraph();           // CLEAR OUT OTHER GRAPHICS MODES

        if (Mode==256)
        {       grdriver=installuserdriver("VGA256", DetectVGA256);
                grdriver=DETECT;
        }
        else if (Mode==16)
        {       grdriver=VGA;
                grmode=VGAHI;
        }

        initgraph(&grdriver, &grmode, "C:\\TC\\BGI");
        errorcode=graphresult();

        if (errorcode!=grOk)
        {       switch(errorcode)
                {       case grOk                                                         : Desc="NO ERROR";
                                                                                                                                break;
                        case grNoInitGraph      : Desc="(BGI) GRAPHICS NOT INSTALLED";
                                                                                                                                break;
                        case grNotDetected      : Desc="GRAPHICS HARDWARE NOT DETECTED";
                                                                                                                                break;
                        case grFileNotFound     : Desc="DEVICE DRIVER FILE NOT FOUND";
                                                                                                                                break;
                        case grInvalidDriver    : Desc="INVALID DEVICE DRIVER FILE";
                                                                                                                                break;
                        case grNoLoadMem        : Desc="NOT ENOUGH MEMORY TO LOAD DRIVER";
                                                                                                                                break;
                        case grNoScanMem        : Desc="OUT OF MEMORY IN SCAN FILL";
                                                                                                                                break;
                        case grNoFloodMem       : Desc="OUT OF MEMORY IN FLOOD FILL";
                                                                                                                                break;
                        case grFontNotFound     : Desc="FONT FILE NOT FOUND";
                                                                                                                                break;
                        case grNoFontMem        : Desc="NOT ENOUGH MEMORY TO LOAD FONT";
                                                                                                                                break;
                        case grInvalidMode      : Desc="INVALID GRAPHICS MODE FOR SELECTED DRIVER";
                                                                                                                                break;
                        case grError            : Desc="GRAPHICS ERROR";
                                                                                                                                break;
                        case grIOerror          : Desc="GRAPHICS I/O ERROR";
                                                                                                                                break;
                        case grInvalidFont      : Desc="INVALID FONT FILE";
                                                                                                                                break;
                        case grInvalidFontNum   : Desc="INVALID FONT NUMBER";
                                                                                                                                break;
                        case 15                 : Desc="INVALID DEVICE NUMBER";
                                                                                                                                break;
                        case grInvalidVersion   : Desc="INVALID VERSION NUMBER";
                                                                                                                                break;
                        default                 : Desc="UNKNOWN GRAPHICS ERROR";
                }

                if (GErrors.On)
                {       GErrors.Err.Description=Desc;
                        GErrors.Err.Source="graphinit";
                        GErrors.Err.Number=500+errorcode;
                }
                else
                        cout<<"||error graphinit -> "<<Desc<<"||";
        }
}


int huge DetectVGA256()
{ int DetectedDriver,SuggestedMode;

        detectgraph(&DetectedDriver, &SuggestedMode);

        if (DetectedDriver == VGA || DetectedDriver == MCGA)
                return 0;
        else
                return grError;

}


#endif