#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "structures.h"

struct BinTree* InsIteration(struct BinTree *T, char *w);
void PrintTree(struct BinTree *T, FILE *f);

#endif // OPERATIONS_H
