Program stock;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
a,b,c,d,e,error_postion,s,m:integer;
leestupid,holder,luke:string;
begin (*main*)
clrscr;
writeln ('Input stock number');
readln (leestupid);
holder:=leestupid;
delete (leestupid,1,2);
delete (leestupid,4,1);
luke:=leestupid;
delete (leestupid,2,4);
val (leestupid, a, error_postion);
leestupid:=luke;
delete (leestupid,1,1);
delete (leestupid,2,3);
val (leestupid, b, error_postion);
leestupid:=luke;
delete (leestupid,1,2);
delete (leestupid,2,4);
val (leestupid, c, error_postion);
leestupid:=luke;
delete (leestupid,1,3);
delete (leestupid,2,4);
val (leestupid, d, error_postion);
leestupid:=luke;
delete (leestupid,1,4);
val (leestupid, e, error_postion);
s:=a+b+c;
m:=d+e;
if s=m then
writeln (holder,' is a real stock')
else
writeln (holder,' is not a real stock');
readln;
End. (*main*)

