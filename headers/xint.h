#ifndef _XINT_H_
#define _XINT_H_

#include "common.h"

__interrupt void xint_isr(void);

void Xint_Init(void);

#endif

