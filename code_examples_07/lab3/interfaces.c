#include "interfaces.h"

void main_menu()
{
	printf("Choose stack for work:\n");
	printf("\t1: Array\n");
	printf("\t2: List\n");
	printf("\t3: Exit\n");
	printf("-> ");
}

void sub_menu()
{
	printf("\n");
	printf("1: PUSH\n");
	printf("2: POP\n");
	printf("3: status of stack\n");
	printf("4: solving task by variant 14\n");
	printf("5: BACK\n");
	printf("-> ");
}

// определение приоритета
int prior(char op)
{
	switch (op)
	{
		case '(':
			return -1;
		case '*': case '/':
			return 1;
			break;
		case '+': case '-':
			return 2;
			break;
		default:
			return -100;
			break;
	}
}

// закончилась ли строка
int endline(char** str_ptr)
{
	while (**str_ptr == ' ')
		(*str_ptr)++;	
	if (**str_ptr == '\0')
		return 1;
	return 0;
}

// чтение числа
int read_num(char** str_ptr)
{
	int num;
	sscanf(*str_ptr, "%d", &num);
	while (**str_ptr != ' ')
		(*str_ptr)++;
	return num;
}

// чтение оператора
char read_op(char** str_ptr)
{
	char op;
	while (**str_ptr == ' ')
		(*str_ptr)++;
	sscanf(*str_ptr, "%c", &op);
	(*str_ptr)++;
	return op;
}

// получаем разрешение на доступ к стеку
int canPop(char op, char st_op) // можно ли вытащить
{
	int p1 = prior(op); 
	int p2 = prior(st_op);	
	if (((p1>=0) && (p2>=0) && (p1>=p2)) || (op == ')'))
		return 1;
	else
		return 0;
}

// вычисление значения выражения
int task_list()
{
	char str[BUF];
	char* str_ptr = str;
	int num=0, flag=0;
	char op, st_op='\0';
	struct list_char *w;
	struct list_int *q;
	
	printf("Input string for calculation:\n");
	fgets(str, BUF-5, stdin);
	
	str[strlen(str)+2] = '\0';
	str[strlen(str)+1] = ' ';
	str[strlen(str)-1] = ' '; // 10
	str[strlen(str)] = ')'; // где был '\0'
	
	create(&q);
	createc(&w);
	pushc(&w, '(');
	
	if (first_op_case(&str_ptr, &w, &q, str))
	{
		printf("Error");
		return -1;
	}
	
	while (*str_ptr)
	{
		if (endline(&str_ptr))
			break;
		if (flag==0)
		{
			if (WReadS(&w, &str_ptr))  // просто кладем открывающуюся скобку, если встретим
				continue;
			
			num = read_num(&str_ptr);
			push(&q, num); 
		}
#ifdef PRINTING
		printSt(q); ////////////////////////////////	
#endif		
		popc(&w, &st_op);
		op = read_op(&str_ptr);
		if (op == ')')
			flag = 1;
		else
			flag = 0;
		while (canPop(op, st_op))
		{
#ifdef PRINTING
		printSt(q); ////////////////////////////////	
#endif
			if ((st_op == '(') && (op == ')'))
				break;
			pushResult(st_op, &q);
			popc(&w, &st_op);
		}
		if ((st_op == '(') && (op == ')'))
			continue;		
		pushc(&w, st_op);
		pushc(&w, op);
	}
	
#ifdef PRINTING
		printSt(q); ////////////////////////////////	
#endif
	pop(&q, &num);
	if (need_free(&q, &w))
		printf("Error");
	else
		printf("\nResult = %d", num);
		
	return 0;
}

int a_task_list()
{
	char str[BUF];
	char* str_ptr = str;
	int num=0, flag=0;
	char op, st_op='\0';
	struct a_stackc *w;
	struct a_stack *q;
	
	printf("Input string for calculation:\n");
	fgets(str, BUF-5, stdin);
	
	str[strlen(str)+2] = '\0';
	str[strlen(str)+1] = ' ';
	str[strlen(str)-1] = ' '; // 10
	str[strlen(str)] = ')'; // где был '\0'
	
	a_create(&q);
	a_createc(&w);
	a_pushc(w, '(');
	
	if (a_first_op_case(&str_ptr, &w, &q, str))
	{
		printf("Error");
		return -1;
	}
	
	while (*str_ptr)
	{
		if (endline(&str_ptr))
			break;
		if (flag==0)
		{
			if (a_WReadS(w, &str_ptr))  // просто кладем открывающуюся скобку, если встретим
				continue;
			
			num = read_num(&str_ptr);
			a_push(q, num); 
		}
#ifdef PRINTING
		a_printSt(q); ////////////////////////////////	
#endif		
		a_popc(w, &st_op);
		op = read_op(&str_ptr);
		if (op == ')')
			flag = 1;
		else
			flag = 0;
		while (canPop(op, st_op))
		{
#ifdef PRINTING
		a_printSt(q); ////////////////////////////////	
#endif
			if ((st_op == '(') && (op == ')'))
				break;
			a_pushResult(st_op, q);
			a_popc(w, &st_op);
		}
		if ((st_op == '(') && (op == ')'))
			continue;		
		a_pushc(w, st_op);
		a_pushc(w, op);
	}
	
#ifdef PRINTING
		a_printSt(q); ////////////////////////////////	
#endif
	a_pop(q, &num);
	if (a_need_free(&q, &w))
		printf("Error");
	else
		printf("\nResult = %d", num);
		
	return 0;
}