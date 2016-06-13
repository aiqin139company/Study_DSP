#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

/*
 * main.c
 */
int main(void)
{
	
	InitSysCtrl();

	DINT;
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO7 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO7 = 1;
	EDIS;

	while(1)
	{
		GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;
		DELAY_US(1000000);
	}

}
