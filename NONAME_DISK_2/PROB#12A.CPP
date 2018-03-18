//Jeremy Higgins
//Due Date
//Mr. Baker
//Block 1
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<apstring.h>
//const
//var
int Option;
char Choice;
void main()
{clrscr();
do{
	 Option=1;
	 while(Option<8)
	 {switch (Option)
		{
		 case 1:cout<<"      *"<<endl;
		 break;
		 case 2:cout<<"    * * *"<<endl;
		 break;
		 case 3:cout<<"  * * * * *"<<endl;
		 break;
		 case 4:cout<<"* * * * * * *"<<endl;
		 break;
		 case 5:cout<<"  * * * * *"<<endl;
		 break;
		 case 6:cout<<"    * * *"<<endl;
		 break;
		 case 7:cout<<"      *"<<endl;
		}
		Option++;
	 }
	 cout<<"Do you want to run the program again y/n";
	 cin>>Choice;
	}while(Choice=='y' || Choice=='Y');
}
