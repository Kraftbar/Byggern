#ifndef CAN_h_
#define CAN_h_


void CAN_init();
unsigned char CAN_send();
unsigned char CAN_read(); 
unsigned char CAN_read2();
struct CAN_message						// Message object
{
	unsigned int id;					// Message ID,
	unsigned char length;				// length of message
	unsigned char data[8];				// message
};

#endif