#include "string_my.h"

int strlen_my(const char* str) // Работает безупречно
{
	int cnt = 0;
	
	while (*str++ != '\0')
		cnt++;
	
	return cnt;
}

char* strcpy_my_why(const char* tmp) // Работает безупречно
{
	int len = strlen_my(tmp) + 1;
	
	char* dest = malloc(sizeof(char)*len);
	
	if (dest)
	{
		for (int i = 0; i < len; i++)
			*(dest+i) = *(tmp+i);
		
		*(dest+len) = '\0';
		
		return dest;
	}
	else
		return NULL;
}

char* strncpy_my_why(const char* tmp, int mlen) // Всё в порядке
{
	int len;
	
	if (mlen < strlen_my(tmp))
		len = mlen;  //
	else
		len = strlen_my(tmp) + 1;
	
	char* dest = malloc(sizeof(char)*len);
	
	if ((dest) && (mlen >= 0))
	{
		for (int i = 0; i < len; i++)
			*(dest+i) = *(tmp+i);
			
		*(dest+len) = '\0';
		
		return dest;
	}
	else
		return NULL;
}

int or_strcmp(const char* a, const char* b) // Работает хорошо
{
	int len_a = strlen_my(a);
	int len_b = strlen_my(b);
	
	if (len_a == len_b)
	{
		for (int i = 0; i < len_a; i++)
			if (*(a+i) != *(b+i))
				return 0;
	}
	else
		return 0;
	
	return 1;
}

int str_in_pos(const char* str, const char* mask) // <----- Верно
{
	int len_str  = strlen_my(str);
	int len_mask = strlen_my(mask);
	
	for (int i = 0; i < len_str; i++)
		for (int j = 0; j < len_mask; j++)
			if (*(str+i) == *(mask+j))
				return i+1;
	
	return 0;
}

int char_in_str(const char* mask, char ch)
{
	int len_mask = strlen_my(mask);
	
	for (int i = 0; i < len_mask; i++)
		if (ch == *(mask+i))
			return 1;
			
	return 0;
}

// возвращает указатель на начало следующего слова, если
// строка начиналась с разделителя, то возращает указатель
// на следующий разделитель
// записывает слово в word
/*
char* get_word_from_str_bg(char* pnt, char** word, const char* mask)  // Это вообще что-то с чем-то
{
	// просто сдвинем указатель вперёд
	if (pnt)
	{
		if (!char_in_str(mask, *pnt))
		{
			int in_pos = str_in_pos(pnt, mask);
			
			if (in_pos != 0) // до позиции разделителя
			{
				printf("\n--[%s]-- [in_pos: %d]\n", strncpy_my_why(pnt, in_pos-1), in_pos-1);
				*word = strncpy_my_why(pnt, in_pos-1);
				
				pnt += in_pos;
			}
			else // до конца строки // Хмм...
			{
				//printf("\n--[%s]--\n", strcpy_my_why(pnt));
				// *word = strcpy_my_why(pnt); // <======================= ЧТО-ТО ЗДЕСЬ НЕ ОЧЕНЬ
				*word = strncpy_my_why(pnt, strlen_my(pnt)); // <========
				pnt += strlen_my(pnt); // <==============================
				//printf("-");
				//pnt = NULL;
			}
			
			return pnt;
		}
		else
		{
			*word = NULL;
			pnt++;
			return pnt; 
		}
	}
	else
	{
		*word = NULL;
		return NULL;
	}
}
*/
char* get_word_from_str_bg(char* pnt, char** word, const char* mask) // <--------====
{	
	if (pnt)
	{
		if (!char_in_str(mask, *pnt))
		{
			int in_pos = str_in_pos(pnt, mask);
			
			if (in_pos != 0) // до позиции разделителя
			{
				printf("\n--[%s]-- [in_pos: %d]\n", strncpy_my_why(pnt, in_pos-1), in_pos-1);
				*word = strncpy_my_why(pnt, in_pos-1);
				
				pnt += in_pos;
			}
			else // до конца строки // Хмм...
			{
				*word = strcpy_my_why(pnt);
				pnt = NULL;
			}
			
			return pnt;
		}
		else
		{
			*word = NULL;
			pnt++;
			return pnt;
		}
	}
	else
	{
		*word = NULL;
		return NULL;
	}
}