#include "arr_queue.h"

// кладем в хвост очереди
void a_push_t(int x, struct a_queue **st)
{
    if (!(*st))
    {
        *st = malloc(sizeof(struct a_queue));
        if (*st)
			(*st)->head = 0;
    }
    else
    {
        for (int i = (*st)->head+1; i >= 0; i--)
            (*st)->list[i+1] = (*st)->list[i];
       (*st)->head++;
    }
    (*st)->list[0]= x;
}

// кладем в голову очереди
void a_push_h(int x, struct a_queue **st)
{
    if (!(*st))
	{
		if ((*st = malloc(sizeof(struct a_queue))))
			(*st)->head = 0;
    }
    else
        (*st)->head++;
    (*st)->list[(*st)->head] = x;
}

void a_pop_h(int *x, struct a_queue **st)
{
    if(*st)
    {
        *x = (*st)->list[(*st)->head];
        if((*st)->head>0)
           (*st)->head--;
        else
        {
           free(*st);
           *st = NULL;
        }
    }
}

void a_pop_t(int *x,struct a_queue **st)
{
    if (*st)
    {
        *x = (*st)->list[0];
        if((*st)->head > 0)
        {
            for (int i=0; i < (*st)->head; i++)
                (*st)->list[i] = (*st)->list[i+1];
           (*st)->head--;
        }
        else
        {
           free(*st);
           *st = NULL;
        }
    }
}

void a_free(struct a_queue **st) 
{
    free(*st);
}

int is_empty_a(struct a_queue *st)
{
    if (!st)
        return 1;
    return 0;
}

int is_full_a(struct a_queue *st)
{
	if (st->head >= DEPTH)
		return 1;
	return 0;
}

void print_a(struct a_queue *st)
{
	if (!is_empty_a(st))
		for (int i = st->head; i>=0; i--)
			printf("%d\n", st->list[i]);
}
