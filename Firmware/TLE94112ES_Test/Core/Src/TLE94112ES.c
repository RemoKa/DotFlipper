/*
 * TLE94112ES.c
 *
 *  Created on: 21.09.2021
 *      Author: Remo Kagerer
 */

#include "TLE94112ES.h"

void TLE94112ES_ConstructTXBuffer(uint8_t *TXBuf, int NumberOfChips, Message *Messages){


	//Daisy Chain
	for(int i = 0; i < NumberOfChips; i++){
		TXBuf[i] 					= (Messages[i].RegisterAdress | Messages[i].WriteClear) & 0b11111101;
		TXBuf[i + NumberOfChips] 	= Messages[i].Data;
	}

	//set Last Address Byte Token LABT
	TXBuf[NumberOfChips - 1] |= 0b00000010;
}

void TLE94112ES_DeconstructRXBuffer(uint8_t *RXBuf, int NumberOfChips, Message *Messages){

	//Daisy Chain
	StatusData globalStatus = 0;

	//calculate a single global Status by ORing all globalStatus responses
	for(int i = 0; i < NumberOfChips; i++){
			globalStatus |= RXBuf[i];
		}

	//set every messages global Status to single global Status
	for(int i = 0; i < NumberOfChips; i++){
			Messages[i].GlobalStatus = globalStatus;
		}

	//set Messages Response to received response in reverse order
	for(int i = 0; i < NumberOfChips; i++){
				Messages[i].Response = RXBuf[((NumberOfChips*2)-1) - i];
		}
}


