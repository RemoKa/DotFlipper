/*
 * TLE94112ES.h
 *
 *  Created on: 21.09.2021
 *      Author: Remo Kagerer
 */

#ifndef INC_TLE94112ES_H_
#define INC_TLE94112ES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


typedef enum RegisterAdresses
{
	//Control Registers
	HB_ACT_1_CTRL 		= 0x03,
	HB_ACT_2_CTRL 		= 0x43,
	HB_ACT_3_CTRL 		= 0x23,
	HB_MODE_1_CTRL		= 0x63,
	HB_MODE_2_CTRL		= 0x13,
	HB_MODE_3_CTRL		= 0x53,
	PWM_CH_FREQ_CTRL	= 0x33,
	PWM1_DC_CTRL 		= 0x73,
	PWM2_DC_CTRL 		= 0x0B,
	PWM3_DC_CTRL		= 0x4B,
	FW_OL_CTRL			= 0x2B,
	FW_CTRL				= 0x6B,
	CONFIG_CTRL			= 0x67,
	//Status Registers
	SYS_DIAG1 			= 0x1B,
	OP_ERROR_1_STAT 	= 0x5B,
	OP_ERROR_2_STAT 	= 0x3B,
	OP_ERROR_3_STAT		= 0x7B,
	OP_ERROR_4_STAT		= 0x07,
	OP_ERROR_5_STAT		= 0x47,
	OP_ERROR_6_STAT		= 0x27
}RegisterAdresses;

static const uint8_t HbActCtrlLookup[12] = {
		HB_ACT_1_CTRL,
		HB_ACT_1_CTRL,
		HB_ACT_1_CTRL,
		HB_ACT_1_CTRL,

		HB_ACT_2_CTRL,
		HB_ACT_2_CTRL,
		HB_ACT_2_CTRL,
		HB_ACT_2_CTRL,

		HB_ACT_3_CTRL,
		HB_ACT_3_CTRL,
		HB_ACT_3_CTRL,
};


