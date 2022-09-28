
/************************************************/
/* Title       : STEPPER MOTOR configuration file*/
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 19, 2021                   */
/************************************************/

#ifndef STEP_CONFIG_H_
#define STEP_CONFIG_H_

#define STEP_u8_PORTN0 			    PORTC 
#define STEP_COIL_u8_A				DIO_u8_PIN_19
#define STEP_COIL_u8_B				DIO_u8_PIN_20
#define STEP_COIL_u8_C				DIO_u8_PIN_21
#define STEP_COIL_u8_D				DIO_u8_PIN_22

#define STEP_u8_STEP_ANGLE       	11.5
#define STEP_u8_DELAY_MS			500

#define STEP_u8_FULL_STEP			1
#define STEP_u8_HALF_STEP			2
#define STEP_u8_MODE				STEP_u8_HALF_STEP
//#define STEP_u8_NUMBER_OF_STEPS()    
/*
1-KEYPAD_U8_EX_PULL
2-KEYPAD_U8_IN_PULL
*/

#define FULL_STEP_u8    1
#define HALF_STEP_u8	0

#endif /* STEPPER_MOTOR_CONFIG_H_*/
