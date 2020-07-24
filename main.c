/*
 * shell's task.c
 *
 * Created: 7/23/2020 4:43:44 PM
 * Author : Mostafa Wael
 */ 

#include <avr/io.h>
#include "GPIO.h"
#include "Timer1.h"
// the used clock is 8MHz
int main(void)
{
	Gpininit();
	Timer1init();
	
    while (1); 
    
}

