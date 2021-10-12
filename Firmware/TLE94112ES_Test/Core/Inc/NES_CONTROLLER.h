/*
 * NES_CONTROLLER.h
 *
 *  Created on: 12.10.2021
 *      Author: Remo Kagerer
 */

#ifndef INC_NES_CONTROLLER_H_
#define INC_NES_CONTROLLER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum NES_Buttons{
	NES_A 		= 0b00000001,
	NES_B		= 0b00000010,
	NES_SELECT	= 0b00000100,
	NES_START 	= 0b00001000,
	NES_UP		= 0b00010000,
	NES_DOWN	= 0b00100000,
	NES_LEFT	= 0b01000000,
	NES_RIGHT	= 0b10000000,
}NES_Buttons;


#ifdef __cplusplus
}
#endif
#endif /* INC_NES_CONTROLLER_H_ */
