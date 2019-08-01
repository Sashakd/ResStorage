#include <stdio.h>
#include "read.h"

int main()
{
    char str0[] = "best friend ever";
	int n = 1;

	char* str1 = get_word(str0, &n);
	char* str2 = get_word(str0, &n);
	char* str3 = get_word(str0, &n);
	
	printf("[%s]\n", str0);
	
	int len = strlen(str0);
	
	while (n < len)
    {
	
	}	
	
	return 0;
}