#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include"DIO_interface.h"
#include "CLCD_register.h"
#include "CLCD_interfac.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
# define F_CPU 8000000UL
#include"util/delay.h"


/*Description:This API for CLCD Intialization */


void CLCD_voidInitalization(void)
{
	_delay_ms(40);

#if CLCD_u8_DATA_LENGTH == EIGHT_BIT_MODE

	CLCD_WriteCommand(0b00111000);

#elif CLCD_u8_DATA_LENGTH == FOUR_BIT_MODE
	/*Set RS =0*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/* Set RW =0  */
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*
	 * Send 0010
	 * */
	CLCD_voidSetHalfDataPort(0b0010);
	/*
	 * Send Enable Pulse
	 * */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	/*
	 * Send 0010
	 * */
	CLCD_voidSetHalfDataPort(0b0010);
	/*
	 * Send Enable Pulse
	 * */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	/*
	 * Send 1000
	 * */
	CLCD_voidSetHalfDataPort(0b1000);
	/*
	 * Send Enable Pulse
	 * */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);

#else #error "Wrong Data Lenght Choice"

#endif
	CLCD_WriteCommand(0b00001111);

	_delay_ms(2);
	CLCD_WriteCommand(1);
	_delay_ms(4);



}
/*Description:This API shall display Data on CLCD*/
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*Set RS =1*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/* Set RW =0  */
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

#if CLCD_u8_DATA_LENGTH==EIGHT_BIT_MODE
	/*Set DatA  */
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Data,0));
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Data,1));
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Data,2));
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Data,3));
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Data,4));
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Data,5));
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Data,6));
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Data,7));
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
#elif CLCD_u8_DATA_LENGTH ==FOUR_BIT_MODE
	/*Set high order of the Command */
	CLCD_voidSetHalfDataPort(Copy_u8Data>>4);
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	CLCD_voidSetHalfDataPort(Copy_u8Data);
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
#else #error "Wrong Data Length Choice"

#endif

}

static void CLCD_voidSetHalfDataPort(u8 Copy_u8Data)
{

	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Data,0));
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Data,1));
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Data,2));
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Data,3));

}



/*Description:This API shall excute a command on CLCD*/



void CLCD_WriteCommand(u8 Copy_u8Cm)
{
	/*Set RS =0*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/* Set RW =0  */
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
#if CLCD_u8_DATA_LENGTH == EIGHT_BIT_MODE
	/*Set DatA  */
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Cm,0));
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Cm,1));
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Cm,2));
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Cm,3));
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Cm,4));
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Cm,5));
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Cm,6));
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Cm,7));
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
#elif CLCD_u8_DATA_LENGTH == FOUR_BIT_MODE
	/*Set high order of the Command */
	CLCD_voidSetHalfDataPort(Copy_u8Cm>>4);
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
	CLCD_voidSetHalfDataPort(Copy_u8Cm);
	/* Enable Pulses  */
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(1);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(1);
#else #error "Wrong Data Length Choice"

#endif



}



void CLCD_voidSetCursor(u8 Row,u8 Col)
{
	if (Row==0)
	{
		CLCD_WriteCommand(CLCD_LINE_1_CMD+Col);
	}
	if (Row==1)
	{
		CLCD_WriteCommand(CLCD_LINE_2_CMD+Col);
	}
}


void CLCD_voidWriteString(u8 * Copy_u8Data)
{
	u8 LocalLoopCounter=0;
	while(Copy_u8Data[LocalLoopCounter]!='\0')
	{
		CLCD_voidWriteData(Copy_u8Data[LocalLoopCounter]);
		LocalLoopCounter++;
	}
}




void LCDWriteInt(u32 x)
{
	u32 y=1;
	if(x==0)
	{
		CLCD_voidWriteData('0');
	}
	if(x<0)
	{
		CLCD_voidWriteData('-');
		x*=-1;
	}
	while(x!=0)
	{
		y=((y*10)+(x%10));
		x=(x/10);
	}
	while(y!=1)
	{
		CLCD_voidWriteData((y%10)+48);
		y=(y/10);
	}
}

