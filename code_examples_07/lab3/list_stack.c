#include "list_stack.h"

void create(struct list_int **s) // структурный тип.
{
	*s = NULL;
}
// 1 - пустой стек, 0 - непустой
int is_empty(struct list_int *s) // структурный тип.
{	
	if (s)
		return 0;
	return 1;
}

void push(struct list_int **s, int x)
{
	struct list_int *elem = malloc(sizeof(struct list_int));
	
	if (elem)
	{
		elem->num = x;
		elem->prev = *s;
		*s = elem;
	}
}

// возвращает указатель на новую вершину стека
void pop(struct list_int **s, int *x)
{	
	if (*s)
	{
		struct list_int *prev = (*s)->prev;
		
		*x = (*s)->num;
		free(*s);
		*s = prev;
	}
	else
		*x = 0; // если извлекали из пустого стека
}

void createc(struct list_char **s) // структурный тип.
{
	*s = NULL;
}

// 1 - пустой стек, 0 - непустой
int is_emptyc(struct list_char *s) // структурный тип.
{	
	if (s)
		return 0;
	return 1;
}

void pushc(struct list_char **s, char x)
{
	struct list_char *elem = malloc(sizeof(struct list_char));
	if (elem)
	{
		elem->ch = x;
		elem->prev = *s;
		*s = elem;
	}
}

// возвращает указатель на новую вершину стека
void popc(struct list_char **s, char *x)
{	
	if (*s)
	{
		struct list_char *prev = (*s)->prev;
		
		*x = (*s)->ch;
		free(*s);
		*s = prev;
	}
	else
		*x = '\0'; // если извлекали символ из пустого стека
}

// кладем результат операции в стек
void pushResult(char st_op, struct list_int **q)
{
	int a, b;
	
	pop(q, &a);
	pop(q, &b);
	switch (st_op)
	{
		case '*': 
			push(q, a*b);
			break;
		case '/':
			push(q, b/a);
			break;
		case '+':
			push(q, a+b);
			break;
		case '-':
			push(q, b-a);
			break;
	}	
}

// печатаем стеки
void printStc(struct list_char *w)
{
	if (is_emptyc(w))
		printf("\nStack is empty.");
	else
	{
		printf("\n w:\n");
		struct list_char *w1 = w;
		while (!is_emptyc(w1))
		{
			printf("%c %d\n", w1->ch, &(w1->ch));
			w1 = w1->prev;
		}
	}
}

void printSt(struct list_int *q)
{
	if (is_empty(q))
		printf("\nStack is empty.");
	else
	{
		printf("\nStack of integers: \n");
		struct list_int *q1 = q;
		while (!is_empty(q1))
		{
			printf("%d  %d\n", q1->num, &(q1->num));
			q1 = q1->prev;
		}
	}
}

// пытаемся считать входную скобку
int WReadS(struct list_char **w, char **str_ptr)
{
	char op;
	char* tmp = *str_ptr;
	op = read_op(&tmp);
	if (op == '(')
	{
		*str_ptr = tmp;
		pushc(w, op);
		return 1;
	}

	return 0;
}

// очищаем стеки после выполнения программы
int need_free(struct list_int **q, struct list_char **w)
{
	if ((!is_empty(*q)) || (!is_emptyc(*w)))
	{
		struct list_int *pi;
		struct list_char *pc;
		while (!is_empty(*q))
		{
			pi = (*q)->prev;
			free(*q);
			*q = pi;
		}
		while (!is_emptyc(*w))
		{
			pc = (*w)->prev;
			free(*w);
			*w = pc;
		}
		return -1;
	}
	else
		return 0;
}

