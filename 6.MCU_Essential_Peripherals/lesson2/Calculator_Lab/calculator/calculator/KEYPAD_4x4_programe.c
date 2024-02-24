/*
 * KBD_programe.c
 *
 *  Created on: Mar 16, 2023
 *      Author: Hello
 */


// Utiles Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

// MCALL
#include "ATMega32_DIO_interface.h"

// HALL
#include "KEYPAD_4x4_interface.h"
#include "KEYPAD_4x4_config.h"

//Functions

void KPD_getValue(u8* returned_value)
{
	// Keypad Column (output) arrays
	u8 coloumns_pins  [KPD_COLMS] = { KPD_COL0_PIN  , KPD_COL1_PIN  , KPD_COL2_PIN  , KPD_COL3_PIN  };
	u8 coloumns_ports [KPD_COLMS] = { KPD_COL0_PORT , KPD_COL1_PORT , KPD_COL2_PORT , KPD_COL3_PORT };
		
	// Keypad Row (input) arrays
	u8 rows_pins  [KPD_ROWS] = { KPD_ROW0_PIN  , KPD_ROW1_PIN  , KPD_ROW2_PIN  , KPD_ROW3_PIN  };
	u8 rows_ports [KPD_ROWS] = { KPD_ROW0_PORT , KPD_ROW1_PORT , KPD_ROW2_PORT , KPD_ROW3_PORT };
		
	// Keypad Buttons arrays
	u8 KPD_Chars[KPD_ROWS][KPD_COLMS]= KPD_KEYS ;

	if (returned_value != 0) // returned_value is a pointer
	{
		
		*returned_value = KPD_NOT_PRESSED ;
		u8 colms_counter , rows_counter , PinValue;

		for(colms_counter = 0 ; colms_counter <KPD_COLMS ;colms_counter++)
		{
			// Activate Column to check
			DIO_setPinValue(coloumns_ports[colms_counter], coloumns_pins[colms_counter], DIO_PIN_LOW);
			
			// LOOP ON ROWS
			for(rows_counter =0 ; rows_counter <KPD_ROWS ;rows_counter++)
			{
				// Check if the button is pressed
				DIO_getPinValue(rows_ports[rows_counter] , rows_pins[rows_counter], &PinValue);

				if(0 == PinValue) // if button is pressed
				{
					*returned_value = KPD_Chars[colms_counter][rows_counter];
					// Don't read until the state is changed
					while(0 == PinValue)
					{
						DIO_getPinValue(rows_ports[rows_counter], rows_pins[rows_counter], &PinValue);
					}
					return;
				}
			}
			// deactivate COLOUM back if no button is pressed
			DIO_setPinValue(coloumns_ports[colms_counter], coloumns_pins[colms_counter], DIO_PIN_HIGH);
		}
	}
}

void KPD_init       (void){
	
	// Set Output Pins
	DIO_setPinDirection(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_OUTPUT);
										
	// Set Input Pins	 				
	DIO_setPinDirection(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_INPUT);
	
	// Set Pull up Resistors
	DIO_setInputPinResistance(KPD_ROW0_PORT, KPD_ROW0_PIN);
	DIO_setInputPinResistance(KPD_ROW1_PORT, KPD_ROW1_PIN);
	DIO_setInputPinResistance(KPD_ROW2_PORT, KPD_ROW2_PIN);
	DIO_setInputPinResistance(KPD_ROW3_PORT, KPD_ROW3_PIN);
	
}