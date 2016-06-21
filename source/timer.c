#include "timer.h"

#define WAITSTEP 	asm(" RPT #255 || NOP")

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

	SCITX(back);
	Cla1ForceTask1andWait();
	WAITSTEP;

	GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;
	PieCtrlRegs.PIEACK.bit.ACK1 = 1;
}

