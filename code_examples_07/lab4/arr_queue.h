#ifndef __ARR_QUEUE_H__
#define __ARR_QUEUE_H__

#define DEPTH (5000)

#include <stdlib.h>
#include <stdio.h>

struct a_queue
{
    int head;
    int list[DEPTH];
};

void a_push_t(int x, struct a_queue **st);
void a_push_h(int x, struct a_queue **st);// бессмысленно
void a_pop_h(int *x, struct a_queue **st);
void a_pop_t(int *x, struct a_queue **st);// бессмысленно

void a_free(struct a_queue **st);

int is_empty_a(struct a_queue *st);
int is_full_a(struct a_queue *st);

void print_a(struct a_queue *st);

#endif
