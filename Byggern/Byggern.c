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
#include "OLED.h"
#include "Joystick.h"
//#include "fonts.h"
#include "Buzz.h"
#include "SPI.h"
#include "MCP2515.h"
#include "CAN.h"

//void testest2(unsigned char x)
//{
	//USART_Transmit(x);
//}



int main(void)
{
	DDRD  = 0xFF;
	
	UartInit();
	SRAM_init();
	ADC_init();
	init_OLED();
	MCP_init();
	
	//DDRB = 0b00011011;				//Output, input på 0-2
	//PORTB = 0xFF;					//pull-up og høy ut
	
	//char name[100];

	//calibrate();
	//OLED_Reset();
	//const unsigned char* streng = "dette er en test";
//const unsigned char* streng = "Espen er en GAUDER";
//const unsigned char* streng2 = "Gaute er en test";
//const unsigned char* streng3 = "Runar er en test";
	
	// Enable Global Interrupts
	sei();
	
	CAN_message testmess;
	testmess.id = 4;
	testmess.length = 8;
	for (unsigned char i=0; i<testmess.length;i++)
	{
		testmess.data[i] = i;
	}
	//testmess.data[0] = 15;
	
    while(1)
    {
		
		//printf("test");
		
		//OLED_Reset();
		
		
		//if (PINB & (1<<PINB0))
		//{	
			//buzz(C4, 800);
			////OLED_Home();
			////OLED_goto(3,36);
			////OLED_print(streng,4);
			////OLED_gotoline(1);
			////OLED_print(streng2,5);
			////OLED_gotoline(2);
			////OLED_print(streng3,8);
		//}
		//if (PINB & (1<<PINB1))
		//{
			//OLED_Reset();
		//}
		
		//OLED_animation();
		//OLED_NameScreen();
		//
				//
		//
		//while(!read_knappJoy())
		//{
		//OLED_picture();
		////}
		//OLED_menu();
					// chip de-select

	//uint8_t dummy=	0xFF;//MCP_read(0x0E);
	//printf("After Reset Status is: %2x\n",dummy);
	//MCP_write(0x0F,0x40);
	//dummy=	MCP_read(0x0F);
	//printf("Updated Status is: %2x\n",dummy);
	//_delay_ms(1000);
				//
		//
			// CAN test oppsett
			
			//for(int i = 0; i < 8; i++)
			//{
				//printf("%i", testmess.data[i]);
				//
			//}
			//printf("\n");
			//printf("%i",testmess.id);
			

			CAN_send(testmess);
			
			CAN_message h = CAN_read2();
			
			
			if(h.id == 4)
			{
				
				printf("h= ");
				for (int i =0; i<h.length; i++)
				{
					printf("%i",h.data);
				}
				printf("\n");
			}
			//
	}
}
		


