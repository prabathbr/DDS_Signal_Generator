/* LCD Init and Set the contrast 
Group 6 mod
*/

//LCD Init
void lcd_set(){

nokia_init();     // Initialising the Nokia LCD
delay_ms(10);
nokia_clear_screen(); // Screen should always be cleared intially.
delay_ms(10);
nokia_clean_ddram();
nokia_contrast(90);

}

//Print Word
void Print_Word(int x,int y,int Word_size,char arr[]){
int i;
 nokia_gotoxy(x,y);
                   for(i=0;i<Word_size;i++)
                         nokia_printchar(*(arr+i));
    }

void Print_Digit(int x,int y,char arr){

 nokia_gotoxy(x,y);
 nokia_printchar (arr+48);
    }	
	