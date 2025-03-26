/*
 * oid.c
 *
 *  Created on: Mar 26, 2025
 *      Author: chifuchang
 */
#include "pid.h"

float pid_control(PID *pid, float pos, float ref)
{
	float output, err, err_dif;
	err = ref - pos;
	pid->err_sum += err;
	if (pid->err_sum >= pid->max_Integral)
	{
		pid->err_sum = pid->max_Integral;
	}
	else if (pid->err_sum <= -pid->max_Integral)
	{
		pid->err_sum = -pid->max_Integral;
	}
	err_dif = err - pid->err_pre;
	pid->err_pre = err;
	output = pid->Kp * err + pid->Ki * pid->err_sum + pid->Kd * err_dif;
	return output;
}


