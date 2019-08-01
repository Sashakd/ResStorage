#include "m_insert_sort.h"

int compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;	// return *(int*)p - *(int*)q;
}

void modified_insertion_sort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *))
{
	// 1) Выбираем первый, для места вставки (в отсортированной части) исп. бинарный поиск
	if ((base != NULL) && (num > 0) && (size > 0))
	{
		char* key;         // Элемент вставки
		char* rem = base;  // Конвертирование указателя на void для применения адресной арифметики
		
		int i;
		
		key = malloc(size);
		
		if (!key)
			base = NULL;
		else
		{
			int first, last;
			
			for (int j = 1; j < num; j++)// 
			{ 
				i = j - 1;
				
				first = 0;
				last  = i;
				
				memmove(key, rem+j*size, size);
				
				// Бинарный поиск места вставки
				while (first < last)
				{
					size_t mid = first + (last - first) / 2;

					if ((*compare)(rem + mid*size, key) > 0)
						last = mid;
					else
						first = mid + 1;
				}
				
				// Вставка
				if (!(first == i) || !((*compare)(rem + first*size, key) < 0))
				{
					for (int k = j; k > first; k--)
						memmove(rem+k*size, rem+(k-1)*size, size);
				
					memmove(rem+first*size, key, size);
				}
			}
			
			free(key);
		}
	}
	else
		base = NULL;
}