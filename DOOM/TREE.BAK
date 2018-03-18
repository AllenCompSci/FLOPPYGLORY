Program trees;
(*El CHoDA
Baker 6th, *)

uses
    graph;
type
tree=record
name:string;
amount:integer;
end;
stuff=file of tree;
var
error_postion,x,y,b,grdriver,grmode,grerror:integer;
gdog:tree;
franknbean:stuff;
countchocula,a:string;
z:real;
begin (*main*)
assign (franknbean,'c:\trees.dat');
reset (franknbean);
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
cleardevice;
outtext ('Welcome to the wonderful world of trees');
x:=filesize (franknbean);
for y:=1 to x do
begin
read (franknbean,gdog);
outtextxy (1,y*20,gdog.name);
z:=gdog.amount/10;
z:=round(z);
str(z:2,a);
val(a,b,error_postion);
delete (a,error_postion,5);
val(a,b,error_postion);
(*b:=gdog.amount;*)
moveto (170,y*20);

lineto (b+200,y*20);
end;
readln;
end;
readln;
close (franknbean);
CloseGraph;
End. (*main*)

