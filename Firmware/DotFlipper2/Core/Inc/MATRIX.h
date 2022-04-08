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

Matrix Diplay_init(uint8_t width, uint8_t height);

#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_H_ */
