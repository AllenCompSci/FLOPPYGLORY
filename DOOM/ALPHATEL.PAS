Program alphatel;
(*El CHoDA
Baker 6th, *)

uses
    Crt;
var
letters,holder:string;
a,b,c,d,e,f,g:string;
counter:char;
a1,b1,c1,d1,e1,f1,g1:integer;
begin (*main*)
clrscr;
writeln ('Enter in your alpha number(please type in lower case)');
readln (letters);
holder:=letters;
delete (letters,2,6);
a:=letters;
letters:=holder;
delete (letters,1,1);
delete (letters, 2,6);
b:=letters;
letters:=holder;
delete (letters,1,2);
delete (letters,2,7);
c:=letters;
letters:=holder;
delete (letters,1,3);
delete (letters,2,3);
d:=letters;
letters:=holder;
delete (letters, 1,4);
delete (letters, 2,2);
e:=letters;
letters:=holder;
delete (letters,1,5);
delete (letters,2,1);
f:=letters;
letters:=holder;
delete (letters,1,6);
g:=letters;


case a[1] of
'a','b','c':a1:=2;
'd','e','f':a1:=3;
'g','h','i':a1:=4;
'j','k','l':a1:=5;
'm','n','o':a1:=6;
'p','r','s':a1:=7;
't','u','v':a1:=8;
'w','x','y':a1:=9;
end;
case b[1] of
'a','b','c':b1:=2;
'd','e','f':b1:=3;
'g','h','i':b1:=4;
'j','k','l':b1:=5;
'm','n','o':b1:=6;
'p','r','s':b1:=7;
't','u','v':b1:=8;
'w','x','y':b1:=9;
else;
end;
case c[1] of
'a','b','c':c1:=2;
'd','e','f':c1:=3;
'g','h','i':c1:=4;
'j','k','l':c1:=5;
'm','n','o':c1:=6;
'p','r','s':c1:=7;
't','u','v':c1:=8;
'w','x','y':c1:=9;
else;
end;
case d[1] of
'a','b','c':d1:=2;
'd','e','f':d1:=3;
'g','h','i':d1:=4;
'j','k','l':d1:=5;
'm','n','o':d1:=6;
'p','r','s':d1:=7;
't','u','v':d1:=8;
'w','x','y':d1:=9;
else;
end;
case e[1] of
'a','b','c':e1:=2;
'd','e','f':e1:=3;
'g','h','i':e1:=4;
'j','k','l':e1:=5;
'm','n','o':e1:=6;
'p','r','s':e1:=7;
't','u','v':e1:=8;
'w','x','y':e1:=9;
else;
end;
case f[1] of
'a','b','c':f1:=2;
'd','e','f':f1:=3;
'g','h','i':f1:=4;
'j','k','l':f1:=5;
'm','n','o':f1:=6;
'p','r','s':f1:=7;
't','u','v':f1:=8;
'w','x','y':f1:=9;
else;
end;
case g[1] of
'a','b','c':g1:=2;
'd','e','f':g1:=3;
'g','h','i':g1:=4;
'j','k','l':g1:=5;
'm','n','o':g1:=6;
'p','r','s':g1:=7;
't','u','v':g1:=8;
'w','x','y':g1:=9;
else;
end;
writeln (a1,b1,c1,'-',d1,e1,f1,g1);
readln;
End. (*main*)

