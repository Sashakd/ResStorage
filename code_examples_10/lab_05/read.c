#include "read.h"

/**
 * @brief free_matrix_rows Процедура, освобождающая память из под матрицы
 * @param data Указатель на матрицу
 * @param n Количество строк матрицы
 */
void free_matrix_rows(double **data, int n)
{
    if (data != NULL)
    {
        for (int i = 0; i < n; i++)
            free(data[i]);
        free(data);
        data = NULL;
    }
}

/**
 * @brief allocate_matrix_rows Функция выделения памяти под матрицу
 * @param n Количество строк матрицы
 * @param m Количество столбцов матрицы
 * @return Указатель на матрицу
 */
double** allocate_matrix_rows(int n, int m)
{
    double **data = calloc(n, sizeof(double*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(double));
        if (!data[i])
        {
            free_matrix_rows(data, n);

            return NULL;
        }
    }
    return data;
}


/**
 * @brief matrix_read Функция чтения матрицы из текстового файла
 * @param f Текстовый файл
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 * @return Код ошибки
 */
int matrix_read(FILE *f, double **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (fscanf(f, "%lf", &matrix[i][j]) != 1)
                return -1;
    return 0;
}

/**
 * @brief matrix_print Процедура вывода матрицы на экран
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 */
void matrix_print(double **matrix, int rows, int cols)
{
    int i = 0;
    int j = 0;

    if (rows <= 0 || cols <= 0)
        printf("\nEmpty matrix.\n");
    else
        printf("\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%0.2f ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief matrix_write Процедура записи матрицы в файл
 * @param f Файл
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 */
void matrix_write(FILE *f, double **matrix, int rows, int cols)
{
    fprintf(f, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] < 0)
                fprintf(f, "%0.6f ", matrix[i][j]);
            else
                fprintf(f, " %0.6f ", matrix[i][j]);
        fprintf(f, "\n");
    }
}
