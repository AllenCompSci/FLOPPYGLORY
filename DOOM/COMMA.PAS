Program commas;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
x,error_postion:integer;
strng,keeper:string;
begin (*main*)
clrscr;
writeln ('Input a number no larger than 99,999');
readln (x);
str (x:5, strng);
keeper:=strng;
if (x>999) and (x<10000) then
begin
strng:=keeper;
insert (',', keeper, 3);
end;
if x>9999 then
insert (',', keeper, 3);
writeln (keeper);
readln;

End. (*main*)

