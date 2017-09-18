#ifndef UART_h_
#define UART_h_

void UartInit();

int SRAM_write(unsigned int address, unsigned int data);

unsigned int SRAM_read(unsigned int address);

void SRAM_test(void);

//void USART_Transmit(unsigned char data);

#endif