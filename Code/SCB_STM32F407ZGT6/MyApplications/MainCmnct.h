#ifndef __MAIN_CMNCT_H__
#define __MAIN_CMNCT_H__

#include "stm32f4xx_hal.h"
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "UartStream.h"

extern volatile bool IsMainCmnctTaskInitOkay;

extern UartStream_t gMainCmnctStream; // 主通信流对象

#endif
