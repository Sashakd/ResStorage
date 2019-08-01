#include "queue.h"

void push_h(int x, struct l_queue **st)
{
    struct list *pt =  malloc(sizeof(struct list));
    pt->x = x;
    pt->next = NULL;	
	
    if (!(*st))
    {
        (*st) = malloc(sizeof(struct l_queue));
        (*st)->head = (*st)->tail = (*st)->st = pt;		
    }
    else
        (*st)->head = (*st)->head->next = pt;
}

void push_t(int x, struct l_queue **st)
{
	struct list *pt =  malloc(sizeof(struct list));
	pt->x = x;
	
    if (!(*st))
    {
        *st = malloc(sizeof(struct l_queue));
        (*st)->head = (*st)->tail = (*st)->st = pt;
        (*st)->st->next = NULL;
    }
    else
    {
        pt->next = (*st)->tail;
        (*st)->tail = pt;
    }
}

void pop_h(int *x, struct l_queue **st)
{
    if (*st)
    {
        *x = (*st)->head->x;
        if ((*st)->tail != (*st)->head)
        {
            struct list *pt = (*st)->tail;
            while (pt->next != (*st)->head)
                pt = pt->next;

            (*st)->head = pt;
			pt=pt->next;
            free(pt);
            (*st)->head->next = NULL;
        }
        else
        {
			free((*st)->head);
            free(*st);
            *st = NULL;
        }
    }
}

void pop_t(int *x, struct l_queue **st)
{
    if (*st)
    {
        *x = (*st)->tail->x;
        if((*st)->tail != (*st)->head)
        {
            struct list *pt = (*st)->tail;
            (*st)->tail = (*st)->tail->next;
            free(pt);
        }
        else
        {
			free((*st)->head);
            free(*st);
            *st = NULL;
        }
    }
}

void free_l(struct l_queue **st) 
{
    int n;
    while (*st)
        pop_t(&n, st);
}

int is_empty_l(struct l_queue *st) 
{
    if (!st)
        return 1;
    return 0;
}

void print_l(struct l_queue *st)
{
    if (st)
    {
		struct list *pt = st->tail;
		while (pt)
		{
			printf("%d : %d\n", pt->x, pt);
			pt = pt->next;
		}
    }
}
