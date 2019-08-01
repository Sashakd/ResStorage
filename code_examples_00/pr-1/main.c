﻿// Вариант 5 //6
///
/*
Цель работы – приобрести навыки работы с динамической памятью (выделение 
и освобождение памяти в «куче», адресная арифметика), указателями на 
функции и ПО для отладки использования памяти Doctor Memory.  

Срок сдачи лабораторной работы – третья неделя.  

При решении задач в методических целях нельзя использовать выражение вида 
a[i] и вообще квадратные скобки (только в этой лабораторной работе). 
Вместо него используется выражение *pa, где pa - указатель на i-ый элемент 
массива (именно на i-ый элемент, а не выражение вида *(pa + i)). Также нельзя 
передавать как аргумент размер массива в элементах, если массив уже создан. 
Вместо этого предлагается использовать пару указателей: на первый элемент 
массива и на элемент массива, расположенный за последним. Ситуация когда 
эти указатели совпадают, означает пустоту обрабатываемого массива.  

Задача 1.  
Написать программу, которая считывает из текстового файла целые числа в массив 
и выполняет обработку этого массива (см. распределение вариантов в таблице).   
Память под массив выделяется динамически. Число элементов в массиве определяется в 
первом проходе по текстовому файлу, во время второго прохода числа считываются в массив.
  
Имя файла передается через параметры командной строки.  
Модульные тесты реализуются в отдельном проекте.  
При защите лабораторной работы необходимо продемонстрировать отчет утилиты Doctor Memory, 
свидетельствующий об отсутствии ошибок при работе с памятью.  

Варианты 
 5. Найти количество различных чисел в файле. 
*/

#include <stdio.h>
#include <stdlib.h>

#include "read_arr.h"
#include "print_arr.h"
#include "diff_numb.h"

// Программа читает до первого некорректного значения

int main(int argc, char** argv)
{
    if (argc == 2)
	{
	    FILE *f = NULL;
		int* bg = NULL;
		int* nd = NULL;
		int n = 0;
		
		int diff_num_cnt = 0;
		
		f = fopen(argv[1], "r");
		
		if (f)
		{
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
				
			fclose(f);
		}
		else
		    printf("Error! Could not open file [%s]", argv[1]);
	}
	else
		printf("HELP:\n  main.exe [name of .txt file]\n");
	
    return 0;
}