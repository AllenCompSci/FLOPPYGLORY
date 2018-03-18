program graphshell;
(*program by aaron evans*)
(*date due *)
(*date due *)
(*for Mr. Baker*)
uses
graph,crt;
type
file_rec=record
tree:string;
num:integer;
end;
name_file=file of file_rec;
var
x,Y,loop,position,i,grdriver,grmode,grerror:integer;
treefil:name_file;
tree_rec:file_rec;
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
assign(treefil,'a:\trees.dat');
gdrive(grdriver,grmode,grerror);
reset(treefil);
x:=filesize(treefil);

for y:=1 to x  do begin
read(treefil,tree_rec);
with tree_rec do
begin
outtextxy(1,y*10,tree);
end;
readln;
end;

closegraph;
end.(*main*)

























































































































































































































































































































