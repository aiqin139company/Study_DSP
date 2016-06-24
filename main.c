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
	uchar key,motorEn = 0;
	System_Init();

//	Led_Init();
	Timer_Init();
	Key_Init();
//	Sci_Init();
	Qep_Init();

//	Motor_Init();

	EPWM_Init();

	Interrupt_Enable();

	qep_speed.init(&qep_speed);

	while(1)
	{
		key = Key_Scan();

		if ( 1 == key )
		{
			motorEn = 1;
		}

		if ( 2 == key )
		{
			Motor_Disable();
			motorEn = 0;
			EQep1Regs.QPOSCNT = 0;
			printf("qep_cnt:%d\r\n",qep_speed.cnt);
		}

		if ( motorEn )
			Motor_Enable();

	}

}



