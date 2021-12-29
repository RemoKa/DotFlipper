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
	uint8_t		*Frontbuffer;
	uint8_t		*Backbuffer;
	uint8_t		*Differencebuffer;
}Display;

Display Display_init(uint16_t width, uint16_t height);

void Display_setPixel();

void Display_swap();

void Display_draw();

#ifdef __cplusplus
}
#endif
#endif /* INC_DISPLAY_H_ */
