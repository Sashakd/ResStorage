// Задание 3-1(2)

#include <stdio.h>

#include "my_strspn.h"

#define MAX_LEN 80

/*
sadh236saj2
sdh2afgj3

sadh236saj2
-&3*

sd
d

wqrfef
whjq

+232esd232
sdsdjym2+
*/

int main(void)  // STRSPN РУЧНАЯ ПРОВЕРКА СО СТАНДАРТНОЙ ФУНКЦИЕЙ
{
	char string[MAX_LEN] = {'0'};
	char mask[MAX_LEN]   = {'0'};
	
	size_t res = 0;
	size_t cmp = 0;
	
	printf("get string: ");
	/*
	if (scanf("%s", string) != 1)
	{
		printf("\nError! Can\'t read string\n");
		return -1;
	}
	*/
	gets(string);
	printf("\nget mask:   ");
	/*
	if (scanf("%s", mask) != 1)
	{
		printf("\nError! Can\'t read mask\n");
		return -2;
	}
	*/
	gets(mask);
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	        1   5    10   15   20\n", string);
	printf("	        ||||||||||    |    |\n", string);
	printf("	string: %s\n", string);
	printf("	mask:   %s\n", mask);
	
	printf("\n");
	
	res = my_strspn(string, mask);
	cmp = strspn(string, mask);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	return 0;
}