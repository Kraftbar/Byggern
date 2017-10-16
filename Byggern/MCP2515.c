// MCP driver file: Espen 08.10.17
#include "MCP2515.h"
#include "SPI.h"
#include <avr/io.h>
void MCP_init()
{
	// Makes sure registers are clean and MCP in control mode
	SPI_MasterInit();
	MCP_reset();
}



void MCP_bitmod(unsigned char reg, unsigned char bit, unsigned char bittil)
{
	PORTB &= ~(1<<PB4);					// Chip select
	SPI_tranciever(MCP_BITMOD);			// send command "I want to modify bit"
	SPI_tranciever(reg);				// In what register do you want to operate
	SPI_tranciever(bit);				// What bit mask do you want to change
	SPI_tranciever(bittil);				// What to you want to change to
	PORTB |=(1<<PB4);						// chip de-select
	
}
// Note that bitmod will change multiple bits unless one specifies which bit address to change. f.ex: bit = DLC3 & DLC2
// This will only change these two, but to use the function this way DLC3 and DCL2 must be defined first

unsigned int MCP_read(unsigned char address)
{
	unsigned int result;
	PORTB &= ~(1<<PB4);				// Selects can controller
	SPI_tranciever(MCP_READ);		// Send command "I want to read MCP
	SPI_tranciever(address);		// Address we want to read
	result = SPI_tranciever(0xFF);	// Save What we read in result
	PORTB |=(1<<PB4);					// De-selects can controller
	return result;					// Return what we read
}

void MCP_write(unsigned char address, unsigned int data)
{
	PORTB &= ~(1<<PB4);					
	SPI_tranciever(MCP_WRITE);		// Send command "I want to write"
	SPI_tranciever(address);		// Where we want to write to
	SPI_tranciever(data);			// What we want to write
	
	PORTB |=(1<<PB4);
}

void MCP_reset()
{
	PORTB &= ~(1<<PB4);	
	SPI_tranciever(MCP_RESET);		// Send command "I want to reset MCP"
	PORTB |=(1<<PB4);
}

void MCP_request()
{
	PORTB &= ~(1<<PB4);
	SPI_tranciever(MCP_RTS_ALL);	// Send command "Request to send for all ports" (TX0, TX1 and TX2)
	PORTB |=(1<<PB4);
}

unsigned char MCP_status()
{
	PORTB &= ~(1<<PB4);
	unsigned char value  = SPI_tranciever(MCP_READ_STATUS);				// Send command "I want to read status"
																		// Save returned value for SPI_ tranciever
	PORTB |=(1<<PB4);	
	return value;														// Return saved variabel 
}

