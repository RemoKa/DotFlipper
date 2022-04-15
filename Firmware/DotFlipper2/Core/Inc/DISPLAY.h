/*
 * DISPLAY.h
 *
 *  Created on: 29.12.2021
 *      Author: Remo Kagerer
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "MATRIX.h"

typedef struct Display{
	uint16_t 	width;
	uint16_t 	height;
	Matrix		*Matrix;
	uint32_t	*Frontbuffer;
	uint32_t	*Backbuffer;
	uint32_t	*Differencebuffer;
}Display;


void Display_setPixel(Display *Display, uint16_t x, uint16_t y, uint8_t color);

void Display_swap(Display *Display);

void Display_draw();

#ifdef __cplusplus
}
#endif
#endif /* INC_DISPLAY_H_ */
