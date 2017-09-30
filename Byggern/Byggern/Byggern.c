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
<<<<<<< HEAD
=======
#include "ADC_test.h"
#include "Joystick.h"
#include "fonts.h"
>>>>>>> 98be1f4a3c990b0200acf7fc30a15a64098bf9eb

void testest2(unsigned char x)
{
	USART_Transmit(x);
}

unsigned char TestChar = 'k';

int main(void)
{
	UartInit();
	
	SRAM_init();
<<<<<<< HEAD
	// Output (the whole port)
	//DDRA = 0xFF;
=======
	ADC_init();
	init_OLED();
	
	DDRB = 0x00;	//input
	PORTB = 0xFF;	//pull-up
>>>>>>> 98be1f4a3c990b0200acf7fc30a15a64098bf9eb
	// output (the whole port)
	//DDRE = 0xFF;
	//TODO:: Please write your application code
	//fdevopen(char a);
	
	//PORTE = 0xFF;
	
	char name[100];

<<<<<<< HEAD
	
	unsigned int i = 1;
	int j = 1;
	
    while(1)
    {
	    scanf("%s", name);
		printf("%s \n \n",name);
	
        //TODO:: Please write your application code 
		//fdevopen(char a);
		
		SRAM_test();
=======
	//calibrate();
	
	unsigned int i = 0;
	int j = 1;
	write_c(0xB0);
	write_c(0x00);
	write_c(0x10);
	write_d(0x00);
	write_d(0b00000000);
	write_d(0b01111101);
	write_d(0x00);
	
    while(1)
    {
		char c = 'k';
		//char myString[] = "This is some text";	//Howto extract a letter form string
		//char myChar = myString[6];
		int d = (int) c - 32;
		//write_c(0xA4);
		//write_c(0x20);		//Adressing mode
		//write_c(0b10);		//Page adressing mode
		
		//write_c(0xA0);
		
		if (PINB & (1<<PINB0)){
			for (int i = 0; i<8; i++){ 
				write_c(0xB0+i);
				write_c(0x00);
				write_c(0x10);
				for (int j = 0; j<16; j++){
					//for (int k = 1; k<8; k++){
						//printf("%i \n", font8[k]);
						
						write_d(font8[d][0]);
						write_d(font8[d][1]);
						write_d(font8[d][2]);
						write_d(font8[d][3]);
						write_d(font8[d][4]);
						write_d(font8[d][5]);
						write_d(font8[d][6]);
						write_d(font8[d][7]);
						//write_d(0x00);
						//write_d(0x00);
						//write_d(0b00000000);
						//write_d(0b01111101);
						//write_d(0x00);
					//}
				}
				//write_c(0xB1);
				//for (int j = 0; j<128; j++){
					//write_d(0x00);
				//}
				//write_c(0xB2);
				//for (int j = 0; j<128; j++){
					//write_d(0x00);
				//}
				//write_c(0xB3);
				//for (int j = 0; j<128; j++){
					//write_d(0x00);
				//}

			}
		//_delay_ms(100);
		
		}
		if (PINB & (1<<PINB1)){
			OLED_Reset();
			//k++;
		}
			
		//write_d(1000);
	    //scanf("%s", name);
		//printf("%s \n \n",name);
		//printf("%i \n",ADC_read_test(2));
        //TODO:: Please write your application code 
		//fdevopen(char a);

		//printf (" %i  %i  %i  %i  %i  %i  %i \n", PINB & (1<<PINB0),PINB & (1<<PINB1),PINB & (1<<PINB2), ADC_read(0),ADC_read(1),ADC_read(2),ADC_read(3));
		//printf (" %i  %i  %i  %i \n", ADC_read(3));
		//printf (" %i \n", PINB);
		//printf (ADC_read ());
		//printf (i);
		//SRAM_test();
>>>>>>> 98be1f4a3c990b0200acf7fc30a15a64098bf9eb
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
call the function “fdevopen(transmit function, receive function)”. For more information about this function, see the section about the Standard I/O module (stdio.h)
in AVR Libc’s user manual at http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html.
11. Verify that you now can send text and values of variables by using the standard printf function.

 */ 
