Program shell;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
socail:string;
begin (*main*)
clrscr;
writeln ('What is your social security number(no dashes, all nine numbers)');
readln (socail);
insert ('-',socail,6);
insert ('-',socail,4);
writeln (socail);
readln;


End. (*main*)

