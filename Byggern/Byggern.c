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


int main(void)
{
	DDRD  = 0xFF;
	
	UartInit();
	SRAM_init();
	ADC_init();
	init_OLED();
	CAN_init();
	
	// kalibrering
	/*DDRB = 0b00011011;				//Output, input p� 0-2
	PORTB = 0xFF;					//pull-up og h�y ut
	
	char name[100];

	calibrate();
	OLED_Reset();*/
	
	// Enable Global Interrupts
	sei();
	

	//testmess.data[0] = 15;
	
	// CAN test

			
			CAN_message myMessage;				//test message
			int ident = 55;
			myMessage.id = ident;
			myMessage.length = 8;
			int n = 5;
			for (int i = 0; i < 8; i++) 
			{
				myMessage.data[i] = n;
				n++;
			}
	printf("Start p� program\n");

	//CAN_message h;								//Receiver generated message
    while(1)
    {
		
		/*printf("test");
		
		OLED_Reset();
		
		
		if (PINB & (1<<PINB0))
		{	
			buzz(C4, 800);
			//OLED_Home();
			//OLED_goto(3,36);
			//OLED_print(streng,4);
			//OLED_gotoline(1);
			//OLED_print(streng2,5);
			//OLED_gotoline(2);
			//OLED_print(streng3,8);
		}
		if (PINB & (1<<PINB1))
		{
			OLED_Reset();
		}
		
		OLED_animation();
		OLED_NameScreen();
		
				
		
		while(!read_knappJoy())
		{
		OLED_picture();
		//}
		OLED_menu();
					 chip de-select*/



			CAN_send(&myMessage);
			_delay_ms(100);
			//uint8_t status = MCP_read(MCP_CANCTRL);
			//printf("STATUS: 0x%02X\n",status);
			//uint8_t status2 = MCP_read(MCP_EFLG);
			//printf("STATUS2: 0x%02X\n",status2);
			//CAN_read2(&h);
				////h.id=h.data[0];
				//printf("h id = %d "  ,h.id  );
				//printf("h length = %d "  , h.length  );
				//printf("h= ");
			//if (h.id == ident)
			//{
				//for (int i =0; i<8; i++)
				//{
					//printf("%d, ",h.data[i]);
				//}
				//printf("\n");
			//}
	}
}
		


