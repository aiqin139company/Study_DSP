/*
 * common.h
 *
 *  Created on: 2016Äê6ÔÂ22ÈÕ
 *      Author: Admin
 */

#ifndef HEADERS_COMMON_H_
#define HEADERS_COMMON_H_

#ifndef uchar
#define uchar unsigned char
#endif

#include "DSP2803x_Device.h"
#include "DSP2803x_Examples.h"
#include "timer.h"
#include "key.h"
#include "Xint.h"
#include "led.h"
#include "Sci.h"
#include "qep.h"
#include "stdio.h"
#include "pwm.h"
#include "motor.h"
#include "cap.h"

extern uchar motorEn;

void Delay_us(long timer);

#endif /* HEADERS_COMMON_H_ */
