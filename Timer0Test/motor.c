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


void MOTOR_Init(void (*pointerCallBack)(void))
{
	//u32 val=(Copy_percentage/100)*256;
	Timer_config(NORMAL,T0NoPrescale_CLOCK,OC0_Disconnected_WFM,0,pointerCallBack,Enable,Disable);
}
