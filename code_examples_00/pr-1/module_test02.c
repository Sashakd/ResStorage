#include <stdio.h>
#include "read_arr.h"   // <-- Тестируется это
#include "print_arr.h"

int main(void)
{
    FILE* f = NULL;
	int* arr = NULL;
	
	int n = 0;
	
	printf("read_arr.h test:\n\n");
	printf("--[get_num_cnt] and [read_i_arr] test:\n");
	printf("---------------------------\n");
	
	f = fopen("t1.mp3", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t1.mp3]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t2.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t2.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	
	f = fopen("t3.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t3.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t4.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t4.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t5.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t5.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t6.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t6.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	printf("\n");
	
	f = fopen("t7.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t7.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t8.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t8.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	
	f = fopen("t9.txt", "r");
	n = get_num_cnt(f);
	printf("FILE OPENED: [t9.txt]\n");
	printf("NUM. COUNT: [%d]\n", n);
	if (n != 0)
	{
	    arr = read_i_arr(f, n);
	    printf("ARR: [");
		print_i_arr(arr, arr+n);
		printf("]\n");
		free(arr);
	}
	else
	    printf("NO ARR\n");
	fclose(f);
	printf("\n");
	printf("\n");
	
	return 0;
}