// Can driver file: Espen 09.10.17

// What should it be able to do?
// Initialization of can controller
// Send message with a given ID and data
// Receive message

#include <avr/io.h>
#include "setup.h"
#include "CAN.h"
#include "MCP2515.h"


unsigned char rxflag = 0;


void CAN_init()
{
	// 
	MCP_bitmod(MCP_RXB0CTRL,0x64,0xFF);
	//MCP_bitmod(MCP_TXB0CTRL,0x00,0xFF);
	MCP_bitmod(MCP_CANCTRL,MODE_MASK,MODE_LOOPBACK);		// Setting MCP to loop-back mode MODE_MASK
	MCP_bitmod(MCP_CANINTE, 0x0F, 0x0F);
	rxflag=1;
}

void CAN_send(CAN_message msg)
{


	if (Can_trans_compl())
	{
		MCP_write(MCP_TXB0SIDH, msg.id);
		//MCP_write(MCP_TXB0SIDL, msg.id << 5);				// Write id to Id handling register (3-3, standard identifier high)
		printf("%i \n",msg.id);
		MCP_write(TXB0DLC, (0x0F) & (msg.length));					// Write length to length handling register (3-7)
		for(unsigned char i=0; i<msg.length;i++)
		{
			MCP_write(TXB0D0+i,msg.data[i]);			// Write data to the data handling register (3-8). iterate through TXBnDm (n.m =1,2,3...)
		}

		MCP_request();									// Request to send written message MCP_RTS_ALL
	}
	//else
	//{
		//// sjekk om man har can error
	//}
}


int Can_trans_compl()
{
	// sjekker om TX buffer er ferdig med transmission (TXREQ = 0)
	if (test_bit(MCP_read(MCP_TXB0CTRL),3))
	{
		return 0;
		
	}	
	else
	{
		return 1;
	}
}

void CAN_Int_Reset()
{
	// clearing flag 
	MCP_bitmod(MCP_CANINTF, 0x01, 0);
	rxflag = 1;
}

CAN_message CAN_read2()
{
	CAN_message msg;
	//printf("sdgxgxsdd");
	if (rxflag == 1)//test_bit(MCP_CANINTF, MCP_RX0IF) ) // rxflag == 1
	{
		printf("abc");
		//msg.id = (MCP_read(MCP_RXB0SIDH) << 3) | (MCP_read(MCP_RXB0SIDL) >> 5);
		msg.id = MCP_read(MCP_RXB0SIDH);				
		printf("s ID: %i\n",msg.id);
		msg.length = (MCP_read(MCP_RXB0DLC)) & (0x0F);
		for (int i = 0; i< msg.length; i++)
		{
			msg.data[i] = MCP_read(MCP_RXB0D0+i);
		}
		printf("r ID: %i\n",msg.id);
												
		//Clear Interrupt flag variable
		rxflag = 0;
		MCP_bitmod(MCP_CANINTF, 0xFF, MCP_RX0IF);
		//clear_bit(MCP_CANINTF, MCP_RX0IF);
	}
	else
	{
		//Message not received
		msg.id = -1;
	}
	
	return msg;										//return object msg

}

// returns an object ,"msg", of type CAN_message containing id, length and data

ISR(INT0)
{
	printf("INTERRUPTED");
	_delay_ms(10);
	CAN_Int_Reset(); //vect
	}