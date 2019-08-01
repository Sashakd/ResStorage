#include "operations.h"

void push_end(struct elm **head, float numb, int type)
{
    struct elm *tmp;
    struct elm *tmp_1;

    tmp = malloc(sizeof(struct elm));
    tmp->numb = numb;
    tmp->type = type;
    tmp->prev = NULL;
    if ((*head) == NULL)
        (*head) = tmp;
    else
    {
        (tmp_1) = (*head);
        while (tmp_1->prev != NULL)
            tmp_1 = tmp_1->prev;
        tmp_1->prev = tmp;
    }
}

void push_end_adress(struct adress **head, struct elm *poin)
{
	struct adress *tmp;
	struct adress *tmp_1;

	tmp = malloc(sizeof(struct elm));
	tmp->ad = poin;
	tmp->prev = NULL;
	if ((*head) == NULL)
		(*head) = tmp;
	else
	{
		(tmp_1) = (*head);
		while (tmp_1->prev != NULL)
			tmp_1 = tmp_1->prev;
		tmp_1->prev = tmp;
	}
}

void push_4(struct elm *head, float numb)
{
    struct elm *tmp;
    struct elm *tmp_1;

    tmp = malloc(sizeof(struct elm));
    tmp->numb = numb;
    tmp->type = 2;

    tmp_1 = head;
    for (int i = 0; i < 2; i++)
        tmp_1 = tmp_1->prev;
    tmp->prev = tmp_1->prev;
    tmp_1->prev = tmp;
}

void pop(struct elm **head)
{
    struct elm *tmp;
    struct elm *tmp_1;

    tmp = (*head);
    tmp_1 = tmp->prev;
    free(tmp);
    (*head) = tmp_1;
}

void view(struct elm *head)
{
    struct elm *tmp;

    tmp = head;
    while (tmp != NULL)
    {
        printf("numb = %f; type = %d\n", tmp->numb, tmp->type);
        tmp = tmp->prev;
    }
}

void view_adress(struct adress *head, struct adress *head1, FILE *f)
{
	struct adress *tmp;
	struct adress *tmp1;
	int i = 0;

	tmp = head;
	tmp1 = head1;
	while ((tmp->prev != NULL || tmp1->prev != NULL) && i < 10)
	{
		if (tmp->prev != NULL && tmp1->prev != NULL)
			fprintf(f, "%p\t%p\n", tmp, tmp1);
		if (tmp->prev != NULL && tmp1->prev == NULL)
			fprintf(f, "%p\n", tmp);
		if (tmp->prev == NULL && tmp1->prev != NULL)
			fprintf(f, "%p\n", tmp1);
		tmp = tmp->prev;
		tmp1 = tmp1->prev;
		i++;
	}
}

int length(struct elm *head)
{
    int l = 0;
    struct elm *tmp;

    tmp = head;
    while (tmp != NULL)
    {
        l++;
        tmp = tmp->prev;
    }
    return l;
}

float last_time(struct elm *head)
{
    struct elm *tmp;

    tmp = head;
    while (tmp->prev != NULL)
        tmp = tmp->prev;
    return tmp->numb;
}

struct elm *last_adress(struct elm *head)
{
	struct elm *tmp;

	tmp = head;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	return tmp;
}


void push_end_mas(float head[1000][2], int *count, float numb, int type)
{
    head[*count][0] = numb;
    head[*count][1] = (float) type;
    *count = *count + 1;
}

void push_4_mas(float head[1000][2], int *count, float numb)
{
    for (int i = *count; i > 3; i--)
    {
        head[i][0] = head[i - 1][0];
        head[i][1] = head[i - 1][1];
    }
    head[3][0] = numb;
    head[3][1] = 2;
    *count = *count + 1;
}

void pop_mas(float head[1000][2], int *count)
{
    for (int i = 0; i < *count - 1; i++)
    {
        head[i][0] = head[i + 1][0];
        head[i][1] = head[i + 1][1];
    }
    *count = *count - 1;
}

void view_mas(float head[1000][2], int count)
{
    for (int i = 0; i < count; i++)
        printf("numb = %f; type = %1.0f\n", head[i][0], head[i][1]);
}
