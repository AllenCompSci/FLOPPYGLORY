Program fle;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
type
c3po=file of integer;
var
luke,leia:c3po;
x:integer;
choda:char;
begin (*main*)
clrscr;
assign (luke,'A:luke.dat');
rewrite(luke);
assign (leia,'A:leia.dat');
rewrite (leia);
repeat
writeln ('Enter in the number');
readln (x);
write (luke,x);
writeln ('Enter in the other number');
readln (x);
write (leia,x);
writeln ('Do you wish to continue(y or n)');
readln (choda);
until choda='n';
close(luke);
close(leia);
End. (*main*)

