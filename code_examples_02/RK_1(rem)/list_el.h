#ifndef LIST_EL_H
#define LIST_EL_H

#include <stdlib.h>

#include "string_my.h"

struct list_elem
{
	char* word;
	int cnt;
	
	struct list_elem* next;
};

struct list_elem* add_elem(struct list_elem* head, char* word);

struct list_elem* del_elem(struct list_elem* head);

void free_elem(struct list_elem* head);

void print_list(FILE* f, struct list_elem* head);

#endif // LIST_EL_H