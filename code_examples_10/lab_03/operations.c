#include "operations.h"
#include "structures.h"

unsigned long long push(struct elm **end)
{
    struct elm *tmp;
    struct elm *end_tmp;
    unsigned long long time_a;
    unsigned long long time_b;
    unsigned long long time = 0;
    end_tmp = *end;
    if (end_tmp == NULL)
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        end_tmp = (struct elm *)malloc(sizeof(struct elm));
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
        printf("Input the number: ");
        if (fscanf(stdin, "%f", &end_tmp->num) != 1)
        {
            printf("Wrong input.\n");
            return -1;
            free(end_tmp);
            end_tmp = NULL;
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        end_tmp->p = NULL;
        *end = end_tmp;
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
    }
    else
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        tmp = malloc(sizeof(struct elm));
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
        printf("Input the number: ");
        if (fscanf(stdin, "%f", &tmp->num) != 1)
        {
            printf("\nWrong input.\n\n");
            return -1;
            free(tmp);
            tmp = NULL;
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        tmp->p = *end;
        *end = tmp;
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
    }
    return time;
}

int pop(struct elm **end, struct empty **end_e)
{
    struct elm *tmp;
    struct elm *end_tmp;
    struct empty *end_e_tmp;
    struct empty *tmp_e;
    end_tmp = *end;
    end_e_tmp = *end_e;
    if (*end == NULL)
        printf("\nStack is empty.\n\n");
    else
    {
        if (end_e_tmp == NULL)
        {
            end_e_tmp = (struct empty *)malloc(sizeof(struct empty));
            end_e_tmp->num = end_tmp;
            end_e_tmp->p = NULL;
            *end_e = end_e_tmp;
        }
        else
        {
            tmp_e = malloc(sizeof(struct empty));
            tmp_e->num = end_tmp;
            tmp_e->p = *end_e;
            *end_e = tmp_e;
        }
        tmp = end_tmp;
        *end = end_tmp->p;
        free(tmp);
        tmp = NULL;
    }
    return 0;
}

int view(struct elm *end)
{
    printf("\n");
    if (end == NULL)
        printf("Stack is empty.\n");
    while (end != NULL)
    {
        printf("%0.2f\n", end->num);
        end = end->p;
    }
    printf("\n");
    return 0;
}

int view_adress(struct elm *end)
{
    printf("\n");
    if (end == NULL)
        printf("\nStack is empty.\n\n");
    while (end != NULL)
    {
        printf("%p\n", end);
        end = end->p;
    }
    printf("\n");
    return 0;
}

int view_adress_empty(struct empty *end)
{
    printf("\n");
    if (end == NULL)
        printf("No deleted elements.\n");
    while (end != NULL)
    {
        printf("%p\n", end->num);
        end = end->p;
    }
    printf("\n");
    return 0;
}
