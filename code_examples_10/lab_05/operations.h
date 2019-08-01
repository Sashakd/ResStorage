#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdlib.h>
#include <stdio.h>

struct elm
{
    int numb;
    struct elm *p;
};

/**
 * @brief matrix_mult Функция произведения матриц
 * @param a_matrix Первый множитель
 * @param b_matrix Второй множитель
 * @param c_matrix Произведение
 * @param a_rows Количество строк первого множителя
 * @param ab Количество столбцов второго множителя и количество строк первого множителя
 * @param b_cols Количество столбцов второго множителя
 * @return Код ошибки
 */
int matrix_mult(double **a_matrix, double **b_matrix, double **c_matrix, int a_rows, int ab, int b_cols);

void push_end(struct elm **head, int numb);

void matrix_spec(double **a_matrix, double *A, int *JA, struct elm **IA, int rows, int cols);

void spec_mult(double *A1, int *JA1, struct elm *IA1, double *A2, int *JA2, struct elm *IA2, double *A_RES, int *JA_RES, struct elm **IA_RES);

#endif // OPERATIONS_H
