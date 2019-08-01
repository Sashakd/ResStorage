#include "my_strndup.h"

size_t my_strlen (const char *str)
{
	size_t cnt = 0;

	while (*(str + cnt) != '\0')
		cnt++;
		
	return cnt;
}

char* my_strndup(const char *str, size_t n)
{
	size_t len;
	
	len = my_strlen(str);
	
	if (len > 0)
	{
		char* buff;
		size_t b_len;
		
		if (len < n)
			b_len = len;
		else
			b_len = n;
		
		buff = malloc(sizeof(char)*(b_len+1));
		
		if (buff)
		{
			for (int i = 0; i < b_len; i++)
				*(buff + i) = *(str + i);
				
			*(buff + b_len) = '\0';
		}
		else
			return NULL;
			
		return buff;
	}
	else
		return NULL;
}