#ifndef _KEY_H_
#define _KEY_H_

#include "common.h"

#define uchar unsigned char

#define KEY1	GpioDataRegs.GPADAT.bit.GPIO14
#define KEY2	GpioDataRegs.GPADAT.bit.GPIO13
#define KEY3	GpioDataRegs.GPADAT.bit.GPIO15

void Key_Init(void);

uchar Key_Scan(void);

#endif

