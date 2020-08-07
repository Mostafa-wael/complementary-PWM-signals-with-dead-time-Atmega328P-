/**
 * @file Timer1.c
 * @author Mostafa Wael
 * @date 2020-08-07
 * 
 * 
 */
#include "Timer1.h"
void Timer1init ()
{
	/**
	* \details{
	* internal frequency = 8MHZ;
	*
	* desired frequency = 5KHZ;
	*
	* (2 * prescaler * topValue) = internal/ desired = 8MHZ/5MHz = 1600;
	*
	* prescaler * topValue =  800;
	*
	* since, the topValue can be held by the ICR
	*
	* then, we don't have to use a prescaler   
	*
	* ICR = 800; presacler = 1:1; -->setting the prescaler to 1:1 through the bits CS12:CS11:CS10 
	* }                                                           
	*/
	ICR1 = F_CPU / (PWM_freq * prescaler * 2) //setting ICR1 to 800 
	TCCR1B |= (1<<CS10); // setting the prescaler to 1:1
	/**
	* \details{
	* duty cycle D = onTime / (onTime + offTime);
	*
	* OCSRx = D * topValue;
	*
	* for A, let the duty cycle be 50% i.e. onTime = 100 unit, offTime = 100 unit;
	*
	* OCSRA = 50% * 800 = 400;
	*
	* lets think about how to configure B to have a dead time of 10 units:
	*
	* having a dead time of 10 units means that the onTime of B would be less than that of A by 2*10 which is 80 units
	*
	* hence, the duty cycle of B is 80/200 = 40%
	*
	* OCSRB = 40% * 800 = 320;   
	* }                                                               
	*/
	OCR1A = duty_cycle * ICR1; // setting OCR1A to 400
	OCR1B = duty_cycle * ( 1 - 2 * dead_time) * ICR1; // setting OCR1B to 320
	/**
	* \details{
	*	we need to set our PWM mode to phase correct mode with a topValue of ICR1
	*
	*	WGM13 : WGM12 : WGM11 : WGM10  
	* 
	*	  1		  0		  1		  0 
	* }
	*/
	TCCR1B |= (1<<WGM13) ;
	TCCR1A |= (1<<WGM11);
	/**
	* \details{
	* in order to obtain two complementary signals, 
	*
	* we should set one of the ports to the inverted mode and the other to the non-inverted mode
	*
	* COM1x1 : COM1x0   
	*
	* 	1		0  --> non-inverted i.e. clear --> set
	*
	*	1		1  --> inverted		i.e. set --> clear
	* }
	*/
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1B0);   
}