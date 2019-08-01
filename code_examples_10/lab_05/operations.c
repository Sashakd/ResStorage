#include "operations.h"

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
int matrix_mult(double **a_matrix, double **b_matrix, double **c_matrix, int a_rows, int ab, int b_cols)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < a_rows; i++)
        for (j = 0; j < b_cols; j++)
        {
            c_matrix[i][j] = 0;
            for (int k = 0; k < ab; k++)
                c_matrix[i][j] += a_matrix[i][k] * b_matrix[k][j];
        }
    return 0;
}

void push_end(struct elm **head, int numb)
{
    struct elm *tmp;
    struct elm *tmp_1;

    tmp = malloc(sizeof(struct elm));
    tmp->numb = numb;
    tmp->p = NULL;
    if ((*head) == NULL)
        (*head) = tmp;
    else
    {
        (tmp_1) = (*head);
        while (tmp_1->p != NULL)
            tmp_1 = tmp_1->p;
        tmp_1->p = tmp;
    }
}

void matrix_spec(double **a_matrix, double *A, int *JA, struct elm **IA, int rows, int cols)
{
    int ai = 0;
    int jai = 0;
    int flag = 1;
    int tmp = 0;

    for (int i = 0; i < rows; i++)
    {
        tmp = ai;
        flag = 0;
        for (int j = 0; j < cols; j++)
            if (a_matrix[i][j] != 0)
            {
                A[ai] = a_matrix[i][j];
                JA[jai] = j;
                ai++;
                jai++;
                flag = 1;
            }
        if (flag)
            push_end(IA, tmp);
        else
            push_end(IA, -1);
    }
    JA[jai] = -1;
}

void spec_mult(double *A1, int *JA1, struct elm *IA1, double *A2, int *JA2, struct elm *IA2, double *A_RES, int *JA_RES, struct elm **IA_RES)
{
    int i = 0;
    int vec_str_ind = 0;
    int ind_res = 0;

    struct elm *tmp = IA2;

    while (IA1 != NULL)
    {
        if (IA1->numb != -1)
        {
            push_end(IA_RES, ind_res);
            i = IA1->numb;
            while (((i == IA1->numb) || (JA1[i] > JA1[i - 1])) /*&& A1[i] != 0*/)
            {
                tmp = IA2;
                vec_str_ind = 0;
                while (tmp != NULL)
                {
                    if (tmp->numb != -1)
                    {
                        if (JA1[i] < vec_str_ind)
                            tmp = NULL;
                        if (JA1[i] == vec_str_ind)
                        {
                            A_RES[ind_res] = A_RES[ind_res] + A1[i] * A2[tmp->numb];
                            JA_RES[ind_res] = 0;
                            tmp = NULL;
                        }
                        if (JA1[i] > vec_str_ind)
                        {
                            vec_str_ind++;
                            tmp = tmp->p;
                        }
                    }
                    else
                    {
                        tmp = tmp->p;
                        vec_str_ind++;
                    }
                }
                i++;
            }
            if (A_RES[ind_res] == 0)
                (*IA_RES)->numb = -1;
            else
                ind_res++;
        }
        else
        {
            push_end(IA_RES, -1);
        }
        IA1 = IA1->p;
    }
    JA_RES[ind_res] = -1;
}

void spec_mult_1(double *A1, int *JA1, struct elm *IA1, double *A2, int *JA2, struct elm *IA2, double *A_RES, int *JA_RES, struct elm **IA_RES)
{
    int i = 0;
    int vec_str_ind = 0;
    int ind_res = 0;

    struct elm *tmp = IA2;

    while (IA1 != NULL)
    {
        if (IA1->numb != -1)
        {
            push_end(IA_RES, ind_res);
            //i = IA1->numb;
            while (((i == IA1->numb) || (JA1[i] > JA1[i - 1])) && (A1[i] != 0))
            {
                tmp = IA2;
                vec_str_ind = 0;
                while (tmp != NULL)
                {
                    if (tmp->numb != -1)
                    {
                        if (JA1[i] == vec_str_ind)
                        {
                            A_RES[ind_res] = A_RES[ind_res] + A1[i] * A2[tmp->numb];
                            JA_RES[ind_res] = 0;
                            tmp = NULL;
                        }
                        if (JA1[i] > vec_str_ind)
                        {
                            vec_str_ind++;
                            tmp = tmp->p;
                        }
                        if (JA1[i] < vec_str_ind)
                            tmp = NULL;
                    }
                    else
                    {
                        tmp = tmp->p;
                        vec_str_ind++;
                    }
                }
                i++;
            }
            if (A_RES[ind_res] == 0)
                (*IA_RES)->numb = -1;
            else
                ind_res++;
        }
        else
            push_end(IA_RES, -1);
        IA1 = IA1->p;
    }
    JA_RES[ind_res] = -1;
}

