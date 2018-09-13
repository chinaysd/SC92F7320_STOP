#ifndef _KEY_H_
#define _KEY_H_

#include "sc92f732x_c.h"

#define KEY_ENABLE       1
#define KEY_DISABLE      0

#if KEY_ENABLE

#define KEY_PIN          P20

#endif




void Key_Init(void);

unsigned char Key_Down(void);




#endif