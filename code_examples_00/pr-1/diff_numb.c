#include "diff_numb.h"

// Определяет количество вхождений num в массив bg,nd
int num_if_in_cnt(int* bg, int* nd, int num)
{
	int cnt = 0;

	for (; bg < nd; bg++)
	    if (num == *bg)
			cnt++;
	
	return cnt;
}

int get_diff_num_cnt(int* bg, int* nd)
{
	int* da = bg;
	int  dn = 0;
	
	for (; bg < nd; bg++)
	    if (num_if_in_cnt(da, bg, *bg) == 0)
			dn++;
	
	return dn;
}