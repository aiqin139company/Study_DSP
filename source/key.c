#include "key.h"

void Key_Init(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;

	GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO13 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO15 = 0;

	GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;

	EDIS;
}

uchar Key_Scan(void)
{
	static uchar flag = 1;

	if ( ( 0 == KEY1 || 0 == KEY2 || 0 == KEY3 ) && flag )
	{
		flag = 0;
		//Delay_us(10000);				//delay 10ms
		if ( 0 == KEY1 ) return 1;
		if ( 0 == KEY2 ) return 2;
		if ( 0 == KEY3 ) return 3;
	}
	else if ( KEY1 && KEY2 && KEY3 ) flag = 1;

	return 0;
}
