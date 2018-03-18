Program sheep_o_doom;
(*El CHoDA  and Mellisa
Baker 6th, *)
uses
    crt,graph;
type
beefaroni=array [1..15,1..11] of integer;
super=array[1..4] of integer;
var
hambergur:beefaroni;
choda1,choda2,choda3,choda4:super;
ABBA,BAAB,{convert pixels to array}k,(*hit counter*)push,a,b,c,d,
(*user box movement*)a1,b1,c1,d1:integer;(*random box movement*)
speed,(*sheep speed*)x,stu,pid,(*size*)grdriver,grmode,grerror(*graphics*):integer;
m,e,f,{title page}dork,{array driver}ray:integer;(*to keep movement*)
score,(*keeps score*)g,stop,(*stopping variable*)san,frisco,error_postion:integer;
{convert pixels to array}abbar,baabr:real;
du,mb(*size*),mellisa:string;
y,z(*key press*),happy:char;
  procedure setup (var hambergur:beefaroni);{creates grid for storing pebbles}
  begin
  {power=1
  pebble=2
  pman=3
  sheep=4
  nothing=0}
  hambergur[1,1]:=1;
  hambergur[1,11]:=1;
  hambergur[15,1]:=1;
  hambergur[15,11]:=1;
  hambergur[2,1]:=2;
  hambergur[3,1]:=2;
  hambergur[4,1]:=2;
  hambergur[5,1]:=2;
  hambergur[6,1]:=2;
  hambergur[7,1]:=2;
  hambergur[8,1]:=2;
  hambergur[9,1]:=2;
  hambergur[10,1]:=2;
  hambergur[11,1]:=2;
  hambergur[12,1]:=2;
  hambergur[13,1]:=2;
  hambergur[14,1]:=2;
  hambergur[1,2]:=2;
  hambergur[2,2]:=2;
  hambergur[3,2]:=2;
  hambergur[4,2]:=2;
  hambergur[5,2]:=2;
  hambergur[6,2]:=2;
  hambergur[7,2]:=2;
  hambergur[8,2]:=2;
  hambergur[9,2]:=2;
  hambergur[10,2]:=2;
  hambergur[11,2]:=2;
  hambergur[12,2]:=2;
  hambergur[13,2]:=2;
  hambergur[14,2]:=2;
  hambergur[15,2]:=2;
  hambergur[1,3]:=2;
  hambergur[2,3]:=2;
  hambergur[3,3]:=2;
  hambergur[4,3]:=2;
  hambergur[5,3]:=2;
  hambergur[6,3]:=2;
  hambergur[7,3]:=2;
  hambergur[8,3]:=2;
  hambergur[9,3]:=2;
  hambergur[10,3]:=2;
  hambergur[11,3]:=2;
  hambergur[12,3]:=2;
  hambergur[13,3]:=2;
  hambergur[14,3]:=2;
  hambergur[15,3]:=2;
  hambergur[1,4]:=2;
  hambergur[2,4]:=2;
  hambergur[3,4]:=2;
  hambergur[4,4]:=2;
  hambergur[5,4]:=2;
  hambergur[6,4]:=2;
  hambergur[7,4]:=2;
  hambergur[8,4]:=2;
  hambergur[9,4]:=2;
  hambergur[10,4]:=2;
  hambergur[11,4]:=2;
  hambergur[12,4]:=2;
  hambergur[13,4]:=2;
  hambergur[14,4]:=2;
  hambergur[15,4]:=2;
  hambergur[1,5]:=2;
  hambergur[2,5]:=2;
  hambergur[3,5]:=2;
  hambergur[4,5]:=2;
  hambergur[5,5]:=2;
  hambergur[6,5]:=2;
  hambergur[7,5]:=2;
  hambergur[8,5]:=2;
  hambergur[9,5]:=2;
  hambergur[10,5]:=2;
  hambergur[11,5]:=2;
  hambergur[12,5]:=2;
  hambergur[13,5]:=2;
  hambergur[14,5]:=2;
  hambergur[15,5]:=2;
  hambergur[1,6]:=2;
  hambergur[2,6]:=2;
  hambergur[3,6]:=2;
  hambergur[4,6]:=2;
  hambergur[5,6]:=2;
  hambergur[6,6]:=2;
  hambergur[7,6]:=2;
  hambergur[8,6]:=2;
  hambergur[9,6]:=2;
  hambergur[10,6]:=2;
  hambergur[11,6]:=2;
  hambergur[12,6]:=2;
  hambergur[13,6]:=2;
  hambergur[14,6]:=2;
  hambergur[15,6]:=2;
  hambergur[1,7]:=2;
  hambergur[2,7]:=2;
  hambergur[3,7]:=2;
  hambergur[4,7]:=2;
  hambergur[5,7]:=2;
  hambergur[6,7]:=2;
  hambergur[7,7]:=4;
  hambergur[8,7]:=2;
  hambergur[9,7]:=2;
  hambergur[10,7]:=2;
  hambergur[11,7]:=2;
  hambergur[12,7]:=2;
  hambergur[13,7]:=2;
  hambergur[14,7]:=2;
  hambergur[15,7]:=2;
  hambergur[1,8]:=2;
  hambergur[2,8]:=2;
  hambergur[3,8]:=2;
  hambergur[4,8]:=2;
  hambergur[5,8]:=2;
  hambergur[6,8]:=2;
  hambergur[7,8]:=2;
  hambergur[8,8]:=3;
  hambergur[9,8]:=2;
  hambergur[10,8]:=2;
  hambergur[11,8]:=2;
  hambergur[12,8]:=2;
  hambergur[13,8]:=2;
  hambergur[14,8]:=2;
  hambergur[15,8]:=2;
  hambergur[1,9]:=2;
  hambergur[2,9]:=2;
  hambergur[3,9]:=2;
  hambergur[4,9]:=2;
  hambergur[5,9]:=2;
  hambergur[6,9]:=2;
  hambergur[7,9]:=2;
  hambergur[8,9]:=2;
  hambergur[9,9]:=2;
  hambergur[10,9]:=2;
  hambergur[11,9]:=2;
  hambergur[12,9]:=2;
  hambergur[13,9]:=2;
  hambergur[14,9]:=2;
  hambergur[15,9]:=2;
  hambergur[1,10]:=2;
  hambergur[2,10]:=2;
  hambergur[3,10]:=2;
  hambergur[4,10]:=2;
  hambergur[5,10]:=2;
  hambergur[6,10]:=2;
  hambergur[7,10]:=2;
  hambergur[8,10]:=2;
  hambergur[9,10]:=2;
  hambergur[10,10]:=2;
  hambergur[11,10]:=2;
  hambergur[12,10]:=2;
  hambergur[13,10]:=2;
  hambergur[14,10]:=2;
  hambergur[15,10]:=2;
  hambergur[2,11]:=2;
  hambergur[3,11]:=2;
  hambergur[4,11]:=2;
  hambergur[5,11]:=2;
  hambergur[6,11]:=2;
  hambergur[7,11]:=2;
  hambergur[8,11]:=2;
  hambergur[9,11]:=2;
  hambergur[10,11]:=2;
  hambergur[11,11]:=2;
  hambergur[12,11]:=2;
  hambergur[13,11]:=2;
  hambergur[14,11]:=2;
  end;
  procedure title (m,e,f :integer);
 begin
  {sheep}
 {  setcolor(1);}
   arc (50-m,e+50,30,270,25);
   arc (50-m,e+100,0,90,25);
   arc (50-m,e+100,200,360,25);
   line (100-m,e+25,100-m,e+125);
   line (100-m,e+75,150-m,e+75);
   line (150-m,e+25,150-m,e+125);
   line (175-m,e+25,175-m,e+125);
   line (175-m,e+25,225-m,e+25);
   line (175-m,e+75,225-m,e+75);
   line (175-m,e+125,225-m,e+125);
   line (250-m,e+25,250-m,e+125);
   line (250-m,e+25,300-m,e+25);
   line (250-m,e+75,300-m,e+75);
   line (250-m,e+125,300-m,e+125);
   line (325-m,e+25,325-m,e+125);
   arc (325-m,e+75,30,90,50);
   arc (325-m,e+40,270,330,50);
   line (369-m,e+51,369-m,e+64);
  {of}
   ellipse (275-m,e+220,0,360,35,50);
   line (325-m,e+170,325-m,e+270);
   line (325-m,e+170,375-m,e+170);
   line (325-m,e+210,375-m,e+210);
  {doom}
   line (250-m,e+325,250-m,e+425);
   arc (250-m,e+375,0,90,50);
   arc (250-m,e+375,270,360,50);
   ellipse (350-m,e+375,0,360,35,50);
   ellipse (435-m,e+375,0,360,35,50);
   line (485-m,e+325,485-m,e+425);
   line (485-m,e+325,525-m,e+375);
   line (525-m,e+375,565-m,e+325);
   line (565-m,e+325,565-m,e+425);
  {!}
   circle (594-m,e+413,12);
   circle (594-m,e+337,12);
   setcolor (0);
   ellipse (594-m,e+337,183,359,12,12);
   setcolor (f);
   line (594-m,e+393,582-m,e+338);
   line (594-m,e+393,606-m,e+339);
  end;
{****************************************************************************}
procedure sheep_gr;
 begin
  setcolor(7);
  arc (30,295,0,270,25);
  arc (30,345,90,360,25);
  arc (80,295,0,180,25);
  arc (80,345,180,360,25);
  arc (130,295,0,180,25);
  arc (130,295,270,360,25);
  arc (130,345,0,90,25);
  arc (130,345,180,360,25);
  circle (155,285,25);
  circle (8,272,7);
  line (55,354,55,394);
  line (105,354,105,394);
  line (50,360,50,394);
  line (100,360,100,394);
  setcolor(0);
  arc (130,295,0,83,25);
  arc (130,295,324,360,25);
  setcolor(7);
  ellipse (147,275,0,360,4,6);
  ellipse (162,275,0,360,4,6);
  setfillstyle (solidfill,7);
  fillellipse(147,278,2,2);
  fillellipse(162,278,2,2);
  arc (155,285,180,360,15);
  ellipse(140,261,0,255,5,7);
  ellipse(170,261,0,180,5,7);
  ellipse(170,261,300,360,5,7);
 end;
{****************************************************************************}
procedure pman_gr;
 begin
  setcolor (14);
  setfillstyle (solidfill,14);
  circle (500,150,75);
  line (500,150,567,120);
  line (500,150,567,180);
  fillellipse (490,112,11,6);
  circle (490,106,12);
  setcolor (0);
  arc (500,150,0,24,75);
  arc (500,150,337,360,75);
 end;
  procedure vertical;
 begin
 setcolor(15);
  rectangle (20,20,620,460);
  line(60,60,60,100);
  line(60,180,60,220);
  line(60,260,60,300);
  line(60,380,60,420);
  line(100,20,100,100);
  line(100,180,100,300);
  line(100,380,100,460);
  line(140,60,140,100);
  line(140,140,140,300);
  line(140,340,140,420);
  line(180,100,180,180);
  line(180,260,180,300);
  line(220,300,220,340);
  line(220,420,220,460);
  line(260,220,260,300);
  line(380,220,380,300);
  line(420,300,420,340);
  line(420,420,420,460);
  line(460,100,460,180);
  line(460,260,460,300);
  line(500,60,500,100);
  line(500,140,500,300);
  line(500,340,500,420);
  line(540,20,540,100);
  line(540,180,540,300);
  line(540,380,540,460);
  line(580,60,580,100);
  line(580,180,580,220);
  line(580,260,580,300);
  line(580,380,580,420);
 end;
{****************************************************************************}
procedure horizontal;
 begin
 setcolor(15);
  line(140,60,220,60);
  line(260,60,380,60);
  line(420,60,500,60);
  line(220,100,300,100);
  line(340,100,420,100);
  line(20,140,100,140);
  line(220,140,260,140);
  line(300,140,340,140);
  line(380,140,420,140);
  line(540,140,620,140);
  line(180,180,220,180);
  line(260,180,380,180);
  line(420,180,460,180);
  line(140,220,220,220);
  line(300,220,340,220);
  line(420,220,500,220);
  line(180,260,220,260);
  line(300,260,340,260);
  line(420,260,460,260);
  line(260,300,380,300);
  line(20,340,100,340);
  line(140,340,180,340);
  line(220,340,300,340);
  line(340,340,420,340);
  line(460,340,500,340);
  line(540,340,620,340);
  line(180,380,260,380);
  line(300,380,340,380);
  line(380,380,460,380);
  line(140,420,180,420);
  line(260,420,380,420);
  line(460,420,500,420);
 end;
 procedure game_over(g:integer);
 begin
  {GAME OVER SCREEN}
  {BLUE FILL}g := 9;
             setfillstyle (solidfill,g);
             bar (25,25,525,175);
  {LINES BETWEEN LETTERS}
  {G}setfillstyle (solidfill,0);
     setcolor (0);
     rectangle (25,25,150,175);rectangle (26,26,149,174);
     bar (80,80,150,82);Bar (80,80,82,125);bar (80,125,115,127);
  {A}rectangle (150,25,250,175);rectangle (151,26,249,174);
     bar (200,132,202,174);bar (190,80,210,105);
  {M}rectangle (250,25,400,175);rectangle (251,26,399,174);
     bar (300,175,302,105);bar (350,175,352,105);
  {E}rectangle (400,25,525,175);rectangle (401,26,524,174);
     bar (460,75,525,77);bar (460,125,525,127);
  {BLUE FILL}setfillstyle (solidfill,g);
             bar (25,225,550,375);
  {LINES BETWEEN LETTERS}
  {O}setfillstyle (solidfill,0);
     setcolor (0);
     rectangle (25,225,150,375);rectangle (26,226,149,374);
     bar (75,275,100,325);
  {V}rectangle (150,225,270,375); rectangle (151,226,269,374);
     bar (209,225,211,325);
  {E}rectangle (270,225,390,375);rectangle (271,226,389,374);
     bar (330,275,390,277);bar (330,325,390,327);
  {R}rectangle (390,225,515,375);rectangle (391,226,514,374);
     bar (445,300,515,302);bar (445,325,447,375);bar (450,250,475,275);
  {!}rectangle (515,225,550,375);rectangle (516,226,549,374);
     bar (515,345,550,347);
 end;
  procedure creat (g:integer);
 begin
  {CREATORS:}
  g := 12;
  setcolor (g);
  {C}ellipse (25,50,30,330,25,40);
  {R}line (65,40,65,90);ellipse (65,55,0,90,20,15);ellipse (65,55,270,360,20,13);ellipse (65,95,10,90,23,26);
  {E}line (105,40,105,90);line (105,40,130,40);line (105,65,120,65);line (105,90,130,90);
  {A}line (140,90,155,40);line (155,40,170,90);line (148,65,162,65);
  {T}line (175,40,215,40);line (195,40,195,90);
  {O}ellipse (240,65,0,360,15,25);
  {R}line (270,40,270,90);ellipse (270,55,0,90,20,15);ellipse (270,55,270,360,20,13);ellipse (270,95,10,90,23,26);
  {S}arc (315,52,30,270,12);arc (315,78,0,90,13);arc (315,78,210,360,13);
  {:}circle (350,50,8);circle (350,75,8);
  {CHRISTOPHER}
  g:= 9;
  setcolor (g);
  {C}ellipse (25,150,30,330,15,30);
  {H}line (50,120,50,180);line (50,150,75,150);line (75,120,75,180);
  {R}line (90,120,90,180);ellipse (90,135,0,90,20,15);ellipse (90,135,270,360,20,13);ellipse (90,187,10,90,25,39);
  {I}line (130,120,130,180);
  {S}arc (155,135,0,270,15);arc (155,165,0,90,15);arc (155,165,180,0,15);
  {T}line (195,120,195,180);line (175,120,215,120);
  {O}ellipse (235,150,0,360,17,30);
  {P}line (260,120,260,180);ellipse (260,135,0,90,25,16);ellipse (260,135,270,360,25,17);
  {H}line (295,120,295,180);line (295,150,320,150);line (320,120,320,180);
  {E}line (335,120,335,180);line (335,120,360,120);line (335,150,355,150);line (335,180,360,180);
  {R}line (375,120,375,180);ellipse (375,135,0,90,20,15);ellipse (375,135,270,360,20,13);ellipse (375,187,10,90,25,39);
  {THOMPSON}
  {T}line (25,200,25,260);line (5,200,45,200);
  {H}line (55,200,55,260);line (55,230,80,230);line (80,200,80,260);
  {O}ellipse (110,230,0,360,17,30);
  {M}line (140,200,140,260);line (140,200,160,230);line (160,230,180,200);line (180,200,180,260);
  {P}line (195,200,195,260);ellipse (195,215,0,90,25,16);ellipse (195,215,270,360,25,17);
  {S}arc (245,215,0,270,15);arc (245,245,0,90,15);arc (245,245,180,0,15);
  {O}ellipse (285,230,0,360,17,30);
  {N}line (315,200,315,260);line (315,200,345,260);line (345,200,345,260);
  {AND}
  {A}line (255,275,245,305);line (255,275,265,305);line (250,290,260,290);
  {N}line (270,275,270,305);line (270,275,280,305);line (280,275,280,305);
  {D}line (290,275,290,305);ellipse (290,290,0,90,15,16);ellipse (290,290,270,0,15,16);
  {MELISSA}
  {M}line (270,325,270,385);line (270,325,290,355);line (290,355,310,325);line (310,325,310,385);
  {E}line (325,325,325,385);line (325,325,350,325);line (325,355,345,355);line (325,385,350,385);
  {L}line (365,325,365,385);line (365,385,390,385);
  {I}line (405,325,405,385);
  {S}arc (430,340,0,270,15);arc (430,370,0,90,15);arc (430,370,180,360,15);
  {S}arc (470,340,0,270,15);arc (470,370,0,90,15);arc (470,370,180,360,15);
  {A}line (515,325,500,385);line (515,325,530,385);line (508,355,523,355);
  {CLEMENTS}
  {C}ellipse (285,430,30,330,15,30);
  {L}line (310,400,310,460);line (310,460,335,460);
  {E}line (350,400,350,460);line (350,400,375,400);line (350,430,370,430);line (350,460,375,460);
  {M}line (390,400,390,460);line (390,400,410,430);line (410,430,430,400);line (430,400,430,460);
  {E}line (445,400,445,460);line (445,400,470,400);line (445,430,465,430);line (445,460,470,460);
  {N}line (485,400,485,460);line (485,400,515,460);line (515,460,515,400);
  {T}line (545,400,545,460);line (525,400,565,400);
  {S}arc (590,415,0,270,15);arc (590,445,0,90,15);arc (590,445,180,360,15);
 end;
 procedure rsheeps;(*draws sheep*)
 begin
  line (a1+2,b1+11,a1+2,b1+12);
  line (a1+3,b1+11,a1+3,b1+12);
  line (a1+4,b1+13,a1+4,b1+20);
  line (a1+4,b1+23,a1+4,b1+26);
  line (a1+5,b1+13,a1+5,b1+20);
  line (a1+5,b1+23,a1+5,b1+26);
  line (a1+6,b1+11,a1+6,b1+28);
  line (a1+7,b1+11,a1+7,b1+28);
  line (a1+8,b1+11,a1+8,b1+34);
  line (a1+9,b1+11,a1+9,b1+34);
  line (a1+10,b1+11,a1+10,b1+28);
  line (a1+11,b1+11,a1+11,b1+28);
  line (a1+12,b1+11,a1+12,b1+34);
  line (a1+13,b1+11,a1+13,b1+34);
  line (a1+14,b1+11,a1+14,b1+28);
  line (a1+15,b1+11,a1+15,b1+28);
  line (a1+16,b1+11,a1+16,b1+28);
  line (a1+17,b1+12,a1+17,b1+27);
  line (a1+18,b1+13,a1+18,b1+26);
  line (a1+19,b1+13,a1+19,b1+26);
  line (a1+20,b1+12,a1+20,b1+27);
  line (a1+21,b1+11,a1+21,b1+28);
  line (a1+22,b1+11,a1+22,b1+28);
  line (a1+23,b1+11,a1+23,b1+28);
  line (a1+24,b1+11,a1+24,b1+34);
  line (a1+25,b1+11,a1+25,b1+34);
  line (a1+26,b1+11,a1+26,b1+28);
  line (a1+27,b1+11,a1+27,b1+28);
  line (a1+28,b1+11,a1+28,b1+34);
  line (a1+29,b1+11,a1+29,b1+34);
  line (a1+30,b1+10,a1+30,b1+28);
  line (a1+31,b1+8,a1+31,b1+28);
  line (a1+32,b1+8,a1+32,b1+28);
  line (a1+33,b1+7,a1+33,b1+28);
  line (a1+34,b1+7,a1+34,b1+20);
  line (a1+34,b1+23,a1+34,b1+26);
  line (a1+35,b1+7,a1+35,b1+20);
  line (a1+35,b1+23,a1+35,b1+26);
  line (a1+36,b1+7,a1+36,b1+14);
  line (a1+37,b1+8,a1+37,b1+13);
  line (a1+38,b1+8,a1+38,b1+13);
  line (a1+39,b1+9,a1+39,b1+12);
 end;
 procedure pebble (ABBA,BAAB:integer);   {small pebble}
 begin
  setfillstyle (solidfill,9);
  setcolor (9);
  fillellipse (ABBA+21,BAAB+21,7,7);
 end;
