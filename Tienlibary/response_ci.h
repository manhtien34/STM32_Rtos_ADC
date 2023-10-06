#ifndef RESPONSE_CI_H
#define RESPONSE_CI_H
#include "stm32f1xx_hal.h"
void response_init2(UART_HandleTypeDef *_huart_print);
void response_print2(const char* str,...);
#endif




