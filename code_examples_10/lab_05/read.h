#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief matrix_read Функция чтения матрицы из текстового файла
 * @param f Текстовый файл
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 * @return Код ошибки
 */
int matrix_read(FILE *f, double **matrix, int rows, int cols);

/**
 * @brief matrix_print Процедура вывода матрицы на экран
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 */
void matrix_print(double **matrix, int rows, int cols);

/**
 * @brief matrix_write Процедура записи матрицы в файл
 * @param f Файл
 * @param matrix Матрица
 * @param rows Количество строк матрицы
 * @param cols Количество столбцов матрицы
 */
void matrix_write(FILE *f, double **matrix, int rows, int cols);

/**
 * @brief allocate_matrix_rows Функция выделения памяти под матрицу
 * @param n Количество строк матрицы
 * @param m Количество столбцов матрицы
 * @return Указатель на матрицу
 */
double** allocate_matrix_rows(int n, int m);

/**
 * @brief free_matrix_rows Процедура, освобождающая память из под матрицы
 * @param data Указатель на матрицу
 * @param n Количество строк матрицы
 */
void free_matrix_rows(double **data, int n);

#endif // READ_H
