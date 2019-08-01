#include "print_arr.h"

void print_i_arr(FILE* f, int* bg, int* nd)
{
    if (bg && nd)
        if (nd > bg)
            for (; bg < nd; bg++)
	            fprintf(f, "%d ", *bg);
}
