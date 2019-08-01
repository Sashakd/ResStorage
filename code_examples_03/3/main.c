/*
Вариант 7 (26)
Элементами стека являются адреса памяти. 
При реализации массивами  - их вводить, 
при реализации списком – брать адрес 
выделенной памяти под элемент.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_STACK_SIZE 5
#define NX 1

unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

// Как массив
char** init_arr_stack(const int max_sz)
{
	char **buff = malloc(max_sz*(sizeof(char*)));
	return buff;
}

void push_arr_stack(char** arr, int* n, void* tmp, int mx_sz)
{
	if (*n < mx_sz)
	{
		*(arr + *n) = tmp;
		(*n)++;
	}
	else
		printf("Warning! Stack is full\n");
}

char* pop_arr_stack(char** arr, int* n)
{
	void* rem;
	
	if (*n > 0)
	{
		rem = *(arr + *n-1);
		(*n)--;
		
		return rem;
	}
	else
	{
		printf("Warning! Stack is empty\n");
		return NULL;
	}
}

void print_arr_stack(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("(%d) %p\n", i+1, *(arr + n-i-1));
	}
}

// освобождение памяти осуществл станд способом

// Как список
struct list_el
{
	char* data;
	struct list_el* next;
};

struct list_el* push_struct_stack(struct list_el* head)
{
	struct list_el* rem;
	
	if (head)
	{
		rem = malloc(sizeof(struct list_el));
		
		if (rem)
		{
			rem->next = head;
			rem->data = (char*) rem;
			
			return rem;
		}
		else
			return head;
	}
	else
	{
		rem = malloc(sizeof(struct list_el));
		
		if (rem)
		{
			rem->data = (char*) rem;
			rem->next = NULL;
			
			return rem;
		}
		else
			return NULL;
	}
}

struct list_el* pop_struct_stack(struct list_el* head, char** pp)  // Сделать  так чтобы возвращал освободившийся адрес
{
	if (head)
	{
		struct list_el* rem = head;
		
		rem = rem->next;
		*pp = head->data;
		free(head);
		
		return rem;
	}
	else
	{
		printf("Warning! Stack is empty\n");
		return NULL;
	}
}

void print_struct_stack(struct list_el* head)  // Подправить
{
	struct list_el* curr = head;
	int i = 0;
	
	if (curr)
	{
		while(curr)
		{
			i++;
			
			printf("(%d) %p\n", i, curr->data);
			curr = curr->next;
		}
	}
	else
		printf("[empty]\n");
}

void free_struct_stack(struct list_el* head)
{
	if (head)
	{
		char* pp;
		
		while(head)
		{
			head = pop_struct_stack(head, &pp);
		}
	}
}

struct list_el* push_tmp_struct_stack(struct list_el* head, char* p)
{
	struct list_el* rem;
	
	if (head)
	{
		if (head->data != p)
		{
			rem = malloc(sizeof(struct list_el));
			
			if (rem)
			{
				rem->next = head;
				rem->data = (char*) p;
				
				return rem;
			}
			else
				return head;
		}
		else
			return head;
	}
	else
	{
		rem = malloc(sizeof(struct list_el));
		
		if (rem)
		{
			rem->data = (char*) p;	
			rem->next = NULL;
			
			return rem;
		}
		else
			return NULL;
	}
}

int main()
{
	char** arr = init_arr_stack(MAX_ARR_STACK_SIZE);
	char ch;
	int n = 0;
	struct list_el* head = NULL;
	struct list_el* free_zone = NULL;
	char* p;
	char str[40];
	
	while (1)
	{
		printf("\n\n-- (ADDRESS STACK) MENU:\n"
			   "(type char to choose operation)\n"
			   "0 -- exit\n"
		       "1 -- push element(array stack)\n"
			   "2 -- pop element (array stack)\n"
			   "3 -- print stack (array stack)\n"
			   "4 -- push element (list stack)\n"
			   "5 -- pop element  (list stack)\n"
			   "6 -- print stack  (list stack)\n"
			   "7 -- free pointer stack (list stack)\n"
			   "8 -- time & memory automatic test\n\n\n>");
	
		//ch = getchar();
		if (scanf("%s", str) == 1)
		{
			ch = str[0];
			
			if (ch == '1')
			{	
				printf("\n Write address: ");
				
				int tem = 0;
				
				if (scanf("%d", &tem) == 1)
				{
					//p = (char*) tem;
					push_arr_stack(arr, &n, (char*)tem, MAX_ARR_STACK_SIZE);
				}
				else
				{
					printf("Error! Wrong input\n");
					free(arr);
					return -1;
				}
			}
			else
			if (ch == '2')
			{
				char* p2;
				
				p2 = pop_arr_stack(arr, &n);
				
				printf("\n Deleted element: %p\n", p2);
			}
			else
			if (ch == '3')
			{
				printf("\nSTACK OF POINTERS:\n");
				print_arr_stack(arr, n);
				printf("\n\n");
			}
			else
			if (ch == '4')
			{
				head = push_struct_stack(head);
				printf("Address stored: %p\n", head->data);
			}
			else
			if (ch == '5')
			{
				head = pop_struct_stack(head, &p);
				printf("\n Deleted element: %p\n", p);
				free_zone = push_tmp_struct_stack(free_zone, p);
			}
			else
			if (ch == '6')
			{
				printf("\nSTACK OF POINTERS:\n");
				print_struct_stack(head);
			}
			else
			if (ch == '7')
			{
				printf("\nFREE POINTERS:\n");
				print_struct_stack(free_zone);
			}
			if (ch == '8') // 20 20
			{
				if (head) free_struct_stack(head);
	            if (free_zone) free_struct_stack(free_zone);
				if (arr) free(arr);
				
				int loops = 0;
				int elements = 0;
				/*
				printf ("\n Set loop count: ");
				if ((scanf("%d", &loops) == 1) && (loops > 0))
				{*/
					if (loops == 0) printf("HOW?\n");
					loops = 1;
					
					printf ("\n Set element count: ");
					
					if ((scanf("%d", &elements) == 1) && (elements > 0))
					{
						unsigned long long t1, t2, t3, t4, t5, t6; //, t7, t8;
						unsigned long long mid_pop_arr;
						unsigned long long mid_push_arr;
						unsigned long long mid_pop_str;
						unsigned long long mid_push_str;
						
						if (arr) free(arr);
						
						//t7 = tick();
						arr = init_arr_stack(elements);
						//t8 = tick();
						
						//elements = 1;

						for (int i = 0; i < loops; i++)
						{
							n = 0;
							
							t1 = tick();
							for (int j = 1; j < elements+1; j++)
								push_arr_stack(arr, &n, (char*) j, elements);
							t2 = tick();
							for (int j = 0; j < elements; j++)
								head = push_struct_stack(head);
							t3 = tick();
							
							mid_push_arr += ((t2 - t1) / (unsigned long long) elements);
							mid_push_str += ((t3 - t2) / (unsigned long long) elements);
							
							char *p;
							
							t4 = tick();
							for (int j = 1; j < elements+1; j++)
							{
								head = pop_struct_stack(head, &p);
							}
							t5 = tick();
							for (int j = 1; j < elements+1; j++)
								pop_arr_stack(arr, &n);
							t6 = tick();
							
							if (arr) free(arr);
							
							mid_pop_arr += ((t6 - t5) / (unsigned long long) elements);
							mid_pop_str += ((t5 - t4) / (unsigned long long) elements);
						}
						
						unsigned long long timeA1 = (mid_push_arr / (loops)); // + (t8 - t7)/elements);
						unsigned long long timeA2 = (mid_pop_arr  / (loops));
						
						unsigned long long timeS1 = (mid_push_str / (loops));
						unsigned long long timeS2 = (mid_pop_str  / (loops)) / 1000;
						
						unsigned long long mem1 = elements * (sizeof(char*));
						unsigned long long mem2 = elements * (sizeof(struct list_el));
						
						printf("\n\nloops = %d; elements = %d;\n", loops, elements);
						printf("for array stack (time): [ pushing = %20llu(t);    popping = %20lu(t);      memory = %20llu(by); ]\n", timeA1, timeA2, mem1);
						printf("for list stack  (time): [ pushing = %20llu(t);    popping = %20lu(t*1000); memory = %20llu(by); ]\n", timeS1, timeS2, mem2);
						
						free(arr);
						free_struct_stack(head);
					}
					else
					{
						printf("Error! Wrong input\n");
						return -3;
					}
				/*
				}
				else
				{
					printf("Error! Wrong input\n");
					return -2;
				}*/
			}
			else
			if (ch == '0') // ОСТАЛСЯ ЗАМЕР ЭФФЕКТИВНОСТИ
			{
				printf("EXIT");
				break;
			}
			
		}
		else
		{
			printf("Warning! Wrong command index\n  [IGNORED]\n");
		}
	}

	free_struct_stack(head);
	free_struct_stack(free_zone);
	free(arr);
	return 0;
}