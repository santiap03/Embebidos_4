/*
 * FIFO.c
 *
 *  Created on: Nov. 8, 2020
 *      Author: santi
 */

#include "FIFO.h"
volatile static uint8_t * ptrPut;
volatile static uint8_t * ptrGet;
volatile static uint8_t * ptrPutR;
volatile static uint8_t * ptrGetR;
volatile static uint8_t FIFO[FIFO_SIZE] = {0};
volatile static uint8_t FIFOR[FIFO_SIZE] = {0};

void Fifo_Init(void)
{
	ptrPut = &FIFO[0];
	ptrGet = &FIFO[0];
	ptrPutR = &FIFOR[0];
	ptrGetR = &FIFOR[0];

}

uint8_t Fifo_Put(uint8_t newdata)
{
	if((ptrGet == ptrPut + 1) || (ptrPut - ptrGet == FIFO_SIZE - 1))
		return false; //FIFO está llena
	else
	{
		*ptrPut = newdata; //se pone el dato en la FIFO y se actualiza el apuntador
		ptrPut++;
		if(ptrPut == &FIFO[0] + FIFO_SIZE)
			ptrPut = &FIFO[0]; //fifo circular
		return true;
	}
}
uint8_t Fifo_Put_Recepcion(uint8_t newdata)
{
	if((ptrGetR == ptrPutR + 1) || (ptrPutR - ptrGetR == FIFO_SIZE - 1))
		return false; //FIFO está llena
	else
	{
		*ptrPutR = newdata; //se pone el dato en la FIFO y se actualiza el apuntador
		ptrPutR++;
		if(ptrPutR == &FIFOR[0] + FIFO_SIZE)
			ptrPutR = &FIFOR[0]; //fifo circular
		return true;
	}
}

uint8_t Fifo_Get(uint8_t * data)
{
	if(ptrPut == ptrGet)
		return false; //FIFO vacía
	else
	{
		*data = *(ptrGet++);
		if(ptrGet == &FIFO[0] + FIFO_SIZE)
			ptrGet = &FIFO[0]; //FIFO circular
		return true;
	}
}
uint8_t Fifo_Get_Recepcion(uint8_t * data)
{
	if(ptrPutR == ptrGetR)
		return false; //FIFO vacía
	else
	{
		*data = *(ptrGetR++);
		if(ptrGetR == &FIFOR[0] + FIFO_SIZE)
			ptrGetR = &FIFOR[0]; //FIFO circular
		return true;
	}
}
void FIFO_PUT_TEXT(uint8_t *text){
	uint8_t index=0;
	while (text[index] != '\0'){
		Fifo_Put(text[index]);
		index+=1;

	}
	bUART2_TIE=1;

}
