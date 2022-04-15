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

typedef struct PixelInfo{
	int x;
	int y;
	int chainNumber;
	int hbControlRegisterIndex; //1-3
	int hbControlDataIndex; //1-12

}PixelInfo;

//map coordinates to PixelInfos

void Matrix_sendMessages(Matrix* matrix);

#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_H_ */
