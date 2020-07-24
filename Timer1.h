/*
 * Timer1.h
 *
 * Created: 7/23/2020 6:41:44 PM
 *  Author: Mostafa Wael
 */ 
#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#define F_CPU 8000000ul /**< setting the CPU frequency to 8MHz. */     

/**
* \brief
* this function is responsible for generating the 2-complementary signals withe the injected dead time                                                                      
*/
void Timer1init ();




#endif /* TIMER1_H_ */