procedure power_peb (ABBA,BAAB:integer); {big pebble}
 begin
 setfillstyle (solidfill,10);
  setcolor (10);
  fillellipse (ABBA+21,BAAB+21,10,10);
 end;
 procedure pman(var a,b:integer);(*makes pman*)
 begin
  {rectangle (1,1,40,40);}
  setfillstyle (solidfill,14);
  setcolor (14);
  fillellipse (a+21,b+21,18,18);
  setfillstyle (solidfill,0);
  setcolor (0);
  pieslice (a+21,b+21,25,0,18);
  setfillstyle (solidfill,0);
  setcolor (0);
  fillellipse (a+15,b+10,2,2);
 end;
 procedure epman(var a,b:integer);(*removes pman*)
 begin
  {rectangle (1,1,40,40);}
  setfillstyle (solidfill,0);
  setcolor (0);
  fillellipse (a+21,b+21,18,18);
  setfillstyle (solidfill,0);
  setcolor (0);
  pieslice (a+21,b+21,25,0,18);
  setfillstyle (solidfill,0);
  setcolor (0);
  fillellipse (a+15,b+10,2,2);
 end;
procedure putpebble (hambergur:beefaroni;var ABBA,BAAB:integer); {draw pebbles}
var
free,dom:integer;
begin
for free:=1 to 15 do
for dom:=1 to 11 do
begin
if hambergur[free,dom]=2 then
begin
ABBA:=free*40-20;
BAAB:=dom*40-20;
pebble (ABBA,BAAB);
end;
if hambergur[free,dom]=1 then
begin
ABBA:=free*40-20;
BAAB:=dom*40-20;
power_peb (ABBA,BAAB);
end;
end;
end;
procedure lftbox ( var score,a1,b1,c1,d1:integer;du,mb:string;abbar,baabr:real;
var a,b,c,d,ABBA,BAAB:integer;var hamburger:beefaroni); (*movement left*)
begin
if (a-40>0) and (c-40>0) then
if Getpixel(a,b+20)<>15 then
begin
setfillstyle (solidfill,0);
  setcolor (0);
