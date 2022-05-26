/*
 * MATRIX.h
 *
 *  Created on: 29.12.2021
 *      Author: Remo Kagerer
 */

#ifndef INC_MATRIX_H_
#define INC_MATRIX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "TLE94112ES.h"

typedef enum hBridge{
	HB1 = 1,
	HB2 = 2,
	HB3 = 3,
	HB4 = 4,
	HB5 = 5,
	HB6 = 6,
	HB7 = 7,
	HB8 = 8,
	HB9 = 9,
	HB10 = 10,
	HB11 = 11,
	HB12 = 12,
}hBridge;

typedef enum daisyChain{
	DC0 = 0,
	DC1 = 1,
	DC2 = 2,
	DC3 = 3,
	DC4 = 4
}daisyChain;

typedef struct Matrix{
	uint8_t 	width;
	uint8_t 	height;
	uint8_t		DaisyChainLength;
	Message		*MessageBuffer;
}Matrix;

typedef struct Pin{
	daisyChain	chainIndex: 3;
	hBridge		hBridgeIndex: 4;
}Pin;

typedef struct Pixel{
	Pin rowHigh;
	Pin rowLow;
	Pin column;
}Pixel;




//map coordinates to PixelInfos

void Matrix_sendMessages(Matrix* matrix);

#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_H_ */
