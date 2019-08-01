#ifndef FILT_H
#define FILT_H

#include <stdlib.h>
#include <string.h>

void filt(void *base, size_t *num, size_t size, int (*compare) (const void *, const void *));

#endif  // FILT_H