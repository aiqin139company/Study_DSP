#ifndef _XINT_H_
#define _XINT_H_

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

__interrupt void xint_isr(void);

void Xint_Init(void);

#endif

