#include "read.h"

int readstrarr(FILE *f, int* a, int *n) // <--- Пробел в конце строки создаёт проблемы
{
    int ch, i = 0;
	
	*n = 0;
	
	while(((ch = fgetc(f)) != '\n')&&(ch != EOF)&&(i < MAXLEN))
	{
	    ungetc(ch,f);
		
		if (fscanf(f, "%d", &a[i]) != 1)
		    return 0; // Ошибка
		
		i++;
	}
	
	*n = i;
	
	if (ch == EOF)
	    return 2;     // EOF

    return 1;         // Считалось 
}

// Печатает массив arr, состоящий из n элеменов
void iprintarr(int* arr, int n)
{
    for (int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
	
	printf("\n");
}