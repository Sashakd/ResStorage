#ifndef __ARR__LIB__H__
#define __ARR__LIB__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ввод
__declspec(dllexport) int __get_num_cnt(FILE* f);
__declspec(dllexport) int* __read_i_arr(FILE* f, int n);

// Вывод
__declspec(dllexport) void __print_i_arr(int* bg, int* nd);

// Обработка
__declspec(dllexport) int __num_if_in_cnt(int* bg, int* nd, int num);
__declspec(dllexport) int __get_diff_num_cnt(int* bg, int* nd);

#endif  //  __ARR__LIB__H__