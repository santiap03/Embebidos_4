/*
 * I2C_SDK.h
 *
 *  Created on: Dec. 7, 2020
 *      Author: santi
 */

#ifndef I2C_SDK_H_
#define I2C_SDK_H_
void BOARD_I2C_ReleaseBus(void);

void data_receive(uint8_t *x1, uint8_t *y1, uint8_t *z1);
void I2C_INIT1(void);


#endif /* I2C_SDK_H_ */
