#ifndef _LED_H_
#define _LED_H_

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

#define LED	GpioDataRegs.GPADAT.bit.GPIO7

void Led_Init(void);

#endif
