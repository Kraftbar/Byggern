void SPI_MasterInit(void)
{
	/* Set MOSI, SS and SCK output, all others input */
	DDRB = (1<<5)|(1<<7) | (1<<4);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0) | (1<<SPIE);
	
	// Enable Global Interrupts
	sei();
}

unsigned char SPI_tranciever(unsigned char data)
{
	//Chip Select
	PORTB = (0<<4);
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while (!(SPSR & (1<<SPIF)));
	//Return received data
	return(SPDR);
}