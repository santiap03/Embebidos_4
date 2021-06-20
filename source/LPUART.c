/*
 * LPUART.c
 *
 *  Created on: Dec. 7, 2020
 *      Author: santi
 */
#include "LPUART.h"
uint8_t recept=0;
//LPUART
uint8_t sampling=2;
const lpuart_config_t LPUART0_config = {
  .baudRate_Bps = 9600UL,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};
#define LPUART0_PERIPHERAL LPUART0
/* Definition of the clock source frequency */
#define LPUART0_CLOCK_SOURCE 48000000UL

void LPUART0_init(void) {
	bSIM_CG_LPUART0=1;
	bSIM_CG_PORTE=1;
	bSIM_LPUART0SRC= kSIM_LPUART0SRC_IRC48M;
	bPTE20_MUX = kPTE20_MUX_LPUART0_TX;
	bPTE21_MUX = kPTE21_MUX_LPUART0_RX;
	bLPUART0_TIE=1;
	bLPUART0_RE=1;
	bLPUART0_RIE=1;
	bLPUART0_SBR=13;
	bLPUART0_TE=1;
	EnableIRQ(LPUART0_IRQn);
    LPUART_Init(LPUART0_PERIPHERAL, &LPUART0_config, LPUART0_CLOCK_SOURCE);
}
void LPUART0_IRQHandler(void){
	if(bLPUART0_TDRE){
		bLPUART0_DATA_8BITS='a';
	}
	if(bLPUART0_RDRF){
		recept=bLPUART0_DATA_8BITS;
		PRINTF("llego un %c. \r\n", recept);
	}

}

