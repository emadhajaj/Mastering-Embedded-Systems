/*
 * LCD_HD44780U.c
 *
 * Created: 2/14/2024 11:40:03 AM
 *  Author: Emad Hajaj
 */ 


#include "LCD_HD44780U.h"


// =========================== LCD Static Functions ===========================

// make sure no other command will be executed meanwhile
static void LCD_Kick(){
	CLEAR_BIT(LCD_control, EN_switch);
	_delay_ms(1); // Enable cycle time (tcyc 1000ns)
	SET_BIT(LCD_control, EN_switch);
}


// =========================== LCD Functionality ===========================

void LCD_Isbusy(void){
	// set the port to receive data on the micro controller (Data direction as input).
	DataDir_LCD_port = 0x0;
	
	// put the LCD in read mode (RW on)
	SET_BIT(LCD_control, RW_switch);
	
	// put the LCD in command mode (RS off)
	CLEAR_BIT(LCD_control, RS_switch);
	
	// make sure no other command will be executed meanwhile
	LCD_Kick();
	
	// D7 pin will be ON if the LCD is busy and OFF if the LCD is not busy
}



void LCD_Init(void){
	// Initializing by Instruction
	
	// Wait for more than 15 ms after VCC rises to 4.5 
	// + wait for the default instructions to be executed by the LCD MP (4.1 ms + 100 µs)
	_delay_ms(20);
	
ifdef EIGHT_BIT_MODE
	// Function set (Interface is 8 bits long. Specify the number of display lines and character font.)
endif	
}




void LCD_Send_Command(unsigned char command);
void LCD_Send_Character(unsigned char character);
void LCD_Send_String(char *string);
void LCD_Clear_screen ();

void LCD_GotoXY(unsigned char line, unsigned char position );



/*

void LCD_clear_screen (){
	LCD_Send_A_Command(LCD_CLEAR_SCREEN);
}



void LCD_lcd_init(void){
	
	// Wait for more than 15 ms after VCC rises to 4.5 V
	_delay_ms(20);
	
	// Set Control Port as Output
	SET_BIT(DataDir_LCD_control,EN_switch);
	SET_BIT(DataDir_LCD_control,ReadWrite);
	SET_BIT(DataDir_LCD_control,RS_switch);


	CLEAR_BIT(LCD_control,EN_switch); // disable
	CLEAR_BIT(LCD_control,ReadWrite); // 0: Write
	CLEAR_BIT(LCD_control,RS_switch); // 0: Instruction register

	
	// Set Data Port as Output
	DataDir_LCD_port = 0xFF ;
	
	_delay_ms(15);

	// Make sure to not display garbage on initialization
	LCD_clear_screen ();

#ifdef EIGHT_BIT_MODE
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
#endif


#ifdef FOUR_BIT_MODE
	LCD_Send_A_Command(0x02);
	LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);
#endif



	LCD_Send_A_Command(LCD_ENTRY_MODE);
	
	// Start location
	LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
	
	// Display mode & Cursor mode
	LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK);

}
















void LCD_GotoXY(unsigned char line, unsigned char position ){

	if(line==0){
		if (position < 16 && position >=0)
			LCD_Send_A_Command(0x80+position);
	}else if (line==1)
	{
		if (position < 16 && position >=0)
			LCD_Send_A_Command(0xc0 + position);
	}
}






void LCD_check_lcd_isbusy(){
	
	DataDir_LCD_port &= ~(0xff<<DATA_shift) ;
	LCD_control |= (1<<ReadWrite); // read
	LCD_control &= ~ (1<<RS_switch);

	LCD_lcd_kick ();
	
	DataDir_LCD_port = 0xFF; 
	LCD_control &= ~ (1<<ReadWrite); //write
}








void LCD_lcd_kick (){
	
	LCD_control &= ~ (1<<EN_switch);
	asm volatile ("nop");
	asm volatile ("nop");
	_delay_ms (50) ;
	LCD_control |= 1<<EN_switch;
}







void LCD_Send_A_Command(unsigned char command){
	
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();

	LCD_port = command  ;
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	
	LCD_lcd_kick ();
#endif


#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	
	LCD_port = (LCD_port & 0x0F) | (command & 0xF0);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	
	LCD_lcd_kick ();
	
	LCD_port = (LCD_port & 0x0F) | (command << 4);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	
	LCD_lcd_kick ();
#endif

}









void LCD_Send_A_Command_4mode(unsigned char command){
	
	LCD_check_lcd_isbusy();
	
	LCD_port&= 0x0F;
	LCD_port |= (command&0xF0);
	LCD_control &= ~ ((1<<ReadWrite)|(1<<RS_switch));
	
	LCD_lcd_kick ();
	
	LCD_control &= 0x0F;  
	LCD_control |= ((command<<4)&0xF0);
	
	LCD_lcd_kick ();
}









void LCD_Send_A_Character(unsigned char character){

#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();

	LCD_control |= 1<<RS_switch;                          //turn RS ON for Data mode.
	LCD_port = ( ( (character  ) << DATA_shift)   )  ;
	LCD_control |= 1<<RS_switch;                          //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);                      //turn RW off so you can write.

	LCD_lcd_kick ();
#endif

#ifdef FOUR_BIT_MODE
	LCD_port = (LCD_port & 0x0F) | (character & 0xF0);
	LCD_control |= 1<<RS_switch;                          //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);                      //turn RW off so you can write.
	
	LCD_lcd_kick ();
	
	LCD_port = (LCD_port & 0x0F) | (character << 4);
	LCD_control |= 1<<RS_switch;                          //turn RS ON for Data mode.
	LCD_control &= ~ (1<<ReadWrite);                      //turn RW off so you can write.
	
	LCD_lcd_kick ();
#endif

}







void LCD_Send_A_String(char *StringOfCharacters){
	
	int count=0 ;
	while(*StringOfCharacters > 0){
		count++;
		LCD_Send_A_Character(*StringOfCharacters++);
		if (count == 16  ){                           // go to the second line
			LCD_GotoXY(1,0);                          //line 1 position zero
		}
		else if (count == 32 || count==33){           // clear screen and show again
			LCD_clear_screen();
			LCD_GotoXY(0,0);                          //line 0 position zero
			count = 0 ;
		}
	}
}








void LCD_display_number (int Number ){
	char  str[7];
	sprintf(str,"%d",Number);
	LCD_Send_A_String (str) ;
}







void LCD_display_real_number (double  Number ){

	char  str[16];
	char *tmpSign = (Number < 0) ? "-" : "";
	float tmpVal = (Number < 0) ? -Number : Number;

	int tmpInt1 = tmpVal;                  // Get the integer (678).
	float tmpFrac = tmpVal - tmpInt1;      // Get fraction (0.0123).
	int tmpInt2 = tmpFrac * 10000;         // Turn into integer (123).

	sprintf (str, "%s%d.%04d", tmpSign, tmpInt1, tmpInt2);

	LCD_Send_A_String (str) ;
}

*/