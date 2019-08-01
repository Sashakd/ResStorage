#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "str_my.h"

int main()
{
	char buff[100] = {'\0'};
	int len = 0;
	
	len = my_snprintf(buff, 100, "asjgk asfkjg %s asdfkjg %o sadkg %s", "STR", 017234632, "BLAH");  // 46
	
	printf("[len = %d][%s]", len, buff);
	
	return 0;
}