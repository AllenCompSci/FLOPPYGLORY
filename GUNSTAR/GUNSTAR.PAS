program shipgame;
(*JOHN CLARK BAKER*)

uses
Crt,GRAPH;
type
    bu = array[1..6] of integer;     (*number of bullets till repeat*)
    hi = array[1..5] of integer;

var
power : boolean;
out : boolean;
ina : boolean;
ffff : char;
wh,scores,sc : integer;
nx,ny : integer;
scstr : string;
grdriver,grmode,grerror:integer; (*GRAPH vars*)
lifevar,ed,c,x,y,z:integer; (*location and image vars*)
b,y1 : bu; (*CREATES more bullets than one*)
life,fire,bull : string;(*controls movement, firing, ie all ship acitons*)
size,s:word;      (*image memory*)
p,pn,pi,po,pt:pointer;    (*image locations*)
on : boolean;    (*regulates first image*)
onofffire : string;(*regulates on/off fire*)
x1,y11,y2,x2 : integer; (*ENEMY location vars*)
d,v,dis,dis1 : integer; (*emeny COUNTER*)
hit : hi; (**)
x3,y3,dis3 : integer;
control3,c3:boolean;
control1,c2,control,c1 : boolean;
outofgame : boolean;
start : boolean;
xx,yy,zz,qq : integer;
ap : pointer;
siz : word;

(**********************************STORY***********************************)
procedure story;
begin
cleardevice;
setcolor(10);
settextstyle(3,0,7);
moveto (150,25);
outtext('THE STORY');
settextstyle(2,0,5);
moveto(60,100);
delay(2000);
outtext('Greetings Starfighter.  Welcome to Rilos.  You have been recruited');
moveto(50,125);
delay(2000);
outtext('by Centauri and the Star League to defend the frontier against');
moveto(50,150);
delay(2000);
outtext('Xur and the Ko-Dan armada.  Rilos is the recruiting center for all');
moveto(50,175);
delay(2000);
outtext('starfighters and you have entered phase I - the test meant to find');
moveto(50,200);
delay(2000);
outtext('those with the gift to become starfighters.');
moveto(60,225);
delay(2000);
outtext('Eons ago our ancestors created our great frontier, a barrier of');
moveto(50,250);
delay(2000);
outtext('energy encircling the peaceful systems of the universe and forever');
moveto(50,275);
delay(2000);
outtext('shutting out the scurge that lurks beyond.  Because of a dark');
moveto(50,300);
delay(2000);
outtext('betrayal our frontier will soon collapse.  So we turn to you,');
moveto(50,325);
delay(2000);
outtext('starfighters, for of all the billions of creatures in the Star');
moveto(50,350);
delay(2000);
outtext('League, only you few who complete this test possess the gift.');
moveto(50,375);
delay(2000);
outtext('You and you alone stand between us and the black terror of');
moveto(50,400);
delay(2000);
outtext('the Ko-Dan.  Man your Gunstar...');
setcolor(4);
settextstyle(2,0,7);
moveto(150,425);
delay(2100);
outtext('Victory or Death!');
settextstyle(2,0,4);
moveto(400,430);
delay(400);
setcolor(3);
outtext('Press ENTER to return to the main menu');
readln;
end;


(****************************************************************************)
procedure savearrow(var ap:pointer);
begin
     setfillstyle(1,14);
     bar(10,10,30,15);

     siz := imagesize(10,10,30,15);
     getmem(ap,siz);
     getimage(10,10,30,15,ap^);
     setfillstyle(1,0);
     bar(10,10,30,15);
     end;
(****************************************************************************)
procedure gmovr;
begin
settextstyle(8,0,10);
setcolor(9);
moveto(130,25);
outtext('G');
delay(160);
outtext('A');
delay(160);
outtext('M');
delay(160);
outtext('E');
delay(160);

SETCOLOR(4);
moveto(140,200);
outtext('O');
delay(160);
outtext('V');
delay(160);
outtext('E');
delay(160);
outtext('R');

setcolor(10);
settextstyle(2,0,6);
moveto(100,400);
outtext('Press the ENTER key to return to the main menu.');
readln;
end;

(****************************************************************************)
procedure lives(var lifevar : integer;var life: string;var outofgame:boolean);
begin
     moveto(250,1);
     setcolor(7);
     life := ' ';
     str(lifevar,life);
     setfillstyle(1,0);
     bar(250,1,350,6);
     outtext('Lives: ');
     moveto(300,1);
     outtext(life);
     if lifevar = 0 then begin
                     outofgame := true;
                     end;
