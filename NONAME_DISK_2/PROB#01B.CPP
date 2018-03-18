//Jeremy Higgins
//August 24, 2001
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
int A;
int B;
int C;
int D;
int E;
int F;
int G;
int H;
int I;
int J;
void main()
{
clrscr();
A=1;
B=2;
C=3;
D=4;
E=5;
F=6;
G=7;
H=8;
I=9;
J=10;
cout<<"1+1="<<A+A<<endl<<"2+3="<<B+C<<endl<<"3+4="<<C+D<<endl;
cout<<"4+5="<<D+E<<endl<<"5+6="<<E+F<<endl<<"6+7="<<F+G<<endl;
cout<<"7+8="<<G+H<<endl<<"8+9="<<H+I<<endl<<"9+10="<<I+J<<endl;
cout<<"10+1="<<J+A<<endl;
getch();
clrscr();
cout<<"10-9="<<J-I<<endl<<"9-8="<<I-H<<endl<<"8-7="<<H-G<<endl;
cout<<"7-6="<<G-F<<endl<<"6-5="<<F-E<<endl<<"5-4="<<E-D<<endl;
cout<<"4-3="<<D-C<<endl<<"3-2="<<C-B<<endl<<"2-1="<<B-A<<endl;
cout<<"1-1="<<A-A<<endl;
getch();
clrscr();
cout<<"1*1="<<A*A<<endl<<"1*2="<<A*B<<endl<<"2*3="<<B*C<<endl;
cout<<"3*4="<<C*D<<endl<<"4*5="<<D*E<<endl<<"5*6="<<E*F<<endl;
cout<<"6*7="<<F*G<<endl<<"7*8="<<G*H<<endl<<"8*9="<<H*I<<endl;
cout<<"9*10="<<I*J<<endl;
getch();
clrscr();
cout<<"10/1="<<J/A<<endl<<"10/2="<<J/B<<endl<<"10/5="<<J/E<<endl;
cout<<"9/3="<<I/C<<endl<<"8/2="<<H/B<<endl<<"8/4="<<H/D<<endl;
cout<<"4/2="<<D/B<<endl<<"4/4="<<D/D<<endl<<"5/1="<<E/A<<endl;
cout<<"3/1="<<C/A<<endl;
getch();
clrscr();
cout<<"10%9="<<J%I<<endl<<"10%8="<<J%H<<endl<<"10%7="<<J%G<<endl;
cout<<"10%6="<<J%F<<endl<<"10%4="<<J%D<<endl<<"10%3="<<J%C<<endl;
cout<<"9%8="<<I%H<<endl<<"9%7="<<I%G<<endl<<"9%5="<<I%E<<endl;
cout<<"9%4="<<I%D<<endl;
getch();
}