(*rectangle (a,b,c,d);*)
(*bar(a,b,c,d);*)
epman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);

{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
hamburger[ABBA,BAAB]:=0;
a:=a-40;
c:=c-40;
setfillstyle (solidfill,14);
  setcolor (14);
setcolor(white);
(*rectangle (a,b,c,d);*)
pman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
if hamburger[abba,baab]=2 then
score:=score+1;
if hamburger[abba,baab]=1 then
begin
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
setcolor (black);
rsheeps;
a1:=300;
B1:=260;
c1:=340;
d1:=300;
end;
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
hamburger[ABBA,BAAB]:=3;
y:=' ';
end;
end;
procedure rtbox (var score,a1,b1,c1,d1:integer;du,mb:string; abbar,baabr:real;
var a,b,c,d,ABBA,BAAB:integer; var hamburger:beefaroni);    (*movement right*)
begin
if (a+40<640) and (c+40<640) then
if getpixel(a+40,b+20)<>15 then
begin
(*rectangle (a,b,c,d);*)
(*bar(a,b,c,d);*)
setfillstyle (solidfill,0);
  setcolor (0);
 epman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}

hamburger[ABBA,BAAB]:=0;
a:=a+40;
c:=c+40;
setcolor(white);
setfillstyle (solidfill,14);
  setcolor (14);(*rectangle (a,b,c,d);*)
