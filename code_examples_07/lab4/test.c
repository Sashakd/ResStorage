#include "test.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void print_menu() 
{
	printf("\n\nChoose action:\n");
    printf("  0)Time\n");
    printf("  1)Work with Array\n");
    printf("  2)Work with List\n");
    printf("  3)Show example POP adress of List\n");
    printf("  4)Exit\n");
	printf("->  ");
}

float random(float from, float to)
{
    return from+((float)rand()/(float)RAND_MAX)*(to-from);
}

void print_new_results(int *num_out, float *tin1, float *tout1, int *sub, int *info, int works)
{
	(*info)++;
	printf("INFO #%d:\n", *info);
	printf("Works AO on the moment: [%d]\n", works);
	printf("Time in: [%f]\n", *tin1);
	printf("Time out: [%f]\n", *tout1);
	printf("Count in per out 1 hundred: [%d]\n", *sub);
	printf("Normal time for 1 element: [%f]\n\n", (*tin1 + *tout1)/100);
	*num_out = *sub = *tin1 = *tout1 = 0;
}

float do_this_time_l(float tr, struct l_queue **o1, int *num_out, float *tin1, 
								float *tout1, int *sub, int *info, int *works, int *i)
{
	float cur=0, trand=0;
	int status;

	while ((cur<tr) && (!is_empty_l(*o1)))
	{
		(*works)++;
		trand = random(0, 1);
		cur += trand;
		*tout1 += trand;	
		pop_h(&status, o1);
		if (status<5)
		{
			status++;
			push_t(status, o1);
		}
		else
		{
			(*i)++;
			(*num_out)++;
		}
		
        if (*num_out >= 100) // печатаем результаты работы с новой сотней
			print_new_results(num_out, tin1, tout1, sub, info, *works); 			
	}
	return cur;
}

void list_working() 
{
    struct l_queue *o1 = NULL;
    int info = 0; // просто номер выдачи сообщения текущего состояния очереди
    float tin=0, tout=0; // время входа, время выхода заявок, не обнуляется
	float time=0; // время работы системы
    float tin1=0, tout1=0; // время обработки 100 заявок, обнуляется каждые сто заявок
    float tr=0; // выданное случайным образом время
    int num_out = 0; // выкинули из очереди насовсем, каждую сотню обнуляем
	int sub = 0; // сколько новых пришло в течение выкинутой сотни, каждую сотню обнуляем
	int works = 0, was_in=0;
	int i = 0; 
	
	while (i<1000)
	{
        tr = random(0, 6);
		tout += do_this_time_l(tr, &o1, &num_out, &tin1, &tout1, &sub, &info, &works, &i); // по-видимому придется больше передавать
		tin1 += tr;
		tin += tr;
		was_in++;
		push_t(1, &o1); // 1 - заявка в первый раз стоит в очереди
		sub++;
	}
	
	free_l(&o1);
    
    if (tin > tout)
		time = tin;
	else
		time = tout;
		
    printf("RESULTS\n");
	printf("Sum time: [%f] \n", time);
    printf("Time in: [%f] \n", tin);
	printf("Time out [%f] \n", tout);
	printf("Works AO : %d\n", works);
	printf("Was 'in' : %d\n", was_in);
}



float do_this_time_a(float tr, struct a_queue **o1, int *num_out, float *tin1, 
								float *tout1, int *sub, int *info, int *works, int *i)
{
	float cur=0, trand=0;
	int status;
	while ((cur<tr) && (!is_empty_a(*o1)))
	{	
		(*works)++;
		trand = random(0, 1);
		cur += trand;
		*tout1 += trand;	
		a_pop_h(&status, o1);
		if (status<5)
		{
			status++;
			a_push_t(status, o1);
		}
		else
		{
			(*i)++;
			(*num_out)++;
		}
			
        if (*num_out >= 100) // печатаем результаты работы с новой сотней
			print_new_results(num_out, tin1, tout1, sub, info, *works); 			
	}
	return cur;
}

