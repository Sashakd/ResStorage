/// Заголовочный файл для подключения модуля обычных f  1деревьев

#ifndef __BALTREE__H__
#define __BALTREE__H__
struct btree_node
{
    char* word;
    int cpy;
    unsigned char height;
    int num;
    struct btree_node* left;
    struct btree_node* right;
};

struct btree_node* createNodeB(char* word);
unsigned char heightB(struct btree_node* p);
int bfactorB(struct btree_node* p);
void fixheightB(struct btree_node* p);
struct btree_node* insertB(struct btree_node* p, char* word);
struct btree_node* findminB(struct btree_node* p);
struct btree_node* removeminB(struct btree_node* p);

struct btree_node* deleteXB(struct btree_node* p, char* word);
struct btree_node* delXB(struct btree_node* p, char* word, int* is_it);
struct btree_node* del_for_all_char_XB(struct btree_node* p, char* word);
struct btree_node* deleteWORD_XB(struct btree_node* p, char* word);

void apply_prefixB(struct btree_node *tree, void (*f)(struct btree_node*, void*), void *arg);
void apply_infixB(struct btree_node *tree, void (*f)(struct btree_node*, void*), void *arg);
void apply_postfixB(struct btree_node *tree, void (*f)(struct btree_node*, void*), void *arg);
void to_dotB(struct btree_node *tree, void *param);
void export_to_dotB(FILE *f, const char *tree_name, struct btree_node *tree);
struct btree_node* poiskRB(const char* x, struct btree_node* q);
#endif  // __BALTREE__H_
