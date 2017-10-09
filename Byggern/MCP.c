// MCP driver file: Espen 08.10.17
#include "MCP2515.h"
#include "SPI.h"

void MCP_init()
{
	// Makes sure registers are clean and MCP in control mode
	MCP_reset()
}



unsigned char MCP_bitmod(unsigned char register, unsigned char bit, unsigned char bittil)
{
	PORTB = (0<<4);					// Chip select
	SPI_tranciever(MCP_BITMOD);		// send command "I want to modify bit"
	SPI_tranciever(register);		// In what register do you want to operate
	SPI_tranciever(bit);			// What bit mask do you want to change
	SPI_tranciever(bittil);			// What to you want to change to
	PORTB =(1<<4);					// chip de-select
	
}
// Note that bitmod will change multiple bits unless one specifies which bit address to change. f.ex: bit = DLC3 & DLC2
// This will only change these two, but to use the function this way DLC3 and DCL2 must be defined first

unsigned char MCP_read(unsigned char address)
{
	unsigned char result;
	PORTB &= ~(1<<CAN_CS);			// Selects can controller
	SPI_tranciever(MCP_READ);		// Send command "I want to read MCP
	SPI_tranciever(address);		// Address we want to read
	result = SPI_tranciever;		// Save What we read in result
	
	PORTB |= (1<<CAN_CS);			// De-selects can controller
	return result;					// Return what we read
}

unsigned char MCP_write(unsigned char address, unsigned char data)
{
	PORTB = (0<<4);					
	SPI_tranciever(MCP_WRITE)		// Send command "I want to write"
	SPI_tranciever(address);		// Where we want to write to
	SPI_tranciever(data);			// What we want to write
	
	PORTB = (1<<4)
}

unsigned char MCP_reset()
{
	PORTB = (0<<4);
	SPI_tranciever(MCP_RESET);		// Send command "I want to reset MCP"
	PORTB = (1<<4);
}

unsigned char MCP_request()
{
	PORTB = (0<<4);
	SPI_tranciever(MCP_RTS_ALL);	// Send command "Request to send for all ports" (TX0, TX1 and TX2)
	PORTB = (1<<4);
}

unsigned char MCP_status()
{
	PORTB = (0<<4);
	SPI_tranciever(MCP_READ_STATUS)				// Send command "I want to read status"
	unsigned char value = SPI_tranciever()		// Save returned value for SPI_ tranciever
	PORTB = (1<<4);
	return value								// Return saved variabel 
}

