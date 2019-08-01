#ifndef ARRAY_MATRIX_H
#define ARRAY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

void print_array_matrix(FILE* f, int* arr, int r, int c);

int* read_array_matrix(FILE* f, int* r, int* c);

int* multiply_array_matrix(int* arr1, int r1, int c1, int* arr2, int r2, int c2, int* rr, int* rc);

#endif  // ARRAY_MATRIX_H