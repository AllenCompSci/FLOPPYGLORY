Program intials;
(*El CHoDA
Baker 6th, *)

uses
    graph;
var
grdriver,grmode,grerror:integer;
x,y,a,b,c,d:integer;
a1,b1,c1,d1:integer;
begin (*main*)
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
cleardevice;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
setbkcolor(2);
setpalette (2,Red);
setcolor(2);
a:=100;
c:=130;
b:=100;
d:=200;
bar(a,b,c,d);
a:=130;
b:=100;
c:=170;
d:=130;
bar(a,b,c,d);
a:=130;
b:=170;
c:=170;
d:=200;
bar(a,b,c,d);
a:=220;
b:=100;
c:=250;
d:=200;
bar(a,b,c,d);
a:=250;
b:=170;
c:=300;
d:=200;
bar(a,b,c,d);
a:=320;
b:=100;
c:=410;
d:=130;
bar(a,b,c,d);
a:=350;
b:=130;
c:=380;
d:=200;
bar(a,b,c,d);

readln;
closegraph;
end;


End. (*main*)

