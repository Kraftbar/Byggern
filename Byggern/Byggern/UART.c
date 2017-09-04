#include <avr/io.h>


void UartTransive(unsigned char data){
	
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
	
	
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
	
}
void UartInit(){
	//Set Baud rate 9600
	UBRR0H = (unsigned char)(31>>8);	// Setter de 8 mest signifikante bitene
	UBRR0L = (unsigned char)(31);	// Setter de 8 minst signifikante bitene
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	// 8N2
	UCSR0C = (1<<URSEL0) | (1<<USBS0) | (3<<UCSZ00);
	
}