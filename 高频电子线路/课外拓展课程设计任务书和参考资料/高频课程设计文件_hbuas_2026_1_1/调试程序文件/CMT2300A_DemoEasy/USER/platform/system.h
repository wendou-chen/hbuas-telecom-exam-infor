
#ifndef _SYSTEM_DEF_H
#define _SYSTEM_DEF_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f10x_conf.h"
#include "time_server.h"

void SystemTimerDelay_Config(void);

void NVIC_Config(void);
void EXTI_Config(void);
void EXTI_ConfigOne(u32 nExitLine, EXTITrigger_TypeDef exitTrigger);

#ifdef __cplusplus
}
#endif

#endif
