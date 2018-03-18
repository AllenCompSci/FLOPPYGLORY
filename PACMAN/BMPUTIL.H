#ifndef __BMPUTIL_H
#define __BMPUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <iostream.h>
#include <conio.h>
#include <apstring.h>
#include <fstream.h>
#include <apvector.h>
#include <apmatrix.h>
#include <graphics.h>
#include <dos.h>
#include <alloc.h>
#include <string.h>


void gr_start(void);

const long int MAX_BM_SIZE = 1024*2;

struct BitmapHeader {
	unsigned char bfType[2];
	unsigned char bfSize[4];
	unsigned char bfReserved1[2];
	unsigned char bfReserved2[2];
	unsigned char bfOffBits[4];

	unsigned char biSize[4];
	unsigned char biWidth[4];
	unsigned char biHeight[4];
	unsigned char biPlanes[2];
	unsigned char biBitCount[2];
	unsigned char biCompression[4];
	unsigned char biSizeImage[4];
	unsigned char biXPelsPerMeter[4];
	unsigned char biYPelsPerMeter[4];
	unsigned char biClrUsed[4];
	unsigned char biClrImportant[4];
};

struct RGBQuad {
	unsigned char rgbBlue;
	unsigned char rgbGreen;
	unsigned char rgbRed;
	unsigned char rgbReserved;
};


class Bitmap {
	private:
		BitmapHeader header;
		RGBQuad *rgbqList;
		unsigned char far *bits;
		char *filename;
	public:
		void Read(apstring &, bool=true);
		void SetPalette(void);
		void Draw(int, int);
		void PrintHeader(void);
		void Close(void);
};

void Bitmap::Read(apstring &fname, bool SaveBM) {
	FILE *fp;
	int max_colors, num_colors;
	long int xsize, ysize, xsize2;
	int i;
	long int x, y;
	unsigned char tempc;

	long int max_bits_index;
	long int bits_index;

	// store filename for later use
	filename = new char[fname.length()+1];
	strcpy (filename,fname.c_str());

	if ((fp = fopen(filename,"rb")) == NULL) {
		fprintf(stderr,"Error opening file %s\n",filename);
		exit(1);
	}


	fread(&header, sizeof(BitmapHeader), 1, fp);
	switch (*(short *)header.biBitCount) {
		case 1:
			max_colors = 2;
			break;
		case 4:
			max_colors = 16;
			break;
		case 8:
			max_colors = 256;
			break;
		case 24:  // true color
			max_colors = -1;
			break;
		default:
			fprintf(stderr,"Invalid bits per pixel: %d\n",
					*(short *)header.biBitCount);
			exit(1);
	}
	if (*(long *)header.biClrUsed == 0) {
		num_colors = max_colors;
		*(long *)header.biClrUsed = num_colors;
	}
	else {
		num_colors = *(long *)header.biClrUsed;
	}

	if (max_colors > 0) {
		// allocate space for palette
		if ((rgbqList = new RGBQuad[num_colors])
				== NULL) {
			fclose(fp);
			fprintf(stderr,
			  "Error allocating memory for rgbqList for file %s\n",
				filename);
			exit(1);
		}
		// Read rgbqList
		for (i=0; i<num_colors; i++)
		{
			fread(rgbqList+i, sizeof(RGBQuad), 1, fp);
		}
	}

		bits = NULL;
		if (SaveBM && *(long int *)header.biSizeImage < MAX_BM_SIZE) // if bm small, save in memory
		{


	// allocate space for bitmap (one byte per pixel)
	xsize = *(unsigned long *)header.biWidth;
	ysize = *(unsigned long *)header.biHeight;
	max_bits_index = xsize*ysize-1;
	if ((bits = new unsigned char far[max_bits_index+1]) == NULL)
	{
		fclose(fp);
		fprintf(stderr,
		  "Error allocating memory for bitmap for file %s\n",
		  filename);
		exit(1);
	}

	switch (*(short *)header.biBitCount) {
		case 1:
			fprintf(stderr,"1 bit color not implemented yet\n");
			break;
		case 4:
			xsize2 = xsize/2;
			for (y = (ysize-1); y>=0; y--)
			{
				for (x=0; x<xsize2; x++)
				{
					tempc = fgetc(fp);
					bits_index = y*xsize + 2*x;
					if (bits_index > max_bits_index)
					{
						fprintf(stderr,"bits index %ld is bigger than max index %ld\n",
								bits_index, max_bits_index);
						exit(1);
					}
					bits[bits_index] = tempc/16;
					bits[bits_index+1] = tempc & 0xF;
				}
				if (xsize%2 != 0)
				{
					tempc = fgetc(fp);
					*(bits+y*xsize+2*x) = tempc/16;

				}
				if ((xsize2+xsize%2)%4 != 0)  // read to 32bit boundry
				{
					for (x=(xsize2+xsize%2)%4; x<4; x++)
					{
						fgetc(fp);
					}
				}
			}
			break;
		case 8:
			for (y = (ysize-1); y>=0; y--)
			{
				for (x=0; x<xsize; x++)
				{
					*(bits+y*xsize+x) = fgetc(fp);
				}
				if (xsize%4 != 0)  // read to 32bit boundry
				{
					for (x=xsize%4; x<4; x++)
					{
						fgetc(fp);
					}
				}
			}
			break;
		case 24:  // true color
			fprintf(stderr,"24 bit color not implemented yet\n");
			exit(1);
			break;
		default:
			fprintf(stderr,"Invalid bits per pixel: %d\n",
					*(short *)header.biBitCount);
			exit(1);
	}
    }

	fclose(fp);

}

