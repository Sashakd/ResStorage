#ifndef CHANGING_H
#define CHANGING_H

#include "structures.h"
#include "read.h"

#define N 100 // максимальное количество записей

int adding(student *table, int *count);
int delete_record(student *table, int *count);

#endif // CHANGING_H
