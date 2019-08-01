#ifndef READ_H
#define READ_H

#include "structures.h"
#define N 100

int print_record(student tmp);
int insrt_record(student *tmp);
int reading(student *table, int *count, char **name);
int print_all(student *table, int count);
int save_file(student *table, int count);
int print_hostel(student *table, int count);

#endif // READ_H
