/*
*************** name :Mahmoud Alhamshry  ***************
*************** date :                   ***************
*************** verison :1/11/2022       ***************


*/
#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "UART_interface.h"


 u16 a0,a1,a2,a3,a4;
 u16 d0,d1,d2,d3,d4;
int main(void)
{
    
	 GLOVES_INIT();
	
	  
    while (1)
    {
	    GLOVES_START(&d0,&d1,&d2,&d3,&d4,&a0,&a1,&a2,&a3,&a4);
 
	    
        		
    }
}
		
		


