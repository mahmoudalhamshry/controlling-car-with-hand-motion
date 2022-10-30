/*
 * GLOVES_PROG.c
 *
 * Created: 10/30/2022 2:17:45 PM
 *  Author: Mahmo
 */ 
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "UART_interface.h"
#include "GLOVES_INTERFACE.h"
extern a0,a1,a2,a3,a4;
extern d0,d1,d2,d3,d4;

void GLOVES_INIT(void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	ADC_init();
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_INPUT);
	
	
	UART_init();
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);//rx
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);//tx
}
void GLOVES_START(u8* d0,u8* d1,u8* d2,u8* d3,u8* d4,u8* a0,u8* a1,u8* a2,u8* a3,u8* a4)
{
	ADC_getDigitalValue(ADC_CHANNEL_4,&d0);
	a0=((u32)d0*5000UL)/1024;
	ADC_getDigitalValue(ADC_CHANNEL_5,&d1);
	a1=((u32)d1*5000UL)/1024;
	ADC_getDigitalValue(ADC_CHANNEL_6,&d2);
	a2=((u32)d2*5000UL)/1024;
	ADC_getDigitalValue(ADC_CHANNEL_7,&d3);
	a3=((u32)d3*5000UL)/1024;
	ADC_getDigitalValue(ADC_CHANNEL_2,&d4);
	a4=((u32)d4*5000UL)/1024;
	
	
	
	
	
	
	
	if((a0<2550)&&(a1>2300)&&(a2>2550)&&(a3>2550))
	{
		UART_TxChar('a');//right
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
		
	}
	else if ((a1<2200)&&(a0<2450)&&(a2<2550)&&(a3<2600))
	{
		UART_TxChar('b');//forward
		
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
	}
	else if((a2>2500)&&(a0>2500)&&(a1>2280)&&(a3>2600))
	{
		UART_TxChar('c');//stop
		
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
	}
	else if((a3<2550)&&(a0>2500)&&(a1>2280)&&(a2>2500))
	{
		UART_TxChar('d');//left
		
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
	}
	else if((a1<2200)&&(a0>2560)&&(a3>2600)&&(a2>2500))
	{
		UART_TxChar('e');//backword
		
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
	}
}