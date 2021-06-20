/*
 * LCD_drive.h
 *
 *  Created on: 17/10/2020
 *      Author: juan
 */

#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_

#include "PIT_LIB.h"
#include "SIM_LIB.h"
#include "PORT_LIB.h"
#include "GPIO_LIB.h"
#include "TPM_LIB.h"
#include <stdint.h>

//Estructura para los datos del LCD
typedef union{
	unsigned char PORTD0_3 : 4;
	struct{
		uint32_t espacio: 32;
	}espacio;
} PORTD_LCD;

#define RS						bGPIOE_PDOR0 //Define instrucción (RS = 0) o lectura/escritura de datos (RS = 1)
#define E							bGPIOE_PDOR1 //Habilita instrucción en el LCD
#define RW					bGPIOE_PDOR16  //Define lectura o escritura (R/W = 1 = Lectura, R/W= 0 = Escritura)
#define rLCD_DATA	(*(PORTD_LCD *)&rGPIOD_PDOR)
#define LCD_DATA		rLCD_DATA.PORTD0_3  //Carácter LCD
#define BF						bGPIOD_PDIR3  //Bandera de operación del LCD (BF = 1 = busy, BF = 0 = free)

//imprime una cadena de carácteres en el LCD
void LCDPrint(char POS_in_LCD, unsigned char * string_to_LCD);
//Inicializa el puerto D, usado para los datos del LCD
void init_PTD(void);
//Inicializa pines usados para E, RS, R/W
void init_E_RS_RW(void);
//Inicializa el LCD
void Init_LCD(void);
//Habilita la instrucción del LCD
void LCDEnable(void);
//Realiza un Delay
void Timmer0(unsigned int tiempo);

#endif /* LCD_DRIVE_H_ */





