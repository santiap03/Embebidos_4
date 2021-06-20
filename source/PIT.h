/*
 * PIT.h
 *
 *  Created on: Nov. 29, 2020
 *      Author: santi
 */

#ifndef PIT_H_
#define PIT_H_
#include "PIT_LIB.h"
#include "fsl_pit.h"
#include <stdio.h>
//#include "I2C_SDK.h"
#include "fsl_debug_console.h"
void PIT0_INIT(void);
void PIT1_INIT(void);
extern uint8_t flag_PIT0;
extern uint8_t flag_PIT1;
void PIT_main(void);
extern uint8_t dato_recibido;
extern uint8_t xo,yo,zo;
#endif /* PIT_H_ */
