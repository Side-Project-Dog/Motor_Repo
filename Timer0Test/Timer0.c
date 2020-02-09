/*
 * Timer0.c

 *
 *  Created on: Feb 6, 2020
 *      Author: ööAhmed Ibrahim
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_interface.h"
#include"Timer0_register.h"
#include"Timer0cfg.h"
#include"Timer0.h"



static void (*TIMER_pvCallBack_Func[2])(void)={NULL,NULL};

#define TOIE0  Enable
#define OCIE0   Enable

/**************************************************************
 * output Compare Register "OCR0" Configuration
 * put the value you want to insert in it in case Compare Match Mode
 **************************************************************/
#define OCR0_Value 128



/*Private Variables*/
static u16 Timer0_NumOfOverflows=0;

static u16 Timer0_CTC_Counter=0;

/*
 * The ISR of the Overflow of Timer0 mode will be enabled
 * if Global interrupt bit is set to high and
 * if the overflow Interrupt enable bit is set to high in TIMSK
 */
void __vector_11 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_11 (void)
{
	if(TIMER_pvCallBack_Func[0]!=NULL)
	{
		TIMER_pvCallBack_Func[0]();
	}
}
/*
 * the ISR of the Capture Match mode will be enabled
 *  if Global interrupt bit is set to high and
 * if the Capture Match Interrupt enable bit is set to high in TIMSK
 */
void __vector_10 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_10 (void)
{
	if(TIMER_pvCallBack_Func[1]!=NULL)
	{
		TIMER_pvCallBack_Func[1]();
	}
}



#if OverFlow_Mode==Enable
#define WGM00 0
#define WGM01 0
#endif

#if PhaseCorrect_PWM==Enable
#define WGM00 1
#define	WGM01 0
#endif

#if CTC_Mode==Enable
#define	WGM00 0
#define	WGM01 1

#endif

#if PWM_Mode==Enable

#define	WGM00 1
#define	WGM01 1
#endif


#if CTC_Mode==Enable
#if OC0_Disconnected==Enable
#define	COM00 0
#define	COM01 0

#endif
#if OC0_Toggle_InCompare==Enable
#define	COM00 1
#define	COM01 0

#endif
#if Clear_OC0_on_Compare==Enable
#define	COM00 0
#define	COM01 1

#endif
#if Set_OC0_on_compare==Enable
#define	COM00 1
#define	COM01 1

#endif



#endif


#if PWM_Mode==Enable
#if OC0_Disconnected==Enable
#define COM00 0
#define	COM01 0

#endif
#if Clear_OC0_on_Compare_set_OC0_AtTOP==Enable
#define	COM00 0
#define	COM01 1

#endif
#if Set_OC0_on_compare_clearOC0_AtTOP==Enable
#define	COM00 1
#define	COM01 1

#endif

#endif

#if T0NoClook==Enable
#define	CS00 0
#define	CS01 0
#define	CS02 0

#endif
#if T0NoPrescale==Enable
#define	CS00 1
#define	CS01 0
#define	CS02 0

#endif
#if T0Prescale8==Enable
#define	CS00 0
#define	CS01 1
#define	CS02 0

#endif
#if T0Prescale64==Enable
#define	CS00 1
#define	CS01 1
#define	CS02 0

#endif
#if T0Prescale256==Enable
#define	CS00 0
#define	CS01 0
#define	CS02 1

#endif
#if T0Prescale1024==Enable
#define	CS00 1
#define	CS01 0
#define	CS02 1

#endif
#if T0External_clk_Fallin_edge==Enable
#define CS00 0
#define	CS01 1
#define	CS02 1

#endif
#if T0External_clk_rising_edge==Enable
#define	CS00 1
#define	CS01 1
#define	CS02 1

#endif


void Timer0_voidInit(void)
{

#if GI == Enable
	/*set the Global interrupt bit value*/
	SET_BIT(SREG,GI_bit);
#endif

	/*fill the value of the TCCR0 Register according to the Configuration*/
	TCCR0 |= (FOC0 << FOC0_bit) | (WGM00 << WGM00_bit) | (COM01 << COM01_bit)
					| (COM00 << COM00_bit) | (WGM01 << WGM01_bit) | (CS02 << CS02_bit)
					| (CS01 << CS01_bit) | (CS00 << CS00_bit);

	/*fill the value of the TIMSK0 Register according to the Configuration*/
#if ((OCIE0 == 1) && (CTC_Mode==Enable))
	OCR0=OCR0_Value;
	TIMSK |= (OCIE0<<OCIE0_bit);
#endif

#if ((TOIE0 == 1) && (OverFlow_Mode==Enable))
	TIMSK|= (TOIE0<<TOIE0_bit);
#endif




}







