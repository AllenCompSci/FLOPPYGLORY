program sheep_1; (*Melissa Clements 3rd Mr. Baker*)
uses
 Crt,graph;
var
 grdriver : integer;
 grmode : integer;
 grerror : integer;
{****************************************************************************}
procedure sheeps;
 begin
  putpixel (2,11,15);
  putpixel (2,12,15);
  putpixel (3,11,15);
  putpixel (3,12,15);
  line (4,13,4,20);
  line (4,23,4,26);
  line (5,13,5,20);
  line (5,23,5,26);
  line (6,11,6,28);
  line (7,11,7,28);
  line (8,11,8,34);
  line (9,11,9,34);
  line (10,11,10,28);
  line (11,11,11,28);
  line (12,11,12,34);
  line (13,11,13,34);
  line (14,11,14,28);
  line (15,11,15,28);
  line (16,11,16,28);
  line (17,12,17,27);
  line (18,13,18,26);
  line (19,13,19,26);
  line (20,12,20,27);
  line (21,11,21,28);
  line (22,11,22,28);
  line (23,11,23,28);
  line (24,11,24,34);
  line (25,11,25,34);
  line (26,11,26,28);
  line (27,11,27,28);
  line (28,11,28,34);
  line (29,11,29,34);
  line (30,10,30,28);
  line (31,8,31,28);
  line (32,8,32,28);
  line (33,7,33,28);
  line (34,7,34,20);
  line (34,23,34,26);
  line (35,7,35,20);
  line (35,23,35,26);
  line (36,7,36,14);
  line (37,8,37,13);
  line (38,8,38,13);
  line (39,9,39,12);
 end;
{****************************************************************************}
procedure pacman(var a,b:integer);
 begin
  {rectangle (1,1,40,40);}
  setfillstyle (solidfill,14);
  setcolor (14);
  fillellipse (a+21,b+21,19,19);
  setfillstyle (solidfill,0);
  setcolor (0);
  pieslice (a+21,b+21,a+25,0,19);
  setfillstyle (solidfill,0);
  setcolor (0);
  fillellipse (a+15,b+10,2,2);

 end;
{****************************************************************************}
begin
 grdriver := detect;
 initgraph (grdriver,grmode,'c:\tp\bgi');
 grerror := graphresult;
 if grerror <> grok
  then writeln ('Graphics error:   ',grapherrormsg (grerror))
 else
  begin
   pacman;
  end;
 readln;
 closegraph;
end.
