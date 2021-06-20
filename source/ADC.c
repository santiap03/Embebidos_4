/*
 * ADC.c
 *
 *  Created on: Nov. 29, 2020
 *      Author: santi
 */
#include "ADC.h"
volatile uint8_t flag_ADC=0;
uint16_t ADC_value=0;
float ADC0_value=1.5;
float ADC1_value=0;
float ADC2_value=0;
uint8_t ADC_STATUS=0;

void ADC_INIT(void){


    //bSIM_CG_PORTB=1;
    //bPTB0_MUX = kPTB0_MUX_ADC0_SE8;
	bSIM_CG_ADC0 = 1;
	bSIM_ADC0ALTTRGEN = 1;
	bSIM_ADC0TRGSEL = kSIM_ADC0TRGSEL_PIT_CH0;
	bADC0_A_AIEN = 1;
	bADC0_A_DIFF = 0;
	bADC0_A_ADCH = kADC_ADCH_AD8;
	bADC0_MODE = kADC_MODE_SE_12_BITS;
	bADC0_ADICLK = kADC_ADICLK_BUS_CLOCK;
	bADC0_ADTRG  = 1;
	EnableIRQ(ADC0_IRQn);
	bADC0_MUXSEL=0;
	bADC0_CAL=1;
	bADC0_REFSEL= kADC_REFSEL_VDDA_VSSA;
	bADC0_AVGE=0;
}
void ADC0_IRQHandler(void)
{
	flag_ADC=1;
	ADC_value = bADC0_A_D;
	bADC0_A_AIEN = 0;
}
void ADC_main(void){
	if (flag_ADC) {
			if(flag_ADC==1) {
				flag_ADC=0;
				switch (ADC_STATUS) {
					case 0:
						ADC0_value = (float)ADC_value*100/4095;
						//PRINTF("El valor de ADC0: %f \n", ADC0_value);
						CHANNEL_ADC =  kADC_ADCH_AD9;
						ADC_STATUS++;

						break;
					case 1:
						ADC1_value = (float)(ADC_value*330/4095)-273;
						//PRINTF("El valor de ADC1: %f \n", ADC1_value);
						CHANNEL_ADC = kADC_ADCH_AD14;
						ADC_STATUS++;

						break;
					case 2:
						ADC2_value = (float)ADC_value*100/4095;
						//PRINTF("El valor de ADC2: %f \n", ADC2_value);
						CHANNEL_ADC = kADC_ADCH_AD8;
						ADC_STATUS=0;

						break;
					default:
						break;
				}
				bADC0_A_AIEN = 1;


		   }
		}
}