typedef enum ControlData
{
	HB1_LS_EN 			= 0b00000001,
	HB1_HS_EN 			= 0b00000010,
	HB2_LS_EN 			= 0b00000100,
	HB2_HS_EN 			= 0b00001000,
	HB3_LS_EN 			= 0b00010000,
	HB3_HS_EN 			= 0b00100000,
	HB4_LS_EN 			= 0b01000000,
	HB4_HS_EN 			= 0b10000000,

	HB5_LS_EN 			= 0b00000001,
	HB5_HS_EN 			= 0b00000010,
	HB6_LS_EN 			= 0b00000100,
	HB6_HS_EN 			= 0b00001000,
	HB7_LS_EN 			= 0b00010000,
	HB7_HS_EN 			= 0b00100000,
	HB8_LS_EN 			= 0b01000000,
	HB8_HS_EN 			= 0b10000000,

	HB9_LS_EN 			= 0b00000001,
	HB9_HS_EN 			= 0b00000010,
	HB10_LS_EN 			= 0b00000100,
	HB10_HS_EN 			= 0b00001000,
	HB11_LS_EN 			= 0b00010000,
	HB11_HS_EN 			= 0b00100000,
	HB12_LS_EN 			= 0b01000000,
	HB12_HS_EN 			= 0b10000000,

	HB1_MODE0 			= 0b00000001,
	HB1_MODE1			= 0b00000010,
	HB2_MODE0 			= 0b00000100,
	HB2_MODE1 			= 0b00001000,
	HB3_MODE0 			= 0b00010000,
	HB3_MODE1 			= 0b00100000,
	HB4_MODE0 			= 0b01000000,
	HB4_MODE1 			= 0b10000000,

	HB5_MODE0 			= 0b00000001,
	HB5_MODE1			= 0b00000010,
	HB6_MODE0 			= 0b00000100,
	HB6_MODE1 			= 0b00001000,
	HB7_MODE0 			= 0b00010000,
	HB7_MODE1 			= 0b00100000,
	HB8_MODE0 			= 0b01000000,
	HB8_MODE1 			= 0b10000000,

	HB9_MODE0 			= 0b00000001,
	HB9_MODE1			= 0b00000010,
	HB10_MODE0 			= 0b00000100,
	HB10_MODE1 			= 0b00001000,
	HB11_MODE0 			= 0b00010000,
	HB11_MODE1 			= 0b00100000,
	HB12_MODE0 			= 0b01000000,
	HB12_MODE1 			= 0b10000000,

	PWM_CH1_FREQ_0 		= 0b00000001,
	PWM_CH1_FREQ_1		= 0b00000010,
	PWM_CH2_FREQ_0 		= 0b00000100,
	PWM_CH2_FREQ_1 		= 0b00001000,
	PWM_CH3_FREQ_0 		= 0b00010000,
	PWM_CH3_FREQ_1 		= 0b00100000,
	FM_CLK_MOD0 		= 0b01000000,
	FM_CLK_MOD1 		= 0b10000000,

	PWM1_DC_CTRL_0 		= 0b00000001,
	PWM1_DC_CTRL_1		= 0b00000010,
	PWM1_DC_CTRL_2 		= 0b00000100,
	PWM1_DC_CTRL_3 		= 0b00001000,
	PWM1_DC_CTRL_4 		= 0b00010000,
	PWM1_DC_CTRL_5 		= 0b00100000,
	PWM1_DC_CTRL_6 		= 0b01000000,
	PWM1_DC_CTRL_7 		= 0b10000000,

	PWM2_DC_CTRL_0 		= 0b00000001,
	PWM2_DC_CTRL_1		= 0b00000010,
	PWM2_DC_CTRL_2 		= 0b00000100,
	PWM2_DC_CTRL_3 		= 0b00001000,
	PWM2_DC_CTRL_4 		= 0b00010000,
	PWM2_DC_CTRL_5 		= 0b00100000,
	PWM2_DC_CTRL_6 		= 0b01000000,
	PWM2_DC_CTRL_7 		= 0b10000000,

	PWM3_DC_CTRL_0 		= 0b00000001,
	PWM3_DC_CTRL_1		= 0b00000010,
	PWM3_DC_CTRL_2 		= 0b00000100,
	PWM3_DC_CTRL_3 		= 0b00001000,
	PWM3_DC_CTRL_4 		= 0b00010000,
	PWM3_DC_CTRL_5 		= 0b00100000,
	PWM3_DC_CTRL_6 		= 0b01000000,
	PWM3_DC_CTRL_7 		= 0b10000000,

	OL_SEL_HS1 			= 0b00000001,
	OL_SEL_HS2			= 0b00000010,
	FW_HB1 				= 0b00000100,
	FW_HB2 				= 0b00001000,
	FW_HB3 				= 0b00010000,
	FW_HB4 				= 0b00100000,
	FW_HB5 				= 0b01000000,
	FW_HB6 				= 0b10000000,

	FW_HB7 				= 0b00000001,
	FW_HB8				= 0b00000010,
	FW_HB9 				= 0b00000100,
	FW_HB10 			= 0b00001000,
	FW_HB11 			= 0b00010000,
	FW_HB12 			= 0b00100000,
	//reserved 			= 0b01000000,
	//reserved 			= 0b10000000,

	DEV_ID0 			= 0b00000001,
	DEV_ID1				= 0b00000010,
	DEV_ID2 			= 0b00000100,
	//reserved 			= 0b00001000,
	//reserved 			= 0b00010000,
	//reserved 			= 0b00100000,
	//reserved 			= 0b01000000,
	//reserved 			= 0b10000000,
}ControlData;

static const uint8_t HbEnLookup[12][2] = {
		{HB1_LS_EN, HB1_HS_EN},
		{HB2_LS_EN, HB2_HS_EN},
		{HB3_LS_EN, HB3_HS_EN},
		{HB4_LS_EN, HB4_HS_EN},
		{HB5_LS_EN, HB5_HS_EN},
		{HB6_LS_EN, HB6_HS_EN},
		{HB7_LS_EN, HB7_HS_EN},
		{HB8_LS_EN, HB8_HS_EN},
		{HB9_LS_EN, HB9_HS_EN},
		{HB10_LS_EN, HB10_HS_EN},
		{HB11_LS_EN, HB11_HS_EN},
		{HB12_LS_EN, HB12_HS_EN},
};

