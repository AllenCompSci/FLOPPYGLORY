/****************************************/
/*										*/
/*		BGI SVGA Defines and Utils		*/
/*		Copyright (c) 1994				*/
/*		Jordan Hargraphix Software		*/
/*										*/
/*   Compiled, cleaned and extended by  */
/*		Ryan Bunker						*/
/*										*/
/****************************************/

#ifndef __SVGA_H__
#define __SVGA_H__

#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <string.h>

#define SVGA16  830
#define SVGA256	831
#define SVGA32K 832
#define SVGA64K 833
#define SVGATC  834
#define SVGAS3  835
#define TWK256  836
#define TWK16   837
#define grInvalidDriverNum -19
#define	XNOR_PUT	5
#define NOR_PUT		6
#define NAND_PUT	7
#define TRANS_COPY_PUT	8	/* Doesn't work with 16-color drivers */

const int drivers[8] = {7, 7, 7, 7, 7, 8, 7, 7};
const char *driver_names[8] = {"Svga16", "Svga256", "Svga32k",
															 "Svga64k", "SvgaTC", "SvgaS3",
															 "Twk256", "Twk16"};

#pragma pack(1)

typedef unsigned char BYTE;
typedef unsigned long ULONG;
typedef unsigned int UINT;

typedef struct bpp24_s
{
	BYTE bVal;
	BYTE gVal;
	BYTE rVal;
} bpp24_t;

typedef struct bpp16_s
{
	UINT rVal : 5;
	UINT gVal : 6;
	UINT bVal : 5;
} bpp16_t;

typedef struct bpp15_s
{
	UINT rVal : 5;
	UINT gVal : 5;
	UINT bVal : 5;
} bpp15_t;

typedef union
{
	struct bpp24_s c24;
	struct bpp16_s c16;
	struct bpp15_s c15;
	unsigned long  cval;
} rColor_u;

typedef struct rgb_s
{
	BYTE r;
	BYTE g;
	BYTE b;
} rgb_t;

typedef struct VBE_VgaInfo
{
	char VESASignature[4];
	short VESAVersion;
	char *OemStringPtr;
	unsigned long Capabilities;
	unsigned long VideoModePtr;
	short TotalMemory;
	//VBE 2.0
	short OemSoftwareRev;
	char *OemVendorNamePtr;
	char *OemProductNamePtr;
	char *OemProductRevPtr;
	char reserved[222];
	char OemData[256];
};

typedef struct VBE_ModeInfo
{
	short ModeAttributes;
	char WinAAttributes;
	char WinBAttributes;
	short WinGranularity;
	short WinSize;
	unsigned short WinASegment;
	unsigned short WinBSegment;
	void *WinFuncPtr;
	short BytesPerScanLine;
	short XRes;
	short YRes;
	char XCharSize;
	char YCharSize;
	char NumberOfPlanes;
	char BitsPerPixel;
	char NumberOfBanks;
	char MemoryModel;
	char BankSize;
	char NumberOfImagePages;
	char res1;
	char RedMaskSize;
	char RedFieldPosition;
	char GreenMaskSize;
	char GreenFieldPosition;
	char BlueMaskSize;
	char BlueFieldPosition;
	char RsvedMaskSize;
	char RsvedFieldPosition;
	char DirectColorModeInfo; //MISSED IN THIS TUTORIAL!! SEE ABOVE
	//VBE 2.0
	unsigned long PhysBasePtr;
	unsigned long OffScreenMemOffset;
	short OffScreenMemSize;
	//VBE 2.1
	short LinbytesPerScanLine;
	char BankNumberOfImagePages;
	char LinNumberOfImagePages;
	char LinRedMaskSize;
	char LinRedFieldPosition;
	char LingreenMaskSize;
	char LinGreenFieldPosition;
	char LinBlueMaskSize;
	char LinBlueFieldPosition;
	char LinRsvdMaskSize;
	char LinRsvdFieldPosition;
	char res2[194];
};

#pragma pack()

#ifdef __cplusplus
	extern "C" {
#endif

typedef rgb_t RGBPalette[256];
typedef rgb_t RGBPalette16[16];

/* Define enhanced color setting functions */
long RGB(BYTE,BYTE,BYTE);
long RealDrawColor(long);
long RealFillColor(long);
long RealColor(long);

/* VESA Detection and Mode Info functions */
int DetectVESA();
int GetVESAModeInfo(short mode);
short GetVESAMode();
int GetCurrentVESAModeInfo();

/* BANK Switching functions */
int SetBankBIOS(short bank);
short GetCurrentBank();

/* Define global graphic variables */
int GraphDriver, GraphMode;
VBE_VgaInfo g_vesainfo;
VBE_ModeInfo g_modeinfo;
short CurBank = 0;

/* Video RAM pointer (A000:0000h) */
BYTE *vram = (BYTE *)MK_FP(0xA000, 0);

#ifdef __cplusplus
	};
