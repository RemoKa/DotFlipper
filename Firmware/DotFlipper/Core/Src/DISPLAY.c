/*
 * DISPLAY.c
 *
 *  Created on: 30.12.2021
 *      Author: Remo Kagerer
 */

#include "DISPLAY.h"


void Display_setPixel(Display *Display, uint16_t x, uint16_t y, uint8_t color){

	if(color == 0){
		Display->Backbuffer[y] &= !(1 << x);
	}else{
		Display->Backbuffer[y] |= (1 << x);
	}
}

void Display_swap();

void Display_draw(){

};


