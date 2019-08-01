#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree_node.h"

// функция извлекающая слово из файла и выделяющая под него память
char* get_word_from_file(FILE* f, int* len, int mx_len);
struct tree_node* get_tree_from_file(FILE* f, int mx_len);

#endif  // READ_H
