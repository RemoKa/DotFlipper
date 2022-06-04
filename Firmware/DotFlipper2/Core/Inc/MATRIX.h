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

//#include "MATRIX_PIXEL_MAP.h"
#include "TLE94112ES.h"

#define PULSE_LENGHT 500

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
	C0 = 0,
	C1 = 1,
	C2 = 2,
	R0 = 3,
	R1 = 4
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

typedef struct Row{
	Pin high;
	Pin low;
}Row;

typedef struct Column{
	Pin pin;
}Column;

static const volatile Message emptyMessage = {
		0x00,
		0x00,
		READ,
		0x00,
		0x00

};

void Matrix_sendMessages(Matrix* matrix);

void clearMessages(Message *messages, uint8_t lenght);

void setPin(Message* m, Pin p, int8_t state);

#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_H_ */
