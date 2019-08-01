#ifndef FIB_H
#define FIB_H

#include <stdio.h>
#include <math.h>

#include "dfnd.h"

// Определяет, является ли число числом Фибоначчи
// in  -- int x - целое число
// out -- int
// (0 - если не является
//  1 - если является)
int isfib(int x);

// Проверяет массив на нахождение в нём чисел Фибоначчи
// in  -- int* arr - массив целых чисел, int n - длина массива
// out -- int
// (1 - если есть хоть одно число Фибоначчи
//  0 - если нет)
int isfibinarr(int* arr, int n);

#endif  // FIB_H