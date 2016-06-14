#include "xint.h"

void Xint_Init(void)
{
	 EALLOW;	// This is needed to write to EALLOW protected registers
	 PieVectTable.XINT2 = &xint_isr;

	 PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
	 PieCtrlRegs.PIEIER1.bit.INTx5 = 1;          // Enable PIE Group 1 INT5
	 IER |= M_INT1;                              // Enable CPU INT1
	 EINT;                                       // Enable Global Interrupts

	 GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;         // GPIO
	 GpioCtrlRegs.GPADIR.bit.GPIO18 = 0;          // input
	 GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 0;        // XINT1 Synch to SYSCLKOUT only

	 GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 18;   // XINT2 is GPIO1

	// Configure XINT2
	 XIntruptRegs.XINT2CR.bit.POLARITY = 1;      // Rising edge interrupt

	// Enable XINT1 and XINT2
	 XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2

	 EDIS;
}

__interrupt void xint_isr(void)
{
	GpioDataRegs.GPATOGGLE.bit.GPIO7 = 1;
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
