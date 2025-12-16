## 目录
* [简介](#简介)
* [配置](#配置)
* [现象](#现象)

## 简介
STM32F407ZGT6 最小系统配置

## 配置

### 生成设置
- Project Manager
  - Project
    * Toolchain / IDE: <u>MDK-ARM</u>
  - Code Generator
    - STM32Cube MCU packages and embedded software packs
      * Copy only the necessary library files: <u>select</u>
    - Generated files
      * Generate peripheral initialization as a pair of '.c/.h' files per peripheral: <u>select</u>
      * Backup previously generated files when re-generating: <u>deselect</u>
      * Keep User Code when re-generating: <u>select</u>
      * Delete previously generated files when not re-generated: <u>select</u>

### 系统基本配置
- Pinout & Configuration
  - System Core
    - SYS
      - Mode
        * Debug: <u>Serial Wire</u>
        * Timebase Source: <u>TIM6</u>
    - RCC
      - Mode
        * High Speed Clock (HSE): <u>Crystal/Ceramic Resonator</u>
    - GPIO
      - Configuration
        - PF9#PF10 Configuration
          * GPIO output level: <u>High</u>
          * GPIO mode: <u>Output Push Pull</u>
          * GPIO Pull-up/Pull-down: <u>No pull-up and no pull-down</u>
          * Maximum output speed: <u>Very High</u>
          * User Label: <u>LED0#LED1</u>
    - NVIC
      - Configuration
          | NVIC Interrupt Table | Enabled | Preemption Priority | Sub Priority | Uses FreeRTOS functions |
          | --- | --- | --- | --- | --- |
          | System tick timer | &#x2611; | 15 | 0 | &#x2611; |
          | Time base: TIM6 global interrupt | &#x2611; | 0 | 0 | &#x2610; |
  - Middleware and Software Packs
    - FREERTOS
      - Configuration
        - Tasks and Queues
          - defaultTask
            * Task Name: <u>defaultTask</u>
            * Priority: <u>osPriorityNormal</u>
            * Stack Size (Words): <u>128</u>
            * Entry Function: <u>StartDefaultTask</u>
            * Code Generation Option: <u>As weak</u>
            * Parameter: <u>NULL</u>
            * Allocation: <u>Static</u>
            * Buffer Name: <u>defaultTaskBuffer</u>
            * Control Block Name: <u>defaultTaskControlBlock</u>
          - BlinkLED0Task
            * Task Name: <u>BlinkLED0Task</u>
            * Priority: <u>osPriorityNormal</u>
            * Stack Size (Words): <u>128</u>
            * Entry Function: <u>BlinkLED0TaskFunc</u>
            * Code Generation Option: <u>As weak</u>
            * Parameter: <u>NULL</u>
            * Allocation: <u>Static</u>
            * Buffer Name: <u>BlinkLED0TaskBuffer</u>
            * Control Block Name: <u>BlinkLED0TaskControlBlock</u>
          - BlinkLED1Task
            * Task Name: <u>BlinkLED1Task</u>
            * Priority: <u>osPriorityNormal</u>
            * Stack Size (Words): <u>128</u>
            * Entry Function: <u>BlinkLED1TaskFunc</u>
            * Code Generation Option: <u>As weak</u>
            * Parameter: <u>NULL</u>
            * Allocation: <u>Static</u>
            * Buffer Name: <u>BlinkLED1TaskBuffer</u>
            * Control Block Name: <u>BlinkLED1TaskControlBlock</u>
  - Clock Configuration
    * HCLK (MHz): <u>168</u>

## 现象
无