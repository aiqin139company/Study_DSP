#include "timer.h"

uchar motorEn = 0;

//Timer0 initialize
void Timer_Init(void)
{
	CpuTimer0Regs.PRD.all = mSec10;
	CpuTimer0Regs.TCR.all = 0x4000;		//enable timer0

	IER |= M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

	EALLOW;
	PieVectTable.TINT0 = &TIM0_ISR;
	EDIS;
}

//Timer0_ISR
__interrupt void TIM0_ISR(void)
{
	static uchar toggle = 0;
	uchar key;

	key = Key_Scan();

	if ( 1 == key )
	{
		toggle = !toggle;
		if ( toggle )
			Motor_Enable();
		else
			Motor_Disable();
	}

	if ( 2 == key )
	{
		EPWM1A -= 10;
		EPWM1B -= 10;
	}

	if ( 3 == key )
	{
		EPWM1A += 10;
		EPWM1B += 10;
	}

	PieCtrlRegs.PIEACK.bit.ACK1 = 1;
}

