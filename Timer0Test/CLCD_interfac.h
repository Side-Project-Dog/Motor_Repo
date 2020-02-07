/************************************************************ 
Author :Mohamed Ibrahem
Version:v01
Date:14-1-2020
/*************************************************************/

#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLCD_LINE_1 0
#define CLCD_LINE_2 1


/*Description:This API for CLCD Intialization */
void CLCD_voidInitalization(void);
/*Description:This API shall display Data on CLCD*/
void CLCD_voidWriteData(u8 Copy_u8Data);
/*Description:This API shall excute a command on CLCD*/
void CLCD_voidSetCursor(u8 Row,u8 Col);

void CLCD_WriteCommand(u8 Copy_u8Cmd);

void CLCD_voidWriteString(u8* Copy_u8Data);


void LCDWriteInt(u32 x);

#endif