end;
(****************************************************************************)
procedure score(var scores,sc : integer;var scstr : string;var lifevar:integer;power : boolean);
begin
     sc := sc + 1;
     if power = true then lifevar := lifevar + 1;
     if sc > 49 then begin
     lifevar := lifevar + 1;
     lives(lifevar,life,outofgame);
     end;
     if sc > 49 then sc := 0;
     setfillstyle(1,0);
     bar(1,1,150,10);
     moveto(1,1);
     setcolor(7);
     outtext('Score: ');
     str(scores,scstr);
     outtext(scstr);
     outtext('00');
end;
(****************************************************************************)
procedure reinit(var x,y,x1,x2,x3,c,d,dis,dis1,dis3: integer;var on,c1,c2,c3 : boolean;
                     var lifevar : integer;var b,y1 : bu);
var
vvv : integer;
sss : string;
begin
cleardevice;
setcolor(7);
vvv := lifevar - 1;
moveto(180,250);
if vvv > 0 then begin
outtext('YOU DIED, BUT THE GAME IS NOT OVER. ');
str(vvv,sss);
outtext(sss);
outtext(' LIVES LEFT');
delay(3000);
end;
cleardevice;
setcolor(5);
line(0,50,650,50);   (*Border*)
line(0,450,650,450);
x := 10;    (*2nd INIT*)
y := 200;
x1 := 600;
x2 := 800;
x3 := 1000;
c := 0;
d := 0;

for vvv := 1 to 5 do
begin
setcolor(0);
line(b[vvv]+1,y1[vvv]+1,b[vvv]+6,y1[vvv]+1);
b[vvv]  := 35;
end;
dis := 2;
dis1 := 2;
dis3 := 2;
on := FALSE;
c1 := false;
c2 := false;
c3 := false;
lifevar := lifevar - 1;
lives(lifevar,life,outofgame);
score(scores,sc,scstr,lifevar,power);
end;
(****************************************************************************)
procedure chy11(var y11 : integer);
begin
     randomize;
     y11 := random (350) + 54;
end;
(****************************************************************************)
procedure chy2(var y2 : integer);
begin
     randomize;
     y2 := random (350) + 54;
end;
(****************************************************************************)
procedure chy3(var y3 : integer);
begin
     randomize;
     y3 := random (350) + 54;
end;
(****************************************************************************)
procedure checking(b,y1 : bu;var x1,x2,x3,y11,y2,y3 : integer;var nx,ny,wh,scores : integer);
var
   nothit : boolean;
begin
if   hit[wh] = 1 then
     begin
     ny := y11;
     nx := x1;
     scores := scores + 1;
     end;
if   hit[wh] = 9 then
     begin
     ny := y2;
     nx := x2;
     scores := scores + 1;
     end;
if hit[wh] = 8 then
     begin
     ny := y3;
     nx := x3;
     scores := scores + 2;
     end;
end;
(****************************************************************************)
procedure explode1(var x,y,nx,x1,x2,x3:integer;var ny,y2,y3,y11:integer);
var ex:integer;
begin
for ex := 1 to 20 do begin        (*518*)
setcolor(4);
circle(nx+18,ny+16,ex+1);
delay(1);
circle(nx+18,ny+16,ex+1);
setcolor(12);
circle(nx+18,ny+16,ex*2);
delay(1);
circle(nx+18,ny+16,ex*2);
end;
setfillstyle(1,0);
bar(18+nx-45,ny-42+16,18 + nx+42,ny+42+16);


if ny = y3    then begin
                chy3(y3);
                 x3 := 600;
                 c3 := false;
                end;
if ny = y2 then begin
                chy2(y2);
                x2 := 600;
                c2 := false;
                end;
if ny = y11    then begin
                chy11(y11);
                 x1 := 600;
                 c1 := false;
                 end;
                                     setcolor(5);
     line(0,50,650,50);   (*Border*)
     line(0,450,650,450); (*Border*)
     score(scores,sc,scstr,lifevar,power);
