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
#include <string.h>
#include <util/delay.h>
#include "UART.h"
#include "SRAM_test.h"
#include "ADC_test.h"

void testest2(unsigned char x)
{
	USART_Transmit(x);
}

unsigned char TestChar = 'k';

int main(void)
{
	UartInit();
	
	SRAM_init();
	ADC_init();
	
	DDRB = 0x00;	//input
	PORTB = 0xFF;	//pull-up
	// output (the whole port)
	//DDRE = 0xFF;
	//TODO:: Please write your application code
	//fdevopen(char a);
	
	//PORTE = 0xFF;
	
	char name[100];

	
	unsigned int i = 0;
	int j = 1;
	
    while(1)
    {
	    //scanf("%s", name);
		//printf("%s \n \n",name);
	
        //TODO:: Please write your application code 
		//fdevopen(char a);
		printf (" %i  %i  %i  %i %i %i %i \n", PINB & (1<<PINB0),PINB & (1<<PINB1),PINB & (1<<PINB2), ADC_read());
		//printf (" %i \n", PINB);
		//printf (ADC_read ());
		//printf (i);
		//SRAM_test();
		//SRAM_write(0x101, 0xF03);
		//_delay_ms(100);
		//printf(SRAM_read(0x101));
		
		//i++;
		//
		//if (i >= 10)
		//{
			//i = 0;
			//if (j == 0)
			//{
				//PORTA = 0xFF;
				//j = 1;
			//}
			//else
			//{
				//PORTA = 0x00;
				//j = 0;
			//}
			//
			//_delay_ms(100);
			//
			//
		//}
		
    }
	
}


/*
10. To link the printf function to the UART driver you only need to make a function that transmits one character to the UART, and
call the function �fdevopen(transmit function, receive function)�. For more information about this function, see the section about the Standard I/O module (stdio.h)
in AVR Libc�s user manual at http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html.
11. Verify that you now can send text and values of variables by using the standard printf function.

 */ 