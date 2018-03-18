Program monkeyshell;
(*PROGRAM BY AARON EVANS, JIM GIFFORD AND CZAR*)
(*DATE DUE*)
(*FOR INSTANT RELIEF*)
USES
GRAPH,CRT;
VAR
GRDRIVER,GRMODE,GRERROR,LOOP,num:INTEGER;
key:char;
finish,asprin,toothb,lax,coat,knife,dinner,gun,boot,map:boolean;
boat,boy,oldman,kal,rep,invent:boolean;
yorn:string;
(****************************************************************************)
PROCEDURE GDRIVE(VAR GRDRIVER,GRMODE,GRERROR:INTEGER);
BEGIN
GRDRIVER:=DETECT;
INITGRAPH(GRDRIVER,GRMODE,'C:\TP\BGI\');
GRERROR:=GRAPHRESULT;
IF GRERROR<>GROK THEN
WRITELN('GRAPHICS ERROR:',GRAPHERRORMSG(GRERROR));
END;
(****************************************************************************)
procedure setfalse(var finish,asprin,toothb,lax,coat,knife,dinner,gun,
boot,map,boat,boy,oldman,kal:boolean);
begin
finish:=false;
asprin:=false;
toothb:=false;
lax:=false;
coat:=false;
knife:=false;
dinner:=false;
gun:=false;
boot:=false;
map:=false;
boat:=false;
boy:=false;
oldman:=false;
kal:=false;
end;
(****)
procedure fin(var finish:boolean);
var size2:word;
p,o,i,n,t,e:pointer;
y,rand:integer;
begin    {main}
GDRIVE(grdriver,grmode,grerror);
rand:=random(2)+1;
setcolor(yellow);
delay(500);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
size2:=imagesize(270,330,330,450);
getmem(i,size2);
getimage(270,330,330,450,i^);
setcolor(black);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
getmem(n,size2);
getimage(270,330,330,450,n^);
putimage(270,330,i^,normalput);
setcolor(brown);
circle(100,350,20);
line(100,370,100,425);
line(90,390,110,390);
line(90,390,80,425);
line(110,390,120,425);
line(100,425,80,450);
line(100,425,120,450);
getmem(p,size2);
getimage(80,330,120,450,p^);
setcolor(black);
circle(100,350,20);
line(100,370,100,425);
line(90,390,110,390);
line(90,390,80,425);
line(110,390,120,425);
line(100,425,80,450);
line(100,425,120,450);
getmem(o,size2);
getimage(80,330,120,450,o^);
setcolor(green);
rectangle(0,451,getmaxx,getmaxy);
setfillstyle(1,green);
floodfill(10,460,green);
for y:=1 to 150 do
begin
putimage(80+y,330,p^,normalput);
putimage(480-y,330,p^,normalput);
delay(1);
putimage(80+y,330,o^,normalput);
putimage(480-y,330,o^,normalput);
end;
putimage(85+y,330,p^,normalput);
putimage(480-y,330,p^,normalput);
setbkcolor(red);
for y:=1 to 120 do
begin
putimage(270,330+y,i^,normalput);
putimage(270,330+y,n^,normalput);
end;
putimage(230,330,o^,normalput);
putimage(330,330,o^,normalput);
setbkcolor(8);
setcolor(brown);
rectangle(270,451,330,500);
setfillstyle(1,brown);
floodfill(280,452,brown);
setcolor(lightgray);
rectangle(331,400,375,451);
setfillstyle(1,lightgray);
floodfill(340,410,lightgray);
arc(353,400,0,180,22);
floodfill(353,390,lightgray);
setcolor(black);
outtextxy(335,410,'R.I.P');
setcolor(white);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
setcolor(yellow);
ellipse(300,310,0,360,22,7);
size2:=imagesize(270,300,330,450);
getmem(i,size2);
getimage(270,300,330,450,i^);
setcolor(black);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
ellipse(300,310,0,360,22,7);
getmem(n,size2);
getimage(270,300,330,450,n^);
delay(1000);
setcolor(white);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
setcolor(red);
arc(300,330,150,210,17);
arc(300,330,150,210,15);
arc(300,330,330,30,17);
arc(300,330,330,30,15);
size2:=imagesize(270,300,330,450);
getmem(t,size2);
getimage(270,300,330,450,t^);
setcolor(black);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
setcolor(black);
arc(300,330,150,210,17);
arc(300,330,150,210,15);
arc(300,330,330,30,17);
arc(300,330,330,30,15);
size2:=imagesize(270,300,330,450);
getmem(e,size2);
getimage(270,300,330,450,e^);
for y:=1 to 100 do
begin
putimage(270,400-y,i^,normalput);
putimage(270,400-y,n^,normalput);
setcolor(brown);
rectangle(270,450,330,500);
setfillstyle(1,brown);
floodfill(280,451,brown);
end;
for y:=101 to 200 do
begin
putimage(270,400-y,i^,normalput);
delay(3);
putimage(270,400-y,n^,normalput);
end;
rectangle(270,450,330,500);
setfillstyle(1,brown);
floodfill(280,451,brown);
if rand=1 then begin
 for y:=201 to 500 do
 begin
 putimage(270,400-y,i^,normalput);
 delay(3);
 putimage(270,400-y,n^,normalput);
 end;
 setcolor(white);
 settextstyle(3,0,30);
 outtextxy(100,100,'Heaven');
 DELAY(900);
 SETCOLOR(BLACK);
 outtextxy(100,100,'Heaven');
 end
 else if rand=2 then begin
 for y:=1 to 300 do
 begin
 putimage(270,200+y,t^,normalput);
 delay(3);
 putimage(270,200+y,e^,normalput);
 setcolor(brown);
 rectangle(270,450,330,500);
 setfillstyle(1,brown);
 floodfill(271,451,brown);
 end;
 setcolor(brown);
 rectangle(270,450,330,500);
 setfillstyle(1,brown);
 floodfill(271,451,brown);
 setcolor(red);
 settextstyle(1,0,30);
 outtextxy(200,100,'Hell');
 line(350,378,362,400);
 delay(500);
 line(362,400,355,418);
 delay(500);
 line(355,418,360,437);
 delay(500);
 line(360,437,350,451);
 SETCOLOR(BLACK);
 outtextxy(200,100,'Hell');
 DELAY(900);
end;
setcolor(white);
settextstyle(1,0,4);
outtextxy(278,200,'GAME');
settextstyle(1,0,5);
outtextxy(270,230,'OVER');
readln;
closegraph;
finish:=true;
end;   {main}
(****)
procedure cabinet(var num:integer;key:char;var asprin,toothb,lax,invent
 :boolean);
begin    {main}
clrscr;
Writeln('You open the cabinet and discover it is full of various medicines.');
writeln('Choose your destiny.');
if asprin=false
 then writeln('1.Get Aspirin');
if toothb=false
 then writeln('2.Get Toothbrush');
if lax=false
 then writeln('3.Get Laxatives');
if (asprin=false)and(toothb=false)and(lax=false)
 then writeln('4.Get All three');
writeln('5.Close cabinet');
readln(key);
case key of
'1':begin
    asprin:=true;
    num:=1;
    end;
'2':begin
    toothb:=true;
    num:=1;
    end;
'3':begin
    lax:=true;
    num:=1;
    end;
'4':begin
    asprin:=true;
    toothb:=true;
    lax:=true;
    num:=1;
    end;
'5':num:=1;
'I':invent:=true;
end;    {case}
end;    {main}
(****)
procedure wardrobe(var num:integer;key:char;var coat,invent:boolean);
begin    {main}
clrscr;
if coat=false
 then begin  {then}
 writeln('You open the wardrobe and find a machine gun, a sword,');
 writeln('but your interest is piqued by the technicolor dream coat you see');
 writeln('Choose your destiny');
 writeln('1.Get Technicolor dream coat');
 writeln('2.Close Wardrobe');
 readln(key);
 if key='1'
  then begin
  coat:=true;
  num:=5;
  end
  else
  num:=5;
 if key='I'
  then invent:=true;
end   {then}
 else begin  {then}
 writeln('You open the wardrobe, but it is empty.');
 textcolor(31);
 writeln('<more>');
 readln;
 num:=5;
 textcolor(7);
 end;   {else}
 end;     {main}
(****)
procedure kitchen(var num:integer; key:char; var invent:boolean);
begin    {main}
clrscr;
writeln('You push the hinged door to reveal the kitchen.');
writeln('There are two doors, to the South and to the West.');
writeln('As you step into the kitchen you see a refrigerator');
writeln('Choose your destiny.');
writeln('1.Go South');
writeln('2.Go West');
writeln('3.Open fridge');
readln(key);
case key of
'1':num:=8;
'2':num:=1;
'3':num:=4;
'I':invent:=true;
end;   {case}
end;   {main}
(****)
procedure bedroom(var num:integer; key:char; var invent:boolean);
begin   {main}
clrscr;
writeln('You enter the bedroom and you see a door to the North,');
writeln('and a door to the East.  You see a wardrobe.  Choose your destiny');
writeln('1.Go North');
writeln('2.Go East');
writeln('3.Look in wardrobe');
readln(key);
case key of
'1':num:=7;
'2':num:=1;
'3':num:=6;
'I':invent:=true;
end;   {case}
end;   {main}
(****)
procedure fridge(var num:integer;key:char;var knife,dinner,invent:boolean);
begin     {main}
clrscr;
if knife=false
then begin    {then}
writeln('You open the fridge.  You hear the voice of an old woman.');
writeln('You glance on the top shelf and see Mrs. Butterworth talking.');
writeln('She says,''Welcome to the arctic land of darkness.  ');
writeln('For returning light to this land I will offer two gifts.');
writeln('The mythical butter knife of enchantment, and ');
writeln('a NIGHT-HAWK DINNER.');
writeln('Choose your destiny');
if (dinner=false)and(knife=false)
 then writeln('1.Take gifts');
writeln('2.Politely decline');
writeln('3.Slam fridge door');
readln(key);
case key of
'1':begin
    knife:=true;
    dinner:=true;
    num:=3;
    end;
'2':begin
 writeln('"I''m sorry you don''t want these, sonny." Mrs. Butterworth says.');
    delay(2000);
    textcolor(red);
    writeln('Suddenly, she extends her arm and tears ');
    writeln('your still-beating heart from your chest');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'3':begin
    writeln('You slam the fridge door in her face and turn around to see...');
    delay(2000);
    textcolor(red);
    writeln('An angry army of APES standing behind you.');
    writeln('They tear your body limb from limb.');
    writeln('The last thing you hear is the laughing of Mrs. Butterworth');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'I':invent:=true;
end;     {case}
 end    {then}
 else  begin  {else}
 writeln('You idiot.  You''ve already done that!');
 num:=3;
 end;   {else}
end;     {main}
(****)
procedure bathroom(var num:integer; key:char; var invent:boolean);
begin    {main}
clrscr;
writeln('You are in the bathroom of the chief''s villa.  You see a sink, ');
writeln('toilet, and a small cabinet.  You see doors North, East, West.');
writeln('Choose your destiny.');
writeln('1.Go North');
writeln('2.Go East');
writeln('3.Go West');
writeln('4.Look in cabinet');
readln(key);
case key of
'1':num:=7;
'2':num:=3;
'3':num:=5;
'4':num:=2;
'I':invent:=true;
end;   {case}
end;   {main}
(****)
procedure hall(var num:integer; key:char; var invent:boolean);
begin   {main}
clrscr;
writeln('You find yourself in the main hallway.');
writeln('You see two doors to the south and the front door.');
writeln('Choose your destiny.');
writeln('1.Go South to Bathroom');
writeln('2.Go South to Bedroom');
writeln('3.Go Out Front Door');
readln(key);
case key of
'1':num:=1;
'2':num:=5;
'3':begin
    writeln('You open the door and walk into the warm sunlight.');
    writeln('In the distance you see a stream of smoke.  You are spotted!');
    writeln('Your worst fear has come true.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'I':invent:=true;
end;   {case}
end;   {main}
(****)
procedure forest(var num:integer; key:char; var gun,invent:boolean);
begin   {main}
clrscr;
writeln('You stumble into a vast forest.  It seems peaceful');
if gun=false
then
 begin
 writeln('You see something moving in the bushes');
 writeln('Suddenly, a tiny elf jumps out and hands you a stun gun.');
 writeln('He then turns and runs away.');
 gun:=true;
 end;
write('You find three pathways. One to the east, to the south, ');
writeln('and one to the west');
writeln('Choose your destiny');
writeln('1.Go East');
writeln('2.Go South');
writeln('3.Go West');
readln(key);
case key of
'1':num:=10;
'2':num:=12;
'3':num:=9;
'I':invent:=true;
end;  {case}
end;  {main}
(****)
procedure shack(var num:integer; key:char; var invent:boolean);
begin    {main}
clrscr;
writeln('You move cautiously into the shack.');
writeln('There is a dead body sprawled across the floor.');
writeln('You see some empty tin cans on the floor.');
writeln('Choose your destiny.');
writeln('1.Return to forest');
writeln('2.Stay in shack');
readln(key);
if key='1'
 then num:=8
 else num:=9;
if key='I'
 then invent:=true;
end;   {main}
(****)
procedure path(var num:integer);
begin    {main}
writeln('You see a sign next to this path');
writeln('The sign reads "1 mile to the Village of Lost Souls');
writeln('You feel a strange pull toward that village.');
writeln('You decide to go explore the village.');
textcolor(31);
writeln('<more>');
readln;
textcolor(7);
num:=11;
end;     {main}
(****)
procedure village(var num:integer; key:char; var invent:boolean);
begin   {main}
clrscr;
textcolor(7);
writeln('You find yourself in the middle of your rival village,');
textcolor(red);
writeln('The Village Of Lost Souls!');
textcolor(7);
write('You see many huts in this village.');
writeln('  However only three interest you.');
writeln('You notice the hut to the south is that of an old man, ');
writeln('and to the east is a wise sage''s hut.');
writeln('The hut to the west seems to be abandonded.');
writeln('To the north you see the path to the forest.');
writeln('Choose your destiny');
writeln('1.Go East');
writeln('2.Go South');
writeln('3.Go West');
writeln('4.Go North');
readln(key);
case key of
'1':num:=15;
'2':num:=14;
'3':num:=13;
'4':num:=8;
'I':invent:=true;
end;   {case}
end;   {main}
(****)
procedure stream(var num:integer;key:char;var boot,map,invent:boolean);
begin  {main}
clrscr;
writeln('You follow the path to a stream.');
writeln('There is a boot floating in the stream.');
writeln('You see the path from whence you came to the north');
writeln('Choose your destiny');
writeln('1.Go North');
if boot=false
 then writeln('2.Take boot');
if boat=true
 then writeln('3.Use boat in stream');
readln(key);
case key of
'1':num:=8;
'2':begin
    boot:=true;
    writeln('You fish the boot out of the stream and try to put it on.');
    writeln('You feel something in the boot and discover it is a map.');
    map:=true;
    num:=12;
    readln;
    end;
'3':num:=16;
'I':invent:=true;
end;  {case}
end;  {main}
(****)
procedure abandon_hut(var num:integer; key:char; var boat,boy,invent:boolean);
begin  {main}
clrscr;
writeln('You decide to explore the abandoned hut.');
writeln('Inside you find a one-room hut devoid of furniture.');
if boat=false
 then
 writeln('The only thing you see besides four walls is an overturned boat.');
writeln('Choose your destiny.');
if (boat=false)and(boy=false)
 then writeln('1.Take Boat');
writeln('2.Go Back to village square');
readln(key);
if key='2'
 then
 num:=11
else
 begin
 writeln('You overturn the boat to make it fit into your pocket.');
writeln('As you turn it over you find a little boy crouched under the boat');
 writeln('You befriend the small child and invite him to join you.');
 writeln('He agrees and helps you put the boat in your pocket');
 boat:=true;
 boy:=true;
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 num:=11;
 end;
if key='I'
 then invent:=true;
end;  {main}
(****)
procedure oldhut(var num:integer; key:char; var knife,oldman,invent:boolean);
begin  {main}
clrscr;
textcolor(7);
writeln('You open the door to the old man''s hut, and walk in.');
if oldman=false
 then begin  {oldman}
 writeln('The old man is sitting in a gnarled and time-worn rocking chair');
 writeln('You approach the old man and he welcomes you with a warm hug.');
 writeln('Within minutes of talking, you find the man fascinating.');
 writeln('He invites you to stay for dinner.');
 writeln('Choose your destiny.');
 writeln('1.Stay and eat with the charming old man.');
 writeln('2.Brutally murder him.');
 writeln('3.Take a rain-check and leave.');
 readln(key);
 case key of
 '1':begin
     writeln('The old man laughs and invites you into his kitchen.');
     write('As you move into the kitchen, you find that it is not a ');
     writeln('kitchen at all.');
     writeln('But instead it is a hell-like dungeon of pain.');
writeln('You suddenly realize that this charming old man is not so charming');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '2':begin
     if knife=true
      then begin
      write('You draw the mythical butter knife of enchantment and ');
      writeln('hurl it at the old man.');
      writeln('The knife finds its target...');
      textcolor(red);
      writeln('The old man''s throat!  He screams in pain and dies.');
      textcolor(7);
      writeln('You retrieve the butter knife and quickly exit the hut.');
      textcolor(31);
      writeln('<more>');
      readln;
      textcolor(7);
      num:=11;
      end
     else begin
      writeln('You look for a blunt object with which to beat the old man');
      writeln('You scan the room but find nothing.  Then you get an idea.');
   writeln('You ask the old man to shake hands.  When he extends his hand, ');
      textcolor(red);
      writeln('you grab his arm and rip it from his body!');
      writeln('Then you begin to beat the old man with his own arm.');
      write('When he is a bloody pulp, you clean the blood from ');
      writeln('your hands and exit the hut.');
      textcolor(31);
      writeln('<more>');
      readln;
      textcolor(7);
      num:=11;
      end;
    end;
 '3':begin
     write('You tell the man you have just eaten and would like ');
     writeln('a rain-check.');
     write('He tells you that won''t be possible because you will be ');
     writeln('dead in 5 minutes!');
     writeln('He pulls some rope from behind his back and ties your hands.');
     writeln('You scream for help, but no one cares.');
     writeln('He then lowers you into a vat of boiling water.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
'I':invent:=true;
 end; {case}
oldman:=true;
end {oldman}
else begin   {else}
 writeln('The hut is empty and you decide to leave.');
 num:=11;
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 end;    {else}
end; {main}
(****)
procedure sagehut(var num:integer; key:char; var kal,invent:boolean);
begin  {main}
clrscr;
if kal=false
 then begin  {sage}
 write('You enter the hut of the town sage.  He sits upon a throne of ');
 writeln('human bones.');
 writeln('He looks up as you enter and greets you with a warm smile.');
 writeln('He pulls a chair from behind the table and invites you to sit');
 write('The two of you talk for over an hour.  ');
 writeln('You realize it is getting late,');
 writeln('and politely excuse yourself.');
 writeln('As you get up he hands you a kaleidoscope.');
 writeln('Choose your destiny');
 writeln('1.Take the present');
 writeln('2.Tell him of the approaching ape army');
 writeln('3.Leave the hut');
 readln(key);
 case key of
 '1':begin
     num:=11;
     kal:=true;
     writeln('You thank the wise sage and warn him of the ape army.');
     writeln('He blesses your journey and you walk into the town square');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     end;
 '2':begin
     writeln('You tell the man of the approaching ape army.');
     writeln('He doesn''t seem bothered.  You don''t understand why.');
     writeln('"You look puzzled." he says.  You are. Why isn''t he scared?');
     writeln('Then he shows you...');
     delay(1000);
     textcolor(red);
     writeln('He grabs his ear and pulls his face off.');
     writeln('Under this mask you see the face of an ape!');
     writeln('The ape grabs you and rips your head off.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '3':num:=11;
'I':invent:=true;
 end;  {case}
 end  {sage}
else begin
 write('You enter the hut of a sage.  In the center you see a throne');
 writeln(' of human bones.');
 writeln('There is no one here so you decide to exit the hut.');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 num:=11;
 end;
end;  {main}
(****)
procedure shore(var num:integer; key:char; var invent:boolean);
begin {main}
clrscr;
writeln('You and the boy float along happily in your boat.');
writeln('Suddenly you see a white-water rapid ahead.');
writeln('You find yourself being sucked toward the rapid.');
writeln('The boat capsizes and you and the boy are thrown into the water.');
writeln('You quickly swim to shore.');
writeln('Choose your destiny.');
writeln('1.Set up camp');
writeln('2.Try to find shelter');
readln(key);
if key='I'
 then invent:=true
 else begin  {else1}
 if key='1'
  then num:=17
  else begin  {else2}
  write('You and the boy set off in search of shelter.');
  writeln(' You find a cave and decide to bed down in there.');
  writeln('In the middle of the night you hear a strange noise.');
  writeln('You awake to find that this cave is home to a black bear.');
 writeln('You quickly call to your young companion, but he can''t hear you.');
  textcolor(red);
 writeln('Because he was the bear''s appetizer and you are the main course!');
  textcolor(31);
  writeln('<more>');
  readln;
  textcolor(7);
  fin(finish);
  end;  {else2}
end; {else1}
end;  {main}
(****)
procedure camp(var num:integer;key:char;var dinner,kal,coat,knife,invent
:boolean);
begin  {main}
clrscr;
writeln('You and the boy set up camp on the shore.');
writeln('"Tell me about your adventure" he says.');
delay(1000);
writeln('"Well, it all began in the bathroom of my chief''s villa..."');
delay(2000);
writeln('"WOW, that''s a wonderful story.  I''m cold and hungry." he says.');
write('"Me too." you tell him. "Maybe we can make a fire.  ');
writeln('Go get some wood."');
writeln('The boy scampers off in search of firewood.  What will you eat?');
textcolor(31);
writeln('<more>');
readln;
textcolor(7);
if dinner=true
 then begin  {then}
 writeln('You suddenly remember your encounter with Mrs. Butterworth.');
 writeln('The Nighthawk dinner!  That''s what you''ll eat.');
 writeln('But it''s frozen stiff, you''ll have to cook it on the fire.');
 writeln('The boy returns burdened with firewood.');
 writeln('You stack the wood in a pile and are ready to start the fire.');
 writeln('But how can you start it?');
 writeln('Choose your destiny');
 writeln('1.Rub sticks together');
 writeln('2.Use your matches');
 writeln('3.Use the stungun');
 writeln('4.Use the kaleidoscope');
 writeln('5.Use the technicolor dream coat');
 writeln('6.Use the butter knife of enchantment');
 readln(key);
 case key of
 '1':begin
     writeln('You find two sticks to rub together...');
     delay(1000);
     writeln('Hours later you still have not produced a spark.');
     writeln('You realize that this was not a good idea.');
     writeln('But, your muscles have cramped and you are forced to lie');
     writeln('on the cold, damp ground waiting for hypothermia.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '2':begin
     writeln('You reach for your matches but then you remember...');
     textcolor(red);
     delay(1000);
     writeln('You have no matches! You scream.');
     writeln('Your scream attracts an ape patrol.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '3':num:=18;
 '4':begin
     if kal=true
     then writeln('This cannot help you now!')
     else writeln('Too bad you don''t have this.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '5':begin
     if coat=true
     then writeln('This cannot help you now!')
     else writeln('Too bad you don''t have this.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '6':begin
     if knife=true
     then writeln('This cannot help you now!')
     else writeln('Too bad you don''t have this.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 'I':invent:=true;
 end; {case}
 end  {then}
 else begin {else}
 writeln('You have nothing to eat.  You will starve.  To survive,');
 write('you must ');
 textcolor(red);
 write('kill ');
 textcolor(7);
 write('the boy and ');
 textcolor(red+blink);
 writeln('eat his flesh.');
 textcolor(7);
writeln('The boy returns with his hands full of firewood. You smile at him.');
 writeln('Then you pounce.  Death comes quickly for the young forest child.');
 writeln('His body will nourish you for days.');
 writeln('But he gets the last laugh.  You choke on his eye and die.');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 fin(finish);
 end;    {else}
end;  {main}
(****)
procedure fire(var num:integer; key:char; var invent:boolean);
begin {main}
clrscr;
writeln('Using the stungun you start the fire.');
writeln('The fire warms your soul.  The boy seems happy and warm for now.');
writeln('But you are both hungry, so you pull out the Nighthawk dinner');
writeln('The dinner only serves one.');
writeln('Choose your destiny.');
writeln('1.Share the dinner with the boy.');
writeln('2.Keep the dinner for yourself and let the boy starve.');
writeln('3.Let the boy have the dinner.');
readln(key);
case key of
'1':begin
    write('You share the dinner with the boy, but his cries of hunger ');
    writeln('persist.');
    writeln('You tell him to be quiet but he won''t. ');
    writeln('You push the boy into the fire.');
    writeln('His cries have finally stopped so finally you can rest.');
    writeln('The smells from his simmering body arouse your hunger.');
    writeln('You decide to eat his flesh.  But, you discover...');
    textcolor(1);
    writeln('That he is an android!');
    textcolor(7);
    writeln('You pull him from the fire in a means to save him.');
    writeln('In the distance you hear the grunting of apes.');
    writeln('The android must have a homing device.');
    writeln('You feel bad about the boy''s death and can''t leave him.');
    writeln('You try to run but you can''t.');
    writeln('The apes capture you and knock you out.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    num:=19;
    end;
'2':begin
    writeln('You decide to eat the dinner yourself and let the boy starve.');
    writeln('The boy becomes very angry and begins to eat his own flesh.');
    writeln('The sight of this make you hungry for flesh, so...');
    textcolor(red);
    writeln('You put your own finger in your mouth and begin to chew.');
    writeln('You can''t eat just one!');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'3':begin
    writeln('Your heroic nature, while good for the boy, is bad for you.');
    writeln('The boy is quite satisfied, but you are hungry.');
    write('You start to have thoughts of eating the boy, and you don''t ');
    writeln('want to.');
    writeln('You run off into the forest to escape these thoughts.');
    writeln('You wander the forest in search of food until you starve.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'I':invent:=true;
end; {case}
end; {main}
(****)
procedure cage(var num:integer; key:char; var invent:boolean);
begin   {main}
clrscr;
write('You awake some time later imprisoned in a cage made from human ');
writeln('bones.');
writeln('You find that they have taken all of your possessions');
writeln('The apes are dragging you on a path in the forest.');
delay(1000);
writeln('You emerge from the forest into a giant ape village.');
writeln('The populace of this village have come to look at you.');
writeln('They begin to throw rotten food at you.');
write('Among the myriad of vegetables thrown at you, you catch a ');
textcolor(yellow);
writeln('cob of corn');
textcolor(7);
writeln('The apes put your cage in the town square, and leave you.');
writeln('Choose your destiny.');
writeln('1.Pick cage lock');
writeln('2.Eat the corn');
readln(key);
if key='I'
then invent:=true;
if key='2'
 then begin
 writeln('You are so hungry you decide to eat the corn.');
 writeln('It tastes funny, but you eat it anyway.');
 writeln('A short time later you begin coughing up blood.');
 writeln('The corn was tainted.  You made a bad choice.');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 fin(finish);
 end
 else begin
 writeln('Good idea, but what''ll you use?');
 writeln('1.Use hair pin');
 writeln('2.Use corn on the cob');
 writeln('3.Use old fingernail');
 readln(key);
 case key of
 '1':begin
     writeln('You reach into your lice infested hair to get a hair pin.');
     writeln('You find nothing.  Then, the apes come to torture you.');
     writeln('They cause you much pain.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '2':begin
     writeln('You remember the corn and decide to use it on the lock.');
     writeln('Hours later you are unsuccessful.  You fall asleep.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     num:=20;
     end;
 '3':begin
     writeln('You decide to use one of your fingernails to open the lock.');
     writeln('Since you don''t have any clippers you have to peel it off.');
     write('You accidentally pull to hard and yank your fingernail totally ');
     writeln('off!');
     textcolor(red);
     write('Blood flows uncontrollably from your finger.  The pain is ');
     writeln('immense!');
     writeln('You can''t stop the bleeding.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
'I':invent:=true;
end;  {case}
end;
end;  {main}
(****)
procedure bird(var num:integer; key:char; var invent:boolean);
begin  {main}
clrscr;
writeln('You wake up the next morning still in the cage.');
writeln('You look at the lock and see a bird perched on it.');
delay(1000);
writeln('The bird is picking at some corn that you wedged in the lock.');
writeln('Suddenly, the lock clicks and the door swings open.');
textcolor(yellow);
writeln('You are free!!');
textcolor(7);
writeln('As you make your way out of the cage, you hear a scream.');
writeln('You turn around to see a little ape boy getting water at the well.');
writeln('Choose your destiny.');
writeln('1.Run away');
writeln('2.Kill little ape boy.');
readln(key);
if key='I'
 then invent:=true
 else  begin {else}
  if key='1'
  then begin  {then}
  writeln('You try to run but the boy''s screams have brought the ape army.');
  writeln('They easily recapture you, but this time they kill you.');
  textcolor(31);
  writeln('<more>');
  readln;
  textcolor(7);
  fin(finish);
  end  {then}
  else begin  {else1}
  writeln('You run to the little ape boy and snap his neck like a twig.');
  writeln('You hear the ape army approaching.');
  writeln('Choose your destiny.');
  writeln('1.Run away');
  writeln('2.Jump in the well.');
  readln(key);
  if key='I'
  then invent:=true
  else begin  {else2}
  if key='2'
  then num:=21
  else begin  {else3}
  writeln('You try to run but the boy''s screams have brought the ape army.');
  writeln('They easily recapture you, but this time they kill you.');
  textcolor(31);
  writeln('<more>');
  readln;
  textcolor(7);
  fin(finish);
  end;    {else3}
 end;   {else2}
 end;   {else1}
 end;    {else}
end;  {main}
(****)
procedure  well(var num:integer; key:char; var asprin,invent:boolean);
begin   {main}
clrscr;
writeln('You fall down the well into the water.');
writeln('You find your belongings floating in the water.');
if asprin=true
 then begin  {then}
 writeln('You find that you are missing the aspirin.');
 writeln('You don''t worry and take a drink of the well water.');
 writeln('The water tastes funny...');
 textcolor(red);
 write('Your aspirin has dissolved in the water, which made a deadly ');
 writeln('chemical!');
 writeln('You begin to convulse and die!');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 fin(finish);
 end  {then}
 else begin   {else}
 write('You gather your things and decide to stay here till the ape army ');
 writeln('leaves');
 writeln('Choose your destiny.');
 writeln('1.Climb out');
 writeln('2.Look at map');
 writeln('3.Live the rest of your life in the well.');
 readln(key);
 case key of
 '1':begin
     writeln('You begin your climb out of the well.');
     writeln('As you near the top, your foot slips.');
     writeln('You fall back into the well.');
  writeln('You land on the body of a dead goat, and your neck snaps in two.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 '2':begin
     writeln('You remember the map you found in the boot.');
     writeln('You pull it out and begin to study it.  You find an exit.');
     writeln('The map tells you that there is a drain in the well.');
     writeln('You dive to the drain and unplug it.');
     writeln('You are sucked into the drain pipe, and knocked out...');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     num:=22;
     end;
 '3':begin
     writeln('You realize that escape is impossible and decide to give up.');
     writeln('A life in a well, while not interesting, is safe.');
     writeln('You never have to worry about water, but you have no food.');
     writeln('You slowly starve.');
     textcolor(31);
     writeln('<more>');
     readln;
     textcolor(7);
     fin(finish);
     end;
 'I':invent:=true;
 end;   {case}
end;   {else}
end;  {main}
(****)
procedure cat(var num:integer; key:char; var invent:boolean);
begin   {main}
clrscr;
textcolor(darkgray);
writeln('You awake in the catacombs.  You are sopping wet, but alive.');
writeln('You follow the map through the catacombs looking for the exit.');
writeln('You come to a fork in the catacombs.');
writeln('Choose your destiny.');
writeln('1.Go Right');
writeln('2.Go Left');
readln(key);
if key='I'
 then invent:=true
 else  begin  {else1}
  if key='1'
  then begin   {then}
  writeln('You go right into a dark tunnel.');
  writeln('You see a light at the end of the tunnel.');
  writeln('The light gets brighter, and brighter.');
  writeln('You reach the end of the tunnel, and stumble into the light.');
  num:=23;
  end    {then}
  else begin  {else2}
  writeln('You go left into the safer of the two tunnels.');
  writeln('This tunnel seems to be sloping downward.');
  writeln('It''s getting hotter, but you keep going.');
  writeln('You finally see the end of the tunnel, and you run toward it.');
  writeln('The tunnel leads into a red room.');
  delay(1000);
  textcolor(red);
  write('This is no ordinary room.  ');
  writeln('It is actually a burning Inferno of Pain');
  writeln('A man in a red suit with horns approaches you and says, ');
  writeln('      "Welcome to eternity!"');
  textcolor(31);
  writeln('<more>');
  readln;
  textcolor(7);
  fin(finish);
  end;   {else2}
 end;   {else1}
end;    {main}
(****)
procedure gate(var num:integer; key:char; var invent:boolean);
begin  {main}
clrscr;
textcolor(7);
write('You enter into a large room.  At the opposite end of the room');
writeln(' you see');
writeln('A man guarding a gate.');
writeln('You approach him and ask him if this is the way out.  He says.');
writeln('"That depends.  Where are you trying to go?');
writeln('Choose your response.');
writeln('1.As far away from here as possible');
writeln('2.Back to where my adventure started');
writeln('3.Wherever the gate goes');
readln(key);
case key of
'1':begin
    writeln('"Then yes, this is the way." he tells you.');
    writeln('He moves out of your way and you walk through the gate.');
  writeln('You are suddenly in another land.  You realize that it is China.');
    writeln('It is in the time of Genghis Khan''s conquest of China.');
    writeln('You find yourself in the middle of a great battle.');
    writeln('Suddenly you feel a sharp pain in your side and look to see...');
    delay(1500);
    textcolor(red);
    writeln('That someone has impaled you on his sword.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'2':begin
    writeln('"Then yes, this is the way." he tells you.');
    writeln('He moves out of your way and you walk through the gate.');
    writeln('You awke to find yourself...');
    delay(3000);
    setfalse(finish,asprin,toothb,lax,coat,knife,dinner,gun,boot,map,boat,boy,
    oldman,kal);
    num:=1;
    end;
'3':begin
    writeln('"Well," he says, "Then you may pass."');
    writeln('He moves out of your way and you walk through the gate.');
   writeln('You find yourself at the stream.  Your boat is tied to a levee.');
    writeln('You retrieve it and begin to row upstream.');
    writeln('You feel something in your pocket.  It''s a gold key.');
   writeln('Where did this come from?  Then you see the keeper of the gate.');
    writeln('He tells you that the gold key will come in handy.');
    writeln('You see the ape citadel ahead of you.  You row toward it.');
    writeln('You dock the boat just outside of the city limits.');
    writeln('You go ashore and make your way to the wall of the citadel.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    num:=24;
    end;
'I':invent:=true;
end;   {case}
end;  {main}
(****)
procedure citadel(var num:integer; key:char; var toothb,coat,invent:boolean);
begin   {main}
clrscr;
if toothb=true
 then begin {then}
 writeln('You wait out side of the wall of the citadel for nightfall.');
 write('Since you are one for dental hygiene, you pull out your ');
 writeln('tooth brush');
 writeln('Of course, after brushing you need to floss.');
 writeln('You pull out a box of some thin wire.');
 writeln('"Ah, dental floss" you think and begin flossing.');
 textcolor(red);
 writeln('You feel immense pain as the wire goes into your gums.');
 writeln('You look at the box label and find that this isn''t dental floss,');
 writeln('But PIANO WIRE!');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 fin(finish);
 end    {then}
 else begin  {else}
 writeln('You are just outside of the citadel wall.');
 writeln('You can smell the stench of apes.');
 writeln('Choose your destiny.');
 writeln('1.Attack the citadel');
 writeln('2.Wait till night fall');
 writeln('3.Enter citadel in peace');
 readln(key);
 case key of
'I':invent:=true;
'1':begin
    writeln('You run toward the citadel in a blaze of glory.');
    writeln('The apes see you coming and close the gate.');
    writeln('So, you try to scale the wall.');
    writeln('But, the apes prepared you a little surprise...');
    delay(2000);
    textcolor(red);
    writeln('BOILING OIL!');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
'2':begin
    writeln('You hide in a nearby bush till nightfall.');
    writeln('You realize a frontal attack is still foolish.');
    writeln('You must sneak up on them.');
    writeln('Choose your destiny.');
    writeln('1.Use the secret art of the ninja');
    if kal=true
     then writeln('2.Use the kaleidoscope to dazle the apes');
    if coat=true
     then writeln('3.Use the technicolor dream coat');
    readln(key);
    case key of
    '1':begin
        writeln('You slip into your secret ninja outfit and scale the wall.');
        write('As you slip through the citadel you step into a ');
        writeln('Burmese tiger trap.');
        writeln('The spikes at the bottom of the pit find their mark...');
        textcolor(red);
        writeln('Your body!');
        textcolor(31);
        writeln('<more>');
        readln;
        textcolor(7);
        fin(finish);
        end;
    '2':begin
    writeln('You pull out the kaleidoscope.  And prepare to dazzle the apes.');
        writeln('But you didn''t realize that a kaleidoscope needs light.');
        writeln('Your plan has failed!  The apes capture you.');
        textcolor(31);
        writeln('<more>');
        readln;
        textcolor(7);
        fin(finish);
        end;
    '3':begin
        write('You slip on the technicolor dream coat, ');
        writeln('and make your way into the citadel.');
        textcolor(31);
        writeln('<more>');
        readln;
        textcolor(7);
        num:=25;
        end;
    end;   {case}
    end;
'3':begin
    writeln('You walk into the citadel and exclaim that you come in peace.');
    writeln('Apes quickly sieze you and take you as a prisoner.');
    writeln('You are forced into a life of slavery.');
    textcolor(31);
    writeln('<more>');
    readln;
    textcolor(7);
    fin(finish);
    end;
end;   {case}
end;   {else}
end;   {main}
(****)
procedure inside(var num:integer; key:char; var lax,invent:boolean);
begin   {main}
clrscr;
writeln('You are wearing the technicolor dream coat, but the apes seem to ');
writeln('not be able to see you.');
writeln('Then you realize that the apes can''t see high frequency colors.');
writeln('You are invisible!');
textcolor(31);
writeln('<more>');
readln;
textcolor(7);
if lax=true
 then begin   {then}
 clrscr;
 writeln('You remember the laxatives you got in the bathroom cabinet.');
 writeln('You take the box and dump all of the laxatives into the ape well');
 delay(1000);
 textcolor(brown);
 writeln('It is a well known fact that monkeys love to throw their feces.');
 write('But, by putting the laxatives in the well water their feces is');
 writeln(' unthrowable!');
 textcolor(12);
 delay(1500);
 writeln('This causes the apes to go insane!');
 textcolor(7);
 delay(1500);
 write('In all of the confusion you make your way toward the imprisoned ');
 writeln('women.');
 writeln('You comfort them and try to open the lock, but you need the key.');
 delay(1000);
 writeln('Then you remember...');
 delay(2000);
 textcolor(yellow);
 writeln('The Gold Key!');
 textcolor(7);
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 clrscr;
 writeln('You pull out the key and unlock the women.  They are vey happy.');
 writeln('You all rejoice and return to your village.');
 writeln('You are the only man who survived the ape attack, so...');
 delay(1500);
 textcolor(9);
 writeln('You alone are the only male to procreate the human race.');
 TEXTCOLOR(31);
 WRITELN('<more>');
 readln;
 TEXTCOLOR(7);
 num:=100;
 end    {then}
 else begin  {else}
 writeln('You have no way of killing the apes.');
 writeln('Your only chance for survival is never taking off the coat.');
 delay(1500);
 writeln('Years later, you are walking invisible through the citadel.');
 writeln('You lean up against a wall.');
 writeln('After a brief rest, you begin your daily stroll through the town.');
 writeln('You turn around to look at the wall and see a white sign.');
 writeln('The sign reads-"WET PAINT"');
 textcolor(red);
 write('You have made a fatal mistake!  The paint has covered the magical ');
 writeln('paint.');
 textcolor(7);
 writeln('You try to run now that your disguise has been foiled.');
 writeln('However, a half visible man does attract attention.');
writeln('The apes are frightened by you so they don''t take you prisoner...');
 writeln('They just kill you!');
 textcolor(31);
 writeln('<more>');
 readln;
 textcolor(7);
 fin(finish);
 end;
end;    {main}
(****)
procedure goodend(var finish:boolean);
var size1,size2:word;
p,o,i,n:pointer;
y:integer;
begin    {main}
GDRIVE(grdriver,grmode,grerror);
setcolor(9);
delay(500);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
size2:=imagesize(270,330,330,450);
getmem(i,size2);
getimage(270,330,330,450,i^);
setcolor(black);
circle(300,350,20);
line(300,370,300,425);
line(270,390,330,390);
line(300,425,280,450);
line(300,425,320,450);
getmem(n,size2);
getimage(270,330,330,450,n^);
putimage(270,330,i^,normalput);
setcolor(green);
rectangle(0,451,getmaxx,getmaxy);
setfillstyle(1,green);
floodfill(10,460,green);
setcolor(yellow);
arc(100,350,0,180,21);
arc(100,350,0,180,22);
line(79,350,79,400);
line(78,350,78,400);
line(121,350,121,400);
line(122,350,122,400);
setcolor(white);
circle(100,350,20);
line(100,370,100,425);
line(70,390,130,390);
line(100,425,80,450);
line(100,425,120,450);
size1:=imagesize(70,325,130,450);
getmem(p,size1);
getimage(70,325,130,450,p^);
setcolor(black);
arc(100,350,0,180,21);
arc(100,350,0,180,22);
line(79,350,79,400);
line(121,350,121,400);
circle(100,350,20);
line(100,370,100,425);
line(70,390,130,390);
line(100,425,80,450);
line(100,425,120,450);
getmem(o,size2);
getimage(70,325,130,450,o^);
for y:=1 to 150 do
begin
putimage(60+y,325,p^,normalput);
putimage(480-y,325,p^,normalput);
delay(1);
putimage(60+y,325,o^,normalput);
putimage(480-y,325,o^,normalput);
end;
putimage(60+y,325,p^,normalput);
putimage(480-y,325,p^,normalput);
setcolor(white);
circle(295,342,1);
circle(305,342,1);
for y:=1 to 90 do
begin
arc(300,350,270-y,270+y,10);
delay(15);
end;
settextstyle(0,0,5);
setcolor(11);
outtextxy(150,150,'YOU WIN!');
readln;
closegraph;
finish:=true;
end;  {main}
(****)
procedure choose(var num:integer);
begin   {main}
case num of
1:bathroom(num,key,invent);
2:cabinet(num,key,asprin,toothb,lax,invent);
3:kitchen(num,key,invent);
4:fridge(num,key,knife,dinner,invent);
5:bedroom(num,key,invent);
6:wardrobe(num,key,coat,invent);
7:hall(num,key,invent);
8:forest(num,key,gun,invent);
9:shack(num,key,invent);
10:path(num);
11:village(num,key,invent);
12:stream(num,key,boot,map,invent);
13:abandon_hut(num,key,boat,boy,invent);
14:oldhut(num,key,knife,oldman,invent);
15:sagehut(num,key,kal,invent);
16:shore(num,key,invent);
17:camp(num,key,dinner,kal,coat,knife,invent);
18:fire(num,key,invent);
19:cage(num,key,invent);
20:bird(num,key,invent);
21:well(num,key,asprin,invent);
22:cat(num,key,invent);
23:gate(num,key,invent);
24:citadel(num,key,toothb,coat,invent);
25:inside(num,key,lax,invent);
100:goodend(finish);
else fin(finish);
end;  {case}
end;  {main}
(****)
procedure inventpr(var asprin,toothb,lax,coat,knife,dinner,gun,
boot,map,boat,boy,kal:boolean);
begin    {main}
clrscr;
writeln;
textcolor(12);
writeln('You are carrying the following items :');
writeln;
TEXTCOLOR(7);
if asprin=true
 then writeln('Aspirin');
if toothb=true
 then writeln('Tooth Brush');
if lax=true
 then writeln('Laxatives');
if coat=true
 then writeln('Technicolor Dream Coat');
if knife=true
 then writeln('Mythical Butter Knife of Enchantment');
if dinner=true
 then writeln('Night-hawk Dinner');
if gun=true
 then writeln('Stungun');
if boot=true
 then writeln('Boot');
if map=true
 then writeln('Map');
if boat=true
 then writeln('Boat');
if boy=true
 then writeln('Little Boy');
if kal=true
 then writeln('Kaleidoscope');
writeln;
writeln;
textcolor(12);
writeln('Press <Enter> to continue');
textcolor(7);
readln;
end;     {main}
(****)
BEGIN(*MAIN*)
CLRSCR;
RANDOMIZE;
num:=1;
yorn:='Y';
rep:=false;
invent:=false;
repeat
if rep=false
then begin   {rep then}
setfalse(finish,asprin,toothb,lax,coat,knife,dinner,gun,boot,map,boat,boy,
oldman,kal);
textcolor(7);
GDRIVE(GRDRIVER,GRMODE,GRERROR);
SETTEXTSTYLE(3,0,3);
delay(1000);
OUTTEXTXY(150,360,' IN THE YEAR 2040,');
FOR LOOP:=1 TO 27 DO
BEGIN
DELAY(50);
TEXTCOLOR(BLACK);
WRITELN;
END;
TEXTCOLOR(WHITE);
SETTEXTSTYLE(3,0,3);
OUTTEXTXY(50,360,'THE EARTH IS SPLIT BETWEEN TWO WORLDS ');
FOR LOOP:=1 TO 35 DO
BEGIN
DELAY(100);
TEXTCOLOR(BLACK);
WRITELN;
END;
TEXTCOLOR(WHITE);
SETTEXTSTYLE(3,0,3);
OUTTEXTXY(150,260,'THE HUMANOIDS ');
DELAY(1000);
FOR LOOP:=1 TO 15 DO
BEGIN
DELAY(100);
TEXTCOLOR(BLACK);
WRITELN;
END;
TEXTCOLOR(WHITE);
SETTEXTSTYLE(7,0,3);
OUTTEXTXY(150,360,'AND...');
FOR LOOP:=1 TO 7 DO
BEGIN
DELAY(10);
TEXTCOLOR(BLACK);
WRITELN;
END;
DELAY(800);
CLRSCR;
SETCOLOR(RED);
SETTEXTSTYLE(10,0,8);
OUTTEXTXY(1,150,'THE APES ');
SETCOLOR(BLACK);
DELAY(1000);
SETTEXTSTYLE(10,0,8);
OUTTEXTXY(1,150,'THE APES ');
SETTEXTSTYLE(10,0,2);
SETCOLOR(RED);
OUTTEXTXY(200,150,'DEATH MONKEY');
SETTEXTSTYLE(7,0,8);
OUTTEXTXY(220,200,'2040');
DELAY(1500);
CLOSEGRAPH;
CLRSCR;
textcolor(7);
WRITELN('You are Taylor, janitor to your Humanoid village.');
writeln('You are mopping the floor of the village chief''s villa, ');
writeln('when you hear a piercing scream.');
textcolor(31);
writeln('<more>');
readln;
textcolor(7);
writeln('A cloud of yellow smoke flows under the door, and you realize ');
writeln('what is happening.  The Apes are attacking your village again.');
write('You are sure that everyone died when they inhaled this ');
textcolor(yellow);
writeln('mustard gas.');
textcolor(7);
writeln('Luckly, you are wearing your mopping gas mask');
writeln('(You hate the smell of ammonia) and you are still alive.');
writeln('The women of the village have been captured and enslaved.');
writeln('It is up to you to rescue the women of your village.');
textcolor(31);
writeln('<more>');
readln;
textcolor(7);
end;  {rep then}

(*******************************)
(*THIS CODE ALLOWS THE GAME TO MOVE FROM PROCEDURE TO PROCEDURE*)
repeat
choose(num);
if invent=true
 then begin  {then}
 inventpr(asprin,toothb,lax,coat,knife,dinner,gun,boot,map,boat,boy,kal);
 invent:=false;
 end;  {then}
until finish=true;

(*******************************)

textcolor(white);
writeln('Do you want to play again?(Y or N)');
readln(yorn);
if yorn='Y'
 then num:=1;

(*******************************)
(*THIS CODE ALLOWS THE USER TO CHEAT WHEN THEY DIE*)
if yorn='YES.'
 then  begin   {then}
 writeln('Enter the level number to which you want to start.');
 readln(num);
 textcolor(7);
 rep:=true;
 end;    {then}
(*******************************)
until yorn='N';
END. (*MAIN*)