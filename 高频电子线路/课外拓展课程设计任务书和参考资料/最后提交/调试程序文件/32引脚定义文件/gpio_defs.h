#ifndef __GPIO_DEFS_H
#define __GPIO_DEFS_H

#include "stm32f10x_conf.h"

/* ---------- ???????? (???) ---------- */
// 1. CSB (??) -> ? PB12
#define CMT_CSB_GPIO                GPIOB
#define CMT_CSB_GPIO_PIN            GPIO_Pin_12

// 2. FCSB (FIFO??) -> ? PB13
#define CMT_FCSB_GPIO               GPIOB
#define CMT_FCSB_GPIO_PIN           GPIO_Pin_13

// 3. SCLK (??) -> ? PB14
#define CMT_SCL_GPIO                GPIOB
#define CMT_SCL_GPIO_PIN            GPIO_Pin_14

// 4. SDIO (??) -> ? PB15
#define CMT_SDA_GPIO                GPIOB
#define CMT_SDA_GPIO_PIN            GPIO_Pin_15

// 5. GPIO1 (??/??) -> ? PB10
#define CMT_GPIO1_GPIO              GPIOB
#define CMT_GPIO1_GPIO_PIN          GPIO_Pin_10

// 6. GPIO2 (??/??) -> ? PB11
#define CMT_GPIO2_GPIO              GPIOB
#define CMT_GPIO2_GPIO_PIN          GPIO_Pin_11

// 7. GPIO3 (????/??) -> ? PB1
// (?????????GPIO3,???????,??????????)
#define CMT_GPIO3_GPIO              GPIOB
#define CMT_GPIO3_GPIO_PIN          GPIO_Pin_1

// 8. GPIO4 (????,?????????)
#define CMT_GPIO4_GPIO              GPIOB
#define CMT_GPIO4_GPIO_PIN          GPIO_Pin_0

//---------------------------------------------------------------???----------------------------------------------------//

#define LCD12864_CS_GPIO            GPIOE
#define LCD12864_CS_GPIO_PIN        GPIO_Pin_1

#define LCD12864_RESET_GPIO         GPIOE
#define LCD12864_RESET_GPIO_PIN     GPIO_Pin_0

#define LCD12864_RS_GPIO            GPIOB
#define LCD12864_RS_GPIO_PIN        GPIO_Pin_9

#define LCD12864_SDA_GPIO           GPIOB
#define LCD12864_SDA_GPIO_PIN       GPIO_Pin_8

#define LCD12864_SCK_GPIO           GPIOB
#define LCD12864_SCK_GPIO_PIN       GPIO_Pin_7

#define LCD12864_LED_GPIO           GPIOB
#define LCD12864_LED_GPIO_PIN       GPIO_Pin_5

#define LED1_GPIO                   GPIOB
#define LED1_GPIO_PIN               GPIO_Pin_2

#define LED2_GPIO                   GPIOE
#define LED2_GPIO_PIN               GPIO_Pin_7

#define LED3_GPIO                   GPIOE
#define LED3_GPIO_PIN               GPIO_Pin_13

#define KEY1_GPIO                   GPIOE
#define KEY1_GPIO_PIN               GPIO_Pin_8

#define KEY2_GPIO                   GPIOE
#define KEY2_GPIO_PIN               GPIO_Pin_9

#define KEY3_GPIO                   GPIOE
#define KEY3_GPIO_PIN               GPIO_Pin_10

#define KEY4_GPIO                   GPIOE
#define KEY4_GPIO_PIN               GPIO_Pin_11

#define KEY5_GPIO                   GPIOE
#define KEY5_GPIO_PIN               GPIO_Pin_12

#define BUZZER_GPIO                 GPIOA
#define BUZZER_GPIO_PIN             GPIO_Pin_10

#define SET_GPIO_OUT(x)             GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_Out_PP)
#define SET_GPIO_IN(x)              GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_IN_FLOATING)
#define SET_GPIO_OD(x)              GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_Out_OD)
#define SET_GPIO_AIN(x)             GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AIN)
#define SET_GPIO_AFOUT(x)           GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AF_PP)
#define SET_GPIO_AFOD(x)            GPIO_Pin_Setting(x, x##_PIN, GPIO_Speed_50MHz, GPIO_Mode_AF_OD)
#define SET_GPIO_H(x)               (x->BSRR = x##_PIN) //GPIO_SetBits(x, x##_PIN)
#define SET_GPIO_L(x)               (x->BRR  = x##_PIN) //GPIO_ResetBits(x, x##_PIN)
#define READ_GPIO_PIN(x)            (((x->IDR & x##_PIN)!=Bit_RESET) ?1 :0) //GPIO_ReadInputDataBit(x, x##_PIN)

#endif
