#ifndef __ARR__LIB__H__
#define __ARR__LIB__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ввод
int get_num_cnt(FILE* f);
int* read_i_arr(FILE* f, int n);

// Вывод
void print_i_arr(int* bg, int* nd);

// Обработка
int num_if_in_cnt(int* bg, int* nd, int num);
int get_diff_num_cnt(int* bg, int* nd);

#endif  //  __ARR__LIB__H__