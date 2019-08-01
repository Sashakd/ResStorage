/// Заголовочный файл для подключения модуля обычных деревьев

#ifndef __USLTREE__H__
#define __USLTREE__H__
struct tree_node
{
    char* word;
    int cpy;
    int num;
    struct tree_node* left;
    struct tree_node* right;
};

struct tree_node* createNode(char* word);
struct tree_node* insert(struct tree_node *tree, struct tree_node *node);
void apply_prefix(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg);
void apply_infix(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg);
void apply_postfix(struct tree_node *tree, void (*f)(struct tree_node*, void*), void *arg);
void to_dot(struct tree_node *tree, void *param);
void export_to_dot(FILE *f, const char *tree_name, struct tree_node *tree);
struct tree_node* poiskR(const char* x, struct tree_node* q);
void changer(struct tree_node** r, struct tree_node** q);

struct tree_node* deleteX(char* x, struct tree_node* p);
struct tree_node* delX(char* x, struct tree_node* p, int* is_it);
struct tree_node* del_for_all_char_X(struct tree_node* p, char* word);
struct tree_node* deleteWORD_X(char* x, struct tree_node* p);

#endif  // __USLTREE__H_
