#include "read.h"

int get_word_len(char* str)
{
    int len = 0;
	
	while((*(str+len) != ' ') && (*(str+len) != '\0'))
        len++; 
	
    return len;
}

char* get_word(char* str, int* n) 
{
    char *buff;   
    int word_len;
	
	str += *n - 1; 
	
	word_len = get_word_len(str);
	
	if (word_len)
	{
	    buff = malloc(sizeof(char)*(word_len + 1));
		
		if (buff)
		{
		    strncpy(buff, str, word_len);
	        *(buff + word_len) = '\0';
            *n += word_len + 1;		    
		}
		else
		    return NULL;
	}
	else
	{
	    (*n)++;
		return NULL;
	}
	
	return buff;
}