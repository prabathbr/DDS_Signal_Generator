#define MUXA    portA.f4
#define MUXB   portA.f5

void Set_Mux( int x)
{
if(x==0) // DAC
{
MUXA =0;
MUXB =0;
}
if(x==1) // SIN
{
MUXA =1;
MUXB =0;
}
if(x==2) // SQR
{
MUXA =0;
MUXB =1;
}
if(x==3) // GND
{
MUXA =1;
MUXB =1;
}
}
