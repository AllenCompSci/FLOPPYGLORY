Program gshell;
(*El CHoDA
Baker 6th, *)

uses
    graph;
var
x,grdriver,grmode,grerror:integer;
y:string;
begin (*main*)
x:=random(6)+1;
str (x:1,y);
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
cleardevice;
setbkcolor (0);
outtext(y);
case x of
1:begin
rectangle (50,50,100,100);
putpixel (75,75,white);
end;
2:begin
rectangle (50,50,100,100);
putpixel (60,60,white);
putpixel (90,90,white);
end;
3:begin
rectangle (50,50,100,100);
putpixel (60,60,white);
putpixel (90,90,white);
putpixel (75,75,white);
end;
4:begin
rectangle (50,50,100,100);
putpixel (60,60,white);
putpixel (90,90,white);
putpixel (60,90,white);
putpixel (90,60,white);
end;
5:begin
rectangle (50,50,100,100);
putpixel (60,60,white);
putpixel (90,90,white);
putpixel (60,90,white);
putpixel (90,60,white);
putpixel (75,75,white);
end;
6:begin
rectangle (50,50,100,100);
putpixel (60,60,white);
putpixel (90,90,white);
putpixel (60,90,white);
putpixel (90,60,white);
putpixel (60,75,white);
putpixel (90,75,white);
end;
end;
readln;
end;


End. (*main*)