void Bitmap::SetPalette(void)
{
	const double CC=63.0/255.0;
	int i, num_colors;
	palettetype CurPalette;

	getpalette(&CurPalette);

	num_colors = *(long *)header.biClrUsed;
	
	for (i=0; i<num_colors; i++)
	{
		setrgbpalette(CurPalette.colors[i],
				(int)rgbqList[i].rgbRed*CC,
				(int)rgbqList[i].rgbGreen*CC,
				(int)rgbqList[i].rgbBlue*CC);
	}

	
}



void Bitmap::Draw(int x0, int y0)
{
	FILE *fp;
	long int i, j;
	long int xsize, ysize, xsize2;
	long int x, y;
	unsigned char tempc;
	xsize = *(unsigned long *)header.biWidth;
	ysize = *(unsigned long *)header.biHeight;

	if (bits && *(long int *)header.biSizeImage < MAX_BM_SIZE) // if bm small, draw from memory
	{
		for (i=0; i<xsize; i++)
		{
			for (j=0; j<ysize; j++)
			{
				putpixel(x0+i, y0+j, *((unsigned char *)bits+i+j*xsize));
			}
		}
	}
	else // read and draw it from the file 
	{
		if ((fp = fopen(filename,"rb")) == NULL) 
		{
			fprintf(stderr,"Error opening file %s for draw\n",filename);
			exit(1);
		}
		fseek(fp, *(long int *)header.bfOffBits, SEEK_SET);

		switch (*(short *)header.biBitCount) {
			case 1:
				fprintf(stderr,"1 bit color not implemented yet\n");
				break;
			case 4:
				xsize2 = xsize/2;
				for (y = (ysize-1); y>=0; y--)
				{
					for (x=0; x<xsize2; x++)
					{
						tempc = fgetc(fp);
						putpixel(x0+2*x, y0+y, tempc/16);
						putpixel(x0+2*x+1, y0+y, tempc & 0xF);
					}
					if (xsize%2 != 0)
					{
						tempc = fgetc(fp);
						putpixel(x0+2*x, y0+y, tempc/16);
	
					}
					if ((xsize2+xsize%2)%4 != 0)  // read to 32bit boundry
					{
						for (x=(xsize2+xsize%2)%4; x<4; x++)
						{
							fgetc(fp);
						}
					}
				}
				break;
			case 8:
				for (y = (ysize-1); y>=0; y--)
				{
					for (x=0; x<xsize; x++)
					{
						putpixel(x0+x, y0+y, fgetc(fp));
					}
					if (xsize%4 != 0)  // read to 32bit boundry
					{
						for (x=xsize%4; x<4; x++)
						{
							fgetc(fp);
						}
					}
				}
				break;
			case 24:  // true color
				fprintf(stderr,"24 bit color not implemented yet\n");
				exit(1);
				break;
			default:
				fprintf(stderr,"Invalid bits per pixel: %d\n",
						*(short *)header.biBitCount);
				exit(1);
		}
		fclose(fp);
	}
}

