// Can driver file: Espen 09.10.17

// What should it be able to do?
// Initialization of can controller
// Send message with a given ID and data
// Receive message

#include "CAN.h"


void CAN_init()
{
	MCP_bitmod(MCP_CANCTRL,MODE_MASK,MODE_LOOPBACK);		// Setting MCP to loop-back mode
}

unsigned char CAN_send(CAN_message* msg)
{
	MCP_write(MCP_TXB0SIDH, msg->id)				// Write id to Id handling register (3-3, standard identifier high)
	MCP_write(TXB0DLC, msg->length)					// Write length to length handling register (3-7)
	for(unsigned char i=0; i<msg.length;i++)
	{
		MCP_write(TXB0D0+i,msg->data[i]);			// Write data to the data handling register (3-8). iterate through TXBnDm (n.m =1,2,3...)
	}
	MCP_request();									// Request to send written message
	
}

unsigned char CAN_read(CAN_message* msg)
{
	for (unsigned char i=0; i<msg.length;i++)
	{
	MCP_read(msg->data[i]);							// Read all data, entire length of message
	unsigned char result[i] = MCP_read;				// Save read message in array "result"
	}
	return result;									//return read message
}
// returns only data

CAN_message CAN_read2(CAN_message* msg)
{
	CAN_message readint =
	{
	.id = msg->id											
	.lenght = msg->length
		for (unsigned char i=0; i<msg.length;i++)
		{
			MCP_read(msg->data[i]);							// Read all data, entire length of message
			.id[i] = MCP_read;								// gathers the read data in "readints" id
		}
		};
		return readint;										//return object readint
}
// returns an object ,"readint", of type CAN_message containing id, length and data