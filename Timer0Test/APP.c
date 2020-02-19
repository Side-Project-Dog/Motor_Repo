/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Mohamed Waleed
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#define FCPU 8000000
#include<avr/delay.h>
#include"Timer0.h"
#include"CLCD_interfac.h"
#include"DIO_register.h"
#include"motor.h"


/*
 * ISR function of the timer
 * tick time=1msec
 * 1 sec high
 * 1 sec low
 * duty cycle 50%
 *
 *
 *if you need to add another pin to out PWM you should write more lines in the below function only
 *
 *
 * */


static u32 Timer0_OV_Counter=0;
static u32 Counter=0;
u32 Duty1=1000;
void LEDON(void)
{
	Timer0_OV_Counter++;
	if(22==Timer0_OV_Counter)   //tick time 1 msec
	{
		Timer0_OV_Counter=0;
		Counter++;
	}

//da example lw 3aiza tzwdo pins zwdin zi el condition eli ta7t
//////////////////////////////////////////////////////////
	if(Counter<=Duty1)   //(Duty 1 sec)   (1000 counts *1msec(tick time) =1sec)
	{
		SetPinValue('A',0,1);
	}
	else if(Counter==2000) //period 2 sec
	{
		Counter=0;
	}
	else  ///1 sec low
		SetPinValue('A',0,0);
///////////////////////////////////////////////


}

int main (void)
{
	PortInitialization();
	MOTOR_Init(LEDON);
	while(1)
	{

	}
	return -1;
}
