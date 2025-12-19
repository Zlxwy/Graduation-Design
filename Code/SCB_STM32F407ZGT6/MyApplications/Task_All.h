#ifndef __TASK_ALL_H__
#define __TASK_ALL_H__

/*C语言标准库头文件*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*芯片平台、FreeRTOS头文件*/
#include "stm32f4xx_hal.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "queue.h"
#include "task.h"
#include "main.h"

/*自定义头文件*/
#include "MainCmnct.h"
#include "UartStream.h"
#include "UartDebug.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;
#define UART_DEBUG  &huart1
#define UART_MAINCMNCT  &huart3

/*以下这些任务线程函数，其实在freertos.c中是声明过的，这里再重复声明一下，是为了方便在其他文件中调用*/
void MainCmnctTaskFunc(void *argument); // 主通信线程
void BlinkLED0TaskFunc(void *argument); // LED0闪烁线程
void BlinkLED1TaskFunc(void *argument); // LED1闪烁线程
void UartTestTaskFunc(void *argument); // UART测试线程

/*以下这些是一些辅助函数*/
bool MainCmnctTask_IsInitOkay(void); // 查询主通信线程是否初始化完成

#endif
