/*
 * DISPLAY.c
 *
 *  Created on: 15.04.2022
 *      Author: Remo
 */

#include "DISPLAY.h"

void Display_setPixel(Display *display, uint16_t x, uint16_t y, uint8_t color);

void Display_swap(Display *display){
	uint32_t* temp = display->Frontbuffer;
	display->Frontbuffer = display->Backbuffer;
	display->Backbuffer = temp;
}

void Display_draw();

