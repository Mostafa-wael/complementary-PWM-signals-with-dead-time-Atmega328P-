/**
 * @file GPIO.c
 * @author Mostafa Wael
 * @date 2020-08-07
 * 
 * 
 */ 
#include "GPIO.h"
void GPIOinit ()
{
	/**
	 * @brief setting pins B1  and B2 as output as they are the pins responsible for the timers 
	 * 
	 */
	DDRB |= (1<<DDB1) | (1<<DDB2);
}