#include "response_ci.h"
#include <stdarg.h>
#include <stdio.h>
#include "string.h"

static UART_HandleTypeDef *huart_print1; 
static UART_HandleTypeDef *huart_print2; 

void response_print1(const char* str,...){// ham nay du lieu vao ma chua biet doi so. tu khoa la va_list
 char stringArray[100];
 va_list args; // khai bao
 va_start(args,str);// khai bao gia tri da tien 
 vsprintf(stringArray,str,args); 
 va_end(args);
	
HAL_UART_Transmit(huart_print1,(uint8_t *)stringArray,strlen(stringArray),100);
	
}
void response_init1(UART_HandleTypeDef  *_huart_print){
	huart_print1=_huart_print;
}
void response_print2(const char* str,...){// ham nay du lieu vao ma chua biet doi so. tu khoa la va_list
 char stringArray[100];
 va_list args; // khai bao
 va_start(args,str);// khai bao gia tri da tien 
 vsprintf(stringArray,str,args); 
 va_end(args);
	
HAL_UART_Transmit(huart_print2,(uint8_t *)stringArray,strlen(stringArray),100);
	
}
void response_init2(UART_HandleTypeDef  *_huart_print){
	huart_print2=_huart_print;
}


