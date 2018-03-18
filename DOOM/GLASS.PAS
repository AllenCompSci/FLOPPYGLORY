Program glass;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
l,w:integer;
atotal,ptotal,acost,pcost,cost:real;
procedure area (l,w:integer;
               var atotal,acost:real);
begin
atotal:=l*w;
acost:=atotal*0.02;
end;
procedure perimeter (l,w:integer;
                    var ptotal,pcost:real);
begin
ptotal:=(l+l+w+w)/12;
pcost:=ptotal*1.45;
end;
begin (*main*)
clrscr;
writeln ('Input the length of the picture');
readln (l);
writeln ('Input the width of the picture');
readln (w);
area (l,w,atotal,acost);
perimeter (l,w,ptotal,pcost);
cost:=acost+pcost;
writeln ('The cost for the glass will be:',acost:2:2);
writeln ('The cost of the frame will be:',pcost:2:2);
writeln ('The cost for the entire thing will be:',cost:2:2);
readln;

End. (*main*)

