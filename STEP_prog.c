/***********************************************************/
/* Title       : STEPPER MOTOR peripheral program file    */
/* Author      : Yahia Ahmed                             */
/* Release     : 1.0                                    */
/* Last Update : Aug 17, 2021                          */
/******************************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "STEP_int.h"
#include "STEP_config.h"
#include "STEP_priv.h"
#include<avr/delay.h>

#ifndef STEP_PROG_H_
#define STEP_PROG_H_
void STEP_vid_Init(void)
{
	DIO_vid_SetPinValue(STEP_COIL_u8_A,DIO_u8_LOW);
	DIO_vid_SetPinValue(STEP_COIL_u8_B,DIO_u8_LOW);
	DIO_vid_SetPinValue(STEP_COIL_u8_C,DIO_u8_LOW);
	DIO_vid_SetPinValue(STEP_COIL_u8_D,DIO_u8_LOW);
}
void STEP_vid_Move(u8 Copy_u8_Direction)
{
	u16	Local_u8_NUMBER_OF_STEPS;
	if( STEP_u8_MODE==STEP_u8_FULL_STEP)
	{
		Local_u8_NUMBER_OF_STEPS=(((f32)STEP_u8_FULL_STEP*360.0)/STEP_u8_STEP_ANGLE);

		for(u8 i=0;i<Local_u8_NUMBER_OF_STEPS;i++)
		{
			STD_vid_Directione_Full_Sequence(Copy_u8_Direction);
			if(DIO_u8_GetPinValue(DIO_u8_PIN_8)==0)
			{
				Copy_u8_Direction=(Copy_u8_Direction==0)? 1:0;
			}

		}
	}
	else if( STEP_u8_MODE==STEP_u8_HALF_STEP)
	{
		Local_u8_NUMBER_OF_STEPS=(((f32)STEP_u8_HALF_STEP*360.0)/STEP_u8_STEP_ANGLE);
		for(u8 i=0;i<=Local_u8_NUMBER_OF_STEPS;i++)
		{
			STD_vid_Directione_Half_Sequence(Copy_u8_Direction);
			if(DIO_u8_GetPinValue(DIO_u8_PIN_8)==0)
			{
				Copy_u8_Direction=(Copy_u8_Direction==0)? 1:0;
			}
		}
	}
}
static void STD_vid_Directione_Full_Sequence(u8 Copy_u8_Direction)
{

	if(Copy_u8_Direction ==STEP_u8_CLOCKWISE)
		for(u8 i=0;i<4;i++)
		{
				DIO_vid_SetPORTValue(DIO_u8_PORTC,1<<i);
				_delay_ms(STEP_u8_DELAY_MS);

		}
	else if(Copy_u8_Direction ==STEP_u8_COUNTER_CLOCKWISE)
	{
		for(u8 i=0;i<4;i++)
		{
			DIO_vid_SetPORTValue(DIO_u8_PORTC,8>>i);
			_delay_ms(STEP_u8_DELAY_MS);
		}
	}
}

static void STD_vid_Directione_Half_Sequence(u8 Copy_u8_Direction)
{
	if(Copy_u8_Direction ==STEP_u8_CLOCKWISE)
	{
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x09);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x01);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x03);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x02);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x06);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x04);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x0c);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x08);
		_delay_ms(STEP_u8_DELAY_MS);

	}
	else if(Copy_u8_Direction ==STEP_u8_COUNTER_CLOCKWISE)
	{
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x08);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x0c);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x04);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x06);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x02);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x03);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x01);
		_delay_ms(STEP_u8_DELAY_MS);
		DIO_vid_SetPORTValue(DIO_u8_PORTC,0x09);
		_delay_ms(STEP_u8_DELAY_MS);

	}
}
#endif /* STEPPER_MOTOR_PROG_H_*/
