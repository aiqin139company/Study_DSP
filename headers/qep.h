/*
 * qep.h
 *
 *  Created on: 2016Äê6ÔÂ22ÈÕ
 *      Author: Admin
 */

#ifndef HEADERS_QEP_H_
#define HEADERS_QEP_H_

#include "common.h"

#define   GLOBAL_Q       15

#include "IQMathLib.h"

typedef struct
{
	int dir;
	_iq pos;
	_iq speed;

	int cnt;
	int oldcnt;
	int test;

	void (*init)();
	void (*calc)();
} POSSPEED_TYPE;

typedef POSSPEED_TYPE *POSSPEED_PRT;

#define POSSPEED_DEFAULTS { 0,0,0,0,0,0,(void (*)(long))POSSPEED_Init, (void (*)(long))POSSPEED_Calc }

extern POSSPEED_TYPE qep_speed;

void Qep_Init(void);
void POSSPEED_Init(void);
void POSSPEED_Calc(POSSPEED_PRT);

#endif /* HEADERS_QEP_H_ */
