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
	System_Init();

	Led_Init();
	Timer_Init();
	Xint_Init();

	while(1)
	{

	}

}


