#include <stdlib.h>
void SRAM_test(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	unsigned int ext_ram_size		= 0x800;
	unsigned int write_errors		= 0;
	unsigned int retrieval_errors	= 0;
	printf("Starting SRAM test...\n");
	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	unsigned int seed = rand();
	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (unsigned int i = 0; i < ext_ram_size; i++) 
		{
		unsigned char some_value = rand();
		ext_ram[i] = some_value;
		unsigned char retreived_value = ext_ram[i];
		if (retreived_value != some_value) 
			{
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			write_errors++;
			}
		}
	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed);
	// reset the PRNG to the state it had before the write phase
	for (unsigned int i = 0; i < ext_ram_size; i++) 
		{
		unsigned char some_value = rand();
		unsigned char retreived_value = ext_ram[i];
		if (retreived_value != some_value) 
			{
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			retrieval_errors++;
			}
		}
	printf("SRAM test completed with \n%4d errors in write phase and \n%4d errors in retrieval phase \n\n", write_errors, retrieval_errors);
}