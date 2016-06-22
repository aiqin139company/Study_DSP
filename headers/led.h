#ifndef _LED_H_
#define _LED_H_

#include "common.h"

#define LED	GpioDataRegs.GPADAT.bit.GPIO7

void Led_Init(void);

#endif
