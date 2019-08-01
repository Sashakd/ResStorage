/// Модуль для реализации обычных деревьев
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#include "usltree.h"

// создание элемента дерева
struct tree_node* createNode(char* word)
{
    static int i=0;
    struct tree_node *node = malloc(sizeof(struct tree_node));
    if (node)
    {
        node->word = word;
        node->cpy = 0;
        node->num = i;
        node->left = NULL;
        node->right = NULL;
        i++;
    }
    return node;
}

// поиск с включением
struct tree_node* insert(struct tree_node *tree, struct tree_node *node)
{
    if (tree == NULL)
        return node;

    if (strcmp(node->word, tree->word) < 0)
        tree->left = insert(tree->left, node);
    else
    {
        if (strcmp(node->word, tree->word) == 0)
        {
            tree->cpy += 1;
            node->cpy += 1;
            return tree;
        }
        tree->right = insert(tree->right, node);
    }
    return tree;
}

// префиксный обход
void apply_prefix(struct tree_node *tree,
                 void (*f)(struct tree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;

    // pre-order
    f(tree, arg);
    apply_prefix(tree->left, f, arg);
    apply_prefix(tree->right, f, arg);
}

// инфиксный обход
void apply_infix(struct tree_node *tree,
                 void (*f)(struct tree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;

    apply_infix(tree->left, f, arg);
    // in-order
    f(tree, arg);
    apply_infix(tree->right, f, arg);
}

// постфиксный обход
void apply_postfix(struct tree_node *tree,
                 void (*f)(struct tree_node*, void*),
                                              void *arg)
{
    if (tree == NULL)
        return;
    f(tree, arg);
    apply_postfix(tree->left, f, arg);
    apply_postfix(tree->right, f, arg);
    // post-order
    f(tree, arg);
}

// печать связи в файл
void to_dot(struct tree_node *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%i -> %i;\n", tree->num, tree->left->num);

    if (tree->right)
        fprintf(f, "%i -> %i;\n", tree->num, tree->right->num);

    fprintf(f, "%i [label=\"%s\"];\n", tree->num, tree->word);
}

// перевод в графа в файл формата dot
void export_to_dot(FILE *f, const char *tree_name,
                                       struct tree_node *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);

    apply_infix(tree, to_dot, f);

    fprintf(f, "}\n");
    if (tree == NULL)
        printf("В дереве нет элементов! Графическое представление не обновлено!");
}

// рекурсивный поиск
struct tree_node* poiskR(const char* x, struct tree_node* q)
{
    if (q == NULL || strcmp(x, q->word)==0)
        return q;
    if (strcmp(x, q->word)<0)
        return poiskR(x, q->left);
    else
        return poiskR(x, q->right);
}

// поменять
void changer(struct tree_node** r, struct tree_node** q)
{
    if ((*r)->right != NULL)
        changer(&((*r)->right), q);
    else
    {
        (*q)->word = (*r)->word;
        (*q)->cpy = (*q)->cpy;
        *q = *r;
        *r = (*r)->left;
    }
}

// удалить элемент по ключу
struct tree_node* deleteX(char* x, struct tree_node* p)
{
    struct tree_node* q;
    if (p == NULL)
        printf("\nЭлемента в дереве нет!");
    else if (strncmp(x, p->word, 1) < 0)
        p->left = deleteX(x, p->left);
    else if (strncmp(x, p->word, 1) > 0)
        p->right = deleteX(x, p->right);
    else
    {
        q = p;
        if (q->right == NULL)
        {
            p = q->left;
        }
        else if (q->left == NULL)
        {
            p = q->right;
        }
        else
        {
            changer(&(q->left), &q);
        }
        printf("\nУдаление успешно!");
    }
    return p;
}

struct tree_node* delX(char* x, struct tree_node* p, int* is_it)
{
    struct tree_node* q;
    if (p == NULL)
	{
		*is_it = 0;
	}
    else if (strncmp(x, p->word, 1) < 0)
        p->left = delX(x, p->left, is_it);
    else if (strncmp(x, p->word, 1) > 0)
        p->right = delX(x, p->right, is_it);
    else
    {
		*is_it = 1;
		
        q = p;
        if (q->right == NULL)
        {
            p = q->left;
        }
        else if (q->left == NULL)
        {
            p = q->right;
        }
        else
        {
            changer(&(q->left), &q);
        }
    }
	
    return p;
}

struct tree_node* del_for_all_char_X(struct tree_node* p, char* word)
{
	int qur = 1;
	
	while (qur)
	{
		p = delX(word, p, &qur);
	}

	return p;
}

struct tree_node* deleteWORD_X(char* x, struct tree_node* p)
{
    struct tree_node* q;
    if (p == NULL)
        printf("\nЭлемента в дереве нет!");
    else if (strcmp(x, p->word) < 0)
        p->left = deleteX(x, p->left);
    else if (strcmp(x, p->word) > 0)
        p->right = deleteX(x, p->right);
    else
    {
        q = p;
        if (q->right == NULL)
        {
            p = q->left;
        }
        else if (q->left == NULL)
        {
            p = q->right;
        }
        else
        {
            changer(&(q->left), &q);
        }
        printf("\nУдаление успешно!");
    }
    return p;
}
