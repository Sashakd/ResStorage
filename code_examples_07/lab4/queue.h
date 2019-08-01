#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MAX_SIZE (100)

#include <stdlib.h>
#include <stdio.h>

struct list
{
    int x;
    struct list *next;
};

struct l_queue
{
    struct list *head;
	struct list *tail;
    struct list *st;
};

void push_h(int x, struct l_queue **st);// бессмысленно, наверное
void push_t(int x, struct l_queue **st);
void pop_h(int *x, struct l_queue **st);
void pop_t(int *x, struct l_queue **st);// бессмысленно, наверное

void free_l(struct l_queue **st);

int is_empty_l(struct l_queue *st);

void print_l(struct l_queue *st);

#endif
