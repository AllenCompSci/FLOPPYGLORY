for(Word=0;Word<Num;Word++)
{
Direction=random(8)+1;



		switch (Direction)
{case 1 :do                   //forward horizontal
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y);
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;}
					 break;
case 2 :do                   //backwards horizontal
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y);
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy][Wx+Words[Word].length()-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;}
					break;
case 3 : do                   //forward vertical
				 {
				 Empty=0;
				 Wx=random(Y);
				 Wy=1;//random(X-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy+=1;}
					 break;
case 4 : do                   //backwards vertical
				 {
				 Empty=0;
				 Wx=random(Y);
				 Wy=random(X-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wy=Wy-1;}
					 break;

case 5 : do                   //forward \
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy++;}
					 break;
case 6 : do                   //backward \
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy=Wy-1;}
					 break;
case 7 : do                   //forward /
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length());
				 Wy=random(Y-Words[Word].length())+Words[Word].length();
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy-Q][Wx+Q]==true)
						 Empty++;
				 }while(Empty>0);

				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx++;
					 Wy=Wy-1;}
					 break;
case 8 : do                   //backward /
				 {
				 Empty=0;
				 Wx=random(X-Words[Word].length())+Words[Word].length();
				 Wy=random(Y-Words[Word].length());
				 for(Q=0;Q<Words[Word].length();Q++)
						if(Id[Wy+Q][Wx-Q]==true)
						 Empty++;
				 }while(Empty>0);


				 for(I=0;I<Words[Word].length();I++)
					{Screen[Wy][Wx]=Words[Word][I];
					 Id[Wy][Wx]=true;
					 Wx=Wx-1;
					 Wy++;}
				 break;}
}
