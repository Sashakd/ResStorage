#ifndef STRUCT_MATRIX_H
#define STRUCT_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

struct IA
{
	int NJA;
	struct IA* next;
};

struct matrix
{
	int* A;
	int* JA;
	struct IA* Nk;
};

int get_arr_zero_len(const int* arr);

int* put_in_arr(int* arr, int tmp);

int get_max_in_arr(int* arr);

int get_max_in_arr_bg_nd(const int* bg, const int* nd);

void print_struct_matrix(FILE* f, struct matrix* matr);

void debug_print_struct_matrix(FILE* f, struct matrix* matr);

struct matrix* read_struct_matrix(FILE* f, int* row);

int get_row_end(struct matrix* A);

int find_c_in_row(int* A, int* JA, int bg, int nd, int col);

struct matrix* multiply_struct_vec_on_matrix(struct matrix* A, struct matrix* B);

int calc_memory_struct_matrix(struct matrix* matr);

void free_struct_matrix(struct matrix* matr);

void get_rc_cnt(struct matrix* M, int* row, int* col);

#endif  // STRUCT_MATRIX_H
