#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "Sci.h"

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
	
	System_Init();

	Sci_Init();

	while(1)
	{
		SCITX('a');
		DELAY_US(1000000);
	}

}
