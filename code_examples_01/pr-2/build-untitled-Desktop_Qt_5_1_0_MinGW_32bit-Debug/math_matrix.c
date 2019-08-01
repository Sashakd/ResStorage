#include "math_matrix.h"

double** summ_matr(double** A, const int ra, const int ca, double** B, const int rb, const int cb, int* row, int* col)
{
    if ((A) && (B) && (ra > 0) && (ca > 0) && (rb > 0) && (cb > 0) && (ra == rb) && (ca == cb))
    {
        double** M = matr_init(ca, ra);

        if (M)
        {
            for (int i = 0; i < ra; i++)
                for (int j = 0; j < ca; j++)
                    *(*(M + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);

            *row = ra;
            *col = ca;

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
                    {
                        *(*(M + i) + j) = 0;
                        for (int k = 0; k < ca; k++)  // Текущая сумма
                            *(*(M + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j)); // <==== проверить
                    }

                *row = new_r;
                *col = new_c;

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

char determinant_gauss(double **M, int n, double *det)
{
    double a;
    double max;
    int imax;
    int p = 0;

    *det = 1;

    // Если матрица указывает на NULL
    if (M == NULL)
        return 0;

    // Если размер матрицы неверный, то вернем 2
    if (n < 1)
        return 0;

    // Вычисление определителя
    for (int i = 0; i < n; i++)
    {
        // Ищем максимальный элемент в столбце и выбираем его главным
        max = fabs(*(*(M + i) + i));  // *(*(M + i) + i)
        imax = i;
        for (int k = i + 1; k < n; k++)
            if (fabs(*(*(M + k) + i)) > max)
            {
                max = fabs(*(*(M + k) + i));
                imax = k;
            }

        // Меняем местами строки матрицы imax, i
        if (imax != i)
        {
            swap ((M + i), (M + imax));

            p++;
        }

        for (int j = i+1; j < n; j++)
        {
            // Если эл-т на гл. диагонали равен нулю, то определитель равен нулю
            if (fabs(*(*(M + i) + i)) < eps)
            {
                *det = 0;
                return 0;
            }

            a = *(*(M + j) + i) / *(*(M + i) + i);
            for (int k = i; k < n; k++)
                *(*(M + j) + k) -= *(*(M + i) + k)*a;
        }

        *det *= *(*(M + i) + i);
    }
    *det *= (p % 2 == 0) ? 1 : -1;
    if (fabs(*det) < eps)
        *det = 0;

    return 1;
}
