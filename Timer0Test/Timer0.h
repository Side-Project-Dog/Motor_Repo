/*
 * Timer0.h
 *
 *  Created on: Feb 6, 2020
 *      Author: ööAhmed Ibrahim
 */

#ifndef TIMER0_H_
#define TIMER0_H_


////timer 1

#define TCCR1A *(u8 *)0x4f
#define TCCR1B *(u8 *)0x4e

#define OCR1AL *(u8 *)0x4a
#define ICR1   *((volatile u16*)0x46)
#define SREG  *((volatile u8*)0x5F)



#define Enable 1
#define Disable 0

/*Modes for timer*/

#define  NORMAL 1
#define  PWM_PHSE_CORRECT 2
#define  CTC 3
#define  PWM  4

typedef struct
{
u8 Mode;   //CTC Normal PWM
u8 Wave_form__mode;	//Wave form from the below options
u8 Clock;						//Clock from the below options
u8 Compare_Interrupt_Enable;   //Enable or Disable
u8 OV_Interrupt_Enable;			//
u8 	OCR0_Val;
void (*pvCallBack)(void);
}TIMER0_CONF_t;

/*CLOCk */
#define T0NoClook_CLOCK			1
#define T0NoPrescale_CLOCK		2
#define T0Prescale8_CLOCK		3
#define T0Prescale64_CLOCK		4
#define T0Prescale256_CLOCK		5
#define T0Prescale1024_CLOCK	6


/*Wave_form__mode For CTC MOde*/
#define OC0_Disconnected_WFM		1
#define OC0_Toggle_InCompare_WFM	2
#define Clear_OC0_on_Compare_WFM	3
#define Set_OC0_on_compare_WFM		4



/*Wave_form__mode For PWM Mode*/
#define OC0_Disconnected_WFM 							1
#define Clear_OC0_on_Compare_set_OC0_AtTOP_WFM 			2
#define Set_OC0_on_compare_clearOC0_AtTOP_WFM 			3
#define Set_OC0_on_compare_WFM   						4



void Timer0_voidInit(void);
void Timer0_void_InitPost(TIMER0_CONF_t *Copy_Timer0_conf);
void Timer_config(u32 CopyMode,u32 Copy_Clock,u32 WaveForm,u32 OCR_val,void (*pointerCallBack)(void),u8 OV_InterruptEnable,u8 CTC_InterruptEnable);







#endif /* TIMER0_H_ */
