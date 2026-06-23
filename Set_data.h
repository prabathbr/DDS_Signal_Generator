double Set_Freq_Val(){

int freq_place=0;
int b=20;
char shift;
char freq_buffer[7] = {0,0,0,0,0,0,0};
double freq_value=20;

delay_ms(300);
//Freq set
nokia_clear_screen();
Print_Word(1,1,12,"1:MHz  2:kHz") ;
Print_Word(1,2,4,"3:Hz") ;
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
nokia_clear_screen();
if(b==1)
{
Print_Word(1,1,10,"Enter Freq") ;
Print_Word(1,3,13,"0M 000k 000Hz") ;
shift=0;
for(freq_place=0; freq_place<7;freq_place++)
{
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
if(b<10)
freq_buffer[freq_place]=b;
if(freq_place==1 || freq_place==4)  shift+=2;
Print_Digit(1+((shift+freq_place)*6),3,b) ;
}
b=10;
}
if(b==2)
{
Print_Word(1,1,10,"Enter Freq") ;
Print_Word(1,3,13,"   000k 000Hz") ;
shift=0;
for(freq_place=1; freq_place<7;freq_place++)
{
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
if(b<10)
freq_buffer[freq_place]=b;
if(freq_place==1 || freq_place==4)  shift+=2;
Print_Digit(1+((shift+freq_place)*6),3,b) ;
}
b=10;
}
if(b==3)
{
Print_Word(1,1,10,"Enter Freq") ;
Print_Word(1,3,13,"        000Hz") ;
shift=0;
for(freq_place=4; freq_place<7;freq_place++)
{
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
if(b<10)
freq_buffer[freq_place]=b;
Print_Digit(1+((4+freq_place)*6),3,b) ;
}
}
b=10;

for(freq_place=0;freq_place<7;freq_place++){
                        freq_value=freq_value+freq_buffer[freq_place]*pow(10,6-freq_place);
}

delay_ms(500);

return freq_value;
}

double Set_Amp_Val(){

int freq_place=0;
int b=20;
char shift=0;
char freq_buffer[5] = {0,0,0,0,0};
double freq_value=1;

delay_ms(300);
//Freq set
nokia_clear_screen();
Print_Word(1,1,9,"Enter Amp") ;
Print_Word(1,3,8,"00V 000mV") ;
for(freq_place=0; freq_place<5;freq_place++)
{
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
if(b<10)
freq_buffer[freq_place]=b;
if(freq_place==2)  shift+=2;
Print_Digit(1+((shift+freq_place)*6),3,b) ;
}
b=10;


for(freq_place=0;freq_place<5;freq_place++){
                        freq_value=freq_value+freq_buffer[freq_place]*pow(10,4-freq_place);
}


delay_ms(500);
return freq_value;
}

void Set_Mode_Val()
{
int b=20;
delay_ms(300);
//Freq set
nokia_clear_screen();
Print_Word(1,1,12,"1:Sin  2:Sqr") ;
Print_Word(1,2,12,"3:Trg  4:Oth") ;
Print_Word(1,3,5,"5.Gnd") ;
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
nokia_clear_screen();
if(b==1)
{
Set_Mux(1);
Set_Mode(0);
b=10;
}
if(b==2)
{
Set_Mux(2);
b=10;
}
if(b==3)
{
Set_Mux(1);
Set_Mode(1);
b=10;
}
if(b==4)
{
Set_Mux(0);
b=10;
}
if(b==5)
{
Set_Mux(3);
b=10;
}
}


void display_out(){  
    int valx=0;
   int b=20;
   int volt[5]={0,0,0,0,0};
        int DisplayVolt=12345;
        int ADC_Value;
        int ADC_Value_new;
nokia_clear_screen();
delay_ms(500);
Print_Word(1,1,14,"Turn Amplitude") ;
Print_Word(1,2,14,"knob to change") ;
Print_Word(1,4,8,"00V 00mV0") ;

while (b== 20)
{
b=  keypad_scan();
for(valx=0;valx<100;valx++)
{
        ADC_Value_new=ADC_Read(1);
if (  ADC_Value <  ADC_Value_new)
  ADC_Value =  ADC_Value_new;
   DisplayVolt = (int)((ADC_Value * 5000.0 / 1023.0) * (12.0/2.0) * (8.0/27.0));
   delay_ms(1);
   }
   ADC_Value=0;
  // DisplayVolt = 4987;
   volt[0] = DisplayVolt%10 ;
   volt[1] = (DisplayVolt/10)%10 ;
   volt[2] = (DisplayVolt/100)%10 ;
   volt[3] = (DisplayVolt/1000)%10 ;
   volt[4] = (DisplayVolt/10000)%10 ;

   Print_Digit(1,4,volt[4]);
   Print_Digit(6,4,volt[3]);
   Print_Digit(21,4,volt[2]);
   Print_Digit(26,4,volt[1]);
   Print_Digit(31,4,volt[0]);
   

}
b=10;
}

double Set_Cust_Freq(){

int freq_place=0;
int b=20;
char shift;
char freq_buffer[7] = {0,0,0,0,0,0,0};
double freq_value=20;

delay_ms(300);
//Freq set
nokia_clear_screen();

b=20;
Print_Word(1,1,10,"Enter Freq") ;
Print_Word(1,3,13,"   000k 000Hz") ;
shift=0;
for(freq_place=1; freq_place<7;freq_place++)
{
b=20;
while (b== 20)
b=  keypad_scan();
delay_ms(300);
if(b<10)
freq_buffer[freq_place]=b;
if(freq_place==1 || freq_place==4)  shift+=2;
Print_Digit(1+((shift+freq_place)*6),3,b) ;
}
b=10;



for(freq_place=0;freq_place<7;freq_place++){
                        freq_value=freq_value+freq_buffer[freq_place]*pow(10,6-freq_place);
}

delay_ms(500);

return freq_value;
}