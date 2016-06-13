#include "key.h"

void Key_Init(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO18 = 0;
	GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;
	EDIS;
}
