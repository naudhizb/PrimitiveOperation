/*
 * BitOperation.h
 *
 *  Created on: 2020. 10. 14.
 *      Author: mjlee2
 */

#ifndef BITOPERATION_H_
#define BITOPERATION_H_

#if __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define BitOp_GetBit(data, offset)	    (!!((data)&(1 << (offset))))
#define BitOp_SetBit(data, offset)	    ((data) |= (1 << (offset)))
#define BitOp_ClearBit(data, offset)	((data) &=~(1 << (offset)))
#define BitOp_ToggleBit(data, offset)	((data) ^= (1 << (offset)))

#define BitOp_GetBits(data, mask)       ((data)&(mask))
#define BitOp_SetBits(data, mask)       ((data) |= (mask))
#define BitOp_ClearBits(data, mask)     ((data) &=~(mask))
#define BitOp_ToggleBits(data, mask)    ((data) ^= (mask))
#define BitOp_PutBits(data, mask, put_data) do {\
    BitOp_ClearBits(data, mask);\
    BitOp_SetBits(data, put_data);\
} while(0)

uint64_t BitOp_GetBitsWithShift(uint64_t data, uint64_t mask); // GetBits Automatically shift by LSBOffset
uint64_t BitOp_GetBitMask(uint32_t length); // Get BitMask by length
uint64_t BitOp_GetBitMaskWithOffset(uint32_t length, uint32_t offset);
int32_t  BitOp_GetLSBOffset(uint64_t data);

#if __cplusplus
}
#endif

#endif /* BITOPERATION_H_ */
