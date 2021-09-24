/*
 * TLE94112ES.c
 *
 *  Created on: 21.09.2021
 *      Author: Remo
 */

#include "TLE94112ES.h"

void TLE94112ES_ConstructTXBuffer(uint8_t *TXBuf, int NumberOfChips, Message *Messages){


	//Daisy Chain
	for(int i = 0; i < NumberOfChips; i++){
		TXBuf[i] 					= (Messages[i].RegisterAdress | (Messages[i].WriteClear << 7)) & 0b11111101;
		TXBuf[i + NumberOfChips] 	= Messages[i].Data;
	}

	//set Last Address Byte Token LABT
	TXBuf[NumberOfChips - 1] |= 0b00000010;
}





