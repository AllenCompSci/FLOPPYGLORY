Program areacode;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
junk:string;
begin (*main*)
clrscr;
writeln ('Enter your phone number and area code, enter your dashes,');
writeln ('and do not put a one at the beginning');
readln (junk);
delete (junk,1,4);
writeln (junk);
readln;
End. (*main*)

