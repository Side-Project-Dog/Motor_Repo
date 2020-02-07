#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"BIT_MATH.h"
#include"DIO_private.h"
#include"DIO_config.h"
#include "DIO_register.h"





void SetPinDir(u8 Port,u8 Pin,u8 Dir)
{
switch(Port)
{
case 'A':
if(Dir==0)
  {
	CLR_BIT(DDRA,Pin);
    //DDRA=DDRA&~(1<<Pin);
    
  }
  else 
  {

  //DDRA=DDRA|(1<<Pin);
	  SET_BIT(DDRA,Pin);
  }
break;
case 'B':
if(Dir==0)
  {
	CLR_BIT(DDRB,Pin);
    //DDRB=DDRB&~(1<<Pin);
  }
  else 
  {
  //DDRB=DDRB|(1<<Pin);
	  SET_BIT(DDRB,Pin);
  }
break;
case 'C':
if(Dir==0)
  {
  //  DDRC=DDRC&~(1<<Pin);
	CLR_BIT(DDRC,Pin);
  }
  else 
  {
  //DDRC=DDRC|(1<<Pin);
	  SET_BIT(DDRC,Pin);
  }
break;
case 'D':
if(Dir==0)
  {
    DDRD=DDRD&~(1<<Pin);
    
  }
  else 
  {
  //DDRD=DDRD|(1<<Pin);
	  SET_BIT(DDRD,Pin);
  }
break;
}
}




void SetPinValue(u8 Port,u8 Pin,u8 Val)

{
switch(Port)
{
case 'A':
if(Val==0)
  {
	CLR_BIT(PORTA,Pin);
    //PORTA=PORTA&~(1<<Pin);
    
  }
  else 
  {
  //PORTA=PORTA|(1<<Pin);
	  SET_BIT(PORTA,Pin);
  }
break;
case 'B':
if(Val==0)
  {
    //PORTB=PORTB&~(1<<Pin);
	CLR_BIT(PORTB,Pin);
  }
  else 
  {
  //PORTB=PORTB|(1<<Pin);
	  SET_BIT(PORTB,Pin);
  }
break;
case 'C':
if(Val==0)
  {
    //PORTC=PORTC&~(1<<Pin);
	CLR_BIT(PORTC,Pin);
  }
  else 
  {
	  SET_BIT(PORTC,Pin);
  //PORTC=PORTC|(1<<Pin);
  }
break;
case 'D':
if(Val==0)
  {
    //PORTD=PORTD&~(1<<Pin);
	CLR_BIT(PORTD,Pin);
  }
  else 
  {
	  SET_BIT(PORTD,Pin);
  //PORTD=PORTD|(1<<Pin);
  }
break;
}
}

void SetPortDir(u8 Port,u8 Dir)
{
switch(Port)
{
case 'A':
	DDRA=Dir;
break;
case 'B':
	DDRB=Dir;
break;
case 'C':
	DDRC=Dir;
break;
case 'D':
	DDRD=Dir;
break;


}

}


void SetPortValue(u8 Port,u8 Val)
{
switch(Port)
{
case 'A':
	PORTA=Val;
break;
case 'B':
	PORTB=Val;
break;
case 'C':
	PORTC=Val;
break;
case 'D':
	PORTD=Val;
break;


}

}

u8 GetPinValue(u8 Port,u8 Pin)
{
u8 result;
switch(Port)
{
case 'A':
	result=GET_BIT(PINA,Pin);
 break;
case 'B':
	result=GET_BIT(PINB,Pin);
break;
case 'C':
	result=GET_BIT(PINC,Pin);
break;
case 'D':
	result=GET_BIT(PIND,Pin);
break;
}
return result;
}

