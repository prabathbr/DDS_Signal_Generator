void Init_DAC()
{
I2C1_Init(100000); 
}

void Set_DAC(int volt)
{
  I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0x98);             // DAC init 10011000
  I2C1_Wr(volt >> 4);                // send byte (address of EEPROM location)
  I2C1_Wr(volt << 4);             // send data (data to be written)
  I2C1_Stop();
}