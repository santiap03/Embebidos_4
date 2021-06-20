/*
 * TPM.h
 *
 *  Created on: Nov. 28, 2020
 *      Author: santi
 */

#ifndef TPM_H_
#define TPM_H_
#include "SIM_LIB.h"
#include "TPM_LIB.h"
#include "PORT_LIB.h"
#include "fsl_tpm.h"

void TPM_INIT(void);
void setLEDRed_Duty(uint8_t val);
void setLEDGreen_Duty(uint8_t val);
void setLEDBlue_Duty(uint8_t val);
#endif /* TPM_H_ */
