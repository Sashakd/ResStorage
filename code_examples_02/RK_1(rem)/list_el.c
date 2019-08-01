#include "list_el.h"

struct list_elem* add_elem(struct list_elem* head, char* word)
{
	struct list_elem* buff = NULL;
	
	if (head)
	{           ///////////////////////////////////
		struct list_elem* rem = head;
		
		while (head->next)
		{
			if (or_strcmp(head->word, word))
			{
				(head->cnt)++;
				return rem;  // <======
			}
			else
				head = head->next;
		}
		
		buff = malloc(sizeof(struct list_elem));
		
		if (buff)
		{
			buff->word = strcpy_my_why(word);
			
			if (buff->word)
			{
				buff->cnt = 1;
				buff->next = NULL; // <=====
				head->next = buff;
				
				return rem;
			}
			else
				return NULL;
		}
		else
			return NULL;
	}        ////////////////////////////////////
	else
	{
		buff = malloc(sizeof(struct list_elem)); // <=======================
		
		if (buff)
		{
				buff->word = strcpy_my_why(word);
				
				if(buff->word)
				{
					buff->cnt = 1;
					buff->next = NULL;
					
					return buff;
				}
				else
					return NULL;
		}
		else
			return NULL;
	}
}

struct list_elem* del_elem(struct list_elem* head) // Не влияет
{
	if (head)
	{
		if (head->next)
		{
			struct list_elem* rem = head;
			
			while (head->next->next)
				head = head->next;
				
			free(head->next->word); // <------
			free(head->next);
			head->next = NULL;
			
			return rem;
		}
		else
		{
			free(head->word); // <--------
			free(head);
			
			return NULL;
		}
	}
	else
		return NULL;
}

void free_elem(struct list_elem* head)  // Не влияет
{
	while (head)
		head = del_elem(head);
}

void print_list(FILE* f, struct list_elem* head)
{
	while (head)
	{
		fprintf(f, "[%s] %d\n", head->word, head->cnt);
		head = head->next;
	}
	
}