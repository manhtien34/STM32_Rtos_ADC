#include "config_rtos.h"
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osMessageQId myQueue01Handle;
osMutexId myMutex01Handle;
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
 void create_rtos(void){
 // CONFIG RTOS	
  osMutexDef(myMutex01);
  myMutex01Handle = osMutexCreate(osMutex(myMutex01));
  osMessageQDef(myQueue01, 16, uint16_t);
  myQueue01Handle = osMessageCreate(osMessageQ(myQueue01), NULL);
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
  osThreadDef(myTask02, StartTask02, osPriorityIdle, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);
 
 }