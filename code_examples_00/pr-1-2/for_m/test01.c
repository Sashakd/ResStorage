#include <stdio.h>
#include <string.h>

#include "..\filt.h"
#include "..\m_insert_sort.h"
#include "..\print_arr.h"

int main(void)
{
	int *arr1 = malloc(sizeof(int));
	*arr1 = 0;
	size_t n1 = 1;
	
	int *arr2 = malloc(sizeof(int)*3);
	*arr2     = -1;
	*(arr2+1) =  0;
	*(arr2+2) =  1;
	size_t n2 = 3;
	
	int *arr3 = malloc(sizeof(int)*10);
	*arr3     =  1;
	*(arr3+1) =  2;
	*(arr3+2) =  3;
	*(arr3+3) =  4;
	*(arr3+4) =  5;
	*(arr3+5) =  6;
	*(arr3+6) =  7;
	*(arr3+7) =  8;
	*(arr3+8) =  9;
	*(arr3+9) = 10;
	size_t n3 = 10;
	
	int *arr4 = malloc(sizeof(int)*10);
	*arr4     =  1;
	*(arr4+1) =  2;
	*(arr4+2) =  3;
	*(arr4+3) =  4;
	*(arr4+4) =  5;
	*(arr4+5) = -6;
	*(arr4+6) =  7;
	*(arr4+7) =  8;
	*(arr4+8) =  9;
	*(arr4+9) = 10;
	size_t n4 = 10;
	
	int *arr5 = malloc(sizeof(int)*10);
	*arr5     =  1;
	*(arr5+1) =  2;
	*(arr5+2) =  3;
	*(arr5+3) =  4;
	*(arr5+4) = -5;
	*(arr5+5) = -6;
	*(arr5+6) = -7;
	*(arr5+7) =  8;
	*(arr5+8) =  9;
	*(arr5+9) = 10;
	size_t n5 = 10;
	
	int *arr6 = malloc(sizeof(int)*10);
	*arr6     =  1;
	*(arr6+1) =  2;
	*(arr6+2) =  3;
	*(arr6+3) =  4;
	*(arr6+4) =  5;
	*(arr6+5) = -6;
	*(arr6+6) =  7;
	*(arr6+7) = -8;
	*(arr6+8) =  9;
	*(arr6+9) = 10;
	size_t n6 = 10;
	
	int *arr7 = malloc(sizeof(int)*10);
	*arr7     = -1;
	*(arr7+1) =  2;
	*(arr7+2) =  3;
	*(arr7+3) =  4;
	*(arr7+4) =  5;
	*(arr7+5) =  6;
	*(arr7+6) =  7;
	*(arr7+7) =  8;
	*(arr7+8) =  9;
	*(arr7+9) = 10;
	size_t n7 = 10;
	
	int *arr8 = malloc(sizeof(int)*10);
	*arr8     =   1;
	*(arr8+1) =   2;
	*(arr8+2) =   3;
	*(arr8+3) =   4;
	*(arr8+4) =   5;
	*(arr8+5) =  -6;
	*(arr8+6) =   7;
	*(arr8+7) =   8;
	*(arr8+8) =   9;
	*(arr8+9) = -10;
	size_t n8 = 10;
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr1, arr1+n1);
	printf("\n");
	filt(arr1, &n1, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr1, arr1+n1);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr2, arr2+n2);
	printf("\n");
	filt(arr2, &n2, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr2, arr2+n2);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr3, arr3+n3);
	printf("\n");
	filt(arr3, &n3, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr3, arr3+n3);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr4, arr4+n4);
	printf("\n");
	filt(arr4, &n4, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr4, arr4+n4);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr5, arr5+n5);
	printf("\n");
	filt(arr5, &n5, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr5, arr5+n5);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr6, arr6+n6);
	printf("\n");
	filt(arr6, &n6, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr6, arr6+n6);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr7, arr7+n7);
	printf("\n");
	filt(arr7, &n7, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr7, arr7+n7);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr8, arr8+n8);
	printf("\n");
	filt(arr8, &n8, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr8, arr8+n8);
	printf("\n");
	printf("\n");
	
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
	free(arr7);
	free(arr8);
	
	return 0;
}