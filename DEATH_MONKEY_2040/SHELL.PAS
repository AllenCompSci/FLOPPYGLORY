program shell;
(*program by aaron evans*)
(*date due *)
(*date due *)
(*for Mr. Baker*)
uses
crt;

VAR
C1,C2,C3:TEXT;
LOOP,Y:INTEGER;
begin(*main*)
clrscr;
ASSIGN(C1,'A:\C1.DAT');
RESET(C1);
FOR LOOP:=1 TO 10 DO
WRITE(C1,LOOP);
ASSIGN(C2'A:\C2.DAT');
RESET(C1);
FOR LOOP:=11 TO 20 DO
WRITE(C2,LOOP);
ASSIGN(C3'A:\C3.DAT');
Y:=FILESIZE(





readln;
end.(*main*)
