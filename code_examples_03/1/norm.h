#ifndef NORM_H
#define NORM_H

#include <string.h>

#include "bnumb.h"

struct big_numb* move_mantis(struct big_numb*  num, char* side, char* rem);

int is_zero(struct big_numb*  num);

struct big_numb* normalize(struct big_numb*  num);

#endif  // NORM_H