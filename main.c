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

void Delay_us(long timer)
{
	while(timer--);
}

/*
 * main.c
 */
int main(void)
{
	long flag = 0;
	System_Init();

	//modules initial
	Sci_Init();
	Motor_Init();
	eCAP_Init();

	//enable glabol interrupt
	Interrupt_Enable();

	while(1)
	{
		flag = SCIRX();
		if ( 0xA0A0 == flag )
		{
			PIE_eCAP_CNT();
			Motor_Enable();
		}

		if ( 0x0A0A == flag )
		{
			Motor_Disable();
		}
	}

}



