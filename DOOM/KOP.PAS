Program kop;
(*El CHoDA
Baker 6th, *)

uses
    Crt;

var
choda:text;
begin (*main*)
clrscr;
assign (choda,'a:/fred.dat');
rewrite (choda);
writeln (choda,'I like traffic lights');
writeln (choda,'I like traffic lights');
writeln (choda,'I like traffic lights');
writeln (choda,'But only when thier green');
writeln (choda,'I like traffic lights');
writeln (choda,'I like traffic lights');
writeln (choda,'I like traffic lights');
writeln (choda,'but not when they are red');
close (choda);

End. (*main*)


