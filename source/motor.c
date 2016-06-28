/*
 * motor.c
 *
 *  Created on: 2016��6��24��
 *      Author: Admin
 */
#include "motor.h"

void Motor_Init(void)
{
	//Gpio Config
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;
	GpioDataRegs.GPADAT.bit.GPIO2 = 0;
	GpioDataRegs.GPADAT.bit.GPIO3 = 0;
	EDIS;

	//ePWM module initial
	EPWM_Init(10,400,300);
	Motor_Disable();
}

void Motor_Enable(void)
{
	EPWM1A = 15;
	EPWM1B = 15;
}

void Motor_Disable(void)
{
	EPWM1A = 0;
	EPWM1B = 0;
}
