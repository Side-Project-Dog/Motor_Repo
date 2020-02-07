/*
 * Timer0_register.h
 *
 *  Created on: Feb 6, 2020
 *      Author: ööAhmed Ibrahim
 */

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_


#define SREG *((volatile u8 *)0x5F)
#define TCCR0 *((volatile u8 *)0x53)
#define TIMSK *((volatile u8 *)0x59)
#define OCR0 *((volatile u8 *)0x5C)
#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define ICR1L *((volatile u8 *)0x46)
#define ICR1H *((volatile u8 *)0x47)
#define OCR1AL *((volatile u8 *)0x4A)
#define OCR1AH *((volatile u8 *)0x4B)


#endif /* TIMER0_REGISTER_H_ */
