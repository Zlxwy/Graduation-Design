/*主通信线程，该线程内的程序不应该有阻塞行为*/
#include "MainCmnct.h"
#include "Task_All.h"

volatile bool IsMainCmnctTaskInitOkay;

UartStream_t gMainCmnctStream; // 主通信流对象
uint8_t gMainCmnctBuffer[UINT8_MAX]; // 主通信流缓冲区

void MainCmnctTaskFunc(void *argument) {
  IsMainCmnctTaskInitOkay = false; // 标记主通信线程初始化未完成

  UartStream_Init(&gMainCmnctStream, UART_MAINCMNCT); // 初始化主通信流对象

  IsMainCmnctTaskInitOkay = true; // 标记主通信线程初始化完成

  while (true) {
    UartStream_ReadStatus_e status = UartStream_Read(&gMainCmnctStream, gMainCmnctBuffer, pdMS_TO_TICKS(1000)); // 读取主通信流对象
    if (status == UartStream_ReadStatus_Successful) {
      HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    } else if (status == UartStream_ReadStatus_Timeout) {
      HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    }
    osDelay(pdMS_TO_TICKS(500));
  }
}
