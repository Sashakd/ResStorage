#ifndef READ_ARR_H
#define READ_ARR_H

#include <stdio.h>
#include <stdlib.h>

int get_num_cnt(FILE* f);

int* read_i_arr(FILE* f, int n);

#endif  // READ_ARR_H