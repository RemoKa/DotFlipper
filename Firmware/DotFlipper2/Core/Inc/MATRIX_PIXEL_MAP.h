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
#include "TLE94112ES.h"

// { {{Pin rowHigh},{Pin rowLow},{Pin column} }},

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
		{C0,4},
		{C0,6},
		{C0,9},
		{C0,7},
		{C0,5},
		{C0,1},
		{C0,2},
		{C0,8},
		{C0,12},
		{C0,11},
		{C0,10},
		{C0,3},

		{C1,4},
		{C1,6},
		{C1,9},
		{C1,7},
		{C1,5},
		{C1,1},
		{C1,2},
		{C1,8},
		{C1,12},
		{C1,11},
		{C1,10},

		{C1,3},
		{C2,6},
		{C2,9},
		{C2,7},
		{C2,5},
		{C2,1},
		{C2,2}
};

static const volatile Pixel PixelMap[30][12] = {
		{ {{4,1},{4,5},{0,4}} , {{0,0},{0,0},{0,0}} , },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
		{  },
};


#ifdef __cplusplus
}
#endif
#endif /* INC_MATRIX_PIXEL_MAP_H_ */
