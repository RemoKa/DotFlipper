/*
 * MATRIX.c
 *
 *  Created on: 15.04.2022
 *      Author: Remo
 */


#include "MATRIX.h"
#include "MATRIX_PIXEL_MAP.h"

void setPixel(uint8_t x, uint8_t y, uint8_t state, uint8_t *TXBuf, uint8_t *RXBuf, uint8_t daisyChainLength, SPI_HandleTypeDef hspi){

	Message messages[daisyChainLength];
	clearMessages(messages, daisyChainLength);

	//lookup row and column info of pixel
	const Column *c = &ColumnMap[x];
	const Row *r = &RowMap[y];

	//cache messages in message index that concern this pixel
	Message* mRH = &messages[r->high.chainIndex];
	Message* mRL = &messages[r->low.chainIndex];
	Message* mC = &messages[c->pin.chainIndex];

	if(state){

		clearMessages(messages, daisyChainLength);
		//set row high Pin to high

		setPin(mRH, r->high, 1);
		setPin(mC, c->pin, 0);

		TLE94112ES_ConstructTXBuffer(TXBuf, daisyChainLength, messages);

		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
		HAL_SPI_TransmitReceive(&hspi, TXBuf, RXBuf, daisyChainLength * 2, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	TLE94112ES_DeconstructRXBuffer(RXBuf, daisyChainLength, messages);


		HAL_Delay(PULSE_LENGHT);

		clearMessages(messages, daisyChainLength);

		//set Pins back to HighZ

		setPin(mRH, r->high, -1);
		setPin(mC, c->pin, -1);

		TLE94112ES_ConstructTXBuffer(TXBuf, daisyChainLength, messages);

		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
		HAL_SPI_TransmitReceive(&hspi, TXBuf, RXBuf, daisyChainLength * 2, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	TLE94112ES_DeconstructRXBuffer(RXBuf, daisyChainLength, messages);


	}else{
		clearMessages(messages, daisyChainLength);
		//set row low Pin to low

		setPin(mRL, r->low, 0);
		setPin(mC, c->pin, 1);

		TLE94112ES_ConstructTXBuffer(TXBuf, daisyChainLength, messages);

		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
		HAL_SPI_TransmitReceive(&hspi, TXBuf, RXBuf, daisyChainLength * 2, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	TLE94112ES_DeconstructRXBuffer(RXBuf, daisyChainLength, messages);


		HAL_Delay(PULSE_LENGHT);

		clearMessages(messages, daisyChainLength);

		//set Pins back to HighZ

		setPin(mRL, r->low, -1);
		setPin(mC, c->pin, -1);

		TLE94112ES_ConstructTXBuffer(TXBuf, daisyChainLength, messages);

		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
		HAL_SPI_TransmitReceive(&hspi, TXBuf, RXBuf, daisyChainLength * 2, HAL_MAX_DELAY);
		HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	TLE94112ES_DeconstructRXBuffer(RXBuf, daisyChainLength, messages);


	}

	//set row high or low pin

	//turn column pin opposite on
	//delay
	//set column pin highZ

	//set row pin highZ

}

void clearMessages(Message *messages, uint8_t lenght){
	for(int i = 0; i < lenght; i++){
			messages[i] = emptyMessage;
	}
}

void setPin(Message* m, Pin p, int8_t state){
	m->RegisterAdress = HbActCtrlLookup[p.hBridgeIndex];
	switch (state){
	case -1: //HighZ
		m->Data &= !HbEnLookup[p.hBridgeIndex][0];
		m->Data &= !HbEnLookup[p.hBridgeIndex][1];
		break;

	case 0:	//Low
		m->Data |= HbEnLookup[p.hBridgeIndex][0];
		m->Data &= !HbEnLookup[p.hBridgeIndex][1];
		break;

	case 1: //High
		m->Data &= !HbEnLookup[p.hBridgeIndex][0];
		m->Data |= HbEnLookup[p.hBridgeIndex][1];
		break;
	default:
		break;
	}
	m->WriteClear = WRITE;
}

