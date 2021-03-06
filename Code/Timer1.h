/**
 * @file Timer1.h
 * @author Mostafa Wael
 * @brief generating two complementary PWM signal with a dead time
 * @version 0.2
 * @date 2020-08-07
 * 
 * 
 */
#ifndef TIMER1_H_
#define TIMER1_H_
#include <avr/io.h>
/**
 * @brief setting the CPU frequency to 8MHz
 * 
 */
#define F_CPU (8000000ul) 
#define PWM_freq 5000
#define prescaler 1
#define duty_cycle (50/100)
#define dead_time (10/100)
/**
* @brief this function is responsible for generating the 2-complementary signals with the injected dead time 
*
*                                                                  
*/
void Timer1init ();




#endif /* TIMER1_H_ */