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
#include "Joystick.h"
//#include "fonts.h"
#include "Buzz.h"
#include "SPI.h"
#include "MCP2515.h"
#include "CAN.h"

void testest2(unsigned char x)
{
	USART_Transmit(x);
}



int main(void)
{
	DDRD  = 0xFF;
	
	UartInit();
	SRAM_init();
	ADC_init();
	init_OLED();
	SPI_MasterInit();
	MCP_init();
	CAN_init();
	
	DDRB = 0x00;	//input
	PORTB = 0xFF;	//pull-up
	
	char name[100];

	//calibrate();
	OLED_Reset();
	//const unsigned char* streng = "dette er en test";
const unsigned char* streng = "Espen er en GAUDER";
const unsigned char* streng2 = "Gaute er en test";
const unsigned char* streng3 = "Runar er en test";
	
    while(1)
    {
		
		
		
		//OLED_Reset();
		
		
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
		
		//OLED_animation();
		OLED_NameScreen();
		
				
		
		while(!read_knappJoy())
		{
		OLED_picture();
		}
		OLED_menu();
	}
}
	


