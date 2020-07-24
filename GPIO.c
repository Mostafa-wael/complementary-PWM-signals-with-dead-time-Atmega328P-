/*
 * GPIO.c
 *
 * Created: 7/23/2020 6:44:10 PM
 *  Author: Mostafa Wael
 */ 
#include "GPIO.h"
void Gpininit ()
{
	
	DDRB |= (1<<DDB1) | (1<<DDB2); // setting pins B1  and B2 as output as they are the pins responsible for the timers 
}