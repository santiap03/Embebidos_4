/*
 * PIT.c
 *
 *  Created on: Nov. 29, 2020
 *      Author: santi
 */
#include "PIT.h"
uint8_t flag_PIT0=0;
uint8_t flag_PIT1=0;

uint8_t xo=0, yo=0, zo=0;



void PIT0_INIT(void){

	pit_config_t pitconfig;
	PIT_GetDefaultConfig(&pitconfig);
	PIT_Init(PIT, &pitconfig);
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(1000000,CLOCK_GetFreq(kCLOCK_BusClk) ));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT_IRQn);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
}
void PIT1_INIT(void){
	rPIT_LDVAL1 = 0x7A120; //Para obtener 0.1 s (100 ms)
	bPIT_CH1_TIE = 1; //Se habiltia la interrupción
	bPIT_CH1_TEN = 1; //Se habilita el PIT
}
void PIT_IRQHandler(void){
	if (bPIT_CH0_TIF){
		bPIT_CH0_TIF = 1;//Para reconocerla (borrarla)
		flag_PIT0 = 1;
	}
	if (bPIT_CH1_TIF){
		bPIT_CH1_TIF = 1; //Para reconocerla (borrarla)
		flag_PIT1 = 1;

	}
}
void PIT_main(void){
	if(flag_PIT0==1){
		flag_PIT0=0;
		data_receive(&xo,yo,zo);

	}


}
