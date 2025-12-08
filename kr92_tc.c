#include "kr92_tc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

kr92_test_case cur_test_case = NONE;

void init(uint value)
{
	cur_test_case = (kr92_test_case)value;
}

kr92_test_case get_tc()
{
	return cur_test_case;
}

uint getMacOffset(uint buffer_len)
{
	return buffer_len - MAC_SIZE;
}

void setHeader(buf* target, kr92_header_type h_type, kr92_header_offset value)
{
	buf* header = &target[HEADER_OFFSET];
	switch(h_type)
	{
		/* 각 BIT_MASK_* 값은 유지할 비트를 1로 둔 값이므로
		 * AND로 기존 필드를 지운 뒤 OR로 새 값을 채운다. */
		case ETY:  *header = (*header & BIT_MASK_ETY) | value; break;
		case TYPE: *header = (*header & BIT_MASK_MTI) | value; break;
		case DF:   *header = (*header & BIT_MASK_DF) | value; break;
	}
}

void setMac(buf* target, uint bufLen, unsigned long value)
{
	uint offset = getMacOffset(bufLen);
	memset(&target[offset], (unsigned char)value, MAC_SIZE);
}

void setBufferLen(buf* target)
{
	// TODO: 함수 구현 필요
	// 현재 구현은 미완성 상태이며 사용 시 주의 필요
	(void)target; // 경고 방지
	/* 
	 * buf* nextBuf = target;
	 * // TODO nextBuf  -1 
	 * free(target);
	 * target = nextBuf;
	 */
}

void setEtcsId(buf* target, kr92_body_type b_type, uint value)
{
	uint bit_mask = 0xFF;
	uint i = (b_type == AU1) ? au1_sa_start :
	         (b_type == AU2) ? au2_sa_start : 0xFFFFFFFF;
	switch (b_type) /* TODO */
	{
	case AU1: 
		for (; i <= au1_sa_end; ++i)
		{ 
			uint shift = (au1_sa_end - i) * 8;
			target[i] = (value >> shift) & bit_mask;
		}
		
		break;
	case AU2: 
		for (; i <= au2_sa_end; ++i)
		{
			uint shift = (au2_sa_end - i) * 8;
			target[i] = (value >> shift) & bit_mask;
		}
		break;
		default: printf("kr92_tc_setEtcsId type error\n");

	}
}

void setSaF(buf* target, kr92_body_type b_type, buf b)
{
	uint offset = 0;
	if (b != 1)
	{
		switch (b_type) /* TODO */
		{
		case AU1:
			offset = au1_sa_end + 1;
			target[offset] = b;
			break;
		case AU2:
			offset = au2_sa_end + 1;
			target[offset] = b;
			break;
		default: printf("kr92_tc_setSaF type error\n");
		}
	}
	else
	{
		printf("kr92_tc_setSaF must be buf value is not 1\n");
	}

}




