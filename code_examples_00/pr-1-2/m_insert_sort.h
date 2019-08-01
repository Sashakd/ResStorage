#ifndef M_INSERT_SORT_H
#define M_INSERT_SORT_H

#include <stdlib.h>
#include <string.h>

int compare_int(const void* p, const void* q);

void modified_insertion_sort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));

#endif  // M_INSERT_SORT_H