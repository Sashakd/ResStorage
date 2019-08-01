#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

long long int push_first(float *mas, int *count_first, int count_second, int count);
long long int push_second(float *mas, int *count_second, int count_first, int count);
int pop_first(int *count_first);
int pop_second(int *count_second);
int view_first(float *mas, int count_first);
int view_second(float *mas, int count_second, int count);

#endif // OPERATIONS_H
