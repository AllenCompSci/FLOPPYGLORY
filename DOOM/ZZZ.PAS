Program zzz;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
 a:integer;
 z:string;
begin (*main*)
clrscr;
writeln ('Dr. CHoDA''s self-help problem');
writeln ('Please enter a name');
readln (z);
repeat
begin
writeln (z,' is a super person!');
writeln ('Enter an additional name.(enter zzz to quit)');
readln (z);
end;
until z='zzz';

End. (*main*)

