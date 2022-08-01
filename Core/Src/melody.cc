/*
 * melody.cc
 *
 *  Created on: Aug 1, 2022
 *      Author: vinhtran
 */

#include "melody.h"

/** BOOT UP SOUND 1 **/
const int bootup1[] = {
	NOTE_A_5,     NOTE_G_6,     NOTE_A_5,   NOTE_E_6,
	NOTE_D_6,     NOTE_C_6,     NOTE_D_6,   NOTE_E_6,
	NOTE_A_5,     NOTE_A_5,     NOTE_A_5
};
const int bootup1_durations[]={
	10, 10, 2, 8,
	8,  8,  8, 5,
	4,  4,  4
};

/** BOOT UP SOUND 2 **/
const int bootup2[]= {
	NOTE_D_4, NOTE_D_4, NOTE_A_4, NOTE_AS_4,
	NOTE_A_4, NOTE_G_4, NOTE_A_4, NOTE_A_4,
};
const int bootup2_durations[] = {
	4, 2, 4, 4,
	8, 8, 4, 3
};

/** BOOT UP SOUND 3 **/
const int bootup3[]={
	NOTE_A_4,      NOTE_CS_5 ,    NOTE_E_5 ,     NOTE_A_5 ,
	NOTE_CS_6,     NOTE_E_6 ,     NOTE_A_6
};
const int bootup3_durations[]={
	10   , 10   ,  10   ,  10   ,
	10   , 10   , 2
};

/** Function **/
void Melody::delay_ms(uint16_t ms)
{
	for(int i = 0; i < ms; i++)
	{
		__HAL_TIM_SET_COUNTER(timHandle_delay, 0);
		while (__HAL_TIM_GetCounter(timHandle_delay) < 10);
	}
}
void Melody::soundBuzzer1(void)
{
	static uint8_t Length_ofMelody = sizeof(bootup1)/sizeof(int);
	uint16_t counter_peroid = __HAL_TIM_GET_AUTORELOAD(timHandle_melody) + 1;
	for (uint8_t thisNote = 0; thisNote < Length_ofMelody; thisNote++)
	{
		uint16_t noteDuration = 1000/bootup1_durations[thisNote];
		if (bootup1[thisNote] == NOTE_SILENT)
		{
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(noteDuration);
		}
		else
		{
			__HAL_TIM_SET_PRESCALER(timHandle_melody,FREQ_TIMER/(bootup1[thisNote]*counter_peroid)-1);
			__HAL_TIM_SetCompare(timHandle_melody,channel,400);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			uint16_t pauseBetweenNotes = noteDuration * 1.3;
			delay_ms(noteDuration);
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(pauseBetweenNotes-noteDuration);
		}
	}
	__HAL_TIM_SetCompare(timHandle_melody,channel,0);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}

void Melody::soundBuzzer2(void)
{
	static uint8_t Length_ofMelody = sizeof(bootup2)/sizeof(int);
	uint16_t counter_peroid = __HAL_TIM_GET_AUTORELOAD(timHandle_melody) + 1;
	for (uint8_t thisNote = 0; thisNote < Length_ofMelody; thisNote++)
	{
		uint16_t noteDuration = 1000/bootup2_durations[thisNote];
		if (bootup2[thisNote] == NOTE_SILENT)
		{
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(noteDuration);
		}
		else
		{
			__HAL_TIM_SET_PRESCALER(timHandle_melody,FREQ_TIMER/(bootup2[thisNote]*counter_peroid)-1);
			__HAL_TIM_SetCompare(timHandle_melody,channel,400);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			uint16_t pauseBetweenNotes = noteDuration * 1.3;
			delay_ms(noteDuration);
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(pauseBetweenNotes-noteDuration);
		}
	}
	__HAL_TIM_SetCompare(timHandle_melody,channel,0);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}

void Melody::soundBuzzer3(void)
{
	static uint8_t Length_ofMelody = sizeof(bootup3)/sizeof(int);
	uint16_t counter_peroid = __HAL_TIM_GET_AUTORELOAD(timHandle_melody) + 1;
	for (uint8_t thisNote = 0; thisNote < Length_ofMelody; thisNote++)
	{
		uint16_t noteDuration = 1000/bootup3_durations[thisNote];
		if (bootup3[thisNote] == NOTE_SILENT)
		{
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(noteDuration);
		}
		else
		{
			__HAL_TIM_SET_PRESCALER(timHandle_melody,FREQ_TIMER/(bootup3[thisNote]*counter_peroid)-1);
			__HAL_TIM_SetCompare(timHandle_melody,channel,400);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			uint16_t pauseBetweenNotes = noteDuration * 1.3;
			delay_ms(noteDuration);
			__HAL_TIM_SetCompare(timHandle_melody,channel,0);
			delay_ms(pauseBetweenNotes-noteDuration);
		}
	}
	__HAL_TIM_SetCompare(timHandle_melody,channel,0);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
}
