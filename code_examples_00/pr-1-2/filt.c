#include "filt.h"

void filt(void *base, size_t *num, size_t size, int (*compare) (const void *, const void *))
{
	if (base && (*num > 0) && (size > 0))
	{
		char* arr = base;
		int z = 0;
		int b_len = -1;
		
		for (int i = 0; i < *num; i++)
			if((*compare)(arr + i*size, &z) < 0)
				b_len = i;
				
		if (b_len < 0)
			b_len = *num-1;
		
		*num = b_len+1;
		
		realloc(arr, size * (b_len + 1));
	}
	else
		base = NULL;
}