//Define I/O pins

#define OUT1     portB.f2
#define OUT2     portB.f3
#define OUT3     portB.f4
#define OUT4     portB.f5
#define READ1    portB.f6
#define READ2    portB.f7
#define READ3    portA.f2
#define READ4    portA.f3

/*
***********Key Pad Library************
***********Group 6************
No input=20
A=21
B=22
C=23
D=24
*=25
#=26

Usage:
int get_keypab = keypad_scan();

*/

int keypad_scan()
{
int x,y;
int val1=0;
int read_num[4][4];

 OUT1=0;
 OUT2=0;
 OUT3=0;
 OUT4=0;
 delay_ms(10);
OUT1=1;
delay_ms(10);
read_num[0][0]=READ1;
read_num[0][1]=READ2 ;
read_num[0][2]=READ3  ;
read_num[0][3]=READ4   ;
OUT1=0;
OUT2=1;
delay_ms(10);
read_num[1][0]=READ1    ;
read_num[1][1]=READ2     ;
read_num[1][2]=READ3      ;
read_num[1][3]=READ4       ;
OUT2=0;
OUT3=1;
delay_ms(10);
read_num[2][0]=READ1        ;
read_num[2][1]=READ2           ;
read_num[2][2]=READ3         ;
read_num[2][3]=READ4          ;
OUT3=0;
OUT4=1;
delay_ms(10);
read_num[3][0]=READ1            ;
read_num[3][1]=READ2             ;
read_num[3][2]=READ3              ;
read_num[3][3]=READ4               ;
OUT4=0;
for(x=0;x<4;x++)
{
for(y=0;y<4;y++)
{
if(read_num[x][y]==1)
{
val1=(x*4)+y+1;
x=5;
y=5;
}
}
}
switch(val1){
case 0: val1=20; break;   // no input
case 1: val1=1;break;
case 2: val1=2;break;
case 3: val1=3;break;
case 4: val1=21; break; // A
case 5: val1=4;break;
case 6: val1=5;break;
case 7: val1=6;break;
case 8: val1=22; break; // B
case 9: val1=7;break;
case 10: val1=8;break;
case 11: val1=9;break;
case 12: val1=23; break; //C
case 13: val1=25;break; // *
case 14: val1=0;break;
case 15: val1=26;break; // #
case 16: val1=24; break;    // D
default: val1=20;break;
}
return val1;
}