#include "arr_lib.h"

// Ввод
int get_num_cnt(FILE* f)
{
    int cnt = 0;
	int num = 0;
	
    while (fscanf(f, "%d", &num) == 1)
	    cnt++;
			
	rewind(f);
	
	return cnt;
}

int* read_i_arr(FILE* f, int n)
{
    int* buff = NULL;
	
	int i = 0;
	
	buff = malloc(sizeof(int)*n);
	
	if (buff)
	{
	    while(fscanf(f, "%d", buff + i) == 1)
		    i++;
	}
	else
	    printf("Warning! Out of memory\n");

	return buff;
}

// Вывод
void print_i_arr(int* bg, int* nd)
{
    if (bg && nd)
        if (nd > bg)
            for (; bg < nd; bg++)
	            printf("%d ", *bg);
}


// Обработка
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