pman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
if hamburger[abba,baab]=2 then
score:=score+1;
if hamburger[abba,baab]=1 then
begin
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
setcolor (black);
rsheeps;
a1:=300;
B1:=260;
c1:=340;
d1:=300;
end;
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
hamburger[ABBA,BAAB]:=3;
y:=' ';
end;
end;
procedure upbox (var score,a1,b1,c1,d1:integer;du,mb:string; abbar,baabr:real;
var a,b,c,d,ABBA,BAAB:integer; var hamburger:beefaroni);     (*movement up*)
begin
if (b-40>0) and (d-40>0) then
if getpixel(a+20,b)<>15 then
begin
(*rectangle (a,b,c,d);*)
(*bar(a,b,c,d);*)
setfillstyle (solidfill,0);
  setcolor (0);
  epman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}

hamburger[ABBA,BAAB]:=0;
b:=b-40;
d:=d-40;
setcolor(white);
setfillstyle (solidfill,14);
  setcolor (14);
(*rectangle (a,b,c,d);*)
pman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
if hamburger[abba,baab]=2 then
score:=score+1;
if hamburger[abba,baab]=1 then
begin
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
setcolor (black);
rsheeps;
a1:=300;
B1:=260;
c1:=340;
d1:=300;
end;
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
hamburger[ABBA,BAAB]:=3;
y:=' ';
end;
end;
procedure downbox (var score,a1,b1,c1,d1:integer;du,mb:string; abbar,baabr:real;
var a,b,c,d,ABBA,BAAB:integer; var hamburger:beefaroni);{move pman down}
begin
if (b+40<480) and (d+40<480) then
if getpixel(a+20,b+40)<>15 then
begin
(*rectangle (a,b,c,d);*)
(*bar(a,b,c,d);*)
setfillstyle (solidfill,0);
  setcolor (0);
  epman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}

