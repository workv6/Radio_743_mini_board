


#DEFINE screen 0x77c2


void PLOT(char x,char y,char c)

{
char x0,y0,code,*addr;
//if (x<0!x>=128!y<0!y>=50!c<0!c>=3) return; ||
code=*(addr=screen+1872+(x0=x>>1)-(y0=y>>1)*78);
if (code>=8&code<16||code>=24) *addr=0;
if (x-(x0+x0)) code=6;
        else   code=17;
if (y-(y0+y0)) code=code&3;
        else   code=code&20;
if (c==1) *addr |= code;
else if (c==0)  *addr=*addr&(code^23);
else *addr=*addr^code;
}

ABS(x)
INT x;
[[
if (x<0) return -x;
return x;
]]


LINE(x0,y0,Ix,Iy,c)
INT x0,y0,Ix,Iy,c;
[[
INT I,D,N1,N2,LF,x,y;
if (x0<0!x0>=128!y0<0!y0>=50!Ix<0!Ix>=128!Iy<0!Iy>=50
    !c<0!c>=3) return;
PLOT(x0,y0,c);
Ix=Ix-x0;
Iy=Iy-y0;
N1=N2=1;
LF=x=y=0;
if (Ix<0) N1=-1;
if (Iy<0) N2=-1;
Ix=ABS(Ix);
Iy=ABS(Iy);
if (Ix<Iy) [[ LF=Ix;Ix=Iy;Iy=LF;LF=1;]]
D=Iy-(Ix>>1);
I=1;
WHILE(I++<=Ix)
    [[
    if (D>0)
        [[
        x=x+N1;
        y=y+N2;
        D=D+Iy-Ix;
        ]]
    else
        [[
        if (LF>0) y=y+N2;
        else x=x+N1;
        D=D+Iy;
        ]]
    PLOT(x0+x,y0+y,c);
    ]]
]]


INT RAND1,RAND2;

RND()
[[
return (RAND2=3*RAND1+7*(RAND1=RAND2)+12345)>>1;
]]

MAIN()
[[
INT c,x,y,Vx,Vy;
RAND1=RAND2=1;
PUTcHAR('\c');
WHILE(1)
    [[
    x=RND()%64;
    y=RND()%24;
    if (((Vx=RND()%13-6)!(Vy=RND()%9-4))==0) cONTINUE;
    c=RND()%2;
    WHILE(1)
        [[
        LINE(x,y,127-x,y,c);
        LINE(127-x,y,127-x,49-y,c);
        LINE(127-x,49-y,x,49-y,c);
        LINE(x,49-y,x,y,c);
        x=x+Vx;
        y=y+Vy;
        if (x<0!x>=63!y<0!y>=23) BREAK;
        ]]
    ]]
]]