#define SCLK    portB.f3
#define SDATA   portB.f2
#define FSYNC   portC.f1
#define CTRL   portC.f0

// SPI 16 Function
void Send_data(unsigned int x)
{
int i,w;
SCLK=1;
FSYNC=1;
FSYNC=0;

w=x;
for(i=0;i<16;i++)
{
SDATA=(w&0x8000)>>15;

SCLK=0;
delay_ms(1);
SCLK=1;
delay_ms(1);
w=w<<1;
}
FSYNC=1;
SCLK=0;
delay_ms(10);
}

// Init DDS
void Init_Device()
{
  Send_data(0b0001000000000010);
  Send_data(0b0010000000000000);
  Send_data(0b0011000000000000);
  Send_data(0b0110000000000010);
}

//Start out,Pulse for control pin
void Start_out()
{
  CTRL=0;
  delay_ms(1000);
  CTRL=1;
}

//Set DDS Freq
void Set_Freq(double freq_in)
{
          unsigned int high,low;
        unsigned long freq_value;

        freq_value = (unsigned long)(freq_in*16777216.0/50000000.0);
        high = (unsigned int)(((freq_value>>12) & 0x0FFF));
        low  = (unsigned int)((freq_value & 0x00000FFF));
        Send_data(0xC000 | low);
        Send_data(0xD000 | high);
}

//Set mode
void Set_Mode(int mode_in)
{
if (mode_in==0)   Send_data(0b0000111111010011);    //Sine
if (mode_in==1)   Send_data(0b0000110111010011); //Trga
}