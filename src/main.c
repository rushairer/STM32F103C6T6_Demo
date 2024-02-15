/*
 * ************************************************
 *
 *              STM32 blink gcc demo
 *
 *  CPU: STM32F103C6 & STM32F103C8
 *  PIN: PA0 & PC13
 *
 * ************************************************
 */

#include "stm32f10x.h"

#define LED_PERIPH  RCC_APB2Periph_GPIOA
#define LED_PORT    GPIOA
#define LED_PIN     GPIO_Pin_0

#define LED2_PERIPH RCC_APB2Periph_GPIOC
#define LED2_PORT   GPIOC
#define LED2_PIN    GPIO_Pin_13

void delay(int x)
{
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 1000; j++)
            __NOP();
    }
}

int main()
{
    GPIO_InitTypeDef gpioDef;
    RCC_APB2PeriphClockCmd(LED_PERIPH, ENABLE);
    gpioDef.GPIO_Mode  = GPIO_Mode_Out_PP;
    gpioDef.GPIO_Pin   = LED_PIN;
    gpioDef.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &gpioDef);

    GPIO_InitTypeDef gpio2Def;
    RCC_APB2PeriphClockCmd(LED2_PERIPH, ENABLE);
    gpio2Def.GPIO_Mode  = GPIO_Mode_Out_PP;
    gpio2Def.GPIO_Pin   = LED2_PIN;
    gpio2Def.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED2_PORT, &gpio2Def);

    while (1) {
        GPIO_WriteBit(LED_PORT, LED_PIN, (BitAction)!GPIO_ReadInputDataBit(LED_PORT, LED_PIN));
        GPIO_WriteBit(LED2_PORT, LED2_PIN, (BitAction)!GPIO_ReadInputDataBit(LED2_PORT, LED2_PIN));
        delay(5000);
    }
}
