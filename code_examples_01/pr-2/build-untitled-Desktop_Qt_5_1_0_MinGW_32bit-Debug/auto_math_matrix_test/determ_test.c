#include <stdio.h>
#include <stdlib.h>

#include "../basic_matrix.h"
#include "../math_matrix.h"

int main()
{
	double expected_for_A = 1.1;   // 1*1
	double expected_for_B = -4.86; // 2*2
	double expected_for_C = 2.42;  // 2*2
	double expected_for_D = 2.42;  // 2*2
	double expected_for_E = 24.23652;  // 4*4
	double expected_for_F = 283.786408;  // 4*4
	
	FILE *fA = NULL;
	
	double **M = NULL;
	int r = 0;
	int c = 0;
	double det = 0;
	
    fA = fopen("for_determ/A.txt", "r");
	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_A);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		printf("nope\n");
		matr_free(M, r);
		fclose(fA);
		return -2;
	}
	
    matr_free(M, r);
	fclose(fA);
	
    fA = fopen("for_determ/B.txt", "r");
	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_B);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		matr_free(M, r);
		fclose(fA);
		return -2;
	}
	
    matr_free(M, r);
	fclose(fA);
	
    fA = fopen("for_determ/C.txt", "r");
	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_C);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		matr_free(M, r);
		fclose(fA);
		return -2;
	}
	
    matr_free(M, r);
	fclose(fA);
	
    fA = fopen("for_determ/D.txt", "r");
	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_D);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		matr_free(M, r);
		fclose(fA);
		return -2;
	}
	
    matr_free(M, r);
	fclose(fA);
	
    fA = fopen("for_determ/E.txt", "r");
	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_E);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		matr_free(M, r);
		fclose(fA);
		return -2;
	}

    matr_free(M, r);
	fclose(fA);
	
    fA = fopen("for_determ/F.txt", "r");

	if (!fA)
		return 0;
	
	M = read_matr_fr_file(fA, &r, &c);
	
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
                printf("\n     (real) Det = %lf\n", det);
				printf("\n (expected) Det = %lf\n", expected_for_F);
            }
            else
            {
                matr_free(M, r);
                fclose(fA);
                return -1;
            }
        }
	}
	else
	{
		matr_free(M, r);
		fclose(fA);
		return -2;
	}
	
    matr_free(M, r);
	fclose(fA);
		
	return 1;
}
