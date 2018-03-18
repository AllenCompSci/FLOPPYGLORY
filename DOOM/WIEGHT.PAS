Program wieght;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
weight,moon,jupiter,mars,venus:real;
procedure moonp (var moon:real;
                weight:real);
begin
moon:=weight*0.16;
end;
procedure jupiterp (var jupiter:real;
                   weight:real);
begin
jupiter:=weight*2.64;
end;
procedure marsp (var mars:real;
                weight:real);
begin
mars:=weight*0.38;
end;
procedure venusp (var venus:real;
                 weight:real);
begin
venus:=weight*0.85;
end;
begin (*main*)
clrscr;
writeln ('It''s time to find your weight on other planets!!Input your weight');
readln (weight);
moonp (moon,
      weight);
jupiterp (jupiter,
         weight);
marsp (mars,
      weight);
venusp (venus,
       weight);
writeln ('Earth:',weight:2:2);
writeln ('Moon:',moon:2:2);
writeln ('Venus:',venus:2:2);
writeln ('Mars:',mars:2:2);
writeln ('Jupiter:',jupiter:2:2);
readln;
End. (*main*)

