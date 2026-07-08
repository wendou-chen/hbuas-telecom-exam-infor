#include "led.h"
#include "gpio_defs.h"
#include "common.h"
#include "time_server.h"
#include "stm32f10x_conf.h"

void led_init(void)
{
    SET_GPIO_L(LED1_GPIO);
    SET_GPIO_OUT(LED1_GPIO);
}

void led_on(u8 index)
{
    if(index == LED_INDEX1 || index == LED_ALL)
        SET_GPIO_H(LED1_GPIO);
}

void led_off(u8 index)
{
    if(index == LED_INDEX1 || index == LED_ALL)
        SET_GPIO_L(LED1_GPIO);
}

void led_reverse(u8 index)
{
    if(index == LED_INDEX1 || index == LED_ALL)
    {
        if(READ_GPIO_PIN(LED1_GPIO))
            SET_GPIO_L(LED1_GPIO);
        else
            SET_GPIO_H(LED1_GPIO);
    }
}

u8 led_is_on(u8 index)
{
    if(index == LED_INDEX1 || index == LED_ALL)
        return READ_GPIO_PIN(LED1_GPIO) ? 1 : 0;

    return 0;
}

void led1_onAutoOff_proc(void)
{
    led_off(LED_INDEX1);
}

void led_onAutoOff(u8 index, u32 ms)
{
    if(index == LED_INDEX1 || index == LED_ALL)
    {
        time_server_setDelayRunTask(DELAY_RUN_TASK_LED1, led1_onAutoOff_proc, ms);
        led_on(LED_INDEX1);
    }
}
