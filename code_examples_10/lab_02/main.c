#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "changing.h"
#include "read.h"
#include "sorting.h"

#define N 100 // максимальное количество записей

int menu(student *table, int *count, char *name_file, key *mas) // процедура меню
{
    int menu_point = 1;
    printf("Choose one of the following commands:\n");
    printf("    1) Load records from file\n");
    printf("    2) Add new records.\n");
    printf("    3) Print all records.\n");
    printf("    4) Save current condition in file.\n");
    printf("    5) Delete record\n");
    printf("    6) Print hostel students\n");
	printf("    7) Analyse sorting\n");
    printf("    8) Create, sort and print keys array\n");
    printf("    9) Sort table.\n");
    printf("    0) Exit\n");
    printf("--> ");
    scanf("%d", &menu_point);
    if (menu_point == 0)
        goto fin;
    if (menu_point < 0 || menu_point > 9)
    {
        printf("\n###No such item in menu\n\n");
        goto rerun;
    }
    switch (menu_point)
    {
        case 1: reading(table, count, &name_file); break;
        case 2: adding(table, count); break;
        case 3: print_all(table, *count); break;
        case 4: save_file(table, *count); break;
        case 5: delete_record(table, count); break;
        case 6: print_hostel(table, *count); break;
        case 7: analyse_sorting(table, *count, name_file); break;
        case 8: prnt_sort_keys(table, mas, *count); break;
        case 9:
            if (*count <= 0)
                printf("Nothing to sort.\n");
            else
                my_sort(table, *count, sizeof(student),(int(*) (const void *, const void *)) comp_student); break;
    }
    rerun:
    menu(table, count, name_file, mas);
    fin:
    return 0;
} // end of процедура меню

int main()
{
    char name_file[20];
    student *table;
    key *mas;
    mas = malloc(N * sizeof(student));
    table = malloc(N * sizeof(student));
    int count = 0;
    printf("*** Program for working with records ***\n\n");
    menu(table, &count, name_file, mas);
    free(table);
    free(mas);
    return 0;
}
