#include "common.h"

// These are defined by the linker
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;

void System_Init(void)
{
#ifdef FLASH
	memcpy( (Uint16 *)&RamfuncsRunStart, (Uint16 *)&RamfuncsLoadStart,
			(unsigned long)&RamfuncsLoadSize);

	InitFlash();
#endif

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
	System_Init();

//	Led_Init();
//	Timer_Init();
	Sci_Init();
//	Qep_Init();

//	EPWM_Init();

	Interrupt_Enable();

//	qep_speed.init(&qep_speed);

	while(1)
	{
		SCITX(0x12345678);
		DELAY_US(1000000);
	}

}



