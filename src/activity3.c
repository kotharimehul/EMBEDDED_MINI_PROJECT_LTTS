/**
 * @file TimersCRO.c
 * @author Mehul Kothari
 * @brief Function to initialize timer 1
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"activity3.h"
/**
 * @brief Delay function
 * 
 * @param delay_time 
 */

void delay_milli(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}
/**
 * @brief Initialize timer
 * 
 */
void InitTimer1(){
    TIMER1_A|=(1<<COMPARE_A)|(1<<WAVEFORM_MODE_10)|(1<<WAVEFORM_MODE_11);
    TIMER1_B|=(1<<WAVEFORM_MODE_12)|(1<<CLOCK_SELECT_11)|(1<<CLOCK_SELECT_10);
    LED_DIRECTION_PIN|=(1<<LED_PIN_1);
}
/**
 * @brief Generate pwm signals
 * 
 * @param Temperature 
 */
void GeneratePWM(uint16_t Temperature){
    
    if(Temperature>=0 && Temperature<=200){
        OUTPUT_COMPARE_A = 204.8;
        delay_milli(200);
    }
    else if(Temperature>=201 && Temperature<=500){
        OUTPUT_COMPARE_A = 409.6;
        delay_milli(200);
    }
    else if(Temperature>=501 && Temperature<=700){
        OUTPUT_COMPARE_A = 716.8;
        delay_milli(200);
    }
    else{
        OUTPUT_COMPARE_A = 972.8;
        delay_milli(200);
    }
}