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


typedef struct Matrix{
	uint8_t 	width;
	uint8_t 	height;
	uint8_t		DaisyChainLength;
	Message		*MessageBuffer;
}Matrix;

typedef struct Pin{
	uint8_t chainIndex: 3;
	uint8_t	hBridgeIndex: 4;
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
