#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdlib.h>
#include <stdio.h>
#include "structures.h"

void push_end(struct elm **head, float numb, int type);
void push_4(struct elm *head, float numb);
void pop(struct elm **head);
void view(struct elm *head);
int length(struct elm *head);
float last_time(struct elm *head);
void push_end_mas(float head[][2], int *count, float numb, int type);
void push_4_mas(float head[][2], int *count, float numb);
void pop_mas(float head[][2], int *count);
void view_mas(float head[][2], int count);
void push_end_adress(struct adress **head, struct elm *poin);
struct elm *last_adress(struct elm *head);
void view_adress(struct adress *head, struct adress *head1, FILE *f);

#endif // OPERATIONS_H
