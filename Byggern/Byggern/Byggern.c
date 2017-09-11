/*
 * Byggern.c
 *
 * Created: 04.09.2017 10:24:49
 *  Author: gautevn
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
//#include <avr/stdint.h>
#include <stdio.h>
#include <util/delay.h>
#include "UART.h"
//#include "UART.c"
#include "SRAM_test.c"

void testest2(unsigned char x)
{
	USART_Transmit(x);
}

unsigned char TestChar = 'k';

int main(void)
{
	// Output (the whole port)
	DDRA = 0xFF;
	// output (the whole port)
	DDRE = 0xFF;
	//TODO:: Please write your application code
	//fdevopen(char a);
	
	PORTE = 0xFF;
	
	char name[100];

	
	unsigned int i = 1;
	int j = 1;
	UartInit();
    while(1)
    {
	    //scanf("%s", name);
		//printf("%s \n \n",name);
	
        //TODO:: Please write your application code 
		//fdevopen(char a);
		
		SRAM_test();
		i++;
		
		if (i >= 10)
		{
			i = 0;
			if (j == 0)
			{
				PORTA = 0xFF;
				j = 1;
			}
			else
			{
				PORTA = 0x00;
				j = 0;
			}
			
			_delay_ms(1000);
			
			
		}
		
    }
	
}


/*
10. To link the printf function to the UART driver you only need to make a function that transmits one character to the UART, and
call the function “fdevopen(transmit function, receive function)”. For more information about this function, see the section about the Standard I/O module (stdio.h)
in AVR Libc’s user manual at http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html.
11. Verify that you now can send text and values of variables by using the standard printf function.

 */ 
