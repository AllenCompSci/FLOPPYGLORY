program graphshell;
(*program by aaron evans*)
(*date due *)
(*date due *)
(*for Mr. Baker*)
uses
graph;
var
x,Y,position,grdriver,grmode,grerror:integer;
{***************************************************************************}
procedure gdrive(Var Grdriver,grmode,grerror:integer);
begin
Grdriver:=detect;
initgraph(grdriver,grmode,'c:\tp\bgi\');
grerror:=graphresult;
if grerror<>grok then
writeln('Graphics error:',Grapherrormsg(grerror));
end;
{***************************************************************************}
begin(*main*)
gdrive(grdriver,grmode,grerror);
x:=getMaxx;
for position:=X DOWNto 1 do
PUTPIXEL(X-POSITION,POSITION-500 ,RED);
X:=GETMAXX;
Y:=GETMAXY;
FOR POSITION:=1 TO 285 DO
PUTPIXEL(POSITION,POSITION-140,RED);
FOR POSITION:=1 TO X-500 DO
PUTPIXEL(POSITION+70,X-570,RED);
FOR POSITION:=1 TO X-410 DO
PUTPIXEL(POSITION+60,X-400,RED);
FOR POSITION:=X-90 DOWNTO 60 DO
PUTPIXEL(60,POSITION+180,RED);
FOR POSITION:=1 TO X-500 DO
PUTPIXEL(POSITION+60,X-300,RED);
FOR POSITION:=1 TO X-397 DO
PUTPIXEL(POSITION+60,X-160,RED);
LINE(0,0,X,0);
LINE(0,X,0,0);
LINE(X,0,X,X);
LINE(0,Y,X,Y);
readln;
closegraph;
end.(*main*)

























































































































































































































































































































