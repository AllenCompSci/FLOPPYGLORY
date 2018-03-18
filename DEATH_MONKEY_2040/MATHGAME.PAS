program MATHGAME;
uses
crt;
var
NAME,GAME,PREF1:STRING;
AGE,CNUM,NEWNUM,NUM1,NUM2,CHOICE:INTEGER;
PROCEDURE STARTER(VAR GAME,NAME:STRING;VAR AGE:INTEGER);
BEGIN
CLRSCR;
writeln('WHAT IS YOUR NAME?');
READLN(NAME);
WRITELN('HOW OLD ARE YOU?');
READLN(AGE);
CLRSCR;
WRITELN('DO YOU WANT TO PLAY THE MATH GAME? (YES OR NO)');

READLN(GAME);


END;
{***************************************************************************}
PROCEDURE PLAY(VAR PREF1:STRING;VAR CHOICE:INTEGER);
BEGIN
CLRSCR;
WRITELN('DO YOU WANT THE GAME HARD OR EASY? (HARD OR EASY)');
READLN(PREF1);
IF PREF1='EASY' THEN
CHOICE:=10
ELSE
CHOICE:=100;
END;
{****************************************************************************}
PROCEDURE NCOICE(VAR CNUM,NEWNUM,NUM1,NUM2,CHOICE:INTEGER);
BEGIN
NUM1:=RANDOM(CHOICE);
NUM2:=RANDOM(CHOICE);
REPEAT
WRITE(NUM1,' + ');
WRITE(NUM2,' = ');
TEXTCOLOR(17);
WRITE('* ');

TEXTCOLOR(7);
READLN(NEWNUM);
CNUM:=NUM1+NUM2;
IF NEWNUM<>CNUM THEN
WRITELN('TRY AGAIN');
UNTIL NEWNUM=CNUM;

CLRSCR;
TEXTCOLOR(2);
DELAY(500);
WRITELN('                              0 0 0 0');
WRITELN('                           0           0');
WRITELN('                         0   **     **    0');
WRITELN('                      0                    0');
WRITELN('                   0            <>            0');
WRITELN('                   0       +         *         0');
WRITELN('                   0        +       +         0');
WRITELN('                     0         + +            0');
WRITELN('                       0                  0');
WRITELN('                          0            0' );
WRITELN('                              0  0');
DELAY(1000);
WRITELN;
WRITELN;
WRITELN('                       GOOD JOB! ',NAME);
READLN;
END;


begin(*main*)
RANDOMIZE;
clrscr;
STARTER(GAME,NAME,AGE);
IF GAME='YES' THEN
BEGIN
PLAY(PREF1,CHOICE);
NCOICE(CNUM,NEWNUM,NUM1,NUM2,CHOICE);
END;
end.(*main*)