(*end;*)
END;
(****************************************************************************)
procedure inside1(var nx,x1,x2,x3,ny,y11,y2,y3,scores : integer);
begin
   if ((x2+25 >18+nx-45) and (x2+25 <18+nx+42))
   or ((x2+1 >18+nx-45) and (x2 +1 < 18+nx+42))then
   if (y2+32>ny-41+16) and (y2+32<ny+42+16)
   or ((y2+1>ny-41+16) and (y2+ 1<ny+42+16)) then begin
   if nx <> y11 then begin ny := y2;
   nx := x2;
   y2 := 700;
   x2 := 700;
   end;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);

   if ((x3+25 >18+nx-45) and (x3+25 <18+nx+42))
   or ((x3+1 >18+nx-45) and (x3 +1 < 18+nx+42))then
   if (y3+32>ny-41+16) and (y3+32<ny+42+16)
   or ((y3+1>ny-41+16) and (y3+ 1<ny+42+16)) then begin
   if nx <> y3 then begin ny := y3;
   nx := x3;
   y3 := 700;
   x3 := 700;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
   end;


end;
(****************************************************************************)
procedure inside2(var nx,x1,x2,x3,ny,y11,y2,y3,scores : integer);
begin
   if ((x1+25 >18+nx-45) and (x1+25 <18+nx+42))
   or ((x1+1 >18+nx-45) and (x1 +1 < 18+nx+42))then
   if (y11+32>ny-41+16) and (y11+32<ny+42+16)
   or ((y11+1>ny-41+16) and (y11+ 1<ny+42+16)) then begin
   if nx <> y11 then begin ny := y11;
   nx := x1;
   y11 := 700;
   x1 := 700;
   end;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);

   if ((x3+25 >18+nx-45) and (x3+25 <18+nx+42))
   or ((x3+1 >18+nx-45) and (x3 +1 < 18+nx+42))then
   if (y3+32>ny-41+16) and (y3+32<ny+42+16)
   or ((y3+1>ny-41+16) and (y3+ 1<ny+42+16)) then begin
   if nx <> y3 then begin ny := y3;
   nx := x3;
   y3 := 700;
   x3 := 700;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
   end;


