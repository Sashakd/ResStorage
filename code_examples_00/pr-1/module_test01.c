#include <stdio.h>
#include "diff_numb.h" // <-- Тестируется это
#include "print_arr.h"

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
	
	printf("diff_numb.h test:\n\n");
	printf("--[num_if_in] test:\n");
	printf("---------------------------");
	printf("\n5 ");
	if (!num_if_in_cnt(arr1, arr1+5, 5))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+5);
	printf("]");
	
	printf("\n7 ");
	if (!num_if_in_cnt(arr1, arr1+5, 7))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+5);
	printf("]");
	
	printf("\n1 ");
	if (!num_if_in_cnt(arr1, arr1+5, 1))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+5);
	printf("]");
	
	printf("\n3 ");
	if (!num_if_in_cnt(arr1, arr1+5, 3))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+5);
	printf("]");
	
	printf("\n5 ");
	if (!num_if_in_cnt(arr1, arr1+4, 5))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+4);
	printf("]");
	
	printf("\n1 ");
	if (!num_if_in_cnt(arr1, arr1, 1))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1);
	printf("]");
	
	printf("\n5 ");
	if (!num_if_in_cnt(arr1, arr1+1, 5))
	    printf("not ");
    printf("in [");
	print_i_arr(arr1, arr1+1);
	printf("]");
	
	int arr2[] = {1, 1, 3, 4, 5, 6, 9, 81, 20, 5, 1};
	int diff_n = 0;
	
	printf("\n\n");
	printf("--[get_diff_num_cnt] test:\n");
	printf("---------------------------\n");
	
	for (int i = 1; i < 11; i++)
	{
        diff_n = get_diff_num_cnt(arr2, arr2+i);
	    printf("ARR:[");
	    print_i_arr(arr2, arr2+i);
	    printf("]\n");
	    printf("DIFF. NUMB. = %d\n", diff_n);
		printf("\n");
	}
	
	int arr3[] = {1, 2, 3, 4, 5, 6, 9};
		diff_n = get_diff_num_cnt(arr3, arr3+7);
	    printf("ARR:[");
	    print_i_arr(arr3, arr3+7);
	    printf("]\n");
	    printf("DIFF. NUMB. = %d\n", diff_n);
		printf("\n");
    		
	return 0;
}