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
    UartStream_ReadState_e status =
      UartStream_Read(&gMainCmnctStream,
        gMainCmnctBuffer,
        pdMS_TO_TICKS(2000)
      ); // 读取主通信流对象

    switch (status) {
      case UartStream_ReadState_None: // 一点儿数据都没读到，超时了
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        break;
      case UartStream_ReadState_CrcErr: // 完整读到了数据，但CRC校验错误
        break;
      case UartStream_ReadState_Timeout: // 读了一部分数据，但中途超时退出了
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        break;
      case UartStream_ReadState_Successful: // 完整读到了数据，CRC校验也通过了
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
        break;
    }

    // if (status == UartStream_ReadState_Successful) {
    //   if ( gMainCmnctBuffer[0] == 0x53
    //     && gMainCmnctBuffer[1] == 0xCA
    //     && gMainCmnctBuffer[2] == 0x00
    //     && gMainCmnctBuffer[3] == 0x00
    //     && gMainCmnctBuffer[4] == 0x00
    //     && gMainCmnctBuffer[5] == 0x05
    //     && gMainCmnctBuffer[6] == 0x67
    //     && gMainCmnctBuffer[7] == 0x68
    //     && gMainCmnctBuffer[8] == 0x6A
    //     && gMainCmnctBuffer[9] == 0x6D
    //     && gMainCmnctBuffer[10] == 0x6F
    //     && gMainCmnctBuffer[11] == 0xE2
    //     && gMainCmnctBuffer[12] == 0x7F ) {
    //     HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    //   }
    //   HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    // } else if (status == UartStream_ReadState_Timeout) {
    //   // HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    // }

    osDelay(pdMS_TO_TICKS(10));
  }
}
