#ifndef __ARRX__H__
#define __ARRX__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef EXAMPLE_EXPORTS
#define EXAMPLE_DLL __declspec(dllexport)
#else
#define EXAMPLE_DLL __declspec(dllimport)
#endif

#define EXAMPLE_DECL __cdecl

// Функция Эйлера
EXAMPLE_DLL int EXAMPLE_DECL phi (int n);

// Проверка является ли число простым
EXAMPLE_DLL int EXAMPLE_DECL is_simple(int n);

// Запись в массив n простых чисел
EXAMPLE_DLL void EXAMPLE_DECL init_arr_simple(int* arr, int n);

// Вставка одной строки на определённую позицию внутри первой
EXAMPLE_DLL int EXAMPLE_DECL insert(char *str, char* sub_str, int start, char *str_res, int res_len);

#endif  // __ARRX__H__