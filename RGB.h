/*
 * RGB.h
 *
 *  Created on: 30 ago 2021
 *      Author: ie716000
 */

#ifndef RGB_H_
#define RGB_H_



#define safe_value_pin_22_pin_21_port_b 0x0600000
#define safe_value_pin_26_port_e 0x04000000;

//Made a function to solve the problem of the purple color
int WhiteON(){
	GPIOB->PDOR=0x0;
	GPIOE->PDOR=0x0;
};

int WhiteOFF(){
	#ifndef DEBUG_ON
			/**pintf is only used for debug purposes. It never use printf in a relese version*/
			printf("ALL LEDS ON\n");
	#endif
			GPIOB->PDOR=0x600000;
			GPIOE->PDOR=0x4000000;
};


#endif /* RGB_H_ */
