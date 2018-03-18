Program gshell;
(*El CHoDA
Baker 6th, *)

uses
    graph;
var
grdriver,grmode,grerror:integer;
begin (*main*)
cleardevice;
grdriver:=detect;
initgraph (grdriver,grmode,'c:\tp\bgi');
grerror:=graphresult;
if grerror<>grOk
then writeln ('Graphics Error:',grapherrormsg (grerror))
else
begin
end;


End. (*main*)

