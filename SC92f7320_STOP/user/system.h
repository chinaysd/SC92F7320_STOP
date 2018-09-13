#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "sc92f732x_c.h"
#include "led.h"
#include "exit_interrupt.h"
#include "stop_mode.h"
#include "TimeOut.h"
#include "timer.h"
#include "intrins.h"
#include "key.h"

#define Delay_Time      60000

void System_Init(void);
void System_Handle(void);




#endif