hamburger[ABBA,BAAB]:=0;
b:=b+40;
d:=d+40;
setcolor(white);
setfillstyle (solidfill,14);
  setcolor (14);
(*rectangle (a,b,c,d);*)
pman(a,b);
ABBAr:=(a+20)/40;
BAABr:=(b+20)/40;
abba:=round(abbar);
baab:=round(baabr);
if hamburger[abba,baab]=2 then
score:=score+1;
if hamburger[abba,baab]=1 then
begin
setcolor (black);
rsheeps;
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
a1:=300;
B1:=260;
c1:=340;
d1:=300;
end;
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
hamburger[ABBA,BAAB]:=3;
y:=' ';
end;
end;
procedure rlftbox (du,mb:string; abbar,baabr:real; hamburger:beefaroni;
abba,baab:integer;var a1,b1,c1,d1,dork:integer);  (*random movement left*)
begin
if (a1-40>0) and (c1-40>0) then
if getpixel (a1,b1+20)<>15 then
begin
setcolor(black);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hambergur[ABBA,BAAB]=2 then
pebble (A1,B1);
if hambergur[ABBA,BAAB]=1 THEN
power_peb(a1,b1);
a1:=a1-40;
c1:=c1-40;
setcolor(white);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
y:=' ';
dork:=1;
end;
end;
procedure rrtbox (du,mb:string; abbar,baabr:real; hamburger:beefaroni;
abba,baab:integer; var a1,b1,c1,d1,dork:integer);   (*random movement right*)
begin
if (a1+40<640) and (c1+40<640) then
if getpixel(a1+40,b1+20)<>15 then
begin
setcolor(black);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
gotoxy(1,1);
outtext (du);
outtext(mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
a1:=a1+40;
c1:=c1+40;
setcolor(white);
(*rectangle (a1,b1,c1,d);*)
rsheeps;
y:=' ';
dork:=1;
end;
end;
procedure rupbox (du,mb:string; abbar,baabr:real; hamburger:beefaroni;
abba,baab:integer; var a1,b1,c1,d1,dork:integer);  (*random movement up*)
begin
if (b1-40>0) and (d1-40>0) then
if getpixel (a1+20,b1)<>15 then
begin
setcolor(black);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
b1:=b1-40;
d1:=d1-40;
setcolor(white);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
y:=' ';
dork:=1;
end;
end;
procedure rdownbox (du,mb:string; abbar,baabr:real; hamburger:beefaroni;
abba,baab:integer; var a1,b1,c1,d1,dork:integer);    (*random movement down*)
begin
if (b1+40<480) and (d1+40<480) then
if getpixel (a1+20,b1+40)<>15 then
begin
setcolor(black);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
ABBAr:=(a1+20)/40;
BAABr:=(b1+20)/40;
abba:=round(abbar);
baab:=round(baabr);
{str(abbar:3,du);
str(baabr:3,mb);
val (du,ABBA,error_postion);
val (mb,BAAB,error_postion);}
if hamburger[ABBA,BAAB]=2 then
pebble(a1,b1);
if hamburger[ABBA,BAAB]=1 then
power_peb(a1,b1);
b1:=b1+40;
d1:=d1+40;
setcolor(white);
(*rectangle (a1,b1,c1,d1);*)
rsheeps;
y:=' ';
dork:=1;
end;
end;
begin (*main*)
randomize;
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
cleardevice;
f:=1;
setcolor (f);
m:=0;
e:=0;
title (m,e,f);
m:=5;
e:=5;
f:=2;
setcolor (f);
title (m,e,f); {title screen}
sheep_gr;
pman_gr;
readln;
cleardevice;
creat(g);
readln;
repeat
cleardevice;
speed:=501;     {sheep speed}
setup(hambergur);  {setup array}
vertical;           {draw grid}
horizontal;
putpebble (hambergur,ABBA,BAAB); {draws pebble}
a:=300;(*starting place*)
b:=300;
c:=340;
d:=340;
(*rectangle (a,b,c,d);*)
pman(a,b);
a1:=300;
b1:=260;
c1:=340;
d1:=300;
setcolor(white);
rsheeps;
ABBA:=20;
BAAB:=20;
(*rectangle (a1,b1,c1,d1);*)
setcolor(white);
(*rsheeps;*)
(*rectangle (170,170,210,210);*)
repeat
setfillstyle (solidfill,0);
bar (600,5,612,10);
setcolor (white);
str (score,mellisa);
outtextxy(600,5,mellisa);
{str (score,du);
outtext (du);}
{putpebble (hambergur,ABBA,BAAB);}
if keypressed=true then
begin
repeat
case random(4)+1 of              (*sheep movement*)
1:rupbox(du,mb,abbar,baabr,hambergur,abba,baab,a1,b1,c1,d1,dork);
2:rlftbox(du,mb,abbar,baabr,hambergur,abba,baab, a1,b1,c1,d1,dork);
3:rrtbox(du,mb,abbar,baabr,hambergur,abba,baab, a1,b1,c1,d1,dork);
4:rdownbox(du,mb,abbar,baabr,hambergur,abba,baab, a1,b1,c1,d1,dork);
end;
until dork=1;
if (a1=a) and (b1=b) then
begin
setcolor (white);
rsheeps;
end;
case readkey of                 (*pman movement*)
#72:upbox(score,a1,b1,c1,d1,du,mb,abbar,baabr,a,b,c,d,ABBA,BAAB,hambergur);
#75:lftbox(score,a1,b1,c1,d1,du,mb,abbar,baabr,a,b,c,d,ABBA,BAAB,hambergur);
#77:rtbox(score,a1,b1,c1,d1,du,mb,abbar,baabr,a,b,c,d,ABBA,BAAB,hambergur);
#80:downbox(score,a1,b1,c1,d1,du,mb,abbar,baabr,a,b,c,d,ABBA,BAAB,hambergur);
end;
end
else
begin
{for ray=1 to 4 do begin}
repeat
case random(4)+1 of              (*sheep movement w/o key*)
1:rupbox(du,mb,abbar,baabr,hambergur,abba,baab,a1,b1,c1,d1,dork);
2:rlftbox(du,mb,abbar,baabr,hambergur,abba,baab,a1,b1,c1,d1,dork);
3:rrtbox(du,mb,abbar,baabr,hambergur,abba,baab,a1,b1,c1,d1,dork);
4:rdownbox(du,mb,abbar,baabr,hambergur,abba,baab,a1,b1,c1,d1,dork);
end;
until dork=1;
end;
(*putpebble (hambergur,ABBA,BAAB);*)
if ((ABBA=a1) and (BAAB=b1)) then
begin
setcolor (white);
rsheeps;
end;

if score=159 then {next level}
begin
cleardevice;
setup (hambergur);
putpebble (hambergur,abba,baab);
speed:=speed+250;
score:=0;
a:=300;
b:=300;
c:=340;
d:=340;
a1:=300;
b1:=260;
c1:=340;
d1:=300;
 end;
if k=1 then{game over screen}
begin
game_over(g);
stop:=5;
delay (500);
{cleardevice;
horizontal;
vertical;
k:=0;
a:=300;
b:=300;
c:=340;
d:=340;
a1:=300;
b1:=260;
c1:=340;
d1:=300;
putpebble (hambergur,ABBA,BAAB);}
end;
if (a=a1) and (b=b1) then (* reconize hit*)
begin
{outtextxy(10,10,'You have been hit');}
k:=1;
end;
delay(speed);{choda is a really cool guy, everyone should listen to choda because he is right}
dork:=9;
until {requested end}(((keypressed) and (readkey='q')) or {death}(stop=5));
stop:=0;
k:=0;
score:=0;
cleardevice;
setcolor (white);
outtext('Would you like to play agian?(y/n)');
readln (happy)
until happy='n';
closegraph;
end;
End. (*main*)

