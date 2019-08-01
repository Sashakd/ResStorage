#include <stdio.h>
#include <stdlib.h>
#include "interfaces.h"
#include "list_stack.h"

//#define PRINTING

unsigned long long tick(void) {
	unsigned long long d;

	__asm__ __volatile__("rdtsc" : "=A"(d));

	return d;
}

/// call: lab3.exe
int main(void)
{
	unsigned long long tb, te;
	int action=1, act=1;
	int num;
	char str[10];
	
	struct list_int *b;
	struct a_stack *a;
	a_create(&a);
	create(&b);
	
	printf("\nTime tests:");
	printf("\n Array stack:");
	printf("\n\t push ");
	tb = tick();
	for (int i = 0; i<5; i++)
		a_push(a, 20);
	te = tick();
	printf("%d", (te-tb)/5);
	printf("\n\t pop ");
	tb = tick();
	for (int i = 0; i<5; i++)
		a_pop(a, &num);
	te = tick();
	printf("%d", (te-tb)/5);
	printf("\n\n List stack:");
	printf("\n\t push ");
	tb = tick();
	for (int i = 0; i<5; i++)
		push(&b, 20);
	te = tick();
	printf("%d", (te-tb)/5);
	printf("\n\t pop ");
	tb = tick();
	for (int i = 0; i<5; i++)
		pop(&b, &num);
	te = tick();
	printf("%d\n\n", (te-tb)/5);
	
	create(&b);
	
	while (action)
	{
		main_menu();
		scanf("%d", &action);
		fgets(str, 9, stdin);
		if ((action != 1) && (action != 2))
			return 0;

		if (action == 1)
		{
			struct a_stack *q;
			a_create(&q);
			while (act)
			{
				printf("\n\n\n\nArray stack:");
				sub_menu();
				scanf("%d", &act);
				fgets(str, 9, stdin);
				if ((act != 1) && (act != 2) && (act != 3) && (act != 4))
				{
					struct a_stackc *w;
					a_createc(&w);
					a_need_free(&q, &w);
					break;
				}
				
				if (act == 1)
				{					
					printf("\nPUSH in array stack.");
					if (q->n >= DEPTH)
						printf("\nStack is full");
					else
					{
						printf("\n-> ");
						scanf("%d", &num);
						fgets(str, 9, stdin);
						a_push(q, num);
					}
				}
				if (act == 2)
				{
					printf("POP from array stack.");
					if (!a_is_empty(q))
					{
						a_pop(q, &num);
						printf("\nPopped %d", num);
					}
					else
						printf("\nStack is empty.");
				}		
				if (act == 3)
				{
					printf("Print array stack + address.");
					a_printSt(q);
				}
				if (act == 4)
					a_task_list();
			}
		}
		
		if (action == 2)
		{
			struct list_int *q;
			create(&q);
			while (act)
			{
				printf("\n\n\n\nList stack:");
				sub_menu();
				scanf("%d", &act);
				fgets(str, 9, stdin);
				if ((act != 1) && (act != 2) && (act != 3) && (act != 4))
				{
					struct list_char *w;
					createc(&w);
					need_free(&q, &w);
					break;
				}
				
				if (act == 1)
				{
					printf("\nPUSH in list stack.");	
					printf("\n-> ");
					scanf("%d", &num);
					fgets(str, 9, stdin);
					push(&q, num);
				}
				if (act == 2)
				{
					printf("\nPOP from list stack.");
					if (!is_empty(q))
					{
						push(&b, (int)q);
						pop(&q, &num);
						printf("\nPopped %d", num);
					}
					else
						printf("\nStack is empty.");
				}		
				if (act == 3)
				{
					printf("Print list stack + address.");
					printSt(q);
					printf("\nPrint address of popped elements");
					printSt(b);
				}
				if (act == 4)
					task_list();
			}
		}
	}

	return 0;
}