#include "read_arr.h"

int get_num_cnt(FILE* f) // OK
{
    int cnt = 0;
	int num = 0;
	
    while (fscanf(f, "%d", &num) == 1)
	    cnt++;
			
	rewind(f);
	
	return cnt;
}

int* read_i_arr(FILE* f, int n) // OK
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