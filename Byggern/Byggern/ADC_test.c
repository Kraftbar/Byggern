#include <avr/io.h>
#include "ADC_test.h"
#include <util/delay.h>



unsigned char ADC_read(void)
{
	//volatile char *ext_ram = (char *) 0x1800
	volatile char *ext_adc = (char *) 0x1400; // Start address for the SRAM
	unsigned char ext_adc_size		= 0b0111;
	unsigned int retrieved_value = 0;
	for (unsigned char i = 0b0100; i <= ext_adc_size; i++)
	{	
		*ext_adc = i;
		_delay_us (50);
		retrieved_value = *ext_adc;
		//printf ("%i \n",retreived_value);	
		//return (retrieved_value);
	}
	return (retrieved_value);
}

//}
void ADC_init()
{	
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
}