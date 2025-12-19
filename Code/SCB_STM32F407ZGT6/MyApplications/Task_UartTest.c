#include "Task_All.h"

void UartTestTaskFunc(void *argument) {
  while (!IsMainCmnctTaskInitOkay) osDelay(pdMS_TO_TICKS(10));
  
  uint64_t a = 0;
  while (true) {
    // uart_printf(UART_MAINCMNCT, "[%d] hello world (From Uart_MAINCMNCT)\n", a);
    // uart_printf(UART_DEBUG, "[%d] %s (From Uart_DEBUG)\n", a, gMainCmnctStream.RecvBuffer);
    uart_printf(UART_DEBUG, "%s (From Uart_DEBUG)\n", gMainCmnctStream.RecvBuffer);
    a++;
    osDelay(pdMS_TO_TICKS(1000));
  }
}
