#include "led.h"

void Led_Init(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;
	GpioDataRegs.GPASET.bit.GPIO7 = 1;
	EDIS;
}
