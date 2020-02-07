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



volatile u32 counter=0,c1,c2,c3,flag=0;

void __vector_6 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_6 (void)
{
	if (flag==0)
	{
		c1=ICR1;
		counter=0;
		CLR_BIT(TCCR1B,6);
	}
	else if(flag==1)
	{
		c2=ICR1+(counter*65536);
		SET_BIT(TCCR1B,6);
	}

	else if(flag==2)
	{
		c3=ICR1+(counter*65536);
		CLR_BIT(TIMSK,5);//=0b11011111;// close the ICE interrupt

	}
	flag++;
}




void __vector_9 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_9 (void)
{
	counter++;
}


int main (void)
{
	PortInitialization();
//	CLCD_voidInitalization();
//	CLCD_voidSetCursor(0,0);
//	CLCD_voidWriteString("Duty: ");
	Timer0_voidInit();
	timer1_pwm_init();

	while(1)
	{
//		if(flag==3)
//		{
//			u32 duty=((c2-c1)*100/(c3-c1));
//			u32 freq=(8000000/(c3-c1));
//
//			//LCD_writecommand(1);
//			CLCD_voidSetCursor(0,0);
//			CLCD_voidWriteString("Duty: ");
//			//LCD_setposition(0,5);
//			LCDWriteInt(duty);
//
//			CLCD_voidSetCursor(1,0);
//			CLCD_voidWriteString("Freq: ");
//			//LCD_setposition(1,5);
//			LCDWriteInt(freq);
//
//			flag=0;
//			SET_BIT(TIFR,5); // to clear the Input Capture Flag "bit 5"
//			SET_BIT(TIMSK,5);// to re-enable the Input Capture Interrupt "bit 5"
//		}
	}
	return -1;
}
