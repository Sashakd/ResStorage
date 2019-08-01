#include "print_arr.h"

void print_i_arr(int* bg, int* nd) // OK
{
    if (bg && nd)
        if (nd > bg)
            for (; bg < nd; bg++)
	            printf("%d ", *bg);
}
