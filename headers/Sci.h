#ifndef _Sci_H_
#define _Sci_H_

#include "common.h"

void Sci_Init(void);
void SCITX(unsigned char dat);
//void SCITX(int data);
unsigned char SCIRX(void);

#endif

