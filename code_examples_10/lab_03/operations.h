#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

unsigned long long push(struct elm **end);
int pop(struct elm **end, struct empty **end_e);
int view(struct elm *end);
int view_adress(struct elm *end);
int view_adress_empty(struct empty *end);

#endif // OPERATIONS_H
