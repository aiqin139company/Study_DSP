#ifndef _Sci_H_
#define _Sci_H_

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"

void Sci_Init(void);
void SCITX(unsigned char dat);
unsigned char SCIRX(void);

#endif

