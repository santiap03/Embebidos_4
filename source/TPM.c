/*
 * TPM.c
 *
 *  Created on: Nov. 28, 2020
 *      Author: santi
 */

#include "TPM.h"
volatile uint16_t DUTY_BLUE;
volatile uint16_t DUTY_RED;
volatile uint16_t DUTY_GREEN;

void TPM_INIT(void){
	// Initialize SIM
	bSIM_CG_TPM1 = 1;
	bSIM_CG_TPM2 = 1;
	bSIM_TPMSRC = kSIM_TPMSRC_IRC48M;

	bSIM_CG_PORTA = 1;
	bSIM_CG_PORTB = 1;

	bPTA13_MUX = kPTA13_MUX_TPM1_CH1;//Azul
	bPTB18_MUX = kPTB18_MUX_TPM2_CH0;//ROJO
	bPTB19_MUX = kPTB19_MUX_TPM2_CH1;//Verde

	// Initialize TPM1
	bTPM1_TOIE = 1;
	bTPM1_PS = kTPM_PS_DIVIDE_BY_128;
	bTPM1_MOD = 6250;
	bTPM1_DBGMODE = kTPM_DBGMODE_COUNT_ACTIVE;

	// Initialize CH1 TPM1
	rTPM1_C1SC = mTPM_CxSC_ELSB | mTPM_CxSC_MSB;
	bTPM1_CH1_VAL = 6125;

	// Start TPM1 count
	bTPM1_CMOD = kTPM_CMOD_COUNTER_INCREMENT_ON_TPM_CLOCK;

	// Initialize TPM2
	bTPM2_TOIE = 1;
	bTPM2_PS = kTPM_PS_DIVIDE_BY_128;
	bTPM2_MOD = 6250;
	bTPM2_DBGMODE = kTPM_DBGMODE_COUNT_ACTIVE;

	// Init CH0 TPM2
	rTPM2_C0SC = mTPM_CxSC_ELSB | mTPM_CxSC_MSB;
	bTPM2_CH0_VAL = 6125;

	// Init CH1 TPM2
	rTPM2_C1SC = mTPM_CxSC_ELSB | mTPM_CxSC_MSB;
	bTPM2_CH1_VAL = 6125;

	// Start TPM1 count
	bTPM2_CMOD = kTPM_CMOD_COUNTER_INCREMENT_ON_TPM_CLOCK;
    EnableIRQ(TPM1_IRQn);
    EnableIRQ(TPM2_IRQn);


}
void setLEDRed_Duty(uint8_t val){
	uint16_t duty = ((uint32_t)(6250*val))>>8;
	if (duty>6125)
		DUTY_RED = 6125;
	else
		DUTY_RED =  duty;

	return;
}

void setLEDGreen_Duty(uint8_t val){
	uint16_t duty = ((uint32_t)(6250*val))>>8;
	if (duty>6125)
		DUTY_GREEN = 6125;
	else
		DUTY_GREEN =  duty;

	return;
}

void setLEDBlue_Duty(uint8_t val){
	uint16_t duty = ((uint32_t)(6250*val))>>8;
	if (duty>6125)
		DUTY_BLUE = 6125;
	else
		DUTY_BLUE =  duty;

	return;
}


void TPM1_IRQHandler(void)
{
	if(rTPM1_STATUS & mTPM_STATUS_TOF)
	{
		rTPM1_C1V = DUTY_BLUE;
		bTPM1_TOF_SC = 1;
	}
}

void TPM2_IRQHandler(void)
{
	if(rTPM2_STATUS & mTPM_STATUS_TOF)
	{
		rTPM2_C0V = DUTY_RED;
		rTPM2_C1V = DUTY_GREEN;
		bTPM2_TOF_SC = 1;
	}
}

