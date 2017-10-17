// Can driver file: Espen 09.10.17

// What should it be able to do?
// Initialization of can controller
// Send message with a given ID and data
// Receive message

#include "CAN.h"
#include "MCP2515.h"




void CAN_init()
{
	MCP_init();
	MCP_bitmod(MCP_RXB0CTRL,0xFF,0x64);
	MCP_bitmod(MCP_TXB0CTRL,0xFF,0x00);
	MCP_bitmod(MCP_CANCTRL,MODE_MASK,MODE_LOOPBACK);		// Setting MCP to loop-back mode MODE_MASK
	MCP_bitmod(MCP_CANINTE, 0x01, 1);
}

void CAN_send(CAN_message msg)
{
	MCP_write(MCP_TXB0SIDH, msg.id >> 3);
	MCP_write(MCP_TXB0SIDL, msg.id << 5);				// Write id to Id handling register (3-3, standard identifier high)

	MCP_write(TXB0DLC, (0x0F) & (msg.length));					// Write length to length handling register (3-7)
	for(unsigned char i=0; i<msg.length;i++)
	{
		MCP_write(TXB0D0+i,msg.data[i]);			// Write data to the data handling register (3-8). iterate through TXBnDm (n.m =1,2,3...)
	}
		//printf("%c",msg.id);
		//printf("%c",msg.length);
		//for (int i =0; i<8; i++)
		//{
			//printf("%c",msg.data[i]);
		//}
		//printf("\n\n");
	MCP_request();									// Request to send written message MCP_RTS_ALL
	
}

//unsigned char CAN_read(CAN_message msg)
//{
	//for (unsigned char i=0; i<msg.length;i++)
	//{
	//MCP_read(msg.data[i]);							// Read all data, entire length of message
	//unsigned char result[i] = MCP_read;				// Save read message in array "result"
	//}
	//return result;									//return read message
//}
// returns only data

CAN_message CAN_read2()
{
	CAN_message msg;
	msg.id = (MCP_read(MCP_RXB0SIDH) << 3) | (MCP_read(MCP_RXB0SIDL) >> 5);
							
	msg.length = (MCP_read(MCP_RXB0DLC)) & (0x0F);
	for (int i = 0; i< msg.length; i++)
	{
		msg.data[i] = MCP_read(MCP_RXB0D0+i);
	}
	printf("ID: %i\n",msg.id);
	//printf("Lengde: %i\n",msg.length);
	//for (int i =0; i<8; i++)	
		//{
			//printf("Bit %i: %i\n",i,msg.data[i]);
		//}
	//printf("\n");												
	return msg;										//return object msg
}
// returns an object ,"msg", of type CAN_message containing id, length and data