/*
 * motor.c
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: Admin
 */
#include "motor.h"

void Motor_Init(void)
{
	EALLOW;
//	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
//	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;

//	GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
//	GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;

//	GpioDataRegs.GPADAT.bit.GPIO0 = 0;
//	GpioDataRegs.GPADAT.bit.GPIO1 = 0;
	GpioDataRegs.GPADAT.bit.GPIO2 = 0;
	GpioDataRegs.GPADAT.bit.GPIO3 = 0;
	EDIS;

}

void Motor_Enable(void)
{
	EPWM1A = 1;
	EPWM1B = 1;
	Delay_us(10);
	EPWM1A = 0;
	EPWM1B = 0;
	Delay_us(45);
}

void Motor_Disable(void)
{
	EPWM1A = 0;
	EPWM1B = 0;
}
