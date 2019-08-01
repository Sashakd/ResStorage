/*
Метод выделения памяти: 2) Матрица как массив указателей;

Реализуемая операция:   8) Вычисление определителя методом Гаусса.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define eps 0.005

double** matr_init(const int w, const int h)
{
	double** matr = malloc(sizeof(double*)*h);
	
	if (!matr)
		return NULL;
	
	for (int i = 0; i < h; i++)
	{
		*(matr + i) = calloc(w, sizeof(double));
		if (!(*(matr + i)))
			return NULL;
	}
		
	return matr;
}

void matr_free(double** matr, const int h)
{
	for (int i = 0; i < h; i++)
		free(*(matr + i));
		
	free(matr);
}

double** read_matr_fr_file(FILE* f, int* row, int* col)  // -- Что-то не считывается --
{
	int r = 0;
	int c = 0;
	
	if (fscanf(f, "w: %d h: %d", &c, &r) == 2)
	{
		if ((r <= 0) || (c <= 0))
			return NULL;
		
		double** M = matr_init(c, r);
		
		if (M)
		{
			double tmp = 0.0;
			*row = r;
			*col = c;   // До этого момента отлично
			
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
				{
					if (fscanf(f, "%lf", &tmp) == 1) // <=====---------
					{
						*(*(M + i) + j) = tmp;  // <=====--------- *(*(M + i) + j)
						printf("[tmp = %lf]\n", tmp);
					}
					else
					{
						matr_free(M, c);
						return NULL;
					}
				}
			
			return M;
		}
		else
			return NULL;
	}
	else
		return NULL;
}

void print_matr(FILE* f, double** M, const int row, const int col)
{
	fprintf(f, "w: %d h: %d\n", col, row);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			fprintf(f, " %4.2lf", *(*(M + i) + j));
		fprintf(f, "\n");
	}
}

double** summ_matr(double** A, const int ra, const int ca, double** B, const int rb, const int cb, int* row, int* col)
{
	if ((A) && (B) && (ra > 0) && (ca > 0) && (rb > 0) && (cb > 0))
	{
		int max_r;
		int max_c;
		//int min_r;
		//int min_с;
		
		if (ra > rb)
		{
			max_r = ra;
			//min_r = rb;
		}
		else
		{
			max_r = rb;
			//min_r = ra;
		}
		
		if (ca > cb)
		{
			max_c = ca;
			//min_c = cb;
		}
		else
		{
			max_c = cb;
			//min_c = ca;
		}

		double** M = matr_init(max_c, max_r);
		
		if (M)
		{
			for (int i = 0; i < ra; i++)
				for (int j = 0; j < ca; j++)
					*(*(M + i) + j) += *(*(A + i) + j);
			
			for (int i = 0; i < rb; i++)
				for (int j = 0; j < cb; j++)
					*(*(M + i) + j) += *(*(A + i) + j);
			
			return M;
		}
		else
			return NULL;
	}
	else
		return NULL;
}

double** mult_matr(double** A, const int ra, const int ca, double** B, const int rb, const int cb, int* row, int* col)  // За основу взята предыдущая функция
{
	if ((A) && (B) && (ra > 0) && (ca > 0) && (rb > 0) && (cb > 0))
	{
		if (ca == rb)  // в этом случае умножение ввыполнимо
		{
			// Размерность результирующей матрицы
			int new_r = ra;
			int new_c = cb;
		
			double** M = matr_init(new_c, new_r);
			
			if (M)
			{
				// Перемножаем
				for (int i = 0; i < new_r; i++)  // Текущий столбец   
					for (int j = 0; j < new_c; j++) // Текущий элемент
						for (int k = 0; k < ca; k++)  // Текущая сумма
							*(*(M + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j)); // <==== проверить
				
				return M;
			}
			else
				return NULL;
		}
		else
			return NULL;
	}
	else
		return NULL;
}

void swap (double** a, double** b)
{
	double* tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

double det_calc(double** M, const int r, const int c, int* st) // <==============
{	
	if (r == c)
	{
		double det = 1;
		//int i,j,k;
		
		//прямой ход     /// <==================
		for (int i=0; i < r; i++) 
		{
			int k = i;
			
			for (int j=i+1; j < r; j++)
				if (abs (*(*(M + j) + i)) > abs (*(*(M + k) + i))) // *(*(M + i) + j)
					k = j;
			
			if (abs (*(*(M + k) +  i)) < eps) 
			{
				det = 0;
				break;
			}
			
			swap (&(*(M + i)), &(*(M + k))); // <==== memmove-ом или через &
			
			if (i != k)
				det = -det;
			
			det *= *(*(M + i) + i);
			
			for (int j=i+1; j < r; j++) // <===
				*(*(M + i) + j) /= *(*(M + i) + i); // <========== с этим осторожней (если i i не ноль)
			
			for (int j=0; j < r; ++j)
				if (j != i && abs (*(*(M + j) + i)) > eps)
					for (int k=i+1; k < r; ++k)
						*(*(M + j) + k) -= (*(*(M + i) + k)) * (*(*(M + j) + i));
		}
		
		*st = 1;
		return det;
	}
	else
		*st = 0;
	
	return 0;
}

int main(int argc, char** argv)
{
	double** M = NULL;
	double** A = NULL;
	double** B = NULL;
	FILE* inp_A_f = NULL;
	FILE* inp_B_f = NULL;
	FILE* out_f = NULL;
	
	if ((argc > 2) && (argc < 6))
	{
		if ((argc == 3) || (argc == 5))
		{
			if (argc == 3)
			{
				if (strcmp(argv[2], "-d") != 0)
				{
					printf("ERROR! Determination applies only to one matrix\n");
					return -1;
				}
				else
				{
					inp_A_f = fopen(argv[1], "r");
					inp_B_f = NULL;
					
					if (inp_A_f)
					{
						int r = 0;
						int c = 0;
						int st = 1;
						double det = 0;
						
						M = read_matr_fr_file(inp_A_f, &r, &c);
						
						if (M)                 // ДЕТЕРМИНАЦИЯ
						{
							printf("\nMATRIX:\n");
							print_matr(stdout, M, r, c);
							det = det_calc(M, r, c, &st);
							if (st)
								printf("\nDet = %4.2lf\n", det);
							else
							{
								printf("ERROR! Could not calculate determinant\n");
								matr_free(M, r);
								fclose(inp_A_f);
								return -5;
							}
						}
						else
						{
							printf("ERROR! Could not read matrix from file [%s]\n", argv[1]);
							matr_free(M, r);
							fclose(inp_A_f);
							return -4;
						}
						
						matr_free(M, r);
						
						fclose(inp_A_f);
					}
					else
					{
						printf("ERROR! Could not open file [%s]\n", argv[1]);
						return -3;
					}
				}
			}
			else
				if (argc == 5)
				{
					if ((strcmp(argv[4], "-s") != 0) && (strcmp(argv[4], "-m") != 0))
					{
						printf("ERROR! Operation needs one more matrix\n");
						return -2;
					}
					else
					{
						inp_A_f = fopen(argv[1], "r");
						
						if (inp_A_f)
						{
							inp_B_f = fopen(argv[2], "r");
							
							int rA = 0;
							int cA = 0;
							int rB = 0;
							int cB = 0;
							
							if (inp_B_f)
							{
								A = read_matr_fr_file(inp_A_f, &rA, &cA);
								
								if (A)
								{
									B = read_matr_fr_file(inp_B_f, &rB, &cB);
									
									if (B)  //////
									{
										int rM = 0;
										int cM = 0;
										
										out_f = fopen(argv[3], "w");
										
										if (strcmp(argv[4], "-s") == 0)            //  СЛОЖЕНИЕ
										{
											print_matr(stdout, A, rA, cA);
											printf("\n	+\n");
											print_matr(stdout, B, rB, cB);
											printf("\n	=\n");
											M = summ_matr(A, rA, cA, B, rB, cB, &rM, &cM);
										}
										else                                       // УМНОЖЕНИЕ
										{
											print_matr(stdout, A, rA, cA);
											printf("\n	*\n");
											print_matr(stdout, B, rB, cB);
											printf("\n	=\n");
											M = mult_matr(A, rA, cA, B, rB, cB, &rM, &cM);
										}
										
										print_matr(stdout, M, rM, cM);
										
										// В случае если не удастся создать файл для записи, то
										// результат возвращается в поток
										if (M)
										{
											if (out_f)
												print_matr(out_f, M, rM, cM);
											else
												printf("WARNING! Could not create file [%s]\n\n", argv[3]);
											
											matr_free(M, rM);
										}
										else
											printf("WARNING! Could not calculate result\n\n");
										
										fclose(inp_A_f);
										fclose(inp_B_f);
										matr_free(A, rA);
										matr_free(B, rB);
									}
									else
									{
										fclose(inp_A_f);
										fclose(inp_B_f);
										matr_free(A, rA);
										
										return -9;
									}
								}
								else
								{
									fclose(inp_A_f);
									fclose(inp_B_f);
									return -8;
								}
							}
							else
							{
								fclose(inp_A_f);
								return -7;
							}
						}
						else
							return -6;
					}
				}
		}
		else
		{
			printf("WARNING! Wrong argument count\n\n");
			printf("	-- HELP: --\n	Det.exe [matrix_A.txt] [matrix_B.txt] [result_matrix.txt] -operation\n");
			printf("			operations:\n				s -- summary\n"
			"				m -- multiply\n				d -- determination");
		}
	}
	else
	{
		printf("	-- HELP: --\n	Det.exe [matrix_A.txt] [matrix_B.txt] [result_matrix.txt] -operation\n");
		printf("			operations:\n				s -- summary\n"
		"				m -- multiply\n				d -- determination");
	}
	
	return 1;
}