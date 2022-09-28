/***********************************************************/
/* Title       : STEPPER MOTOR peripheral Private file    */
/* Author      : Yahia Ahmed                             */
/* Release     : 1.0                                    */
/* Last Update : Aug 19, 2021                          */
/******************************************************/
#ifndef STEP_PRIV_H_
#define STEP_PRIV_H_


#define STEP_u8_CLOCKWISE 			0
#define STEP_u8_COUNTER_CLOCKWISE   1
static void STD_vid_Directione_Full_Sequence(u8 Copy_u8_Direction);
static void STD_vid_Directione_Half_Sequence(u8 Copy_u8_Direction);

#endif /* STEPPER_MOTOR_PRIV_H_*/
