#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct tree_node
{
	struct tree_node *up;
	struct tree_node *left;
	struct tree_node *right;
	char *data;
};

void node_info(struct tree_node* node);

struct tree_node* add_tree_node(struct tree_node* node, char* tmp);
struct tree_node* add_test_tree(void);
struct tree_node* make_test_tree1(void);

struct tree_node* search_tree_node(struct tree_node* root, char* ch);
struct tree_node* search_ch_tree_node(struct tree_node* root, char* ch);
struct tree_node* del_tree_node(struct tree_node* node);

struct tree_node* DeleteNode(struct tree_node* node, char* val);

void free_tree(struct tree_node* root);

void print_text_tree(FILE* f, struct tree_node* root);

void move_on(FILE* f, struct tree_node* root, const char* formation);

#endif  // TREE_NODE_H
