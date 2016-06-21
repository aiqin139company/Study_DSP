/*
 * cla.h
 *
 *  Created on: 2016Äê6ÔÂ17ÈÕ
 *      Author: Admin
 */

#ifndef HEADERS_CLA_H_
#define HEADERS_CLA_H_

#include "DSP2803x_Cla_defines.h"

extern unsigned char send;
extern unsigned char back;

void CLA_C_Init(void);

__interrupt void Cla1Task1(void);
__interrupt void cla1_task1_isr(void);


#endif /* HEADERS_CLA_H_ */