end;
(****************************************************************************)
procedure inside3(var nx,x1,x2,x3,ny,y11,y2,y3,scores : integer);
begin
   if ((x1+25 >18+nx-45) and (x1+25 <18+nx+42))
   or ((x1+1 >18+nx-45) and (x1 +1 < 18+nx+42))then
   if (y11+32>ny-41+16) and (y11+32<ny+42+16)
   or ((y11+1>ny-41+16) and (y11+ 1<ny+42+16)) then begin
   if nx <> y11 then begin ny := y11;
   nx := x1;
   y11 := 700;
   x1 := 700;
   end;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);

   if ((x2+25 >18+nx-45) and (x2+25 <18+nx+42))
   or ((x2+1 >18+nx-45) and (x2 +1 < 18+nx+42))then
   if (y2+32>ny-41+16) and (y2+32<ny+42+16)
   or ((y2+1>ny-41+16) and (y2+ 1<ny+42+16)) then begin
   if nx <> y2 then begin ny := y2;
   nx := x2;
   y11 := 700;
   x1 := 700;
   end;
   explode1(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
   end;


end;

(****************************************************************************)
procedure bullres(var b,y1 : bu;var nx,ny : integer);
var
   dig : integer;
begin
for dig := 1 to 5 do
begin
     if (b[dig] > nx - 27) and (b[dig] < nx + 64) then begin
     if (y1[dig]> ny -32) and (y1[dig]< ny + 62) then begin
                                                       setcolor(0);
     line(b[dig]+1,y1[dig]+1,b[dig]+6,y1[dig]+1);
     b[dig]  := 35;
                                                       end;
     end;
     end;
end;
(****************************************************************************)
procedure g;                        (*INITS graph mode*)
  var grdriver,grmode,grerror:integer;
  begin
  grdriver:=detect;
  initgraph(grdriver,grmode,'c:\tp\bgi');
  grerror:=graphresult;
  if grerror<>grok then writeln('Graphics error: ',grapherrormsg(grerror));
  end;
(****************************************************************************)
procedure explode(var x,y,nx,x1,x2,x3:integer;var ny,y2,y3,y11:integer);
var ex:integer;
begin
for ex := 1 to 20 do begin        (*518*)
setcolor(4);
circle(nx+18,ny+16,ex+1);
delay(1);
circle(nx+18,ny+16,ex+1);
setcolor(12);
circle(nx+18,ny+16,ex*2);
delay(1);
circle(nx+18,ny+16,ex*2);
end;
setfillstyle(1,0);
bar(18+nx-45,ny-42+16,18 + nx+42,ny+42+16);


if ny = y3    then begin
                   inside2(nx,x1,x2,x3,ny,y11,y2,y3,scores);
                chy3(y3);
                 x3 := 600;
                 c3 := false;
                end;
if ny = y2 then begin
                inside2(nx,x1,x2,x3,ny,y11,y2,y3,scores);
                chy2(y2);
                x2 := 600;
                c2 := false;
                end;
if ny = y11    then begin
               inside3(nx,x1,x2,x3,ny,y11,y2,y3,scores);
                chy11(y11);
                 x1 := 600;
                 c1 := false;
                 end;
                                     setcolor(5);
     line(0,50,650,50);   (*Border*)
     line(0,450,650,450); (*Border*)
     score(scores,sc,scstr,lifevar,power);
(*end;*)
END;
(****************************************************************************)
procedure nothing(var nx,ny,x,y : integer;pi : pointer);
var
check : boolean;
j : bu;
rr : integer;
begin

      j[1] := getpixel (16,-2+y);
                  j[2] := getpixel (16,41+y);
                    j[3] := getpixel (36,13+y);  (*****)
                    j[4] := getpixel (36,25+y);
                    j[5] := getpixel (25,4+y);
                    j[6] := getpixel (25,34+y);

       for rr := 1 to 6 do
                    if (j[rr] <> 0) then check := true;
                    if check = true then begin
                       nx := 5;
                       ny := y+5;
                       explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                       setfillstyle(1,0);
                       putimage(10,200,pi^,xorput);
                       for rr := 1 to 6 do
                       j[rr] := 0;
                       reinit(x,y,x1,x2,x3,c,d,dis,dis1,dis3,on,c1,c2,c3,lifevar,b,y1);
                       end;

end;
(****************************************************************************)
procedure ship(var pi:pointer;var size : word;var x,y :integer);
begin
     setcolor(4);
     line(10,196+y,22,196+y);
     Line(11,195+y,18,195+y);
     line(12,194+y,17,194+y);
     line(11,193+y,16,193+y);
     line(10,192+y,15,192+y);
     line(10,191+y,15,191+y);
     setcolor(8);
     line(10,190+y,20,190+y);
     setcolor(4);
     line(10,189+y,13,189+y);
     line(10,197+y,24,197+y);
     line(10,198+y,32,198+y);
     line(10,199+y,24,199+y);
     line(10,200+y,23,200+Y);
     line(10,201+y,20,201+y);
     setcolor(4);
     setfillstyle(1,4);
     bar(10,202+y,30,214+y);
     setcolor(4);
              for z := 1 to 6 do
     circle(28,208+y,z);
     setcolor(4);
     line(10,219+y,24,219+y);
     line(10,218+y,32,218+y);
     line(10,217+y,24,217+y);
     line(10,216+y,23,216+y);
     line(10,215+y,20,215+y);
     line(11,220+y,22,220+y);
     Line(12,221+y,18,221+y);
     line(11,222+y,17,222+y);
     line(10,223+y,16,223+y);
     line(10,224+y,15,224+y);
     line(10,225+y,15,225+y);
     setcolor(8);
     line(10,226+y,20,226+y);
     setcolor(4);
     line(10,227+y,13,227+y);
size := imagesize(10,189,37,231);
getmem(pi,size);
getimage(10,189,37,231,pi^);
setfillstyle(1,0);
bar(10,189,37,231);
end;
(****************************************************************************)
procedure pause;  {allows player to pause the game}
begin
     setcolor(7);
       moveto(550,40);
     outtext('PAUSED');
     repeat
     until (readkey = 'p');
     fire := 'r';
     setfillstyle(1,0);
     bar(549,39,650,48);
end;
(****************************************************************************)
procedure bullets(var po : pointer;var s : word);
begin
setcolor(2);
line(40,206,45,206);
s := imagesize(39,205,46,207);            (*CREATES bullet image*)
getmem(po,s);
getimage(39,205,46,207,po^);
setcolor(0);
line(40,206,45,206);
end;
(****************************************************************************)
procedure bullet(var bull:string;var c : integer;var b : bu;var hit:hi;
                 var y1 :bu;var onofffire:string;var wh : integer);
var
ss,you : integer;
begin                                      (*WEAPON PROCEDURE for movement*)
    if bull = 'o' then begin
                        if b[c] < 36 then b[c] := 36;
                        if (b[c] > 37) and (bull = 'o') then begin
                                                             ss := b[c];
                                                             b[c] := 36;
                                                             setcolor(0);
                                            line(ss+1,y1[c]+1,ss+6,y1[c]+1);
                                               end;
                        y1[c] := y  + 17;
                        bull := 'r';
                        end;
if b[1] > 35 then begin
                  setcolor(0);
              if b[1] = 41 then line(b[1]-4,y1[1]+1,b[1]+3,y1[1]+1);
              if b[1] = 42 then putpixel(b[1]+1,y1[1]+1,0);
              b[1] := b[1] + 1;
              putimage(b[1],y1[1],po^,xorput);
              hit[1] := getpixel(b[1]+1,y1[1]+9);
              if hit[1] <> 0 then begin
                                  wh := 1;
                                  checking(b,y1,x1,x2,x3,y11,y2,y3,nx,ny,wh,scores);
                                  bullres(b,y1,nx,ny);
                                  explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                                  b[1] := 35;
                                  end;

              if b[1] = 600 then begin
                                 setcolor(0);
                                 line(600,y1[1]+1,606,y1[1]+1);
                                 b[1] := 35;
                                 end;

              end;
if b[2] > 35 then begin
                  setcolor(0);
              if b[2] = 41 then line(b[2]-4,y1[2]+1,b[2]+3,y1[2]+1);
              if b[2] = 42 then putpixel(b[2]+1,y1[2]+1,0);
              b[2] := b[2] + 1;
              putimage(b[2],y1[2],po^,xorput);

              hit[2] := getpixel(b[2]+1,y1[2]+9);
         if hit[2] <> 0 then begin
                                  wh := 2;
                                  checking(b,y1,x1,x2,x3,y11,y2,y3,nx,ny,wh,scores);
                                  bullres(b,y1,nx,ny);
                                  explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                                  b[2] := 35;
                                  end;

              if b[2] = 600 then begin
                                 setcolor(0);
                                 line(600,y1[2]+1,606,y1[2]+1);
                                 b[2] := 35;
                                 end;
              end;
if b[3] > 35 then begin
                  setcolor(0);
              if b[3] = 41 then line(b[3]-4,y1[3]+1,b[3]+3,y1[3]+1);
              if b[3] = 42 then putpixel(b[3]+1,y1[3]+1,0);
              b[3] := b[3] + 1;
              putimage(b[3],y1[3],po^,xorput);
              hit[3] := getpixel(b[3]+1,y1[3]+9);
                  if hit[3] <> 0 then begin
                                  wh := 3;
                                  checking(b,y1,x1,x2,x3,y11,y2,y3,nx,ny,wh,scores);
                                  bullres(b,y1,nx,ny);
                                  explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                                  b[3] := 35;
                                  end;
              if b[3] = 600 then begin
                                 setcolor(0);
                                 line(600,y1[3]+1,606,y1[3]+1);
                                 b[3] := 35;
                                 end;
              end;
if b[4] > 35 then begin

                  setcolor(0);
              if b[4] = 41 then line(b[4]-4,y1[4]+1,b[4]+3,y1[4]+1);
              if b[4] = 42 then putpixel(b[4]+1,y1[4]+1,0);
              b[4] := b[4] + 1;
              putimage(b[4],y1[4],po^,xorput);
              hit[4] := getpixel(b[4]+1,y1[4]+9);
    if hit[4] <> 0 then begin     wh := 4;
                                  checking(b,y1,x1,x2,x3,y11,y2,y3,nx,ny,wh,scores);
                                  bullres(b,y1,nx,ny);
                                  explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                                  b[4] := 35;

                                  end;

              if b[4] = 600 then begin
                                 setcolor(0);
                                 line(600,y1[4]+1,606,y1[4]+1);
                                 b[4] := 35;
                                 end;
              end;
if b[5] > 35 then begin

                  setcolor(0);
              if b[5] = 41 then line(b[5]-4,y1[5]+1,b[5]+3,y1[5]+1);
              if b[5] = 42 then putpixel(b[5]+1,y1[5]+1,0);
              b[5] := b[5] + 1;
              putimage(b[5],y1[5],po^,xorput);
              hit[5] := getpixel(b[5]+1,y1[5]+9);
    if hit[5] <> 0 then begin
                                  wh:= 5;
                                  checking(b,y1,x1,x2,x3,y11,y2,y3,nx,ny,wh,scores);
                                  bullres(b,y1,nx,ny);
                                  explode(x,y,nx,x1,x2,x3,ny,y2,y3,y11);
                                  b[5] := 35;
                                  end;
              if b[5] = 600 then begin
                                 setcolor(0);
                                 line(600,y1[5]+1,606,y1[5]+1);
                                 b[5] := 35;
                                 end;
              end;

               bull := 'r';

end;
(****************************************************************************)
procedure action(var fire : string;var bull : string; var c : integer
                 ;var sc : integer);
               (*MAKES actions occur for ship*)
begin

if fire = 'P' then begin          (*down*)
                    y := y + 3;
                     putimage(x,y-3,pi^,xorput);
                    if y = 413 then begin
                                    y := 410;
                                    fire := 'r';
                                    end;

                    putimage(x,y,pi^,xorput);

                    end;

if fire = 'H' then begin    (*up*)
                    y := y - 3;
                    putimage(x,y+3,pi^,xorput);
                    if y = 50 then begin
                                    y := 53;
                                    fire := 'r'
                                    end;

                    putimage(x,y,pi^,xorput);

                 end;
if fire = 'g' then begin         (*fires bullets*)
                   bull := 'o';
                   fire := 'r';
                   if c = 5 then c := 0;
                   c := c + 1;
                   end;
nothing(nx,ny,x,y,pi);
end;
(****************************************************************************)
procedure savepic ( var p:pointer; var pn:pointer);
var z:integer;
begin
setcolor(1);
for z :=  1 to 8 do
circle(301,300, z);
setfillstyle(1,1);
bar(303,308,299,314);
bar(303,286,299,292);
arc(301,300,55,125,15);
arc(301,300,235,305,15);
setfillstyle(1,0);

size:=imagesize(285,285,310,317); {Gets the size of a rectangler image}
getmem(p,size);               {Finds a memory location of size(size)
                                and points at location P}
getimage(285,285,310,317,p^); {Places all pixle data into the loaction pointed
                          to by the pointer P.}
bar(285,285,310,317);
setcolor(9);
for z :=  1 to 8 do
circle(301,300, z);
setfillstyle(1,9);
bar(303,308,299,314);
bar(303,286,299,292);
arc(301,300,55,125,15);
arc(301,300,235,305,15);


getmem(pn,size);
getimage(285,285,310,317,pn^);
putimage(285,285,pn^,xorput);
setcolor(8);
for z :=  1 to 8 do
circle(301,300, z);
setfillstyle(1,8);
bar(303,308,299,314);
bar(303,286,299,292);
arc(301,300,55,125,15);
arc(301,300,235,305,15);
getmem(pt,size);
getimage(285,285,310,317,pt^);
putimage(285,285,pt^,xorput);
end;
(****************************************************************************)
procedure enem1(var dis1:integer;var control1: boolean;var p:pointer; var x1:integer;
               var y11:integer;var c1 : boolean);

var loc:integer;
   w:integer;
begin

randomize;
 w := random(10) + 1;

 if c1 = true then putimage(x1,y11,p^,xorput);
 c1 := true;
 if control1 = false then loc := - 2
                            else loc := 2;
 y11 := y11 + loc;
 x1 := x1 - dis1;
 case w of
    (* 1 : fires back*)
     2 : if control1 = true then control1 := false
                           else if control1 = false then control1 := true;
     3 : if control1 = true then control1 := false
                           else if control1 = false then control1 := true;
     4 : if dis1 = 6 then dis1 := 2
                    else if dis1 = 2 then dis1 := 6;
     5 : if dis1 = 2 then dis1 := 0;
     6 : if dis1 = 0 then dis1 := 2;
     7 : if dis1 = 6 then dis1 := 2;
     8 : if dis1 = 2 then dis1 := 0;
     9 : if dis1 = 0 then dis1 := 2;
     10: if dis1 = 6 then dis1 := 2;
  end;
  if loc + y11 < 50 then begin
                         control1 := true;
                         y11 := 54;
                         end;

  if loc + y11 > 410 then begin
                          control1 := false;
                          y11 := 406;
                          end;
  if x1 < 0  then begin
                     x1 := 600;
                     chy11(y11);
                     end;
     putimage(x1,y11 ,p^,xorput);
end;
(****************************************************************************)
procedure enem2(var dis: integer;var control : boolean; var pn:pointer;
                var x2:integer; var y2:integer;var c2 : boolean);
var
   w:integer;
   loca: integer;
begin

randomize;
 w := random(10) + 1;

 if c2 = true then putimage(x2,y2,pn^,xorput);
 c2 := true;
 if control = false then loca := - 2
                            else loca := 2;
 y2 := y2 + loca;
 x2 := x2 - dis;
 case w of
    (* 1 : fires back*)
     2 : if control = true then control := false
                           else if control = false then control := true;
     3 : if control = true then control := false
                           else if control = false then control := true;
     4 : if dis = 6 then dis := 2
                    else if dis = 2 then dis := 6;
     5 : if dis = 2 then dis := 0;
     6 : if dis = 0 then dis := 2;
     7 : if dis = 6 then dis := 2;
     8 : if dis = 2 then dis := 0;
     9 : if dis = 0 then dis := 2;
     10: if dis = 6 then dis := 2;
  end;
  if loca + y2 < 50 then begin
                        y2 := 54;
                        control := true;
                        end;
  if loca + y2 > 410 then begin
                         y2 := 406;
                         control := false;
                         end;
  if x2 < 0  then begin
                     x2 := 600;
                     chy2(y2);
                     end;
     putimage(x2,y2 ,pn^,xorput);
end;
(****************************************************************************)
procedure enem3(var dis3: integer;var control3 : boolean; var pt:pointer;
                var x3,y3:integer;var c3 : boolean);
var
   f:integer;
   locb: integer;
begin

randomize;
 f := random(10) + 1;

 if c3 = true then putimage(x3,y3,pt^,xorput);
 c3 := true;
 if control3 = false then locb := - 2
                            else locb := 2;
 y3 := y3 + locb;
 x3 := x3 - dis3;
 case f of
    (* 1 : fires back*)
     2 : if control3 = true then control3 := false
                           else if control3 = false then control3 := true;
     3 : if control3 = true then control3 := false
                           else if control3 = false then control3 := true;
     4 : if dis3 = 6 then dis3 := 2
                    else if dis3 = 2 then dis3 := 6;
     5 : if dis3 = 2 then dis3 := 0;
     6 : if dis3 = 0 then dis3 := 2;
     7 : if dis3 = 6 then dis3 := 2;
     8 : if dis3 = 2 then dis3 := 0;
     9 : if dis3 = 0 then dis3 := 2;
     10: if dis3 = 6 then dis3 := 2;
  end;
  if locb + y3 < 50 then begin
                        y3 := 54;
                        control3 := true;
                        end;
  if locb + y3 > 410 then begin
                         y3 := 406;
                         control3 := false;
                         end;
  if x3 < 0  then begin
                     x3 := 600;
                     chy3(y3);
                     end;
     putimage(x3,y3 ,pt^,xorput);
end;
(****************************************************************************)
procedure menus;
begin
putimage(200,208,ap^,xorput);
moveto(170,100);
setcolor(10);
settextstyle(3,0,7);
outtext('MAIN MENU');
settextstyle(2,0,6);
moveto(225,200);
outtext('1 - Play the Game');
moveto(225,225);
outtext('2 - Read the story');
moveto(225,250);
outtext('3 - How to play');
moveto(225,275);
outtext('4 - Quit');
setcolor(3);
moveto(25,300);
outtext('Use the up and down arrow keys to move the yellow indicator.');
moveto(10,325);
outtext('When the indicator is next to the selection you want press ENTER.');
xx := 200;
yy := 208;

end;
(****************************************************************************)
procedure instructions(var power : boolean);
var
   bbb : char;
begin
     cleardevice;
     settextstyle(0,0,0);
     moveto (245,5);
     outtext('INSTRUCTIONS');
     moveto(1,50);
     outtext('How to Play:');
     moveto(26,70);
     outtext('To control the ship press the up and down arrow keys.');
     moveto(26,80);
     outtext('To fire press the key ''g''.');
     moveto(26,90);
     outtext('To leave the game press ''q''.');
     moveto(26,100);
     outtext('To pause the game press ''p''.');
     moveto(26,110);
     outtext('You start with three lives');
     moveto(1,150);
     outtext('This is your ship.');
     putimage(50,180,pi^,xorput);
     moveto(1,230);
     outtext('These are the enemy ships');
     putimage(50,260,p^,xorput);
     putimage(130,260,pn^,xorput);
     putimage(210,260,pt^,xorput);
     setcolor(3);
     moveto(45,305);
     outtext('100pts');
     moveto(125,305);
     outtext('100pts');
     moveto(205,305);
     outtext('200pts');
     moveto(1,340);
     outtext('Watch out these guys move fast and if they explode to close,');
     moveto(26,350);
     OUTTEXT('You do to.');
     moveto(1,400);
     outtext('You only have three lives to start out with and gain one every');
     moveto(1,410);
     outtext('5,000 points');

     bbb := readkey;
     if bbb = 't' then power := true;
     if bbb = 'f' then power := false;
     putimage(50,180,pi^,xorput);
     putimage(50,260,p^,xorput);
     putimage(130,260,pn^,xorput);
     putimage(210,260,pn^,xorput);

end;
(**************************************INTRO*****************************)

procedure intro;
var xxxx,ex:integer;
begin
cleardevice;
setcolor(1);
settextstyle(10,0,8);
outtext('G');
delay(475);
outtext('U');
delay(475);
outtext('N');
delay(475);
outtext('S');
delay(475);
outtext('T');
delay(475);
outtext('A');
delay(475);
outtext('R');

settextstyle(2,0,8);
moveto(200,250);
setcolor(10);
outtext('By:');
moveto(240,250);
outtext('John Clark');
moveto(270,275);
outtext('  &');
moveto(240,300);
outtext('Chris LaBove');

putimage(0,380,p^,xorput);
putimage(19,400,pt^,xorput);
putimage(0,420,pn^,xorput);

for xxxx := 1 to 700 do begin
    delay(2);
    putimage(xxxx-1,380,p^,xorput);
    putimage(xxxx,380,p^,xorput);
    putimage(xxxx+18,400,pt^,xorput);
    putimage(xxxx+19,400,pt^,xorput);
    putimage(xxxx-1,420,pn^,xorput);
    putimage(xxxx,420,pn^,xorput);
end;
delay(500);
for ex := 1 to 300 do begin        (*518*)
    setcolor(4);
    circle(320,250,ex+1);
    delay(0);
    circle(320,250,ex+1);
    setcolor(12);
    circle(320,250,ex*2);
    delay(0);
    circle(320,250,ex*2);
    end;
cleardevice;
end;
(****************************************************************************)
begin
g;     (*initalizes graph*)
savearrow(ap);
ship(pi,size,x,y);  (*ship image*)
bullets(po,s);   (*bullet image*)
savepic(p,pn);
intro;
repeat
settextstyle(3,0,7);
menus;
repeat

ffff := readkey;
if ffff = 'P' then begin          (*down*)
                    putimage(xx,yy,ap^,xorput);
                    yy := yy + 25;
                    if yy > 283 then yy := 208;
                    putimage(xx,yy,ap^,xorput);
                    end;

if ffff = 'H' then begin    (*up*)
                    putimage(xx,yy,ap^,xorput);
                    yy := yy - 25;
                    if yy < 208 then yy := 283;
                    putimage(xx,yy,ap^,xorput);
                    end;
start := false;
qq := ord(ffff);
if qq = 13 then begin
           zz := yy;
           case zz of
              208 :begin
                   start := true;
                   out := true;
                   end;
              233 :begin
                   cleardevice;
                   story;
                   cleardevice;
                   menus;
                   end;
              258 :begin
                   instructions(power);
                   cleardevice;
                   menus;
                   end;
              283 : begin
                    start := false;
                    ina := true;
                    out := true;
                    end;
              {233 then story;  }
              end;
           end;
until (out = true);

out := false;










settextstyle(0,0,0);
if start = true then begin
x := 0;       (*INIT vars*)
y := 0;
cleardevice;
chy2(y2);
c := 0;
lifevar := 3;
d := 0;
sc := 1;
dis := 2;
dis1 := 2;
v := 0;
x := 10;    (*2nd INIT*)
y := 200;
   setcolor(5);
     line(0,50,650,50);   (*Border*)
     line(0,450,650,450); (*Border*)
on := FALSE;
lives(lifevar,life,outofgame);
score(scores,sc,scstr,lifevar,power);
x1 := 620;
x2:= 770;
x3 := 920;
repeat   (*play LOOP*)
if keypressed then fire := readkey;
if on = false then begin
                   putimage(x,y,pi^,xorput); (*Trashes first image*)
                   on := true;
                   end;
(*if the shiphit then lives(lifevar,life);*)
inc(v);
d := d + 1;
if d = 2 then d := 0;
bullet(bull,c,b,hit,y1,onofffire,wh);
action(fire,bull,c,sc);(*MOVEMENT*)
if d = 1 then enem1(dis1,control1,p,x1,y11,c1);
if d = 0 then enem2(dis,control,pn,x2,y2,c2);
if d = 0 then enem3(dis3,control3,pt,x3,y3,c3);
if x3 > 800 then delay(1);
if x2 > 700 then delay(2);

if fire = 'p' then pause;(*simple BREAK in program*)
until ((fire = 'q') or (outofgame = true)); (*QUITS WHEN "Q" pressed*)
end;
fire := 'r';
if outofgame = true then gmovr;
outofgame := false;
scores := 0;
lifevar := 3;
delay(1000);
cleardevice;
until (ina = true);
closegraph;
end.