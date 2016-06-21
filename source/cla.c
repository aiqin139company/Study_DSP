/*
 * cla.c
 *
 *  Created on: 2016Äê6ÔÂ17ÈÕ
 *      Author: Admin
 */
#include "cla.h"

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

#include "Sci.h"

#define CLARAM0_ENABLE	1
#define CLARAM1_ENABLE	1

#pragma DATA_SECTION(send,"CpuToCla1MsgRAM");
unsigned char send = 10;
#pragma DATA_SECTION(back,"Cla1ToCpuMsgRAM");
unsigned char back;

//Linker defined vars
extern Uint16 Cla1Prog_Start;
extern Uint16 Cla1funcsLoadStart;
extern Uint16 Cla1funcsLoadEnd;
extern Uint16 Cla1funcsRunStart;
extern Uint16 Cla1funcsLoadSize;
extern Uint16 Cla1mathTablesLoadStart;
extern Uint16 Cla1mathTablesRunStart;
extern Uint16 Cla1mathTablesLoadSize;

void CLA_C_Init(void)
{

   /*  Assign user defined ISR to the PIE vector table */
   EALLOW;
   PieVectTable.CLA1_INT1  = &cla1_task1_isr;
   EDIS;

   //Copy over the CLA code and Tables
    memcpy(&Cla1funcsRunStart, &Cla1funcsLoadStart, (Uint32)&Cla1funcsLoadSize);

    /*  Compute all CLA task vectors */
    EALLOW;
    Cla1Regs.MVECT1 = (Uint16)((Uint32)&Cla1Task1 - (Uint32)&Cla1Prog_Start);
    EDIS;

	//  Step 3 : Mapping CLA tasks
	/*  All tasks are enabled and will be started by an ePWM trigger
	*  Map CLA program memory to the CLA and enable software breakpoints
	*/
	EALLOW;
	Cla1Regs.MPISRCSEL1.bit.PERINT1SEL 	= CLA_INT1_NONE;
	Cla1Regs.MIER.all 		 		    = 0x00FF;
	EDIS;


	/*  Enable CLA interrupts at the group and subgroup levels */
	PieCtrlRegs.PIEIER11.all       = 0xFFFF;
	IER |= (M_INT11 );

	/* Switch the CLA program space to the CLA and enable software forcing
	* Also switch over CLA data ram 0 and 1
	*/
	EALLOW;
	Cla1Regs.MMEMCFG.bit.PROGE 	= 1;
	Cla1Regs.MCTL.bit.IACKE		= 1;
	Cla1Regs.MMEMCFG.bit.RAM0E	= CLARAM0_ENABLE;
	Cla1Regs.MMEMCFG.bit.RAM1E	= CLARAM1_ENABLE;
	EDIS;

}

__interrupt void cla1_task1_isr(void)
{
	SCITX('a');
	PieCtrlRegs.PIEACK.bit.ACK11 = 1;
}

