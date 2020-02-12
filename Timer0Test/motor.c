/*
 * motor.c
 *
 *  Created on: Feb 12, 2020
 *      Author: ööAhmed Ibrahim
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Timer0.h"
#include"motor.h"


void MOTOR_Init(u32 Copy_percentage,void (*pointerCallBack)(void))
{
	u32 val=(Copy_percentage/100)*256;
	Timer_config(PWM,T0Prescale8_CLOCK,Clear_OC0_on_Compare_set_OC0_AtTOP_WFM,val,pointerCallBack,Enable,Enable);
}
