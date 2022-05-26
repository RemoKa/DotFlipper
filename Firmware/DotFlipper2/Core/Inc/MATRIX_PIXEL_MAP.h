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

static const volatile Pixel PixelMap[30][12] = {
		{ {{4, HB_ACT_1_CTRL, HB1_HS_EN},{4, HB_ACT_2_CTRL, HB5_LS_EN},{0, HB_ACT_1_CTRL, HB4_LS_EN} }},
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
