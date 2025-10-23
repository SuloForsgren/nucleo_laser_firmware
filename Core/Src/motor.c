#include "motor.h"

void motor_init(TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3) 
{
    htim1->Instance = TIM1;
    htim2->Instance = TIM2;
    htim3->Instance = TIM3;

    htim1->Init.Prescaler = 0;
    htim2->Init.Prescaler = 0;
    htim3->Init.Prescaler = 0;

    htim1->Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2->Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3->Init.CounterMode = TIM_COUNTERMODE_UP;

    htim1->Init.Period = ARR_TIM1;
    htim2->Init.Period = ARR_TIM2;
    htim3->Init.Period = ARR_TIM2;

    htim1->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim2->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

    htim1->Init.RepetitionCounter = 0;
    htim2->Init.RepetitionCounter = 0;
    htim3->Init.RepetitionCounter = 0;
    
    htim1->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    htim2->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    htim3->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    if(HAL_TIM_PWM_Init(htim1) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Init(htim2) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Init(htim3) != HAL_OK) Error_Handler();

    TIM_OC_InitTypeDef sConfigOC = {0};
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = ARR_TIM2;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

    if(HAL_TIM_PWM_ConfigChannel(htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_ConfigChannel(htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_ConfigChannel(htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
    
    if(HAL_TIM_PWM_Start(htim1, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_3) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Start(htim3, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
}


void motor_drive() 
{

}