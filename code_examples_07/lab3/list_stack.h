#ifndef __LIST_STACK_H__

#define __LIST_STACK_H__

#include "interfaces.h"
#include <stdio.h>
#include <stdlib.h>

struct list_char
{
	char ch;
	struct list_char *prev;
};

struct list_int
{
	int num;
	struct list_int *prev;
};

void push(struct list_int **s, int x);
void pop(struct list_int **s, int *x);
void create(struct list_int **s);
int is_empty(struct list_int *s);

void pushc(struct list_char **s, char x);
void popc(struct list_char **s, char *x);
void createc(struct list_char **s);
int is_emptyc(struct list_char *s);

int need_free(struct list_int **q, struct list_char **w);
int WReadS(struct list_char **w, char **str_ptr);
void printSt(struct list_int *q);
void printStc(struct list_char *w);
void pushResult(char st_op, struct list_int **q);
int first_op_case(char **str_ptr, struct list_char **w, struct list_int **q, char *str);


#define DEPTH (5)

struct a_stack {
	int n; // позиция вершины
	int *array;
};

struct a_stackc {
	int n; // позиция вершины
	char *array;
};

void a_push(struct a_stack *s, int x);
void a_pop(struct a_stack *s, int *x);
void a_create(struct a_stack **s);
int a_is_empty(struct a_stack *s);

void a_pushc(struct a_stackc *s, char x);
void a_popc(struct a_stackc *s, char *x);
void a_createc(struct a_stackc **s);
int a_is_emptyc(struct a_stackc *s);

int a_need_free(struct a_stack **q, struct a_stackc **w);
int a_WReadS(struct a_stackc *w, char **str_ptr);
void a_printSt(struct a_stack *q);
void a_printStc(struct a_stackc *w);
void a_pushResult(char st_op, struct a_stack *q); //
int a_first_op_case(char **str_ptr, struct a_stackc **w, struct a_stack **q, char *str);

#endif