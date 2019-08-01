#ifndef BALANCE_H
#define BALANCE_H

#include "tree_node.h"

int node_height(struct tree_node* node);        // OK

int get_max_sublen(struct tree_node* node);     // OK

int get_balance_factor(struct tree_node* node); // OK

struct tree_node* turn_min_on(struct tree_node* r, struct tree_node* p);

struct tree_node* turn_min_rev(struct tree_node* r, struct tree_node* p);

struct tree_node* turn_big_on(struct tree_node* r, struct tree_node* p);

struct tree_node* turn_big_rev(struct tree_node* r, struct tree_node* p);

struct tree_node* tree_balancing(struct tree_node* r, struct tree_node* p);

#endif  // BALANCE_H