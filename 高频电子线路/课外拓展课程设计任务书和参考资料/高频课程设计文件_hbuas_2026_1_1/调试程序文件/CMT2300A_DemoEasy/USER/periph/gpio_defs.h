#ifndef __GPIO_DEFS_H
#define __GPIO_DEFS_H

#include "stm32f10x_conf.h"

/* CMT2300A interface for the STM32F103C8T6 board. */
#define CMT_CSB_GPIO                GPIOB
#define CMT_CSB_GPIO_PIN            GPIO_Pin_12

#define CMT_FCSB_GPIO               GPIOB
#define CMT_FCSB_GPIO_PIN           GPIO_Pin_13

#define CMT_SCL_GPIO                GPIOB
#define CMT_SCL_GPIO_PIN            GPIO_Pin_14

#define CMT_SDA_GPIO                GPIOB
#define CMT_SDA_GPIO_PIN            GPIO_Pin_15

#define CMT_GPIO1_GPIO              GPIOB
#define CMT_GPIO1_GPIO_PIN          GPIO_Pin_10

#define CMT_GPIO2_GPIO              GPIOB
#define CMT_GPIO2_GPIO_PIN          GPIO_Pin_11

#define CMT_GPIO3_GPIO              GPIOB
#define CMT_GPIO3_GPIO_PIN          GPIO_Pin_1

#define CMT_GPIO4_GPIO              GPIOB
#define CMT_GPIO4_GPIO_PIN          GPIO_Pin_0

/* Optional local status LED on PB2. */
#define LED1_GPIO                   GPIOB
#define LED1_GPIO_PIN               GPIO_Pin_2

#define SET_GPIO_OUT(x)             GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_Out_PP)
#define SET_GPIO_IN(x)              GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_IN_FLOATING)
#define SET_GPIO_OD(x)              GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_Out_OD)
#define SET_GPIO_AIN(x)             GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AIN)
#define SET_GPIO_AFOUT(x)           GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AF_PP)
#define SET_GPIO_AFOD(x)            GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AF_OD)
#define SET_GPIO_H(x)               (x->BSRR = x##_PIN)
#define SET_GPIO_L(x)               (x->BRR  = x##_PIN)
#define READ_GPIO_PIN(x)            (((x->IDR & x##_PIN) != Bit_RESET) ? 1 : 0)

#endif
