#ifndef MOTOR_H
#define MOTOR_H
#include "stm32f4xx_hal.h"
#include "stm32f446xx.h"
#include "stm32f4xx_hal_tim.h"
#include "main.h"


#define TIMER_CLOCK 84000000UL
#define PWM_FREQ    200000UL
#define ARR_TIM1 ((TIMER_CLOCK / PWM_FREQ) - 1)
#define ARR_TIM2 ((TIMER_CLOCK / 2 / PWM_FREQ) - 1)


void motor_init(TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3);
void motor_drive();

#endif