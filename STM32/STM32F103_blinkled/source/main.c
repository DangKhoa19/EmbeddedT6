#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

void TIM2_INT_Init()
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
    TIM_TimeBaseInitStruct.TIM_Period = 19; 
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);

    NVIC_InitTypeDef NVIC_InitStruct;

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

int milis = 0;

void TIM2_IRQHandler() {
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
        milis++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}

void delayMs(int delayMilis) {
    milis = 0;
    while (milis < delayMilis);
}

void config() {
    GPIO_InitTypeDef gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    gpio.GPIO_Pin = GPIO_Pin_13;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOC, &gpio);
}

int main() {
    config();
    TIM2_INT_Init();

    delayMs(100);
    while (1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delayMs(300);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delayMs(300);
    }
    return 0;
}
