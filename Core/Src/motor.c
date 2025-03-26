/*
 * motor.c
 *
 *  Created on: Mar 26, 2025
 *      Author: chifuchang
 */


#include <motor.h>

void mtr_init(void)
{
	TIM2->CCR1 = 0;
	HAL_GPIO_WritePin(MTR_CW_GPIO_Port, MTR_CW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MTR_CCW_GPIO_Port, MTR_CCW_Pin, GPIO_PIN_RESET);
}

float mtr_duty(float u)
{
	if (u > MTR_MAX) return MAX_DUTY;
	else if (u < MTR_MIN) return MIN_DUTY;
	else return (u / MTR_MAX);
}

void mtr_output(float duty_cycle)
{
	bool dir = duty_cycle > 0.;
	float pwm_val = (float)PWM_ARR * fabs(duty_cycle);
	/* PWM */
	if (pwm_val < 500) pwm_val = 500; // Avoid the motor dead zone.
	TIM2->CCR1 = pwm_val;
	HAL_GPIO_WritePin(MTR_CW_GPIO_Port, MTR_CW_Pin, !dir);
	HAL_GPIO_WritePin(MTR_CCW_GPIO_Port, MTR_CCW_Pin, dir);
}