void Bitmap::PrintHeader(void)
{
	fprintf(stderr,"bfType: %c%c\n",header.bfType[0],header.bfType[1]);
	fprintf(stderr,"bfSize: %ld\n",*(unsigned long *)header.bfSize);
	fprintf(stderr,"bfOffBits: %ld\n",*(unsigned long *)header.bfOffBits);

	fprintf(stderr,"biSize: %ld\n",*(unsigned long *)header.biSize);
	fprintf(stderr,"biWidth: %ld\n",*(unsigned long *)header.biWidth);
	fprintf(stderr,"biHeight: %ld\n",*(unsigned long *)header.biHeight);
	fprintf(stderr,"biPlanes: %d\n",*(unsigned short *)header.biPlanes);
	fprintf(stderr,"biBitCount: %d\n",*(unsigned short *)header.biBitCount);
	fprintf(stderr,"biCompression: %ld\n",*(unsigned long *)header.biCompression);
	fprintf(stderr,"biSizeImage: %ld\n",*(unsigned long *)header.biSizeImage);
	fprintf(stderr,"biXPelsPerMeter: %ld\n",*(unsigned long *)header.biXPelsPerMeter);
	fprintf(stderr,"biYPelsPerMeter: %ld\n",*(unsigned long *)header.biYPelsPerMeter);
	fprintf(stderr,"biClrUsed: %ld\n",*(unsigned long *)header.biClrUsed);
	fprintf(stderr,"biClrImportant: %ld\n",*(unsigned long *)header.biClrImportant);
}

void Bitmap::Close(void)
{
//	farfree(palette);
//	farfree(bits);
	delete [] rgbqList;
	if (bits) delete [] bits;
	delete [] filename;
}

#ifdef __TEST_BMPUTIL

void main(void)
{
	Bitmap zot[100];
	int i;

	clrscr();

	for (i=0; i<30; i++)
	{
		zot[i].Read("c:\\users\\rachel\\turbo_c\\pacproj\\yuckbm\\cross.bmp");
//		zot[i].Read("c:\\users\\rachel\\turbo_c\\pacproj\\yuckbm\\medium.bmp");

//		zot[i].Read("c:\\pacman2.bmp");
//		zot[i].Read("c:\\users\\rachel\\turbo_c\\pacproj\\yuckbm\\keys.bmp");
		fprintf(stderr,"Finished bitmap read %d\n",i);
//		getch();
	}
	i--;

	zot[i].PrintHeader();
	getch();

//	exit(0);

	gr_start();
	cleardevice();
	getch();
	zot[i].SetPalette();
	zot[i].Draw(0,0);
	getch();

//	zot.Close();
	exit(0);
}



void gr_start(void)
{
int grdriver, grmode, errorcode;
	grdriver = VGA;
	grmode = VGAHI;

	initgraph(&grdriver, &grmode, "C:\\TC\\BGI");

	errorcode = graphresult();

	if(errorcode!=grOk)
		{
		clrscr();
		cout << "ERROR: " << errorcode << endl;
		cout << "Press return to continue." << endl;
		getch();
		exit(1);
		}



};

#endif  // def __TEST_BMPUTIL
#endif  // def __BMPUTIL_H
