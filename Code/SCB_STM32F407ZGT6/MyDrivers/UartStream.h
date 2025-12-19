#ifndef __UART_STREAM_H__
#define __UART_STREAM_H__

#include "stm32f4xx_hal.h"
#include "main.h"
#include <string.h>
#include <stdint.h>

// # 第1,2个字节
//   - 0x53 0xCA为请求帧帧头
//   - 0x53 0x35为应答帧帧头
//   - 0x53 0x96为事件帧帧头
// # 第3,4,5,6个字节
//   - 有效数据部分长度，大端顺序
// # 在7个字节开始
//   - 有效数据部分
// # 最后2个字节
//   - 从第一个字节开始，到有效数据的最后一个字节，所有字节的CRC16校验码，大端顺序

typedef enum {
  UartStream_FrameHead1 = 0x53, // 帧头1
  UartStream_FrameHead2_Req = 0xCA, // 帧头2 请求帧
  UartStream_FrameHead2_Res = 0x35, // 帧头2 应答帧
  UartStream_FrameHead2_Event = 0x96, // 帧头2 事件帧
} UartStream_FrameHead_e;

#define UART_STREAM_RECV_BUFFER_SIZE  512

typedef struct {
  UART_HandleTypeDef *huart;
  uint8_t RecvBuffer[UART_STREAM_RECV_BUFFER_SIZE];
  uint32_t RecvBufferCount;
  uint8_t *RecvPtr; // 接收指针，指向当前接收字节的位置
  uint8_t *ReadPtr; // 读取指针，指向当前读取字节的位置
} UartStream_t;

uint16_t UartStream_CRC16Cal(const uint8_t *bytes, uint32_t len);

void UartStream_Init(UartStream_t *cThis, UART_HandleTypeDef *huart);
void UartStream_FuncCalled_InUartRecvInterrupt(UartStream_t *cThis);

#endif