#endif

/********************************************************/
/* int huge DetectAny();   															*/
/*					   																					*/
/* Purpose: autodetect function for installuserdriver() */
/*																											*/
/* Input:																								*/
/*	None																								*/
/*																											*/
/* Returns:																							*/
/* 	int - mode number to use with current driver				*/
/*																											*/
/********************************************************/
int huge DetectAny()
{
	return 0;
};

/********************************************************/
/* char gr_init(int GD, int GM, char *path);						*/
/*					   																					*/
/* Purpose: to initialize graphics mode 								*/
/*																											*/
/* Input:																								*/
/*	long GD - driver number, use named defines					*/
/*	int GM - mode number for driver											*/
/*	char *path - path to BGI files, if null looks in		*/
/*							 current directory first								*/
/*																											*/
/* Returns:																							*/
/* 	char - error message from initgraph() and						*/
/*				 graphresult()																*/
/*																											*/
/********************************************************/
char gr_init(int GD, int GM, char *path)
{
	GD -= 830;
	if ((GD < 0) || (GD > 7))
		return grInvalidDriver;

	if ((GM < 0) || (GM > drivers[GD]))
		return grInvalidMode;

	GraphDriver = installuserdriver(driver_names[GD], DetectAny);
	GraphMode   = GM;
	initgraph(&GraphDriver, &GraphMode, (char far *)path);

	return graphresult();
};

/********************************************************/
/* long RGB(char rVal, char gVal, char bVal);
/*
/* Purpose: Returns the color value for a R,G,B triple
/*	based on the current graphics mode.
/*
/* Input:
/*	char rVal - Red value   [0..255]
/*	char gVal - Green value [0..255]
/*	char bVal - Blue value  [0..255]
/*
/* Returns:
/* 	long - Color value for this mode.
/*
/********************************************************/
long RGB(BYTE rVal, BYTE gVal, BYTE bVal)
{
	rColor_u xColor;

	switch(getmaxcolor())
	{
		case 32767:
			xColor.c15.rVal = (rVal >> 3) & 0x1F;
			xColor.c15.gVal = (gVal >> 3) & 0x1F;
			xColor.c15.bVal = (bVal >> 3) & 0x1F;
			break;
		case 65535:
			xColor.c16.rVal = (rVal >> 3) & 0x1F;
			xColor.c16.gVal = (gVal >> 2) & 0x3F;
			xColor.c16.bVal = (bVal >> 3) & 0x1F;
			break;
		case 16777:
			xColor.c24.rVal = rVal;
			xColor.c24.gVal = gVal;
			xColor.c24.bVal = bVal;
			break;
		}
		return (xColor.cval);
}

/****************************************************************/
/* long RealDrawColor(long color);
/*
/* Purpose: Sets the current drawing color for HC/TC modes.
/*	Used for 'setcolor'
/*
/* Input:
/*	long color - Color value
/*
/* Returns:
/*	long - Color value
/*
/****************************************************************/
long RealDrawColor(long color)
{
	rColor_u xColor;

	xColor.cval = color;
	/* Do color set hacks for hicolor/truecolor modes */
	switch(getmaxcolor())
	{
		case 32767:
			setrgbpalette(1024,xColor.c15.rVal,xColor.c15.gVal,xColor.c15.bVal);
			break;
		case 65535:
			setrgbpalette(1024,xColor.c16.rVal,xColor.c16.gVal,xColor.c16.bVal);
			break;
		case 16777:
			setrgbpalette(1024,xColor.c24.rVal,xColor.c24.gVal,xColor.c24.bVal);
			break;
	};

	return color;
}

/****************************************************************/
/* long RealFillColor(long color);
/*
/* Purpose: Sets the current fill color for HC/TC modes.
/*	Used for 'setfillstyle' and 'setfillpattern'
/*
/* Input:
/*	long color - Color value
/*
/* Returns:
/*	long - Color value
/*
/****************************************************************/
long RealFillColor(long color)
{
		rColor_u xColor;

		xColor.cval = color;
		/* Do color set hacks for hicolor/truecolor modes */
		switch(getmaxcolor())
	{
		case 32767:
		setrgbpalette(1025,xColor.c15.rVal,xColor.c15.gVal,xColor.c15.bVal);
		break;
		case 65535:
		setrgbpalette(1025,xColor.c16.rVal,xColor.c16.gVal,xColor.c16.bVal);
		break;
	case 16777:
		setrgbpalette(1025,xColor.c24.rVal,xColor.c24.gVal,xColor.c24.bVal);
		break;
		};

		return color;
}

