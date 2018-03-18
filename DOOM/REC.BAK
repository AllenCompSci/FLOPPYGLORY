Program gshell;
(*El CHoDA
Baker 6th, *)

uses
    graph;
var
grdriver,grmode,grerror:integer;
begin (*main*)
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
cleardevice;
rectangle (60,60,120,120);
rectangle (70,70,110,110);
rectangle (80,80,100,100);
readln;
closegraph;
end;


End. (*main*)

