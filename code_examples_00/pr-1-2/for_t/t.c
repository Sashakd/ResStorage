#include <stdio.h>
#include <stdlib.h>

#include "time.h"
#include "windows.h"
#include "..\m_insert_sort.h"
#include "..\read_arr.h"
#include "..\read_arr.h"
#include "..\print_arr.h"

#define Pause 500

int main(int argc, char* argv[])
{
	unsigned long long t1, t2, t3, t4;
	unsigned long long t_m_insert_sort, t_qsort;
	
	if (argc < 1)
	{
		printf("TEXT FILE FAIL\n");
		return 0;
	}
	
	// ИНИЦИАЛИЗАЦИЯ
	FILE *f = NULL;
	int* arr1;
	int* arr2;
	int n;
	
	
	f = fopen(argv[1], "r");
	
	if (f)
	{
		n = get_num_cnt(f);
		
		arr1 = read_i_arr(f, n);
		rewind(f);
		arr2 = read_i_arr(f, n);
		
		printf("\n");
		printf("	INITIAL ARR1: ");
		print_i_arr(arr1, arr1+n);
		printf("\n");
		printf("	INITIAL ARR2: ");
		print_i_arr(arr2, arr2+n);
		printf("\n\n");
	
		Sleep(Pause);
		t1 = tick();
		//////////////////////    ПРОГОН QSORT   //////////////////////
		qsort(arr1, n, sizeof(int), compare_int);
		//////////////////////    ПРОГОН QSORT   //////////////////////
		t2 = tick();
		Sleep(Pause);
		t3 = tick();
		////////////////////// ПРОГОН M_INS_SORT //////////////////////
		modified_insertion_sort(arr2, n, sizeof(int), compare_int);
		////////////////////// ПРОГОН M_INS_SORT //////////////////////
		t4 = tick();
		Sleep(Pause);
	
		// ВЫВОД РЕЗУЛЬТАТА
		t_qsort         = t2 - t1;
		t_m_insert_sort = t4 - t3;
		
		printf("--------------------------------------------\n");
		printf("\n");
		printf("	RESULT ARR1: ");
		print_i_arr(arr1, arr1+n);
		printf("\n");
		printf("	RESULT ARR2: ");
		print_i_arr(arr2, arr2+n);
		printf("\n");
		printf("\n");
		printf("                  (qsort) time = %lld\n", t_qsort);
		printf("(modified_insertion_sort) time = %lld\n", t_m_insert_sort);
		
		free(arr1);
		free(arr2);
		
		fclose(f);
	}
	else
		printf("EPIC FAIL\n");
	
	return 1;
}