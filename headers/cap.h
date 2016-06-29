/*
 * cap.h
 *
 *  Created on: 2016Äê6ÔÂ27ÈÕ
 *      Author: Admin
 */

#ifndef HEADERS_CAP_H_
#define HEADERS_CAP_H_

#include "common.h"

#define COUNT 2000

#define eCAP_ACK()					\
	ECap1Regs.ECCLR.bit.CEVT1 = 1;	\
	ECap1Regs.ECCLR.bit.INT = 1;	\
	ECap1Regs.ECCTL2.bit.REARM = 1;	\
	PieCtrlRegs.PIEACK.bit.ACK4 = 1;

#define PIE_eCAP_CNT()					\
	EALLOW;								\
	PieVectTable.ECAP1_INT = &eCAP_CNT;	\
	EDIS;

#define PIE_eCAP_ISR()					\
	EALLOW;								\
	PieVectTable.ECAP1_INT = &eCAP_ISR;	\
	EDIS;



void eCAP_Init(void);
__interrupt void eCAP_CNT(void);
__interrupt void eCAP_ISR(void);

#endif /* HEADERS_CAP_H_ */