/****************************************************************/
/* long RealColor(long color);			  						*/
/* 							  									*/
/* Purpose: Sets the current color for HC/TC modes.				*/
/*	Used for 'putpixel' and 'floodfill'							*/
/*																*/
/* Input:														*/
/*	long color - Color value									*/
/*																*/
/* Returns:														*/
/*	long - Color value											*/
/*																*/
/****************************************************************/
long RealColor(long color)
{
		rColor_u xColor;

		xColor.cval = color;
		/* Do color set hacks for hicolor/truecolor modes */
    switch(getmaxcolor())
	{
		case 32767:
		setrgbpalette(1026,xColor.c15.rVal,xColor.c15.gVal,xColor.c15.bVal);
		break;
		case 65535:
		setrgbpalette(1026,xColor.c16.rVal,xColor.c16.gVal,xColor.c16.bVal);
		break;
		case 16777:
		setrgbpalette(1026,xColor.c24.rVal,xColor.c24.gVal,xColor.c24.bVal);
		break;
		};

		return color;
}

/***********************************************************************/
/* RGB Color setting functions                                         */
/* void setcolor(char rVal, char gVal, char bVal);      						   */
/* void setfillstyle(int pattern, char rVal, char gVal, char bVal);    */
/* void setfillpattern(char far *upattern, char rVal, char gVal,       */
/*                        char bVal);                                  */
/* void putpixel(int x, int y, char rVal, char gVal, char bVal);       */
/* void floodfill(int x, int y, char rVal, char gVal, char bVal);      */
/*                                                                     */
/* Purpose: sets the drawing color (for paletteless     						   */
/*          video modes)                                						   */
/*                                                      						   */
/* Input:                                               						   */
/*	char rVal - Red value   [0..255]		                						   */
/*	char gVal - Green value [0..255]		                						   */
/*	char bVal - Blue value  [0..255]		                						   */
/*                                                      						   */
/***********************************************************************/
void setcolor(char rVal, char gVal, char bVal)
{
	setcolor(RealDrawColor(RGB(rVal, gVal, bVal)));
}

void setfillstyle(int pattern, char rVal, char gVal, char bVal)
{
	setfillstyle(pattern, RealFillColor(RGB(rVal, gVal, bVal)));
}

void setfillpattern(char far *upattern, char rVal, char gVal, char bVal)
{
	setfillpattern(upattern, RealFillColor(RGB(rVal, gVal, bVal)));
}

void putpixel(int x, int y, char rVal, char gVal, char bVal)
{
	putpixel(x, y, RealColor(RGB(rVal, gVal, bVal)));
}

void floodfill(int x, int y, char rVal, char gVal, char bVal)
{
	floodfill(x, y, RealColor(RGB(rVal, gVal, bVal)));
}

rgb_t ConvertToStdRGB(rColor_u c)
{
	rgb_t rgb;

	switch(getmaxcolor())
	{
		case 32767:
			rgb.r = c.c15.rVal;
			rgb.g = c.c15.gVal;
			rgb.b = c.c15.bVal;
			break;
		case 65535:
			rgb.r = c.c16.rVal;
			rgb.g = c.c16.gVal;
			rgb.b = c.c16.bVal;
			break;
		case 16777:
			rgb.r = c.c24.rVal;
			rgb.g = c.c24.gVal;
			rgb.b = c.c24.bVal;
			break;
	};

	return rgb;
}

rgb_t getpixelRGB(int x, int y)
{
	rColor_u c;

	c.cval = getpixel(x, y);
	c.cval = _DX;

	return ConvertToStdRGB(c);
}

void setpalcolor(int index, char rVal, char gVal, char bVal)
{
	//if ((index < 0) || (index > getmaxcolor()))
	//	return;

	outp(0x3C8, index);
	outp(0x3C9, rVal);
	outp(0x3C9, gVal);
	outp(0x3C9, bVal);
}

rgb_t getpalcolor(int index)
{
	rgb_t rgb;

	outp(0x3C7, index);

	rgb.r = (char) inp(0x3C9);
	rgb.g = (char) inp(0x3C9);
	rgb.b = (char) inp(0x3C9);

	return rgb;
}

