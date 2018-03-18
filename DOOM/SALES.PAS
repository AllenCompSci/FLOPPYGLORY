Program sales;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
const
     a=35.00;
     b=28.50;
     c=22.95;
     d=12.25;
var
   w,x,y,z:real;
   h,i,j,k:real;

begin (*main*)
clrscr;
writeln ('Current costs of prices are:');
writeln ('sweater':10,'skirt':10,'blouse':10,'braclet':10);
writeln (a:10:2, b:10:2, c:10:2, d:10:2);
writeln ('Sales prices are:');
writeln ('sweater':10,'skirt':10,'blouse':10,'braclet':10);
w:=a*0.15; x:=b*0.15; y:=c*0.15;
h:=a-w; i:=b-x; j:=c-y;
writeln (h:10:2, i:10:2, j:10:2, d:10:2);
writeln ('Press enter to continue');
readln;

End. (*main*)

