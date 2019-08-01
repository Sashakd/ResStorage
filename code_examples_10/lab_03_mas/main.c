#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "operations.h"

int menu(float *mas, int *count_first, int *count_second, int count)
{
    int choise;
    unsigned long long time_a;
    unsigned long long time_b;
    unsigned long long time;

    printf("Choose one of the following points of menu:\n");
    printf("    1) Push element in first stack.\n");
    printf("    2) Push element in second stack.\n");
    printf("    3) Pop element from first stack.\n");
    printf("    4) Pop element from second stack.\n");
    printf("    5) View elements of first stack.\n");
    printf("    6) View elements of second stack.\n");
    printf("    0) Exit.\n");
    printf("--> ");
    if (fscanf(stdin, "%d", &choise) != 1)
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        printf("\n");
        printf("Wrong input.\n\n");
        menu(mas, count_first, count_second, count);
    }
    else
        if (choise < 0 || choise > 6)
        {
            printf("\nNo such point in menu.\n\n");
            menu(mas, count_first, count_second, count);
        }
    switch (choise)
    {
        case 1:
            time = push_first(mas, count_first, *count_second, count);
            scanf( "%*[^\n]" );
            scanf( "%*c" );
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
        case 2:
            time = push_second(mas, count_second, *count_first, count);
            scanf( "%*[^\n]" );
            scanf( "%*c" );
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
        case 3:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            pop_first(count_first);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
        case 4:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            pop_second(count_second);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
        case 5:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            view_first(mas, *count_first);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
        case 6:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            view_second(mas, *count_second, count);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("\nTime of operation = %llu\n\n", time);
            menu(mas, count_first, count_second, count);
            break;
    }
    return 0;
}

int main()
{
    float mas[30];
    int count_first = 0;
    int count_second = 0;
    int count = 3; // 30

    menu(mas, &count_first, &count_second, count);
    return 0;
}
