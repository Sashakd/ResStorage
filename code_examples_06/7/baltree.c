/// Модуль для реализации сбалансированных деревьев
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#include "baltree.h"

// создание элемента дерева
struct btree_node* createNodeB(char* word)
{
    static int i=0;
    struct btree_node *node = malloc(sizeof(struct btree_node));
    if (node)
    {
        node->word = word;
        node->cpy = 0;
        node->height = 1;
        node->num = i;
        node->left = NULL;
        node->right = NULL;
        i++;
    }
    return node;
}

// высота
unsigned char heightB(struct btree_node* p)
{
    return p?p->height:0;
}

// вычисление баланса
int bfactor(struct btree_node* p)
{
    return heightB(p->right)-heightB(p->left);
}

// восстановление корректного значения heightB
void fixheightB(struct btree_node* p)
{
    unsigned char hl = heightB(p->left);
    unsigned char hr = heightB(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

// правый поворот вокруг p
struct btree_node* rotaterightB(struct btree_node* p)
{
    struct btree_node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightB(p);
    fixheightB(q);
    return q;
}

// левый поворот вокруг q
struct btree_node* rotateleftB(struct btree_node* q)
{
    struct btree_node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightB(q);
    fixheightB(p);
    return p;
}

// балансировка узла p
struct btree_node* balance(struct btree_node* p)
{
    fixheightB(p);
    if (bfactor(p)==2)
    {
        if (bfactor(p->right) < 0)
            p->right = rotaterightB(p->right);
        return rotateleftB(p);
    }
    if (bfactor(p)==-2)
    {
        if (bfactor(p->left) > 0)
            p->left = rotateleftB(p->left);
        return rotaterightB(p);
    }
    return p; // балансировка не нужна
}

// вставка слова в дерево с корнем p
struct btree_node* insertB(struct btree_node* p, char* word)
{
    if (!p)
        return createNodeB(word);
    if (strcmp(word, p->word) < 0)
        p->left = insertB(p->left, word);
    else
    {
        if (strcmp(word, p->word) == 0)
        {
            p->cpy += 1;
            return balance(p);
        }
        p->right = insertB(p->right, word);
    }
    return balance(p);
}

// поиск узла с минимальным ключом в дереве p
struct btree_node* findminB(struct btree_node* p)
{
    return p->left?findminB(p->left):p;
}

// удаление узла с минимальным ключом из дерева p
struct btree_node* removeminB(struct btree_node* p)
{
    if (p->left==0)
        return p->right;
    p->left = removeminB(p->left);
    return balance(p);
}

// удаление слова из дерева p
struct btree_node* deleteXB(struct btree_node* p, char* word)
{
    if (!p)
        return NULL;
	
    if (strncmp(word, p->word, 1) < 0)
        p->left = deleteXB(p->left, word);
    else if (strncmp(word, p->word, 1) > 0)
        p->right = deleteXB(p->right, word);
    else //  k == p->key
    {
        struct btree_node* q = p->left;
        struct btree_node* r = p->right;
        if (!r)
            return q;
        struct btree_node* min = findminB(r);
        min->right = removeminB(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

struct btree_node* delXB(struct btree_node* p, char* word, int* is_it) /// проблема
{
    if (!p)
	{
		*is_it = 0;
        return NULL;
	}
	
    if (strncmp(word, p->word, 1) < 0)
        p->left = delXB(p->left, word, is_it);
    else if (strncmp(word, p->word, 1) > 0)
        p->right = delXB(p->right, word, is_it);
    else //  k == p->key
    {
		*is_it = 1;
        struct btree_node* q = p->left;
        struct btree_node* r = p->right;
        if (!r)
            return q;
        struct btree_node* min = findminB(r);
        min->right = removeminB(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

struct btree_node* del_for_all_char_XB(struct btree_node* p, char* word)
{
	int qur = 1;
	
	while (qur)
	{
		p = delXB(p, word, &qur);
	}

	return balance(p);
}

struct btree_node* deleteWORD_XB(struct btree_node* p, char* word)
{
    if (!p)
        return NULL;
	
    if (strcmp(word, p->word) < 0)
        p->left = deleteXB(p->left, word);
    else if (strcmp(word, p->word) > 0)
        p->right = deleteXB(p->right, word);
    else //  k == p->key
    {
        struct btree_node* q = p->left;
        struct btree_node* r = p->right;
        if (!r)
            return q;
        struct btree_node* min = findminB(r);
        min->right = removeminB(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

/*
struct btree_node* deleteXB(struct btree_node* p, char* word)
{
    if (!p)
        return NULL;
    if (strcmp(word, p->word) < 0)
        p->left = deleteXB(p->left, word);
    else if (strcmp(word, p->word) > 0)
        p->right = deleteXB(p->right, word);
    else //  k == p->key
    {
        struct btree_node* q = p->left;
        struct btree_node* r = p->right;
        if (!r)
            return q;
        struct btree_node* min = findminB(r);
        min->right = removeminB(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}
*/

// префиксный обход
void apply_prefixB(struct btree_node *tree,
                 void (*f)(struct btree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;

    // pre-order
    f(tree, arg);
    apply_prefixB(tree->left, f, arg);
    apply_prefixB(tree->right, f, arg);
}

// инфиксный обход
void apply_infixB(struct btree_node *tree,
                 void (*f)(struct btree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;

    apply_infixB(tree->left, f, arg);
    // in-order
    f(tree, arg);
    apply_infixB(tree->right, f, arg);
}

// постфиксный обход
void apply_postfixB(struct btree_node *tree,
                 void (*f)(struct btree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;
    f(tree, arg);
    apply_postfixB(tree->left, f, arg);
    apply_postfixB(tree->right, f, arg);
    // post-order
    f(tree, arg);
}

// печать связи в файл
void to_dotB(struct btree_node *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%i -> %i;\n", tree->num, tree->left->num);

    if (tree->right)
        fprintf(f, "%i -> %i;\n", tree->num, tree->right->num);

    fprintf(f, "%i [label=\"%s\"];\n", tree->num, tree->word);
}

// перевод в графа в файл формата dot
void export_to_dotB(FILE *f, const char *tree_name,
                                       struct btree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);

    apply_infixB(tree, to_dotB, f);

    fprintf(f, "}\n");
    if (tree == NULL)
        printf("В дереве нет элементов! Графическое представление не обновлено!");
}

// рекурсивный поиск
struct btree_node* poiskRB(const char* x, struct btree_node* q)
{
    if (q == NULL || strcmp(x, q->word)==0)
        return q;
    if (strcmp(x, q->word)<0)
        return poiskRB(x, q->left);
    else
        return poiskRB(x, q->right);
}