void setpal(rgb_t *pal)
{
	int i;
	for (i=0; i<=getmaxcolor(); i++)
		setpalcolor(i, pal[i].r, pal[i].g, pal[i].b);
}

void getpal16(rgb_t *pal)
{
	int i;
	for (i=0; i<16; i++)
		pal[i] = getpalcolor(i);
}

void getpal(rgb_t *pal)
{
	int i;
	for (i=0; i<getmaxcolor(); i++)
		pal[i] = getpalcolor(i);
}

//********************************************************
// int DetectVESA()
//					   						
// Purpose: to detect if VESA is present and then fill a
//			VBE_VgaInfo structure with the current video
//			card's capabilities
//											
// Input: none			
//													
// Returns:	0 (false) VESA Detection Failed
//			1 (true)  VESA Detection succesful, struct filled										
//													
//********************************************************
int DetectVESA()
{
	BYTE ahr;
	UINT fp_seg, fp_off;

	strncpy(g_vesainfo.VESASignature, "VESA", 4);
	fp_seg = FP_SEG(&g_vesainfo);
	fp_off = FP_OFF(&g_vesainfo);

	asm mov AX, 0x4F00;
	asm mov DI, fp_off;
	asm mov ES, fp_seg;
	asm int 0x10;
	asm mov ahr, AH;

	if (ahr ||
			strncmp("VESA", g_vesainfo.VESASignature, 4) ||
			g_vesainfo.VESAVersion < 0x100)
		return 0;

	return 1;
}

//********************************************************
// int GetVESAModeInfo(short mode)
//			   						
// Purpose: fills g_modeinfo with the information
//			about mode
//
// Input: short mode - the mode to retrieve a struct for
//											
// Returns: 0 (false) Failed, struct not filled
//			1 (true)  Succesful, struct filled
//
//********************************************************
int GetVESAModeInfo(short mode)
{
	BYTE axr[2];
	UINT fp_seg, fp_off;

	fp_off = FP_OFF(&g_modeinfo);
	fp_seg = FP_SEG(&g_modeinfo);

	asm mov AX, 0x4F01;
	asm mov CX, mode;
	asm mov DI, fp_off;
	asm mov ES, fp_seg;
	asm int 0x10;
	asm mov axr, AX;

	if (axr[1] == 0x01 || axr[0] != 0x4F)
		return 0;

	return 1;
}

//********************************************************
// short GetVESAMode()
//			   						
// Purpose: returns the current graphics mode
//
// Input: none
//											
// Returns: -1		Failed
//			Other	Succesful, returns mode number 
//
//********************************************************
short GetVESAMode()
{
	BYTE axr[2];
	short bxr;

	asm mov AX, 0x4F03;
	asm int 0x10;
	asm mov axr, AX;
	asm mov bxr, BX;

	if (axr[1] == 0x01 || axr[0] != 0x4F)
		return -1;

	return bxr;
}

//********************************************************
// int GetCurrentVESAModeInfo()
//			   						
// Purpose: calls GetVESAModeInfo() with current graphics
//			mode
//
// Input: none
//											
// Returns: 0 (false) Failed
//			1 (true)  Successful
//
// g_modeinfo will contain the information about the current
// graphics mode if call successful
//
//********************************************************
int GetCurrentVESAModeInfo()
{
	return GetVESAModeInfo(GetVESAMode());
}

//********************************************************
// int SetBankBIOS(short bank)
//			   						
// Purpose: makes a BIOS call to switch to the specified bank
//
// Input: short bank - bank to switch to
//											
// Returns: 0 (false) Failed
//			1 (true) Successful
//
//********************************************************
int SetBankBIOS(short bank)
{
	BYTE axr[2];
	short oldBank;

	oldBank = CurBank;
	CurBank = bank;
	bank <<= g_modeinfo.WinGranularity;

	asm mov AX, 0x4F05;
	asm xor BX, BX;
	asm mov DX, bank;
	asm int 0x10;
	asm mov axr, AX;

	if (axr[1] == 0x01 || axr[0] != 0x4F)
	{
		CurBank = oldBank;
		return 0;
	}

	return 1;
}

//********************************************************
// short GetCurrentBank()
//			   						
// Purpose: returns the current bank number
//
// Input: none
//											
// Returns: short - current bank number
//
//********************************************************
short GetCurrentBank()
{
    return CurBank;
}

#endif