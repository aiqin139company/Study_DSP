#ifndef _TIMER_H_
#define _TIMER_H_

#include "common.h"

__interrupt void TIM0_ISR(void);
__interrupt void TIM1_ISR(void);

void Timer_Init(void);

#endif
