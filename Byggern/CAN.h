#ifndef CAN_h_
#define CAN_h_
typedef struct
{
	unsigned char id;
	unsigned char length;
	unsigned char data[8];
} CAN_message;


void CAN_init();
void CAN_send(CAN_message msg);
//unsigned char CAN_read(); 
CAN_message CAN_read2();


#endif