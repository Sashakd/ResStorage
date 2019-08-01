#ifndef MAZE_RDY_H
#define MAZE_RDY_H

#include <stdio.h>
#include <stdlib.h>

// Проверяет лабиринт на корректность
int check_maze_file(FILE* f);

// Записывает лабиринт (матрицу) в одномерный массив
int* get_maze_arr(FILE* f, int *r, int *c, int max_sz);

// Печать лабиринта.  (скорее всего с этим проблем нет)
void print_maze(int* arr, int r, int c);

// Функция обращения к элементу (получения значения элемента)
int get_value_arr(int* arr, int ix, int jy, int c); // нумерация начинается с нуля

#endif // MAZE_RDY_H
