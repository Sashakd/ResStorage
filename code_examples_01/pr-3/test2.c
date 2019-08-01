#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_strndup.h"

int main(void)    // АВТО-ТЕСТ STRNDUP (СТАНДАРТНОЙ ФУНКЦИИ НЕТ)
{
	char str1[] = "";
	char *cpy1;
	int n1 = 10;
	
	cpy1 = my_strndup(str1, n1);
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str1);
	printf("copy (my_strndup):   %s\n", cpy1);
	printf("max_n = %d\n", n1);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	char str2[] = "a";
	char *cpy2;
	int n2 = 10;
	
	cpy2 = my_strndup(str2, n2);
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str2);
	printf("copy (my_strndup):   %s\n", cpy2);
	printf("max_n = %d\n", n2);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	char str3[] = "abcdkjhg";
	char *cpy3;
	int n3 = 10;
	
	cpy3 = my_strndup(str3, n3);
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str3);
	printf("copy (my_strndup):   %s\n", cpy3);
	printf("max_n = %d\n", n3);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	char str4[] = "zxcxvbvnc";
	char *cpy4;
	int n4 = 5;
	
	cpy4 = my_strndup(str4, n4);
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str4);
	printf("copy (my_strndup):   %s\n", cpy4);
	printf("max_n = %d\n", n4);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	char str5[] = "qwewr3546";
	char *cpy5;
	int n5 = 0;
	
	cpy5 = my_strndup(str5, n5);
	
	printf("\n-------------------------------------------------\n\n");
	printf("string:              %s\n", str5);
	printf("copy (my_strndup):   %s\n", cpy5);
	printf("max_n = %d\n", n5);
	printf("                     ||||||||||    |    |\n");
	printf("                     1   5    10   15   20\n");
	
	free(cpy1);
	free(cpy2);
	free(cpy3);
	free(cpy4);
	free(cpy5);

	return 0;
}