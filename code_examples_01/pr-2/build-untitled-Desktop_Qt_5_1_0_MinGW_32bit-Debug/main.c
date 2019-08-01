/*
Метод выделения памяти: 2) Матрица как массив указателей;

Реализуемая операция:   8) Вычисление определителя методом Гаусса.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define eps 0.0001

#include "basic_matrix.h"
#include "math_matrix.h"

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
                        double det = 0;
						
						M = read_matr_fr_file(inp_A_f, &r, &c);
						
						if (M)                 // ДЕТЕРМИНАЦИЯ
						{
							printf("\nMATRIX:\n");
							print_matr(stdout, M, r, c);

                            // print_matr(stdout, M, r, c);
                            if (r == c)
                            {
                                if (determinant_gauss(M, r, &det))
                                {
                                    printf("\n");
                                    printf("\nDet = %lf\n", det);
                                }
                                else
                                {
                                    printf("ERROR! Could not calculate determinant\n");
                                    matr_free(M, r);
                                    fclose(inp_A_f);
                                    return -5;
                                }
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
									
                                    if (B)
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
                                            {
												print_matr(out_f, M, rM, cM);
                                                fclose(out_f);
                                            }
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

/*
            double tmp = 0.0;

            tmp = *(*M + i);
            *(*M + i) = *(*M + k);

            *(*M + k) = tmp;
*/
            //swap (&(*(M + i)), &(*(M + k)));
            // а может надо свапать не сами строки
