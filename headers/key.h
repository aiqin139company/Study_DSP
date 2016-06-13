#ifndef _KEY_H_
#define _KEY_H_

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

#define KEY	GpioDataRegs.GPADAT.bit.GPIO18

void Key_Init(void);

#endif

