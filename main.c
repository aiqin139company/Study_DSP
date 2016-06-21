#include "DSP28x_Project.h"     // DSP28x Headerfile
#include "timer.h"
#include "led.h"
#include "cla.h"
#include "Sci.h"

// These are defined by the linker
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;

void System_Init(void)
{
	InitSysCtrl();
	DINT;
	InitPieCtrl();
	IER = 0x00000000;
	IFR = 0x00000000;
	InitPieVectTable();
}

void Interrupt_Enable(void)
{
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
}

/*
 * main.c
 */
int main(void)
{

#ifdef FLASH
	memcpy( (Uint16 *)&RamfuncsRunStart, (Uint16 *)&RamfuncsLoadStart, (unsigned long)&RamfuncsLoadSize);
	InitFlash();
#endif

	System_Init();
	CLA_C_Init();

	Timer_Init();
	Sci_Init();

	Interrupt_Enable();

	while(1)
	{
		asm(" NOP");
	}

}

