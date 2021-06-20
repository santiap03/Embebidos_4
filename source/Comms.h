/*
 * Comms.h
 *
 *  Created on: Nov. 30, 2020
 *      Author: santi
 */

#ifndef COMMS_H_
#define COMMS_H_
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "FIFO.h"
#include "UART.h"
#include "ADC.h"
#include "TPM.h"
extern uint8_t Comms_flag;
void main_comms(void);
void process(void);
#endif /* COMMS_H_ */
