#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "structures.h"
#include "operations.h"

int menu(struct elm *end, struct empty *end_e)
{
    int choise;
    unsigned long long time_a;
    unsigned long long time_b;
    unsigned long long time;

    printf("Choose one of the following points of menu:\n");
    printf("    1) Push element.\n");
    printf("    2) Pop element.\n");
    printf("    3) View elements.\n");
    printf("    4) View adress list.\n");
    printf("    5) View adress list of deleted elements.\n");
    printf("    0) Exit.\n");
    printf("--> ");
    if (fscanf(stdin, "%d", &choise) != 1)
    {
        scanf( "%*[^\n]" );
        scanf( "%*c" );
        printf("\n");
        printf("Wrong input.\n\n");
        menu(end, end_e);
    }
    else
        if (choise < 0 || choise > 5)
        {
            printf("\nNo such point in menu.\n\n");
            menu(end, end_e);
        }
    switch (choise)
    {
        case 1:
            time = push(&end);
            scanf( "%*[^\n]" );
            scanf( "%*c" );
            printf("Time of operation = %llu\n", time);
            menu(end, end_e);
            break;
        case 2:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            pop(&end, &end_e);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("Time of operation = %llu\n", time);
            menu(end, end_e);
            break;
        case 3:
            __asm__ __volatile__ ("rdtsc" : "=A" (time_a));
            view(end);
            __asm__ __volatile__ ("rdtsc" : "=A" (time_b));
            time = time_b - time_a;
            printf("Time of operation = %llu\n", time);
            menu(end, end_e);
            break;
        case 4: view_adress(end); menu(end, end_e); break;
        case 5: view_adress_empty(end_e); menu(end, end_e); break;
    }
    return 0;
}

int main()
{
    struct empty *end_e = NULL;
    struct elm *end = NULL;
    menu(end, end_e);
    free(end);
    free(end_e);
    return 0;
}
