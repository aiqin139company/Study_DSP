/*
 * qep.h
 *
 *  Created on: 2016��6��22��
 *      Author: Admin
 */

#ifndef HEADERS_QEP_H_
#define HEADERS_QEP_H_

#include "common.h"

void Qep_Init(void);
void POSSPEED_Init(void);
__interrupt void EQEP_ISR(void);


#endif /* HEADERS_QEP_H_ */
