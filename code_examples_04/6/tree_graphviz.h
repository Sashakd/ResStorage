#ifndef TREE_GRAPHVIZ_H
#define TREE_GRAPHVIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_node.h"

void PrintTree(struct tree_node* T, FILE* f);
int create_tree_graph(struct tree_node* root, const char* gv_name, const char* png_name);

#endif  // TREE_GRAPHVIZ_H