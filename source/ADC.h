/*
 * ADC.h
 *
 *  Created on: Nov. 29, 2020
 *      Author: santi
 */

#ifndef ADC_H_
#define ADC_H_
#include "ADC_LIB.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "SIM_LIB.h"
void ADC_main(void);
void ADC_INIT(void);
extern uint16_t ADC_value;
extern float ADC0_value;
extern float ADC1_value;
extern float ADC2_value;
#define CHANNEL_ADC    bADC0_A_ADCH//Canal del adc


#endif /* ADC_H_ */
