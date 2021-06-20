/*
 * LCD_drive.c
 */
#include "LCD_drive.h"

void Init_LCD(void){
	RS = 0; //Necesario para el formato de instrucciones a continuación
	E = 0; //desabilita instrucciones del LCD
	RW = 0;//Necesario para el formato de instrucciones a continuación

	Timmer0(119997); //15ms

	//Se manda 3 veces la secuencia 0x3
	LCD_DATA = 0x3;
	LCDEnable();

	LCD_DATA = 0x3;
	LCDEnable();

	LCD_DATA = 0x3;
	LCDEnable();

	//4 bits de entrada y dos líneas de uso para el LCD
	LCD_DATA = 0x28>>4;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCD_DATA = 0x28;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCDEnable();

	//Borrar LCD y poner cursor al principio
	LCD_DATA = 0x1>>4;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCD_DATA = 0x1;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCDEnable();

	//Modo incremental, no shift,
	LCD_DATA = 0x6>>4;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCD_DATA = 0x6;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCDEnable();

	//Enciende pantalla y apaga el cursor
	LCD_DATA = 0xC>>4;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCD_DATA = 0xC;
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCDEnable();
}

void LCDEnable(void){
	unsigned char RS_old = RS; //Guarda valor anterior
	E = 1;
	Timmer0(5); //1us
	E = 0;

	//Para leer la bandera BF del LCD
	bGPIOD_PDDR3 = 0; //habilitar como entrada. En esta función el pin D7 del LCD es la bandera BF
	RS = 0; //Necesario para leer la bandera BF
	RW = 1; //Necesario para leer la bandera BF
	E = 1; //Habilita la instrucción

	while(BF){ //Espera a que el LCD termine su tarea
	}
	E = 0;//Desabilita futuras instrucciones

	//Se retorna al estado anterior
	RW = 0;
	RS = RS_old;
	bGPIOD_PDDR3 = 1; //habilitar como salida
}

void Timmer0(unsigned int tiempo){
	for(unsigned int time = tiempo; time > 0; time--){
		__asm volatile ("nop");
	}
	//Tiempo de la CPU = (7 antes del ciclo+11 después del ciclo+ tiempo*6 en el ciclo) * CPU clock
	//T = (18+N*6)*S
	//N = (T/S -18)/6
}

void LCDPrint(char POS_in_LCD,unsigned char * string_to_LCD){
	//POS_in_LCD debe estar en Hex
	RS = 0;
	unsigned char pos = 0x80; //Formato para mandar la posición
	pos += POS_in_LCD; //Posición a mandar
	LCD_DATA = pos>>4;//se carga en el puerto D3-0 los bits 7-4
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCD_DATA = pos;//se carga en el puerto D3-0 los bits 3-0
	E = 1;
	Timmer0(5); //1us
	E = 0;
	LCDEnable();

	RS = 1; //Para escribir en el LCD
	unsigned int index = 0;
	while (string_to_LCD[index] != '\0'){//si no funciona '/0' usar simplemente 0
		LCD_DATA = string_to_LCD[index] >> 4; //se carga en el puerto D3-0 los bits 7-4
		E = 1;
		Timmer0(5); //1us
		E = 0;
		LCD_DATA = string_to_LCD[index]; //se carga en el puerto D3-0 los bits 3-0
		E = 1;
		Timmer0(5); //1us
		E = 0;
		LCDEnable();
		index += 1; //Se pasa al siguiente caracter
	}
}

void init_E_RS_RW(void){
	bSIM_CG_PORTE = 1; //Activar reloj del PORTE

	//Borrar  para evitar algún dato no deseado
	rPTE_PCR0 = 0x0;
	rPTE_PCR1 = 0x0;
	rPTE_PCR16 = 0x0;

	//Definir como GPIO
	bPTE0_MUX = kPTD0_MUX_GPIO;
	bPTE1_MUX = kPTD1_MUX_GPIO;
	bPTE16_MUX = kPTD2_MUX_GPIO;

	//PTD0, 1 y 16 como salidas
	bGPIOE_PDDR0 = 1;
	bGPIOE_PDDR1 = 1;
	bGPIOE_PDDR16 = 1;
}

void init_PTD(void){
	bSIM_CG_PORTD = 1; //Activar reloj del PORTD

	//Borrar  para evitar algún dato no deseado
	rPTD_PCR0 = 0x0;
	rPTD_PCR1 = 0x0;
	rPTD_PCR2 = 0x0;
	rPTD_PCR3 = 0x0;

	//Definir como GPIO
	bPTD0_MUX = kPTD0_MUX_GPIO;
	bPTD1_MUX = kPTD1_MUX_GPIO;
	bPTD2_MUX = kPTD2_MUX_GPIO;
	bPTD3_MUX = kPTD3_MUX_GPIO;

	//PTD0-7 como salidas
	bGPIOD_PDDR0=1;
	bGPIOD_PDDR1=1;
	bGPIOD_PDDR2=1;
	bGPIOD_PDDR3=1;
}
