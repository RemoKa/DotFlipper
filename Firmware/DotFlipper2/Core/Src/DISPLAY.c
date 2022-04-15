/*
 * DISPLAY.c
 *
 *  Created on: 15.04.2022
 *      Author: Remo
 */

#include "DISPLAY.h"

void Display_setPixel(Display *display, uint16_t x, uint16_t y, uint8_t color){
	if(color == 0){
		display->Backbuffer[y] &= !(1 << y);
	}else{
		Display->Backbuffer[y] |= (1 << x);
	}
}

void Display_swap(Display *display){
	uint32_t* temp = display->Frontbuffer;
	display->Frontbuffer = display->Backbuffer;
	display->Backbuffer = temp;
}

void Display_draw(Display *display){
	Display_swap(display);
	Matrix *matrix = display->Matrix;
	uint32t *frontBuffer = display->Frontbuffer;

	//iterate over the buffer

		//convert frontbuffer to messages in Matrix of buffer

		Matrix_sendMessages(matrix);

}

