#include "array_matrix.h"

void print_array_matrix(FILE* f, int* arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			fprintf(f, "%3d ", *(arr + i*c + j));
		fprintf(f, "\n");
	}
}

int* read_array_matrix(FILE* f, int* r, int* c)
{
	if (fscanf(f, "r: %d c: %d", r, c) == 2)
	{	
		int* buff = calloc((*r) * (*c), sizeof(int));
		
		if (buff)
		{
			int tmp = 0;
			
			for (int i = 0; i < *r; i++)
			{
				for (int j = 0; j < *c; j++)
				{
					if (fscanf(f, "%d", &tmp) == 1)
						*(buff + i*(*c) + j) = tmp;
					else
					{
						free(buff);
						return NULL;
					}
				}
			}
			
			return buff;
		}
		else
			return NULL;
	}
	else
		return NULL;
}

int* multiply_array_matrix(int* arr1, int r1, int c1, int* arr2, int r2, int c2, int* rr, int* rc)
{
	if ((r1 > 0) && (c1 > 0) && (r2 > 0) && (c2 > 0))
	{
		if (c1 == r2)
		{
			int rows = r1;
			int cols = c2;
			
			int* buff = calloc(rows * cols, sizeof(int));
			
			
			
			if (buff)
			{
				// Определяем количество строк и столбцов результирующей матрицы
				*rr = rows;
				*rc = cols;
				
				// Перемножаем
				for (int i = 0; i < rows; i++)  // Текущий столбец   
					for (int j = 0; j < cols; j++)  // Текущий элемент
						for (int k = 0; k < c1; k++)  // Текущая сумма
							*(buff + i * cols + j) += (*(arr1 + i * c1 + k)) * (*(arr2 + k * c2 + j));
				
				return buff;
			}
			else
			{
				free(buff);
				return NULL;
			}
		}
		else
			return NULL;
	}
	else
		return NULL;
}