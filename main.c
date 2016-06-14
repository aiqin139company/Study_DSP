#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "timer.h"
#include "led.h"
#include "xint.h"

void System_Init(void)
{
	InitSysCtrl();
	DINT;
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();
}

/*
 * main.c
 */
int main(void)
{
	int i = 0,j=0;
	System_Init();

	Led_Init();
	Timer_Init();
//	Xint_Init();

//	EALLOW;
//  SysCtrlRegs.WDCR = 0;
//  EDIS;

	while(1)
	{
		for(i =0;i<10;i++)
		{
			j++;
		}
		EALLOW;
		SysCtrlRegs.WDCR = 0;
		EDIS;
	}

}


