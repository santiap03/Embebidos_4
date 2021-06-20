/*
 * FIFO.h
 *
 *  Created on: Nov. 8, 2020
 *      Author: santi
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "UART_LIB.h"
#define FIFO_SIZE	20

uint8_t Fifo_Put(uint8_t newdata);
uint8_t Fifo_Put_Recepcion(uint8_t newdata);

uint8_t Fifo_Get(uint8_t * data);
uint8_t Fifo_Get_Recepcion(uint8_t * data);
void FIFO_PUT_TEXT(uint8_t *text);
void Fifo_Init(void);

#endif /* FIFO_H_ */
