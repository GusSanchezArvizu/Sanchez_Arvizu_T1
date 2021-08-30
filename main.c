/*
 * main.c
 *
 *  Created on: 30 ago 2021
 *  Author: ie716000
 */

#include <stdio.h>
/**Standard integer definition provided by the compiler*/
#include <stdint.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"

//#define DEBUG_ON


int main(void) {
	/**Activating the GPIOB clock gating*/
	SIM->SCGC5 = 0x2400;
	/**Pin control configuration of GPIOB pin22 as GPIO*/
	PORTB->PCR[22] = gpio_function;
	PORTB->PCR[21] = gpio_function;
	PORTE->PCR[26] = gpio_function;
	/**Assigns a safe value to the output pin*/
	GPIOB->PDOR = safe_value_pin_22_pin_21_port_b;
	GPIOE->PDOR = safe_value_pin_26_port_e;

	/**Configures GPIOB pin22 as output*/
	GPIOB->PDDR = 0x00600000;
	GPIOE->PDDR = 0x04000000;

	// 0x200000; BLUE
	// 0x400000; RED
	// 0x4000000; GREEN

    while(1) {
		/**Clears the output port, therefore the led is on*/
		GPIOB->PDOR = 0x200000;
#ifndef DEBUG_ON
		/**pintf is only used for debug purposes. It never use printf in a relese version*/
		printf("RED LED ON\n");
#endif
		/**Clears the output port, therefore the led is off*/
		GPIOB->PDOR= 0x600000; //only to turn off both leds
		GPIOB->PDOR= 0x400000;

#ifndef DEBUG_ON
		printf("RED LED OFF AND LED BLUE IS ON\n");
#endif
		/**Clears the output port, therefore the led is on*/
		GPIOB->PDOR = 0x600000;
		GPIOE->PDOR = 0x0;
#ifndef DEBUG_ON
		/**pintf is only used for debug purposes. It never use printf in a relese version*/
		printf("BLUE LED OFF, AND GREEN LED ON\n");
#endif
		/**Clears the output port, therefore the led is off*/
		GPIOE->PDOR= 0x4000000;
#ifndef DEBUG_ON
		printf("RED LED OFF\n");
#endif
		//Tarea EMBEBIDOS:

		//The constructor builds first all code thats inside the function
		WhiteON();
		//When white color is ON, it just switch PDDR inside the OFF function
		WhiteOFF();
    }
    return 0 ;
}
