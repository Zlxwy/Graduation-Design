#ifndef __TASK_ALL_H__
#define __TASK_ALL_H__

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "queue.h"
#include "task.h"
#include "main.h"

void BlinkLED0TaskFunc(void *argument);
void BlinkLED1TaskFunc(void *argument);

#endif
