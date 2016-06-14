#include "timer.h"

void Timer_Init(void)
{
	InitCpuTimers();
//	ConfigCpuTimer(&CpuTimer0, 60, 1000000);
	ConfigCpuTimer(&CpuTimer1, 60, 500000);		//let timer1 into isr at frist
//	CpuTimer0Regs.TCR.all = 0x4000;
	CpuTimer1Regs.TCR.all = 0x4000;
	IER |= M_INT1;
	IER |= M_INT13;
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

	EALLOW;
//	PieVectTable.TINT0 = &TIM0_ISR;
	PieVectTable.TINT1 = &TIM1_ISR;
	EDIS;

	EINT;
	ERTM;
}


__interrupt void TIM0_ISR(void)
{
	GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;
	PieCtrlRegs.PIEACK.all = 1;
}


__interrupt void TIM1_ISR(void)
{


 	//test interrupt nesting  1
	IER |= 0x0001;
	IER &= 0x0001;
	PieCtrlRegs.PIEIER1.all &= 0x0010;		//timer0 interrupt
	PieCtrlRegs.PIEACK.all = 0xFFFF;

	EINT;
	while(1){}

/*
	//test interrupt nesting  2
	int i;
	Uint16 TempPIE = PieCtrlRegs.PIEIER1.all;

	IER |= 0x0001;
	IER &= 0x0001;
	PieCtrlRegs.PIEIER1.all &= 0x0040;		//timer0 interrupt
	PieCtrlRegs.PIEACK.all = 0xFFFF;

//	asm("		NOP");
	EINT;
	for(i=0;i<30000;i++){}
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIE;
*/

	//normal
//	PieCtrlRegs.PIEACK.all = 1;
}
