#ifndef CAN_h_
#define CAN_h_


unsigned char rxflag;
typedef struct
{
	unsigned char id;
	unsigned char length;
	unsigned char data[8];
} CAN_message;


void CAN_init();
void CAN_send(CAN_message msg);
int Can_trans_compl();

void CAN_Int_Reset();

//unsigned char CAN_read(); 
CAN_message CAN_read2();


#endif