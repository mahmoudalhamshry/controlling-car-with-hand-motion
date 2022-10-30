/*
 * CAR_PROG.c
 *
 * Created: 10/30/2022 1:26:54 PM
 *  Author: Mahmo
 */ 
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "WDT_interface.h"
#include "UART_interface.h"



#include "CAR_INTERFACE.h"



void CAR_INIT(void)
{
	UART_init();
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);//rx
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);//tx
	//pin directions
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);//led
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);//led
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);//led

	
	
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN4,DIO_PIN_OUTPUT);//en1
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);//en2
	DIO_setPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);//motor1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);//motor1
	DIO_setPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);//motor2
	DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);//motor2
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);	  //lcd pins
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);	  //lcd pins
	
	
	LCD_init();
}

void CAR_START(u8* temp)
{
	DIO_setPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH);//en1
	DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH);//en2
	
	UART_RxChar(&temp);
	
	
	
	if (temp=='a')
	{//RIGHT
		
		LCD_clear();
		LCD_writeString("RIGHT");
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);

		
		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);//motor1 CLOCK WISE
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);//motor1
		DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);//motor2 ANTI CLOCK WISE
		DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);//moto
	}
	else if (temp=='b')//forward
	{
		LCD_clear();
		LCD_writeString("FORWAED");
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
		

		DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);//motor1 CLOCK WISE
		DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);//motor1
		DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);//motor2 ANTI CLOCK WISE
	DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);//moto		}
}
else if(temp =='c')//stop
{
	LCD_clear();
	LCD_writeString("IDLE");
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);

	
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);//motor1 CLOCK WISE
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);//motor1
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);//motor2 ANTI CLOCK WISE
DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);//moto		}
}
else if(temp =='d')//left
{
	LCD_clear();
	LCD_writeString("LEFT");
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);

	
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);//motor1 CLOCK WISE
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);//motor1
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);//motor2 ANTI CLOCK WISE
DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);//moto		}
}

else if(temp =='e')//left
{
	LCD_clear();
	LCD_writeString("BACK");
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
	DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
	
	DIO_setPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);//motor1 CLOCK WISE
	DIO_setPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);//motor1
	DIO_setPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);//motor2 ANTI CLOCK WISE
DIO_setPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);//moto		}
}
}