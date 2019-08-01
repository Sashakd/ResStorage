#ifndef BASIC_MATRIX_H
#define BASIC_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

double** matr_init(const int w, const int h);

double** read_matr_fr_file(FILE* f, int* row, int* col);

void print_matr(FILE* f, double** M, const int row, const int col);

void matr_free(double** matr, const int h);

#endif // BASIC_MATRIX_H
