Program calories;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
const
     a=2.3;
     b=15.0;
     c=1.7;
begin (*main*)
clrscr;
writeln ('ACTIVITY':12,'15 MINUTES':12,'30 MINUTES':12,'60 MINUTES':12);
writeln ('SLEEPING':12, a*15:12:2, b*15:12:2, c*15:12:2);
writeln ('JOGGING':12, a*30:12:2, b*30:12:2, c*30:12:2);
writeln ('SITTING':12, a*60:12:2, b*60:12:2, c*60:12:2);
writeln ('PRESS ENTER TO CONTINUE');
READLN;
End. (*main*)

