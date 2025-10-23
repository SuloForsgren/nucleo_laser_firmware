#include "gpio.h"

void start_clocks() 
{
    // Enable A and B channel clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    // Enable TIMER clocks
    __HAL_RCC_TIM1_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();
}

void gpio_init() 
{
    start_clocks();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef led_struct = {0};
    led_struct.Pin = GPIO_PIN_5;
    led_struct.Mode = GPIO_MODE_OUTPUT_PP;
    led_struct.Pull = GPIO_NOPULL;
    led_struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &led_struct);

    // Init pwm pin PB10
    GPIO_InitTypeDef pwm_struct = {0};
    pwm_struct.Pin = GPIO_PIN_10;
    pwm_struct.Mode = GPIO_MODE_AF_PP;
    pwm_struct.Pull = GPIO_NOPULL;
    pwm_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    pwm_struct.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOB, &pwm_struct);

    // Init pwm pin PA8
    pwm_struct.Pin = GPIO_PIN_8;
    pwm_struct.Alternate = GPIO_AF1_TIM1;
    HAL_GPIO_Init(GPIOA, &pwm_struct);

    // Init pwm pin PB4
    pwm_struct.Pin = GPIO_PIN_4;
    pwm_struct.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &pwm_struct);    
}

void gpio_toggle() 
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}