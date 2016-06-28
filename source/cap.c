/*
 * cap.c
 *
 *  Created on: 2016��6��27��
 *      Author: Admin
 */

#include "cap.h"

Uint32 Period1;

#ifdef TEST_PIN
#define T_Pin  GpioDataRegs.GPBDAT.bit.GPIO39
void Test_Pin(void)
{
	EALLOW;
	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;
	GpioDataRegs.GPBDAT.bit.GPIO39 = 0;
	EDIS;
}
#endif

void eCAP_Init(void)
{
#ifdef TEST_PIN
	Test_Pin();
#endif
	//GPIO Config
	EALLOW;
	GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;     // Enable pull-up on GPIO19 (CAP1)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 0;   // Synch to SYSCLKOUT GPIO19 (CAP1)
	GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 3;    // Configure GPIO19 as CAP1
	EDIS;

	//Interrupt Config
	EALLOW;
	PieVectTable.ECAP1_INT = &eCAP_ISR;
	IER |= M_INT4;						// Enable CPU INT4 which is connected to ECAP1-4 INT:
	PieCtrlRegs.PIEIER4.bit.INTx1 = 1;	// Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
	EDIS;

	// Code snippet for CAP mode Delta Time, Rising and Falling
	// edge triggers
	// Initialization Time
	//=======================
	// ECAP module 1 config
	EALLOW;
	ECap1Regs.ECEINT.all = 0x0000;             // Disable all capture interrupts
	ECap1Regs.ECCLR.all = 0xFFFF;              // Clear all CAP interrupt flags
	ECap1Regs.ECCTL1.bit.CAPLDEN = 0;          // Disable CAP1-CAP4 register loads
	ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0;        // Make sure the counter is stopped

	// Configure peripheral registers
	ECap1Regs.ECCTL2.bit.CONT_ONESHT = 1;      // One-shot
	ECap1Regs.ECCTL2.bit.STOP_WRAP = 0;        // Stop at 1 event
	ECap1Regs.ECCTL1.bit.CAP1POL = 0;          // Rising edge
	ECap1Regs.ECCTL1.bit.CTRRST1 = 1;          // Difference operation
	ECap1Regs.ECCTL1.bit.CTRRST2 = 1;          // Difference operation
	ECap1Regs.ECCTL2.bit.SYNCI_EN = 1;         // Enable sync in
	ECap1Regs.ECCTL2.bit.SYNCO_SEL = 0;        // Pass through
	ECap1Regs.ECCTL1.bit.CAPLDEN = 1;          // Enable capture units

	ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1;        // Start Counter
	ECap1Regs.ECCTL2.bit.REARM = 1;            // arm one-shot
	ECap1Regs.ECCTL1.bit.CAPLDEN = 1;          // Enable CAP1-CAP4 register loads
	ECap1Regs.ECEINT.bit.CEVT1 = 1;            // 1 event = interrupt
	EDIS;

}

__interrupt void eCAP_ISR(void)
{
#ifdef TEST_PIN
	T_Pin = 1;
#endif

	Period1 = ECap1Regs.CAP1;
	SCITX(Period1);

	//CLR Interrupt Flag
	ECap1Regs.ECCLR.bit.CEVT1 = 1;
	ECap1Regs.ECCLR.bit.INT = 1;
	ECap1Regs.ECCTL2.bit.REARM = 1;
	PieCtrlRegs.PIEACK.bit.ACK4 = 1;

#ifdef TEST_PIN
	T_Pin = 0;
#endif
}


