#include <stdio.h>
#include <stdlib.h>

/*
#include "read_arr.h"
#include "print_arr.h"
#include "diff_numb.h"
*/

#include "arr_lib.h"

// Программа читает до первого некорректного значения

int main()
{
	printf("BEGIN\n");
	FILE *f = NULL;
	int n;
	int *bg, *nd;
	int diff_num_cnt;
	
	int res1 = 0;
	int res2 = 0;
	int res3 = 0;
	int res4 = 0;
	int res5 = 0;
	int res6 = 0;
	int res7 = 0;
	int res8 = 0;
	int res9 = 0;
	int res10 = 0;
		
	f = fopen("../tests/t1.mp3", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t1.mp3]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
			
	if (n == 0)
	{
		printf("TEST01------------- V\n");
		res1 = 1;
	}
	else
	{
		printf("TEST01------------- X\n");
		res1 = 0;
	}
				
	fclose(f);
			
	f = fopen("../tests/t2.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t2.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
			
	if (n == 0)
	{
		printf("TEST02------------- V\n");
		res2 = 1;
	}
	else
	{
		printf("TEST02------------- X\n");
		res2 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t3.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t3.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
			
	if (n == 0)
	{
		printf("TEST03------------- V\n");
		res3 = 1;
	}
	else
	{
		printf("TEST03------------- X\n");
		res3 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t4.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t4.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 1]\n");
	if (n == 1 && diff_num_cnt == 1)
	{
		printf("TEST04------------- V\n");
		res4 = 1;
	}
	else
	{
		printf("TEST04------------- X\n");
		res4 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t5.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t5.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 10]\n");
	if (n == 10 && diff_num_cnt == 10)
	{
		printf("TEST05------------- V\n");
		res5 = 1;
	}
	else
	{
		printf("TEST05------------- X\n");
		res5 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t6.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t6.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 6]\n");
	if (n == 6 && diff_num_cnt == 6)
	{
		printf("TEST06------------- V\n");
		res6 = 1;
	}
	else
	{
		printf("TEST06------------- X\n");
		res6 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t7.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t7.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	if (n == 0)
	{
		printf("TEST07------------- V\n");
		res7 = 1;
	}
	else
	{
		printf("TEST07------------- X\n");
		res7 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t8.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t8.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 10]\n");
	if (n == 10 && diff_num_cnt == 10)
	{
		printf("TEST08------------- V\n");
		res8 = 1;
	}
	else
	{
		printf("TEST08------------- X\n");
		res8 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/t9.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/t9.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 14]\n");
	if (n == 22 && diff_num_cnt == 14)
	{
		printf("TEST09------------- V\n");
		res9 = 1;
	}
	else
	{
		printf("TEST09------------- X\n");
		res9 = 0;
	}
			
	fclose(f);
	
	f = fopen("../tests/a.txt", "r");
		
	if (!f)
		return -1;
	else
		printf("OPENED:[../tests/a.txt]\n");
		
	bg = NULL;
	nd = NULL;
		
	diff_num_cnt = 0;
		
	n = 0;

	n = get_num_cnt(f);         // Подсчёт длины массива
			
	if (n > 0)
	{
		bg = read_i_arr(f, n);  // Считывание массива из файла
		nd = bg + n;
				
		if (bg)
		{
			printf("\nInitial array:      ");
			print_i_arr(bg, nd);                      // Печать считанного массива
			printf("\n");
			printf("\nDiferent numbers count = "); 
			diff_num_cnt = get_diff_num_cnt(bg, nd);  // Количество различных чисел
			printf("%d\n", diff_num_cnt);             // Печать результата
            free(bg);
		}
	}
	else
		printf("Error! Have no numbers\n");
	
	printf("EXPECTED : [diff_num_cnt = 5]\n");
	if (n == 7 && diff_num_cnt == 5)
	{
		printf("TEST10------------- V\n");
		res10 = 1;
	}
	else
	{
		printf("TEST10------------- X\n");
		res10 = 0;
	}
			
	fclose(f);
			
	if (res1 && res2 && res3 && res4 && res5 && res6 && res7 && res8 && res9 && res10)
		printf("\n\nALL TESTS DONE [GOOD]\n");
	else
		printf("\n\nALL TESTS DONE [BAD ]\n");
			
	printf("ENDED\n");

    return 0;
}