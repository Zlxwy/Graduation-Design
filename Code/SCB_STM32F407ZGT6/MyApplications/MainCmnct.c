/*主通信线程，该线程内的程序不应该有阻塞行为*/
#include "MainCmnct.h"
#include "Task_All.h"

volatile bool IsMainCmnctTaskInitOkay;

UartStream_t gMainCmnctStream; // 主通信流对象

void MainCmnctTaskFunc(void *argument) {
  IsMainCmnctTaskInitOkay = false;

  UartStream_Init(&gMainCmnctStream, UART_MAINCMNCT); // 初始化主通信流对象

  IsMainCmnctTaskInitOkay = true;

  while (true) {
    osDelay(pdMS_TO_TICKS(500));
  }
}
