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

#include <stdio.h>
#include <string.h>

#include "my_strspn.h"

int main(void)  // АВТО-ТЕСТ STRSPN СО СРАВНЕНИЕМ СО СТАНДАРТНОЙ ФУНКЦИЕЙ
{
	char str1[] = "sd";
	char msk1[] = "d";
	
	size_t res = 0;
	size_t cmp = 0;	
	
	printf("my_strspn test:\n");
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str1);
	printf("	mask:   %s\n", msk1);
	
	printf("\n");
	
	res = my_strspn(str1, msk1);
	cmp =    strspn(str1, msk1);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str2[] = "ds";
	char msk2[] = "d";
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str2);
	printf("	mask:   %s\n", msk2);
	
	printf("\n");
	
	res = my_strspn(str2, msk2);
	cmp =    strspn(str2, msk2);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str3[] = "s";
	char msk3[] = "ds";
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str3);
	printf("	mask:   %s\n", msk3);
	
	printf("\n");
	
	res = my_strspn(str3, msk3);
	cmp =    strspn(str3, msk3);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str4[] = "wqrfef";
	char msk4[] = "whjq";
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str4);
	printf("	mask:   %s\n", msk4);
	
	printf("\n");
	
	res = my_strspn(str4, msk4);
	cmp =    strspn(str4, msk4);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str5[] = "sadh236saj2";
	char msk5[] = "sdh2afgj3";
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str5);
	printf("	mask:   %s\n", msk5);
	
	printf("\n");
	
	res = my_strspn(str5, msk5);
	cmp =    strspn(str5, msk5);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str6[] = "";
	char msk6[] = "d";
	
	printf("my_strspn test:\n");
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str6);
	printf("	mask:   %s\n", msk6);
	
	printf("\n");
	
	res = my_strspn(str1, msk6);
	cmp =    strspn(str1, msk6);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	char str7[] = "sd";
	char msk7[] = "";
	
	printf("my_strspn test:\n");
	
	printf("\n-----------------------------------------------\n\n");
	
	printf("	string: %s\n", str7);
	printf("	mask:   %s\n", msk7);
	
	printf("\n");
	
	res = my_strspn(str1, msk7);
	cmp =    strspn(str1, msk7);
	
	printf("	result (my_strspn) = %d\n", res);
	printf("	result (strspn)    = %d\n", cmp);
	
	printf("\n-----------------------------------------------\n\n");
	
	return 0;
}