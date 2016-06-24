/*
 * pwm.c
 *
 *  Created on: 2016Äê6ÔÂ23ÈÕ
 *      Author: Admin
 */

#include "pwm.h"

void EPWM_Init(void)
{
	EALLOW;
	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)
/*	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)
	GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
	GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)
*/
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
/*	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
*/	EDIS;

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;	//ETWPM Module TBCLK enable/sync
	EDIS;

	InitEPwm1Example();
}


void InitEPwm1Example()
{
	EALLOW;
	// Initialization Time
	// = = = = = = = = = = = = = = = = = = = = = = = =
	EPwm1Regs.TBPRD = 1000; // Period = 601 TBCLK counts
	EPwm1Regs.CMPA.half.CMPA = 350; // Compare A = 350 TBCLK counts
	EPwm1Regs.CMPB = 200; // Compare B = 200 TBCLK counts
	EPwm1Regs.TBPHS.all = 0; // Set Phase register to zero
	EPwm1Regs.TBCTR = 0; // clear TB counter
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Phase loading disabled
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // TBCLK = SYSCLK
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // load on CTR = Zero
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; // load on CTR = Zero
	EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
	EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;
	EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;
	EDIS;
}


