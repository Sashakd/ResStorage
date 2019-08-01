#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define eps 0.0001

#include "basic_matrix.h"

double** summ_matr(double** A, const int ra, const int ca, double** B, const int rb, const int cb, int* row, int* col);

double** mult_matr(double** A, const int ra, const int ca, double** B, const int rb, const int cb, int* row, int* col);

char determinant_gauss(double **M, int n, double *det);

#endif // MATH_MATRIX_H
