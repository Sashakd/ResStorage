#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"

struct BinTree *tree_create(struct BinTree *root, FILE *f);

#endif // READ_H