void Timer0_void_InitPost(TIMER0_CONF_t *Copy_Timer0_conf)
{
	if (Copy_Timer0_conf->Mode==NORMAL)
	{
		TIMER_pvCallBack_Func[0]=Copy_Timer0_conf->pvCallBack;
	}
	else if(Copy_Timer0_conf->Mode==CTC  ||Copy_Timer0_conf->Mode==PWM)
	{
		TIMER_pvCallBack_Func[1]=Copy_Timer0_conf->pvCallBack;
	}

	switch(Copy_Timer0_conf->Clock)
	{
	case T0NoClook_CLOCK:
		CLR_BIT(TCCR0,CS00_bit);
		CLR_BIT(TCCR0,CS01_bit);
		CLR_BIT(TCCR0,CS02_bit);
		break;

	case T0NoPrescale_CLOCK:
		SET_BIT(TCCR0,CS00_bit);
		CLR_BIT(TCCR0,CS01_bit);
		CLR_BIT(TCCR0,CS02_bit);


		break;
	case T0Prescale8_CLOCK:
		CLR_BIT(TCCR0,CS00_bit);
		SET_BIT(TCCR0,CS01_bit);
		CLR_BIT(TCCR0,CS02_bit);
		break;
	case T0Prescale64_CLOCK:
		SET_BIT(TCCR0,CS00_bit);
		SET_BIT(TCCR0,CS01_bit);
		CLR_BIT(TCCR0,CS02_bit);
		break;
	case T0Prescale256_CLOCK:
		CLR_BIT(TCCR0,CS00_bit);
		CLR_BIT(TCCR0,CS01_bit);
		SET_BIT(TCCR0,CS02_bit);
		break;
	case T0Prescale1024_CLOCK:
		SET_BIT(TCCR0,CS00_bit);
		CLR_BIT(TCCR0,CS01_bit);
		SET_BIT(TCCR0,CS02_bit);
		break;
	}

	switch(Copy_Timer0_conf->Mode)
	{
	case  NORMAL:
		CLR_BIT(TCCR0,WGM00_bit);
		CLR_BIT(TCCR0,WGM01_bit);
		break;
	case PWM_PHSE_CORRECT:
		SET_BIT(TCCR0,WGM00_bit);
		CLR_BIT(TCCR0,WGM01_bit);
		break;
	case CTC:
		CLR_BIT(TCCR0,WGM00_bit);
		SET_BIT(TCCR0,WGM01_bit);
		switch(Copy_Timer0_conf->Wave_form__mode)
		{
		case OC0_Disconnected_WFM:
			CLR_BIT(TCCR0,COM00_bit);
			CLR_BIT(TCCR0,COM01_bit);
			break;
		case OC0_Toggle_InCompare_WFM:
			SET_BIT(TCCR0,COM00_bit);
			CLR_BIT(TCCR0,COM01_bit);
			break;
		case Clear_OC0_on_Compare_WFM:
			CLR_BIT(TCCR0,COM00_bit);
			SET_BIT(TCCR0,COM01_bit);

			break;
		case Set_OC0_on_compare_WFM:
			SET_BIT(TCCR0,COM00_bit);
			SET_BIT(TCCR0,COM01_bit);

			break;
		}
		break;
		case PWM:
			SET_BIT(TCCR0,WGM00_bit);
			SET_BIT(TCCR0,WGM01_bit);

			if (Copy_Timer0_conf->Wave_form__mode==OC0_Disconnected_WFM)
			{
				CLR_BIT(TCCR0,COM00_bit);
				CLR_BIT(TCCR0,COM01_bit);
			}
			else if(Copy_Timer0_conf->Wave_form__mode==Clear_OC0_on_Compare_set_OC0_AtTOP_WFM)
			{
				CLR_BIT(TCCR0,COM00_bit);
				SET_BIT(TCCR0,COM01_bit);
			}
			else if( Copy_Timer0_conf->Wave_form__mode==Set_OC0_on_compare_clearOC0_AtTOP_WFM)
			{
				SET_BIT(TCCR0,COM00_bit);
				SET_BIT(TCCR0,COM01_bit);
			}
			break;
	}
	SET_BIT(SREG,7);
	TIMSK|= (Copy_Timer0_conf->OV_Interrupt_Enable<<TOIE0_bit);
	TIMSK |= (Copy_Timer0_conf->Compare_Interrupt_Enable<<OCIE0_bit);
	OCR0=Copy_Timer0_conf->OCR0_Val;
	SET_BIT(TIMSK,OCIE0_bit);




}


void timer1_pwm_init(void)
{
	SET_BIT(SREG,7);

	TCCR1A = 0b00000000;
	TCCR1B = 0b01000001;

	//enable overflow interrupt
	SET_BIT(TIMSK,2);
	//enable Input capture interrupt
	SET_BIT(TIMSK,5);

	//set pin D6(ICP) as Input because it will read the PWM signal
	//DIOSetPinDirection(3,6,0);
}

