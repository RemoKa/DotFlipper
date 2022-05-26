/*
 * MATRIX_PIXEL_MAP.h
 *
 *  Created on: 22.05.2022
 *      Author: Remo
 */

#ifndef INC_MATRIX_PIXEL_MAP_H_
#define INC_MATRIX_PIXEL_MAP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "MATRIX.h"

static const volatile Row RowMap[12] = {
		{{R1,1 },{R1,5 }},	//0
		{{R1,7 },{R1,9 }},	//1
		{{R1,6 },{R1,4 }},	//2
		{{R1,3 },{R1,10}},	//3
		{{R1,11},{R1,12}},	//4
		{{R1,8 },{R1,2 }},	//5

		{{R0,10},{R0,3 }},	//6
		{{R0,12},{R0,11}},	//7
		{{R0,2 },{R0,8 }},	//8
		{{R0,5 },{R0,1 }},	//9
		{{R0,9 },{R0,7 }},	//10
		{{R0,4 },{R0,6 }}	//11
};
static const volatile Column ColumnMap[30] = {
		{{C0,4}},		//0
		{{C0,6}},		//1
		{{C0,9}},		//2
		{{C0,7}},		//3
		{{C0,5}},		//4
		{{C0,1}},		//5
		{{C0,2}},		//6
		{{C0,8}},		//7
		{{C0,12}},		//8
		{{C0,11}},		//9
		{{C0,10}},		//10
		{{C0,3}},		//11

		{{C1,4}},		//12
		{{C1,6}},		//13
		{{C1,9}},		//14
		{{C1,7}},		//15
		{{C1,5}},		//16
		{{C1,1}},		//17
		{{C1,2}},		//18
		{{C1,8}},		//19
		{{C1,12}},		//20
		{{C1,11}},		//21
		{{C1,10}},		//22

		{{C1,3}},		//23
		{{C2,6}},		//24
		{{C2,9}},		//25
		{{C2,7}},		//26
		{{C2,5}},		//27
		{{C2,1}},		//28
		{{C2,2}}		//29
};

#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_PIXEL_MAP_H_ */
