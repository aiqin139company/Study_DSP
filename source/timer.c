#include "timer.h"

//Timer0 initialize
void Timer_Init(void)
{
	CpuTimer0Regs.PRD.all = mSec1000;
	CpuTimer0Regs.TCR.all = 0x4000;

	IER |= M_INT1;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

	EALLOW;
	PieVectTable.TINT0 = &TIM0_ISR;
	EDIS;
}

//Timer0_ISR
__interrupt void TIM0_ISR(void)
{
//	qep_speed.calc(&qep_speed);
//	printf("qep_cnt:%d \r\n",qep_speed.cnt);
//	GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;

	EPwm1Regs.CMPA.half.CMPA = 350; // Compare A = 350 TBCLK counts
	EPwm1Regs.CMPB = 200; // Compare B = 200 TBCLK counts

	PieCtrlRegs.PIEACK.bit.ACK1 = 1;
}

