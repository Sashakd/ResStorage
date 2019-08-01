#ifndef __ARR__LIB__H__
#define __ARR__LIB__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

// Ввод
ARR_DLL int ARR_DECL get_num_cnt(FILE* f);
ARR_DLL int* ARR_DECL read_i_arr(FILE* f, int n);

// Вывод
ARR_DLL void ARR_DECL print_i_arr(int* bg, int* nd);

// Обработка
ARR_DLL int ARR_DECL num_if_in_cnt(int* bg, int* nd, int num);
ARR_DLL int ARR_DECL get_diff_num_cnt(int* bg, int* nd);

#endif  //  __ARR__LIB__H__