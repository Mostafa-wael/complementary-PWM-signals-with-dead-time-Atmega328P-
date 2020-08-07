/*
 * shell's task.c
 *
 * Created: 7/23/2020 4:43:44 PM
 * Author : Mostafa Wael
 */ 


#include <avr/io.h>
#include "GPIO.h"
#include "Timer1.h"
/**
 * @brief the used clock is 8MHz
 * 
 * @return int 
 */
int main(void)
{
	Gpininit();
	Timer1init();
	
    while (1); 
   // no need to add a return as it won't be reached anyway 
}

