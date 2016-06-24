/*
 * motor.h
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: Admin
 */

#ifndef HEADERS_MOTOR_H_
#define HEADERS_MOTOR_H_

#include "common.h"

#define EPWM1A 	GpioDataRegs.GPADAT.bit.GPIO0
#define EPWM1B 	GpioDataRegs.GPADAT.bit.GPIO1
#define EPWM2A 	GpioDataRegs.GPADAT.bit.GPIO2
#define EPWM2B 	GpioDataRegs.GPADAT.bit.GPIO3

void Motor_Init(void);
void Motor_Enable(void);
void Motor_Disable(void);

#endif /* HEADERS_MOTOR_H_ */
