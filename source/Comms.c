/*
 * Comms.c
 *
 *  Created on: Nov. 30, 2020
 *      Author: santi
 */
#include "Comms.h"
uint8_t Cstatus=0;
uint8_t Comms_flag=0;
uint8_t temporal=0;
uint8_t command=0;
uint8_t checksum=0;
uint8_t data_command=0;
uint8_t accel=0;
uint8_t rvalue=0;
uint8_t bvalue=0;
uint8_t gvalue=0;
uint8_t q=0;
void main_comms(void){//registra la trama
	if(Comms_flag==1){
		while(Fifo_Get_Recepcion(&temporal)){
			switch (Cstatus) {
				case 0:
					if (temporal=='$'){
						Cstatus++;
					}
				break;
				case 1:
					command=temporal;
					Cstatus++;

				break;
				case 2:
					data_command=temporal;
					Cstatus++;

				break;
				case 3:
					checksum=temporal;
					Cstatus=0;
					process();
				break;
				default:
					break;
			}
		}
		Comms_flag=0;
	}
}
void process(void){//Procesa la trama
	uint8_t chk_local=0; uint8_t type=0;
	chk_local=(uint8_t)((command+data_command)%256);
	type= 0x80 & command;
	if(checksum==chk_local){
		command=0x7f & command;
		if(type==0){
			switch (command) {//Llega comando de lectura
				case kLED_RED:
				    TRAMA(rvalue, mControl, kLED_RED);

				break;
				case kLED_GREEN:
				    TRAMA(gvalue, mControl, kLED_GREEN);

				break;
				case kLED_BLUE:
				    TRAMA(bvalue, mControl, kLED_BLUE);

				break;
				case kTEMP:
					q= (uint8_t)ADC1_value;
					TRAMA(q, mMonitoreo, kTEMP);


				break;

				case kLIGHT:
					TRAMA((uint8_t)ADC0_value, mMonitoreo, kLIGHT);
				break;
				case kFLAME:
					TRAMA((uint8_t)ADC2_value, mMonitoreo, kFLAME);
				break;
				case kACCEL:
					TRAMA(accel, mMonitoreo, kACCEL);
				break;
				default:
					break;
			}
		}
		if(type!=0){//Llega comando de control
			switch (command) {
				case kLED_RED:
				    setLEDRed_Duty(data_command);
				    rvalue=data_command;
				    TRAMA(data_command, mControl, kLED_RED);
				break;
				case kLED_GREEN:
				    setLEDGreen_Duty(data_command);
				    gvalue=data_command;
				    TRAMA(data_command, mControl, kLED_GREEN);
				break;
				case kLED_BLUE:
				    setLEDBlue_Duty(data_command);
				    gvalue=data_command;
				    TRAMA(data_command, mControl, kLED_BLUE);
				break;
				default:
					break;
			}

		}



	}
}
