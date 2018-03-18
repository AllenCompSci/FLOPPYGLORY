//Chris Chapman
//shell
//7th
//Mr. Baker

//Library Section
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const.section

//variable section
char Answer;
int Star;

void main ()
{
clrscr();

do{
Star=0;
 while (Star<6)
	{switch(Star)
	 {

	 case 4:cout<<"*******"<<endl;
	 case 6:cout<<" *****"<<endl;
						 break;
	 case 2:cout<<"  ***"<<endl;
						 break;
	 case 3:cout<<" *****"<<endl;
						 break;
	 case 5:cout<<"  ***"<<endl;
	 case 1:cout<<"   *"<<endl;
						 break;

	 }
Star++;
	}



	cout<<"Run agian? (Y/N)";
	cin>>Answer;
	}while(Answer=='Y'||Answer=='y');
}
