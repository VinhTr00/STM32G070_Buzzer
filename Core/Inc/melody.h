/*
 * melody.h
 *
 *  Created on: Aug 1, 2022
 *      Author: vinhtran
 */

#ifndef INC_MELODY_H_
#define INC_MELODY_H_

#include "stm32g0xx_hal.h"
#include "main.h"

#define NOTE_SILENT 0
#define NOTE_B_0  31
#define NOTE_C_1  33
#define NOTE_CS_1 35
#define NOTE_D_1  37
#define NOTE_DS_1 39
#define NOTE_E_1  41
#define NOTE_F_1  44
#define NOTE_FS_1 46
#define NOTE_G_1  49
#define NOTE_GS_1 52
#define NOTE_A_1  55
#define NOTE_AS_1 58
#define NOTE_B_1  62
#define NOTE_C_2  65
#define NOTE_CS_2 69
#define NOTE_D_2  73
#define NOTE_DS_2 78
#define NOTE_E_2  82
#define NOTE_F_2  87
#define NOTE_FS_2 93
#define NOTE_G_2  98
#define NOTE_GS_2 104
#define NOTE_A_2  110
#define NOTE_AS_2 117
#define NOTE_B_2  123
#define NOTE_C_3  131
#define NOTE_CS_3 139
#define NOTE_D_3  147
#define NOTE_DS_3 156
#define NOTE_E_3  165
#define NOTE_F_3  175
#define NOTE_FS_3 185
#define NOTE_G_3  196
#define NOTE_GS_3 208
#define NOTE_A_3  220
#define NOTE_AS_3 233
#define NOTE_B_3  247
#define NOTE_C_4  262
#define NOTE_CS_4 277
#define NOTE_D_4  294
#define NOTE_DS_4 311
#define NOTE_E_4  330
#define NOTE_F_4  349
#define NOTE_FS_4 370
#define NOTE_G_4  392
#define NOTE_GS_4 415
#define NOTE_A_4  440
#define NOTE_AS_4 466
#define NOTE_B_4  494
#define NOTE_C_5  523
#define NOTE_CS_5 554
#define NOTE_D_5  587
#define NOTE_DS_5 622
#define NOTE_E_5  659
#define NOTE_F_5  698
#define NOTE_FS_5 740
#define NOTE_G_5  784
#define NOTE_GS_5 831
#define NOTE_A_5  880
#define NOTE_AS_5 932
#define NOTE_B_5  988
#define NOTE_C_6  1047
#define NOTE_CS_6 1109
#define NOTE_D_6  1175
#define NOTE_DS_6 1245
#define NOTE_E_6  1319
#define NOTE_F_6  1397
#define NOTE_FS_6 1480
#define NOTE_G_6  1568
#define NOTE_GS_6 1661
#define NOTE_A_6  1760
#define NOTE_AS_6 1865
#define NOTE_B_6  1976
#define NOTE_C_7  2093
#define NOTE_CS_7 2217
#define NOTE_D_7  2349
#define NOTE_DS_7 2489
#define NOTE_E_7  2637
#define NOTE_F_7  2794
#define NOTE_FS_7 2960
#define NOTE_G_7  3136
#define NOTE_GS_7 3322
#define NOTE_A_7  3520
#define NOTE_AS_7 3729
#define NOTE_B_7  3951
#define NOTE_C_8  4186
#define NOTE_CS_8 4435
#define NOTE_D_8  4699
#define NOTE_DS_8 4978

#define FREQ_TIMER 64000000 //TIMER1 (Hz)

class Melody{
	private:
		TIM_HandleTypeDef* timHandle_delay;
		TIM_HandleTypeDef* timHandle_melody;
		uint32_t channel;
	public:
		Melody(TIM_HandleTypeDef* timHandle_delay, TIM_HandleTypeDef* timHandle_melody, uint32_t channel){
			this->channel = channel;
			this->timHandle_delay = timHandle_delay;
			this->timHandle_melody = timHandle_melody;
		}
		void delay_ms(uint16_t ms);
		void soundBuzzer1(void);
		void soundBuzzer2(void);
		void soundBuzzer3(void);
};

#endif /* INC_MELODY_H_ */