typedef enum StatusData
{
	//reserved 			= 0b00000001,
	TPW					= 0b00000010,
	TSD 				= 0b00000100,
	NPOR 				= 0b00001000,
	VS_OV 				= 0b00010000,
	VS_UV 				= 0b00100000,
	LE 					= 0b01000000,
	SPI_ERR 			= 0b10000000,

	HB1_LS_OC 			= 0b00000001,
	HB1_HS_OC			= 0b00000010,
	HB2_LS_OC 			= 0b00000100,
	HB2_HS_OC 			= 0b00001000,
	HB3_LS_OC 			= 0b00010000,
	HB3_HS_OC 			= 0b00100000,
	HB4_LS_OC 			= 0b01000000,
	HB4_HS_OC 			= 0b10000000,

	HB5_LS_OC 			= 0b00000001,
	HB5_HS_OC			= 0b00000010,
	HB6_LS_OC 			= 0b00000100,
	HB6_HS_OC 			= 0b00001000,
	HB7_LS_OC 			= 0b00010000,
	HB7_HS_OC 			= 0b00100000,
	HB8_LS_OC 			= 0b01000000,
	HB8_HS_OC 			= 0b10000000,

	HB9_LS_OC 			= 0b00000001,
	HB9_HS_OC			= 0b00000010,
	HB10_LS_OC 			= 0b00000100,
	HB10_HS_OC 			= 0b00001000,
	HB11_LS_OC 			= 0b00010000,
	HB11_HS_OC 			= 0b00100000,
	HB12_LS_OC 			= 0b01000000,
	HB12_HS_OC 			= 0b10000000,

	HB1_LS_OL 			= 0b00000001,
	HB1_HS_OL			= 0b00000010,
	HB2_LS_OL 			= 0b00000100,
	HB2_HS_OL 			= 0b00001000,
	HB3_LS_OL 			= 0b00010000,
	HB3_HS_OL 			= 0b00100000,
	HB4_LS_OL 			= 0b01000000,
	HB4_HS_OL 			= 0b10000000,

	HB5_LS_OL 			= 0b00000001,
	HB5_HS_OL			= 0b00000010,
	HB6_LS_OL 			= 0b00000100,
	HB6_HS_OL 			= 0b00001000,
	HB7_LS_OL 			= 0b00010000,
	HB7_HS_OL 			= 0b00100000,
	HB8_LS_OL 			= 0b01000000,
	HB8_HS_OL 			= 0b10000000,

	HB9_LS_OL 			= 0b00000001,
	HB9_HS_OL			= 0b00000010,
	HB10_LS_OL 			= 0b00000100,
	HB10_HS_OL 			= 0b00001000,
	HB11_LS_OL 			= 0b00010000,
	HB11_HS_OL 			= 0b00100000,
	HB12_LS_OL 			= 0b01000000,
	HB12_HS_OL 			= 0b10000000,
}StatusData;

typedef enum ReadWriteClear
{
	READ 				= 0b00000000,
	WRITE 				= 0b10000000,
	CLEAR				= 0b10000000,
}ReadWriteClear;



typedef struct Message
{
	RegisterAdresses 	RegisterAdress;
	ControlData 		Data;
	ReadWriteClear		WriteClear;
	StatusData			Response;
	StatusData			GlobalStatus;
}Message;

void TLE94112ES_ConstructTXBuffer(uint8_t *TXBuf, int length, Message *Messages);

void TLE94112ES_DeconstructRXBuffer(uint8_t *RXBuf, int NumberOfChips, Message *Messages);

#ifdef __cplusplus
}
#endif
#endif /* INC_TLE94112ES_H_ */
