#ifndef _LED_h_
#define _LED_H_

#include "sc92f732x_c.h"


#define   LED_ENABLE     1
#define   LED_DISABLE    0


#if   LED_ENABLE
#define Led_Pin          P26

#endif



void Led_Open(void);
void Led_Close(void);
void Led_Init(void);


#endif