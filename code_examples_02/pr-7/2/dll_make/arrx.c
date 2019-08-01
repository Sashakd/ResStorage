#include "arrx.h"

// Функция Эйлера
int phi (int n) 
{
	int result = n;
	
	for (int i=2; i*i <= n; ++i)
		if (n % i == 0) 
		{
			while (n % i == 0)
				n /= i;
			
			result -= result / i;
		}
	
	if (n > 1)
		result -= result / n;
	return result;
}

// Проверка является ли число простым
int is_simple(int n)
{
	if (n > 1)	
		return (phi(n) == (n - 1));
	else
		return 0;
}

// Запись в массив n простых чисел
void init_arr_simple(int* arr, int n)
{
	int stored = 0;
	int passed = 1;
	
	while (stored <= n)
	{
		passed++;
		if (is_simple(passed))
		{
			*(arr + stored) = passed;
			stored++;
		}
	}
}

// Вставка одной строки на определённую позицию внутри первой
int insert(char *str, char* sub_str, int start, char *str_res, int res_len)
{
	int len_str = strlen(str);
	int len_sub = strlen(sub_str);
	int len_rln = len_str + len_sub + 1;
	
	if ((len_rln <= res_len) && (start <= len_str+1) && (start > 0))
	{
		memmove(str_res, str, start-1);
		memmove(str_res + start-1, sub_str, len_sub);
		memmove(str_res + start + len_sub-1, str + start-1, len_str - start+1);
		memmove(str_res + len_str + len_sub, "\0", 1);
	}
	else
		return 0;
	
	return len_rln;
}