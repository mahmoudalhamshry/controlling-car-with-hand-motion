

/*
*************** name :Mahmoud Alhamshry  ***************
*************** date :1/11/2022          ***************
*************** verison :1/11/2022       ***************


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
#include "LCD_config.h"
#include "LCD_interface.h"


volatile u8 temp;
int main(void)
{
	CAR_INIT();
	
     
	 
    while (1) 
    {
			CAR_START(&temp);
		
		
    }
	
}



