/*
 * qep.c
 *
 *  Created on: 2016��6��22��
 *      Author: Admin
 */

#include "qep.h"

void Qep_Init(void)
{
	EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up on GPIO21 (EQEP1B)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync to SYSCLKOUT GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;   // Sync to SYSCLKOUT GPIO21 (EQEP1B)

	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;	//Configure GPIO20 as EQEP1A
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;	//Configure GPIO21 as EQEP1B
	EDIS;

	POSSPEED_Init();
}

void POSSPEED_Init(void)
{
    EQep1Regs.QUPRD=600000;         // Unit Timer for 100Hz at 60 MHz SYSCLKOUT

    EQep1Regs.QDECCTL.bit.QSRC=00;      // QEP quadrature count mode

    EQep1Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep1Regs.QEPCTL.bit.PCRM=00;       // PCRM=00 mode - QPOSCNT reset on index event
    EQep1Regs.QEPCTL.bit.UTE=1;         // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;        // Latch on unit time out
    EQep1Regs.QPOSMAX=0xffffffff;
    EQep1Regs.QEPCTL.bit.QPEN=1;        // QEP enable

    EQep1Regs.QCAPCTL.bit.UPPS=5;       // 1/32 for unit position
    EQep1Regs.QCAPCTL.bit.CCPS=6;       // 1/64 for CAP clock
    EQep1Regs.QCAPCTL.bit.CEN=1;        // QEP Capture Enable
}

void POSSPEED_Calc(void)
{

}



