#ifndef _TIMER_H_
#define _TIMER_H_

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

#include "Sci.h"

__interrupt void TIM0_ISR(void);
__interrupt void TIM1_ISR(void);

void Timer_Init(void);

#endif
