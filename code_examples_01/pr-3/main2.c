// Задание 3-1(7)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_strndup.h" // Тест strndup

int main(void)  // STRNDUP РУЧНАЯ ПРОВЕРКА (СТАНДАРТНОЙ ФУНКЦИИ НЕТ)
{
	char str[80];
	char *cpy_my;
	int n;
	//char *cpy;
	
	printf("get string:  ");
	gets(str);
	printf("get max len: ");
	if (scanf("%d", &n) != 1)
		return -1;
	
	cpy_my = my_strndup(str, n);
	//cpy    =    strndup(str, n); // <-- такой функции нет в string.h
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str);
	printf("copy (my_strndup):   %s\n", cpy_my);
	//printf("copy    (strndup):   %s\n", cpy);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	free(cpy_my);

	return 0;
}