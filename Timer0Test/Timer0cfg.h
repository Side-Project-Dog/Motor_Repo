/*
 * Timer0cfg.h
 *
 *  Created on: Feb 6, 2020
 *      Author: ööAhmed Ibrahim
 */

#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_
#define Enable 1
#define Disable 0

/*
 * 1)Define Which mode you will use the timer for
 */
#define OverFlow_Mode Disable
#define CTC_Mode Enable
#define PWM_Mode Enable
#define PhaseCorrect_PWM Disable


/***************************************************************
//Compare Output Mode, non-PWM Mode
/***************************************************************/


#define OC0_Disconnected Disable
#define OC0_Toggle_InCompare Disable
#define Clear_OC0_on_Compare Disable
#define Set_OC0_on_compare Disable

/***************************************************************
//Compare Output Mode, Fast PWM Mode
/***************************************************************/

#define OC0_Disconnected Disable
#define Clear_OC0_on_Compare_set_OC0_AtTOP Enable
#define Set_OC0_on_compare_clearOC0_AtTOP Disable
/***************************************************************
//Clock Select
 * /***************************************************************/

#define T0NoClook Disable
#define T0NoPrescale Disable
#define T0Prescale8 Enable
#define T0Prescale64 Disable
#define T0Prescale256 Disable
#define T0Prescale1024 Disable
#define T0External_clk_Fallin_edge Disable
#define T0External_clk_rising_edge Disable


/***************************************************************
 * Global Interrupt bit
 ***************************************************************/
#define GI Enable
#define GI_bit 7


/**************************************************************
 * Timer0/Counter Control Register "TCCR0" Configuration
 **************************************************************/

#define FOC0 0
#define WGM00 0
#define COM01 0
#define COM00 0
#define WGM01 0
#define CS02 0
#define CS01 0
#define CS00 0



/*define number of each bit in the register instead of using magic numbers*/
#define FOC0_bit 7
#define WGM00_bit 6
#define COM01_bit 5
#define COM00_bit 4
#define WGM01_bit 3
#define CS02_bit 2
#define CS01_bit 1
#define CS00_bit 0


//I need to define OC0"b3" as output

/**************************************************************
 * Timer0/Counter Interrupt Mask Register "TIMSK0" Configuration
 **************************************************************/

#define TOIE0 Disable                            //Over flow Interrupt
#define OCIE0 Enable                            //compare output interrupt

#define TOIE0_bit 0
#define OCIE0_bit 1





/**************************************************************
 * Timer0/Counter Interrupt Flag Register "TIFR0" Configuration
 **************************************************************/

#define OCF0
#define T0V0

#define OCIE0_bit 1
#define T0IE0_bit 0



#endif /* TIMER0CFG_H_ */
