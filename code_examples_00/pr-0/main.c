#include <stdio.h>
#include <math.h>

#include "fib.h"
#include "read.h"

//#define EPS 0.0000001
//#define MAXLEN 80

/*
Допущения:
1) Гарантируется корректная работа для до 80 чисел в строке;
2) Гарантируется корректная работа при отсутствии некорректных значений;
3) В конце строки нет пробелов;
*/

int main(int argc, char** argv)
{
    if (argc == 2)
    {
	    FILE *f = NULL;
        int a[MAXLEN];
	    int n = 7;
		int quest = 1;
	
	    f = fopen(argv[1], "r");  // Открываем файл f
		
		printf("File: [%s]\n", argv[1]);
		printf("\n");
		
		if (f)
		{
		    while (quest != 2)  // пока не конец файла
			{
			    quest = readstrarr(f, a, &n);  // Считываем массив из текущей строки
				
	            if(quest)
				{
			        if (isfibinarr(a, n))  // Проверка массива на нахождение в нём числа Фибоначчи
			            iprintarr(a, n);   // Печать массива
				}
				else
				{
				    printf("Error! Found a wrong value\n");  // Ошибка
					fclose(f);
					return -1;
				}
			}
            
			fclose(f);
		}
		else
		    printf("Error! Could not open file [%s]\n", argv[1]);  // Ошибка
	}
	else
	    printf("Help:\n    main.exe [name of .txt file]\n");       // Помощь
	
    return 0;
}
