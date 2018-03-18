Program class1;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type

    class_type = (Freshman,Sophmore,Junior,Senior);

var
   class:class_type;
   a:string;
   y,z:integer;
begin (*main*)
clrscr;
writeln ('May I have your name please?');
readln (a);
writeln ('Type in your grade status.');
writeln ('1)Freshman');
writeln ('2)Sophmore');
writeln ('3)Junior');
writeln ('4)Senior');
readln (z);
case z of
1:begin
class:=freshman;
y:=2000;
end;
2:begin
class:=sophmore;
y:=1999;
end;
3:begin
class:=junior;
y:=1998;
end;
4:begin
class:=senior;
y:=1997;
end;
end;
if class<junior then
writeln (a, ' is a lower classman that will graduate in ', y)
else
writeln (a, ' is an upper classman that will graduate in ', y);

readln;
End. (*main*)