// проверяем правильность случая оператора, идущего первым в строке
int first_op_case(char **str_ptr, struct list_char **w, struct list_int **q, char *str)
{
	char op = read_op(str_ptr); // проверка на первый оператор: тогда добавляем ноль в стек
	if ((op == ')') || (op == '*') || (op == '/'))
	{
		popc(w, &op);
		need_free(q, w);
		return -1;
	}
	
	if ((op == '+') || (op == '-'))
	{
		pushc(w, op);
		
		op = read_op(str_ptr);
		if (op == ')')
		{
			popc(w, &op);
			need_free(q, w);
			return -1;
		}
		*str_ptr = str;
		if ((op == '+') || (op == '-'))
		{
			read_op(str_ptr);
			push(q, 0);
		}
		else
			popc(w, &op);
	}
	else
		*str_ptr = str;
		
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////

void a_create(struct a_stack **s) // структурный тип.
{
	*s = malloc(sizeof(struct a_stack));
	(*s)->n = 0;
	(*s)->array = malloc(DEPTH*sizeof(int));
}

// 1 - пустой стек, 0 - непустой
int a_is_empty(struct a_stack *s) // структурный тип.
{	
	if (s->n)
		return 0;
	return 1;
}

void a_push(struct a_stack *s, int x)
{
	if (s->n < DEPTH)
	{
		s->array[s->n] = x;
		s->n++;
	}
}

// возвращает указатель на новую вершину стека
void a_pop(struct a_stack *s, int *x)
{	
	if (s->n)
	{
		s->n--;
		*x = s->array[s->n];
	}
}

void a_createc(struct a_stackc **s) // структурный тип.
{
	*s = malloc(sizeof(struct a_stack));
	(*s)->n = 0;
	(*s)->array = malloc(DEPTH*sizeof(char));
}

// 1 - пустой стек, 0 - непустой
int a_is_emptyc(struct a_stackc *s) // структурный тип.
{	
	if (s->n)
		return 0;
	return 1;
}

void a_pushc(struct a_stackc *s, char x)
{
	if (s->n < DEPTH)
	{
		s->array[s->n] = x;
		s->n++;
	}
}

// возвращает указатель на новую вершину стека
void a_popc(struct a_stackc *s, char *x)
{	
	if (s->n)
	{
		s->n--;
		*x = s->array[s->n];
	}
}

// кладем результат операции в стек
void a_pushResult(char st_op, struct a_stack *q)
{
	int a, b;
	
	a_pop(q, &a);
	a_pop(q, &b);
	switch (st_op)
	{
		case '*': 
			a_push(q, a*b);
			break;
		case '/':
			a_push(q, b/a);
			break;
		case '+':
			a_push(q, a+b);
			break;
		case '-':
			a_push(q, b-a);
			break;
	}	
}

// печатаем стеки
void a_printStc(struct a_stackc *w)
{
	if (a_is_emptyc(w))
		printf("\nStack is empty.");
	else
	{
		printf("\n w:\n");
		struct a_stackc *w1 = w;
		while (!a_is_emptyc(w1))
		{
			w1->n--;
			printf("%c %p\n", w1->array[w1->n], &(w1->array[w1->n]));
		}
	}
}

void a_printSt(struct a_stack *q)
{
	if (a_is_empty(q))
		printf("\nStack is empty.");
	else
	{
		printf("\nStack of integers: \n");
		struct a_stack *q1 = q;
		while (!a_is_empty(q1))
		{
			q1->n--;
			printf("%d  %p\n", q1->array[q1->n], &(q1->array[q1->n]));
		}
	}
}

// пытаемся считать входную скобку
int a_WReadS(struct a_stackc *w, char **str_ptr)
{
	char op;
	char* tmp = *str_ptr;
	op = read_op(&tmp);
	if (op == '(')
	{
		*str_ptr = tmp;
		a_pushc(w, op);
		return 1;
	}

	return 0;
}

// очищаем стеки после выполнения программы
int a_need_free(struct a_stack **q, struct a_stackc **w)
{
	if ((!a_is_empty(*q)) || (!a_is_emptyc(*w)))
	{
		free((*q)->array);
		free(*q);
		free((*w)->array);
		free(*w);
		return -1;
	}
	else
		return 0;
}

// проверяем правильность случая оператора, идущего первым в строке
int a_first_op_case(char **str_ptr, struct a_stackc **w, struct a_stack **q, char *str)
{
	char op = read_op(str_ptr); // проверка на первый оператор: тогда добавляем ноль в стек
	if ((op == ')') || (op == '*') || (op == '/'))
	{
		a_popc(*w, &op);
		a_need_free(q, w);
		return -1;
	}
	
	if ((op == '+') || (op == '-'))
	{
		a_pushc(*w, op);
		
		op = read_op(str_ptr);
		if (op == ')')
		{
			a_popc(*w, &op);
			a_need_free(q, w);
			return -1;
		}
		*str_ptr = str;
		if ((op == '+') || (op == '-'))
		{
			read_op(str_ptr);
			a_push(*q, 0);
		}
		else
			a_popc(*w, &op);
	}
	else
		*str_ptr = str;
		
	return 0;
}
