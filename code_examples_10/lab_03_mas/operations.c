#include "operations.h"

long long int push_first(float *mas, int *count_first, int count_second, int count)
{
    unsigned long long time_a;
    unsigned long long time_b;
    unsigned long long time = 0;
    float tmp;

    __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
    if (*count_first < count - count_second)
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
        printf("Input the number: ");
        if (fscanf(stdin, "%f", &tmp) != 1)
        {
            printf("Wrong input.\n");
            return -1;
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        mas[*count_first] = tmp;
        *count_first = *count_first + 1;
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
    }
    else
        printf("Overflow.\n");

    return time;
}

long long int push_second(float *mas, int *count_second, int count_first, int count)
{
    unsigned long long time_a;
    unsigned long long time_b;
    unsigned long long time = 0;
    float tmp;

    __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
    if (*count_second >= count_first)
    {
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
        printf("Input the number: ");
        if (fscanf(stdin, "%f", &tmp) != 1)
        {
            printf("Wrong input.\n");
            return -1;
        }
        __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
        mas[count - *count_second - 1] = tmp;
        *count_second = *count_second + 1;
        __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
        time = time + time_b - time_a;
    }
    else
        printf("Overflow.\n");

    return time;
}

int pop_first(int *count_first)
{
    if (*count_first == 0)
    {
        printf("\nFirst stack is empty.\n\n");
        return -1;
    }
    *count_first = *count_first - 1;
    return 0;
}

int pop_second(int *count_second)
{
    if (*count_second == 0)
    {
        printf("\nSecond stack is empty.\n\n");
        return -1;
    }
    *count_second = *count_second - 1;
    return 0;
}

int view_first(float *mas, int count_first)
{
    printf("\n");
    if (count_first == 0)
    {
        printf("First stack is empty.\n\n");
        return -1;
    }
    for (int i = count_first - 1; i >= 0; i--)
    {
        printf("%0.2f\n", mas[i]);
    }
    printf("\n");
    return 0;
}

int view_second(float *mas, int count_second, int count)
{
    printf("\n");
    if (count_second == 0)
    {
        printf("Second stack is empty.\n\n");
        return -1;
    }
    for (int i = count - count_second; i < count; i++)
    {
        printf("%0.2f\n", mas[i]);
    }
    printf("\n");
    return 0;
}
