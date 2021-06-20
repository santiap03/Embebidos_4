/*
 * UART.h
 *
 *  Created on: Nov. 28, 2020
 *      Author: santi
 */

#ifndef UART_H_

#define UART_H_
#include "FIFO.h"
#include "fsl_uart.h"
#include "PORT_LIB.h"
#include "SIM_LIB.h"
#include  "fsl_uart.h"
#include  "UART_LIB.h"
#include "Comms.h"

//----------------------Aplication data

#define mControl 0x80
#define mMonitoreo 0x0
#define kLED_RED 0x01
#define kLED_GREEN 0x02
#define kLED_BLUE 0x03
#define kTEMP 0x04
#define kACCEL 0x05
#define kLIGHT 0x06
#define kFLAME 0X07


void UART_INIT1(void);
void TRAMA(uint8_t data, uint8_t function, uint8_t direction);

#endif /* UART_H_ */
