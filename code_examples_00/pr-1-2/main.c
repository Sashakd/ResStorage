// Задача 1-2 (3-4)
/*
Написать программу, которая упорядочивает массив.
Данные в массив считываются из файла (можно и нужно взять функцию чтения 
массива из предыдущей лабораторной работы). Полученный после сортировки 
массив записывается в файл.
Возможно, что перед сортировкой элементы массива могут быть отфильтрованы 
с помощью функции-фильтра.

Функция-фильтр работает следующим образом:
определяет количество элементов массива, которые удовлетворяют заданному
условию;
выделяет память под соответствующее количество элементов;
копирует элементы, удовлетворяющие условию, из старого массива в новый.

Функция сортировки реализуется универсальной (т.е. имеет одинаковый прототип с 
функцией qsort из стандартной библиотеки (stdlib.h)).

Все параметры (имена файлов, необходимость фильтрации) передаются через 
аргументы командной строки.
Для функции сортировки и функции-фильтра реализуются модульные тесты 
(отдельный проект).
При защите лабораторной работы необходимо продемонстрировать отчет утилиты 
Doctor Memory, свидетельствующий об отсутствии ошибок при работе с памятью.

Кроме того, необходимо сравнить время работы реализованного алгоритма 
сортировки и qsort. Постараться найти примеры, когда ваша реализация лучше. 
Результаты представить в виде графиков (рисунки в формате PNG, оси подписаны). 
Графики разместить в Wiki на отдельно странице. Графики можно строить любыми 
средствами (например, в Excel).

Алгоритм сортировки:
4) Модифицированная сортировка вставками. Для поиска места вставки 
нового элемента используется двоичный поиск.

Функция-фильтр:
3) В массиве остаются элементы от нулевого до p-го, где p - индекс последнего 
отрицательного элемента этого массива либо число n-1, если такого элемента в массиве нет;
*/

/*
void qsort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *))
*/

#include <stdio.h>
#include <string.h>

#include "read_arr.h"
#include "print_arr.h"
#include "m_insert_sort.h"
#include "filt.h"

int main(int argc,char** argv)
{
	FILE *in_f, *out_f;
	size_t n = 0;
	int*  arr = NULL;
	
	if (argc > 3)
	{
		in_f  = fopen(argv[1], "r");
		out_f = fopen(argv[2], "w");
		
		if (in_f && out_f)
		{
			n   = get_num_cnt(in_f);
			arr = read_i_arr(in_f, n);
			
			printf("\n\n");
			printf("	FILE [%s] OPENED\n", argv[1]);
			printf("	FILE [%s] CREATED\n", argv[2]);
			
			if (arr && (n > 0))
			{
				printf("	ARRAY LOADED\n");
				printf("	ARRAY: \n	");
				print_i_arr(stdout, arr, arr+n);
				printf("\n");
				printf("\n");
				
				for (int i = 3; i < argc; i++)
				{
					if (strncmp(argv[i], "-filt", 5) == 0)
					{
						printf("		ARRAY FILTERING\n");
						filt(arr, &n, sizeof(int), compare_int);
						
						if (arr)
						{
							printf("			SUCCESS\n");
							printf("			ARRAY: \n		");
							print_i_arr(stdout, arr, arr+n);
							printf("\n");
							printf("			ARRAY FILTERED\n");
						}
						else
						{
							printf("			FAILED\n");
							break;
						}
						
						printf("\n");
					}
					else
					if (strncmp(argv[i], "-sort", 5) == 0)
					{
						printf("		ARRAY SORTING\n");
						modified_insertion_sort(arr, n, sizeof(int), compare_int);
						
						if (arr)
						{
							printf("			SUCCESS\n");
							printf("			ARRAY: \n		");
							print_i_arr(stdout, arr, arr+n);
							printf("\n");
							printf("			ARRAY SORTED\n");
						}
						else
						{
							printf("			FAILED\n");
							break;
						}
						
						printf("\n");
					}
					else
					if (strncmp(argv[i], "-help", 5) == 0)
					{
						printf("		GETTING HELP\n");
						printf("-- Help: --\n	main.exe [input.txt] [output.txt] (-argument)\n");
						printf("\n				Arguments:\n		-filt  --  filtration\n		-sort");
						printf("  --  modified insertion sort\n		-help  --  show help\n\n");
					}
					else
						printf("		[%s] is not argument of [main.exe]. IGNORED.\n", argv[i]);
				}
				
				printf("	RECORDING\n");
				printf("			");
				
				print_i_arr(out_f, arr, arr+n);
				
				printf("\n			DONE\n	ENDED\n");
				
			}
			else
				printf("	ARRAY NOT LOADED\n");
			
			if (arr)
				free(arr);
			
			fclose(in_f);
			fclose(out_f);
		}
		else
		{
			if (!in_f)
			{
				printf("Could not open file   [%s]\n", argv[1]);
				printf("(Please  try again)\n");
			}
			
			if (!out_f)
			{
				printf("Could not create file [%s]\n", argv[2]);
				printf("(Please  try again)\n");
			}
			
			if (in_f)
				fclose(in_f);
			
			if (out_f)
				fclose(out_f);
		}
	}
	else
	{
		printf("-- Help: --\n	main.exe [input.txt] [output.txt] (-argument)\n");
		printf("\n				Arguments:\n		-filt  --  filtration\n		-sort");
		printf("  --  modified insertion sort\n		-help  --  show help\n\n");
	}
	
	return 0;
}