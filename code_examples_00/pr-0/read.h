#ifndef READ_H
#define READ_H

#include <stdio.h>

#include "dfnd.h"

// Считывает массив из строки в файле
/*
Возвращает:
    0 - если найдено недопустимое значение
    1 - если массив чисел считан полностью
	2 - если конец файла
*/
int readstrarr(FILE *f, int* a, int *n);

// Печатает массив arr, состоящий из n элеменов
void iprintarr(int* arr, int n);

#endif  // READ_H