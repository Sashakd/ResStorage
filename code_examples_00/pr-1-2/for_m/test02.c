#include <stdio.h>
#include <string.h>

#include "..\m_insert_sort.h"
#include "..\print_arr.h"

int main(void)
{
	int arr1[] = {0};
	size_t n1 = 1;
	
	int arr2[] = {0, 1, 2, 3, 4, 5, 6};
	size_t n2 = 7;
	
	int arr3[] = {6, 5, 4, 3, 2, 1, 0};
	size_t n3 = 7;
	
	int arr4[] = {1, -1};
	size_t n4 = 2;
	
	int arr5[] = {-1, 1};
	size_t n5 = 2;
	
	int arr6[] = {1, 2, 3, 4, 4, 6, 7, 3, 9, 34, 4, 456, 2, 3235, 23, -12, -12, -6, 21, -4, 2};
	size_t n6 = 21;
	
	
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr1, arr1+n1);
	printf("\n");
	modified_insertion_sort(arr1, n1, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr1, arr1+n1);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr2, arr2+n2);
	printf("\n");
	modified_insertion_sort(arr2, n2, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr2, arr2+n2);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr3, arr3+n3);
	printf("\n");
	modified_insertion_sort(arr3, n3, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr3, arr3+n3);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr4, arr4+n4);
	printf("\n");
	modified_insertion_sort(arr4, n4, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr4, arr4+n4);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr5, arr5+n5);
	printf("\n");
	modified_insertion_sort(arr5, n5, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr5, arr5+n5);
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("INITIAL ARR: ");
	print_i_arr(arr6, arr6+n6);
	printf("\n");
	modified_insertion_sort(arr6, n6, sizeof(int), compare_int);
	printf(" RESULT ARR: ");
	print_i_arr(arr6, arr6+n6);
	printf("\n");
	printf("\n");
	
	return 0;
}