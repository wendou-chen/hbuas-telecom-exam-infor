/*
 * ??????? - 433MHz ???? "??????" (Hex ???)
 * ??:STM32F103 + CMT2300A
 * ??:?????????????????????
 */

#include "typedefs.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h> // ????,?? uint8_t ????
#include "common.h"
#include "system.h"
#include "gpio_defs.h"
#include "radio.h"
#include "stm32f10x.h"
#include "stm32f10x_usart.h"

// ============================================================
// ?? ?????? (???????????!!!)
// ============================================================
// 1 = ??? (TX), 0 = ??? (RX)
#define IS_TRANSMITTER   1

// ============================================================
// ?? ????
// ============================================================
#define RF_PACKET_SIZE   32

static u8 g_rxBuffer[RF_PACKET_SIZE];
static u8 g_txBuffer[RF_PACKET_SIZE];

// ? ?? P0: ?? Hex ???????,???? "????" ????
// ??:"??????" (GB2312??)
// ?????????? GBK/GB2312 ????
const uint8_t TARGET_DATA[] = {
    0xCE, 0xD2, // ?
    0xB0, 0xAE, // ?
    0xB8, 0xDF, // ?
    0xC6, 0xB5, // ?
    0xB5, 0xE7, // ?
    0xD7, 0xD3  // ?
};

// ????? (PA9=TX, PA10=RX, 115200)
void My_UART1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

    // TX: PA9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // RX: PA10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 115200
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}

// ??? printf ???
int fputc(int ch, FILE *f)
{
    USART_SendData(USART1, (uint8_t) ch);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
    return ch;
}

// ??????
void Delay_ms_Simple(volatile uint32_t ms)
{
    volatile uint32_t i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 8000; j++);
}

// ============================================================
// ?? ???
// ============================================================
int main(void)
{
    time_server_init();
    SystemTimerDelay_Config();
    GPIO_Config();
    My_UART1_Init();

    printf("\r\nSystem Init OK! (Hex Fix Mode)\r\n");

    RF_Init();

    if(FALSE == CMT2300A_IsExist()) {
        printf("Error: CMT2300A Not Found! Check Wiring!\r\n");
        // ?????????,????????
        while(1);
    }
    else {
        printf("CMT2300A Ready! Mode: %s\r\n", IS_TRANSMITTER ? "TX" : "RX");
    }

    while(1)
    {
        EnumRFResult result = RF_Process();

#if IS_TRANSMITTER
        // ======================== ?????? (TX) ========================
        switch(result)
        {
            case RF_IDLE:
            {
                // ? ?? P1: ???? Variable Length (???) ??
                // ????:[?0??=??] + [????=??]
                uint8_t data_len = sizeof(TARGET_DATA);

                // ???????? FIFO (??32)
                if(data_len > 30) data_len = 30;

                g_txBuffer[0] = data_len; // ?0????
                memcpy(&g_txBuffer[1], TARGET_DATA, data_len); // ?1??????

                // ?????? = ???? + 1????
                RF_StartTx(g_txBuffer, data_len + 1, 1000);

                printf("Sending Data...\r\n");
                break;
            }
            case RF_TX_DONE:
            {
                printf("TX Done.\r\n");
                Delay_ms_Simple(1000); // ??1???
                break;
            }
            case RF_TX_TIMEOUT:
                printf("TX Timeout, Resetting...\r\n");
                RF_Init();
                break;
            case RF_ERROR:
                printf("TX Error, Resetting...\r\n");
                RF_Init();
                break;
            default: break;
        }

#else
        // ======================== ?????? (RX) ========================
        switch(result)
        {
            case RF_IDLE:
            {
                // ????
                RF_StartRx(g_rxBuffer, RF_PACKET_SIZE, INFINITE);
                break;
            }
            case RF_RX_DONE:
            {
                // ? ?????
                // ??????????,???????,????? g_rxBuffer ??
                // g_rxBuffer[0] ????????????

                uint8_t len = g_rxBuffer[0];

                // ???????????? (?????12??)
                if(len > 30 || len == 0) {
                     printf("Rx Invalid Len: %d\r\n", len);
                }
                else {
                    // ?????????? '\0',?? printf ?????
                    g_rxBuffer[len + 1] = '\0';

                    // ??1??????? (???0????)
                    // ???? (char*) ??????
                    printf("Received: %s\r\n", (char*)&g_rxBuffer[1]);
                    printf("RSSI: %d dBm\r\n", CMT2300A_GetRssiDBm());
                }
                break;
            }
            case RF_RX_TIMEOUT:
                RF_Init();
                break;
            case RF_ERROR:
                printf("RX Error!\r\n");
                RF_Init();
                break;
            default: break;
        }
#endif
    }
}
