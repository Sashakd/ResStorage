#ifndef SORTING_H
#define SORTING_H

#include "structures.h"

int keys_create(student *table, key *list, int count);
int comp_student(student *arg1, student *arg2);
int comp_key(key *arg1, key *arg2);
void my_sort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));
int analyse_sorting(student *table, int count, char *name_file);
int prnt_sort_keys(student *table, key *mas, int count);

#endif // SORTING_H
