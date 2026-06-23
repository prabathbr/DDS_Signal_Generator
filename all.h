#ifndef _ALL_H
#define _ALL_H
//--------------------------
typedef unsigned char BYTE ;

typedef unsigned short USHORT;
typedef unsigned int WORD ;
typedef unsigned long TLONG;
typedef int int16;
typedef long int int32;
//--------------------------
#define key_enter portd.f0
#define key_min portd.f2
#define key_plus portd.f3
//-------------------------
BYTE k_button =0;
#define k_enter k_button.f0
#define k_plus k_button.f1
#define k_min k_button.f2
#define k_temp k_button.f3
#define k_temp1 k_button.f4
#define k_set k_button.f5
#define k_data k_button.f6
//-----------------------

//---------------- macro buttons-----------
#define _KEY_ENTER (key_enter && k_enter)
#define _KEY_PLUS (key_plus && k_plus)
#define _KEY_MIN (key_min && k_min)
//---------------------
#define _KEY_SUB_ENTER (_KEY_ENTER && k_temp)
#define _KEY_MENU_ENTER (_KEY_ENTER &&!k_temp)
//-------------------------
//----------- macro --------
#define ERASE_ROW(var) lcd_out(var,1,empty_15);

//------- flages 1 to 8 -----------
BYTE BOOLEEN = 0;
#define ENTER_FLAG BOOLEEN.F0
#define EXIT_FLAG BOOLEEN.F1
#define TEMP_FLAG BOOLEEN.F2
#define MENU_FLAG BOOLEEN.F3
#define PLUS_FLAG BOOLEEN.F4
#define MIN_FLAG BOOLEEN.F5
#define ERASE_FLAG BOOLEEN.F6
#define SHOW_FLAG BOOLEEN.F7
//-------------------------
#define ARROW_FLAG BOOLEEN.F7
#define TIME_FLAG BOOLEEN.F6
// -----------------
//#define enter F_1
//#define exit F_2
//#define close F_3
//#define save F_4
//#define nsave F_5
//#define pass F_6
#define Esave F_7
//#define flag2 F_8
//---------- CONSTANTS ---------------
#define SET 1
#define CLR 0
#define TRUE SET
#define FALSE CLR
#define SEEK 1
#define NSEEK 0
#define IN 1
#define OUT 0
#define INPUT 0xFF
#define OUTPUT 0x00
//---------- PORTB CONFIG  --------------
#define B0 PORTB.F0
#define B1 PORTB.F1
#define B2 PORTB.F2
#define B3 PORTB.F3
#define B4 PORTB.F4
#define B5 PORTB.F5
#define B6 PORTB.F6
#define B7 PORTB.F7
//-----------PORTD CONFIG------------
#define D0 PORTD.F0
#define D1 PORTD.F1
#define D2 PORTD.F2
#define D3 PORTD.F3
#define D4 PORTD.F4
#define D5 PORTD.F5
#define D6 PORTD.F6
#define D7 PORTD.F7
//---------- PORTD CONFIG DIG_7seg --------------
#define DIG1 PORTD.F4
#define DIG2 PORTD.F5
#define DIG3 PORTD.F6
#define DIG4 PORTD.F7
//------------- INTCON macro ---------
#define INT_TOIE  0xA0
#define INT_TOIF_CLR   0x20
#define ASSIGNED_TMR0 0x80
// --------- constant string ---------
//#define ERROR "Error!"
//#define WAIT "Wait!"
//#define SAVE "Save:"
//#define YES "Yes!"
//#define NO "No!"
// -----------------------------------
//---------- function dalay -----------

//--------------------------------
//--------- macro ------
#define B_S_F(reg,num) reg|=(1<<num)
#define BIT_SET(reg,num) reg|=(1<<num)
//------------------
#define B_C_F(reg,num) reg&=(~(1<<num))
#define BIT_CLR(reg,num) reg&(~(1<<num))
//-------------
#define B_T_F(reg,num)    reg&(1<<num)


//--------------------------
#endif

