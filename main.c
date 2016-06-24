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

	System_Init();

	Key_Init();
//	Qep_Init();
	Motor_Init();

	EPWM_Init(10,400,300);
	Motor_Disable();
	Timer_Init();
	Interrupt_Enable();

	while(1)
	{

	/*
//		if ( motorEn )
			Motor_Enable();

		if ( 0 == EQep1Regs.QPOSCNT )
		{
			CpuTimer0Regs.TIM.all = 0;
			CpuTimer0Regs.TCR.bit.TSS = 1;
		}

		if ( EQep1Regs.QPOSCNT >= 4000 )
		{
			timer_cnt = CpuTimer0Regs.TIM.all;
			CpuTimer0Regs.TCR.bit.TSS = 0;
			EQep1Regs.QPOSCNT = 0;
			printf("time: %ld ms\r\n",timer_cnt/60000);
		}

		*/



	}

}



