/*
 * Timer0.h
 *
 *  Created on: Feb 6, 2020
 *      Author: ööAhmed Ibrahim
 */

#ifndef TIMER0_H_
#define TIMER0_H_

///timer 0
#define TCNT0 *(u8 *)0x52
#define TCCR0 *(u8 *)0x53
#define TIFR *(u8 *)0x58
#define TIMSK *(u8 *)0x59
#define OCR0 *(u8 *)0x5c

////timer 1

#define TCCR1A *(u8 *)0x4f
#define TCCR1B *(u8 *)0x4e

#define OCR1AL *(u8 *)0x4a
#define ICR1   *((volatile u16*)0x46)
#define SREG  *((volatile u8*)0x5F)


void Timer0_voidInit(void);
void timer1_pwm_init(void);






#endif /* TIMER0_H_ */
