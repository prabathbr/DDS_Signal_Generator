#include "nokia3310botskool.h"
#include "all.h"
#include "Mux.h"
#include "DAC.h"
#include "lcd_init.h"
#include "Keypad.h"
#include "DDS.h"
#include "Set_data.h"

unsigned char readbuff[64] absolute 0x500; // Buffers should be in USB RAM, please consult datasheet
unsigned char writebuff[64] absolute 0x540;
char cnt;

void interrupt(){
   USB_Interrupt_Proc(); // USB servicing is done inside the interrupt
}

void disp_menu(){
Print_Word(1,1,6,"1:Freq") ;
Print_Word(45,1,6,"2:Amp ") ;
Print_Word(1,2,6,"3:Mode") ;
Print_Word(45,2,6,"4:DAQ ") ;
Print_Word(1,3,6,"5:Osci") ;
Print_Word(45,3,6,"6:Cust") ;
Print_Word(1,4,6,"7:Rand") ;
Print_Word(45,4,6,"8:Swep") ;
Print_Word(1,5,4,"9:FM") ;
}


int main(){
int freq_place=0;
double freq_value=20;
double swp1=20;
double swp2=200;
double swp_inc=20;
double swp_ln=20;
int amp_value=1000;
int y=0;
int b=20;
int i;
char shift;
char freq_buffer[7] = {0,0,0,0,0,0,0};
int osci_temp;
int cust_delay;
double swp_freq=0;
char swp_str[12];

LATC=0;
TRISC=0; // PORT C as output
PORTC=0;   // Intial Value at PORTC is Zero
cmcon=0x07;  // Turn off the comparators
TRISB=0XC0;

LATA=0;
//TRISA=0X0C; // PORT C as output
PORTA=0;
//ADCON1=0x0F;
 //ADCON0 = 0x01;
 ADCON1 = 0X0D; // RA2/AN2 is analog input
 TRISA = 0X0F;  // 0x0c + 0x03
  //ADC_Init();
 // Set_DAC(128);
     Init_DAC();
     Set_DAC(255);
CTRL=1;
delay_ms(100);
  Set_Mode(0);
  Init_Device();

HID_Enable(&readbuff,&writebuff);

lcd_set();
Set_Mux(3);

nokia_clear_screen();
Print_Word(1,2,13,"SignalFactory") ;
Print_Word(1,4,13,"SF 267017-USB") ;
delay_ms(3000);
nokia_clear_screen();
Print_Word(1,2,13,"Product by:G6") ;
Print_Word(1,4,8,"E/08/017") ;
Print_Word(1,5,8,"E/08/267") ;
delay_ms(3000);
while(1){
nokia_clear_screen();
disp_menu();

b=20;
while (b== 20)
b=  keypad_scan();

if(b==1)
{  //Freq set
freq_value=Set_Freq_Val();
Set_Freq(freq_value-18);
Start_out();
delay_ms(200);
}

if(b==2)
{
//Amp set
display_out();
b=10;
delay_ms(200);
//amp_value=Set_Amp_Val();
}

if(b==3)
{
//Mode set
nokia_clear_screen();
Set_Mode_Val();
b=10;
delay_ms(200);
}

if(b==4)
{

delay_ms(500);
nokia_clear_screen();
Print_Word(1,1,16,"Sampling Data!") ;
Print_Word(1,3,16,"Sending To PC!") ;
b=20;
while (b== 20)  {
b=  keypad_scan();
for(cnt=0;cnt<64;cnt++)
{
      writebuff[cnt]=ADC_Read(0)>>2;
delay_ms(1);
}
    while(!HID_Write(&writebuff,64));
  }
b=10;
delay_ms(200);
}

if(b==5)
{
//Mode set
delay_ms(500);

nokia_clear_screen();
b=20;
while (b== 20)  {
b=  keypad_scan();
nokia_clear_screen();
for(cnt=0;cnt<84;cnt++)
{
osci_temp=ADC_Read(0);
nokia_gotoxy(cnt,(int)(osci_temp/170));
nokia_write_data((int)pow(2.0,((osci_temp%170)/22)));
delay_ms(1);
}
  }
b=10;
delay_ms(200);
}

if(b==6)
{

delay_ms(500);

nokia_clear_screen();
b=20;
freq_value=Set_Cust_Freq();
cust_delay= (int)((1000.0/freq_value)/64.0);
nokia_clear_screen();
Print_Word(1,1,9,"Feed Data!") ;
    delay_ms(1000);
 //delay_ms(1000);
 b=20;
 while (b== 20)  {
b=  keypad_scan();
// while(!HID_Read());
for(i=0;i<64;i++)
{
Set_DAC(readbuff[64]);
Vdelay_ms(cust_delay);
//delay_ms(1);
}
 }
b=10;
delay_ms(200);
}

if(b==7)
{

delay_ms(500);

nokia_clear_screen();
b=20;
Print_Word(1,1,10,"Generating") ;
Print_Word(1,2,13,"Random Signal") ;
while (b== 20)  {
b=  keypad_scan();
srand(i);
Set_DAC(rand()%255);
Vdelay_ms(10);
i=i+1;

 }
b=10;
delay_ms(200);
}

if(b==8)
{  //Freq set
nokia_clear_screen();
Print_Word(1,1,11,"Enter Freq1") ;
delay_ms(1000);
swp1=Set_Freq_Val();
nokia_clear_screen();
Print_Word(1,1,11,"Enter Freq2") ;
delay_ms(1000);
swp2=Set_Freq_Val();
nokia_clear_screen();
Print_Word(1,1,9,"Enter Inc") ;
delay_ms(1000);
swp_inc=Set_Freq_Val();
swp_ln= (int)((swp2-swp1)/swp_inc);
for(i=0; i<swp_ln;i++)
{
Set_Freq(swp1+(swp_inc*i)-18);
swp_freq=(swp1+(swp_inc*i));
LongToStr((long)swp_freq,swp_str);
nokia_clear_screen();
Print_Word(1,1,10,"Rounded to") ;
Print_Word(1,2,8,"Possible") ;
Print_Word(1,3,12,swp_str) ;
Print_Word(1,4,12,"          Hz") ;
Start_out();
delay_ms(500);
}
b=10;
delay_ms(200);
}

if(b==9)
{
nokia_clear_screen();
Print_Word(1,1,13,"Enter Snsvty") ;
delay_ms(1000);
swp1=Set_Freq_Val();
nokia_clear_screen();
Print_Word(1,1,13,"Enter Carrier") ;
delay_ms(1000);
swp2=Set_Freq_Val();
b=20;
delay_ms(1000);
while (b== 20)  {
b=  keypad_scan();
nokia_clear_screen();
Print_Word(1,1,13,"Generating FM") ;
Set_Freq((ADC_Read(0)*5.0*swp1/1023.0 )  + swp2) ;
delay_ms(1);
 }
b=10;
delay_ms(200);
}

}


}