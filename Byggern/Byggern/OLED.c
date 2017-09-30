#include <stdlib.h>
#include <avr/io.h>
#include "OLED.h"

void init_OLED()
{
	write_c(0xae);        //  display  off
	write_c(0xa1);        //segment  remap
	write_c(0xda);        //common  pads  hardware:  alternative
	write_c(0x12);
	write_c(0xc8);        //common output scan direction:com63~com0
	write_c(0xa8);        //multiplex  ration  mode:63
	write_c(0x3f);
	write_c(0xd5);        //display divide ratio/osc. freq. mode
	write_c(0x80);
	write_c(0x81);        //contrast  control
	write_c(0x50);
	write_c(0xd9);        //set  pre-charge  period
	write_c(0x21);
	write_c(0x20);        //Set  Memory  Addressing  Mode
	write_c(0x02);
	write_c(0xdb);        //VCOM  deselect  level  mode
	write_c(0x30);
	write_c(0xad);        //master  configuration
	write_c(0x00);
	write_c(0xa4);        //out  follows  RAM  content
	write_c(0xa6);        //set  normal  display
	write_c(0xaf);        //  display  on
}

void OLED_Reset(void)
{
	for (int i = 0; i<8; i++){
		write_c(0xB0+i);
		for (int j = 0; j<128; j++){
			write_d(0x00);
		}
	}
}

void OLED_Home(void)
{
	write_c(0xB0);
	write_c(0x00);
	write_c(0x10);
}

void write_c(unsigned char out_command)
{
	volatile char *ext_OLEDc = (char *) 0x1000;
	*ext_OLEDc = out_command;
	return 0;
	//DC(0);CS(0);RW(0);
	////delay_ms(1);
	//LCD_out(out_command);
	//// delay_ms(1);
	//RW(1);
	//CS(1);
	//DC(1);
}

void write_d(unsigned char out_data)
{
	volatile char *ext_OLEDd = (char *) 0x1200;
	*ext_OLEDd = out_data;
	return 0;
	//DC(1);CS(0);RW(0);
	//// delay_ms(1);
	//LCD_out(out_data);
	//// delay_ms(1);
	//RW(1);
	//CS(1);
	//DC(1);
}

//// these functions set / clear pins for LCD control lines.  they accecpt a 0 or 1
//void RD(char stat)
//{
	//IODIR0 |= LCD_RD;				// RD is P0.18, set to output
	//if (stat)
	//IOSET0 |= LCD_RD;
	//else
	//IOCLR0 |= LCD_RD;
//}
//
//void RW(char stat)
//{
	//IODIR0 |= LCD_RW;				// RW is P0.17, set to output
	//if (stat)
	//IOSET0 |= LCD_RW;
	//else
	//IOCLR0 |= LCD_RW;
//}
//
//void DC(char stat)
//{
	//IODIR0 |= LCD_RS;				// RS is P0.30, set to output
	//if (stat)
	//IOSET0 |= LCD_RS;
	//else
	//IOCLR0 |= LCD_RS;
//}
//
//void RES(char stat)
//{
	//IODIR0 |= LCD_RSTB;				// RSTB is P0.7, set to output
	//if (stat)
	//IOSET0 |= LCD_RSTB;
	//else
	//IOCLR0 |= LCD_RSTB;
//}
//
//void CS(char stat)
//{
	//IODIR0 |= LCD_CS;				// RSTB is P0.7, set to output
	//if (stat)
	//IOSET0 |= LCD_CS;
	//else
	//IOCLR0 |= LCD_CS;
//}
//
//
//
//
//// send to the LCD
//void LCD_out(unsigned char cmd)
//{
	//IODIR0 |= LCD_DATA;           	// set lcd data pins to output
	//IOCLR0 |= LCD_DATA;				// clear all pins
	//IOSET0 |= get_LCD_port(cmd);	  	// set port
//}
//
//
//unsigned int get_LCD_port(unsigned char data)
//{
	//return ((data & 0x01) << D0) | (((data >> 1) & 0x01) << D1) | (((data >> 2) & 0x01) << D2) |
	//(((data >> 3) & 0x01) << D3) | (((data >> 4) & 0x01) << D4) |
	//(((data >> 5) & 0x01) << D5) | (((data >> 6) & 0x01) << D6) | (((data >> 7) & 0x01) << D7);
//}