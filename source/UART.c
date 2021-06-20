/*
 * UART.C
 *
 *  Created on: Nov. 28, 2020
 *      Author: santi
 */

#include "UART.h"
uint8_t rec=0;
uint8_t fifo_recover=0;


uint8_t Data_counter=0;//Contador de trama
void UART_INIT1(void){
	bSIM_CG_UART2= 1;
	bSIM_CG_PORTD=1;
	bPTD4_MUX = kPTD4_MUX_UART2_RX;
	bPTD5_MUX = kPTD5_MUX_UART2_TX;
	bUART2_BRFA= 8 ;//0;
	bUART2_SBRL=156;//;
	bUART2_SBRH=0;
	bUART2_M= 0;
	bUART2_PE= 0;
	bUART2_TIE=1;
	bUART2_TE =1;
	bUART2_RE=1;
	bUART2_TDRE=1;
	bUART2_RIE=1;
	EnableIRQ(UART2_FLEXIO_IRQn);

}
void UART2_FLEXIO_IRQHandler(void){

	if (bUART2_RDRF==1){
		bUART2_RDRF=0;
		rec=rUART2_D;
		//PRINTF("received: %c \n", rec);
		Fifo_Put_Recepcion(rec);
		if(Data_counter==3){
			Comms_flag=1;
			Data_counter=0;
		}
		else{
			Data_counter++;
		}
	}



	if (bUART2_TDRE==1){
		if(Fifo_Get(&fifo_recover)){
			rUART2_D= fifo_recover;
			//PRINTF("sent  %c \n", fifo_recover);
		}
		else{
			bUART2_TIE=0;
		}
	}


}


void TRAMA(uint8_t data, uint8_t function, uint8_t direction){//Crea la trama, la pone en fifo y envia
	uint8_t chk=0; uint8_t status;
	status=function|direction;
	chk= (uint8_t)((status+data)%256);
	Fifo_Put('$');
	Fifo_Put(status);
	Fifo_Put(data);
	Fifo_Put(chk);
	bUART2_TIE=1;


}