void array_working() 
{
    struct a_queue *o1 = NULL;
    int info = 0; // просто номер выдачи сообщения текущего состояния очереди
    float tin=0, tout=0; // время входа, время выхода заявок, не обнуляется
	float time=0; // время работы системы
    float tin1=0, tout1=0; // время обработки 100 заявок, обнуляется каждые сто заявок
    float tr=0; // выданное случайным образом время
    int num_out = 0; // выкинули из очереди насовсем, каждую сотню обнуляем
	int sub = 0; // сколько новых пришло в течение выкинутой сотни, каждую сотню обнуляем
	int works = 0, was_in = 0;
	int i=0;
	
	while (i<1000)
	{
        tr = random(0, 6);
		tout += do_this_time_a(tr, &o1, &num_out, &tin1, &tout1, &sub, &info, &works, &i); // по-видимому придется больше передавать
		tin1 += tr;
		tin += tr;
		was_in++;
		a_push_t(1, &o1); // 1 - заявка в первый раз стоит в очереди
		sub++;
	}
	
	a_free(&o1);
    
    if (tin > tout)
		time = tin;
	else
		time = tout;
		
    printf("RESULTS\n");
	printf("Sum time: [%f] \n", time);
    printf("Time in: [%f] \n", tin);
	printf("Time out [%f] \n", tout);
	printf("Works AO : %d\n", works);
	printf("Was 'in' : %d\n", was_in);
}
























































void test_a() 
{
    struct a_queue *p = NULL;
    int x;
	
    a_push_h(0, &p);
    if (is_empty_a(p)>=0)
        printf("Push_h is good!\n");
    else
         printf("Push_h is bad!\n");
    print_a(p);
	
    a_pop_h(&x, &p);
    printf("{%d}\n",x);
    if (is_empty_a(p))
        printf("Pop_h is good!\n");
    else
        printf("Pop_h is bad!\n");
    print_a(p);

    printf("\n");

    a_push_t(2, &p);
    if(!is_empty_a(p))
        printf("Push_t is good!\n");
    else
         printf("Push_t is bad!\n");
    print_a(p);
	
    a_pop_t(&x, &p);
    printf("{%d}\n",x);
    if (is_empty_a(p)) 
        printf("Pop_t is good!\n");
    else
        printf("Pop_t is bad!\n");
    print_a(p);

    printf("\n");

    a_push_t(2,&p);
    a_push_t(4,&p);
    a_push_h(6,&p);
    a_push_h(8,&p);
    a_push_t(2,&p);
    print_a(p);
    printf("\n");
    a_pop_h(&x,&p);
    a_pop_t(&x,&p);
    print_a(p);
    a_push_t(2,&p);
    a_push_t(4,&p);
    a_push_h(6,&p);
    a_push_h(8,&p);
    a_push_t(2,&p);
    print_a(p);
    printf("\n");
    a_free(&p);
    if (is_empty_a(p))
        printf("free is good!\n");
    else
        printf("free is bad!\n");
}


void test_s() 
{
    struct l_queue *p = NULL;
    int x;
	
    push_h(0, &p);
    if (!is_empty_l(p))
        printf("Push_h is good!\n");
    else
        printf("Push_h is bad!\n");
    print_l(p);
	
    pop_h(&x, &p);
    printf("{%d}\n",x);
    if (is_empty_l(p))
        printf("Pop_h is good!\n");
    else
        printf("Pop_h is bad!\n");
    print_l(p);

    printf("\n");

    push_t(2, &p);
    if (!is_empty_l(p))
        printf("Push_t is good!\n");
    else
        printf("Push_t is bad!\n");
    print_l(p);
	
    pop_t(&x, &p);
    printf("{%d}\n",x);
    if(is_empty_l(p))
        printf("Pop_t is good!\n");
    else
         printf("Pop_t is bad!\n");
    print_l(p);
	
    push_t(2,&p);
    push_h(6,&p);
    printf("_________________________________\n");
    push_h(8,&p);
    printf("_________________________________\n");
    push_t(2,&p);
    printf("_________________________________\n");
    print_l(p);
    printf("_________________________________\n");
    pop_h(&x,&p);
    pop_t(&x,&p);
    printf("_________________________________\n");
    print_l(p);
    printf("_________________________________\n");
    push_t(2,&p);
    push_h(6,&p);
    push_t(4,&p);
    push_h(6,&p);
    push_h(8,&p);
    push_t(2,&p);
    print_l(p);
    printf("\n");
    pop_h(&x,&p);
    pop_t(&x,&p);
    print_l(p);

    printf("\n");
    free_l(&p);
    if(is_empty_l(p))
        printf("free is good!\n");
    else
        printf("free is bad!\n");
}
