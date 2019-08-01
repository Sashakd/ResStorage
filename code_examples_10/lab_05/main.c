#include <stdio.h>
#include <math.h>

#include "operations.h"
#include "read.h"

int main(int argc, char **argv)
{
    ///////////////// МАТРИЦЫ И РАЗМЕРЫ ДЛЯ ОБЫЧНОГО УМНОЖЕНИЯ
    FILE *f;
    double **a_matrix = NULL;
    double **b_matrix = NULL;
    double **c_matrix = NULL;
    int a_rows = 1;
    int a_cols = 1;
    int b_rows = 1;
    int b_cols = 1;
    int c_rows = 1;
    int c_cols = 1;
    int i = 0;
    //////////////// ПЕРЕМЕННЫЕ ДЛЯ ИЗМЕРЕНИЯ ВРЕМЕНИ
    unsigned long long time_before_1 = 0;
    unsigned long long time_after_1 = 0;
    unsigned long long time_before_2 = 0;
    unsigned long long time_after_2 = 0;
    unsigned long long usual_time = 0;
    unsigned long long spec_time = 0;
    /////////////// МАТРИЦА
    double *AM;
    int *JAM;
    struct elm *IAM = NULL;
    /////////////// ВЕКТОР
    double *AV;
    int *JAV;
    struct elm *IAV = NULL;
    /////////////// РЕЗУЛЬТАТ ПРОИЗВЕДЕНИЯ
    double *A_RES;
    int *JA_RES;
    struct elm *IA_RES = NULL;
    if (argc == 2)
    {
        f = fopen(argv[1], "r");
        fscanf(f, "%d%d", &a_rows, &a_cols);
        a_matrix = allocate_matrix_rows(a_rows, a_cols);
        matrix_read(f, a_matrix, a_rows, a_cols);
        fscanf(f, "%d%d", &b_rows, &b_cols);
        b_matrix = allocate_matrix_rows(b_rows, b_cols);
        matrix_read(f, b_matrix, b_rows, b_cols);
        c_rows = a_rows;
        c_cols = b_cols;
        c_matrix = allocate_matrix_rows(c_rows, c_cols);
        AM = calloc(a_cols * a_rows + 1, sizeof(double));
        JAM = calloc(a_cols * a_rows + 1, sizeof(int));
        AV = calloc(b_cols * b_rows + 1, sizeof(double));
        JAV = calloc(b_cols * b_rows + 1, sizeof(int));
        A_RES = calloc(b_cols * b_rows + 1, sizeof(double));
        JA_RES = calloc(b_cols * b_rows + 1, sizeof(int));
        ////////////////////////////////////////////// СПЕЦИАЛЬНОЕ ПРОИЗВЕДЕНИЕ
        matrix_spec(a_matrix, AM, JAM, &IAM, a_rows, a_cols); // перевод матрицы в специальный вид
        matrix_spec(b_matrix, AV, JAV, &IAV, b_rows, b_cols); // перевод вектора в специальный вид
        __asm__ __volatile__ ("rdtsc" : "=A" (time_before_1));
        spec_mult(AM, JAM, IAM, AV, JAV, IAV, A_RES, JA_RES, &IA_RES); // само умножение
        __asm__ __volatile__ ("rdtsc" : "=A" (time_after_1));
        spec_time = time_after_1 - time_before_1;
        /////////////////////////////////////////////// ОБЫЧНОЕ ПРОИЗВЕДЕНИЕ
        __asm__ __volatile__ ("rdtsc" : "=A" (time_before_2));
        matrix_mult(a_matrix, b_matrix, c_matrix, a_rows, a_cols, b_cols);
        __asm__ __volatile__ ("rdtsc" : "=A" (time_after_2));
        usual_time = time_after_2 - time_before_2;
        ////////////////////////////////////////////// ВЫВОД
        printf("Usual:\n\n");
        matrix_print(c_matrix, c_rows,c_cols);
        printf("Special:\n\n");
        printf("Result A: ");
        while (A_RES[i] != 0)
        {
            printf("%0.2f ", A_RES[i]);
            i++;
        }
        printf("\n");
        i = 0;
        printf("Result JA: ");
        while (JA_RES[i] != -1)
        {
            printf("%d ", JA_RES[i]);
            i++;
        }
        printf("\n");
        printf("Result IA: ");
        while(IA_RES != NULL)
        {
            printf("%d ", IA_RES->numb);
            IA_RES = IA_RES->p;
        }
        printf("\n\n");
        printf("Usual time = %llu\n", spec_time);
        printf("Special time = %llu\n", usual_time);
        fclose(f);
    }
    else
        printf("ERROR\n");
    printf("PRESS ENTER TO CONTINUE\n");
    getchar();
    return 0;
}
