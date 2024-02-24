/*
 * DIO_program.c
 *
 * Created: 3/14/2023 12:49:40 PM
 *  Author: Emad Hajaj
 */


// Utiles Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

// MCALL
#include "ATMega32_DIO_interface.h"

//Functions

void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection){
    if( (PortId<=3) && (PinId<=7) && (( PinDirection == 1)||( PinDirection == 0)) ){ // the parameters are unsigned
        switch (PortId)
        {
        case 0://PORTA
            if ( PinDirection == DIO_PIN_INPUT)
            {
                CLR_BIT(DDRA, PinId);
            }
            else
            {
                SET_BIT(DDRA, PinId);
            }
            break;

        case 1://PORTB
            if ( PinDirection == DIO_PIN_INPUT)
            {
                CLR_BIT(DDRB, PinId);
            }
            else
            {
                SET_BIT(DDRB, PinId);
            }
            break;

        case 2://PORTC
            if ( PinDirection == DIO_PIN_INPUT)
            {
                CLR_BIT(DDRC, PinId);
            }
            else
            {
                SET_BIT(DDRC, PinId);
            }
            break;

        case 3://PORTD
            if ( PinDirection == DIO_PIN_INPUT)
            {
                CLR_BIT(DDRD, PinId);
            }
            else
            {
                SET_BIT(DDRD, PinId);
            }
            break;

        default:
            break;
        }
    }
}



void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue){
    if( (PortId<=3) && (PinId<=7) && ((PinValue==1)||(PinValue==0)) ){
        switch (PortId)
        {
        case 0:// PORTA
            if ( PinValue == DIO_PIN_HIGH){
                SET_BIT(PORTA,PinId);
            }
            else {
                CLR_BIT(PORTA,PinId);
            }
            break;

        case 1:// PORTB
            if ( PinValue == DIO_PIN_HIGH){
                SET_BIT(PORTB,PinId);
            }
            else {
                CLR_BIT(PORTB,PinId);
            }
            break;

        case 2:// PORTC
            if ( PinValue == DIO_PIN_HIGH){
                SET_BIT(PORTC,PinId);
            }
            else {
                CLR_BIT(PORTC,PinId);
            }
            break;

        case 3:// PORTD
            if ( PinValue == DIO_PIN_HIGH){
                SET_BIT(PORTD,PinId);
            }
            else {
                CLR_BIT(PORTD,PinId);
            }
            break;


        default:
            break;
        }
    }
}



void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue){
    if( (PortId<=3) && (PinId<=7) && (PinValue != NULL ) ){
        switch (PortId)
        {
        case 0:// PORTA
            if ( GET_BIT(PINA ,PinId) == DIO_PIN_HIGH){
                *PinValue = DIO_PIN_HIGH;
            }
            else {
                *PinValue = DIO_PIN_LOW;
            }
            break;

        case 1:// PORTB
            if ( GET_BIT(PINB ,PinId) == DIO_PIN_HIGH){
                *PinValue = DIO_PIN_HIGH;
            }
            else {
                *PinValue = DIO_PIN_LOW;
            }
            break;

        case 2:// PORTC
            if ( GET_BIT(PINC ,PinId) == DIO_PIN_HIGH){
                *PinValue = DIO_PIN_HIGH;
            }
            else {
                *PinValue = DIO_PIN_LOW;
            }
            break;

        case 3:// PORTD
            if ( GET_BIT(PIND ,PinId) == DIO_PIN_HIGH){
                *PinValue = DIO_PIN_HIGH;
            }
            else {
                *PinValue = DIO_PIN_LOW;
            }
            break;

        default:
            break;
        }
    }
}


void DIO_togglePinValue(u8 PortId, u8 PinId){
    if ((PortId<=3) && (PinId<=7)){
        switch (PortId)
        {
        case 0:
            TOG_BIT(PORTA,PinId);
            break;

        case 1:
            TOG_BIT(PORTB,PinId);
            break;

        case 2:
            TOG_BIT(PORTC,PinId);
            break;

        case 3:
            TOG_BIT(PORTD,PinId);
            break;
        
        default:
            break;
        }
    }

}

void DIO_setPortDirection      (u8 PortId, u8 PortDirection){
    if ( (PortId <= 3) && ( (PortDirection == DIO_PORT_OUTPUT) || (PortDirection == DIO_PORT_INPUT) ) ) {
        // We need to set the whole port so we must be 0xff or 0x00
        switch (PortId)
        {
        case 0: //PORTA
            if (PortDirection == DIO_PORT_OUTPUT){
                DDRA = 0xff;
            }
            else{
                DDRA = 0x00;
            }
            break;
        
        case 1: //PORTB
            if (PortDirection == DIO_PORT_OUTPUT){
                DDRB = 0xff;
            }
            else{
                DDRB = 0x00;
            }
            break;


        case 2: //PORTC
            if (PortDirection == DIO_PORT_OUTPUT){
                DDRC = 0xff;
            }
            else{
                DDRC = 0x00;
            }
            break;


        case 3: //PORTD
            if (PortDirection == DIO_PORT_OUTPUT){
                DDRD = 0xff;
            }
            else{
                DDRD = 0x00;
            }
            break;


        default:
            break;
        }
    }
}


void DIO_setPortValue          (u8 PortId, u8 PortValue){
    if ( (PortId <= 3) ){
        // we are given the values of the pins so we save them as given
        switch (PortId)
        {
        case 0: // PORTA
            PORTA = PortValue;
            break;
        
        case 1: // PORTB
            PORTB = PortValue;
            break;

        case 2: // PORTC
            PORTC = PortValue;
            break;

        case 3: // PORTD
            PORTD = PortValue;
            break;

        default:
            break;
        }
    }
}


void DIO_getPortValue          (u8 PortId, u8*PortValue){
    if ( (PortId <=3) && (PortValue != NULL) ){
        switch (PortId)
        {
        case 0: //PINA
            *PortValue = PINA;
            break;

        case 1: //PINB
            *PortValue = PINB;
            break;

        case 2: //PINC
            *PortValue = PINC;
            break;

        case 3: //PIND
            *PortValue = PIND;
            break;
        
        default:
            break;
        }
    }
}


void DIO_togglePortValue       (u8 PortId){
    if ( PortId <=3 ){
        switch (PortId)
        {
        case 0: //PINA
            PORTA = ~PORTA;
            break;

        case 1: //PINB
            PORTB = ~PORTB;
            break;

        case 2: //PINC
            PORTC = ~PORTC;
            break;

        case 3: //PIND
            PORTD = ~PORTD;
            break;
        
        default:
            break;
        }
    }
}

void DIO_setInputPinResistance   (u8 PortId, u8 PinId){
    if (( PortId <= 3 ) && ( PinId <= 7 )){
        switch (PortId)
        {
        case 0: //PORTA
            SET_BIT(PORTA, PinId);
            break;
        
        case 1: //PORTB
            SET_BIT(PORTB, PinId);
            break;

        case 2: //PORTC
            SET_BIT(PORTC, PinId);
            break;

        case 3: //PORTD
            SET_BIT(PORTD, PinId);
            break;

        default:
            break;
        }
    }
}

void DIO_setInputPortResistance   (u8 PortId){
    if ( PortId <= 3 ){
        switch (PortId)
        {
        case 0:
            PORTA = 0xff;
            break;

        case 1:
            PORTB = 0xff;
            break;

        case 2:
            PORTC = 0xff;
            break;

        case 3:
            PORTD = 0xff;
            break;
        
        default:
            break;
        }
    }
}

